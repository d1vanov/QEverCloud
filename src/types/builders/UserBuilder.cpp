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

#include <qevercloud/types/builders/UserBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserBuilder::Impl final:
    public QSharedData
{
public:
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<UserID> m_id;
    std::optional<QString> m_username;
    std::optional<QString> m_email;
    std::optional<QString> m_name;
    std::optional<QString> m_timezone;
    std::optional<PrivilegeLevel> m_privilege;
    std::optional<ServiceLevel> m_serviceLevel;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_updated;
    std::optional<Timestamp> m_deleted;
    std::optional<bool> m_active;
    std::optional<QString> m_shardId;
    std::optional<UserAttributes> m_attributes;
    std::optional<Accounting> m_accounting;
    std::optional<BusinessUserInfo> m_businessUserInfo;
    std::optional<QString> m_photoUrl;
    std::optional<Timestamp> m_photoLastUpdated;
    std::optional<AccountLimits> m_accountLimits;
};

UserBuilder::UserBuilder() :
    d(new UserBuilder::Impl)
{}

UserBuilder::UserBuilder(UserBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UserBuilder::~UserBuilder() noexcept = default;

UserBuilder & UserBuilder::operator=(UserBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserBuilder & UserBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

UserBuilder & UserBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

UserBuilder & UserBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

UserBuilder & UserBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

UserBuilder & UserBuilder::setId(std::optional<UserID> id)
{
    d->m_id = std::move(id);
    return *this;
}

UserBuilder & UserBuilder::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
    return *this;
}

UserBuilder & UserBuilder::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
    return *this;
}

UserBuilder & UserBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

UserBuilder & UserBuilder::setTimezone(std::optional<QString> timezone)
{
    d->m_timezone = std::move(timezone);
    return *this;
}

UserBuilder & UserBuilder::setPrivilege(std::optional<PrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

UserBuilder & UserBuilder::setServiceLevel(std::optional<ServiceLevel> serviceLevel)
{
    d->m_serviceLevel = std::move(serviceLevel);
    return *this;
}

UserBuilder & UserBuilder::setCreated(std::optional<Timestamp> created)
{
    d->m_created = std::move(created);
    return *this;
}

UserBuilder & UserBuilder::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

UserBuilder & UserBuilder::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = std::move(deleted);
    return *this;
}

UserBuilder & UserBuilder::setActive(std::optional<bool> active)
{
    d->m_active = std::move(active);
    return *this;
}

UserBuilder & UserBuilder::setShardId(std::optional<QString> shardId)
{
    d->m_shardId = std::move(shardId);
    return *this;
}

UserBuilder & UserBuilder::setAttributes(std::optional<UserAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
    return *this;
}

UserBuilder & UserBuilder::setAccounting(std::optional<Accounting> accounting)
{
    d->m_accounting = std::move(accounting);
    return *this;
}

UserBuilder & UserBuilder::setBusinessUserInfo(std::optional<BusinessUserInfo> businessUserInfo)
{
    d->m_businessUserInfo = std::move(businessUserInfo);
    return *this;
}

UserBuilder & UserBuilder::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = std::move(photoUrl);
    return *this;
}

UserBuilder & UserBuilder::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = std::move(photoLastUpdated);
    return *this;
}

UserBuilder & UserBuilder::setAccountLimits(std::optional<AccountLimits> accountLimits)
{
    d->m_accountLimits = std::move(accountLimits);
    return *this;
}

User UserBuilder::build()
{
    User result;

    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setId(std::move(d->m_id));
    result.setUsername(std::move(d->m_username));
    result.setEmail(std::move(d->m_email));
    result.setName(std::move(d->m_name));
    result.setTimezone(std::move(d->m_timezone));
    result.setPrivilege(std::move(d->m_privilege));
    result.setServiceLevel(std::move(d->m_serviceLevel));
    result.setCreated(std::move(d->m_created));
    result.setUpdated(std::move(d->m_updated));
    result.setDeleted(std::move(d->m_deleted));
    result.setActive(std::move(d->m_active));
    result.setShardId(std::move(d->m_shardId));
    result.setAttributes(std::move(d->m_attributes));
    result.setAccounting(std::move(d->m_accounting));
    result.setBusinessUserInfo(std::move(d->m_businessUserInfo));
    result.setPhotoUrl(std::move(d->m_photoUrl));
    result.setPhotoLastUpdated(std::move(d->m_photoLastUpdated));
    result.setAccountLimits(std::move(d->m_accountLimits));

    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_id = {};
    d->m_username = {};
    d->m_email = {};
    d->m_name = {};
    d->m_timezone = {};
    d->m_privilege = {};
    d->m_serviceLevel = {};
    d->m_created = {};
    d->m_updated = {};
    d->m_deleted = {};
    d->m_active = {};
    d->m_shardId = {};
    d->m_attributes = {};
    d->m_accounting = {};
    d->m_businessUserInfo = {};
    d->m_photoUrl = {};
    d->m_photoLastUpdated = {};
    d->m_accountLimits = {};

    return result;
}

} // namespace qevercloud
