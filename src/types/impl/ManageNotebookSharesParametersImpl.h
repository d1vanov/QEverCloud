/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSIMPL_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSIMPL_H

#include <qevercloud/types/ManageNotebookSharesParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesParameters::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNotebookSharesParameters::Impl & other) = default;
    Impl(ManageNotebookSharesParameters::Impl && other) noexcept = default;

    ManageNotebookSharesParameters::Impl & operator=(const ManageNotebookSharesParameters::Impl & other) = delete;
    ManageNotebookSharesParameters::Impl & operator=(ManageNotebookSharesParameters::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_notebookGuid;
    std::optional<QString> m_inviteMessage;
    std::optional<QList<MemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<InvitationShareRelationship>> m_invitationsToCreateOrUpdate;
    std::optional<QList<UserIdentity>> m_unshares;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSIMPL_H
