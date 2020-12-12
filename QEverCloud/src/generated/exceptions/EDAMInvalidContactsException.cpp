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

#include <generated/exceptions/EDAMInvalidContactsException.h>

#include "impl/EDAMInvalidContactsExceptionImpl.h"

namespace qevercloud {

EDAMInvalidContactsException::EDAMInvalidContactsException() : d(new EDAMInvalidContactsException::Impl) {}

EDAMInvalidContactsException::EDAMInvalidContactsException(const EDAMInvalidContactsException & other) : d(other.d) {}

EDAMInvalidContactsException::EDAMInvalidContactsException(EDAMInvalidContactsException && other) noexcept : d(std::move(other.d))
{}

EDAMInvalidContactsException::~EDAMInvalidContactsException() noexcept {}

EDAMInvalidContactsException & EDAMInvalidContactsException::operator=(const EDAMInvalidContactsException & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

EDAMInvalidContactsException & EDAMInvalidContactsException::operator=(EDAMInvalidContactsException && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QList<Contact> & EDAMInvalidContactsException::contacts() const noexcept
{
    return d->m_contacts;
}

QList<Contact> & EDAMInvalidContactsException::mutableContacts()
{
    return d->m_contacts;
}

void EDAMInvalidContactsException::setContacts(QList<Contact> contacts)
{
    d->m_contacts = contacts;
}

const std::optional<QString> & EDAMInvalidContactsException::parameter() const noexcept
{
    return d->m_parameter;
}

void EDAMInvalidContactsException::setParameter(std::optional<QString> parameter)
{
    d->m_parameter = parameter;
}

const std::optional<QList<EDAMInvalidContactReason>> & EDAMInvalidContactsException::reasons() const noexcept
{
    return d->m_reasons;
}

std::optional<QList<EDAMInvalidContactReason>> & EDAMInvalidContactsException::mutableReasons()
{
    return d->m_reasons;
}

void EDAMInvalidContactsException::setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons)
{
    d->m_reasons = reasons;
}

void EDAMInvalidContactsException::print(QTextStream & strm) const
{
    d->print(strm);
}

bool EDAMInvalidContactsException::operator==(const EDAMInvalidContactsException & other) const noexcept
{
    return *d == *other.d;
}

bool EDAMInvalidContactsException::operator!=(const EDAMInvalidContactsException & other) const noexcept
{
    return !(*this == other);
}

const char * EDAMInvalidContactsException::what() const noexcept
{
    return EvernoteException::what();
}

EverCloudExceptionDataPtr EDAMInvalidContactsException::exceptionData() const
{
    return std::make_shared<EDAMInvalidContactsExceptionData>(
        contacts(),
        parameter(),
        reasons());
}

EDAMInvalidContactsExceptionData::EDAMInvalidContactsExceptionData(
    QList<Contact> contacts,
    QString parameter,
    QList<EDAMInvalidContactReason> reasons):
    EvernoteExceptionData(QStringLiteral("EDAMInvalidContactsExceptionData")),
    d(new EDAMInvalidContactsExceptionData::Impl)
{
    d->m_contacts = std::move(contacts);
    d->m_parameter = std::move(parameter);
    d->m_reasons = std::move(reasons);
}

const QList<Contact> & EDAMInvalidContactsExceptionData::contacts() const noexcept
{
    return d->m_contacts;
}

QList<Contact> & EDAMInvalidContactsExceptionData::mutableContacts()
{
    return d->m_contacts;
}

void EDAMInvalidContactsExceptionData::setContacts(QList<Contact> contacts)
{
    d->m_contacts = contacts;
}

const std::optional<QString> & EDAMInvalidContactsExceptionData::parameter() const noexcept
{
    return d->m_parameter;
}

void EDAMInvalidContactsExceptionData::setParameter(std::optional<QString> parameter)
{
    d->m_parameter = parameter;
}

const std::optional<QList<EDAMInvalidContactReason>> & EDAMInvalidContactsExceptionData::reasons() const noexcept
{
    return d->m_reasons;
}

std::optional<QList<EDAMInvalidContactReason>> & EDAMInvalidContactsExceptionData::mutableReasons()
{
    return d->m_reasons;
}

void EDAMInvalidContactsExceptionData::setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons)
{
    d->m_reasons = reasons;
}

void EDAMInvalidContactsExceptionData::throwException() const
{
    EDAMInvalidContactsException e;
    e.setContacts(d->m_contacts);
    e.setParameter(d->m_parameter);
    e.setReasons(d->m_reasons);
    throw e;
}

} // namespace qevercloud
