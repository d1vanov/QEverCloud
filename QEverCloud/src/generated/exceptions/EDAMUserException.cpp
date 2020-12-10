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

#include <generated/exceptions/EDAMUserException.h>

#include "data/EDAMUserExceptionData.h"

namespace qevercloud {

EDAMUserException::EDAMUserException() : d(new EDAMUserExceptionData) {}

EDAMUserException::EDAMUserException(const EDAMUserException & other) : d(other.d) {}

EDAMUserException::EDAMUserException(EDAMUserException && other) noexcept : d(std::move(other.d))
{}

EDAMUserException::~EDAMUserException() noexcept {}

EDAMUserException & EDAMUserException::operator=(const EDAMUserException & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

EDAMUserException & EDAMUserException::operator=(EDAMUserException && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMErrorCode EDAMUserException::errorCode() const noexcept
{
    return d->m_errorCode;
}

void EDAMUserException::setErrorCode(EDAMErrorCode errorCode)
{
    d->m_errorCode = errorCode;
}

const std::optional<QString> & EDAMUserException::parameter() const noexcept
{
    return d->m_parameter;
}

void EDAMUserException::setParameter(std::optional<QString> parameter)
{
    d->m_parameter = parameter;
}

void EDAMUserException::print(QTextStream & strm) const
{
    d->print(strm);
}

bool EDAMUserException::operator==(const EDAMUserException & other) const noexcept
{
    return *d == *other.d;
}

bool EDAMUserException::operator!=(const EDAMUserException & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
