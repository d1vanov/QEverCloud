/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_H
#define QEVERCLOUD_HTTP_H

#include <Helpers.h>

#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslError>
#include <QString>
#include <QtEndian>
#include <QTimer>
#include <QTypeInfo>

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
    ReplyFetcher(QObject * parent = Q_NULLPTR);

    void start(QNetworkAccessManager * nam, QUrl url, qint64 timeoutMsec);

    // if !postData.isNull() then POST will be issued instead of GET
    void start(QNetworkAccessManager * nam, QNetworkRequest request,
               qint64 timeoutMsec, QByteArray postData = QByteArray());

    bool isError() const { return m_errorType != QNetworkReply::NoError; }

    QNetworkReply::NetworkError errorType() const { return m_errorType; }

    QString errorText() const { return m_errorText; }

    QByteArray receivedData() const { return m_receivedData; }

    int httpStatusCode() const { return m_httpStatusCode; }

Q_SIGNALS:
    void replyFetched(QObject * self); // sends itself

private Q_SLOTS:
    void onFinished();
    void onError(QNetworkReply::NetworkError);
    void onSslErrors(QList<QSslError> list);
    void onDownloadProgress(qint64 downloaded, qint64 total);
    void checkForTimeout();

private:
    void setError(QNetworkReply::NetworkError errorType, QString errorText);

private:
    std::shared_ptr<QNetworkReply>  m_reply;

    QNetworkReply::NetworkError m_errorType = QNetworkReply::NoError;
    QString     m_errorText;
    QByteArray  m_receivedData;
    int         m_httpStatusCode = 0;

    QTimer *    m_ticker;
    qint64      m_lastNetworkTime = 0;
    qint64      m_timeoutMsec = 0;
};

////////////////////////////////////////////////////////////////////////////////

QNetworkAccessManager * evernoteNetworkAccessManager();

QNetworkRequest createEvernoteRequest(QString url);

QByteArray askEvernote(QString url, QByteArray postData, const qint64 timeoutMsec);

QByteArray simpleDownload(QNetworkAccessManager * nam, QNetworkRequest request,
                          const qint64 timeoutMsec,
                          QByteArray postData = QByteArray(),
                          int * httpStatusCode = Q_NULLPTR);

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The ReplyFetcherLauncher class simplifies ReplyFetcher starting
 */
class ReplyFetcherLauncher: public QObject
{
    Q_OBJECT
public:
    explicit ReplyFetcherLauncher(
        ReplyFetcher * fetcher, QNetworkAccessManager * nam,
        const QNetworkRequest & request, const qint64 timeoutMsec,
        const QByteArray & postData);

public Q_SLOTS:
    void start();

private:
    ReplyFetcher *          m_fetcher;
    QNetworkAccessManager * m_nam;
    QNetworkRequest         m_request;
    qint64                  m_timeoutMsec;
    QByteArray              m_postData;
};

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_HTTP_H
