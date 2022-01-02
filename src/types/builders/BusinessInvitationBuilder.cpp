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

#include <qevercloud/types/builders/BusinessInvitationBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessInvitationBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_businessId;
    std::optional<QString> m_email;
    std::optional<BusinessUserRole> m_role;
    std::optional<BusinessInvitationStatus> m_status;
    std::optional<UserID> m_requesterId;
    std::optional<bool> m_fromWorkChat;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_mostRecentReminder;
};

BusinessInvitationBuilder::BusinessInvitationBuilder() :
    d(new BusinessInvitationBuilder::Impl)
{}

BusinessInvitationBuilder::BusinessInvitationBuilder(BusinessInvitationBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BusinessInvitationBuilder::~BusinessInvitationBuilder() noexcept = default;

BusinessInvitationBuilder & BusinessInvitationBuilder::operator=(BusinessInvitationBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = std::move(businessId);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = std::move(role);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setStatus(std::optional<BusinessInvitationStatus> status)
{
    d->m_status = std::move(status);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setRequesterId(std::optional<UserID> requesterId)
{
    d->m_requesterId = std::move(requesterId);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setFromWorkChat(std::optional<bool> fromWorkChat)
{
    d->m_fromWorkChat = std::move(fromWorkChat);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setCreated(std::optional<Timestamp> created)
{
    d->m_created = std::move(created);
    return *this;
}

BusinessInvitationBuilder & BusinessInvitationBuilder::setMostRecentReminder(std::optional<Timestamp> mostRecentReminder)
{
    d->m_mostRecentReminder = std::move(mostRecentReminder);
    return *this;
}

BusinessInvitation BusinessInvitationBuilder::build()
{
    BusinessInvitation result;

    result.setBusinessId(std::move(d->m_businessId));
    result.setEmail(std::move(d->m_email));
    result.setRole(std::move(d->m_role));
    result.setStatus(std::move(d->m_status));
    result.setRequesterId(std::move(d->m_requesterId));
    result.setFromWorkChat(std::move(d->m_fromWorkChat));
    result.setCreated(std::move(d->m_created));
    result.setMostRecentReminder(std::move(d->m_mostRecentReminder));

    d->m_businessId = {};
    d->m_email = {};
    d->m_role = {};
    d->m_status = {};
    d->m_requesterId = {};
    d->m_fromWorkChat = {};
    d->m_created = {};
    d->m_mostRecentReminder = {};

    return result;
}

} // namespace qevercloud
