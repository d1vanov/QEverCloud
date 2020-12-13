/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EXPORT_H
#define QEVERCLOUD_EXPORT_H

#include <qevercloud/LibraryType.h>

#include <QtCore/QtGlobal>

#if QEVERCLOUD_SHARED_LIBRARY
#  if BUILDING_QEVERCLOUD_SHARED_LIBRARY
#    define QEVERCLOUD_EXPORT Q_DECL_EXPORT
#  else
#    define QEVERCLOUD_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define QEVERCLOUD_EXPORT
#endif

#endif // QEVERCLOUD_EXPORT_H
