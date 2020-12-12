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

#include <generated/types/MemberShareRelationship.h>

#include "impl/MemberShareRelationshipImpl.h"

namespace qevercloud {

MemberShareRelationship::MemberShareRelationship() : d(new MemberShareRelationship::Impl) {}

MemberShareRelationship::MemberShareRelationship(const MemberShareRelationship & other) : d(other.d) {}

MemberShareRelationship::MemberShareRelationship(MemberShareRelationship && other) noexcept : d(std::move(other.d))
{}

MemberShareRelationship::~MemberShareRelationship() noexcept {}

MemberShareRelationship & MemberShareRelationship::operator=(const MemberShareRelationship & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

MemberShareRelationship & MemberShareRelationship::operator=(MemberShareRelationship && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & MemberShareRelationship::displayName() const noexcept
{
    return d->m_displayName;
}

void MemberShareRelationship::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = displayName;
}

const std::optional<UserID> & MemberShareRelationship::recipientUserId() const noexcept
{
    return d->m_recipientUserId;
}

std::optional<UserID> & MemberShareRelationship::mutableRecipientUserId()
{
    return d->m_recipientUserId;
}

void MemberShareRelationship::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = recipientUserId;
}

const std::optional<ShareRelationshipPrivilegeLevel> & MemberShareRelationship::bestPrivilege() const noexcept
{
    return d->m_bestPrivilege;
}

std::optional<ShareRelationshipPrivilegeLevel> & MemberShareRelationship::mutableBestPrivilege()
{
    return d->m_bestPrivilege;
}

void MemberShareRelationship::setBestPrivilege(std::optional<ShareRelationshipPrivilegeLevel> bestPrivilege)
{
    d->m_bestPrivilege = bestPrivilege;
}

const std::optional<ShareRelationshipPrivilegeLevel> & MemberShareRelationship::individualPrivilege() const noexcept
{
    return d->m_individualPrivilege;
}

std::optional<ShareRelationshipPrivilegeLevel> & MemberShareRelationship::mutableIndividualPrivilege()
{
    return d->m_individualPrivilege;
}

void MemberShareRelationship::setIndividualPrivilege(std::optional<ShareRelationshipPrivilegeLevel> individualPrivilege)
{
    d->m_individualPrivilege = individualPrivilege;
}

const std::optional<ShareRelationshipRestrictions> & MemberShareRelationship::restrictions() const noexcept
{
    return d->m_restrictions;
}

std::optional<ShareRelationshipRestrictions> & MemberShareRelationship::mutableRestrictions()
{
    return d->m_restrictions;
}

void MemberShareRelationship::setRestrictions(std::optional<ShareRelationshipRestrictions> restrictions)
{
    d->m_restrictions = restrictions;
}

const std::optional<UserID> & MemberShareRelationship::sharerUserId() const noexcept
{
    return d->m_sharerUserId;
}

std::optional<UserID> & MemberShareRelationship::mutableSharerUserId()
{
    return d->m_sharerUserId;
}

void MemberShareRelationship::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = sharerUserId;
}

void MemberShareRelationship::print(QTextStream & strm) const
{
    d->print(strm);
}

bool MemberShareRelationship::operator==(const MemberShareRelationship & other) const noexcept
{
    return *d == *other.d;
}

bool MemberShareRelationship::operator!=(const MemberShareRelationship & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
