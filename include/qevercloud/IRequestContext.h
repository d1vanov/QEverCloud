/**
 * Copyright (c) 2019-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_I_REQUEST_CONTEXT_H
#define QEVERCLOUD_I_REQUEST_CONTEXT_H

#include <qevercloud/Export.h>
#include <qevercloud/Fwd.h>

#include <QDebug>
#include <QList>
#include <QNetworkCookie>
#include <QTextStream>
#include <QUuid>

#include <memory>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

constexpr quint64 gDefaultConnectionTimeoutMsec = 10000ull;

constexpr bool gDefaultConnectionTimeoutExponentialIncrease = true;

constexpr quint64 gDefaultMaxConnectionTimeoutMsec = 600000ull;

constexpr quint32 gDefaultMaxRequestRetryCount = 10;

////////////////////////////////////////////////////////////////////////////////

/**
 * IRequestContext carries several request scoped values defining the way
 * request is handled by QEverCloud
 */
class QEVERCLOUD_EXPORT IRequestContext
{
public:
    /**
     * Automatically generated unique identifier for each request
     */
    [[nodiscard]] virtual QUuid requestId() const = 0;

    /**
     * Authentication token to use along with the request
     */
    [[nodiscard]] virtual QString authenticationToken() const = 0;

    /**
     * Network connection timeout in milliseconds. If not a single packet with
     * data comes along during this timeout, the corresponding Evernote API call
     * is considered failed.
     */
    [[nodiscard]] virtual qint64 connectionTimeout() const = 0;

    /**
     * Should network connection timeout be exponentially increased on retries
     * or not
     */
    [[nodiscard]] virtual bool increaseConnectionTimeoutExponentially() const = 0;

    /**
     * Max network connection timeout in milliseconds (upper boundary for
     * exponentially increasing timeouts on retries)
     */
    [[nodiscard]] virtual qint64 maxConnectionTimeout() const = 0;

    /** Max number of attempts to retry a request */
    [[nodiscard]] virtual quint32 maxRequestRetryCount() const = 0;

    /** Cookies to set to QNetworkRequest corresponding to Evernote API call */
    [[nodiscard]] virtual QList<QNetworkCookie> cookies() const = 0;

    /**
     * Create a new instance of IRequestContext with all the same parameters
     * as in the source but a distinct id
     */
    [[nodiscard]] virtual IRequestContext * clone() const = 0;

    virtual ~IRequestContext();

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const IRequestContext & ctx);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const IRequestContext & ctx);
};

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT IRequestContextPtr newRequestContext(
    QString authenticationToken = {},
    qint64 connectionTimeout = gDefaultConnectionTimeoutMsec,
    bool increaseConnectionTimeoutExponentially =
        gDefaultConnectionTimeoutExponentialIncrease,
    qint64 maxConnectionTimeout = gDefaultMaxConnectionTimeoutMsec,
    quint32 maxRequestRetryCount = gDefaultMaxRequestRetryCount,
    QList<QNetworkCookie> cookies = {});

} // namespace qevercloud

#endif // QEVERCLOUD_I_REQUEST_CONTEXT_H
