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

#ifndef QEVERCLOUD_GENERATED_IDENTITYIMPL_H
#define QEVERCLOUD_GENERATED_IDENTITYIMPL_H

#include <qevercloud/generated/types/Identity.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Identity::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Identity::Impl & other) = default;
    Impl(Identity::Impl && other) noexcept = default;

    Identity::Impl & operator=(const Identity::Impl & other) = delete;
    Identity::Impl & operator=(Identity::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_IDENTITYIMPL_H
