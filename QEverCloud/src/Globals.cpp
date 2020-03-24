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
#include <QReadLocker>
#include <QReadWriteLock>
#include <QWriteLocker>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

class EvernoteProxySettingsHolder
{
private:
    EvernoteProxySettingsHolder() = default;
    Q_DISABLE_COPY(EvernoteProxySettingsHolder)

public:
    static EvernoteProxySettingsHolder & instance()
    {
        static EvernoteProxySettingsHolder holder;
        return holder;
    }

    QNetworkProxy proxy()
    {
        QReadLocker locker(&m_lock);

        if (m_pProxy) {
            return *m_pProxy;
        }

        return QNetworkProxy::applicationProxy();
    }

    void setProxy(QNetworkProxy proxy)
    {
        QWriteLocker locker(&m_lock);

        if (m_pProxy) {
            *m_pProxy = std::move(proxy);
        }
        else {
            m_pProxy = std::make_shared<QNetworkProxy>(std::move(proxy));
        }
    }

    void resetProxy()
    {
        QWriteLocker locker(&m_lock);
        m_pProxy.reset();
    }

private:
    QReadWriteLock  m_lock;
    std::shared_ptr<QNetworkProxy>  m_pProxy;
};

////////////////////////////////////////////////////////////////////////////////

void registerMetatypes()
{
    qRegisterMetaType<EverCloudExceptionDataPtr>("EverCloudExceptionDataPtr");
    qRegisterMetaType<IRequestContextPtr>("IRequestContextPtr");
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

QNetworkProxy evernoteNetworkProxy()
{
    return EvernoteProxySettingsHolder::instance().proxy();
}

void setEvernoteNetworkProxy(QNetworkProxy proxy)
{
    EvernoteProxySettingsHolder::instance().setProxy(std::move(proxy));
}

void resetEvernoteNetworkProxy()
{
    EvernoteProxySettingsHolder::instance().resetProxy();
}

////////////////////////////////////////////////////////////////////////////////

int libraryVersion()
{
    return 5*10000 + 1*100 + 0;
}

////////////////////////////////////////////////////////////////////////////////

void initializeQEverCloud()
{
    registerMetatypes();
}

} // namespace qevercloud
