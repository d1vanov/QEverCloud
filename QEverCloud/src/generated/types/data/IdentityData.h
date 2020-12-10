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

#ifndef QEVERCLOUD_GENERATED_IDENTITYDATA_H
#define QEVERCLOUD_GENERATED_IDENTITYDATA_H

#include <generated/types/Identity.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Identity::IdentityData final:
    public QSharedData,
    public Printable
{
public:
    IdentityData() = default;
    IdentityData(const IdentityData & other) = default;
    IdentityData(IdentityData && other) noexcept = default;

    IdentityData & operator=(const IdentityData & other) = delete;
    IdentityData & operator=(IdentityData && other) = delete;

    ~IdentityData() noexcept override = default;

    [[nodiscard]] bool operator==(const IdentityData & other) const noexcept;
    [[nodiscard]] bool operator!=(const IdentityData & other) const noexcept;

    void print(QTextStream & strm) const override;

    IdentityID m_id = 0;
    std::optional<Contact> m_contact;
    std::optional<UserID> m_userId;
    std::optional<bool> m_deactivated;
    std::optional<bool> m_sameBusiness;
    std::optional<bool> m_blocked;
    std::optional<bool> m_userConnected;
    std::optional<MessageEventID> m_eventId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_IDENTITYDATA_H
