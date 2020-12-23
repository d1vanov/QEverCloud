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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS_H

#include <qevercloud/Export.h>

#include "InvitationShareRelationship.h"
#include "MemberShareRelationship.h"
#include "UserIdentity.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure that captures parameters used by clients to manage the
 * shares for a given notebook via the manageNotebookShares method.
 *
 * */
class QEVERCLOUD_EXPORT ManageNotebookSharesParameters: public Printable
{
    Q_GADGET
public:
    ManageNotebookSharesParameters();
    ManageNotebookSharesParameters(const ManageNotebookSharesParameters & other);
    ManageNotebookSharesParameters(ManageNotebookSharesParameters && other) noexcept;
    ~ManageNotebookSharesParameters() noexcept override;

    ManageNotebookSharesParameters & operator=(const ManageNotebookSharesParameters & other);
    ManageNotebookSharesParameters & operator=(ManageNotebookSharesParameters && other) noexcept;

    /**
    The GUID of the notebook whose shares are being managed.
    */
    [[nodiscard]] const std::optional<QString> & notebookGuid() const noexcept;
    void setNotebookGuid(std::optional<QString> notebookGuid);

    /**
    If the service sends a message to invitees, this parameter will
     be used to form the actual message that is sent.
    */
    [[nodiscard]] const std::optional<QString> & inviteMessage() const noexcept;
    void setInviteMessage(std::optional<QString> inviteMessage);

    /**
    The list of existing memberships to update.  This field is not
     intended to be the full set of memberships for the notebook and
     should only include those already-existing memberships that you
     actually want to change.  If you want to remove shares, see the
     unshares fields.  If you want to create a membership,
     i.e. auto-join a business user, you can do this via the
     invitationsToCreateOrUpdate field using an Evernote UserID of a
     fellow business member (the created invitation is automatically
     joined by the service, so the client is creating an
     invitation, not a membership).
    */
    [[nodiscard]] const std::optional<QList<MemberShareRelationship>> & membershipsToUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<MemberShareRelationship>> & mutableMembershipsToUpdate();
    void setMembershipsToUpdate(std::optional<QList<MemberShareRelationship>> membershipsToUpdate);

    /**
    The list of invitations to update, as matched by the identity
     field of the InvitationShareRelationship instances, or to create if
     an existing invitation does not exist.  This field is not intended
     to be the full set of invitations on the notebook and should only
     include those invitations that you wish to create or update.  Note
     that your invitation could convert into a membership via a
     service-supported auto-join operation.  This happens, for example,
     when you use an invitation with an Evernote UserID type for a
     recipient who is a member of the business to which the notebook
     belongs.  Note that to discover the user IDs for business members,
     the sharer must also be part of the business.
    */
    [[nodiscard]] const std::optional<QList<InvitationShareRelationship>> & invitationsToCreateOrUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<InvitationShareRelationship>> & mutableInvitationsToCreateOrUpdate();
    void setInvitationsToCreateOrUpdate(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate);

    /**
    The list of share relationships to expunge from the service.
     If the user identity is for an Evernote UserID, then matching invitations or
     memberships will be removed. If it's an e-mail, then e-mail based shared notebook
     invitations will be removed. If it's for an Identity ID, then any invitations that
     match the identity (by identity ID or user ID or e-mail for legacy invitations) will be
     removed.
    */
    [[nodiscard]] const std::optional<QList<UserIdentity>> & unshares() const noexcept;
    [[nodiscard]] std::optional<QList<UserIdentity>> & mutableUnshares();
    void setUnshares(std::optional<QList<UserIdentity>> unshares);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const ManageNotebookSharesParameters & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesParameters & other) const noexcept;

    Q_PROPERTY(std::optional<QString> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QString> inviteMessage READ inviteMessage WRITE setInviteMessage)
    Q_PROPERTY(std::optional<QList<MemberShareRelationship>> membershipsToUpdate READ membershipsToUpdate WRITE setMembershipsToUpdate)
    Q_PROPERTY(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate READ invitationsToCreateOrUpdate WRITE setInvitationsToCreateOrUpdate)
    Q_PROPERTY(std::optional<QList<UserIdentity>> unshares READ unshares WRITE setUnshares)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesParameters)

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS_H
