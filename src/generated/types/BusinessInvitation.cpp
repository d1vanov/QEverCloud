/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/generated/types/BusinessInvitation.h>

#include "impl/BusinessInvitationImpl.h"

namespace qevercloud {

BusinessInvitation::BusinessInvitation() :
    d(new BusinessInvitation::Impl)
 {}

BusinessInvitation::BusinessInvitation(const BusinessInvitation & other) :
    d(other.d)
{}

BusinessInvitation::BusinessInvitation(BusinessInvitation && other) noexcept :
    d(std::move(other.d))
{}

BusinessInvitation::~BusinessInvitation() noexcept {}

BusinessInvitation & BusinessInvitation::operator=(const BusinessInvitation & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BusinessInvitation & BusinessInvitation::operator=(BusinessInvitation && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & BusinessInvitation::businessId() const noexcept
{
    return d->m_businessId;
}

std::optional<qint32> & BusinessInvitation::mutableBusinessId()
{
    return d->m_businessId;
}

void BusinessInvitation::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = businessId;
}

const std::optional<QString> & BusinessInvitation::email() const noexcept
{
    return d->m_email;
}

void BusinessInvitation::setEmail(std::optional<QString> email)
{
    d->m_email = email;
}

const std::optional<BusinessUserRole> & BusinessInvitation::role() const noexcept
{
    return d->m_role;
}

std::optional<BusinessUserRole> & BusinessInvitation::mutableRole()
{
    return d->m_role;
}

void BusinessInvitation::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = role;
}

const std::optional<BusinessInvitationStatus> & BusinessInvitation::status() const noexcept
{
    return d->m_status;
}

std::optional<BusinessInvitationStatus> & BusinessInvitation::mutableStatus()
{
    return d->m_status;
}

void BusinessInvitation::setStatus(std::optional<BusinessInvitationStatus> status)
{
    d->m_status = status;
}

const std::optional<UserID> & BusinessInvitation::requesterId() const noexcept
{
    return d->m_requesterId;
}

std::optional<UserID> & BusinessInvitation::mutableRequesterId()
{
    return d->m_requesterId;
}

void BusinessInvitation::setRequesterId(std::optional<UserID> requesterId)
{
    d->m_requesterId = requesterId;
}

const std::optional<bool> & BusinessInvitation::fromWorkChat() const noexcept
{
    return d->m_fromWorkChat;
}

std::optional<bool> & BusinessInvitation::mutableFromWorkChat()
{
    return d->m_fromWorkChat;
}

void BusinessInvitation::setFromWorkChat(std::optional<bool> fromWorkChat)
{
    d->m_fromWorkChat = fromWorkChat;
}

const std::optional<Timestamp> & BusinessInvitation::created() const noexcept
{
    return d->m_created;
}

std::optional<Timestamp> & BusinessInvitation::mutableCreated()
{
    return d->m_created;
}

void BusinessInvitation::setCreated(std::optional<Timestamp> created)
{
    d->m_created = created;
}

const std::optional<Timestamp> & BusinessInvitation::mostRecentReminder() const noexcept
{
    return d->m_mostRecentReminder;
}

std::optional<Timestamp> & BusinessInvitation::mutableMostRecentReminder()
{
    return d->m_mostRecentReminder;
}

void BusinessInvitation::setMostRecentReminder(std::optional<Timestamp> mostRecentReminder)
{
    d->m_mostRecentReminder = mostRecentReminder;
}

void BusinessInvitation::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const BusinessInvitation & lhs, const BusinessInvitation & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.businessId() == rhs.businessId() &&
        lhs.email() == rhs.email() &&
        lhs.role() == rhs.role() &&
        lhs.status() == rhs.status() &&
        lhs.requesterId() == rhs.requesterId() &&
        lhs.fromWorkChat() == rhs.fromWorkChat() &&
        lhs.created() == rhs.created() &&
        lhs.mostRecentReminder() == rhs.mostRecentReminder();
}

bool operator!=(const BusinessInvitation & lhs, const BusinessInvitation & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
