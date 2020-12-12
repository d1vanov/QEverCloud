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

#include <generated/types/User.h>

#include "impl/UserImpl.h"

namespace qevercloud {

User::User() : d(new User::Impl) {}

User::User(const User & other) : d(other.d) {}

User::User(User && other) noexcept : d(std::move(other.d))
{}

User::~User() noexcept {}

User & User::operator=(const User & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

User & User::operator=(User && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<UserID> & User::id() const noexcept
{
    return d->m_id;
}

std::optional<UserID> & User::mutableId()
{
    return d->m_id;
}

void User::setId(std::optional<UserID> id)
{
    d->m_id = id;
}

const std::optional<QString> & User::username() const noexcept
{
    return d->m_username;
}

void User::setUsername(std::optional<QString> username)
{
    d->m_username = username;
}

const std::optional<QString> & User::email() const noexcept
{
    return d->m_email;
}

void User::setEmail(std::optional<QString> email)
{
    d->m_email = email;
}

const std::optional<QString> & User::name() const noexcept
{
    return d->m_name;
}

void User::setName(std::optional<QString> name)
{
    d->m_name = name;
}

const std::optional<QString> & User::timezone() const noexcept
{
    return d->m_timezone;
}

void User::setTimezone(std::optional<QString> timezone)
{
    d->m_timezone = timezone;
}

const std::optional<PrivilegeLevel> & User::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<PrivilegeLevel> & User::mutablePrivilege()
{
    return d->m_privilege;
}

void User::setPrivilege(std::optional<PrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<ServiceLevel> & User::serviceLevel() const noexcept
{
    return d->m_serviceLevel;
}

std::optional<ServiceLevel> & User::mutableServiceLevel()
{
    return d->m_serviceLevel;
}

void User::setServiceLevel(std::optional<ServiceLevel> serviceLevel)
{
    d->m_serviceLevel = serviceLevel;
}

const std::optional<Timestamp> & User::created() const noexcept
{
    return d->m_created;
}

std::optional<Timestamp> & User::mutableCreated()
{
    return d->m_created;
}

void User::setCreated(std::optional<Timestamp> created)
{
    d->m_created = created;
}

const std::optional<Timestamp> & User::updated() const noexcept
{
    return d->m_updated;
}

std::optional<Timestamp> & User::mutableUpdated()
{
    return d->m_updated;
}

void User::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = updated;
}

const std::optional<Timestamp> & User::deleted() const noexcept
{
    return d->m_deleted;
}

std::optional<Timestamp> & User::mutableDeleted()
{
    return d->m_deleted;
}

void User::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = deleted;
}

const std::optional<bool> & User::active() const noexcept
{
    return d->m_active;
}

std::optional<bool> & User::mutableActive()
{
    return d->m_active;
}

void User::setActive(std::optional<bool> active)
{
    d->m_active = active;
}

const std::optional<QString> & User::shardId() const noexcept
{
    return d->m_shardId;
}

void User::setShardId(std::optional<QString> shardId)
{
    d->m_shardId = shardId;
}

const std::optional<UserAttributes> & User::attributes() const noexcept
{
    return d->m_attributes;
}

std::optional<UserAttributes> & User::mutableAttributes()
{
    return d->m_attributes;
}

void User::setAttributes(std::optional<UserAttributes> attributes)
{
    d->m_attributes = attributes;
}

const std::optional<Accounting> & User::accounting() const noexcept
{
    return d->m_accounting;
}

std::optional<Accounting> & User::mutableAccounting()
{
    return d->m_accounting;
}

void User::setAccounting(std::optional<Accounting> accounting)
{
    d->m_accounting = accounting;
}

const std::optional<BusinessUserInfo> & User::businessUserInfo() const noexcept
{
    return d->m_businessUserInfo;
}

std::optional<BusinessUserInfo> & User::mutableBusinessUserInfo()
{
    return d->m_businessUserInfo;
}

void User::setBusinessUserInfo(std::optional<BusinessUserInfo> businessUserInfo)
{
    d->m_businessUserInfo = businessUserInfo;
}

const std::optional<QString> & User::photoUrl() const noexcept
{
    return d->m_photoUrl;
}

void User::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = photoUrl;
}

const std::optional<Timestamp> & User::photoLastUpdated() const noexcept
{
    return d->m_photoLastUpdated;
}

std::optional<Timestamp> & User::mutablePhotoLastUpdated()
{
    return d->m_photoLastUpdated;
}

void User::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = photoLastUpdated;
}

const std::optional<AccountLimits> & User::accountLimits() const noexcept
{
    return d->m_accountLimits;
}

std::optional<AccountLimits> & User::mutableAccountLimits()
{
    return d->m_accountLimits;
}

void User::setAccountLimits(std::optional<AccountLimits> accountLimits)
{
    d->m_accountLimits = accountLimits;
}

void User::print(QTextStream & strm) const
{
    d->print(strm);
}

bool User::operator==(const User & other) const noexcept
{
    return *d == *other.d;
}

bool User::operator!=(const User & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
