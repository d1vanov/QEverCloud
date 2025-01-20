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

#ifndef QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPBUILDER
#define QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteMemberShareRelationship.h>
#include <qevercloud/types/NoteShareRelationshipRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteMemberShareRelationshipBuilder
{
public:
    NoteMemberShareRelationshipBuilder();

    NoteMemberShareRelationshipBuilder(NoteMemberShareRelationshipBuilder && other) noexcept;

    ~NoteMemberShareRelationshipBuilder() noexcept;

    NoteMemberShareRelationshipBuilder & operator=(NoteMemberShareRelationshipBuilder && other) noexcept;

    NoteMemberShareRelationshipBuilder & setDisplayName(std::optional<QString> displayName);
    NoteMemberShareRelationshipBuilder & setRecipientUserId(std::optional<UserID> recipientUserId);
    NoteMemberShareRelationshipBuilder & setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);
    NoteMemberShareRelationshipBuilder & setRestrictions(std::optional<NoteShareRelationshipRestrictions> restrictions);
    NoteMemberShareRelationshipBuilder & setSharerUserId(std::optional<UserID> sharerUserId);

    [[nodiscard]] NoteMemberShareRelationship build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPBUILDER
