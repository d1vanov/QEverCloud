/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/Export.h>

namespace qevercloud {

/**
 * Initialization function for QEverCloud, needs to be called once
 * before using the library. There is no harm if it is called multiple times
 */
QEVERCLOUD_EXPORT void initializeQEverCloud();

} // namespace qevercloud
