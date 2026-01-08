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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPSBUILDER
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/InvitationShareRelationship.h>
#include <qevercloud/types/MemberShareRelationship.h>
#include <qevercloud/types/ShareRelationshipRestrictions.h>
#include <qevercloud/types/ShareRelationships.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ShareRelationshipsBuilder
{
public:
    ShareRelationshipsBuilder();

    ShareRelationshipsBuilder(ShareRelationshipsBuilder && other) noexcept;

    ~ShareRelationshipsBuilder() noexcept;

    ShareRelationshipsBuilder & operator=(ShareRelationshipsBuilder && other) noexcept;

    ShareRelationshipsBuilder & setInvitations(std::optional<QList<InvitationShareRelationship>> invitations);
    ShareRelationshipsBuilder & setMemberships(std::optional<QList<MemberShareRelationship>> memberships);
    ShareRelationshipsBuilder & setInvitationRestrictions(std::optional<ShareRelationshipRestrictions> invitationRestrictions);

    [[nodiscard]] ShareRelationships build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPSBUILDER
