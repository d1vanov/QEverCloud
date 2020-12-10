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

#include <generated/types/InvitationShareRelationship.h>

#include "data/InvitationShareRelationshipData.h"

namespace qevercloud {

InvitationShareRelationship::InvitationShareRelationship() : d(new InvitationShareRelationshipData) {}

InvitationShareRelationship::InvitationShareRelationship(const InvitationShareRelationship & other) : d(other.d) {}

InvitationShareRelationship::InvitationShareRelationship(InvitationShareRelationship && other) noexcept : d(std::move(other.d))
{}

InvitationShareRelationship::~InvitationShareRelationship() noexcept {}

InvitationShareRelationship & InvitationShareRelationship::operator=(const InvitationShareRelationship & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

InvitationShareRelationship & InvitationShareRelationship::operator=(InvitationShareRelationship && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & InvitationShareRelationship::displayName() const noexcept
{
    return d->m_displayName;
}

void InvitationShareRelationship::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = displayName;
}

const std::optional<UserIdentity> & InvitationShareRelationship::recipientUserIdentity() const noexcept
{
    return d->m_recipientUserIdentity;
}

std::optional<UserIdentity> & InvitationShareRelationship::mutableRecipientUserIdentity()
{
    return d->m_recipientUserIdentity;
}

void InvitationShareRelationship::setRecipientUserIdentity(std::optional<UserIdentity> recipientUserIdentity)
{
    d->m_recipientUserIdentity = recipientUserIdentity;
}

const std::optional<ShareRelationshipPrivilegeLevel> & InvitationShareRelationship::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<ShareRelationshipPrivilegeLevel> & InvitationShareRelationship::mutablePrivilege()
{
    return d->m_privilege;
}

void InvitationShareRelationship::setPrivilege(std::optional<ShareRelationshipPrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<UserID> & InvitationShareRelationship::sharerUserId() const noexcept
{
    return d->m_sharerUserId;
}

std::optional<UserID> & InvitationShareRelationship::mutableSharerUserId()
{
    return d->m_sharerUserId;
}

void InvitationShareRelationship::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = sharerUserId;
}

void InvitationShareRelationship::print(QTextStream & strm) const
{
    d->print(strm);
}

bool InvitationShareRelationship::operator==(const InvitationShareRelationship & other) const noexcept
{
    return *d == *other.d;
}

bool InvitationShareRelationship::operator!=(const InvitationShareRelationship & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
