/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/Identity.h>

#include "impl/IdentityImpl.h"

namespace qevercloud {

Identity::Identity() :
    d(new Identity::Impl)
{}

Identity::Identity(const Identity & other) :
    d(other.d)
{}

Identity::Identity(Identity && other) noexcept :
    d(std::move(other.d))
{}

Identity::~Identity() noexcept {}

Identity & Identity::operator=(const Identity & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Identity & Identity::operator=(Identity && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

IdentityID Identity::id() const noexcept
{
    return d->m_id;
}

void Identity::setId(IdentityID id)
{
    d->m_id = id;
}

const std::optional<Contact> & Identity::contact() const noexcept
{
    return d->m_contact;
}

std::optional<Contact> & Identity::mutableContact()
{
    return d->m_contact;
}

void Identity::setContact(std::optional<Contact> contact)
{
    d->m_contact = std::move(contact);
}

const std::optional<UserID> & Identity::userId() const noexcept
{
    return d->m_userId;
}

std::optional<UserID> & Identity::mutableUserId()
{
    return d->m_userId;
}

void Identity::setUserId(std::optional<UserID> userId)
{
    d->m_userId = userId;
}

const std::optional<bool> & Identity::deactivated() const noexcept
{
    return d->m_deactivated;
}

std::optional<bool> & Identity::mutableDeactivated()
{
    return d->m_deactivated;
}

void Identity::setDeactivated(std::optional<bool> deactivated)
{
    d->m_deactivated = deactivated;
}

const std::optional<bool> & Identity::sameBusiness() const noexcept
{
    return d->m_sameBusiness;
}

std::optional<bool> & Identity::mutableSameBusiness()
{
    return d->m_sameBusiness;
}

void Identity::setSameBusiness(std::optional<bool> sameBusiness)
{
    d->m_sameBusiness = sameBusiness;
}

const std::optional<bool> & Identity::blocked() const noexcept
{
    return d->m_blocked;
}

std::optional<bool> & Identity::mutableBlocked()
{
    return d->m_blocked;
}

void Identity::setBlocked(std::optional<bool> blocked)
{
    d->m_blocked = blocked;
}

const std::optional<bool> & Identity::userConnected() const noexcept
{
    return d->m_userConnected;
}

std::optional<bool> & Identity::mutableUserConnected()
{
    return d->m_userConnected;
}

void Identity::setUserConnected(std::optional<bool> userConnected)
{
    d->m_userConnected = userConnected;
}

const std::optional<MessageEventID> & Identity::eventId() const noexcept
{
    return d->m_eventId;
}

std::optional<MessageEventID> & Identity::mutableEventId()
{
    return d->m_eventId;
}

void Identity::setEventId(std::optional<MessageEventID> eventId)
{
    d->m_eventId = eventId;
}

void Identity::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const Identity & identity)
{
    strm << static_cast<const Printable&>(identity);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Identity & identity)
{
    dbg << static_cast<const Printable&>(identity);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Identity & identity)
{
    strm << static_cast<const Printable&>(identity);
    return strm;
}

bool operator==(const Identity & lhs, const Identity & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.id() == rhs.id() &&
        lhs.contact() == rhs.contact() &&
        lhs.userId() == rhs.userId() &&
        lhs.deactivated() == rhs.deactivated() &&
        lhs.sameBusiness() == rhs.sameBusiness() &&
        lhs.blocked() == rhs.blocked() &&
        lhs.userConnected() == rhs.userConnected() &&
        lhs.eventId() == rhs.eventId();
}

bool operator!=(const Identity & lhs, const Identity & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
