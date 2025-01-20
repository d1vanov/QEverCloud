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

#include <qevercloud/types/builders/PublicUserInfoBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN PublicUserInfoBuilder::Impl final:
    public QSharedData
{
public:
    UserID m_userId = 0;
    std::optional<ServiceLevel> m_serviceLevel;
    std::optional<QString> m_username;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
};

PublicUserInfoBuilder::PublicUserInfoBuilder() :
    d(new PublicUserInfoBuilder::Impl)
{}

PublicUserInfoBuilder::PublicUserInfoBuilder(PublicUserInfoBuilder && other) noexcept :
    d{std::move(other.d)}
{}

PublicUserInfoBuilder::~PublicUserInfoBuilder() noexcept = default;

PublicUserInfoBuilder & PublicUserInfoBuilder::operator=(PublicUserInfoBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

PublicUserInfoBuilder & PublicUserInfoBuilder::setUserId(UserID userId)
{
    d->m_userId = userId;
    return *this;
}

PublicUserInfoBuilder & PublicUserInfoBuilder::setServiceLevel(std::optional<ServiceLevel> serviceLevel)
{
    d->m_serviceLevel = std::move(serviceLevel);
    return *this;
}

PublicUserInfoBuilder & PublicUserInfoBuilder::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
    return *this;
}

PublicUserInfoBuilder & PublicUserInfoBuilder::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = std::move(noteStoreUrl);
    return *this;
}

PublicUserInfoBuilder & PublicUserInfoBuilder::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = std::move(webApiUrlPrefix);
    return *this;
}

PublicUserInfo PublicUserInfoBuilder::build()
{
    PublicUserInfo result;

    result.setUserId(d->m_userId);
    result.setServiceLevel(std::move(d->m_serviceLevel));
    result.setUsername(std::move(d->m_username));
    result.setNoteStoreUrl(std::move(d->m_noteStoreUrl));
    result.setWebApiUrlPrefix(std::move(d->m_webApiUrlPrefix));

    d->m_userId = 0;
    d->m_serviceLevel = {};
    d->m_username = {};
    d->m_noteStoreUrl = {};
    d->m_webApiUrlPrefix = {};

    return result;
}

} // namespace qevercloud
