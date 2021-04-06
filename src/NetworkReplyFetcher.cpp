/**
 * Copyright (c) 2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "NetworkReplyFetcher.h"

#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/utility/Log.h>

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
    QNetworkAccessManager * pNam, QUuid requestId, QNetworkRequest request,
    qint64 timeoutMsec, QByteArray postData,
    ReadReplyFunction readReplyFunction, QObject * parent) :
    QObject(parent),
    m_pNam{pNam},
    m_requestId{std::move(requestId)},
    m_request{std::move(request)},
    m_timeoutMsec{timeoutMsec},
    m_postData{std::move(postData)},
    m_readReplyFunction{std::move(readReplyFunction)},
    m_pTicker{new QTimer(this)}
{
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
        << m_requestId);

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
        &ReplyFetcher::onError);
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

    QObject::connect(
        &m_futureWatcher,
        &QFutureWatcher<QByteArray>::canceled,
        this,
        &NetworkReplyFetcher::onFutureCanceled);

    m_promise.start();
    return future;
}

void NetworkReplyFetcher::onDownloadProgress(qint64 downloaded, qint64 total)
{
    QEC_TRACE(
        "http",
        "NetworkReplyFetcher::onDownloadProgress: downloaded = "
            << downloaded << ", total = " << total << ", request id = "
            << m_requestId);

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
    if (m_timeoutMsec < 0) {
        return;
    }

    if ((QDateTime::currentMSecsSinceEpoch() - m_lastNetworkTime) > m_timeoutMsec) {
        setError(QNetworkReply::TimeoutError, QStringLiteral("Request timeout"));
    }
}

void NetworkReplyFetcher::onFinished()
{
    QEC_TRACE(
        "http",
        "NetworkReplyFetcher finished: request id = " << m_requestId)

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
        << ", request id = " << m_requestId);

    setError(error, m_pReply->errorString());
}

void NetworkReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append(QStringLiteral("\n"));
    }

    QEC_WARNING("http", errorText << ", request id = " << m_requestId);
    setError(QNetworkReply::SslHandshakeFailedError, errorText);
}

void NetworkReplyFetcher::onFutureCanceled()
{
    QEC_DEBUG(
        "http",
        "NetworkReplyFetcher: future canceled. request id = " << m_requestId);

    QObject::disconnect(m_pReply.get());
    m_pReply->abort();
    deleteLater();
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
    EverCloudExceptionDataPtr error;
    QVariant result;

    try
    {
        if (m_errorType != QNetworkReply::NoError)
        {
            error = std::make_shared<EverCloudExceptionData>(m_errorText);
        }
        else if (m_httpStatusCode != 200)
        {
            error = std::make_shared<EverCloudExceptionData>(
                QString::fromUtf8("HTTP Status Code = %1")
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
    catch(const EverCloudException & e)
    {
        error = e.exceptionData();
    }
    catch(const std::exception & e)
    {
        error = std::make_shared<EverCloudExceptionData>(
            QString::fromUtf8("Exception of type \"%1\" with the message: %2")
            .arg(QString::fromUtf8(typeid(e).name()), QString::fromUtf8(e.what())));
    }
    catch(...)
    {
        error = std::make_shared<EverCloudExceptionData>(
            QStringLiteral("Unknown exception"));
    }

    if (error)
    {
        try
        {
            error->throwException();
        }
        catch (const EverCloudException & e)
        {
            m_promise.setException(std::current_exception());
        }

        Q_ASSERT_X(false, "QEverCloud:HTTP", "Unreachable code");
    }
    else
    {
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
