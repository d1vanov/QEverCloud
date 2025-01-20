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

#ifndef QEVERCLOUD_GENERATED_USERURLSBUILDER
#define QEVERCLOUD_GENERATED_USERURLSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserUrls.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UserUrlsBuilder
{
public:
    UserUrlsBuilder();

    UserUrlsBuilder(UserUrlsBuilder && other) noexcept;

    ~UserUrlsBuilder() noexcept;

    UserUrlsBuilder & operator=(UserUrlsBuilder && other) noexcept;

    UserUrlsBuilder & setNoteStoreUrl(std::optional<QString> noteStoreUrl);
    UserUrlsBuilder & setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);
    UserUrlsBuilder & setUserStoreUrl(std::optional<QString> userStoreUrl);
    UserUrlsBuilder & setUtilityUrl(std::optional<QString> utilityUrl);
    UserUrlsBuilder & setMessageStoreUrl(std::optional<QString> messageStoreUrl);
    UserUrlsBuilder & setUserWebSocketUrl(std::optional<QString> userWebSocketUrl);

    [[nodiscard]] UserUrls build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERURLSBUILDER
