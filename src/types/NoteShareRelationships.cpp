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

#include <qevercloud/types/NoteShareRelationships.h>

#include "impl/NoteShareRelationshipsImpl.h"

namespace qevercloud {

NoteShareRelationships::NoteShareRelationships() :
    d(new NoteShareRelationships::Impl)
{}

NoteShareRelationships::NoteShareRelationships(const NoteShareRelationships & other) :
    d(other.d)
{}

NoteShareRelationships::NoteShareRelationships(NoteShareRelationships && other) noexcept :
    d(std::move(other.d))
{}

NoteShareRelationships::~NoteShareRelationships() noexcept {}

NoteShareRelationships & NoteShareRelationships::operator=(const NoteShareRelationships & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteShareRelationships & NoteShareRelationships::operator=(NoteShareRelationships && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QList<NoteInvitationShareRelationship>> & NoteShareRelationships::invitations() const noexcept
{
    return d->m_invitations;
}

std::optional<QList<NoteInvitationShareRelationship>> & NoteShareRelationships::mutableInvitations()
{
    return d->m_invitations;
}

void NoteShareRelationships::setInvitations(std::optional<QList<NoteInvitationShareRelationship>> invitations)
{
    d->m_invitations = std::move(invitations);
}

const std::optional<QList<NoteMemberShareRelationship>> & NoteShareRelationships::memberships() const noexcept
{
    return d->m_memberships;
}

std::optional<QList<NoteMemberShareRelationship>> & NoteShareRelationships::mutableMemberships()
{
    return d->m_memberships;
}

void NoteShareRelationships::setMemberships(std::optional<QList<NoteMemberShareRelationship>> memberships)
{
    d->m_memberships = std::move(memberships);
}

const std::optional<NoteShareRelationshipRestrictions> & NoteShareRelationships::invitationRestrictions() const noexcept
{
    return d->m_invitationRestrictions;
}

std::optional<NoteShareRelationshipRestrictions> & NoteShareRelationships::mutableInvitationRestrictions()
{
    return d->m_invitationRestrictions;
}

void NoteShareRelationships::setInvitationRestrictions(std::optional<NoteShareRelationshipRestrictions> invitationRestrictions)
{
    d->m_invitationRestrictions = std::move(invitationRestrictions);
}

void NoteShareRelationships::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const NoteShareRelationships & noteShareRelationships)
{
    strm << static_cast<const Printable&>(noteShareRelationships);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NoteShareRelationships & noteShareRelationships)
{
    dbg << static_cast<const Printable&>(noteShareRelationships);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NoteShareRelationships & noteShareRelationships)
{
    strm << static_cast<const Printable&>(noteShareRelationships);
    return strm;
}

bool operator==(const NoteShareRelationships & lhs, const NoteShareRelationships & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.invitations() == rhs.invitations() &&
        lhs.memberships() == rhs.memberships() &&
        lhs.invitationRestrictions() == rhs.invitationRestrictions();
}

bool operator!=(const NoteShareRelationships & lhs, const NoteShareRelationships & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud