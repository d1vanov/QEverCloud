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
#include <iterator>
#include <limits>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

// Pretty dumb yet suitable for tests HTTP parser of data coming from QTcpSocket.
class HttpRequestParser: public QObject
{
    Q_OBJECT
public:
    explicit HttpRequestParser(QTcpSocket & socket, QObject * parent = nullptr) :
        QObject(parent)
    {
        QObject::connect(
            &socket,
            &QIODevice::readyRead,
            this,
            &HttpRequestParser::onSocketReadyRead,
            Qt::QueuedConnection);
    }

    [[nodiscard]] bool status() const noexcept { return m_status; }

    [[nodiscard]] const QByteArray & data() const noexcept { return m_requestData.body; }

    [[nodiscard]] HttpRequestData requestData() const { return m_requestData; }

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
        // Data read from socket should be a HTTP request with headers and body.
        // Maybe incomplete in which case we postpone the attempt to parse
        // the request.

        // The first line of a HTTP request should be the request line:
        // method<space>request-uri<space>http-version<crlf>
        int methodEndIndex = m_data.indexOf(" ");
        if (methodEndIndex < 0) {
            // No first space symbol, probably not all data has arrived yet
            return;
        }

        const QByteArray method{m_data.constData(), methodEndIndex};
        if (method == QByteArray::fromRawData("GET", 3))
        {
            m_requestData.method = HttpRequestData::Method::GET;
        }
        else if (method == QByteArray::fromRawData("POST", 4))
        {
            m_requestData.method = HttpRequestData::Method::POST;
        }

        int resourceUriEndIndex = m_data.indexOf(" ", methodEndIndex + 1);
        if (resourceUriEndIndex < 0) {
            // No resource URI end index, probably not all data has arrived yet
            return;
        }

        m_requestData.uri = QByteArray{
            m_data.constData() + methodEndIndex + 1,
            resourceUriEndIndex - methodEndIndex - 1};

        // Now parse headers, find Content-Length one to figure out the size
        // of request body
        int contentLengthIndex =
            m_data.indexOf("Content-Length:", resourceUriEndIndex + 1);
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

        m_requestData.body = body;
        m_status = true;
        Q_EMIT finished();
    }

private:
    bool            m_status = false;
    HttpRequestData m_requestData;
    QByteArray      m_data;
};

////////////////////////////////////////////////////////////////////////////////

HttpRequestData readRequestDataFromSocket(QTcpSocket & socket)
{
    if (!socket.waitForConnected()) {
        return {};
    }

    QEventLoop loop;
    HttpRequestParser extractor(socket);

    QObject::connect(
        &extractor,
        &HttpRequestParser::finished,
        &loop,
        &QEventLoop::quit);

    QObject::connect(
        &extractor,
        &HttpRequestParser::failed,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    if (!extractor.status()) {
        return {};
    }

    return extractor.requestData();
}

QByteArray readRequestBodyFromSocket(QTcpSocket & socket)
{
    return readRequestDataFromSocket(socket).body;
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
