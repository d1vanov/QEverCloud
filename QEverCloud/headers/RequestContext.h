/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_REQUEST_CONTEXT_H
#define QEVERCLOUD_REQUEST_CONTEXT_H

#include "Export.h"

#include <QDebug>
#include <QSharedPointer>
#include <QTextStream>
#include <QUuid>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

static constexpr quint64 DEFAULT_REQUEST_TIMEOUT_MSEC = 10'000ull;

static constexpr bool DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_ICREASE = true;

static constexpr quint64 DEFAULT_MAX_REQUEST_TIMEOUT_MSEC = 600'000ull;

static constexpr quint32 DEFAULT_MAX_REQUEST_RETRY_COUNT = 10;

////////////////////////////////////////////////////////////////////////////////

/**
 * IRequestContext carries several request scoped values defining the way
 * request is handled by QEverCloud
 */
class QEVERCLOUD_EXPORT IRequestContext
{
public:
    /** Automatically generated unique identifier for each request */
    virtual QUuid requestId() const = 0;

    /** Authentication token to use along with the request */
    virtual QString authenticationToken() const = 0;

    /** Request timeout in milliseconds */
    virtual qint64 requestTimeout() const = 0;

    /** Should request timeout be exponentially increased on retries or not */
    virtual bool increaseRequestTimeoutExponentially() const = 0;

    /**
     * Max request timeout in milliseconds (upper boundary for exponentially
     * increasing timeouts on retries)
     */
    virtual qint64 maxRequestTimeout() const = 0;

    /** Max number of attempts to retry a request */
    virtual quint32 maxRequestRetryCount() const = 0;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const IRequestContext & ctx);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const IRequestContext & ctx);
};

using IRequestContextPtr = QSharedPointer<IRequestContext>;

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT IRequestContextPtr newRequestContext(
    QString authenticationToken = {},
    qint64 requestTimeout = DEFAULT_REQUEST_TIMEOUT_MSEC,
    bool increaseRequestTimeoutExponentially = DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_ICREASE,
    qint64 maxRequestTimeout = DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
    quint32 maxRequestRetryCount = DEFAULT_MAX_REQUEST_RETRY_COUNT);

} // namespace qevercloud

#endif // QEVERCLOUD_REQUEST_CONTEXT_H
