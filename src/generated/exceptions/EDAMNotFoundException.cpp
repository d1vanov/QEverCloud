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

#include <qevercloud/generated/exceptions/EDAMNotFoundException.h>

#include "impl/EDAMNotFoundExceptionImpl.h"

namespace qevercloud {

EDAMNotFoundException::EDAMNotFoundException() :
    EvernoteException(QStringLiteral("EDAMNotFoundException")),
    d(new EDAMNotFoundException::Impl)
 {}

EDAMNotFoundException::EDAMNotFoundException(const EDAMNotFoundException & other) :
    d(other.d)
{}

EDAMNotFoundException::EDAMNotFoundException(EDAMNotFoundException && other) noexcept :
    d(std::move(other.d))
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

const char * EDAMNotFoundException::what() const noexcept
{
    return EvernoteException::what();
}

EverCloudExceptionDataPtr EDAMNotFoundException::exceptionData() const
{
    return std::make_shared<EDAMNotFoundExceptionData>(
        QString::fromUtf8(what()),
        identifier(),
        key());
}

EDAMNotFoundExceptionData::EDAMNotFoundExceptionData(
    QString error,
    std::optional<QString> identifier,
    std::optional<QString> key):
    EvernoteExceptionData(error),
    d(new EDAMNotFoundExceptionData::Impl)
{
    d->m_identifier = std::move(identifier);
    d->m_key = std::move(key);
}

const std::optional<QString> & EDAMNotFoundExceptionData::identifier() const noexcept
{
    return d->m_identifier;
}

void EDAMNotFoundExceptionData::setIdentifier(std::optional<QString> identifier)
{
    d->m_identifier = identifier;
}

const std::optional<QString> & EDAMNotFoundExceptionData::key() const noexcept
{
    return d->m_key;
}

void EDAMNotFoundExceptionData::setKey(std::optional<QString> key)
{
    d->m_key = key;
}

EDAMNotFoundExceptionData::~EDAMNotFoundExceptionData() noexcept {}

void EDAMNotFoundExceptionData::throwException() const
{
    EDAMNotFoundException e;
    e.setIdentifier(d->m_identifier);
    e.setKey(d->m_key);
    throw e;
}

bool operator==(const EDAMNotFoundException & lhs, const EDAMNotFoundException & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.identifier() == rhs.identifier() &&
        lhs.key() == rhs.key();
}

bool operator!=(const EDAMNotFoundException & lhs, const EDAMNotFoundException & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
