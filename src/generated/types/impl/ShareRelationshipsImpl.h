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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPSIMPL_H
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPSIMPL_H

#include <qevercloud/generated/types/ShareRelationships.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationships::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ShareRelationships::Impl & other) = default;
    Impl(ShareRelationships::Impl && other) noexcept = default;

    ShareRelationships::Impl & operator=(const ShareRelationships::Impl & other) = delete;
    ShareRelationships::Impl & operator=(ShareRelationships::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const ShareRelationships::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const ShareRelationships::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QList<InvitationShareRelationship>> m_invitations;
    std::optional<QList<MemberShareRelationship>> m_memberships;
    std::optional<ShareRelationshipRestrictions> m_invitationRestrictions;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPSIMPL_H