/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "OAuthWebKit.h"

#include "NetworkCookieJar.h"
#include "Utils.h"

#include <qevercloud/NetworkProxy.h>
#include <qevercloud/utility/Log.h>

namespace qevercloud {

EvernoteOAuthWidgetPrivate::EvernoteOAuthWidgetPrivate(QWidget * parent) :
    QWebView(parent)
{
    auto * pNam = page()->networkAccessManager();
    pNam->setProxy(evernoteNetworkProxy());
    pNam->setCookieJar(new NetworkCookieJar);
}

EvernoteOAuthWidgetPrivate::~EvernoteOAuthWidgetPrivate()
{
    QWebSettings::clearMemoryCaches();
}

void EvernoteOAuthWidgetPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

void EvernoteOAuthWidgetPrivate::onUrlChanged(const QUrl & url)
{
    const auto urlString = url.toString();
    if (!urlString.contains(QString::fromUtf8("%1?").arg(oauthCallbackUrl()))) {
        // Hack which appears to solve the problem of login page freezing on
        // analytics pitstop
        back();
        return;
    }

    onOAuthCallback(urlString);
}

void EvernoteOAuthWidgetPrivate::onAuthenticationFinished(bool success)
{
    Q_EMIT authenticationFinished(success);
}

void EvernoteOAuthWidgetPrivate::openOAuthPage(QUrl pageUrl)
{
    QEC_DEBUG("oauth[webkit]", "EvernoteOAuthWidgetPrivate::openOAuthPage");

    QObject::connect(
        this, &EvernoteOAuthWidgetPrivate::urlChanged,
        this, &EvernoteOAuthWidgetPrivate::onUrlChanged);

    QNetworkRequest request;
    request.setUrl(pageUrl);
    request.setRawHeader(
        QByteArray("Accept-Language"), httpAcceptLanguage().toUtf8());

    load(request);
}

void EvernoteOAuthWidgetPrivate::onOAuthResponseReceived()
{
    QObject::disconnect(
        this, &EvernoteOAuthWidgetPrivate::urlChanged,
        this, &EvernoteOAuthWidgetPrivate::onUrlChanged);

    QMetaObject::invokeMethod(this, "clearHtml", Qt::QueuedConnection);
}

void EvernoteOAuthWidgetPrivate::clear()
{
    setHtml(QLatin1String(""));
    history()->clear();
}

QObject * EvernoteOAuthWidgetPrivate::context()
{
    return this;
}

bool EvernoteOAuthWidgetPrivate::onStartAuthentication()
{
    setHtml(QLatin1String(""));
    history()->clear();
    return true;
}

QString EvernoteOAuthWidgetPrivate::oauthCallbackUrl() const
{
    return QStringLiteral("nnoauth");
}

QNetworkAccessManager * EvernoteOAuthWidgetPrivate::networkAccessManager(
    QObject * rf)
{
    return page()->networkAccessManager();
}

QList<QNetworkCookie> EvernoteOAuthWidgetPrivate::extractCookies(
    ReplyFetcher * rf)
{
    Q_ASSERT(rf);

    auto * pNam = rf->networkAccessManager();
    if (Q_UNLIKELY(!pNam)) {
        QEC_WARNING("oauth[webkit]", "Failed to extract cookies after OAuth: "
            << "network access manager instance expired");
        return {};
    }

    auto * pCookieJar = qobject_cast<NetworkCookieJar*>(pNam->cookieJar());
    if (Q_UNLIKELY(!pCookieJar)) {
        QEC_WARNING("oauth[webkit]", "Failed to extract cookies after OAuth: "
            << "unexpected instance of cookie jar");
        return {};
    }

    return pCookieJar->allCookies();
}

} // namespace qevercloud
