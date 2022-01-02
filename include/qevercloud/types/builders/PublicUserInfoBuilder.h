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

#ifndef QEVERCLOUD_GENERATED_PUBLICUSERINFOBUILDER
#define QEVERCLOUD_GENERATED_PUBLICUSERINFOBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/PublicUserInfo.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT PublicUserInfoBuilder
{
public:
    PublicUserInfoBuilder();

    PublicUserInfoBuilder(PublicUserInfoBuilder && other) noexcept;

    ~PublicUserInfoBuilder() noexcept;

    PublicUserInfoBuilder & operator=(PublicUserInfoBuilder && other) noexcept;

    PublicUserInfoBuilder & setUserId(UserID userId);
    PublicUserInfoBuilder & setServiceLevel(std::optional<ServiceLevel> serviceLevel);
    PublicUserInfoBuilder & setUsername(std::optional<QString> username);
    PublicUserInfoBuilder & setNoteStoreUrl(std::optional<QString> noteStoreUrl);
    PublicUserInfoBuilder & setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);

    [[nodiscard]] PublicUserInfo build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLICUSERINFOBUILDER
