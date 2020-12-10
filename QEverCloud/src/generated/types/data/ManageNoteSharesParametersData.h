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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSDATA_H

#include <generated/types/ManageNoteSharesParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesParameters::ManageNoteSharesParametersData final:
    public QSharedData,
    public Printable
{
public:
    ManageNoteSharesParametersData() = default;
    ManageNoteSharesParametersData(const ManageNoteSharesParametersData & other) = default;
    ManageNoteSharesParametersData(ManageNoteSharesParametersData && other) noexcept = default;

    ManageNoteSharesParametersData & operator=(const ManageNoteSharesParametersData & other) = delete;
    ManageNoteSharesParametersData & operator=(ManageNoteSharesParametersData && other) = delete;

    ~ManageNoteSharesParametersData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNoteSharesParametersData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNoteSharesParametersData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteGuid;
    std::optional<QList<NoteMemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<NoteInvitationShareRelationship>> m_invitationsToUpdate;
    std::optional<QList<UserID>> m_membershipsToUnshare;
    std::optional<QList<IdentityID>> m_invitationsToUnshare;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSDATA_H
