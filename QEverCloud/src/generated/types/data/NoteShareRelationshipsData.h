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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSDATA_H
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSDATA_H

#include <generated/types/NoteShareRelationships.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteShareRelationships::NoteShareRelationshipsData final:
    public QSharedData,
    public Printable
{
public:
    NoteShareRelationshipsData() = default;
    NoteShareRelationshipsData(const NoteShareRelationshipsData & other) = default;
    NoteShareRelationshipsData(NoteShareRelationshipsData && other) noexcept = default;

    NoteShareRelationshipsData & operator=(const NoteShareRelationshipsData & other) = delete;
    NoteShareRelationshipsData & operator=(NoteShareRelationshipsData && other) = delete;

    ~NoteShareRelationshipsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteShareRelationshipsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteShareRelationshipsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QList<NoteInvitationShareRelationship>> m_invitations;
    std::optional<QList<NoteMemberShareRelationship>> m_memberships;
    std::optional<NoteShareRelationshipRestrictions> m_invitationRestrictions;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPSDATA_H
