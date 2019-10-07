/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"
#include "DurableService.h"

namespace qevercloud {

DurableService::DurableService(IRetryPolicyPtr retryPolicy, IRequestContextPtr ctx) :
    m_retryPolicy(std::move(retryPolicy)),
    m_ctx(std::move(ctx))
{}

DurableService::SyncResult DurableService::ExecuteSyncRequest(
    SyncServiceCall && syncServiceCall, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    SyncResult result;

    while(state.m_retryCount)
    {
        try {
            result = syncServiceCall();
        }
        catch(const EverCloudException & e) {
            result.second = e.exceptionData();
        }
        catch(const std::exception & e) {
            result.second = QSharedPointer<EverCloudExceptionData>(
                new EverCloudExceptionData(QString::fromLocal8Bit(e.what())));
            return result;
        }

        if (result.second)
        {
            if (!m_retryPolicy->ShouldRetry(result.second)) {
                return result;
            }

            --state.m_retryCount;
            continue;
        }

        break;
    }

    return result;
}

AsyncResult * DurableService::ExecuteAsyncRequest(
    AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    AsyncResult * result = new AsyncResult;
    DoExecuteAsyncRequest(std::move(asyncServiceCall), std::move(ctx),
                          std::move(state), result);

    return result;
}

void DurableService::DoExecuteAsyncRequest(
    AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx,
    RetryState && retryState, AsyncResult * result)
{
    AsyncResult * attemptRes = asyncServiceCall();
    QObject::connect(attemptRes, &AsyncResult::finished,
                     [=, retryPolicy = m_retryPolicy] (
                        QVariant value,
                        QSharedPointer<EverCloudExceptionData> exceptionData) mutable
                     {
                         if (!exceptionData) {
                             result->d_ptr->setValue(value, {});
                             return;
                         }

                         if (!retryPolicy->ShouldRetry(exceptionData)) {
                             result->d_ptr->setValue({}, exceptionData);
                             return;
                         }

                         --retryState.m_retryCount;
                         if (!retryState.m_retryCount) {
                             result->d_ptr->setValue({}, exceptionData);
                             return;
                         }

                         quint64 requestTimeout = ctx->requestTimeout();
                         if (ctx->increaseRequestTimeoutExponentially()) {
                             // TODO: increase timeout
                         }

                         auto newCtx = newRequestContext(
                             ctx->authenticationToken(),
                             requestTimeout,
                             ctx->increaseRequestTimeoutExponentially(),
                             ctx->maxRequestTimeout(),
                             ctx->maxRequestRetryCount());

                         DoExecuteAsyncRequest(
                             std::move(asyncServiceCall), std::move(newCtx),
                             std::move(retryState), result);
                     });
}

} // namespace qevercloud
