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

#ifndef QEVERCLOUD_GENERATED_IDENTITYBUILDER
#define QEVERCLOUD_GENERATED_IDENTITYBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/Identity.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT IdentityBuilder
{
public:
    IdentityBuilder();

    IdentityBuilder(IdentityBuilder && other) noexcept;

    ~IdentityBuilder() noexcept;

    IdentityBuilder & operator=(IdentityBuilder && other) noexcept;

    IdentityBuilder & setId(IdentityID id);
    IdentityBuilder & setContact(std::optional<Contact> contact);
    IdentityBuilder & setUserId(std::optional<UserID> userId);
    IdentityBuilder & setDeactivated(std::optional<bool> deactivated);
    IdentityBuilder & setSameBusiness(std::optional<bool> sameBusiness);
    IdentityBuilder & setBlocked(std::optional<bool> blocked);
    IdentityBuilder & setUserConnected(std::optional<bool> userConnected);
    IdentityBuilder & setEventId(std::optional<MessageEventID> eventId);

    [[nodiscard]] Identity build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_IDENTITYBUILDER
