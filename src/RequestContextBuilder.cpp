/**
 * Copyright (c) 2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/IRequestContext.h>
#include <qevercloud/RequestContextBuilder.h>

namespace qevercloud {

class RequestContextBuilder::Impl
{
public:
    void reset()
    {
        m_authenticationToken.clear();
        m_connectionTimeout = gDefaultConnectionTimeoutMsec;
        m_increaseConnectionTimeoutExponentially =
            gDefaultConnectionTimeoutExponentialIncrease;

        m_maxConnectionTimeout = gDefaultMaxConnectionTimeoutMsec;
        m_maxRetryCount = gDefaultMaxRequestRetryCount;
        m_cookies.clear();
    }

    QString m_authenticationToken;
    qint64 m_connectionTimeout = gDefaultConnectionTimeoutMsec;

    bool m_increaseConnectionTimeoutExponentially =
        gDefaultConnectionTimeoutExponentialIncrease;

    qint64 m_maxConnectionTimeout = gDefaultMaxConnectionTimeoutMsec;
    quint32 m_maxRetryCount = gDefaultMaxRequestRetryCount;
    QList<QNetworkCookie> m_cookies = {};
};

RequestContextBuilder::RequestContextBuilder() :
    m_impl{std::make_unique<Impl>()}
{}

RequestContextBuilder::~RequestContextBuilder() = default;

RequestContextBuilder & RequestContextBuilder::setAuthenticationToken(
    QString authenticationToken)
{
    m_impl->m_authenticationToken = std::move(authenticationToken);
    return *this;
}

RequestContextBuilder & RequestContextBuilder::setConnectionTimeout(
    const qint64 timeoutMsec)
{
    m_impl->m_connectionTimeout = timeoutMsec;
    return *this;
}

RequestContextBuilder & RequestContextBuilder::setIncreaseConnectionTimeoutExponentially(
    const bool increaseRequestTimeoutExponentially)
{
    m_impl->m_increaseConnectionTimeoutExponentially =
        increaseRequestTimeoutExponentially;

    return *this;
}

RequestContextBuilder & RequestContextBuilder::setMaxConnectionTimeout(
    const qint64 timeoutMsec)
{
    m_impl->m_maxConnectionTimeout = timeoutMsec;
    return *this;
}

RequestContextBuilder & RequestContextBuilder::setMaxRetryCount(
    const quint32 maxRetryCount)
{
    m_impl->m_maxRetryCount = maxRetryCount;
    return *this;
}

RequestContextBuilder & RequestContextBuilder::setCookies(
    QList<QNetworkCookie> cookies)
{
    m_impl->m_cookies = std::move(cookies);
    return *this;
}

IRequestContextPtr RequestContextBuilder::build()
{
    auto ctx = newRequestContext(
        std::move(m_impl->m_authenticationToken),
        m_impl->m_connectionTimeout,
        m_impl->m_increaseConnectionTimeoutExponentially,
        m_impl->m_maxConnectionTimeout,
        m_impl->m_maxRetryCount,
        std::move(m_impl->m_cookies));

    m_impl->reset();
    return ctx;
}

} // namespace qevercloud
