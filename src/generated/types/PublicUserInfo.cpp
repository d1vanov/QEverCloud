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

#include <qevercloud/generated/types/PublicUserInfo.h>

#include "impl/PublicUserInfoImpl.h"

namespace qevercloud {

PublicUserInfo::PublicUserInfo() :
    d(new PublicUserInfo::Impl)
 {}

PublicUserInfo::PublicUserInfo(const PublicUserInfo & other) :
    d(other.d)
{}

PublicUserInfo::PublicUserInfo(PublicUserInfo && other) noexcept :
    d(std::move(other.d))
{}

PublicUserInfo::~PublicUserInfo() noexcept {}

PublicUserInfo & PublicUserInfo::operator=(const PublicUserInfo & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

PublicUserInfo & PublicUserInfo::operator=(PublicUserInfo && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserID PublicUserInfo::userId() const noexcept
{
    return d->m_userId;
}

void PublicUserInfo::setUserId(UserID userId)
{
    d->m_userId = userId;
}

const std::optional<ServiceLevel> & PublicUserInfo::serviceLevel() const noexcept
{
    return d->m_serviceLevel;
}

std::optional<ServiceLevel> & PublicUserInfo::mutableServiceLevel()
{
    return d->m_serviceLevel;
}

void PublicUserInfo::setServiceLevel(std::optional<ServiceLevel> serviceLevel)
{
    d->m_serviceLevel = serviceLevel;
}

const std::optional<QString> & PublicUserInfo::username() const noexcept
{
    return d->m_username;
}

void PublicUserInfo::setUsername(std::optional<QString> username)
{
    d->m_username = username;
}

const std::optional<QString> & PublicUserInfo::noteStoreUrl() const noexcept
{
    return d->m_noteStoreUrl;
}

void PublicUserInfo::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = noteStoreUrl;
}

const std::optional<QString> & PublicUserInfo::webApiUrlPrefix() const noexcept
{
    return d->m_webApiUrlPrefix;
}

void PublicUserInfo::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = webApiUrlPrefix;
}

void PublicUserInfo::print(QTextStream & strm) const
{
    d->print(strm);
}

bool PublicUserInfo::operator==(const PublicUserInfo & other) const noexcept
{
    return *d == *other.d;
}

bool PublicUserInfo::operator!=(const PublicUserInfo & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
