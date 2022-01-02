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

#ifndef QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPBUILDER
#define QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/InvitationShareRelationship.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserIdentity.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT InvitationShareRelationshipBuilder
{
public:
    InvitationShareRelationshipBuilder();

    InvitationShareRelationshipBuilder(InvitationShareRelationshipBuilder && other) noexcept;

    ~InvitationShareRelationshipBuilder() noexcept;

    InvitationShareRelationshipBuilder & operator=(InvitationShareRelationshipBuilder && other) noexcept;

    InvitationShareRelationshipBuilder & setDisplayName(std::optional<QString> displayName);
    InvitationShareRelationshipBuilder & setRecipientUserIdentity(std::optional<UserIdentity> recipientUserIdentity);
    InvitationShareRelationshipBuilder & setPrivilege(std::optional<ShareRelationshipPrivilegeLevel> privilege);
    InvitationShareRelationshipBuilder & setSharerUserId(std::optional<UserID> sharerUserId);

    [[nodiscard]] InvitationShareRelationship build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_INVITATIONSHARERELATIONSHIPBUILDER
