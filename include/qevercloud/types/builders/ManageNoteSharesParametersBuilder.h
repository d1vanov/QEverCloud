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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/ManageNoteSharesParameters.h>
#include <qevercloud/types/NoteInvitationShareRelationship.h>
#include <qevercloud/types/NoteMemberShareRelationship.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNoteSharesParametersBuilder
{
public:
    ManageNoteSharesParametersBuilder();

    ManageNoteSharesParametersBuilder(ManageNoteSharesParametersBuilder && other) noexcept;

    ~ManageNoteSharesParametersBuilder() noexcept;

    ManageNoteSharesParametersBuilder & operator=(ManageNoteSharesParametersBuilder && other) noexcept;

    ManageNoteSharesParametersBuilder & setNoteGuid(std::optional<QString> noteGuid);
    ManageNoteSharesParametersBuilder & setMembershipsToUpdate(std::optional<QList<NoteMemberShareRelationship>> membershipsToUpdate);
    ManageNoteSharesParametersBuilder & setInvitationsToUpdate(std::optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate);
    ManageNoteSharesParametersBuilder & setMembershipsToUnshare(std::optional<QList<UserID>> membershipsToUnshare);
    ManageNoteSharesParametersBuilder & setInvitationsToUnshare(std::optional<QList<IdentityID>> invitationsToUnshare);

    [[nodiscard]] ManageNoteSharesParameters build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSBUILDER
