/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_LOG_H
#define QEVERCLOUD_LOG_H

#include "Export.h"

#include <QDebug>
#include <QTextStream>

#include <memory>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

enum class LogLevel
{
    Trace = 0,
    Debug,
    Warn,
    Error
};

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const LogLevel level);

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const LogLevel level);

////////////////////////////////////////////////////////////////////////////////

class QEVERCLOUD_EXPORT ILogger
{
public:
    virtual bool shouldLog(
        const LogLevel level, const char * component) const = 0;

    virtual void log(
        const LogLevel level, const char * component, const char * fileName,
        const quint32 lineNumber, const qint64 timestamp,
        const QString & message) = 0;

    virtual void setLevel(const LogLevel level) = 0;

    virtual LogLevel level() const = 0;
};

using ILoggerPtr = std::shared_ptr<ILogger>;

////////////////////////////////////////////////////////////////////////////////

ILoggerPtr newNullLogger();

ILoggerPtr newStdErrLogger(LogLevel level = LogLevel::Warn);

} // namespace qevercloud

#endif // QEVERCLOUD_LOG_H
