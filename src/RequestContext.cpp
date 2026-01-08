/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "RequestContext.h"

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

RequestContext::RequestContext(
    std::optional<QUuid> requestId,
    QString authenticationToken, qint64 connectionTimeout,
    bool increaseConnectionTimeoutExponentially,
    qint64 maxConnectionTimeout, quint32 maxRequestRetryCount,
    QList<QNetworkCookie> cookies) :
    m_requestId{requestId.value_or(QUuid::createUuid())},
    m_authenticationToken{std::move(authenticationToken)},
    m_connectionTimeout{connectionTimeout},
    m_increaseConnectionTimeoutExponentially{increaseConnectionTimeoutExponentially},
    m_maxConnectionTimeout{maxConnectionTimeout},
    m_maxRequestRetryCount{maxRequestRetryCount},
    m_cookies{std::move(cookies)}
{
}

QUuid RequestContext::requestId() const
{
    return m_requestId;
}

QString RequestContext::authenticationToken() const
{
    return m_authenticationToken;
}

qint64 RequestContext::connectionTimeout() const noexcept
{
    return m_connectionTimeout;
}

bool RequestContext::increaseConnectionTimeoutExponentially() const noexcept
{
    return m_increaseConnectionTimeoutExponentially;
}

qint64 RequestContext::maxConnectionTimeout() const noexcept
{
    return m_maxConnectionTimeout;
}

quint32 RequestContext::maxRequestRetryCount() const noexcept
{
    return m_maxRequestRetryCount;
}

QList<QNetworkCookie> RequestContext::cookies() const
{
    return m_cookies;
}

IRequestContext * RequestContext::clone() const
{
    return new RequestContext(
        std::nullopt,
        m_authenticationToken,
        m_connectionTimeout,
        m_increaseConnectionTimeoutExponentially,
        m_maxConnectionTimeout,
        m_maxRequestRetryCount,
        m_cookies);
}

} // namespace qevercloud
