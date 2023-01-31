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

#include <qevercloud/types/builders/NoteShareRelationshipsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteShareRelationshipsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QList<NoteInvitationShareRelationship>> m_invitations;
    std::optional<QList<NoteMemberShareRelationship>> m_memberships;
    std::optional<NoteShareRelationshipRestrictions> m_invitationRestrictions;
};

NoteShareRelationshipsBuilder::NoteShareRelationshipsBuilder() :
    d(new NoteShareRelationshipsBuilder::Impl)
{}

NoteShareRelationshipsBuilder::NoteShareRelationshipsBuilder(NoteShareRelationshipsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteShareRelationshipsBuilder::~NoteShareRelationshipsBuilder() noexcept = default;

NoteShareRelationshipsBuilder & NoteShareRelationshipsBuilder::operator=(NoteShareRelationshipsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteShareRelationshipsBuilder & NoteShareRelationshipsBuilder::setInvitations(std::optional<QList<NoteInvitationShareRelationship>> invitations)
{
    d->m_invitations = std::move(invitations);
    return *this;
}

NoteShareRelationshipsBuilder & NoteShareRelationshipsBuilder::setMemberships(std::optional<QList<NoteMemberShareRelationship>> memberships)
{
    d->m_memberships = std::move(memberships);
    return *this;
}

NoteShareRelationshipsBuilder & NoteShareRelationshipsBuilder::setInvitationRestrictions(std::optional<NoteShareRelationshipRestrictions> invitationRestrictions)
{
    d->m_invitationRestrictions = std::move(invitationRestrictions);
    return *this;
}

NoteShareRelationships NoteShareRelationshipsBuilder::build()
{
    NoteShareRelationships result;

    result.setInvitations(std::move(d->m_invitations));
    result.setMemberships(std::move(d->m_memberships));
    result.setInvitationRestrictions(std::move(d->m_invitationRestrictions));

    d->m_invitations = {};
    d->m_memberships = {};
    d->m_invitationRestrictions = {};

    return result;
}

} // namespace qevercloud
