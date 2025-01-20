/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/ShareRelationshipsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationshipsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QList<InvitationShareRelationship>> m_invitations;
    std::optional<QList<MemberShareRelationship>> m_memberships;
    std::optional<ShareRelationshipRestrictions> m_invitationRestrictions;
};

ShareRelationshipsBuilder::ShareRelationshipsBuilder() :
    d(new ShareRelationshipsBuilder::Impl)
{}

ShareRelationshipsBuilder::ShareRelationshipsBuilder(ShareRelationshipsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ShareRelationshipsBuilder::~ShareRelationshipsBuilder() noexcept = default;

ShareRelationshipsBuilder & ShareRelationshipsBuilder::operator=(ShareRelationshipsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ShareRelationshipsBuilder & ShareRelationshipsBuilder::setInvitations(std::optional<QList<InvitationShareRelationship>> invitations)
{
    d->m_invitations = std::move(invitations);
    return *this;
}

ShareRelationshipsBuilder & ShareRelationshipsBuilder::setMemberships(std::optional<QList<MemberShareRelationship>> memberships)
{
    d->m_memberships = std::move(memberships);
    return *this;
}

ShareRelationshipsBuilder & ShareRelationshipsBuilder::setInvitationRestrictions(std::optional<ShareRelationshipRestrictions> invitationRestrictions)
{
    d->m_invitationRestrictions = std::move(invitationRestrictions);
    return *this;
}

ShareRelationships ShareRelationshipsBuilder::build()
{
    ShareRelationships result;

    result.setInvitations(std::move(d->m_invitations));
    result.setMemberships(std::move(d->m_memberships));
    result.setInvitationRestrictions(std::move(d->m_invitationRestrictions));

    d->m_invitations = {};
    d->m_memberships = {};
    d->m_invitationRestrictions = {};

    return result;
}

} // namespace qevercloud
