/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "RequestContext.h"

#include <qevercloud/IRequestContext.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

namespace {

template <typename T>
void printRequestContext(const IRequestContext & ctx, T & strm)
{
    strm << "RequestContext:\n"
        << "    authentication token = " << ctx.authenticationToken() << "\n"
        << "    request timeout = " << ctx.connectionTimeout() << "\n"
        << "    increase request timeout exponentially = "
        << (ctx.increaseConnectionTimeoutExponentially() ? "yes" : "no") << "\n"
        << "    max request timeout = " << ctx.maxConnectionTimeout() << "\n"
        << "    max request retry count = " << ctx.maxRequestRetryCount()
        << "\n";

    const auto cookies = ctx.cookies();
    if (!cookies.isEmpty())
    {
        strm << "    cookies: " << "\n";

        for(const auto & cookie: qAsConst(cookies)) {
            strm << "        " << QString::fromUtf8(cookie.toRawForm()) << "\n";
        }
    }
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

IRequestContext::~IRequestContext() = default;

QTextStream & operator<<(QTextStream & strm, const IRequestContext & ctx)
{
    printRequestContext(ctx, strm);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const IRequestContext & ctx)
{
    printRequestContext(ctx, dbg);
    return dbg;
}

////////////////////////////////////////////////////////////////////////////////

IRequestContextPtr newRequestContext(
    QString authenticationToken,
    qint64 connectionTimeout,
    bool increaseConnectionTimeoutExponentially,
    qint64 maxConnectionTimeout,
    quint32 maxRequestRetryCount,
    QList<QNetworkCookie> cookies)
{
    return std::make_shared<RequestContext>(
        std::move(authenticationToken),
        connectionTimeout,
        increaseConnectionTimeoutExponentially,
        maxConnectionTimeout,
        maxRequestRetryCount,
        std::move(cookies));
}

} // namespace qevercloud
