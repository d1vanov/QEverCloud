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

#include <qevercloud/types/UserProfile.h>

#include "impl/UserProfileImpl.h"

namespace qevercloud {

UserProfile::UserProfile() :
    d(new UserProfile::Impl)
{}

UserProfile::UserProfile(const UserProfile & other) :
    d(other.d)
{}

UserProfile::UserProfile(UserProfile && other) noexcept :
    d(std::move(other.d))
{}

UserProfile::~UserProfile() noexcept {}

UserProfile & UserProfile::operator=(const UserProfile & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

UserProfile & UserProfile::operator=(UserProfile && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<UserID> & UserProfile::id() const noexcept
{
    return d->m_id;
}

std::optional<UserID> & UserProfile::mutableId()
{
    return d->m_id;
}

void UserProfile::setId(std::optional<UserID> id)
{
    d->m_id = id;
}

const std::optional<QString> & UserProfile::name() const noexcept
{
    return d->m_name;
}

void UserProfile::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
}

const std::optional<QString> & UserProfile::email() const noexcept
{
    return d->m_email;
}

void UserProfile::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
}

const std::optional<QString> & UserProfile::username() const noexcept
{
    return d->m_username;
}

void UserProfile::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
}

const std::optional<BusinessUserAttributes> & UserProfile::attributes() const noexcept
{
    return d->m_attributes;
}

std::optional<BusinessUserAttributes> & UserProfile::mutableAttributes()
{
    return d->m_attributes;
}

void UserProfile::setAttributes(std::optional<BusinessUserAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
}

const std::optional<Timestamp> & UserProfile::joined() const noexcept
{
    return d->m_joined;
}

std::optional<Timestamp> & UserProfile::mutableJoined()
{
    return d->m_joined;
}

void UserProfile::setJoined(std::optional<Timestamp> joined)
{
    d->m_joined = joined;
}

const std::optional<Timestamp> & UserProfile::photoLastUpdated() const noexcept
{
    return d->m_photoLastUpdated;
}

std::optional<Timestamp> & UserProfile::mutablePhotoLastUpdated()
{
    return d->m_photoLastUpdated;
}

void UserProfile::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = photoLastUpdated;
}

const std::optional<QString> & UserProfile::photoUrl() const noexcept
{
    return d->m_photoUrl;
}

void UserProfile::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = std::move(photoUrl);
}

const std::optional<BusinessUserRole> & UserProfile::role() const noexcept
{
    return d->m_role;
}

std::optional<BusinessUserRole> & UserProfile::mutableRole()
{
    return d->m_role;
}

void UserProfile::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = role;
}

const std::optional<BusinessUserStatus> & UserProfile::status() const noexcept
{
    return d->m_status;
}

std::optional<BusinessUserStatus> & UserProfile::mutableStatus()
{
    return d->m_status;
}

void UserProfile::setStatus(std::optional<BusinessUserStatus> status)
{
    d->m_status = status;
}

void UserProfile::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const UserProfile & userProfile)
{
    strm << static_cast<const Printable&>(userProfile);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const UserProfile & userProfile)
{
    dbg << static_cast<const Printable&>(userProfile);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const UserProfile & userProfile)
{
    strm << static_cast<const Printable&>(userProfile);
    return strm;
}

bool operator==(const UserProfile & lhs, const UserProfile & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.id() == rhs.id() &&
        lhs.name() == rhs.name() &&
        lhs.email() == rhs.email() &&
        lhs.username() == rhs.username() &&
        lhs.attributes() == rhs.attributes() &&
        lhs.joined() == rhs.joined() &&
        lhs.photoLastUpdated() == rhs.photoLastUpdated() &&
        lhs.photoUrl() == rhs.photoUrl() &&
        lhs.role() == rhs.role() &&
        lhs.status() == rhs.status();
}

bool operator!=(const UserProfile & lhs, const UserProfile & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
