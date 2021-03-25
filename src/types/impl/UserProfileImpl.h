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

#ifndef QEVERCLOUD_GENERATED_USERPROFILEIMPL
#define QEVERCLOUD_GENERATED_USERPROFILEIMPL

#include <qevercloud/types/UserProfile.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserProfile::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const UserProfile::Impl & other) = default;
    Impl(UserProfile::Impl && other) noexcept = default;

    UserProfile::Impl & operator=(const UserProfile::Impl & other) = delete;
    UserProfile::Impl & operator=(UserProfile::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_USERPROFILEIMPL
