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

#include <QTcpServer>
#include <QtTest/QtTest>

namespace qevercloud {

InkNoteImageDownloaderTester::InkNoteImageDownloaderTester(QObject * parent) :
    QObject(parent)
{}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeSynchronously()
{
    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
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

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    // TODO: implement
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSingleStripeAsynchronously()
{
    // TODO: implement
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSeveralStripesSynchronously()
{
    // TODO: implement
}

void InkNoteImageDownloaderTester::downloadInkNoteImageWithSeveralStripesAsynchronously()
{
    // TODO: implement
}

} // namespace qevercloud
