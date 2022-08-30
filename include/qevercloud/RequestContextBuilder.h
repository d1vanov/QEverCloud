/**
 * Copyright (c) 2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_REQUEST_CONTEXT_BUILDER_H
#define QEVERCLOUD_REQUEST_CONTEXT_BUILDER_H

#include <qevercloud/Export.h>
#include <qevercloud/Fwd.h>

#include <QNetworkCookie>
#include <QString>

#include <memory>

namespace qevercloud {

class QEVERCLOUD_EXPORT RequestContextBuilder
{
public:
    RequestContextBuilder();
    ~RequestContextBuilder();

    RequestContextBuilder & setAuthenticationToken(QString authenticationToken);
    RequestContextBuilder & setRequestTimeout(qint64 timeoutMsec);

    RequestContextBuilder & setIncreaseRequestTimeoutExponentially(
        bool increaseRequestTimeoutExponentially);

    RequestContextBuilder & setMaxRequestTimeout(qint64 timeoutMsec);
    RequestContextBuilder & setMaxRetryCount(quint32 maxRetryCount);
    RequestContextBuilder & setCookies(QList<QNetworkCookie> cookies);

    [[nodiscard]] IRequestContextPtr build();

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

} // namespace qevercloud

#endif // QEVERCLOUD_REQUEST_CONTEXT_BUILDER_H
