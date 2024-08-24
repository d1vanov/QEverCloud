/**
 * Copyright (c) 2019-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <QtGlobal>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include "Qt5Promise.h"
#endif

#include <qevercloud/DurableService.h>
#include <qevercloud/exceptions/NetworkException.h>
#include <qevercloud/exceptions/ThriftException.h>
#include <qevercloud/exceptions/EDAMSystemException.h>
#include <qevercloud/utility/Log.h>

#include <QFutureWatcher>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPromise>
#endif

#include <algorithm>
#include <cmath>
#include <functional>
#include <memory>
#include <mutex>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

std::once_flag gRegisterIRequestContextPtrMetaType;

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
    [[nodiscard]] bool shouldRetry(std::exception_ptr exc) override
    {
        if (Q_UNLIKELY(!exc)) {
            return true;
        }

        try
        {
            std::rethrow_exception(exc);
        }
        catch(const NetworkException & e)
        {
            switch(e.type())
            {
            case QNetworkReply::TimeoutError:
                return true;
            case QNetworkReply::TemporaryNetworkFailureError:
                return true;
            case QNetworkReply::NetworkSessionFailedError:
                return true;
            case QNetworkReply::ProxyConnectionClosedError:
                return true;
            case QNetworkReply::ProxyTimeoutError:
                return true;
            case QNetworkReply::ContentReSendError:
                return true;
            case QNetworkReply::InternalServerError:
                return true;
            case QNetworkReply::ServiceUnavailableError:
                return true;
            case QNetworkReply::ProtocolFailure:
                return true;
            default:
                return false;
            }
        }
        catch(const ThriftException & e)
        {
            switch(e.type())
            {
            case ThriftException::Type::BAD_SEQUENCE_ID:
                return true;
            case ThriftException::Type::INTERNAL_ERROR:
                return true;
            case ThriftException::Type::PROTOCOL_ERROR:
                return true;
            case ThriftException::Type::UNKNOWN:
                return true;
            default:
                return false;
            }
        }
        catch(const EDAMSystemException & e)
        {
            switch (e.errorCode())
            {
            case EDAMErrorCode::UNKNOWN:
            case EDAMErrorCode::INTERNAL_ERROR:
                return true;
            default:
                return false;
            }
        }
        catch(...)
        {
        }

        return false;
    }
};

////////////////////////////////////////////////////////////////////////////////

struct Q_DECL_HIDDEN NullRetryPolicy: public IRetryPolicy
{
    [[nodiscard]] bool shouldRetry(std::exception_ptr e) override
    {
        Q_UNUSED(e)
        return false;
    }
};

} // namespace

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN DurableService: public IDurableService
{
public:
    DurableService(IRetryPolicyPtr retryPolicy, IRequestContextPtr ctx);

    [[nodiscard]] SyncResult executeSyncRequest(
        SyncRequest && syncRequest, IRequestContextPtr ctx) override;

    [[nodiscard]] QFuture<QVariant> executeAsyncRequest(
        AsyncRequest && asyncRequest, IRequestContextPtr ctx) override;

private:
    static void doExecuteAsyncRequest(
        AsyncRequest && asyncRequest, IRequestContextPtr ctx,
        IRetryPolicyPtr retryPolicy, RetryState && retryState,
        QPromise<QVariant> && resultPromise);

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

    if (!m_ctx) {
        m_ctx = newRequestContext();
    }

    std::call_once(
        gRegisterIRequestContextPtrMetaType,
        []
        {
            qRegisterMetaType<IRequestContextPtr>("IRequestContextPtr");
        });
}

DurableService::SyncResult DurableService::executeSyncRequest(
    SyncRequest && syncRequest, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    SyncResult result;

    while(state.m_retryCount)
    {
        QEC_DEBUG("durable_service", "Executing sync " << syncRequest.m_name
            << " request: " << state.m_retryCount << " attempts left, timeout = "
            << ctx->connectionTimeout());
        QEC_TRACE("durable_service", "Request details: "
            << syncRequest.m_description);

        QString errorMessage;
        try {
            result = syncRequest.m_call(ctx);
        }
        catch(const std::exception & e) {
            errorMessage = QString::fromLocal8Bit(e.what());
            result.second = std::current_exception();
            return result;
        }

        if (result.second)
        {
            QEC_WARNING("durable_service", "Sync request " << syncRequest.m_name
                << " failed: " << errorMessage
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

            if (ctx->increaseConnectionTimeoutExponentially())
            {
                auto timeout = ctx->connectionTimeout();
                auto maxTimeout = ctx->maxConnectionTimeout();
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

QFuture<QVariant> DurableService::executeAsyncRequest(
    AsyncRequest && asyncRequest, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    RetryState state;
    state.m_retryCount = ctx->maxRequestRetryCount();

    QPromise<QVariant> resultPromise;
    auto future = resultPromise.future();

    doExecuteAsyncRequest(
        std::move(asyncRequest), std::move(ctx), m_retryPolicy,
        std::move(state), std::move(resultPromise));

    return future;
}

void DurableService::doExecuteAsyncRequest(
    AsyncRequest && asyncRequest, IRequestContextPtr ctx,
    IRetryPolicyPtr retryPolicy, RetryState && retryState,
    QPromise<QVariant> && resultPromise)
{
    QEC_DEBUG("durable_service", "Executing async " << asyncRequest.m_name
        << " request: " << retryState.m_retryCount << " attempts left, timeout = "
        << ctx->connectionTimeout() << ", request id = " << ctx->requestId());
    QEC_TRACE("durable_service", "Request details: "
        << asyncRequest.m_description);

    resultPromise.start();
    auto resultPromisePtr = std::make_shared<QPromise<QVariant>>(std::move(resultPromise));

    auto pWatcher = std::make_shared<QFutureWatcher<QVariant>>();

    auto attemptFuture = asyncRequest.m_call(ctx);
    std::function<void()> resultCallback =
        [ctx, retryPolicy, asyncRequest, resultPromisePtr, pWatcher, retryState]
        () mutable
        {
            std::exception_ptr exception;
            try
            {
                auto result = pWatcher->result();

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
                resultPromisePtr->addResult(std::move(result));
#else
                resultPromisePtr->addResult(result);
#endif
                resultPromisePtr->finish();
                return;
            }
            catch (const QException & e)
            {
                QEC_DEBUG("durable_service", "Exception: " << e.what());
                exception = std::current_exception();
            }

            Q_ASSERT_X(
                exception,
                "DurableService",
                "Unexpectedly null exception pointer");

            if (!retryPolicy->shouldRetry(exception)) {
                QEC_WARNING("durable_service", "Error is not retriable");

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
                resultPromisePtr->setException(exception);
#else
                try
                {
                    std::rethrow_exception(exception);
                }
                catch (const QException & e)
                {
                    resultPromisePtr->setException(e);
                }
#endif

                resultPromisePtr->finish();
                return;
            }

            --retryState.m_retryCount;
            if (!retryState.m_retryCount) {
                QEC_WARNING("durable_service", "No retry attempts left");

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
                resultPromisePtr->setException(exception);
#else
                try
                {
                    std::rethrow_exception(exception);
                }
                catch (const QException & e)
                {
                    resultPromisePtr->setException(e);
                }
#endif

                resultPromisePtr->finish();
                return;
            }

            if (ctx->increaseConnectionTimeoutExponentially())
            {
                auto timeout = ctx->connectionTimeout();
                auto maxTimeout = ctx->maxConnectionTimeout();

                timeout = exponentiallyIncreasedTimeoutMsec(
                    timeout, maxTimeout);

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
                std::move(asyncRequest), std::move(ctx), std::move(retryPolicy),
                std::move(retryState), std::move(*resultPromisePtr));

            resultPromisePtr.reset();
        };

    if (attemptFuture.isCanceled() || attemptFuture.isFinished())
    {
        pWatcher->setFuture(attemptFuture);
        resultCallback();
    }
    else
    {
        QObject::connect(
            pWatcher.get(),
            &QFutureWatcher<QVariant>::finished,
            pWatcher.get(),
            resultCallback,
            Qt::QueuedConnection);

        QObject::connect(
            pWatcher.get(),
            &QFutureWatcher<QVariant>::canceled,
            pWatcher.get(),
            resultCallback,
            Qt::QueuedConnection);

        pWatcher->setFuture(attemptFuture);
    }
}

////////////////////////////////////////////////////////////////////////////////

IRetryPolicyPtr newRetryPolicy()
{
    return std::make_shared<RetryPolicy>();
}

IRetryPolicyPtr nullRetryPolicy()
{
    return std::make_shared<NullRetryPolicy>();
}

IDurableServicePtr newDurableService(
    IRetryPolicyPtr retryPolicy,
    IRequestContextPtr ctx)
{
    return std::make_shared<DurableService>(retryPolicy, ctx);
}

} // namespace qevercloud
