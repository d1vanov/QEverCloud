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

#include <generated/types/NoteMemberShareRelationship.h>

#include "data/NoteMemberShareRelationshipData.h"

namespace qevercloud {

NoteMemberShareRelationship::NoteMemberShareRelationship() : d(new NoteMemberShareRelationshipData) {}

NoteMemberShareRelationship::NoteMemberShareRelationship(const NoteMemberShareRelationship & other) : d(other.d) {}

NoteMemberShareRelationship::NoteMemberShareRelationship(NoteMemberShareRelationship && other) noexcept : d(std::move(other.d))
{}

NoteMemberShareRelationship::~NoteMemberShareRelationship() noexcept {}

NoteMemberShareRelationship & NoteMemberShareRelationship::operator=(const NoteMemberShareRelationship & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteMemberShareRelationship & NoteMemberShareRelationship::operator=(NoteMemberShareRelationship && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & NoteMemberShareRelationship::displayName() const noexcept
{
    return d->m_displayName;
}

void NoteMemberShareRelationship::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = displayName;
}

const std::optional<UserID> & NoteMemberShareRelationship::recipientUserId() const noexcept
{
    return d->m_recipientUserId;
}

std::optional<UserID> & NoteMemberShareRelationship::mutableRecipientUserId()
{
    return d->m_recipientUserId;
}

void NoteMemberShareRelationship::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = recipientUserId;
}

const std::optional<SharedNotePrivilegeLevel> & NoteMemberShareRelationship::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotePrivilegeLevel> & NoteMemberShareRelationship::mutablePrivilege()
{
    return d->m_privilege;
}

void NoteMemberShareRelationship::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<NoteShareRelationshipRestrictions> & NoteMemberShareRelationship::restrictions() const noexcept
{
    return d->m_restrictions;
}

std::optional<NoteShareRelationshipRestrictions> & NoteMemberShareRelationship::mutableRestrictions()
{
    return d->m_restrictions;
}

void NoteMemberShareRelationship::setRestrictions(std::optional<NoteShareRelationshipRestrictions> restrictions)
{
    d->m_restrictions = restrictions;
}

const std::optional<UserID> & NoteMemberShareRelationship::sharerUserId() const noexcept
{
    return d->m_sharerUserId;
}

std::optional<UserID> & NoteMemberShareRelationship::mutableSharerUserId()
{
    return d->m_sharerUserId;
}

void NoteMemberShareRelationship::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = sharerUserId;
}

void NoteMemberShareRelationship::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteMemberShareRelationship::operator==(const NoteMemberShareRelationship & other) const noexcept
{
    return *d == *other.d;
}

bool NoteMemberShareRelationship::operator!=(const NoteMemberShareRelationship & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
