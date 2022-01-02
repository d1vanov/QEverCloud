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

#ifndef QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPBUILDER
#define QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteInvitationShareRelationship.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteInvitationShareRelationshipBuilder
{
public:
    NoteInvitationShareRelationshipBuilder();

    NoteInvitationShareRelationshipBuilder(NoteInvitationShareRelationshipBuilder && other) noexcept;

    ~NoteInvitationShareRelationshipBuilder() noexcept;

    NoteInvitationShareRelationshipBuilder & operator=(NoteInvitationShareRelationshipBuilder && other) noexcept;

    NoteInvitationShareRelationshipBuilder & setDisplayName(std::optional<QString> displayName);
    NoteInvitationShareRelationshipBuilder & setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId);
    NoteInvitationShareRelationshipBuilder & setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);
    NoteInvitationShareRelationshipBuilder & setSharerUserId(std::optional<UserID> sharerUserId);

    [[nodiscard]] NoteInvitationShareRelationship build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEINVITATIONSHARERELATIONSHIPBUILDER
