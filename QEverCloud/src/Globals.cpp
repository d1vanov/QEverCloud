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

#ifndef __MINGW32__
#include <QGlobalStatic>
#else
#include <QMutex>
#include <QMutexLocker>
#include <memory>
#endif

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

// For unknown reason fetching the value declared as Q_GLOBAL_STATIC hangs with
// code built by MinGW. Hence this workaround
#ifndef __MINGW32__
Q_GLOBAL_STATIC(QNetworkAccessManager, globalEvernoteNetworkAccessManager)
#endif

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
#ifndef __MINGW32__
    return globalEvernoteNetworkAccessManager;
#else
    static std::shared_ptr<QNetworkAccessManager> pNetworkAccessManager;
    static QMutex networkAccessManagerMutex;
    QMutexLocker mutexLocker(&networkAccessManagerMutex);
    if (!pNetworkAccessManager) {
        pNetworkAccessManager.reset(new QNetworkAccessManager);
    }
    return pNetworkAccessManager.get();
#endif
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
