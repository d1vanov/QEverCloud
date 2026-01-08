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

#ifndef QEVERCLOUD_GENERATED_USERPROFILEBUILDER
#define QEVERCLOUD_GENERATED_USERPROFILEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessUserAttributes.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserProfile.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UserProfileBuilder
{
public:
    UserProfileBuilder();

    UserProfileBuilder(UserProfileBuilder && other) noexcept;

    ~UserProfileBuilder() noexcept;

    UserProfileBuilder & operator=(UserProfileBuilder && other) noexcept;

    UserProfileBuilder & setId(std::optional<UserID> id);
    UserProfileBuilder & setName(std::optional<QString> name);
    UserProfileBuilder & setEmail(std::optional<QString> email);
    UserProfileBuilder & setUsername(std::optional<QString> username);
    UserProfileBuilder & setAttributes(std::optional<BusinessUserAttributes> attributes);
    UserProfileBuilder & setJoined(std::optional<Timestamp> joined);
    UserProfileBuilder & setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);
    UserProfileBuilder & setPhotoUrl(std::optional<QString> photoUrl);
    UserProfileBuilder & setRole(std::optional<BusinessUserRole> role);
    UserProfileBuilder & setStatus(std::optional<BusinessUserStatus> status);

    [[nodiscard]] UserProfile build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERPROFILEBUILDER
