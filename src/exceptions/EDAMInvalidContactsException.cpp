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

#include <qevercloud/exceptions/EDAMInvalidContactsException.h>

#include "impl/EDAMInvalidContactsExceptionImpl.h"

namespace qevercloud {

EDAMInvalidContactsException::EDAMInvalidContactsException() :
    EvernoteException(QStringLiteral("EDAMInvalidContactsException")),
    d(new EDAMInvalidContactsException::Impl)
 {}

EDAMInvalidContactsException::EDAMInvalidContactsException(const EDAMInvalidContactsException & other) :
    d(other.d)
{}

EDAMInvalidContactsException::EDAMInvalidContactsException(EDAMInvalidContactsException && other) noexcept :
    d(std::move(other.d))
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

const char * EDAMInvalidContactsException::what() const noexcept
{
    return EvernoteException::what();
}

EverCloudExceptionDataPtr EDAMInvalidContactsException::exceptionData() const
{
    return std::make_shared<EDAMInvalidContactsExceptionData>(
        QString::fromUtf8(what()),
        contacts(),
        parameter(),
        reasons());
}

EDAMInvalidContactsExceptionData::EDAMInvalidContactsExceptionData(
    QString error,
    QList<Contact> contacts,
    std::optional<QString> parameter,
    std::optional<QList<EDAMInvalidContactReason>> reasons):
    EvernoteExceptionData(error),
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

EDAMInvalidContactsExceptionData::~EDAMInvalidContactsExceptionData() noexcept {}

void EDAMInvalidContactsExceptionData::throwException() const
{
    EDAMInvalidContactsException e;
    e.setContacts(d->m_contacts);
    e.setParameter(d->m_parameter);
    e.setReasons(d->m_reasons);
    throw e;
}

bool operator==(const EDAMInvalidContactsException & lhs, const EDAMInvalidContactsException & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.contacts() == rhs.contacts() &&
        lhs.parameter() == rhs.parameter() &&
        lhs.reasons() == rhs.reasons();
}

bool operator!=(const EDAMInvalidContactsException & lhs, const EDAMInvalidContactsException & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
