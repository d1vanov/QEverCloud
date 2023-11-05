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

#include <qevercloud/exceptions/EDAMUserException.h>

#include "impl/EDAMUserExceptionImpl.h"

#include <QTextStream>

#include <memory>

namespace qevercloud {

namespace {

[[nodiscard]] std::string composeExceptionMessage(
    const EDAMErrorCode & errorCode,
    const std::optional<QString> & parameter)
{
    QString res;
    QTextStream strm{&res};

    strm << "EDAMUserException: ";
    strm << "errorCode = " << errorCode;
    strm << ", ";

    strm << "parameter = ";
    if (parameter) {
        strm << *parameter;
    }
    else {
        strm << "<none>";
    }
    strm.flush();
    return res.toStdString();
}

} // namespace

EDAMUserException::EDAMUserException() :
    EvernoteException(QStringLiteral("EDAMUserException")),
    d(new EDAMUserException::Impl)
{}

EDAMUserException::EDAMUserException(
    EDAMErrorCode errorCode,
    std::optional<QString> parameter) :
    EvernoteException(QStringLiteral("EDAMUserException")),
    d(new EDAMUserException::Impl)
{
    d->m_errorCode = errorCode;
    d->m_parameter = std::move(parameter);
    d->m_strMessage = composeExceptionMessage(
        d->m_errorCode,
        d->m_parameter);
}

EDAMUserException::EDAMUserException(const EDAMUserException & other) :
    d(other.d)
{}

EDAMUserException::EDAMUserException(EDAMUserException && other) noexcept :
    d(std::move(other.d))
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
    if (d->m_errorCode != errorCode) {
        d->m_errorCode = errorCode;
        d->m_strMessage = composeExceptionMessage(
            d->m_errorCode,
            d->m_parameter);
    }
}

const std::optional<QString> & EDAMUserException::parameter() const noexcept
{
    return d->m_parameter;
}

void EDAMUserException::setParameter(std::optional<QString> parameter)
{
    if (d->m_parameter != parameter) {
        d->m_parameter = std::move(parameter);
        d->m_strMessage = composeExceptionMessage(
            d->m_errorCode,
            d->m_parameter);
    }
}

void EDAMUserException::print(QTextStream & strm) const
{
    d->print(strm);
}

const char * EDAMUserException::what() const noexcept
{
    return d->m_strMessage.data();
}

void EDAMUserException::raise() const
{
    throw *this;
}

EDAMUserException * EDAMUserException::clone() const
{
    auto e = std::make_unique<EDAMUserException>();
    e->setErrorCode(d->m_errorCode);
    e->setParameter(d->m_parameter);
    return e.release();
}

QTextStream & operator<<(QTextStream & strm, const EDAMUserException & eDAMUserException)
{
    strm << static_cast<const Printable&>(eDAMUserException);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const EDAMUserException & eDAMUserException)
{
    dbg << static_cast<const Printable&>(eDAMUserException);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const EDAMUserException & eDAMUserException)
{
    strm << static_cast<const Printable&>(eDAMUserException);
    return strm;
}

bool operator==(const EDAMUserException & lhs, const EDAMUserException & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.errorCode() == rhs.errorCode() &&
        lhs.parameter() == rhs.parameter();
}

bool operator!=(const EDAMUserException & lhs, const EDAMUserException & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
