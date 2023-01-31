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

#include <QTcpSocket>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

[[nodiscard]] QByteArray readRequestBodyFromSocket(QTcpSocket & socket);

[[nodiscard]] bool writeBufferToSocket(
    const QByteArray & data, QTcpSocket & socket);

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_COMMON_H
