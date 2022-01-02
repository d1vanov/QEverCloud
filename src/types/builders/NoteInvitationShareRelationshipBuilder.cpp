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

#include <qevercloud/types/builders/NoteInvitationShareRelationshipBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteInvitationShareRelationshipBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_displayName;
    std::optional<IdentityID> m_recipientIdentityId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<UserID> m_sharerUserId;
};

NoteInvitationShareRelationshipBuilder::NoteInvitationShareRelationshipBuilder() :
    d(new NoteInvitationShareRelationshipBuilder::Impl)
{}

NoteInvitationShareRelationshipBuilder::NoteInvitationShareRelationshipBuilder(NoteInvitationShareRelationshipBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteInvitationShareRelationshipBuilder::~NoteInvitationShareRelationshipBuilder() noexcept = default;

NoteInvitationShareRelationshipBuilder & NoteInvitationShareRelationshipBuilder::operator=(NoteInvitationShareRelationshipBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteInvitationShareRelationshipBuilder & NoteInvitationShareRelationshipBuilder::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = std::move(displayName);
    return *this;
}

NoteInvitationShareRelationshipBuilder & NoteInvitationShareRelationshipBuilder::setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId)
{
    d->m_recipientIdentityId = std::move(recipientIdentityId);
    return *this;
}

NoteInvitationShareRelationshipBuilder & NoteInvitationShareRelationshipBuilder::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

NoteInvitationShareRelationshipBuilder & NoteInvitationShareRelationshipBuilder::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = std::move(sharerUserId);
    return *this;
}

NoteInvitationShareRelationship NoteInvitationShareRelationshipBuilder::build()
{
    NoteInvitationShareRelationship result;

    result.setDisplayName(std::move(d->m_displayName));
    result.setRecipientIdentityId(std::move(d->m_recipientIdentityId));
    result.setPrivilege(std::move(d->m_privilege));
    result.setSharerUserId(std::move(d->m_sharerUserId));

    d->m_displayName = {};
    d->m_recipientIdentityId = {};
    d->m_privilege = {};
    d->m_sharerUserId = {};

    return result;
}

} // namespace qevercloud
