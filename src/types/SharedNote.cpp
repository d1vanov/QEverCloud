/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/SharedNote.h>

#include "impl/SharedNoteImpl.h"

namespace qevercloud {

SharedNote::SharedNote() :
    d(new SharedNote::Impl)
{}

SharedNote::SharedNote(const SharedNote & other) :
    d(other.d)
{}

SharedNote::SharedNote(SharedNote && other) noexcept :
    d(std::move(other.d))
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

bool SharedNote::isLocallyModified() const noexcept
{
    return d->m_isLocallyModified;
}

void SharedNote::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
}

bool SharedNote::isLocalOnly() const noexcept
{
    return d->m_isLocalOnly;
}

void SharedNote::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
}

bool SharedNote::isLocallyFavorited() const noexcept
{
    return d->m_isLocallyFavorited;
}

void SharedNote::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
}

const QHash<QString, QVariant> & SharedNote::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & SharedNote::mutableLocalData()
{
    return d->m_localData;
}

void SharedNote::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = localData;
}

const Guid & SharedNote::noteGuid() const noexcept
{
    return d->m_noteGuid;
}

Guid & SharedNote::mutableNoteGuid()
{
    return d->m_noteGuid;
}

void SharedNote::setNoteGuid(Guid noteGuid)
{
    d->m_noteGuid = noteGuid;
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

QTextStream & operator<<(QTextStream & strm, const SharedNote & sharedNote)
{
    strm << static_cast<const Printable&>(sharedNote);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const SharedNote & sharedNote)
{
    dbg << static_cast<const Printable&>(sharedNote);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const SharedNote & sharedNote)
{
    strm << static_cast<const Printable&>(sharedNote);
    return strm;
}

bool operator==(const SharedNote & lhs, const SharedNote & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.isLocallyModified() == rhs.isLocallyModified() &&
        lhs.isLocalOnly() == rhs.isLocalOnly() &&
        lhs.isLocallyFavorited() == rhs.isLocallyFavorited() &&
        lhs.localData() == rhs.localData() &&
        lhs.noteGuid() == rhs.noteGuid() &&
        lhs.sharerUserID() == rhs.sharerUserID() &&
        lhs.recipientIdentity() == rhs.recipientIdentity() &&
        lhs.privilege() == rhs.privilege() &&
        lhs.serviceCreated() == rhs.serviceCreated() &&
        lhs.serviceUpdated() == rhs.serviceUpdated() &&
        lhs.serviceAssigned() == rhs.serviceAssigned();
}

bool operator!=(const SharedNote & lhs, const SharedNote & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
