/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "../Types_io.h"

#include <qevercloud/exceptions/ThriftException.h>

#include <QTextStream>

namespace qevercloud {

ThriftException::ThriftException() :
    m_type(Type::UNKNOWN)
{}

ThriftException::ThriftException(ThriftException::Type type) :
    m_type(type)
{}

ThriftException::ThriftException(ThriftException::Type type, QString message) :
    m_type(type)
{}

ThriftException::~ThriftException() noexcept
{}

QTextStream & operator<<(QTextStream & strm, const ThriftException::Type type)
{
    switch(type)
    {
    case ThriftException::Type::UNKNOWN:
        strm << "Unknown application exception";
        break;
    case ThriftException::Type::UNKNOWN_METHOD:
        strm << "Unknown method";
        break;
    case ThriftException::Type::INVALID_MESSAGE_TYPE:
        strm << "Invalid message type";
        break;
    case ThriftException::Type::WRONG_METHOD_NAME:
        strm << "Wrong method name";
        break;
    case ThriftException::Type::BAD_SEQUENCE_ID:
        strm << "Bad sequence identifier";
        break;
    case ThriftException::Type::MISSING_RESULT:
        strm << "Missing result";
        break;
    case ThriftException::Type::INTERNAL_ERROR:
        strm << "Internal error";
        break;
    case ThriftException::Type::PROTOCOL_ERROR:
        strm << "Protocol error";
        break;
    case ThriftException::Type::INVALID_DATA:
        strm << "Invalid data";
        break;
    default:
        strm << "Invalid exception type: " << static_cast<int>(type);
        break;
    }

    return strm;
}

bool ThriftException::operator==(const ThriftException & other) const noexcept
{
    return m_type == other.m_type && m_error == other.m_error;
}

bool ThriftException::operator!=(const ThriftException & other) const noexcept
{
    return !operator==(other);
}

ThriftException::Type ThriftException::type() const noexcept
{
    return m_type;
}

const char * ThriftException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        switch (m_type)
        {
        case Type::UNKNOWN:
            return "ThriftException: Unknown application exception";
        case Type::UNKNOWN_METHOD:
            return "ThriftException: Unknown method";
        case Type::INVALID_MESSAGE_TYPE:
            return "ThriftException: Invalid message type";
        case Type::WRONG_METHOD_NAME:
            return "ThriftException: Wrong method name";
        case Type::BAD_SEQUENCE_ID:
            return "ThriftException: Bad sequence identifier";
        case Type::MISSING_RESULT:
            return "ThriftException: Missing result";
        case Type::INTERNAL_ERROR:
            return "ThriftException: Internal error";
        case Type::PROTOCOL_ERROR:
            return "ThriftException: Protocol error";
        case Type::INVALID_DATA:
            return "ThriftException: Invalid data";
        default:
            return "ThriftException: (Invalid exception type)";
        };
    }
    else
    {
        return m_error.constData();
    }
}

EverCloudExceptionDataPtr ThriftException::exceptionData() const
{
    return std::make_shared<ThriftExceptionData>(
        QString::fromUtf8(what()), type());
}

ThriftExceptionData::ThriftExceptionData(
        QString error,
        ThriftException::Type type) :
    EverCloudExceptionData(error),
    m_type(type)
{}

void ThriftExceptionData::throwException() const
{
    throw ThriftException(m_type, errorMessage);
}

ThriftException readThriftException(ThriftBinaryBufferReader & reader)
{
    QString name;
    ThriftFieldType fieldType;
    qint16 fieldId;

    reader.readStructBegin(name);
    QString error;
    ThriftException::Type type = ThriftException::Type::UNKNOWN;

    while(true)
    {
        reader.readFieldBegin(name, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        switch(fieldId)
        {
        case 1:
            if (fieldType == ThriftFieldType::T_STRING) {
                QString str;
                reader.readString(str);
                error = str;
            }
            else {
                reader.skip(fieldType);
            }
            break;
        case 2:
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 t;
                reader.readI32(t);
                type = static_cast<ThriftException::Type>(t);
            }
            else {
                reader.skip(fieldType);
            }
            break;
        default:
            reader.skip(fieldType);
            break;
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();

    return ThriftException(type, error);
}

void writeThriftException(
    ThriftBinaryBufferWriter & writer, const ThriftException & exception)
{
    writer.writeStructBegin(QStringLiteral("ThriftException"));

    writer.writeFieldBegin(QStringLiteral("error"), ThriftFieldType::T_STRING, 1);
    writer.writeString(QString::fromUtf8(exception.what()));
    writer.writeFieldEnd();

    writer.writeFieldBegin(QStringLiteral("type"), ThriftFieldType::T_I32, 2);
    writer.writeI32(static_cast<qint32>(exception.type()));
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
}

} // namespace qevercloud
