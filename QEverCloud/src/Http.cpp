/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"

#include <Exceptions.h>
#include <Helpers.h>
#include <Globals.h>

#include <QEventLoop>
#include <QtNetwork>
#include <QUrl>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

ReplyFetcher::ReplyFetcher(QObject * parent) :
    QObject(parent),
    m_ticker(new QTimer(this))
{
    QObject::connect(
        m_ticker, &QTimer::timeout,
        this, &ReplyFetcher::checkForTimeout);
}

void ReplyFetcher::start(
    QNetworkAccessManager * nam, QUrl url, qint64 timeoutMsec)
{
    QNetworkRequest request;
    request.setUrl(url);
    start(nam, request, timeoutMsec);
}

void ReplyFetcher::start(
    QNetworkAccessManager * nam, QNetworkRequest request, qint64 timeoutMsec,
    QByteArray postData)
{
    m_httpStatusCode = 0;
    m_errorType = QNetworkReply::NoError;
    m_errorText.clear();
    m_receivedData.clear();

    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
    m_timeoutMsec = timeoutMsec;
    m_ticker->start(1000);

    if (postData.isNull()) {
        m_reply = QNetworkReplyPtr(nam->get(request));
    }
    else {
        m_reply = QNetworkReplyPtr(nam->post(request, postData));
    }

    QObject::connect(m_reply.get(), &QNetworkReply::finished,
                     this, &ReplyFetcher::onFinished);
    QObject::connect(m_reply.get(), SIGNAL(error(QNetworkReply::NetworkError)),
                     this, SLOT(onError(QNetworkReply::NetworkError)));
    QObject::connect(m_reply.get(), &QNetworkReply::sslErrors,
                     this, &ReplyFetcher::onSslErrors);
    QObject::connect(m_reply.get(), &QNetworkReply::downloadProgress,
                     this, &ReplyFetcher::onDownloadProgress);
}

void ReplyFetcher::onDownloadProgress(qint64 downloaded, qint64 total)
{
    Q_UNUSED(downloaded)
    Q_UNUSED(total)

    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
}

void ReplyFetcher::checkForTimeout()
{
    if (m_timeoutMsec < 0) {
        return;
    }

    if ((QDateTime::currentMSecsSinceEpoch() - m_lastNetworkTime) > m_timeoutMsec) {
        setError(QNetworkReply::TimeoutError, QStringLiteral("Request timeout."));
    }
}

void ReplyFetcher::onFinished()
{
    m_ticker->stop();

    if (m_errorType != QNetworkReply::NoError) {
        return;
    }

    m_receivedData = m_reply->readAll();
    m_httpStatusCode = m_reply->attribute(
        QNetworkRequest::HttpStatusCodeAttribute).toInt();

    QObject::disconnect(m_reply.get());
    emit replyFetched(this);
}

void ReplyFetcher::onError(QNetworkReply::NetworkError error)
{
    setError(error, m_reply->errorString());
}

void ReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append(QStringLiteral("\n"));
    }

    setError(QNetworkReply::SslHandshakeFailedError, errorText);
}

void ReplyFetcher::setError(
    QNetworkReply::NetworkError errorType, QString errorText)
{
    m_ticker->stop();
    m_errorType = errorType;
    m_errorText = errorText;
    QObject::disconnect(m_reply.get());
    emit replyFetched(this);
}

////////////////////////////////////////////////////////////////////////////////

ReplyFetcherLauncher::ReplyFetcherLauncher(
        ReplyFetcher * fetcher,
        QNetworkAccessManager * nam,
        const QNetworkRequest & request,
        const qint64 timeoutMsec,
        const QByteArray & postData) :
    QObject(nam),
    m_fetcher(fetcher),
    m_nam(nam),
    m_request(request),
    m_timeoutMsec(timeoutMsec),
    m_postData(postData)
{}

void ReplyFetcherLauncher::start()
{
    m_fetcher->start(m_nam, m_request, m_timeoutMsec, m_postData);
}

////////////////////////////////////////////////////////////////////////////////

QByteArray simpleDownload(
    QNetworkAccessManager* nam, QNetworkRequest request, const qint64 timeoutMsec,
    QByteArray postData, int * httpStatusCode)
{
    ReplyFetcher * fetcher = new ReplyFetcher;
    QEventLoop loop;
    QObject::connect(fetcher, SIGNAL(replyFetched(QObject*)),
                     &loop, SLOT(quit()));

    ReplyFetcherLauncher * fetcherLauncher =
        new ReplyFetcherLauncher(fetcher, nam, request, timeoutMsec, postData);
    QTimer::singleShot(0, fetcherLauncher, SLOT(start()));
    loop.exec(QEventLoop::ExcludeUserInputEvents);

    fetcherLauncher->deleteLater();

    if (httpStatusCode) {
        *httpStatusCode = fetcher->httpStatusCode();
    }

    if (fetcher->isError()) {
        auto errorType = fetcher->errorType();
        QString errorText = fetcher->errorText();
        fetcher->deleteLater();
        throw NetworkException(errorType, errorText);
    }

    QByteArray receivedData = fetcher->receivedData();
    fetcher->deleteLater();
    return receivedData;
}

QNetworkRequest createEvernoteRequest(QString url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      QStringLiteral("application/x-thrift"));

    request.setHeader(
        QNetworkRequest::UserAgentHeader,
        QString::fromUtf8("QEverCloud %1.%2")
        .arg(libraryVersion() / 10000)
        .arg(libraryVersion() % 10000));

    request.setRawHeader("Accept", "application/x-thrift");
    return request;
}

QByteArray askEvernote(QString url, QByteArray postData, const qint64 timeoutMsec)
{
    int httpStatusCode = 0;
    QByteArray reply = simpleDownload(
        evernoteNetworkAccessManager(),
        createEvernoteRequest(url),
        timeoutMsec,
        postData,
        &httpStatusCode);

    if (httpStatusCode != 200) {
        throw EverCloudException(
            QString::fromUtf8("HTTP Status Code = %1").arg(httpStatusCode));
    }

    return reply;
}

} // namespace qevercloud

/** @endcond */
