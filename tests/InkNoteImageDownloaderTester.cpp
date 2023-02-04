/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "InkNoteImageDownloaderTester.h"
#include "SocketHelpers.h"

#include <qevercloud/InkNoteImageDownloader.h>

#include <QEventLoop>
#include <QFile>
#include <QFutureWatcher>
#include <QImage>
#include <QTcpServer>
#include <QtTest/QtTest>

#include <utility>

namespace qevercloud {

namespace {

[[nodiscard]] std::pair<QByteArray, QImage> readStripesFile(
    const QString & fileName)
{
    QFile stripesFile{fileName};

    bool res = stripesFile.open(QIODevice::ReadOnly);
    Q_ASSERT(res);

    auto stripesData = stripesFile.readAll();
    stripesFile.close();

    QImage image;
    res = image.loadFromData(stripesData, "PNG");
    Q_ASSERT(res);

    return std::make_pair(std::move(stripesData), std::move(image));
}

} // namespace

InkNoteImageDownloaderTester::InkNoteImageDownloaderTester(QObject * parent) :
    QObject(parent)
{}

void InkNoteImageDownloaderTester::initTestCase()
{
    auto pair = readStripesFile(QStringLiteral(":/stripes.png"));
    m_stripesImageData = std::move(pair.first);
    m_stripesImage = std::move(pair.second);

    m_shardId = QStringLiteral("shard1");
    m_guid = QStringLiteral("guid1");
    m_authToken = QStringLiteral("authToken");
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeSynchronously()
{
    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QList<QByteArray> requestBodies;

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, this] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            HttpRequestData requestData = readRequestDataFromSocket(*pSocket);
            QVERIFY(
                requestData.uri ==
                QString::fromUtf8("/shard/%1/res/%2.ink?slice=1")
                    .arg(m_shardId, m_guid).toUtf8());

            QVERIFY(requestData.method == HttpRequestData::Method::POST);
            requestBodies << requestData.body;

            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(m_stripesImageData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: image/png\r\n\r\n");
            buffer.append(m_stripesImageData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    InkNoteImageDownloader downloader{
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId, m_authToken, m_stripesImage.width(), m_stripesImage.height()};

    // First, check non-public ink note
    bool isPublic = false;
    auto downloadedData = downloader.download(m_guid, isPublic);

    QImage downloadedDataImage;
    bool res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 1);
    QVERIFY(
        requestBodies[0] == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());

    // Second, check public ink note
    isPublic = true;
    downloadedData = downloader.download(m_guid, isPublic);
    downloadedDataImage = {};
    res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 2);
    QVERIFY(requestBodies[1].isEmpty());
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeAsynchronously()
{
    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QList<QByteArray> requestBodies;

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, this] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            HttpRequestData requestData = readRequestDataFromSocket(*pSocket);
            QVERIFY(
                requestData.uri ==
                QString::fromUtf8("/shard/%1/res/%2.ink?slice=1")
                    .arg(m_shardId, m_guid).toUtf8());

            QVERIFY(requestData.method == HttpRequestData::Method::POST);
            requestBodies << requestData.body;

            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(m_stripesImageData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: image/png\r\n\r\n");
            buffer.append(m_stripesImageData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    InkNoteImageDownloader downloader{
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId, m_authToken, m_stripesImage.width(), m_stripesImage.height()};

    // First, check non-public ink note
    bool isPublic = false;
    auto downloadedDataFuture = downloader.downloadAsync(m_guid, isPublic);
    {
        QFutureWatcher<QByteArray> watcher;
        QEventLoop loop;
        QObject::connect(
            &watcher, &QFutureWatcher<SyncState>::finished, &loop,
            &QEventLoop::quit);

        watcher.setFuture(downloadedDataFuture);
        if (!downloadedDataFuture.isFinished()) {
            loop.exec();
        }
    }

    Q_ASSERT(downloadedDataFuture.isFinished());
    Q_ASSERT(downloadedDataFuture.resultCount() == 1);

    auto downloadedData = downloadedDataFuture.result();

    QImage downloadedDataImage;
    bool res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 1);
    QVERIFY(
        requestBodies[0] == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());

    // Second, check public ink note
    isPublic = true;
    downloadedDataFuture = downloader.downloadAsync(m_guid, isPublic);
    {
        QFutureWatcher<QByteArray> watcher;
        QEventLoop loop;
        QObject::connect(
            &watcher, &QFutureWatcher<SyncState>::finished, &loop,
            &QEventLoop::quit);

        watcher.setFuture(downloadedDataFuture);
        if (!downloadedDataFuture.isFinished()) {
            loop.exec();
        }
    }

    Q_ASSERT(downloadedDataFuture.isFinished());
    Q_ASSERT(downloadedDataFuture.resultCount() == 1);

    downloadedData = downloadedDataFuture.result();

    downloadedDataImage = {};
    res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 2);
    QVERIFY(requestBodies[1].isEmpty());
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSeveralStripesSynchronously()
{
    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QList<QByteArray> requestBodies;

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, this] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            HttpRequestData requestData = readRequestDataFromSocket(*pSocket);
            QVERIFY(requestData.method == HttpRequestData::Method::POST);
            requestBodies << requestData.body;

            int stripeIndex = requestBodies.size();

            QVERIFY(
                requestData.uri ==
                QString::fromUtf8("/shard/%1/res/%2.ink?slice=%3")
                    .arg(m_shardId, m_guid, QString::number(stripeIndex).toUtf8()));

            auto pair = readStripesFile(
                QString::fromUtf8(":/stripe%1.png").arg(stripeIndex));

            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(pair.first.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: image/png\r\n\r\n");
            buffer.append(pair.first);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    InkNoteImageDownloader downloader{
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId, m_authToken, m_stripesImage.width(), m_stripesImage.height()};

    // First, check non-public ink note
    bool isPublic = false;
    auto downloadedData = downloader.download(m_guid, isPublic);

    QImage downloadedDataImage;
    bool res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 3);
    for (const auto & requestBody: qAsConst(requestBodies)) {
        QVERIFY(
            requestBody == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());
    }

    // Second, check public ink note
    isPublic = true;
    requestBodies.clear();
    downloadedData = downloader.download(m_guid, isPublic);
    downloadedDataImage = {};
    res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 3);
    for (const auto & requestBody: qAsConst(requestBodies)) {
        QVERIFY(requestBody.isEmpty());
    }
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSeveralStripesAsynchronously()
{
    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QList<QByteArray> requestBodies;

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, this] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            HttpRequestData requestData = readRequestDataFromSocket(*pSocket);
            QVERIFY(requestData.method == HttpRequestData::Method::POST);
            requestBodies << requestData.body;

            int stripeIndex = requestBodies.size();

            QVERIFY(
                requestData.uri ==
                QString::fromUtf8(
                    "/shard/%1/res/%2.ink?slice=%3")
                .arg(m_shardId, m_guid, QString::number(stripeIndex).toUtf8()));

            auto pair = readStripesFile(
                QString::fromUtf8(":/stripe%1.png").arg(stripeIndex));

            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(pair.first.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: image/png\r\n\r\n");
            buffer.append(pair.first);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    InkNoteImageDownloader downloader{
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId, m_authToken, m_stripesImage.width(), m_stripesImage.height()};

    // First, check non-public ink note
    bool isPublic = false;
    auto downloadedDataFuture = downloader.downloadAsync(m_guid, isPublic);
    {
        QFutureWatcher<QByteArray> watcher;
        QEventLoop loop;
        QObject::connect(
            &watcher, &QFutureWatcher<SyncState>::finished, &loop,
            &QEventLoop::quit);

        watcher.setFuture(downloadedDataFuture);
        if (!downloadedDataFuture.isFinished()) {
            loop.exec();
        }
    }

    Q_ASSERT(downloadedDataFuture.isFinished());
    Q_ASSERT(downloadedDataFuture.resultCount() == 1);

    auto downloadedData = downloadedDataFuture.result();

    QImage downloadedDataImage;
    bool res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 3);
    for (const auto & requestBody: qAsConst(requestBodies)) {
        QVERIFY(
            requestBody == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());
    }

    // Second, check public ink note
    isPublic = true;
    requestBodies.clear();
    downloadedDataFuture = downloader.downloadAsync(m_guid, isPublic);
    {
        QFutureWatcher<QByteArray> watcher;
        QEventLoop loop;
        QObject::connect(
            &watcher, &QFutureWatcher<SyncState>::finished, &loop,
            &QEventLoop::quit);

        watcher.setFuture(downloadedDataFuture);
        if (!downloadedDataFuture.isFinished()) {
            loop.exec();
        }
    }

    Q_ASSERT(downloadedDataFuture.isFinished());
    Q_ASSERT(downloadedDataFuture.resultCount() == 1);

    downloadedData = downloadedDataFuture.result();

    downloadedDataImage = {};
    res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 3);
    for (const auto & requestBody: qAsConst(requestBodies)) {
        QVERIFY(requestBody.isEmpty());
    }
}

} // namespace qevercloud
