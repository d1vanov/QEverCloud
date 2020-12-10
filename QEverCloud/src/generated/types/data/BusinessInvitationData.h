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

#ifndef QEVERCLOUD_GENERATED_BUSINESSINVITATIONDATA_H
#define QEVERCLOUD_GENERATED_BUSINESSINVITATIONDATA_H

#include <generated/types/BusinessInvitation.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessInvitation::BusinessInvitationData final:
    public QSharedData,
    public Printable
{
public:
    BusinessInvitationData() = default;
    BusinessInvitationData(const BusinessInvitationData & other) = default;
    BusinessInvitationData(BusinessInvitationData && other) noexcept = default;

    BusinessInvitationData & operator=(const BusinessInvitationData & other) = delete;
    BusinessInvitationData & operator=(BusinessInvitationData && other) = delete;

    ~BusinessInvitationData() noexcept override = default;

    [[nodiscard]] bool operator==(const BusinessInvitationData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessInvitationData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_businessId;
    std::optional<QString> m_email;
    std::optional<BusinessUserRole> m_role;
    std::optional<BusinessInvitationStatus> m_status;
    std::optional<UserID> m_requesterId;
    std::optional<bool> m_fromWorkChat;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_mostRecentReminder;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSINVITATIONDATA_H
