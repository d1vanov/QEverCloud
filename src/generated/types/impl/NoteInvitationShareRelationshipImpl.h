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

#ifndef QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPIMPL_H
#define QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPIMPL_H

#include <qevercloud/generated/types/NoteInvitationShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteInvitationShareRelationship::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteInvitationShareRelationship::Impl & other) = default;
    Impl(NoteInvitationShareRelationship::Impl && other) noexcept = default;

    NoteInvitationShareRelationship::Impl & operator=(const NoteInvitationShareRelationship::Impl & other) = delete;
    NoteInvitationShareRelationship::Impl & operator=(NoteInvitationShareRelationship::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteInvitationShareRelationship::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteInvitationShareRelationship::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<IdentityID> m_recipientIdentityId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPIMPL_H
