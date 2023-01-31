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

#include <qevercloud/types/builders/NoteMemberShareRelationshipBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteMemberShareRelationshipBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<NoteShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

NoteMemberShareRelationshipBuilder::NoteMemberShareRelationshipBuilder() :
    d(new NoteMemberShareRelationshipBuilder::Impl)
{}

NoteMemberShareRelationshipBuilder::NoteMemberShareRelationshipBuilder(NoteMemberShareRelationshipBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteMemberShareRelationshipBuilder::~NoteMemberShareRelationshipBuilder() noexcept = default;

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::operator=(NoteMemberShareRelationshipBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = std::move(displayName);
    return *this;
}

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = std::move(recipientUserId);
    return *this;
}

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::setRestrictions(std::optional<NoteShareRelationshipRestrictions> restrictions)
{
    d->m_restrictions = std::move(restrictions);
    return *this;
}

NoteMemberShareRelationshipBuilder & NoteMemberShareRelationshipBuilder::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = std::move(sharerUserId);
    return *this;
}

NoteMemberShareRelationship NoteMemberShareRelationshipBuilder::build()
{
    NoteMemberShareRelationship result;

    result.setDisplayName(std::move(d->m_displayName));
    result.setRecipientUserId(std::move(d->m_recipientUserId));
    result.setPrivilege(std::move(d->m_privilege));
    result.setRestrictions(std::move(d->m_restrictions));
    result.setSharerUserId(std::move(d->m_sharerUserId));

    d->m_displayName = {};
    d->m_recipientUserId = {};
    d->m_privilege = {};
    d->m_restrictions = {};
    d->m_sharerUserId = {};

    return result;
}

} // namespace qevercloud
