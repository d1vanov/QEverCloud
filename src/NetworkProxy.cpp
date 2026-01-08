/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/NetworkProxy.h>

#include <QGlobalStatic>
#include <QReadLocker>
#include <QReadWriteLock>
#include <QWriteLocker>

#include <memory>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

class EvernoteProxySettingsHolder
{
public:
    EvernoteProxySettingsHolder() = default;

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
    Q_DISABLE_COPY(EvernoteProxySettingsHolder)

private:
    QReadWriteLock  m_lock;
    std::shared_ptr<QNetworkProxy>  m_pProxy;
};

Q_GLOBAL_STATIC(EvernoteProxySettingsHolder, evernoteProxySettingsHolder)

} // namespace

////////////////////////////////////////////////////////////////////////////////

QNetworkProxy evernoteNetworkProxy()
{
    return evernoteProxySettingsHolder->proxy();
}

void setEvernoteNetworkProxy(QNetworkProxy proxy)
{
    evernoteProxySettingsHolder->setProxy(std::move(proxy));
}

void resetEvernoteNetworkProxy()
{
    evernoteProxySettingsHolder->resetProxy();
}

} // namespace qevercloud
