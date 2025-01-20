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

#ifndef QEVERCLOUD_GENERATED_USERBUILDER
#define QEVERCLOUD_GENERATED_USERBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/AccountLimits.h>
#include <qevercloud/types/Accounting.h>
#include <qevercloud/types/BusinessUserInfo.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/User.h>
#include <qevercloud/types/UserAttributes.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UserBuilder
{
public:
    UserBuilder();

    UserBuilder(UserBuilder && other) noexcept;

    ~UserBuilder() noexcept;

    UserBuilder & operator=(UserBuilder && other) noexcept;

    UserBuilder & setLocallyModified(bool isLocallyModified);
    UserBuilder & setLocalOnly(bool isLocalOnly);
    UserBuilder & setLocallyFavorited(bool isLocallyFavorited);
    UserBuilder & setLocalData(QHash<QString, QVariant> localData);
    UserBuilder & setId(std::optional<UserID> id);
    UserBuilder & setUsername(std::optional<QString> username);
    UserBuilder & setEmail(std::optional<QString> email);
    UserBuilder & setName(std::optional<QString> name);
    UserBuilder & setTimezone(std::optional<QString> timezone);
    UserBuilder & setPrivilege(std::optional<PrivilegeLevel> privilege);
    UserBuilder & setServiceLevel(std::optional<ServiceLevel> serviceLevel);
    UserBuilder & setCreated(std::optional<Timestamp> created);
    UserBuilder & setUpdated(std::optional<Timestamp> updated);
    UserBuilder & setDeleted(std::optional<Timestamp> deleted);
    UserBuilder & setActive(std::optional<bool> active);
    UserBuilder & setShardId(std::optional<QString> shardId);
    UserBuilder & setAttributes(std::optional<UserAttributes> attributes);
    UserBuilder & setAccounting(std::optional<Accounting> accounting);
    UserBuilder & setBusinessUserInfo(std::optional<BusinessUserInfo> businessUserInfo);
    UserBuilder & setPhotoUrl(std::optional<QString> photoUrl);
    UserBuilder & setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);
    UserBuilder & setAccountLimits(std::optional<AccountLimits> accountLimits);

    [[nodiscard]] User build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERBUILDER
