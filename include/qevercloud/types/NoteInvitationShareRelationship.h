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

#ifndef QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIP
#define QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIP

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Describes an invitation to a person to use their Evernote credentials
 * to gain access to a note belonging to another user.
 *
 * */
class QEVERCLOUD_EXPORT NoteInvitationShareRelationship: public Printable
{
    Q_GADGET
public:
    NoteInvitationShareRelationship();
    NoteInvitationShareRelationship(const NoteInvitationShareRelationship & other);
    NoteInvitationShareRelationship(NoteInvitationShareRelationship && other) noexcept;
    ~NoteInvitationShareRelationship() noexcept override;

    NoteInvitationShareRelationship & operator=(const NoteInvitationShareRelationship & other);
    NoteInvitationShareRelationship & operator=(NoteInvitationShareRelationship && other) noexcept;

    /**
     * The string that clients should show to users to represent this
     * invitation.
     */
    [[nodiscard]] const std::optional<QString> & displayName() const noexcept;
    void setDisplayName(std::optional<QString> displayName);

    /**
     * Identifies the identity of the invitation recipient. Once the
     * identity has been claimed by an Evernote user and they have accessed
     * the note at least once, the invitation will be used up and will no
     * longer be returned by the service to clients. Instead, that recipient
     * will be included in the list of NoteMemberShareRelationships.
     */
    [[nodiscard]] const std::optional<IdentityID> & recipientIdentityId() const noexcept;
    [[nodiscard]] std::optional<IdentityID> & mutableRecipientIdentityId();
    void setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId);

    /**
     * The privilege level that the recipient will be granted when they
     * accept this invitation. If the user already has a higher privilege to
     * access this note then this will not affect the recipient's privileges.
     */
    [[nodiscard]] const std::optional<SharedNotePrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotePrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    /**
     * The user id of the user who most recently shared this note to this
     * recipient. This field is used by the service to convey information
     * to the user, so clients should treat it as read-only.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserId();
    void setSharerUserId(std::optional<UserID> sharerUserId);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<QString> displayName READ displayName WRITE setDisplayName)
    Q_PROPERTY(std::optional<IdentityID> recipientIdentityId READ recipientIdentityId WRITE setRecipientIdentityId)
    Q_PROPERTY(std::optional<SharedNotePrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<UserID> sharerUserId READ sharerUserId WRITE setSharerUserId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const NoteInvitationShareRelationship & lhs, const NoteInvitationShareRelationship & rhs) noexcept;
[[nodiscard]] bool operator!=(const NoteInvitationShareRelationship & lhs, const NoteInvitationShareRelationship & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteInvitationShareRelationship)

#endif // QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIP
