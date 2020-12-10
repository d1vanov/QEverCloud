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

#include <generated/exceptions/EDAMNotFoundException.h>

#include "data/EDAMNotFoundExceptionData.h"

namespace qevercloud {

EDAMNotFoundException::EDAMNotFoundException() : d(new EDAMNotFoundExceptionData) {}

EDAMNotFoundException::EDAMNotFoundException(const EDAMNotFoundException & other) : d(other.d) {}

EDAMNotFoundException::EDAMNotFoundException(EDAMNotFoundException && other) noexcept : d(std::move(other.d))
{}

EDAMNotFoundException::~EDAMNotFoundException() noexcept {}

EDAMNotFoundException & EDAMNotFoundException::operator=(const EDAMNotFoundException & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

EDAMNotFoundException & EDAMNotFoundException::operator=(EDAMNotFoundException && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & EDAMNotFoundException::identifier() const noexcept
{
    return d->m_identifier;
}

void EDAMNotFoundException::setIdentifier(std::optional<QString> identifier)
{
    d->m_identifier = identifier;
}

const std::optional<QString> & EDAMNotFoundException::key() const noexcept
{
    return d->m_key;
}

void EDAMNotFoundException::setKey(std::optional<QString> key)
{
    d->m_key = key;
}

void EDAMNotFoundException::print(QTextStream & strm) const
{
    d->print(strm);
}

bool EDAMNotFoundException::operator==(const EDAMNotFoundException & other) const noexcept
{
    return *d == *other.d;
}

bool EDAMNotFoundException::operator!=(const EDAMNotFoundException & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
