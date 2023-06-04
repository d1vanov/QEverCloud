/**
 * Copyright (c) 2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "NetworkReplyFetcher.h"

#include <qevercloud/exceptions/NetworkException.h>
#include <qevercloud/utility/Log.h>

#include <QtGlobal>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] int safeCastToInt(qint64 value) noexcept
{
    return static_cast<int>(
        std::min(
            value,
            static_cast<qint64>(std::numeric_limits<int>::max())));
}

} // namespace

NetworkReplyFetcher::NetworkReplyFetcher(
    IRequestContextPtr ctx, QNetworkRequest request, QByteArray postData,
    ReadReplyFunction readReplyFunction, QObject * parent) :
    QObject(parent),
    m_ctx{std::move(ctx)},
    m_request{std::move(request)},
    m_postData{std::move(postData)},
    m_readReplyFunction{std::move(readReplyFunction)},
    m_pNam{new QNetworkAccessManager(this)},
    m_pTicker{new QTimer(this)}
{
    Q_ASSERT_X(m_ctx, "NetworkReplyFetcher", "Null request context passed to NetworkReplyFetcher");

    QObject::connect(
        m_pTicker,
        &QTimer::timeout,
        this,
        &NetworkReplyFetcher::checkForTimeout,
        Qt::UniqueConnection);
}

QFuture<QVariant> NetworkReplyFetcher::start()
{
    QEC_TRACE("http", "NetworkReplyFetcher started for URL " << m_request.url()
        << ", post data size: " << m_postData.size() << ", request id = "
        << m_ctx->requestId());

    m_httpStatusCode = 0;
    m_errorType = QNetworkReply::NoError;
    m_errorText.clear();
    m_receivedData.clear();

    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
    m_pTicker->start(1000);

    if (m_postData.isNull()) {
        m_pReply = QNetworkReplyPtr{m_pNam->get(m_request)};
    }
    else {
        m_pReply = QNetworkReplyPtr{m_pNam->post(m_request, m_postData)};
    }

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::finished,
        this,
        &NetworkReplyFetcher::onFinished);

#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::errorOccurred,
        this,
        &NetworkReplyFetcher::onError);
#else
    QObject::connect(
        m_pReply.get(),
        qOverload<QNetworkReply::NetworkError>(&QNetworkReply::error),
        this,
        &NetworkReplyFetcher::onError);
#endif

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::sslErrors,
        this,
        &NetworkReplyFetcher::onSslErrors);

    QObject::connect(
        m_pReply.get(),
        &QNetworkReply::downloadProgress,
        this,
        &NetworkReplyFetcher::onDownloadProgress);

    auto future = m_promise.future();
    m_futureWatcher.setFuture(future);

    m_promise.start();
    return future;
}

void NetworkReplyFetcher::onDownloadProgress(qint64 downloaded, qint64 total)
{
    QEC_TRACE(
        "http",
        "NetworkReplyFetcher::onDownloadProgress: downloaded = "
            << downloaded << ", total = " << total << ", request id = "
            << m_ctx->requestId());

    if (!m_promiseProgressRangeSet)
    {
        m_promise.setProgressRange(0, safeCastToInt(total));
        m_promiseProgressRangeSet = true;
    }

    m_promise.setProgressValue(safeCastToInt(downloaded));
    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
}

void NetworkReplyFetcher::checkForTimeout()
{
    const auto timeout = m_ctx->connectionTimeout();
    if (timeout < 0) {
        return;
    }

    if ((QDateTime::currentMSecsSinceEpoch() - m_lastNetworkTime) > timeout) {
        setError(QNetworkReply::TimeoutError, QStringLiteral("Request timeout"));
    }
}

void NetworkReplyFetcher::onFinished()
{
    QEC_TRACE(
        "http",
        "NetworkReplyFetcher finished: request id = " << m_ctx->requestId())

    m_pTicker->stop();

    if (m_errorType != QNetworkReply::NoError) {
        return;
    }

    m_receivedData = m_pReply->readAll();
    m_httpStatusCode = m_pReply->attribute(
        QNetworkRequest::HttpStatusCodeAttribute).toInt();

    QObject::disconnect(m_pReply.get());
    finalize();
}

void NetworkReplyFetcher::onError(QNetworkReply::NetworkError error)
{
    QEC_WARNING("http", "NetworkReplyFetcher error: code = "
        << error << ", description: " << m_pReply->errorString()
        << "; http status code: " << m_pReply->attribute(
            QNetworkRequest::HttpStatusCodeAttribute).toInt()
        << ", request id = " << m_ctx->requestId());

    setError(error, m_pReply->errorString());
}

void NetworkReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append(QStringLiteral("\n"));
    }

    QEC_WARNING("http", errorText << ", request id = " << m_ctx->requestId());
    setError(QNetworkReply::SslHandshakeFailedError, errorText);
}

void NetworkReplyFetcher::setError(
    QNetworkReply::NetworkError errorType, QString errorText)
{
    m_pTicker->stop();
    m_errorType = errorType;
    m_errorText = errorText;
    QObject::disconnect(m_pReply.get());
    finalize();
}

void NetworkReplyFetcher::finalize()
{
    QVariant result;
    bool caughtException = false;

    try
    {
        if (m_errorType != QNetworkReply::NoError)
        {
            throw NetworkException(m_errorType, m_errorText);
        }
        else if (m_httpStatusCode != 200)
        {
            throw EverCloudException(QString::fromUtf8("HTTP Status Code = %1")
                .arg(m_httpStatusCode));
        }
        else
        {
            if (m_readReplyFunction) {
                result = m_readReplyFunction(m_receivedData);
            }
            else {
                result = QVariant::fromValue(m_receivedData);
            }
        }
    }
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    catch(...)
    {
        m_promise.setException(std::current_exception());
        caughtException = true;
    }
#else
    catch(const QException & e)
    {
        m_promise.setException(e);
        caughtException = true;
    }
#endif

    if (!caughtException) {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        m_promise.addResult(std::move(result));
#else
        m_promise.addResult(result);
#endif
    }

    m_promise.finish();
    deleteLater();
}

} // namespace qevercloud
