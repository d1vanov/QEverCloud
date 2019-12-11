/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <Globals.h>
#include <AsyncResult.h>
#include <RequestContext.h>

#include <QMetaType>
#include <QGlobalStatic>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

Q_GLOBAL_STATIC(QNetworkAccessManager, globalEvernoteNetworkAccessManager)

////////////////////////////////////////////////////////////////////////////////

void registerMetatypes()
{
    qRegisterMetaType<EverCloudExceptionDataPtr>("EverCloudExceptionDataPtr");
    qRegisterMetaType<IRequestContextPtr>("IRequestContextPtr");
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

QNetworkAccessManager * evernoteNetworkAccessManager()
{
    return globalEvernoteNetworkAccessManager;
}

////////////////////////////////////////////////////////////////////////////////

int libraryVersion()
{
    return 5*10000 + 0*100 + 0;
}

////////////////////////////////////////////////////////////////////////////////

void initializeQEverCloud()
{
    registerMetatypes();
}

} // namespace qevercloud
