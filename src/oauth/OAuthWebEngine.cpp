/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "OAuthWebEngine.h"

#include "NetworkCookieJar.h"
#include "Utils.h"

#include <qevercloud/utility/Log.h>

namespace qevercloud {

EvernoteOAuthWidgetPrivate::EvernoteOAuthWidgetPrivate(QWidget * parent) :
    QWebEngineView(parent),
    m_pCookieJar{new NetworkCookieJar(this)}
{
    m_pCookieJar->loadStore();

    page()->profile()->defaultProfile()->setHttpAcceptLanguage(
        httpAcceptLanguage());
}

void EvernoteOAuthWidgetPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

void EvernoteOAuthWidgetPrivate::onUrlChanged(const QUrl & url)
{
    const auto urlString = url.toString();
    if (!urlString.contains(QString::fromUtf8("%1?").arg(oauthCallbackUrl()))) {
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
    QEC_DEBUG("oauth[webengine]", "EvernoteOAuthWidgetPrivate::openOAuthPage");

    QObject::connect(
        this, &EvernoteOAuthWidgetPrivate::urlChanged,
        this, &EvernoteOAuthWidgetPrivate::onUrlChanged);

    setUrl(std::move(pageUrl));
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
    auto * pNam = new QNetworkAccessManager(rf);
    pNam->setCookieJar(new NetworkCookieJar);
    return pNam;
}

QList<QNetworkCookie> EvernoteOAuthWidgetPrivate::extractCookies(
    ReplyFetcher * rf)
{
    Q_UNUSED(rf)
    Q_ASSERT(m_pCookieJar);
    return m_pCookieJar->allCookies();
}

} // namespace qevercloud
