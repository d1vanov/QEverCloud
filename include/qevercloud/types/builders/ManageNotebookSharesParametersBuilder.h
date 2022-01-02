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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/InvitationShareRelationship.h>
#include <qevercloud/types/ManageNotebookSharesParameters.h>
#include <qevercloud/types/MemberShareRelationship.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserIdentity.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNotebookSharesParametersBuilder
{
public:
    ManageNotebookSharesParametersBuilder();

    ManageNotebookSharesParametersBuilder(ManageNotebookSharesParametersBuilder && other) noexcept;

    ~ManageNotebookSharesParametersBuilder() noexcept;

    ManageNotebookSharesParametersBuilder & operator=(ManageNotebookSharesParametersBuilder && other) noexcept;

    ManageNotebookSharesParametersBuilder & setNotebookGuid(std::optional<QString> notebookGuid);
    ManageNotebookSharesParametersBuilder & setInviteMessage(std::optional<QString> inviteMessage);
    ManageNotebookSharesParametersBuilder & setMembershipsToUpdate(std::optional<QList<MemberShareRelationship>> membershipsToUpdate);
    ManageNotebookSharesParametersBuilder & setInvitationsToCreateOrUpdate(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate);
    ManageNotebookSharesParametersBuilder & setUnshares(std::optional<QList<UserIdentity>> unshares);

    [[nodiscard]] ManageNotebookSharesParameters build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSBUILDER
