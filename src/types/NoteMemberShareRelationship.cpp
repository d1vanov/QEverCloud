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

#include <qevercloud/types/NoteMemberShareRelationship.h>

#include "impl/NoteMemberShareRelationshipImpl.h"

namespace qevercloud {

NoteMemberShareRelationship::NoteMemberShareRelationship() :
    d(new NoteMemberShareRelationship::Impl)
{}

NoteMemberShareRelationship::NoteMemberShareRelationship(const NoteMemberShareRelationship & other) :
    d(other.d)
{}

NoteMemberShareRelationship::NoteMemberShareRelationship(NoteMemberShareRelationship && other) noexcept :
    d(std::move(other.d))
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
    d->m_displayName = std::move(displayName);
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
    d->m_restrictions = std::move(restrictions);
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

QTextStream & operator<<(QTextStream & strm, const NoteMemberShareRelationship & noteMemberShareRelationship)
{
    strm << static_cast<const Printable&>(noteMemberShareRelationship);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NoteMemberShareRelationship & noteMemberShareRelationship)
{
    dbg << static_cast<const Printable&>(noteMemberShareRelationship);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NoteMemberShareRelationship & noteMemberShareRelationship)
{
    strm << static_cast<const Printable&>(noteMemberShareRelationship);
    return strm;
}

bool operator==(const NoteMemberShareRelationship & lhs, const NoteMemberShareRelationship & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.displayName() == rhs.displayName() &&
        lhs.recipientUserId() == rhs.recipientUserId() &&
        lhs.privilege() == rhs.privilege() &&
        lhs.restrictions() == rhs.restrictions() &&
        lhs.sharerUserId() == rhs.sharerUserId();
}

bool operator!=(const NoteMemberShareRelationship & lhs, const NoteMemberShareRelationship & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
