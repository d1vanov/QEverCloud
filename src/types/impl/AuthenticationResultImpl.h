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

#ifndef QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTIMPL
#define QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTIMPL

#include <qevercloud/types/AuthenticationResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AuthenticationResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const AuthenticationResult::Impl & other) = default;
    Impl(AuthenticationResult::Impl && other) noexcept = default;

    AuthenticationResult::Impl & operator=(const AuthenticationResult::Impl & other) = delete;
    AuthenticationResult::Impl & operator=(AuthenticationResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    Timestamp m_currentTime = 0;
    QString m_authenticationToken;
    Timestamp m_expiration = 0;
    std::optional<User> m_user;
    std::optional<PublicUserInfo> m_publicUserInfo;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<bool> m_secondFactorRequired;
    std::optional<QString> m_secondFactorDeliveryHint;
    std::optional<UserUrls> m_urls;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTIMPL
