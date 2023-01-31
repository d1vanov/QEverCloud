/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS

#include <qevercloud/Export.h>

#include "InvitationShareRelationship.h"
#include "MemberShareRelationship.h"
#include "UserIdentity.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
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
     * The GUID of the notebook whose shares are being managed.
     */
    [[nodiscard]] const std::optional<QString> & notebookGuid() const noexcept;
    void setNotebookGuid(std::optional<QString> notebookGuid);

    /**
     * If the service sends a message to invitees, this parameter will
     * be used to form the actual message that is sent.
     */
    [[nodiscard]] const std::optional<QString> & inviteMessage() const noexcept;
    void setInviteMessage(std::optional<QString> inviteMessage);

    /**
     * The list of existing memberships to update. This field is not
     * intended to be the full set of memberships for the notebook and
     * should only include those already-existing memberships that you
     * actually want to change. If you want to remove shares, see the
     * unshares fields. If you want to create a membership,
     * i.e. auto-join a business user, you can do this via the
     * invitationsToCreateOrUpdate field using an Evernote UserID of a
     * fellow business member (the created invitation is automatically
     * joined by the service, so the client is creating an
     * invitation, not a membership).
     */
    [[nodiscard]] const std::optional<QList<MemberShareRelationship>> & membershipsToUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<MemberShareRelationship>> & mutableMembershipsToUpdate();
    void setMembershipsToUpdate(std::optional<QList<MemberShareRelationship>> membershipsToUpdate);

    /**
     * The list of invitations to update, as matched by the identity
     * field of the InvitationShareRelationship instances, or to create if
     * an existing invitation does not exist. This field is not intended
     * to be the full set of invitations on the notebook and should only
     * include those invitations that you wish to create or update. Note
     * that your invitation could convert into a membership via a
     * service-supported auto-join operation. This happens, for example,
     * when you use an invitation with an Evernote UserID type for a
     * recipient who is a member of the business to which the notebook
     * belongs. Note that to discover the user IDs for business members,
     * the sharer must also be part of the business.
     */
    [[nodiscard]] const std::optional<QList<InvitationShareRelationship>> & invitationsToCreateOrUpdate() const noexcept;
    [[nodiscard]] std::optional<QList<InvitationShareRelationship>> & mutableInvitationsToCreateOrUpdate();
    void setInvitationsToCreateOrUpdate(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate);

    /**
     * The list of share relationships to expunge from the service.
     * If the user identity is for an Evernote UserID, then matching invitations or
     * memberships will be removed. If it's an e-mail, then e-mail based shared notebook
     * invitations will be removed. If it's for an Identity ID, then any invitations that
     * match the identity (by identity ID or user ID or e-mail for legacy invitations) will be
     * removed.
     */
    [[nodiscard]] const std::optional<QList<UserIdentity>> & unshares() const noexcept;
    [[nodiscard]] std::optional<QList<UserIdentity>> & mutableUnshares();
    void setUnshares(std::optional<QList<UserIdentity>> unshares);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const ManageNotebookSharesParameters & manageNotebookSharesParameters);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const ManageNotebookSharesParameters & manageNotebookSharesParameters);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const ManageNotebookSharesParameters & manageNotebookSharesParameters);

    Q_PROPERTY(std::optional<QString> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QString> inviteMessage READ inviteMessage WRITE setInviteMessage)
    Q_PROPERTY(std::optional<QList<MemberShareRelationship>> membershipsToUpdate READ membershipsToUpdate WRITE setMembershipsToUpdate)
    Q_PROPERTY(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate READ invitationsToCreateOrUpdate WRITE setInvitationsToCreateOrUpdate)
    Q_PROPERTY(std::optional<QList<UserIdentity>> unshares READ unshares WRITE setUnshares)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ManageNotebookSharesParameters & lhs, const ManageNotebookSharesParameters & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ManageNotebookSharesParameters & lhs, const ManageNotebookSharesParameters & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERS
