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

#include <qevercloud/types/InvitationShareRelationship.h>

#include "impl/InvitationShareRelationshipImpl.h"

namespace qevercloud {

InvitationShareRelationship::InvitationShareRelationship() :
    d(new InvitationShareRelationship::Impl)
{}

InvitationShareRelationship::InvitationShareRelationship(const InvitationShareRelationship & other) :
    d(other.d)
{}

InvitationShareRelationship::InvitationShareRelationship(InvitationShareRelationship && other) noexcept :
    d(std::move(other.d))
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
    d->m_displayName = std::move(displayName);
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
    d->m_recipientUserIdentity = std::move(recipientUserIdentity);
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

QTextStream & operator<<(QTextStream & strm, const InvitationShareRelationship & invitationShareRelationship)
{
    strm << static_cast<const Printable&>(invitationShareRelationship);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const InvitationShareRelationship & invitationShareRelationship)
{
    dbg << static_cast<const Printable&>(invitationShareRelationship);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const InvitationShareRelationship & invitationShareRelationship)
{
    strm << static_cast<const Printable&>(invitationShareRelationship);
    return strm;
}

bool operator==(const InvitationShareRelationship & lhs, const InvitationShareRelationship & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.displayName() == rhs.displayName() &&
        lhs.recipientUserIdentity() == rhs.recipientUserIdentity() &&
        lhs.privilege() == rhs.privilege() &&
        lhs.sharerUserId() == rhs.sharerUserId();
}

bool operator!=(const InvitationShareRelationship & lhs, const InvitationShareRelationship & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud