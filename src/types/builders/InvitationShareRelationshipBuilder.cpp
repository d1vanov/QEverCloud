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

#include <qevercloud/types/builders/InvitationShareRelationshipBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN InvitationShareRelationshipBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_displayName;
    std::optional<UserIdentity> m_recipientUserIdentity;
    std::optional<ShareRelationshipPrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

InvitationShareRelationshipBuilder::InvitationShareRelationshipBuilder() :
    d(new InvitationShareRelationshipBuilder::Impl)
{}

InvitationShareRelationshipBuilder::InvitationShareRelationshipBuilder(InvitationShareRelationshipBuilder && other) noexcept :
    d{std::move(other.d)}
{}

InvitationShareRelationshipBuilder::~InvitationShareRelationshipBuilder() noexcept = default;

InvitationShareRelationshipBuilder & InvitationShareRelationshipBuilder::operator=(InvitationShareRelationshipBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

InvitationShareRelationshipBuilder & InvitationShareRelationshipBuilder::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = std::move(displayName);
    return *this;
}

InvitationShareRelationshipBuilder & InvitationShareRelationshipBuilder::setRecipientUserIdentity(std::optional<UserIdentity> recipientUserIdentity)
{
    d->m_recipientUserIdentity = std::move(recipientUserIdentity);
    return *this;
}

InvitationShareRelationshipBuilder & InvitationShareRelationshipBuilder::setPrivilege(std::optional<ShareRelationshipPrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

InvitationShareRelationshipBuilder & InvitationShareRelationshipBuilder::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = std::move(sharerUserId);
    return *this;
}

InvitationShareRelationship InvitationShareRelationshipBuilder::build()
{
    InvitationShareRelationship result;

    result.setDisplayName(std::move(d->m_displayName));
    result.setRecipientUserIdentity(std::move(d->m_recipientUserIdentity));
    result.setPrivilege(std::move(d->m_privilege));
    result.setSharerUserId(std::move(d->m_sharerUserId));

    d->m_displayName = {};
    d->m_recipientUserIdentity = {};
    d->m_privilege = {};
    d->m_sharerUserId = {};

    return result;
}

} // namespace qevercloud
