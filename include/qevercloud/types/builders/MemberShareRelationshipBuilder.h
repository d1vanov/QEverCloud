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

#ifndef QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPBUILDER
#define QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/MemberShareRelationship.h>
#include <qevercloud/types/ShareRelationshipRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT MemberShareRelationshipBuilder
{
public:
    MemberShareRelationshipBuilder();

    MemberShareRelationshipBuilder(MemberShareRelationshipBuilder && other) noexcept;

    ~MemberShareRelationshipBuilder() noexcept;

    MemberShareRelationshipBuilder & operator=(MemberShareRelationshipBuilder && other) noexcept;

    MemberShareRelationshipBuilder & setDisplayName(std::optional<QString> displayName);
    MemberShareRelationshipBuilder & setRecipientUserId(std::optional<UserID> recipientUserId);
    MemberShareRelationshipBuilder & setBestPrivilege(std::optional<ShareRelationshipPrivilegeLevel> bestPrivilege);
    MemberShareRelationshipBuilder & setIndividualPrivilege(std::optional<ShareRelationshipPrivilegeLevel> individualPrivilege);
    MemberShareRelationshipBuilder & setRestrictions(std::optional<ShareRelationshipRestrictions> restrictions);
    MemberShareRelationshipBuilder & setSharerUserId(std::optional<UserID> sharerUserId);

    [[nodiscard]] MemberShareRelationship build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPBUILDER
