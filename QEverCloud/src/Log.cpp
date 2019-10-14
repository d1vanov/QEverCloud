/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <Log.h>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

template <typename T>
void printLogLevel(T & out, const LogLevel level)
{
    switch(level)
    {
    case LogLevel::Trace:
        out << "Trace";
        break;
    case LogLevel::Debug:
        out << "Debug";
        break;
    case LogLevel::Warn:
        out << "Warn";
        break;
    case LogLevel::Error:
        out << "Error";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(level) << ")";
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////

class NullLogger final: public ILogger
{
public:
    virtual void writeLog(
        const LogLevel level, const char * fileName,
        const quint32 lineNumber, const qint64 timestamp,
        const QString & message) override
    {
        Q_UNUSED(level)
        Q_UNUSED(fileName)
        Q_UNUSED(lineNumber)
        Q_UNUSED(timestamp)
        Q_UNUSED(message)
    }

    virtual void setLevel(const LogLevel level) override
    {
        m_level = level;
    }

    virtual LogLevel level() const override
    {
        return m_level;
    }

private:
    LogLevel m_level;
};

} // namespace

////////////////////////////////////////////////////////////////////////////////

ILoggerPtr newNullLogger()
{
    return std::make_shared<NullLogger>();
}

QTextStream & operator<<(QTextStream & out, const LogLevel level)
{
    printLogLevel<QTextStream>(out, level);
    return out;
}

QDebug & operator<<(QDebug & out, const LogLevel level)
{
    printLogLevel<QDebug>(out, level);
    return out;
}

} // namespace qevercloud
