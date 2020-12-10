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

#ifndef QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPDATA_H
#define QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPDATA_H

#include <generated/types/NoteInvitationShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteInvitationShareRelationship::NoteInvitationShareRelationshipData final:
    public QSharedData,
    public Printable
{
public:
    NoteInvitationShareRelationshipData() = default;
    NoteInvitationShareRelationshipData(const NoteInvitationShareRelationshipData & other) = default;
    NoteInvitationShareRelationshipData(NoteInvitationShareRelationshipData && other) noexcept = default;

    NoteInvitationShareRelationshipData & operator=(const NoteInvitationShareRelationshipData & other) = delete;
    NoteInvitationShareRelationshipData & operator=(NoteInvitationShareRelationshipData && other) = delete;

    ~NoteInvitationShareRelationshipData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteInvitationShareRelationshipData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteInvitationShareRelationshipData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<IdentityID> m_recipientIdentityId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPDATA_H
