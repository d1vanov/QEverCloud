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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPS_H
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPS_H

#include <qevercloud/Export.h>

#include "InvitationShareRelationship.h"
#include "MemberShareRelationship.h"
#include "ShareRelationshipRestrictions.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Captures a collection of share relationships for a notebook, for
 * example, as returned by the getNotebookShares method.  The share
 * relationships fall into two broad categories: members, and
 * invitations that can be used to become members.
 *
 * */
class QEVERCLOUD_EXPORT ShareRelationships: public Printable
{
    Q_GADGET
public:
    ShareRelationships();
    ShareRelationships(const ShareRelationships & other);
    ShareRelationships(ShareRelationships && other) noexcept;
    ~ShareRelationships() noexcept override;

    ShareRelationships & operator=(const ShareRelationships & other);
    ShareRelationships & operator=(ShareRelationships && other) noexcept;

    /**
    A list of open invitations that can be redeemed into
     memberships to the notebook.
    */
    [[nodiscard]] const std::optional<QList<InvitationShareRelationship>> & invitations() const noexcept;
    [[nodiscard]] std::optional<QList<InvitationShareRelationship>> & mutableInvitations();
    void setInvitations(std::optional<QList<InvitationShareRelationship>> invitations);

    /**
    A list of memberships of the notebook.  A member is identified
     by their Evernote UserID and has rights to access the
     notebook.
    */
    [[nodiscard]] const std::optional<QList<MemberShareRelationship>> & memberships() const noexcept;
    [[nodiscard]] std::optional<QList<MemberShareRelationship>> & mutableMemberships();
    void setMemberships(std::optional<QList<MemberShareRelationship>> memberships);

    /**
    The restrictions on what privileges may be granted to invitees
     to this notebook. These restrictions may be specific to the calling
     user or to the notebook itself. They represent the
     union of all possible invite cases, so it is possible that once the
     recipient of the invitation has been identified by the service, such
     as by a business auto-join, the actual assigned privilege may change.
    */
    [[nodiscard]] const std::optional<ShareRelationshipRestrictions> & invitationRestrictions() const noexcept;
    [[nodiscard]] std::optional<ShareRelationshipRestrictions> & mutableInvitationRestrictions();
    void setInvitationRestrictions(std::optional<ShareRelationshipRestrictions> invitationRestrictions);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const ShareRelationships & other) const noexcept;
    [[nodiscard]] bool operator!=(const ShareRelationships & other) const noexcept;

    Q_PROPERTY(std::optional<QList<InvitationShareRelationship>> invitations READ invitations WRITE setInvitations)
    Q_PROPERTY(std::optional<QList<MemberShareRelationship>> memberships READ memberships WRITE setMemberships)
    Q_PROPERTY(std::optional<ShareRelationshipRestrictions> invitationRestrictions READ invitationRestrictions WRITE setInvitationRestrictions)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ShareRelationships)

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPS_H
