/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "InkNoteImageDownloaderTester.h"
#include "../src/HttpRequestParser.h"
#include "../src/HttpUtils.h"

#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/IInkNoteImageDownloader.h>
#include <qevercloud/IRequestContext.h>
#include <qevercloud/RequestContextBuilder.h>

#include <QEventLoop>
#include <QFile>
#include <QFutureWatcher>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtTest/QtTest>

namespace qevercloud {

namespace {

[[nodiscard]] QByteArray readStripesFile(
    const QString & fileName)
{
    QFile stripesFile{fileName};

    bool res = stripesFile.open(QIODevice::ReadOnly);
    Q_ASSERT(res);

    auto stripesData = stripesFile.readAll();
    stripesFile.close();

    return stripesData;
}

[[nodiscard]] QByteArray readStripeFile(const int sliceIndex)
{
    return readStripesFile(QString::fromUtf8(":/stripe%1.png").arg(sliceIndex));
}

} // namespace

InkNoteImageDownloaderTester::InkNoteImageDownloaderTester(QObject * parent) :
    QObject(parent)
{}

void InkNoteImageDownloaderTester::initTestCase()
{
    m_stripesImageData = readStripesFile(QStringLiteral(":/stripes.png"));

    m_stripesImage = {};
    bool res = m_stripesImage.loadFromData(m_stripesImageData, "PNG");
    Q_ASSERT(res);

    m_shardId = QStringLiteral("shard1");
    m_guid = QStringLiteral("guid1");
    m_authToken = QStringLiteral("authToken");
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeSynchronously()
{
    QTcpServer tcpServer;
    QList<QByteArray> requestBodies;

    const quint16 port = setupServer(
        tcpServer, requestBodies,
        [this]([[maybe_unused]] int sliceIndex) { return m_stripesImageData; });

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newInkNoteImageDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId);

    // First, check non-public ink note
    auto downloadedData = downloader->download(m_guid, m_stripesImage.size(), ctx);

    QImage downloadedDataImage;
    bool res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 1);
    QVERIFY(
        requestBodies[0] == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());

    // Second, check public ink note
    requestBodies.clear();
    ctx = newRequestContext();
    downloadedData = downloader->download(m_guid, m_stripesImage.size(), ctx);
    downloadedDataImage = {};
    res = downloadedDataImage.loadFromData(downloadedData, "PNG");
    Q_ASSERT(res);

    QVERIFY(downloadedDataImage == m_stripesImage);

    Q_ASSERT(requestBodies.size() == 1);
    QVERIFY(requestBodies[0].isEmpty());
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeAsynchronously()
{
    QTcpServer tcpServer;
    QList<QByteArray> requestBodies;
    const auto port = setupServer(
        tcpServer, requestBodies,
        [this]([[maybe_unused]] int sliceIndex) { return m_stripesImageData; });

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newInkNoteImageDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId);

    // First, check non-public ink note
    auto downloadedDataFuture = downloader->downloadAsync(
        m_guid, m_stripesImage.size(), ctx);
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
    requestBodies.clear();
    ctx = newRequestContext();
    downloadedDataFuture = downloader->downloadAsync(
        m_guid, m_stripesImage.size(), ctx);
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

    Q_ASSERT(requestBodies.size() == 1);
    QVERIFY(requestBodies[0].isEmpty());
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSeveralStripesSynchronously()
{
    QTcpServer tcpServer;
    QList<QByteArray> requestBodies;
    const auto port = setupServer(
        tcpServer, requestBodies,
        [&, this](int sliceIndex) { return readStripeFile(sliceIndex); });

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newInkNoteImageDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port), m_shardId);

    // First, check non-public ink note
    auto downloadedData = downloader->download(
        m_guid, m_stripesImage.size(), ctx);

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
    requestBodies.clear();
    ctx = newRequestContext();
    downloadedData = downloader->download(m_guid, m_stripesImage.size(), ctx);
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
    QList<QByteArray> requestBodies;
    const auto port = setupServer(
        tcpServer, requestBodies,
        [&, this](int sliceIndex) { return readStripeFile(sliceIndex); });

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newInkNoteImageDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port), m_shardId);

    // First, check non-public ink note
    auto downloadedDataFuture = downloader->downloadAsync(
        m_guid, m_stripesImage.size(), ctx);
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
    requestBodies.clear();
    ctx = newRequestContext();
    downloadedDataFuture = downloader->downloadAsync(
        m_guid, m_stripesImage.size(), ctx);
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

quint16 InkNoteImageDownloaderTester::setupServer(
    QTcpServer & tcpServer,
    QList<QByteArray> & requestBodies,
    ResponseDataProvider responseDataProvider)
{
    Q_ASSERT(responseDataProvider);

    bool res = tcpServer.listen(QHostAddress::LocalHost);
    Q_ASSERT(res);
    quint16 port = tcpServer.serverPort();

    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, responseDataProvider = std::move(responseDataProvider), this] {
            auto pSocket = tcpServer.nextPendingConnection();
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

            auto responseData = responseDataProvider(stripeIndex);

            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: image/png\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    return port;
}

} // namespace qevercloud
