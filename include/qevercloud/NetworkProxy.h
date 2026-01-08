/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_NETWORK_PROXY_H
#define QEVERCLOUD_NETWORK_PROXY_H

#include <qevercloud/Export.h>

#include <QNetworkProxy>

namespace qevercloud {

/**
 * Getter for network proxy settings used by QEverCloud. If none were set
 * explicitly, returns the same result as QNetworkProxy::applicationProxy.
 * Hence, QEverCloud uses the same proxy settings as the application which uses
 * QEverCloud by default.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 *
 * WARNING: when QEverCloud is built with QtWebEngine and some proxy settings
 * different from QNetworkProxy::applicationProxy are set, the OAuth call
 * which loads the web page would not use them; instead it would use proxy
 * settings from QNetworkProxy::applicationProxy. This limitation is imposed
 * by Qt: https://doc.qt.io/qt-5/qtwebengine-overview.html#proxy-support
 */
QEVERCLOUD_EXPORT QNetworkProxy evernoteNetworkProxy();

/**
 * Setter for network proxy settings used by QEverCloud. If this function is
 * never called, QEverCloud would use proxy settings returned from
 * QNetworkProxy::applicationProxy static method.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 *
 * WARNING: when QEverCloud is built with QtWebEngine and some proxy settings
 * different from QNetworkProxy::applicationProxy are set, the OAuth call
 * which loads the web page would not use them; instead it would use proxy
 * settings from QNetworkProxy::applicationProxy. This limitation is imposed
 * by Qt: https://doc.qt.io/qt-5/qtwebengine-overview.html#proxy-support
 */
QEVERCLOUD_EXPORT void setEvernoteNetworkProxy(QNetworkProxy proxy);

/**
 * Reset network proxy settings used by QEverCloud to those returned from
 * QNetworkProxy::applicationProxy static method.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 */
QEVERCLOUD_EXPORT void resetEvernoteNetworkProxy();

} // namespace qevercloud

#endif // QEVERCLOUD_NETWORK_PROXY_H
