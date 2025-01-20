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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSBUILDER
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteInvitationShareRelationship.h>
#include <qevercloud/types/NoteMemberShareRelationship.h>
#include <qevercloud/types/NoteShareRelationshipRestrictions.h>
#include <qevercloud/types/NoteShareRelationships.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteShareRelationshipsBuilder
{
public:
    NoteShareRelationshipsBuilder();

    NoteShareRelationshipsBuilder(NoteShareRelationshipsBuilder && other) noexcept;

    ~NoteShareRelationshipsBuilder() noexcept;

    NoteShareRelationshipsBuilder & operator=(NoteShareRelationshipsBuilder && other) noexcept;

    NoteShareRelationshipsBuilder & setInvitations(std::optional<QList<NoteInvitationShareRelationship>> invitations);
    NoteShareRelationshipsBuilder & setMemberships(std::optional<QList<NoteMemberShareRelationship>> memberships);
    NoteShareRelationshipsBuilder & setInvitationRestrictions(std::optional<NoteShareRelationshipRestrictions> invitationRestrictions);

    [[nodiscard]] NoteShareRelationships build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSBUILDER
