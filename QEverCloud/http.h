#ifndef QEVERCLOUD_HTTPL_H
#define QEVERCLOUD_HTTPL_H

#include <QString>
#include <QByteArray>
#include <QtEndian>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

QNetworkAccessManager* networkAccessManager();

// the class greatly simplifies QNetworkReply handling
class ReplyFetcher: public QObject {
    Q_OBJECT
public:
    ReplyFetcher();
    void start(QNetworkAccessManager* nam, QUrl url);
    // if !postData.isNull() then POST will be issued instead of GET
    void start(QNetworkAccessManager* nam, QNetworkRequest request, QByteArray postData = QByteArray());
    bool isError() {return !success_;}
    QString errorText() {return errorText_;}
    QByteArray receivedData() {return receivedData_;}
    int httpStatusCode() {return httpStatusCode_;}

signals:
    void replyFetched(QObject*); // sends itself

private slots:
    void onFinished();
    void onError();
    void onSslErrors(QList<QSslError> l);
    void onDownloadProgress(qint64, qint64);
    void checkForTimeout();

private:
    QSharedPointer<QNetworkReply> reply;
    bool success_;
    QString errorText_;
    QByteArray receivedData_;
    int httpStatusCode_;
    void setError(QString errorText);
    QTimer* ticker_;
    qint64 lastNetworkTime_;
};

QByteArray askEvernote(QString url, QByteArray postData);


}

/** @endcond */

#endif // QEVERCLOUD_HTTPL_H
