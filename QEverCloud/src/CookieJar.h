/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <QNetworkCookieJar>

namespace qevercloud {

class NetworkCookieJar: public QNetworkCookieJar
{
    Q_OBJECT
public:
    explicit NetworkCookieJar(QObject * parent = nullptr) :
        QNetworkCookieJar(parent)
    {}

    QList<QNetworkCookie> allCookies()
    {
        return QNetworkCookieJar::allCookies();
    }
};

} // namespace qevercloud
