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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPS_H
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPS_H

#include <qevercloud/Export.h>

#include "NoteInvitationShareRelationship.h"
#include "NoteMemberShareRelationship.h"
#include "NoteShareRelationshipRestrictions.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Captures a collection of share relationships for a single note,
 * for example, as returned by the getNoteShares method. The share
 * relationships fall into two broad categories: members, and
 * invitations that can be used to become members.
 *
 * */
class QEVERCLOUD_EXPORT NoteShareRelationships: public Printable
{
    Q_GADGET
public:
    NoteShareRelationships();
    NoteShareRelationships(const NoteShareRelationships & other);
    NoteShareRelationships(NoteShareRelationships && other) noexcept;
    ~NoteShareRelationships() noexcept override;

    NoteShareRelationships & operator=(const NoteShareRelationships & other);
    NoteShareRelationships & operator=(NoteShareRelationships && other) noexcept;

    /**
     * A list of open invitations that can be redeemed into
     * memberships to the note.
     */
    [[nodiscard]] const std::optional<QList<NoteInvitationShareRelationship>> & invitations() const noexcept;
    [[nodiscard]] std::optional<QList<NoteInvitationShareRelationship>> & mutableInvitations();
    void setInvitations(std::optional<QList<NoteInvitationShareRelationship>> invitations);

    /**
     * A list of memberships of the noteb. A member is identified
     * by their Evernote UserID and has rights to access the
     * note.
     */
    [[nodiscard]] const std::optional<QList<NoteMemberShareRelationship>> & memberships() const noexcept;
    [[nodiscard]] std::optional<QList<NoteMemberShareRelationship>> & mutableMemberships();
    void setMemberships(std::optional<QList<NoteMemberShareRelationship>> memberships);

    [[nodiscard]] const std::optional<NoteShareRelationshipRestrictions> & invitationRestrictions() const noexcept;
    [[nodiscard]] std::optional<NoteShareRelationshipRestrictions> & mutableInvitationRestrictions();
    void setInvitationRestrictions(std::optional<NoteShareRelationshipRestrictions> invitationRestrictions);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteShareRelationships & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteShareRelationships & other) const noexcept;

    Q_PROPERTY(std::optional<QList<NoteInvitationShareRelationship>> invitations READ invitations WRITE setInvitations)
    Q_PROPERTY(std::optional<QList<NoteMemberShareRelationship>> memberships READ memberships WRITE setMemberships)
    Q_PROPERTY(std::optional<NoteShareRelationshipRestrictions> invitationRestrictions READ invitationRestrictions WRITE setInvitationRestrictions)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteShareRelationships)

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPS_H
