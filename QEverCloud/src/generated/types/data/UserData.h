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

#ifndef QEVERCLOUD_GENERATED_USERDATA_H
#define QEVERCLOUD_GENERATED_USERDATA_H

#include <generated/types/User.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN User::UserData final:
    public QSharedData,
    public Printable
{
public:
    UserData() = default;
    UserData(const UserData & other) = default;
    UserData(UserData && other) noexcept = default;

    UserData & operator=(const UserData & other) = delete;
    UserData & operator=(UserData && other) = delete;

    ~UserData() noexcept override = default;

    [[nodiscard]] bool operator==(const UserData & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserData & other) const noexcept;

    void print(QTextStream & strm) const override;

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

#endif // QEVERCLOUD_GENERATED_USERDATA_H
