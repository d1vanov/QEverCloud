/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_DURABLE_SERVICE_H
#define QEVERCLOUD_DURABLE_SERVICE_H

#include <AsyncResult.h>
#include <RequestContext.h>

#include <QDateTime>
#include <QVariant>

#include <functional>
#include <memory>
#include <utility>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

struct Q_DECL_HIDDEN RetryState
{
    qint64 m_started = QDateTime::currentMSecsSinceEpoch();
    quint32 m_retryCount = 0;
};

////////////////////////////////////////////////////////////////////////////////

struct Q_DECL_HIDDEN IRetryPolicy
{
    virtual bool shouldRetry(
        QSharedPointer<EverCloudExceptionData> exceptionData) = 0;
};

using IRetryPolicyPtr = std::shared_ptr<IRetryPolicy>;

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN DurableService: public QObject
{
    Q_OBJECT
public:
    using SyncResult = std::pair<QVariant, QSharedPointer<EverCloudExceptionData>>;
    using SyncServiceCall = std::function<SyncResult(IRequestContextPtr)>;
    using AsyncServiceCall = std::function<AsyncResult*(IRequestContextPtr)>;

public:
    DurableService(IRetryPolicyPtr retryPolicy, IRequestContextPtr ctx);

    SyncResult executeSyncRequest(
        SyncServiceCall && syncServiceCall, IRequestContextPtr ctx);

    AsyncResult * executeAsyncRequest(
        AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx);

private:
    void doExecuteAsyncRequest(
        AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx,
        RetryState && retryState, AsyncResult * result);

private:
    IRetryPolicyPtr     m_retryPolicy;
    IRequestContextPtr  m_ctx;
};

////////////////////////////////////////////////////////////////////////////////

IRetryPolicyPtr newRetryPolicy();

} // namespace qevercloud

#endif // QEVERCLOUD_DURABLE_SERVICE_H
