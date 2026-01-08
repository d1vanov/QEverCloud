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

#include <qevercloud/types/builders/UserUrlsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserUrlsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<QString> m_userStoreUrl;
    std::optional<QString> m_utilityUrl;
    std::optional<QString> m_messageStoreUrl;
    std::optional<QString> m_userWebSocketUrl;
};

UserUrlsBuilder::UserUrlsBuilder() :
    d(new UserUrlsBuilder::Impl)
{}

UserUrlsBuilder::UserUrlsBuilder(UserUrlsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UserUrlsBuilder::~UserUrlsBuilder() noexcept = default;

UserUrlsBuilder & UserUrlsBuilder::operator=(UserUrlsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = std::move(noteStoreUrl);
    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = std::move(webApiUrlPrefix);
    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setUserStoreUrl(std::optional<QString> userStoreUrl)
{
    d->m_userStoreUrl = std::move(userStoreUrl);
    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setUtilityUrl(std::optional<QString> utilityUrl)
{
    d->m_utilityUrl = std::move(utilityUrl);
    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setMessageStoreUrl(std::optional<QString> messageStoreUrl)
{
    d->m_messageStoreUrl = std::move(messageStoreUrl);
    return *this;
}

UserUrlsBuilder & UserUrlsBuilder::setUserWebSocketUrl(std::optional<QString> userWebSocketUrl)
{
    d->m_userWebSocketUrl = std::move(userWebSocketUrl);
    return *this;
}

UserUrls UserUrlsBuilder::build()
{
    UserUrls result;

    result.setNoteStoreUrl(std::move(d->m_noteStoreUrl));
    result.setWebApiUrlPrefix(std::move(d->m_webApiUrlPrefix));
    result.setUserStoreUrl(std::move(d->m_userStoreUrl));
    result.setUtilityUrl(std::move(d->m_utilityUrl));
    result.setMessageStoreUrl(std::move(d->m_messageStoreUrl));
    result.setUserWebSocketUrl(std::move(d->m_userWebSocketUrl));

    d->m_noteStoreUrl = {};
    d->m_webApiUrlPrefix = {};
    d->m_userStoreUrl = {};
    d->m_utilityUrl = {};
    d->m_messageStoreUrl = {};
    d->m_userWebSocketUrl = {};

    return result;
}

} // namespace qevercloud
