/**
 * Copyright (c) 2019-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_NETWORK_EXCEPTION_H
#define QEVERCLOUD_NETWORK_EXCEPTION_H

#include <qevercloud/Export.h>
#include <qevercloud/exceptions/EverCloudException.h>

#include <QNetworkReply>

namespace qevercloud {

/**
 * @brief The NetworkException class represents QNetworkReply level errors.
 */
class QEVERCLOUD_EXPORT NetworkException: public EverCloudException
{
public:
    NetworkException();
    NetworkException(QNetworkReply::NetworkError error);
    NetworkException(QNetworkReply::NetworkError error, QString message);
    ~NetworkException() noexcept override;

    [[nodiscard]] bool operator==(
        const NetworkException & other) const noexcept;

    [[nodiscard]] bool operator!=(
        const NetworkException & other) const noexcept;

    [[nodiscard]] QNetworkReply::NetworkError type() const;

    [[nodiscard]] const char * what() const noexcept override;

    void raise() const override;

    [[nodiscard]] NetworkException * clone() const override;

    [[nodiscard]] EverCloudExceptionDataPtr exceptionData() const override;

protected:
    QNetworkReply::NetworkError m_type;
};

/**
 * Asynchronous API counterpart of NetworkException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT NetworkExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(NetworkExceptionData)
public:
    explicit NetworkExceptionData(
        QString error, QNetworkReply::NetworkError type);

    void throwException() const override;

protected:
    QNetworkReply::NetworkError m_type;
};

} // namespace qevercloud

#endif // QEVERCLOUD_NETWORK_EXCEPTION_H
