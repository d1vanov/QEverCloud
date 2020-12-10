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

#ifndef QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPDATA_H
#define QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPDATA_H

#include <generated/types/InvitationShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN InvitationShareRelationship::InvitationShareRelationshipData final:
    public QSharedData,
    public Printable
{
public:
    InvitationShareRelationshipData() = default;
    InvitationShareRelationshipData(const InvitationShareRelationshipData & other) = default;
    InvitationShareRelationshipData(InvitationShareRelationshipData && other) noexcept = default;

    InvitationShareRelationshipData & operator=(const InvitationShareRelationshipData & other) = delete;
    InvitationShareRelationshipData & operator=(InvitationShareRelationshipData && other) = delete;

    ~InvitationShareRelationshipData() noexcept override = default;

    [[nodiscard]] bool operator==(const InvitationShareRelationshipData & other) const noexcept;
    [[nodiscard]] bool operator!=(const InvitationShareRelationshipData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserIdentity> m_recipientUserIdentity;
    std::optional<ShareRelationshipPrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPDATA_H
