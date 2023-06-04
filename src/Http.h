/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_H
#define QEVERCLOUD_HTTP_H

#include <qevercloud/RequestContext.h>

#include <QByteArray>
#include <QFuture>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QSslError>
#include <QString>
#include <QtEndian>
#include <QTimer>
#include <QTypeInfo>

#include <functional>
#include <memory>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The ReplyFetcher class simplifies handling of QNetworkReply
 */
class ReplyFetcher: public QObject
{
    Q_OBJECT
public:
    ReplyFetcher(QObject * parent = nullptr);

    void start(QNetworkAccessManager * nam, QUrl url, qint64 timeoutMsec);

    // if !postData.isNull() then POST will be issued instead of GET
    void start(
        QNetworkAccessManager * nam, QNetworkRequest request,
        qint64 timeoutMsec, QByteArray postData = {});

    [[nodiscard]] bool isError() const noexcept
    {
        return m_errorType != QNetworkReply::NoError;
    }

    [[nodiscard]] QNetworkReply::NetworkError errorType() const noexcept
    {
        return m_errorType;
    }

    [[nodiscard]] QString errorText() const
    {
        return m_errorText;
    }

    [[nodiscard]] QByteArray receivedData() const
    {
        return m_receivedData;
    }

    [[nodiscard]] int httpStatusCode() const noexcept
    {
        return m_httpStatusCode;
    }

    [[nodiscard]] QNetworkAccessManager * networkAccessManager() noexcept
    {
        if (!m_pNam.isNull()) {
            return m_pNam.data();
        }

        return nullptr;
    }

Q_SIGNALS:
    void replyFetched(ReplyFetcher * pSelf); // sends itself

private Q_SLOTS:
    void onFinished();
    void onError(QNetworkReply::NetworkError);
    void onSslErrors(QList<QSslError> list);
    void onDownloadProgress(qint64 downloaded, qint64 total);
    void checkForTimeout();

private:
    void setError(QNetworkReply::NetworkError errorType, QString errorText);

private:
    struct QNetworkReplyDeleter
    {
        void operator()(QNetworkReply * pReply)
        {
            pReply->deleteLater();
        }
    };

    using QNetworkReplyPtr = std::unique_ptr<QNetworkReply, QNetworkReplyDeleter>;

private:
    QPointer<QNetworkAccessManager>     m_pNam;
    QNetworkReplyPtr    m_pReply;

    QNetworkReply::NetworkError m_errorType = QNetworkReply::NoError;
    QString     m_errorText;
    QByteArray  m_receivedData;
    int         m_httpStatusCode = 0;

    QTimer *    m_pTicker = nullptr;
    qint64      m_lastNetworkTime = 0;
    qint64      m_timeoutMsec = 0;
};

////////////////////////////////////////////////////////////////////////////////

[[nodiscard]] QNetworkRequest createEvernoteRequest(
    QString url, QList<QNetworkCookie> cookies);

[[nodiscard]] QByteArray askEvernote(
    QString url, QByteArray postData, const qint64 timeoutMsec,
    QList<QNetworkCookie> cookies = {});

[[nodiscard]] QByteArray simpleDownload(
    QNetworkRequest request, const qint64 timeoutMsec,
    QByteArray postData = {}, int * pHttpStatusCode = nullptr);

////////////////////////////////////////////////////////////////////////////////

[[nodiscard]] QFuture<QVariant> sendRequest(
    QString url, QByteArray postData, IRequestContextPtr ctx,
    std::function<QVariant(QByteArray)> readReplyFunction = nullptr);

[[nodiscard]] QFuture<QVariant> sendRequest(
    QNetworkRequest request, QByteArray postData, IRequestContextPtr ctx,
    std::function<QVariant(QByteArray)> readReplyFunction = nullptr);

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_HTTP_H
