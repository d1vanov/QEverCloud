/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <Globals.h>
#include <Exceptions.h>

#include <QMetaType>
#include <QMutex>
#include <QMutexLocker>

#include <memory>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

QNetworkAccessManager * evernoteNetworkAccessManager()
{
    static std::shared_ptr<QNetworkAccessManager> pNetworkAccessManager;
    static QMutex networkAccessManagerMutex;
    QMutexLocker mutexLocker(&networkAccessManagerMutex);
    if (Q_UNLIKELY(!pNetworkAccessManager)) {
        pNetworkAccessManager = std::make_shared<QNetworkAccessManager>();
    }
    return pNetworkAccessManager.get();
}

////////////////////////////////////////////////////////////////////////////////

static int qevercloudRequestTimeout = 180000;

int requestTimeout()
{
    return qevercloudRequestTimeout;
}

void setRequestTimeout(int timeout)
{
    qevercloudRequestTimeout = timeout;
}

////////////////////////////////////////////////////////////////////////////////

int libraryVersion()
{
    return 5*10000 + 0*100 + 0;
}

} // namespace qevercloud
