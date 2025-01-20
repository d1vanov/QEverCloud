/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/exceptions/EDAMSystemException.h>

#include "impl/EDAMSystemExceptionImpl.h"

#include <QTextStream>

#include <memory>

namespace qevercloud {

namespace {

[[nodiscard]] std::string composeExceptionMessage(
    const EDAMErrorCode & errorCode,
    const std::optional<QString> & message,
    const std::optional<qint32> & rateLimitDuration)
{
    QString res;
    QTextStream strm{&res};

    strm << "EDAMSystemException: ";
    strm << "errorCode = " << errorCode;
    strm << ", ";

    strm << "message = ";
    if (message) {
        strm << *message;
    }
    else {
        strm << "<none>";
    }
    strm << ", ";

    strm << "rateLimitDuration = ";
    if (rateLimitDuration) {
        strm << *rateLimitDuration;
    }
    else {
        strm << "<none>";
    }
    strm.flush();
    return res.toStdString();
}

} // namespace

EDAMSystemException::EDAMSystemException() :
    EvernoteException(QStringLiteral("EDAMSystemException")),
    d(new EDAMSystemException::Impl)
{}

EDAMSystemException::EDAMSystemException(
    EDAMErrorCode errorCode,
    std::optional<QString> message,
    std::optional<qint32> rateLimitDuration) :
    EvernoteException(QStringLiteral("EDAMSystemException")),
    d(new EDAMSystemException::Impl)
{
    d->m_errorCode = errorCode;
    d->m_message = std::move(message);
    d->m_rateLimitDuration = std::move(rateLimitDuration);
    d->m_strMessage = composeExceptionMessage(
        d->m_errorCode,
        d->m_message,
        d->m_rateLimitDuration);
}

EDAMSystemException::EDAMSystemException(const EDAMSystemException & other) :
    d(other.d)
{}

EDAMSystemException::EDAMSystemException(EDAMSystemException && other) noexcept :
    d(std::move(other.d))
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
    if (d->m_errorCode != errorCode) {
        d->m_errorCode = errorCode;
        d->m_strMessage = composeExceptionMessage(
            d->m_errorCode,
            d->m_message,
            d->m_rateLimitDuration);
    }
}

const std::optional<QString> & EDAMSystemException::message() const noexcept
{
    return d->m_message;
}

void EDAMSystemException::setMessage(std::optional<QString> message)
{
    if (d->m_message != message) {
        d->m_message = std::move(message);
        d->m_strMessage = composeExceptionMessage(
            d->m_errorCode,
            d->m_message,
            d->m_rateLimitDuration);
    }
}

const std::optional<qint32> & EDAMSystemException::rateLimitDuration() const noexcept
{
    return d->m_rateLimitDuration;
}

void EDAMSystemException::setRateLimitDuration(std::optional<qint32> rateLimitDuration)
{
    if (d->m_rateLimitDuration != rateLimitDuration) {
        d->m_rateLimitDuration = rateLimitDuration;
        d->m_strMessage = composeExceptionMessage(
            d->m_errorCode,
            d->m_message,
            d->m_rateLimitDuration);
    }
}

void EDAMSystemException::print(QTextStream & strm) const
{
    d->print(strm);
}

const char * EDAMSystemException::what() const noexcept
{
    return d->m_strMessage.data();
}

void EDAMSystemException::raise() const
{
    throw *this;
}

EDAMSystemException * EDAMSystemException::clone() const
{
    auto e = std::make_unique<EDAMSystemException>();
    e->setErrorCode(d->m_errorCode);
    e->setMessage(d->m_message);
    e->setRateLimitDuration(d->m_rateLimitDuration);
    return e.release();
}

QTextStream & operator<<(QTextStream & strm, const EDAMSystemException & eDAMSystemException)
{
    strm << static_cast<const Printable&>(eDAMSystemException);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const EDAMSystemException & eDAMSystemException)
{
    dbg << static_cast<const Printable&>(eDAMSystemException);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const EDAMSystemException & eDAMSystemException)
{
    strm << static_cast<const Printable&>(eDAMSystemException);
    return strm;
}

bool operator==(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.errorCode() == rhs.errorCode() &&
        lhs.message() == rhs.message() &&
        lhs.rateLimitDuration() == rhs.rateLimitDuration();
}

bool operator!=(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
