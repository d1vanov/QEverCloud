/**
 * Copyright (c) 2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_NETWORK_REPLY_FETCHER_H
#define QEVERCLOUD_NETWORK_REPLY_FETCHER_H

#include <QtGlobal>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include "Qt5Promise.h"
#endif

#include <QFuture>
#include <QFutureWatcher>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QObject>
#include <QPointer>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPromise>
#endif

#include <QSslError>
#include <QTimer>
#include <QVariant>
#include <QUuid>

#include <functional>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

class Q_DECL_HIDDEN NetworkReplyFetcher final: public QObject
{
    Q_OBJECT
public:
    using ReadReplyFunction = std::function<QVariant(QByteArray)>;

    explicit NetworkReplyFetcher(
        QNetworkAccessManager * pNam,
        QUuid requestId,
        QNetworkRequest request,
        qint64 timeoutMsec,
        QByteArray postData = {}, // if non-empty, POST will be issued instead of GET
        ReadReplyFunction readReplyFunction = nullptr,
        QObject * parent = nullptr);

    QFuture<QVariant> start();

private Q_SLOTS:
    void onDownloadProgress(qint64 downloaded, qint64 total);
    void checkForTimeout();
    void onFinished();
    void onError(QNetworkReply::NetworkError);
    void onSslErrors(QList<QSslError> errors);
    void onFutureCanceled();

private:
    void setError(QNetworkReply::NetworkError errorType, QString errorText);
    void finalize();

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
    const QPointer<QNetworkAccessManager>   m_pNam;
    const QUuid                 m_requestId;
    const QNetworkRequest       m_request;
    const qint64                m_timeoutMsec;
    const QByteArray            m_postData;
    const ReadReplyFunction     m_readReplyFunction;

    QNetworkReplyPtr    m_pReply;

    QNetworkReply::NetworkError m_errorType = QNetworkReply::NoError;
    QString     m_errorText;
    QByteArray  m_receivedData;
    int         m_httpStatusCode = 0;

    QPromise<QVariant> m_promise;
    QFutureWatcher<QVariant> m_futureWatcher;
    bool m_promiseProgressRangeSet = false;

    QTimer *    m_pTicker = nullptr;
    qint64      m_lastNetworkTime = 0;
};

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_NETWORK_REPLY_FETCHER_H
