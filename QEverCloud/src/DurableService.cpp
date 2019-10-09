/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"
#include "DurableService.h"

#include <Exceptions.h>

#include <algorithm>
#include <cmath>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

quint64 exponentiallyIncreasedTimeoutMsec(
    quint64 timeout, const quint64 maxTimeout)
{
    timeout = static_cast<quint64>(std::floor(timeout * 1.6 + 0.5));
    timeout = std::min(timeout, maxTimeout);
    return timeout;
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

DurableService::DurableService(IRetryPolicyPtr retryPolicy, IRequestContextPtr ctx) :
    m_retryPolicy(std::move(retryPolicy)),
    m_ctx(std::move(ctx))
{}

AsyncResult * DurableService::newAsyncResult()
{
    return new AsyncResult;
}

DurableService::SyncResult DurableService::executeSyncRequest(
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
            result = syncServiceCall(ctx);
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
            if (!m_retryPolicy->shouldRetry(result.second)) {
                return result;
            }

            --state.m_retryCount;

            if (state.m_retryCount && ctx->increaseRequestTimeoutExponentially())
            {
                auto timeout = ctx->requestTimeout();
                auto maxTimeout = ctx->maxRequestTimeout();
                timeout = exponentiallyIncreasedTimeoutMsec(timeout, maxTimeout);

                ctx = newRequestContext(
                    ctx->authenticationToken(),
                    timeout,
                    /* increase request timeout exponentially = */ true,
                    maxTimeout,
                    ctx->maxRequestRetryCount());
            }

            continue;
        }

        break;
    }

    return result;
}

AsyncResult * DurableService::executeAsyncRequest(
    AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    AsyncResult * result = new AsyncResult;
    doExecuteAsyncRequest(std::move(asyncServiceCall), std::move(ctx),
                          std::move(state), result);

    return result;
}

void DurableService::doExecuteAsyncRequest(
    AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx,
    RetryState && retryState, AsyncResult * result)
{
    AsyncResult * attemptRes = asyncServiceCall(ctx);
    QObject::connect(
        attemptRes,
        &AsyncResult::finished,
        result,
        [=, retryState = std::move(retryState), retryPolicy = m_retryPolicy] (
            QVariant value,
            QSharedPointer<EverCloudExceptionData> exceptionData) mutable
        {
            if (!exceptionData) {
                result->d_ptr->setValue(value, {});
                return;
            }

            if (!retryPolicy->shouldRetry(exceptionData)) {
                result->d_ptr->setValue({}, exceptionData);
                return;
            }

            --retryState.m_retryCount;
            if (!retryState.m_retryCount) {
                result->d_ptr->setValue({}, exceptionData);
                return;
            }

            quint64 requestTimeout = ctx->requestTimeout();
            if (ctx->increaseRequestTimeoutExponentially())
            {
                auto timeout = ctx->requestTimeout();
                auto maxTimeout = ctx->maxRequestTimeout();
                timeout = exponentiallyIncreasedTimeoutMsec(timeout, maxTimeout);

                ctx = newRequestContext(
                    ctx->authenticationToken(),
                    timeout,
                    /* increase request timeout exponentially = */ true,
                    maxTimeout,
                    ctx->maxRequestRetryCount());
            }

            doExecuteAsyncRequest(
                std::move(asyncServiceCall), std::move(ctx),
                std::move(retryState), result);
        },
        Qt::QueuedConnection);
}

////////////////////////////////////////////////////////////////////////////////

struct Q_DECL_HIDDEN RetryPolicy: public IRetryPolicy
{
    virtual bool shouldRetry(
        QSharedPointer<EverCloudExceptionData> exceptionData) override
    {
        if (Q_UNLIKELY(exceptionData.isNull())) {
            return true;
        }

        try {
            exceptionData->throwException();
        }
        catch(const ThriftException &) {
            return true;
        }
        catch(const EDAMSystemException &) {
            return true;
        }
        catch(...) {
        }

        return false;
    }
};

////////////////////////////////////////////////////////////////////////////////

IRetryPolicyPtr newRetryPolicy()
{
    return std::make_shared<RetryPolicy>();
}

} // namespace qevercloud
