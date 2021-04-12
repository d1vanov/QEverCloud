/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_THRIFT_EXCEPTION_H
#define QEVERCLOUD_THRIFT_EXCEPTION_H

#include <qevercloud/Export.h>
#include <qevercloud/exceptions/EverCloudException.h>

class QTextStream;

namespace qevercloud {

/**
 * Errors of the Thrift protocol level. It could be wrongly formatted parameters
 * or return values for example.
 */
class QEVERCLOUD_EXPORT ThriftException: public EverCloudException
{
public:
    enum class Type {
        UNKNOWN = 0,
        UNKNOWN_METHOD = 1,
        INVALID_MESSAGE_TYPE = 2,
        WRONG_METHOD_NAME = 3,
        BAD_SEQUENCE_ID = 4,
        MISSING_RESULT = 5,
        INTERNAL_ERROR = 6,
        PROTOCOL_ERROR = 7,
        INVALID_DATA = 8
    };

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const Type type);

    ThriftException();
    ThriftException(Type type);
    ThriftException(Type type, QString message);
    ~ThriftException() noexcept override;

    [[nodiscard]] bool operator==(const ThriftException & other) const noexcept;
    [[nodiscard]] bool operator!=(const ThriftException & other) const noexcept;

    [[nodiscard]] Type type() const noexcept;

    [[nodiscard]] const char * what() const noexcept override;

    void raise() const override;

    [[nodiscard]] ThriftException * clone() const override;

protected:
    Type m_type;
};

} // namespace qevercloud

#endif // QEVERCLOUD_THRIFT_EXCEPTION_H
