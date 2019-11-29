/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_COMMON_H
#define QEVERCLOUD_TEST_COMMON_H

#include <generated/Types.h>

#include <QTcpSocket>

#ifdef QEVERCLOUD_SHARED_LIBRARY
#undef QEVERCLOUD_SHARED_LIBRARY
#endif

#ifdef QEVERCLOUD_STATIC_LIBRARY
#undef QEVERCLOUD_STATIC_LIBRARY
#endif

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

QByteArray readThriftRequestFromSocket(QTcpSocket & socket);

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket);

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_COMMON_H
