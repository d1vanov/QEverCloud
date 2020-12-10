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

#include <generated/types/NoteInvitationShareRelationship.h>

#include "data/NoteInvitationShareRelationshipData.h"

namespace qevercloud {

NoteInvitationShareRelationship::NoteInvitationShareRelationship() : d(new NoteInvitationShareRelationshipData) {}

NoteInvitationShareRelationship::NoteInvitationShareRelationship(const NoteInvitationShareRelationship & other) : d(other.d) {}

NoteInvitationShareRelationship::NoteInvitationShareRelationship(NoteInvitationShareRelationship && other) noexcept : d(std::move(other.d))
{}

NoteInvitationShareRelationship::~NoteInvitationShareRelationship() noexcept {}

NoteInvitationShareRelationship & NoteInvitationShareRelationship::operator=(const NoteInvitationShareRelationship & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteInvitationShareRelationship & NoteInvitationShareRelationship::operator=(NoteInvitationShareRelationship && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & NoteInvitationShareRelationship::displayName() const noexcept
{
    return d->m_displayName;
}

void NoteInvitationShareRelationship::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = displayName;
}

const std::optional<IdentityID> & NoteInvitationShareRelationship::recipientIdentityId() const noexcept
{
    return d->m_recipientIdentityId;
}

std::optional<IdentityID> & NoteInvitationShareRelationship::mutableRecipientIdentityId()
{
    return d->m_recipientIdentityId;
}

void NoteInvitationShareRelationship::setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId)
{
    d->m_recipientIdentityId = recipientIdentityId;
}

const std::optional<SharedNotePrivilegeLevel> & NoteInvitationShareRelationship::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotePrivilegeLevel> & NoteInvitationShareRelationship::mutablePrivilege()
{
    return d->m_privilege;
}

void NoteInvitationShareRelationship::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<UserID> & NoteInvitationShareRelationship::sharerUserId() const noexcept
{
    return d->m_sharerUserId;
}

std::optional<UserID> & NoteInvitationShareRelationship::mutableSharerUserId()
{
    return d->m_sharerUserId;
}

void NoteInvitationShareRelationship::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = sharerUserId;
}

void NoteInvitationShareRelationship::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteInvitationShareRelationship::operator==(const NoteInvitationShareRelationship & other) const noexcept
{
    return *d == *other.d;
}

bool NoteInvitationShareRelationship::operator!=(const NoteInvitationShareRelationship & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
