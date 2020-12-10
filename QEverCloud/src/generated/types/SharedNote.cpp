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

#include <generated/types/SharedNote.h>

#include "data/SharedNoteData.h"

namespace qevercloud {

SharedNote::SharedNote() : d(new SharedNoteData) {}

SharedNote::SharedNote(const SharedNote & other) : d(other.d) {}

SharedNote::SharedNote(SharedNote && other) noexcept : d(std::move(other.d))
{}

SharedNote::~SharedNote() noexcept {}

SharedNote & SharedNote::operator=(const SharedNote & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SharedNote & SharedNote::operator=(SharedNote && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<UserID> & SharedNote::sharerUserID() const noexcept
{
    return d->m_sharerUserID;
}

std::optional<UserID> & SharedNote::mutableSharerUserID()
{
    return d->m_sharerUserID;
}

void SharedNote::setSharerUserID(std::optional<UserID> sharerUserID)
{
    d->m_sharerUserID = sharerUserID;
}

const std::optional<Identity> & SharedNote::recipientIdentity() const noexcept
{
    return d->m_recipientIdentity;
}

std::optional<Identity> & SharedNote::mutableRecipientIdentity()
{
    return d->m_recipientIdentity;
}

void SharedNote::setRecipientIdentity(std::optional<Identity> recipientIdentity)
{
    d->m_recipientIdentity = recipientIdentity;
}

const std::optional<SharedNotePrivilegeLevel> & SharedNote::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotePrivilegeLevel> & SharedNote::mutablePrivilege()
{
    return d->m_privilege;
}

void SharedNote::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<Timestamp> & SharedNote::serviceCreated() const noexcept
{
    return d->m_serviceCreated;
}

std::optional<Timestamp> & SharedNote::mutableServiceCreated()
{
    return d->m_serviceCreated;
}

void SharedNote::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = serviceCreated;
}

const std::optional<Timestamp> & SharedNote::serviceUpdated() const noexcept
{
    return d->m_serviceUpdated;
}

std::optional<Timestamp> & SharedNote::mutableServiceUpdated()
{
    return d->m_serviceUpdated;
}

void SharedNote::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = serviceUpdated;
}

const std::optional<Timestamp> & SharedNote::serviceAssigned() const noexcept
{
    return d->m_serviceAssigned;
}

std::optional<Timestamp> & SharedNote::mutableServiceAssigned()
{
    return d->m_serviceAssigned;
}

void SharedNote::setServiceAssigned(std::optional<Timestamp> serviceAssigned)
{
    d->m_serviceAssigned = serviceAssigned;
}

void SharedNote::print(QTextStream & strm) const
{
    d->print(strm);
}

bool SharedNote::operator==(const SharedNote & other) const noexcept
{
    return *d == *other.d;
}

bool SharedNote::operator!=(const SharedNote & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
