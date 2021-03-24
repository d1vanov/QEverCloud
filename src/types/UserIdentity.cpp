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

#include <qevercloud/types/UserIdentity.h>

#include "impl/UserIdentityImpl.h"

namespace qevercloud {

UserIdentity::UserIdentity() :
    d(new UserIdentity::Impl)
 {}

UserIdentity::UserIdentity(const UserIdentity & other) :
    d(other.d)
{}

UserIdentity::UserIdentity(UserIdentity && other) noexcept :
    d(std::move(other.d))
{}

UserIdentity::~UserIdentity() noexcept {}

UserIdentity & UserIdentity::operator=(const UserIdentity & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

UserIdentity & UserIdentity::operator=(UserIdentity && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<UserIdentityType> & UserIdentity::type() const noexcept
{
    return d->m_type;
}

std::optional<UserIdentityType> & UserIdentity::mutableType()
{
    return d->m_type;
}

void UserIdentity::setType(std::optional<UserIdentityType> type)
{
    d->m_type = type;
}

const std::optional<QString> & UserIdentity::stringIdentifier() const noexcept
{
    return d->m_stringIdentifier;
}

void UserIdentity::setStringIdentifier(std::optional<QString> stringIdentifier)
{
    d->m_stringIdentifier = stringIdentifier;
}

const std::optional<qint64> & UserIdentity::longIdentifier() const noexcept
{
    return d->m_longIdentifier;
}

std::optional<qint64> & UserIdentity::mutableLongIdentifier()
{
    return d->m_longIdentifier;
}

void UserIdentity::setLongIdentifier(std::optional<qint64> longIdentifier)
{
    d->m_longIdentifier = longIdentifier;
}

void UserIdentity::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const UserIdentity & lhs, const UserIdentity & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.type() == rhs.type() &&
        lhs.stringIdentifier() == rhs.stringIdentifier() &&
        lhs.longIdentifier() == rhs.longIdentifier();
}

bool operator!=(const UserIdentity & lhs, const UserIdentity & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
