/**
 * Copyright (c) 2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/RequestContextBuilder.h>
#include <qevercloud/RequestContext.h>

namespace qevercloud {

class RequestContextBuilder::Impl
{
public:
    void reset()
    {
        m_authenticationToken.clear();
        m_requestTimeout = DEFAULT_REQUEST_TIMEOUT_MSEC;
        m_increaseRequestTimeoutExponentially =
            DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE;

        m_maxRequestTimeout = DEFAULT_MAX_REQUEST_TIMEOUT_MSEC;
        m_maxRetryCount = DEFAULT_MAX_REQUEST_RETRY_COUNT;
        m_cookies.clear();
    }

    QString m_authenticationToken;
    qint64 m_requestTimeout = DEFAULT_REQUEST_TIMEOUT_MSEC;

    bool m_increaseRequestTimeoutExponentially =
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE;

    qint64 m_maxRequestTimeout = DEFAULT_MAX_REQUEST_TIMEOUT_MSEC;
    quint32 m_maxRetryCount = DEFAULT_MAX_REQUEST_RETRY_COUNT;
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

RequestContextBuilder & RequestContextBuilder::setRequestTimeout(
    const qint64 timeoutMsec)
{
    m_impl->m_requestTimeout = timeoutMsec;
    return *this;
}

RequestContextBuilder & RequestContextBuilder::setIncreaseRequestTimeoutExponentially(
    const bool increaseRequestTimeoutExponentially)
{
    m_impl->m_increaseRequestTimeoutExponentially =
        increaseRequestTimeoutExponentially;

    return *this;
}

RequestContextBuilder & RequestContextBuilder::setMaxRequestTimeout(
    const qint64 timeoutMsec)
{
    m_impl->m_maxRequestTimeout = timeoutMsec;
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
        m_impl->m_requestTimeout,
        m_impl->m_increaseRequestTimeoutExponentially,
        m_impl->m_maxRequestTimeout,
        m_impl->m_maxRetryCount,
        std::move(m_impl->m_cookies));

    m_impl->reset();
    return ctx;
}

} // namespace qevercloud
