/**
 * Copyright (c) 2019-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_DURABLE_SERVICE_H
#define QEVERCLOUD_DURABLE_SERVICE_H

#include <qevercloud/Export.h>
#include <qevercloud/Fwd.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/exceptions/EverCloudException.h>

#include <QDateTime>
#include <QFuture>
#include <QVariant>

#include <exception>
#include <functional>
#include <memory>
#include <utility>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

struct QEVERCLOUD_EXPORT IRetryPolicy
{
    [[nodiscard]] virtual bool shouldRetry(std::exception_ptr exc) = 0;
};

////////////////////////////////////////////////////////////////////////////////

class DurableServicePrivate;

class QEVERCLOUD_EXPORT IDurableService
{
public:
    using SyncResult = std::pair<QVariant,std::exception_ptr>;
    using SyncServiceCall = std::function<SyncResult(IRequestContextPtr)>;
    using AsyncServiceCall = std::function<QFuture<QVariant>(IRequestContextPtr)>;

    struct QEVERCLOUD_EXPORT SyncRequest
    {
        const char *    m_name;
        QString         m_description;
        SyncServiceCall m_call;

        SyncRequest(const char * name, QString description,
                    SyncServiceCall && call) :
            m_name(name),
            m_description(std::move(description)),
            m_call(std::move(call))
        {}
    };

    struct QEVERCLOUD_EXPORT AsyncRequest
    {
        const char *        m_name;
        QString             m_description;
        AsyncServiceCall    m_call;

        AsyncRequest(const char * name, QString description,
                     AsyncServiceCall && call) :
            m_name(name),
            m_description(std::move(description)),
            m_call(std::move(call))
        {}
    };

public:
    [[nodiscard]] virtual SyncResult executeSyncRequest(
        SyncRequest && syncRequest, IRequestContextPtr ctx) = 0;

    [[nodiscard]] virtual QFuture<QVariant> executeAsyncRequest(
        AsyncRequest && asyncRequest, IRequestContextPtr ctx) = 0;
};

using IDurableServicePtr = std::shared_ptr<IDurableService>;

////////////////////////////////////////////////////////////////////////////////

[[nodiscard]] QEVERCLOUD_EXPORT IRetryPolicyPtr newRetryPolicy();

[[nodiscard]] QEVERCLOUD_EXPORT IRetryPolicyPtr nullRetryPolicy();

[[nodiscard]] QEVERCLOUD_EXPORT IDurableServicePtr newDurableService(
    IRetryPolicyPtr = {},
    IRequestContextPtr = {});

} // namespace qevercloud

#endif // QEVERCLOUD_DURABLE_SERVICE_H
