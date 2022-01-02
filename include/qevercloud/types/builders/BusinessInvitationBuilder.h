/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_BUSINESSINVITATIONBUILDER
#define QEVERCLOUD_GENERATED_BUSINESSINVITATIONBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessInvitation.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT BusinessInvitationBuilder
{
public:
    BusinessInvitationBuilder();

    BusinessInvitationBuilder(BusinessInvitationBuilder && other) noexcept;

    ~BusinessInvitationBuilder() noexcept;

    BusinessInvitationBuilder & operator=(BusinessInvitationBuilder && other) noexcept;

    BusinessInvitationBuilder & setBusinessId(std::optional<qint32> businessId);
    BusinessInvitationBuilder & setEmail(std::optional<QString> email);
    BusinessInvitationBuilder & setRole(std::optional<BusinessUserRole> role);
    BusinessInvitationBuilder & setStatus(std::optional<BusinessInvitationStatus> status);
    BusinessInvitationBuilder & setRequesterId(std::optional<UserID> requesterId);
    BusinessInvitationBuilder & setFromWorkChat(std::optional<bool> fromWorkChat);
    BusinessInvitationBuilder & setCreated(std::optional<Timestamp> created);
    BusinessInvitationBuilder & setMostRecentReminder(std::optional<Timestamp> mostRecentReminder);

    [[nodiscard]] BusinessInvitation build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSINVITATIONBUILDER
