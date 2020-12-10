/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/exceptions/EDAMSystemException.h>

#include "data/EDAMSystemExceptionData.h"

namespace qevercloud {

EDAMSystemException::EDAMSystemException() : d(new EDAMSystemExceptionData) {}

EDAMSystemException::EDAMSystemException(const EDAMSystemException & other) : d(other.d) {}

EDAMSystemException::EDAMSystemException(EDAMSystemException && other) noexcept : d(std::move(other.d))
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

bool EDAMSystemException::operator==(const EDAMSystemException & other) const noexcept
{
    return *d == *other.d;
}

bool EDAMSystemException::operator!=(const EDAMSystemException & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
