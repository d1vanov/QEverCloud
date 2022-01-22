/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_USERIMPL
#define QEVERCLOUD_GENERATED_USERIMPL

#include <qevercloud/types/User.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN User::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const User::Impl & other) = default;
    Impl(User::Impl && other) noexcept = default;

    User::Impl & operator=(const User::Impl & other) = delete;
    User::Impl & operator=(User::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERIMPL
