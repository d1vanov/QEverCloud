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

#ifndef QEVERCLOUD_GENERATED_USERPROFILEDATA_H
#define QEVERCLOUD_GENERATED_USERPROFILEDATA_H

#include <generated/types/UserProfile.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserProfile::UserProfileData final:
    public QSharedData,
    public Printable
{
public:
    UserProfileData() = default;
    UserProfileData(const UserProfileData & other) = default;
    UserProfileData(UserProfileData && other) noexcept = default;

    UserProfileData & operator=(const UserProfileData & other) = delete;
    UserProfileData & operator=(UserProfileData && other) = delete;

    ~UserProfileData() noexcept override = default;

    [[nodiscard]] bool operator==(const UserProfileData & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserProfileData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserID> m_id;
    std::optional<QString> m_name;
    std::optional<QString> m_email;
    std::optional<QString> m_username;
    std::optional<BusinessUserAttributes> m_attributes;
    std::optional<Timestamp> m_joined;
    std::optional<Timestamp> m_photoLastUpdated;
    std::optional<QString> m_photoUrl;
    std::optional<BusinessUserRole> m_role;
    std::optional<BusinessUserStatus> m_status;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERPROFILEDATA_H
