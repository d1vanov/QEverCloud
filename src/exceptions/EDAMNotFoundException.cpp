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

#include <qevercloud/exceptions/EDAMNotFoundException.h>

#include "impl/EDAMNotFoundExceptionImpl.h"

#include <QTextStream>

#include <memory>

namespace qevercloud {

namespace {

[[nodiscard]] std::string composeExceptionMessage(
    const std::optional<QString> & identifier,
    const std::optional<QString> & key)
{
    QString res;
    QTextStream strm{&res};

    strm << "EDAMNotFoundException: ";
    strm << "identifier = ";
    if (identifier) {
        strm << *identifier;
    }
    else {
        strm << "<none>";
    }
    strm << ", ";

    strm << "key = ";
    if (key) {
        strm << *key;
    }
    else {
        strm << "<none>";
    }
    strm.flush();
    return res.toStdString();
}

} // namespace

EDAMNotFoundException::EDAMNotFoundException() :
    EvernoteException(QStringLiteral("EDAMNotFoundException")),
    d(new EDAMNotFoundException::Impl)
{}

EDAMNotFoundException::EDAMNotFoundException(
    std::optional<QString> identifier,
    std::optional<QString> key) :
    EvernoteException(QStringLiteral("EDAMNotFoundException")),
    d(new EDAMNotFoundException::Impl)
{
    d->m_identifier = std::move(identifier);
    d->m_key = std::move(key);
    d->m_strMessage = composeExceptionMessage(
        d->m_identifier,
        d->m_key);
}

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
    if (d->m_identifier != identifier) {
        d->m_identifier = std::move(identifier);
        d->m_strMessage = composeExceptionMessage(
            d->m_identifier,
            d->m_key);
    }
}

const std::optional<QString> & EDAMNotFoundException::key() const noexcept
{
    return d->m_key;
}

void EDAMNotFoundException::setKey(std::optional<QString> key)
{
    if (d->m_key != key) {
        d->m_key = std::move(key);
        d->m_strMessage = composeExceptionMessage(
            d->m_identifier,
            d->m_key);
    }
}

void EDAMNotFoundException::print(QTextStream & strm) const
{
    d->print(strm);
}

const char * EDAMNotFoundException::what() const noexcept
{
    return d->m_strMessage.data();
}

void EDAMNotFoundException::raise() const
{
    throw *this;
}

EDAMNotFoundException * EDAMNotFoundException::clone() const
{
    auto e = std::make_unique<EDAMNotFoundException>();
    e->setIdentifier(d->m_identifier);
    e->setKey(d->m_key);
    return e.release();
}

QTextStream & operator<<(QTextStream & strm, const EDAMNotFoundException & eDAMNotFoundException)
{
    strm << static_cast<const Printable&>(eDAMNotFoundException);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const EDAMNotFoundException & eDAMNotFoundException)
{
    dbg << static_cast<const Printable&>(eDAMNotFoundException);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const EDAMNotFoundException & eDAMNotFoundException)
{
    strm << static_cast<const Printable&>(eDAMNotFoundException);
    return strm;
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
