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

#ifndef QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTBUILDER
#define QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/AuthenticationResult.h>
#include <qevercloud/types/PublicUserInfo.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/User.h>
#include <qevercloud/types/UserUrls.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT AuthenticationResultBuilder
{
public:
    AuthenticationResultBuilder();

    AuthenticationResultBuilder(AuthenticationResultBuilder && other) noexcept;

    ~AuthenticationResultBuilder() noexcept;

    AuthenticationResultBuilder & operator=(AuthenticationResultBuilder && other) noexcept;

    AuthenticationResultBuilder & setCurrentTime(Timestamp currentTime);
    AuthenticationResultBuilder & setAuthenticationToken(QString authenticationToken);
    AuthenticationResultBuilder & setExpiration(Timestamp expiration);
    AuthenticationResultBuilder & setUser(std::optional<User> user);
    AuthenticationResultBuilder & setPublicUserInfo(std::optional<PublicUserInfo> publicUserInfo);
    AuthenticationResultBuilder & setNoteStoreUrl(std::optional<QString> noteStoreUrl);
    AuthenticationResultBuilder & setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);
    AuthenticationResultBuilder & setSecondFactorRequired(std::optional<bool> secondFactorRequired);
    AuthenticationResultBuilder & setSecondFactorDeliveryHint(std::optional<QString> secondFactorDeliveryHint);
    AuthenticationResultBuilder & setUrls(std::optional<UserUrls> urls);

    [[nodiscard]] AuthenticationResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTBUILDER
