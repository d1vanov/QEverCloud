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

#ifndef QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPIMPL
#define QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPIMPL

#include <qevercloud/types/InvitationShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN InvitationShareRelationship::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const InvitationShareRelationship::Impl & other) = default;
    Impl(InvitationShareRelationship::Impl && other) noexcept = default;

    InvitationShareRelationship::Impl & operator=(const InvitationShareRelationship::Impl & other) = delete;
    InvitationShareRelationship::Impl & operator=(InvitationShareRelationship::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserIdentity> m_recipientUserIdentity;
    std::optional<ShareRelationshipPrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPIMPL
