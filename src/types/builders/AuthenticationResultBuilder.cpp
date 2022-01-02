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

#include <qevercloud/types/builders/AuthenticationResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AuthenticationResultBuilder::Impl final:
    public QSharedData
{
public:
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

AuthenticationResultBuilder::AuthenticationResultBuilder() :
    d(new AuthenticationResultBuilder::Impl)
{}

AuthenticationResultBuilder::AuthenticationResultBuilder(AuthenticationResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

AuthenticationResultBuilder::~AuthenticationResultBuilder() noexcept = default;

AuthenticationResultBuilder & AuthenticationResultBuilder::operator=(AuthenticationResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setAuthenticationToken(QString authenticationToken)
{
    d->m_authenticationToken = std::move(authenticationToken);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setExpiration(Timestamp expiration)
{
    d->m_expiration = expiration;
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setUser(std::optional<User> user)
{
    d->m_user = std::move(user);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setPublicUserInfo(std::optional<PublicUserInfo> publicUserInfo)
{
    d->m_publicUserInfo = std::move(publicUserInfo);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = std::move(noteStoreUrl);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = std::move(webApiUrlPrefix);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setSecondFactorRequired(std::optional<bool> secondFactorRequired)
{
    d->m_secondFactorRequired = std::move(secondFactorRequired);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setSecondFactorDeliveryHint(std::optional<QString> secondFactorDeliveryHint)
{
    d->m_secondFactorDeliveryHint = std::move(secondFactorDeliveryHint);
    return *this;
}

AuthenticationResultBuilder & AuthenticationResultBuilder::setUrls(std::optional<UserUrls> urls)
{
    d->m_urls = std::move(urls);
    return *this;
}

AuthenticationResult AuthenticationResultBuilder::build()
{
    AuthenticationResult result;

    result.setCurrentTime(d->m_currentTime);
    result.setAuthenticationToken(std::move(d->m_authenticationToken));
    result.setExpiration(d->m_expiration);
    result.setUser(std::move(d->m_user));
    result.setPublicUserInfo(std::move(d->m_publicUserInfo));
    result.setNoteStoreUrl(std::move(d->m_noteStoreUrl));
    result.setWebApiUrlPrefix(std::move(d->m_webApiUrlPrefix));
    result.setSecondFactorRequired(std::move(d->m_secondFactorRequired));
    result.setSecondFactorDeliveryHint(std::move(d->m_secondFactorDeliveryHint));
    result.setUrls(std::move(d->m_urls));

    d->m_currentTime = 0;
    d->m_authenticationToken = QString{};
    d->m_expiration = 0;
    d->m_user = {};
    d->m_publicUserInfo = {};
    d->m_noteStoreUrl = {};
    d->m_webApiUrlPrefix = {};
    d->m_secondFactorRequired = {};
    d->m_secondFactorDeliveryHint = {};
    d->m_urls = {};

    return result;
}

} // namespace qevercloud
