/**
 * Copyright (c) 2019-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_COMMON_H
#define QEVERCLOUD_TEST_COMMON_H

#include <qevercloud/Types.h>

#include <QByteArray>
#include <QList>
#include <QTcpSocket>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

// (Incomplete) data from http request which might be usable/interesting in
// tests
struct HttpRequestData
{
    enum class Method
    {
        GET,
        POST
    };

    Method method = Method::GET;
    QByteArray uri;
    QByteArray body;
};

[[nodiscard]] HttpRequestData readRequestDataFromSocket(QTcpSocket & socket);

[[nodiscard]] QByteArray readRequestBodyFromSocket(QTcpSocket & socket);

[[nodiscard]] bool writeBufferToSocket(
    const QByteArray & data, QTcpSocket & socket);

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_COMMON_H
