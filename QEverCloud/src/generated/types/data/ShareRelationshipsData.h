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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPSDATA_H
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPSDATA_H

#include <generated/types/ShareRelationships.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationships::ShareRelationshipsData final:
    public QSharedData,
    public Printable
{
public:
    ShareRelationshipsData() = default;
    ShareRelationshipsData(const ShareRelationshipsData & other) = default;
    ShareRelationshipsData(ShareRelationshipsData && other) noexcept = default;

    ShareRelationshipsData & operator=(const ShareRelationshipsData & other) = delete;
    ShareRelationshipsData & operator=(ShareRelationshipsData && other) = delete;

    ~ShareRelationshipsData() noexcept override = default;

    [[nodiscard]] bool operator==(const ShareRelationshipsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ShareRelationshipsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QList<InvitationShareRelationship>> m_invitations;
    std::optional<QList<MemberShareRelationship>> m_memberships;
    std::optional<ShareRelationshipRestrictions> m_invitationRestrictions;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPSDATA_H
