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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSIMPL
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSIMPL

#include <qevercloud/types/ManageNoteSharesParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesParameters::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNoteSharesParameters::Impl & other) = default;
    Impl(ManageNoteSharesParameters::Impl && other) noexcept = default;

    ManageNoteSharesParameters::Impl & operator=(const ManageNoteSharesParameters::Impl & other) = delete;
    ManageNoteSharesParameters::Impl & operator=(ManageNoteSharesParameters::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteGuid;
    std::optional<QList<NoteMemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<NoteInvitationShareRelationship>> m_invitationsToUpdate;
    std::optional<QList<UserID>> m_membershipsToUnshare;
    std::optional<QList<IdentityID>> m_invitationsToUnshare;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESPARAMETERSIMPL
