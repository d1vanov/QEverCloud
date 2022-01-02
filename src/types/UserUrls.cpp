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

#include <qevercloud/types/UserUrls.h>

#include "impl/UserUrlsImpl.h"

namespace qevercloud {

UserUrls::UserUrls() :
    d(new UserUrls::Impl)
{}

UserUrls::UserUrls(const UserUrls & other) :
    d(other.d)
{}

UserUrls::UserUrls(UserUrls && other) noexcept :
    d(std::move(other.d))
{}

UserUrls::~UserUrls() noexcept {}

UserUrls & UserUrls::operator=(const UserUrls & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

UserUrls & UserUrls::operator=(UserUrls && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & UserUrls::noteStoreUrl() const noexcept
{
    return d->m_noteStoreUrl;
}

void UserUrls::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = noteStoreUrl;
}

const std::optional<QString> & UserUrls::webApiUrlPrefix() const noexcept
{
    return d->m_webApiUrlPrefix;
}

void UserUrls::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = webApiUrlPrefix;
}

const std::optional<QString> & UserUrls::userStoreUrl() const noexcept
{
    return d->m_userStoreUrl;
}

void UserUrls::setUserStoreUrl(std::optional<QString> userStoreUrl)
{
    d->m_userStoreUrl = userStoreUrl;
}

const std::optional<QString> & UserUrls::utilityUrl() const noexcept
{
    return d->m_utilityUrl;
}

void UserUrls::setUtilityUrl(std::optional<QString> utilityUrl)
{
    d->m_utilityUrl = utilityUrl;
}

const std::optional<QString> & UserUrls::messageStoreUrl() const noexcept
{
    return d->m_messageStoreUrl;
}

void UserUrls::setMessageStoreUrl(std::optional<QString> messageStoreUrl)
{
    d->m_messageStoreUrl = messageStoreUrl;
}

const std::optional<QString> & UserUrls::userWebSocketUrl() const noexcept
{
    return d->m_userWebSocketUrl;
}

void UserUrls::setUserWebSocketUrl(std::optional<QString> userWebSocketUrl)
{
    d->m_userWebSocketUrl = userWebSocketUrl;
}

void UserUrls::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const UserUrls & userUrls)
{
    strm << static_cast<const Printable&>(userUrls);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const UserUrls & userUrls)
{
    dbg << static_cast<const Printable&>(userUrls);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const UserUrls & userUrls)
{
    strm << static_cast<const Printable&>(userUrls);
    return strm;
}

bool operator==(const UserUrls & lhs, const UserUrls & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noteStoreUrl() == rhs.noteStoreUrl() &&
        lhs.webApiUrlPrefix() == rhs.webApiUrlPrefix() &&
        lhs.userStoreUrl() == rhs.userStoreUrl() &&
        lhs.utilityUrl() == rhs.utilityUrl() &&
        lhs.messageStoreUrl() == rhs.messageStoreUrl() &&
        lhs.userWebSocketUrl() == rhs.userWebSocketUrl();
}

bool operator!=(const UserUrls & lhs, const UserUrls & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
