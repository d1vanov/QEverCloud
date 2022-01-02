/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIP
#define QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIP

#include <qevercloud/Export.h>

#include "UserIdentity.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Describes an invitation to a person to use their Evernote
 * credentials to become a member of a notebook.
 *
 * */
class QEVERCLOUD_EXPORT InvitationShareRelationship: public Printable
{
    Q_GADGET
public:
    InvitationShareRelationship();
    InvitationShareRelationship(const InvitationShareRelationship & other);
    InvitationShareRelationship(InvitationShareRelationship && other) noexcept;
    ~InvitationShareRelationship() noexcept override;

    InvitationShareRelationship & operator=(const InvitationShareRelationship & other);
    InvitationShareRelationship & operator=(InvitationShareRelationship && other) noexcept;

    /**
     * The string that clients should show to users to represent this
     * invitation.
     */
    [[nodiscard]] const std::optional<QString> & displayName() const noexcept;
    void setDisplayName(std::optional<QString> displayName);

    /**
     * Identifies the recipient of the invitation. The user identity
     * type can be either EMAIL, EVERNOTE or IDENTITYID. If the
     * invitation was created using the classic notebook sharing APIs it will be EMAIL. If it
     * was created using the new identity-based notebook sharing APIs it will either be
     * EVERNOTE or IDENTITYID, depending on whether we can map the identity to an Evernote
     * user at the time of creation.
     */
    [[nodiscard]] const std::optional<UserIdentity> & recipientUserIdentity() const noexcept;
    [[nodiscard]] std::optional<UserIdentity> & mutableRecipientUserIdentity();
    void setRecipientUserIdentity(std::optional<UserIdentity> recipientUserIdentity);

    /**
     * The privilege level at which the member will be joined, if it
     * turns out that the member is not already joined at a higher level.
     * Note that the <tt>identity</tt> field may not uniquely identify an
     * Evernote User ID, and so we won't know until the invitation is
     * redeemed whether or not the recipient already has privilege.
     */
    [[nodiscard]] const std::optional<ShareRelationshipPrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<ShareRelationshipPrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<ShareRelationshipPrivilegeLevel> privilege);

    /**
     * The user id of the user who most recently shared this notebook
     * to this identity. This field is used by the service to convey information
     * to the user, so clients should treat it as read-only.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserId();
    void setSharerUserId(std::optional<UserID> sharerUserId);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const InvitationShareRelationship & invitationShareRelationship);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const InvitationShareRelationship & invitationShareRelationship);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const InvitationShareRelationship & invitationShareRelationship);

    Q_PROPERTY(std::optional<QString> displayName READ displayName WRITE setDisplayName)
    Q_PROPERTY(std::optional<UserIdentity> recipientUserIdentity READ recipientUserIdentity WRITE setRecipientUserIdentity)
    Q_PROPERTY(std::optional<ShareRelationshipPrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<UserID> sharerUserId READ sharerUserId WRITE setSharerUserId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const InvitationShareRelationship & lhs, const InvitationShareRelationship & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const InvitationShareRelationship & lhs, const InvitationShareRelationship & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::InvitationShareRelationship)

#endif // QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIP
