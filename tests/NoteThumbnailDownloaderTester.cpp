/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "NoteThumbnailDownloaderTester.h"
#include "SocketHelpers.h"

#include <qevercloud/INoteThumbnailDownloader.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/RequestContextBuilder.h>

#include <QEventLoop>
#include <QFile>
#include <QFutureWatcher>
#include <QTcpServer>
#include <QtTest/QtTest>

namespace qevercloud {

namespace {

[[nodiscard]] QByteArray readThumbnailData(
    const QString & fileName)
{
    QFile file{fileName};

    bool res = file.open(QIODevice::ReadOnly);
    Q_ASSERT(res);

    auto fileData = file.readAll();
    file.close();

    return fileData;
}

[[nodiscard]] INoteThumbnailDownloader::ImageType toImageType(
    const QString & extension)
{
    if (extension == QStringLiteral("png")) {
        return INoteThumbnailDownloader::ImageType::PNG;
    }

    if (extension == QStringLiteral("jpg")) {
        return INoteThumbnailDownloader::ImageType::JPEG;
    }

    if (extension == QStringLiteral("gif")) {
        return INoteThumbnailDownloader::ImageType::GIF;
    }

    if (extension == QStringLiteral("bmp")) {
        return INoteThumbnailDownloader::ImageType::BMP;
    }

    throw EverCloudException{
        QStringLiteral("Unknown note thumbnail extension")};
}

} // namespace

NoteThumbnailDownloaderTester::NoteThumbnailDownloaderTester(QObject * parent) :
    QObject(parent)
{}

void NoteThumbnailDownloaderTester::initTestCase()
{
    m_thumbnailData = readThumbnailData(QStringLiteral(":/stripes.png"));
    m_shardId = QStringLiteral("shard1");
    m_guid = QStringLiteral("guid1");
    m_authToken = QStringLiteral("authToken");
}

void NoteThumbnailDownloaderTester::downloadNotePngThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("note"), QStringLiteral("png"));
}

void NoteThumbnailDownloaderTester::downloadNoteJpegThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("note"), QStringLiteral("jpg"));
}

void NoteThumbnailDownloaderTester::downloadNoteGifThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("note"), QStringLiteral("gif"));
}

void NoteThumbnailDownloaderTester::downloadNoteBmpThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("note"), QStringLiteral("bmp"));
}

void NoteThumbnailDownloaderTester::downloadNotePngThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("note"), QStringLiteral("png"));
}

void NoteThumbnailDownloaderTester::downloadNoteJpegThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("note"), QStringLiteral("jpg"));
}

void NoteThumbnailDownloaderTester::downloadNoteGifThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("note"), QStringLiteral("gif"));
}

void NoteThumbnailDownloaderTester::downloadNoteBmpThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("note"), QStringLiteral("bmp"));
}

void NoteThumbnailDownloaderTester::downloadResourcePngThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("res"), QStringLiteral("png"));
}

void NoteThumbnailDownloaderTester::downloadResourceJpegThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("res"), QStringLiteral("jpg"));
}

void NoteThumbnailDownloaderTester::downloadResourceGifThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("res"), QStringLiteral("gif"));
}

void NoteThumbnailDownloaderTester::downloadResourceBmpThumbnailSynchronously()
{
    runDownloadSynchronouslyTest(QStringLiteral("res"), QStringLiteral("bmp"));
}

void NoteThumbnailDownloaderTester::downloadResourcePngThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("res"), QStringLiteral("png"));
}

void NoteThumbnailDownloaderTester::downloadResourceJpegThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("res"), QStringLiteral("jpg"));
}

void NoteThumbnailDownloaderTester::downloadResourceGifThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("res"), QStringLiteral("gif"));
}

void NoteThumbnailDownloaderTester::downloadResourceBmpThumbnailAsynchronously()
{
    runDownloadAsynchronouslyTest(QStringLiteral("res"), QStringLiteral("bmp"));
}

quint16 NoteThumbnailDownloaderTester::setupServer(
    QTcpServer & tcpServer, QByteArray & requestBody, QString urlPart,
    QString extension)
{
    bool res = tcpServer.listen(QHostAddress::LocalHost);
    Q_ASSERT(res);
    quint16 port = tcpServer.serverPort();

    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&, urlPart = std::move(urlPart), extension = std::move(extension),
         this]
        {
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
            requestBody = requestData.body;

            QVERIFY(
                requestData.uri ==
                QString::fromUtf8(
                    "/shard/%1/thm/%2/%3.%4")
                .arg(m_shardId, urlPart, m_guid, extension));

            auto responseData =
                readThumbnailData(QStringLiteral(":/stripes.png"));

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

void NoteThumbnailDownloaderTester::runDownloadSynchronouslyTest(
    QString urlPart, QString extension)
{
    QTcpServer tcpServer;
    QByteArray requestBody;
    const quint16 port = setupServer(
        tcpServer, requestBody, urlPart, extension);

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newNoteThumbnailDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId);

    const int size = 300;
    const auto imageType = toImageType(extension);

    // First, check non-public note/resource thumbnail
    QByteArray downloadedData;
    if (urlPart == QStringLiteral("note")) {
        downloadedData = downloader->downloadNoteThumbnail(
            m_guid, size, imageType, ctx);
    }
    else {
        downloadedData = downloader->downloadResourceThumbnail(
            m_guid, size, imageType, ctx);
    }

    QVERIFY(downloadedData == m_thumbnailData);

    QVERIFY(
        requestBody == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());

    // Second, check public note thumbnail
    requestBody.clear();
    ctx = newRequestContext();
    if (urlPart == QStringLiteral("note")) {
        downloadedData = downloader->downloadNoteThumbnail(
            m_guid, size, imageType, ctx);
    }
    else {
        downloadedData = downloader->downloadResourceThumbnail(
            m_guid, size, imageType, ctx);
    }

    QVERIFY(downloadedData == m_thumbnailData);
    QVERIFY(requestBody.isEmpty());
}

void NoteThumbnailDownloaderTester::runDownloadAsynchronouslyTest(
    QString urlPart, QString extension)
{
    QTcpServer tcpServer;
    QByteArray requestBody;
    const quint16 port = setupServer(
        tcpServer, requestBody, urlPart, extension);

    auto ctx = RequestContextBuilder{}
        .setAuthenticationToken(m_authToken)
        .build();

    auto downloader = newNoteThumbnailDownloader(
        QString::fromUtf8("http://127.0.0.1:%1").arg(port),
        m_shardId);

    const int size = 300;
    const auto imageType = toImageType(extension);

    // First, check non-public note/resource thumbnail
    QFuture<QByteArray> downloadedDataFuture;
    if (urlPart == QStringLiteral("note")) {
        downloadedDataFuture = downloader->downloadNoteThumbnailAsync(
            m_guid, size, imageType, ctx);
    }
    else {
        downloadedDataFuture = downloader->downloadResourceThumbnailAsync(
            m_guid, size, imageType, ctx);
    }

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

    QByteArray downloadedData = downloadedDataFuture.result();

    QVERIFY(downloadedData == m_thumbnailData);

    QVERIFY(
        requestBody == QString::fromUtf8("auth=%1").arg(m_authToken).toUtf8());

    // Second, check public note thumbnail
    requestBody.clear();
    ctx = newRequestContext();
    if (urlPart == QStringLiteral("note")) {
        downloadedDataFuture = downloader->downloadNoteThumbnailAsync(
            m_guid, size, imageType, ctx);
    }
    else {
        downloadedDataFuture = downloader->downloadResourceThumbnailAsync(
            m_guid, size, imageType, ctx);
    }

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

    QVERIFY(downloadedData == m_thumbnailData);
    QVERIFY(requestBody.isEmpty());
}

} // namespace qevercloud
