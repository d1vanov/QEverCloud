/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSDATA_H

#include <generated/types/ManageNotebookSharesParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesParameters::ManageNotebookSharesParametersData final:
    public QSharedData,
    public Printable
{
public:
    ManageNotebookSharesParametersData() = default;
    ManageNotebookSharesParametersData(const ManageNotebookSharesParametersData & other) = default;
    ManageNotebookSharesParametersData(ManageNotebookSharesParametersData && other) noexcept = default;

    ManageNotebookSharesParametersData & operator=(const ManageNotebookSharesParametersData & other) = delete;
    ManageNotebookSharesParametersData & operator=(ManageNotebookSharesParametersData && other) = delete;

    ~ManageNotebookSharesParametersData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNotebookSharesParametersData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesParametersData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_notebookGuid;
    std::optional<QString> m_inviteMessage;
    std::optional<QList<MemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<InvitationShareRelationship>> m_invitationsToCreateOrUpdate;
    std::optional<QList<UserIdentity>> m_unshares;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESPARAMETERSDATA_H
