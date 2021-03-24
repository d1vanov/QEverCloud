/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/exceptions/EDAMSystemException.h>

#include "impl/EDAMSystemExceptionImpl.h"

namespace qevercloud {

EDAMSystemException::EDAMSystemException() :
    EvernoteException(QStringLiteral("EDAMSystemException")),
    d(new EDAMSystemException::Impl)
 {}

EDAMSystemException::EDAMSystemException(const EDAMSystemException & other) :
    d(other.d)
{}

EDAMSystemException::EDAMSystemException(EDAMSystemException && other) noexcept :
    d(std::move(other.d))
{}

EDAMSystemException::~EDAMSystemException() noexcept {}

EDAMSystemException & EDAMSystemException::operator=(const EDAMSystemException & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

EDAMSystemException & EDAMSystemException::operator=(EDAMSystemException && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMErrorCode EDAMSystemException::errorCode() const noexcept
{
    return d->m_errorCode;
}

void EDAMSystemException::setErrorCode(EDAMErrorCode errorCode)
{
    d->m_errorCode = errorCode;
}

const std::optional<QString> & EDAMSystemException::message() const noexcept
{
    return d->m_message;
}

void EDAMSystemException::setMessage(std::optional<QString> message)
{
    d->m_message = message;
}

const std::optional<qint32> & EDAMSystemException::rateLimitDuration() const noexcept
{
    return d->m_rateLimitDuration;
}

std::optional<qint32> & EDAMSystemException::mutableRateLimitDuration()
{
    return d->m_rateLimitDuration;
}

void EDAMSystemException::setRateLimitDuration(std::optional<qint32> rateLimitDuration)
{
    d->m_rateLimitDuration = rateLimitDuration;
}

void EDAMSystemException::print(QTextStream & strm) const
{
    d->print(strm);
}

const char * EDAMSystemException::what() const noexcept
{
    return EvernoteException::what();
}

EverCloudExceptionDataPtr EDAMSystemException::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionData>(
        QString::fromUtf8(what()),
        errorCode(),
        message(),
        rateLimitDuration());
}

EDAMSystemExceptionData::EDAMSystemExceptionData(
    QString error,
    EDAMErrorCode errorCode,
    std::optional<QString> message,
    std::optional<qint32> rateLimitDuration):
    EvernoteExceptionData(error),
    d(new EDAMSystemExceptionData::Impl)
{
    d->m_errorCode = std::move(errorCode);
    d->m_message = std::move(message);
    d->m_rateLimitDuration = std::move(rateLimitDuration);
}

EDAMErrorCode EDAMSystemExceptionData::errorCode() const noexcept
{
    return d->m_errorCode;
}

void EDAMSystemExceptionData::setErrorCode(EDAMErrorCode errorCode)
{
    d->m_errorCode = errorCode;
}

const std::optional<QString> & EDAMSystemExceptionData::message() const noexcept
{
    return d->m_message;
}

void EDAMSystemExceptionData::setMessage(std::optional<QString> message)
{
    d->m_message = message;
}

const std::optional<qint32> & EDAMSystemExceptionData::rateLimitDuration() const noexcept
{
    return d->m_rateLimitDuration;
}

std::optional<qint32> & EDAMSystemExceptionData::mutableRateLimitDuration()
{
    return d->m_rateLimitDuration;
}

void EDAMSystemExceptionData::setRateLimitDuration(std::optional<qint32> rateLimitDuration)
{
    d->m_rateLimitDuration = rateLimitDuration;
}

EDAMSystemExceptionData::~EDAMSystemExceptionData() noexcept {}

void EDAMSystemExceptionData::throwException() const
{
    EDAMSystemException e;
    e.setErrorCode(d->m_errorCode);
    e.setMessage(d->m_message);
    e.setRateLimitDuration(d->m_rateLimitDuration);
    throw e;
}

bool operator==(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.errorCode() == rhs.errorCode() &&
        lhs.message() == rhs.message() &&
        lhs.rateLimitDuration() == rhs.rateLimitDuration();
}

bool operator!=(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
