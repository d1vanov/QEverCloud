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

#include <generated/types/ShareRelationships.h>

#include "data/ShareRelationshipsData.h"

namespace qevercloud {

ShareRelationships::ShareRelationships() : d(new ShareRelationshipsData) {}

ShareRelationships::ShareRelationships(const ShareRelationships & other) : d(other.d) {}

ShareRelationships::ShareRelationships(ShareRelationships && other) noexcept : d(std::move(other.d))
{}

ShareRelationships::~ShareRelationships() noexcept {}

ShareRelationships & ShareRelationships::operator=(const ShareRelationships & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ShareRelationships & ShareRelationships::operator=(ShareRelationships && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QList<InvitationShareRelationship>> & ShareRelationships::invitations() const noexcept
{
    return d->m_invitations;
}

std::optional<QList<InvitationShareRelationship>> & ShareRelationships::mutableInvitations()
{
    return d->m_invitations;
}

void ShareRelationships::setInvitations(std::optional<QList<InvitationShareRelationship>> invitations)
{
    d->m_invitations = invitations;
}

const std::optional<QList<MemberShareRelationship>> & ShareRelationships::memberships() const noexcept
{
    return d->m_memberships;
}

std::optional<QList<MemberShareRelationship>> & ShareRelationships::mutableMemberships()
{
    return d->m_memberships;
}

void ShareRelationships::setMemberships(std::optional<QList<MemberShareRelationship>> memberships)
{
    d->m_memberships = memberships;
}

const std::optional<ShareRelationshipRestrictions> & ShareRelationships::invitationRestrictions() const noexcept
{
    return d->m_invitationRestrictions;
}

std::optional<ShareRelationshipRestrictions> & ShareRelationships::mutableInvitationRestrictions()
{
    return d->m_invitationRestrictions;
}

void ShareRelationships::setInvitationRestrictions(std::optional<ShareRelationshipRestrictions> invitationRestrictions)
{
    d->m_invitationRestrictions = invitationRestrictions;
}

void ShareRelationships::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ShareRelationships::operator==(const ShareRelationships & other) const noexcept
{
    return *d == *other.d;
}

bool ShareRelationships::operator!=(const ShareRelationships & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
