/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"

#include <Exceptions.h>
#include <Helpers.h>
#include <Globals.h>
#include <Log.h>
#include <VersionInfo.h>

#include <QEventLoop>
#include <QtNetwork>
#include <QUrl>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

ReplyFetcher::ReplyFetcher(QObject * parent) :
    QObject(parent),
    m_pTicker(new QTimer(this))
{
    QObject::connect(
        m_pTicker,
        &QTimer::timeout,
        this,
        &ReplyFetcher::checkForTimeout);
}

void ReplyFetcher::start(
    QNetworkAccessManager * pNam, QUrl url, qint64 timeoutMsec)
{
    QNetworkRequest request;
    request.setUrl(url);
    start(pNam, request, timeoutMsec);
}

void ReplyFetcher::start(
    QNetworkAccessManager * pNam, QNetworkRequest request, qint64 timeoutMsec,
    QByteArray postData)
{
    QEC_TRACE("http", "ReplyFetcher started for URL " << request.url()
        << ", post data size: " << postData.size());

    m_pNam = pNam;

    m_httpStatusCode = 0;
    m_errorType = QNetworkReply::NoError;
    m_errorText.clear();
    m_receivedData.clear();

    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
    m_timeoutMsec = timeoutMsec;
    m_pTicker->start(1000);

    if (postData.isNull()) {
        m_pReply = QNetworkReplyPtr(pNam->get(request));
    }
    else {
        m_pReply = QNetworkReplyPtr(pNam->post(request, postData));
    }

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::finished,
        this,
        &ReplyFetcher::onFinished);

#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::errorOccurred,
        this,
        &ReplyFetcher::onError);
#elif QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
    QObject::connect(
        m_pReply.get(),
        qOverload<QNetworkReply::NetworkError>(&QNetworkReply::error),
        this,
        &ReplyFetcher::onError);
#else
    QObject::connect(
        m_pReply.get(),
        SIGNAL(error(QNetworkReply::NetworkError)),
        this,
        SLOT(onError(QNetworkReply::NetworkError)));
#endif

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::sslErrors,
        this,
        &ReplyFetcher::onSslErrors);

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::downloadProgress,
        this,
        &ReplyFetcher::onDownloadProgress);
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
        setError(QNetworkReply::TimeoutError, QStringLiteral("Request timeout"));
    }
}

void ReplyFetcher::onFinished()
{
    QEC_TRACE("http", "ReplyFetcher finished")

    m_pTicker->stop();

    if (m_errorType != QNetworkReply::NoError) {
        return;
    }

    m_receivedData = m_pReply->readAll();
    m_httpStatusCode = m_pReply->attribute(
        QNetworkRequest::HttpStatusCodeAttribute).toInt();

    QObject::disconnect(m_pReply.get());
    Q_EMIT replyFetched(this);
}

void ReplyFetcher::onError(QNetworkReply::NetworkError error)
{
    QEC_WARNING("http", "ReplyFetcher error: code = "
        << error << ", description: " << m_pReply->errorString()
        << "; http status code: " << m_pReply->attribute(
            QNetworkRequest::HttpStatusCodeAttribute).toInt());

    setError(error, m_pReply->errorString());
}

void ReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append(QStringLiteral("\n"));
    }

    QEC_WARNING("http", errorText);
    setError(QNetworkReply::SslHandshakeFailedError, errorText);
}

void ReplyFetcher::setError(
    QNetworkReply::NetworkError errorType, QString errorText)
{
    m_pTicker->stop();
    m_errorType = errorType;
    m_errorText = errorText;
    QObject::disconnect(m_pReply.get());
    Q_EMIT replyFetched(this);
}

////////////////////////////////////////////////////////////////////////////////

ReplyFetcherLauncher::ReplyFetcherLauncher(
        ReplyFetcher * fetcher,
        QNetworkAccessManager * nam,
        const QNetworkRequest & request,
        const qint64 timeoutMsec,
        const QByteArray & postData) :
    QObject(nam),
    m_pFetcher(fetcher),
    m_pNam(nam),
    m_request(request),
    m_timeoutMsec(timeoutMsec),
    m_postData(postData)
{}

void ReplyFetcherLauncher::start()
{
    m_pFetcher->start(m_pNam, m_request, m_timeoutMsec, m_postData);
}

////////////////////////////////////////////////////////////////////////////////

QByteArray simpleDownload(
    QNetworkRequest request, const qint64 timeoutMsec,
    QByteArray postData, int * pHttpStatusCode)
{
    auto * pFetcher = new ReplyFetcher;

    auto * pNam = new QNetworkAccessManager(pFetcher);
    pNam->setProxy(evernoteNetworkProxy());

    QEventLoop loop;
    QObject::connect(
        pFetcher,
        SIGNAL(replyFetched(ReplyFetcher*)),
        &loop,
        SLOT(quit()));

    auto * fetcherLauncher = new ReplyFetcherLauncher(
        pFetcher,
        pNam,
        request,
        timeoutMsec,
        postData);

    QTimer::singleShot(0, fetcherLauncher, SLOT(start()));
    loop.exec(QEventLoop::ExcludeUserInputEvents);

    fetcherLauncher->deleteLater();

    if (pHttpStatusCode) {
        *pHttpStatusCode = pFetcher->httpStatusCode();
    }

    if (pFetcher->isError()) {
        auto errorType = pFetcher->errorType();
        QString errorText = pFetcher->errorText();
        pFetcher->deleteLater();
        throw NetworkException(errorType, errorText);
    }

    QByteArray receivedData = pFetcher->receivedData();
    pFetcher->deleteLater();
    return receivedData;
}

QNetworkRequest createEvernoteRequest(
    QString url, QList<QNetworkCookie> cookies)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        QStringLiteral("application/x-thrift"));

    request.setHeader(
        QNetworkRequest::UserAgentHeader,
        QString::fromUtf8("QEverCloud %1.%2.%3")
        .arg(qevercloudVersionMajor())
        .arg(qevercloudVersionMinor())
        .arg(qevercloudVersionPatch()));

    request.setRawHeader("Accept", "application/x-thrift");

    if (!cookies.isEmpty()) {
        request.setHeader(QNetworkRequest::CookieHeader, QVariant::fromValue(cookies));
    }

    return request;
}

QByteArray askEvernote(
    QString url, QByteArray postData, const qint64 timeoutMsec,
    QList<QNetworkCookie> cookies)
{
    int httpStatusCode = 0;
    QByteArray reply = simpleDownload(
        createEvernoteRequest(url, std::move(cookies)),
        timeoutMsec,
        postData,
        &httpStatusCode);

    if (httpStatusCode != 200) {
        throw EverCloudException(
            QString::fromUtf8("HTTP Status Code = %1").arg(httpStatusCode));
    }

    return reply;
}

////////////////////////////////////////////////////////////////////////////////

HttpRequestParser::HttpRequestParser(QTcpSocket & socket, QObject * parent) :
    QObject(parent)
{
    QObject::connect(
        &socket,
        &QIODevice::readyRead,
        this,
        &HttpRequestParser::onSocketReadyRead,
        Qt::QueuedConnection);
}

bool HttpRequestParser::status() const noexcept
{
    return m_status;
}

const QByteArray & HttpRequestParser::data() const noexcept
{
    return m_requestData.body;
}

HttpRequestData HttpRequestParser::requestData() const
{
    return m_requestData;
}

void HttpRequestParser::onSocketReadyRead()
{
    QTcpSocket * pSocket = qobject_cast<QTcpSocket*>(sender());
    Q_ASSERT(pSocket);

    m_data.append(pSocket->read(pSocket->bytesAvailable()));
    tryParseData();
}

void HttpRequestParser::tryParseData()
{
    // Data read from socket should be a HTTP request with headers and body.
    // Maybe incomplete in which case we postpone the attempt to parse
    // the request.

    // The first line of a HTTP request should be the request line:
    // method<space>request-uri<space>http-version<crlf>
    int methodEndIndex = m_data.indexOf(" ");
    if (methodEndIndex < 0) {
        // No first space symbol, probably not all data has arrived yet
        return;
    }

    const QByteArray method{m_data.constData(), methodEndIndex};
    if (method == QByteArray::fromRawData("GET", 3))
    {
        m_requestData.method = HttpRequestData::Method::GET;
    }
    else if (method == QByteArray::fromRawData("POST", 4))
    {
        m_requestData.method = HttpRequestData::Method::POST;
    }

    int resourceUriEndIndex = m_data.indexOf(" ", methodEndIndex + 1);
    if (resourceUriEndIndex < 0) {
        // No resource URI end index, probably not all data has arrived yet
        return;
    }

    m_requestData.uri = QByteArray{
        m_data.constData() + methodEndIndex + 1,
        resourceUriEndIndex - methodEndIndex - 1};

    if (m_requestData.method == HttpRequestData::Method::GET)
    {
        // GET requests don't include Content-Length header so we need to look
        // for two consequent carriage returns with nothing in between them
        // to determine that the whole HTTP request has been received.
        const int requestEndIndex =
            m_data.indexOf("\r\n\r\n", resourceUriEndIndex + 1);
        if (requestEndIndex < 0) {
            return;
        }

        m_status = true;
        Q_EMIT finished();
        return;
    }

    // For POST request will parse headers, find Content-Length one to figure
    // out the size of request body
    int contentLengthIndex =
        m_data.indexOf("Content-Length:", resourceUriEndIndex + 1);
    if (contentLengthIndex < 0) {
        // No Content-Length header, probably not all data has arrived yet
        return;
    }

    int contentLengthLineEndIndex = m_data.indexOf("\r\n", contentLengthIndex);
    if (contentLengthLineEndIndex < 0) {
        // No line end after Content-Length header, probably not all data
        // has arrived yet
        return;
    }

    int contentLengthLen = contentLengthLineEndIndex - contentLengthIndex - 15;
    QString contentLengthStr =
        QString::fromUtf8(m_data.mid(contentLengthIndex + 15, contentLengthLen));

    bool conversionResult = false;
    int contentLength = contentLengthStr.toInt(&conversionResult);
    if (Q_UNLIKELY(!conversionResult)) {
        QEC_WARNING(
            "http",
            "Failed to convert content length header value to int: "
                << contentLengthStr);
        m_status = false;
        Q_EMIT failed();
        return;
    }

    // Now see whether whole body data is present
    int headersEndIndex = m_data.indexOf("\r\n\r\n", contentLengthLineEndIndex);
    if (headersEndIndex < 0) {
        // No empty line after http headers, probably not all data has
        // arrived yet
        return;
    }

    QByteArray body = m_data;
    body.remove(0, headersEndIndex + 4);
    if (body.size() < contentLength) {
        // Not all data has arrived yet
        return;
    }

    m_requestData.body = body;
    m_status = true;
    Q_EMIT finished();
}

HttpRequestData readRequestDataFromSocket(QTcpSocket & socket)
{
    if (!socket.waitForConnected()) {
        return {};
    }

    QEventLoop loop;
    HttpRequestParser extractor(socket);

    QObject::connect(
        &extractor,
        &HttpRequestParser::finished,
        &loop,
        &QEventLoop::quit);

    QObject::connect(
        &extractor,
        &HttpRequestParser::failed,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    if (!extractor.status()) {
        return {};
    }

    return extractor.requestData();
}

QByteArray readRequestBodyFromSocket(QTcpSocket & socket)
{
    return readRequestDataFromSocket(socket).body;
}

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket)
{
    int remaining = data.size();
    const char * pData = data.constData();
    while(socket.isOpen() && remaining>0)
    {
        // If the output buffer has become large, then wait until it has been sent.
        if (socket.bytesToWrite() > 16384)
        {
            socket.waitForBytesWritten(-1);
        }

        qint64 written = socket.write(pData, remaining);
        if (written < 0) {
            return false;
        }

        pData += written;
        remaining -= written;
    }
    return true;
}

} // namespace qevercloud

/** @endcond */
