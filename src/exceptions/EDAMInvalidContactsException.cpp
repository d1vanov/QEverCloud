/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/exceptions/EDAMInvalidContactsException.h>

#include "impl/EDAMInvalidContactsExceptionImpl.h"

#include <QTextStream>

#include <memory>

namespace qevercloud {

namespace {

[[nodiscard]] std::string composeExceptionMessage(
    const QList<Contact> & contacts,
    const std::optional<QString> & parameter,
    const std::optional<QList<EDAMInvalidContactReason>> & reasons)
{
    QString res;
    QTextStream strm{&res};

    strm << "EDAMInvalidContactsException: ";
    Q_UNUSED(contacts);
    strm << "parameter = ";
    if (parameter) {
        strm << *parameter;
    }
    else {
        strm << "<none>";
    }
    strm << ", ";

    Q_UNUSED(reasons);
    strm.flush();
    return res.toStdString();
}

} // namespace

EDAMInvalidContactsException::EDAMInvalidContactsException() :
    EvernoteException(QStringLiteral("EDAMInvalidContactsException")),
    d(new EDAMInvalidContactsException::Impl)
{}

EDAMInvalidContactsException::EDAMInvalidContactsException(
    QList<Contact> contacts,
    std::optional<QString> parameter,
    std::optional<QList<EDAMInvalidContactReason>> reasons) :
    EvernoteException(QStringLiteral("EDAMInvalidContactsException")),
    d(new EDAMInvalidContactsException::Impl)
{
    d->m_contacts = std::move(contacts);
    d->m_parameter = std::move(parameter);
    d->m_reasons = std::move(reasons);
    d->m_strMessage = composeExceptionMessage(
        d->m_contacts,
        d->m_parameter,
        d->m_reasons);
}

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

void EDAMInvalidContactsException::setContacts(QList<Contact> contacts)
{
    if (d->m_contacts != contacts) {
        d->m_contacts = std::move(contacts);
        d->m_strMessage = composeExceptionMessage(
            d->m_contacts,
            d->m_parameter,
            d->m_reasons);
    }
}

const std::optional<QString> & EDAMInvalidContactsException::parameter() const noexcept
{
    return d->m_parameter;
}

void EDAMInvalidContactsException::setParameter(std::optional<QString> parameter)
{
    if (d->m_parameter != parameter) {
        d->m_parameter = std::move(parameter);
        d->m_strMessage = composeExceptionMessage(
            d->m_contacts,
            d->m_parameter,
            d->m_reasons);
    }
}

const std::optional<QList<EDAMInvalidContactReason>> & EDAMInvalidContactsException::reasons() const noexcept
{
    return d->m_reasons;
}

void EDAMInvalidContactsException::setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons)
{
    if (d->m_reasons != reasons) {
        d->m_reasons = std::move(reasons);
        d->m_strMessage = composeExceptionMessage(
            d->m_contacts,
            d->m_parameter,
            d->m_reasons);
    }
}

void EDAMInvalidContactsException::print(QTextStream & strm) const
{
    d->print(strm);
}

const char * EDAMInvalidContactsException::what() const noexcept
{
    return d->m_strMessage.data();
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

QTextStream & operator<<(QTextStream & strm, const EDAMInvalidContactsException & eDAMInvalidContactsException)
{
    strm << static_cast<const Printable&>(eDAMInvalidContactsException);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const EDAMInvalidContactsException & eDAMInvalidContactsException)
{
    dbg << static_cast<const Printable&>(eDAMInvalidContactsException);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const EDAMInvalidContactsException & eDAMInvalidContactsException)
{
    strm << static_cast<const Printable&>(eDAMInvalidContactsException);
    return strm;
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
