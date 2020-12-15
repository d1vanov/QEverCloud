/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/EverCloudException.h>
#include <qevercloud/Initialization.h>
#include <qevercloud/RequestContext.h>

namespace qevercloud {

namespace {

void registerMetatypes()
{
    qRegisterMetaType<EverCloudExceptionDataPtr>("EverCloudExceptionDataPtr");
    qRegisterMetaType<IRequestContextPtr>("IRequestContextPtr");
}

} // namespace

void initializeQEverCloud()
{
    registerMetatypes();
}

} // namespace qevercloud
