/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_DURABLE_SERVICE_H
#define QEVERCLOUD_DURABLE_SERVICE_H

#include "AsyncResult.h"
#include "Export.h"
#include "RequestContext.h"

#include <QDateTime>
#include <QVariant>

#include <functional>
#include <memory>
#include <utility>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

struct QEVERCLOUD_EXPORT IRetryPolicy
{
    virtual bool shouldRetry(
        QSharedPointer<EverCloudExceptionData> exceptionData) = 0;
};

using IRetryPolicyPtr = std::shared_ptr<IRetryPolicy>;

////////////////////////////////////////////////////////////////////////////////

QT_FORWARD_DECLARE_CLASS(DurableServicePrivate)

class QEVERCLOUD_EXPORT IDurableService
{
public:
    using SyncResult = std::pair<QVariant, QSharedPointer<EverCloudExceptionData>>;
    using SyncServiceCall = std::function<SyncResult(IRequestContextPtr)>;
    using AsyncServiceCall = std::function<AsyncResult*(IRequestContextPtr)>;

public:
    virtual SyncResult executeSyncRequest(
        SyncServiceCall && syncServiceCall, IRequestContextPtr ctx) = 0;

    virtual AsyncResult * executeAsyncRequest(
        AsyncServiceCall && asyncServiceCall, IRequestContextPtr ctx) = 0;
};

using IDurableServicePtr = std::shared_ptr<IDurableService>;

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT IRetryPolicyPtr newRetryPolicy();

QEVERCLOUD_EXPORT IDurableServicePtr newDurableService(
    IRetryPolicyPtr = {},
    IRequestContextPtr = {});

} // namespace qevercloud

#endif // QEVERCLOUD_DURABLE_SERVICE_H
