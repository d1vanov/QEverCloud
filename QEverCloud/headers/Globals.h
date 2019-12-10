/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_GLOBALS_H
#define QEVERCLOUD_GLOBALS_H

#include "Export.h"

#include <QNetworkAccessManager>

/**
 * All the library lives in this namespace.
 */
namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * All network request made by QEverCloud - including OAuth - are
 * served by this NetworkAccessManager.
 *
 * Use this function to handle proxy authentication requests etc.
 */
QEVERCLOUD_EXPORT QNetworkAccessManager * evernoteNetworkAccessManager();

////////////////////////////////////////////////////////////////////////////////

/**
 * QEverCloud library version.
 */
QEVERCLOUD_EXPORT int libraryVersion();

////////////////////////////////////////////////////////////////////////////////

/**
 * Initialization function for QEverCloud, needs to be called once
 * before using the library. There is no harm if it is called multiple times
 */
QEVERCLOUD_EXPORT void initializeQEverCloud();

} // namespace qevercloud

#endif // QEVERCLOUD_GLOBALS_H
