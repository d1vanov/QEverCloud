/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <Globals.h>

#include <QGlobalStatic>

namespace qevercloud {

Q_GLOBAL_STATIC(QNetworkAccessManager, globalEvernoteNetworkAccessManager)

////////////////////////////////////////////////////////////////////////////////

QNetworkAccessManager * evernoteNetworkAccessManager()
{
    return globalEvernoteNetworkAccessManager;
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
