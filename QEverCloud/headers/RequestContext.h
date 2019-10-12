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
#include <QTextStream>

#include <memory>

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
    /** Authentication token to use along with the request */
    virtual QString authenticationToken() const = 0;

    /** Request timeout in milliseconds */
    virtual quint64 requestTimeout() const = 0;

    /** Should request timeout be exponentially increased on retries or not */
    virtual bool increaseRequestTimeoutExponentially() const = 0;

    /**
     * Max request timeout in milliseconds (upper boundary for exponentially
     * increasing timeouts on retries)
     */
    virtual quint64 maxRequestTimeout() const = 0;

    /** Max number of attempts to retry a request */
    virtual quint32 maxRequestRetryCount() const = 0;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const IRequestContext & ctx);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const IRequestContext & ctx);
};

using IRequestContextPtr = std::shared_ptr<IRequestContext>;

////////////////////////////////////////////////////////////////////////////////

IRequestContextPtr newRequestContext(
    QString authenticationToken = {},
    quint64 requestTimeout = DEFAULT_REQUEST_TIMEOUT_MSEC,
    bool increaseRequestTimeoutExponentially = DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_ICREASE,
    quint64 maxRequestTimeout = DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
    quint32 maxRequestRetryCount = DEFAULT_MAX_REQUEST_RETRY_COUNT);

} // namespace qevercloud

#endif // QEVERCLOUD_REQUEST_CONTEXT_H