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

#include <qevercloud/types/builders/IdentityBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN IdentityBuilder::Impl final:
    public QSharedData
{
public:
    IdentityID m_id = 0;
    std::optional<Contact> m_contact;
    std::optional<UserID> m_userId;
    std::optional<bool> m_deactivated;
    std::optional<bool> m_sameBusiness;
    std::optional<bool> m_blocked;
    std::optional<bool> m_userConnected;
    std::optional<MessageEventID> m_eventId;
};

IdentityBuilder::IdentityBuilder() :
    d(new IdentityBuilder::Impl)
{}

IdentityBuilder::IdentityBuilder(IdentityBuilder && other) noexcept :
    d{std::move(other.d)}
{}

IdentityBuilder::~IdentityBuilder() noexcept = default;

IdentityBuilder & IdentityBuilder::operator=(IdentityBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

IdentityBuilder & IdentityBuilder::setId(IdentityID id)
{
    d->m_id = id;
    return *this;
}

IdentityBuilder & IdentityBuilder::setContact(std::optional<Contact> contact)
{
    d->m_contact = std::move(contact);
    return *this;
}

IdentityBuilder & IdentityBuilder::setUserId(std::optional<UserID> userId)
{
    d->m_userId = std::move(userId);
    return *this;
}

IdentityBuilder & IdentityBuilder::setDeactivated(std::optional<bool> deactivated)
{
    d->m_deactivated = std::move(deactivated);
    return *this;
}

IdentityBuilder & IdentityBuilder::setSameBusiness(std::optional<bool> sameBusiness)
{
    d->m_sameBusiness = std::move(sameBusiness);
    return *this;
}

IdentityBuilder & IdentityBuilder::setBlocked(std::optional<bool> blocked)
{
    d->m_blocked = std::move(blocked);
    return *this;
}

IdentityBuilder & IdentityBuilder::setUserConnected(std::optional<bool> userConnected)
{
    d->m_userConnected = std::move(userConnected);
    return *this;
}

IdentityBuilder & IdentityBuilder::setEventId(std::optional<MessageEventID> eventId)
{
    d->m_eventId = std::move(eventId);
    return *this;
}

Identity IdentityBuilder::build()
{
    Identity result;

    result.setId(d->m_id);
    result.setContact(std::move(d->m_contact));
    result.setUserId(std::move(d->m_userId));
    result.setDeactivated(std::move(d->m_deactivated));
    result.setSameBusiness(std::move(d->m_sameBusiness));
    result.setBlocked(std::move(d->m_blocked));
    result.setUserConnected(std::move(d->m_userConnected));
    result.setEventId(std::move(d->m_eventId));

    d->m_id = 0;
    d->m_contact = {};
    d->m_userId = {};
    d->m_deactivated = {};
    d->m_sameBusiness = {};
    d->m_blocked = {};
    d->m_userConnected = {};
    d->m_eventId = {};

    return result;
}

} // namespace qevercloud
