/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EVER_CLOUD_EXCEPTION_H
#define QEVERCLOUD_EVER_CLOUD_EXCEPTION_H

#include <qevercloud/Export.h>

#include <QException>
#include <QObject>
#include <QString>

namespace qevercloud {

/**
 * All exceptions thrown by the library are of this class or its descendants.
 */
class QEVERCLOUD_EXPORT EverCloudException: public QException
{
protected:
    mutable QByteArray m_error;

public:
    explicit EverCloudException();
    explicit EverCloudException(QString error);
    explicit EverCloudException(const std::string & error);
    explicit EverCloudException(const char * error);

    ~EverCloudException() noexcept override;

    [[nodiscard]] const char * what() const noexcept override;

    void raise() const override;

    [[nodiscard]] EverCloudException * clone() const override;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EVER_CLOUD_EXCEPTION_H
