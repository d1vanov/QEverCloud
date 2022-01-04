/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/Initialization.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/types/Metatypes.h>

namespace qevercloud {

void initializeQEverCloud()
{
    registerMetatypes();
    qRegisterMetaType<IRequestContextPtr>("IRequestContextPtr");
}

} // namespace qevercloud
