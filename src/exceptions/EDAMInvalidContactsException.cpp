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

#include <memory>

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

void EDAMInvalidContactsException::raise() const
{
    throw *this;
}

EDAMInvalidContactsException * EDAMInvalidContactsException::clone() const
{
    auto e = std::make_unique<EDAMInvalidContactsException>();
    e->setContacts(d->m_contacts);
    e->setParameter(d->m_parameter);
    e->setReasons(d->m_reasons);
    return e.release();
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
