/**
 * Copyright (c) 2019-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "SocketHelpers.h"

#include <QCryptographicHash>
#include <QDateTime>
#include <QEventLoop>
#include <QObject>

#include <algorithm>
#include <cstdlib>
#include <limits>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class ThriftRequestExtractor: public QObject
{
    Q_OBJECT
public:
    explicit ThriftRequestExtractor(QTcpSocket & socket, QObject * parent = nullptr) :
        QObject(parent)
    {
        QObject::connect(
            &socket,
            &QIODevice::readyRead,
            this,
            &ThriftRequestExtractor::onSocketReadyRead,
            Qt::QueuedConnection);
    }

    bool status() const { return m_status; }

    const QByteArray & data() { return m_data; }

Q_SIGNALS:
    void finished();
    void failed();

private Q_SLOTS:
    void onSocketReadyRead()
    {
        QTcpSocket * pSocket = qobject_cast<QTcpSocket*>(sender());
        Q_ASSERT(pSocket);

        m_data.append(pSocket->read(pSocket->bytesAvailable()));
        tryParseData();
    }

private:
    void tryParseData()
    {
        // Data read from socket should be a http request with headers and body

        // First parse headers, find Content-Length one to figure out the size
        // of request body
        int contentLengthIndex = m_data.indexOf("Content-Length:");
        if (contentLengthIndex < 0) {
            // No Content-Length header, probably not all data has arrived yet
            return;
        }

        int contentLengthLineEndIndex = m_data.indexOf("\r\n", contentLengthIndex);
        if (contentLengthLineEndIndex < 0) {
            // No line end after Content-Length header, probably not all data
            // has arrived yet
            return;
        }

        int contentLengthLen = contentLengthLineEndIndex - contentLengthIndex - 15;
        QString contentLengthStr =
            QString::fromUtf8(m_data.mid(contentLengthIndex + 15, contentLengthLen));

        bool conversionResult = false;
        int contentLength = contentLengthStr.toInt(&conversionResult);
        if (Q_UNLIKELY(!conversionResult)) {
            m_status = false;
            Q_EMIT failed();
            return;
        }

        // Now see whether whole body data is present
        int headersEndIndex = m_data.indexOf("\r\n\r\n", contentLengthLineEndIndex);
        if (headersEndIndex < 0) {
            // No empty line after http headers, probably not all data has
            // arrived yet
            return;
        }

        QByteArray body = m_data;
        body.remove(0, headersEndIndex + 4);
        if (body.size() < contentLength) {
            // Not all data has arrived yet
            return;
        }

        m_data = body;
        m_status = true;
        Q_EMIT finished();
    }

private:
    bool            m_status = false;
    QByteArray      m_data;
};

////////////////////////////////////////////////////////////////////////////////

QByteArray readRequestBodyFromSocket(QTcpSocket & socket)
{
    if (!socket.waitForConnected()) {
        return QByteArray();
    }

    QEventLoop loop;
    ThriftRequestExtractor extractor(socket);

    QObject::connect(
        &extractor,
        &ThriftRequestExtractor::finished,
        &loop,
        &QEventLoop::quit);

    QObject::connect(
        &extractor,
        &ThriftRequestExtractor::failed,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    if (!extractor.status()) {
        return QByteArray();
    }

    return extractor.data();
}

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket)
{
    int remaining = data.size();
    const char * pData = data.constData();
    while(socket.isOpen() && remaining>0)
    {
        // If the output buffer has become large, then wait until it has been sent.
        if (socket.bytesToWrite() > 16384)
        {
            socket.waitForBytesWritten(-1);
        }

        qint64 written = socket.write(pData, remaining);
        if (written < 0) {
            return false;
        }

        pData += written;
        remaining -= written;
    }
    return true;
}

} // namespace qevercloud

#include <SocketHelpers.moc>
