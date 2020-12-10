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

#ifndef QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTDATA_H
#define QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTDATA_H

#include <generated/types/AuthenticationResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AuthenticationResult::AuthenticationResultData final:
    public QSharedData,
    public Printable
{
public:
    AuthenticationResultData() = default;
    AuthenticationResultData(const AuthenticationResultData & other) = default;
    AuthenticationResultData(AuthenticationResultData && other) noexcept = default;

    AuthenticationResultData & operator=(const AuthenticationResultData & other) = delete;
    AuthenticationResultData & operator=(AuthenticationResultData && other) = delete;

    ~AuthenticationResultData() noexcept override = default;

    [[nodiscard]] bool operator==(const AuthenticationResultData & other) const noexcept;
    [[nodiscard]] bool operator!=(const AuthenticationResultData & other) const noexcept;

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

#endif // QEVERCLOUD_GENERATED_AUTHENTICATIONRESULTDATA_H
