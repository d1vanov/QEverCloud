/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"

#include <DurableService.h>
#include <Exceptions.h>
#include <Log.h>

#include <algorithm>
#include <cmath>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

struct RetryState
{
    quint32 m_retryCount = 0;
};

////////////////////////////////////////////////////////////////////////////////

quint64 exponentiallyIncreasedTimeoutMsec(
    quint64 timeout, const quint64 maxTimeout)
{
    timeout = static_cast<quint64>(std::floor(timeout * 1.6 + 0.5));
    timeout = std::min(timeout, maxTimeout);
    return timeout;
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

} // namespace

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN DurableService: public IDurableService
{
public:
    DurableService(IRetryPolicyPtr retryPolicy, IRequestContextPtr ctx);

    virtual SyncResult executeSyncRequest(
        SyncRequest && syncRequest, IRequestContextPtr ctx) override;

    virtual AsyncResult * executeAsyncRequest(
        AsyncRequest && asyncRequest, IRequestContextPtr ctx) override;

private:
    void doExecuteAsyncRequest(
        AsyncRequest && asyncRequest, IRequestContextPtr ctx,
        RetryState && retryState, AsyncResult * result);

private:
    IRetryPolicyPtr     m_retryPolicy;
    IRequestContextPtr  m_ctx;
};

DurableService::DurableService(IRetryPolicyPtr retryPolicy,
                               IRequestContextPtr ctx) :
    m_retryPolicy(std::move(retryPolicy)),
    m_ctx(std::move(ctx))
{
    if (!m_retryPolicy) {
        m_retryPolicy = newRetryPolicy();
    }
}

DurableService::SyncResult DurableService::executeSyncRequest(
    SyncRequest && syncRequest, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    SyncResult result;

    while(state.m_retryCount)
    {
        QEC_DEBUG("durable_service", "Executing sync " << syncRequest.m_name
            << " request: " << state.m_retryCount << " attempts left, timeout = "
            << ctx->requestTimeout());
        QEC_TRACE("durable_service", "Request details: "
            << syncRequest.m_description);

        try {
            result = syncRequest.m_call(ctx);
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
            QEC_WARNING("durable_service", "Sync request " << syncRequest.m_name
                << " failed: " << result.second->errorMessage
                << "; request details: " << syncRequest.m_description);

            if (!m_retryPolicy->shouldRetry(result.second)) {
                QEC_WARNING("durable_service", "Error is not retriable");
                return result;
            }

            --state.m_retryCount;
            if (!state.m_retryCount) {
                QEC_WARNING("durable_service", "No retry attempts left");
                break;
            }

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

            QEC_INFO("durable_service", "Retrying sync " << syncRequest.m_name
                << " request, " << state.m_retryCount << " attempts left");
            continue;
        }

        if (!result.second) {
            QEC_DEBUG("durable_service", "Successfully executed sync "
                << syncRequest.m_name << " request");
        }

        break;
    }

    return result;
}

AsyncResult * DurableService::executeAsyncRequest(
    AsyncRequest && asyncRequest, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    AsyncResult * result = new AsyncResult(QString(), QByteArray(), 0);
    doExecuteAsyncRequest(std::move(asyncRequest), std::move(ctx),
                          std::move(state), result);

    return result;
}

void DurableService::doExecuteAsyncRequest(
    AsyncRequest && asyncRequest, IRequestContextPtr ctx,
    RetryState && retryState, AsyncResult * result)
{
    QEC_DEBUG("durable_service", "Executing async " << asyncRequest.m_name
        << " request: " << retryState.m_retryCount << " attempts left, timeout = "
        << ctx->requestTimeout());
    QEC_TRACE("durable_service", "Request details: "
        << asyncRequest.m_description);

    AsyncResult * attemptRes = asyncRequest.m_call(ctx);
    QObject::connect(
        attemptRes,
        &AsyncResult::finished,
        result,
        [=, retryState = std::move(retryState), retryPolicy = m_retryPolicy] (
            QVariant value,
            QSharedPointer<EverCloudExceptionData> exceptionData) mutable
        {
            if (!exceptionData) {
                QEC_DEBUG("durable_service", "Successfully executed async "
                    << asyncRequest.m_name << " request");
                result->d_ptr->setValue(value, {});
                return;
            }

            QEC_WARNING("durable_service", "Sync request " << asyncRequest.m_name
                << " failed: " << exceptionData->errorMessage
                << "; request details: " << asyncRequest.m_description);

            if (!retryPolicy->shouldRetry(exceptionData)) {
                QEC_WARNING("durable_service", "Error is not retriable");
                result->d_ptr->setValue({}, exceptionData);
                return;
            }

            --retryState.m_retryCount;
            if (!retryState.m_retryCount) {
                QEC_WARNING("durable_service", "No retry attempts left");
                result->d_ptr->setValue({}, exceptionData);
                return;
            }

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

            QEC_INFO("durable_service", "Retrying async " << asyncRequest.m_name
                << " request, " << retryState.m_retryCount << " attempts left");
            doExecuteAsyncRequest(
                std::move(asyncRequest), std::move(ctx),
                std::move(retryState), result);
        },
        Qt::QueuedConnection);
}

////////////////////////////////////////////////////////////////////////////////

IRetryPolicyPtr newRetryPolicy()
{
    return std::make_shared<RetryPolicy>();
}

IDurableServicePtr newDurableService(
    IRetryPolicyPtr retryPolicy,
    IRequestContextPtr ctx)
{
    return std::make_shared<DurableService>(
        retryPolicy, ctx);
}

} // namespace qevercloud
