/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_REQUEST_CONTEXT_H
#define QEVERCLOUD_REQUEST_CONTEXT_H

#include <qevercloud/IRequestContext.h>

namespace qevercloud {

class Q_DECL_HIDDEN RequestContext final: public IRequestContext
{
public:
    RequestContext(
        QString authenticationToken, qint64 connectionTimeout,
        bool increaseConnectionTimeoutExponentially,
        qint64 maxConnectionTimeout, quint32 maxRequestRetryCount,
        QList<QNetworkCookie> cookies);

public: // IRequestContext
    [[nodiscard]] QUuid requestId() const override;
    [[nodiscard]] QString authenticationToken() const override;
    [[nodiscard]] qint64 connectionTimeout() const noexcept override;
    [[nodiscard]] bool increaseConnectionTimeoutExponentially() const noexcept override;
    [[nodiscard]] qint64 maxConnectionTimeout() const noexcept override;
    [[nodiscard]] quint32 maxRequestRetryCount() const noexcept override;
    [[nodiscard]] QList<QNetworkCookie> cookies() const override;
    [[nodiscard]] IRequestContext * clone() const override;

private:
    QUuid       m_requestId;
    QString     m_authenticationToken;
    qint64      m_connectionTimeout;
    bool        m_increaseConnectionTimeoutExponentially;
    qint64      m_maxConnectionTimeout;
    quint32     m_maxRequestRetryCount;

    QList<QNetworkCookie>   m_cookies;
};

} // namespace qevercloud

#endif // QEVERCLOUD_REQUEST_CONTEXT_H
