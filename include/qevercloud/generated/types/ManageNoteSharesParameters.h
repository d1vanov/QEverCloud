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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERS_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERS_H

#include <qevercloud/Export.h>

#include "NoteInvitationShareRelationship.h"
#include "NoteMemberShareRelationship.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Captures parameters used by clients to manage the shares for a given
 * note via the manageNoteShares function. This is used only to manage
 * the existing memberships and invitations for a note. To invite a new
 * recipient, use NoteStore.createOrUpdateSharedNotes.
 *
 * The only field of an existing membership or invitation that can be
 * updated by this function is the share privilege.
 *
 * */
class QEVERCLOUD_EXPORT ManageNoteSharesParameters: public Printable
{
    Q_GADGET
public:
    ManageNoteSharesParameters();
    ManageNoteSharesParameters(const ManageNoteSharesParameters & other);
    ManageNoteSharesParameters(ManageNoteSharesParameters && other) noexcept;
    ~ManageNoteSharesParameters() noexcept override;

    ManageNoteSharesParameters & operator=(const ManageNoteSharesParameters & other);
    ManageNoteSharesParameters & operator=(ManageNoteSharesParameters && other) noexcept;

    /**
     * The GUID of the note whose shares are being managed.
     */
    [[nodiscard]] const std::optional<QString> & noteGuid() const noexcept;
    void setNoteGuid(std::optional<QString> noteGuid);

    /**
     * A list of existing memberships to update. This field is not
     * meant to be the full set of memberships for the note. Clients
     * should only include those existing memberships that they wish
     * to modify. To remove an existing membership, see the unshares
     * field.
     */
    [[nodiscard]] const std::optional<QList<NoteMemberShareRelationship>> & membershipsToUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<NoteMemberShareRelationship>> & mutableMembershipsToUpdate();
    void setMembershipsToUpdate(std::optional<QList<NoteMemberShareRelationship>> membershipsToUpdate);

    /**
     * The list of outstanding invitations to update, as matched by the
     * identity field of the NoteInvitationShareRelatioship instances.
     * This field is not meant to be the full set of invitations for the
     * note. Clients should only include those existing invitations that
     * they wish to modify.
     */
    [[nodiscard]] const std::optional<QList<NoteInvitationShareRelationship>> & invitationsToUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<NoteInvitationShareRelationship>> & mutableInvitationsToUpdate();
    void setInvitationsToUpdate(std::optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate);

    /**
     * A list of existing memberships to expunge from the service.
     */
    [[nodiscard]] const std::optional<QList<UserID>> & membershipsToUnshare() const noexcept;
    [[nodiscard]] std::optional<QList<UserID>> & mutableMembershipsToUnshare();
    void setMembershipsToUnshare(std::optional<QList<UserID>> membershipsToUnshare);

    /**
     * A list of outstanding invitations to expunge from the service.
     */
    [[nodiscard]] const std::optional<QList<IdentityID>> & invitationsToUnshare() const noexcept;
    [[nodiscard]] std::optional<QList<IdentityID>> & mutableInvitationsToUnshare();
    void setInvitationsToUnshare(std::optional<QList<IdentityID>> invitationsToUnshare);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<QString> noteGuid READ noteGuid WRITE setNoteGuid)
    Q_PROPERTY(std::optional<QList<NoteMemberShareRelationship>> membershipsToUpdate READ membershipsToUpdate WRITE setMembershipsToUpdate)
    Q_PROPERTY(std::optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate READ invitationsToUpdate WRITE setInvitationsToUpdate)
    Q_PROPERTY(std::optional<QList<UserID>> membershipsToUnshare READ membershipsToUnshare WRITE setMembershipsToUnshare)
    Q_PROPERTY(std::optional<QList<IdentityID>> invitationsToUnshare READ invitationsToUnshare WRITE setInvitationsToUnshare)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const ManageNoteSharesParameters & lhs, const ManageNoteSharesParameters & rhs) noexcept;
[[nodiscard]] bool operator!=(const ManageNoteSharesParameters & lhs, const ManageNoteSharesParameters & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNoteSharesParameters)

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERS_H
