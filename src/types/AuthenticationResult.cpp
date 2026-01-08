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

#include <qevercloud/types/AuthenticationResult.h>

#include "impl/AuthenticationResultImpl.h"

namespace qevercloud {

AuthenticationResult::AuthenticationResult() :
    d(new AuthenticationResult::Impl)
{}

AuthenticationResult::AuthenticationResult(const AuthenticationResult & other) :
    d(other.d)
{}

AuthenticationResult::AuthenticationResult(AuthenticationResult && other) noexcept :
    d(std::move(other.d))
{}

AuthenticationResult::~AuthenticationResult() noexcept {}

AuthenticationResult & AuthenticationResult::operator=(const AuthenticationResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

AuthenticationResult & AuthenticationResult::operator=(AuthenticationResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

Timestamp AuthenticationResult::currentTime() const noexcept
{
    return d->m_currentTime;
}

void AuthenticationResult::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
}

const QString & AuthenticationResult::authenticationToken() const noexcept
{
    return d->m_authenticationToken;
}

void AuthenticationResult::setAuthenticationToken(QString authenticationToken)
{
    d->m_authenticationToken = std::move(authenticationToken);
}

Timestamp AuthenticationResult::expiration() const noexcept
{
    return d->m_expiration;
}

void AuthenticationResult::setExpiration(Timestamp expiration)
{
    d->m_expiration = expiration;
}

const std::optional<User> & AuthenticationResult::user() const noexcept
{
    return d->m_user;
}

std::optional<User> & AuthenticationResult::mutableUser()
{
    return d->m_user;
}

void AuthenticationResult::setUser(std::optional<User> user)
{
    d->m_user = std::move(user);
}

const std::optional<PublicUserInfo> & AuthenticationResult::publicUserInfo() const noexcept
{
    return d->m_publicUserInfo;
}

std::optional<PublicUserInfo> & AuthenticationResult::mutablePublicUserInfo()
{
    return d->m_publicUserInfo;
}

void AuthenticationResult::setPublicUserInfo(std::optional<PublicUserInfo> publicUserInfo)
{
    d->m_publicUserInfo = std::move(publicUserInfo);
}

const std::optional<QString> & AuthenticationResult::noteStoreUrl() const noexcept
{
    return d->m_noteStoreUrl;
}

void AuthenticationResult::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = std::move(noteStoreUrl);
}

const std::optional<QString> & AuthenticationResult::webApiUrlPrefix() const noexcept
{
    return d->m_webApiUrlPrefix;
}

void AuthenticationResult::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = std::move(webApiUrlPrefix);
}

const std::optional<bool> & AuthenticationResult::secondFactorRequired() const noexcept
{
    return d->m_secondFactorRequired;
}

std::optional<bool> & AuthenticationResult::mutableSecondFactorRequired()
{
    return d->m_secondFactorRequired;
}

void AuthenticationResult::setSecondFactorRequired(std::optional<bool> secondFactorRequired)
{
    d->m_secondFactorRequired = secondFactorRequired;
}

const std::optional<QString> & AuthenticationResult::secondFactorDeliveryHint() const noexcept
{
    return d->m_secondFactorDeliveryHint;
}

void AuthenticationResult::setSecondFactorDeliveryHint(std::optional<QString> secondFactorDeliveryHint)
{
    d->m_secondFactorDeliveryHint = std::move(secondFactorDeliveryHint);
}

const std::optional<UserUrls> & AuthenticationResult::urls() const noexcept
{
    return d->m_urls;
}

std::optional<UserUrls> & AuthenticationResult::mutableUrls()
{
    return d->m_urls;
}

void AuthenticationResult::setUrls(std::optional<UserUrls> urls)
{
    d->m_urls = std::move(urls);
}

void AuthenticationResult::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const AuthenticationResult & authenticationResult)
{
    strm << static_cast<const Printable&>(authenticationResult);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const AuthenticationResult & authenticationResult)
{
    dbg << static_cast<const Printable&>(authenticationResult);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const AuthenticationResult & authenticationResult)
{
    strm << static_cast<const Printable&>(authenticationResult);
    return strm;
}

bool operator==(const AuthenticationResult & lhs, const AuthenticationResult & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.currentTime() == rhs.currentTime() &&
        lhs.authenticationToken() == rhs.authenticationToken() &&
        lhs.expiration() == rhs.expiration() &&
        lhs.user() == rhs.user() &&
        lhs.publicUserInfo() == rhs.publicUserInfo() &&
        lhs.noteStoreUrl() == rhs.noteStoreUrl() &&
        lhs.webApiUrlPrefix() == rhs.webApiUrlPrefix() &&
        lhs.secondFactorRequired() == rhs.secondFactorRequired() &&
        lhs.secondFactorDeliveryHint() == rhs.secondFactorDeliveryHint() &&
        lhs.urls() == rhs.urls();
}

bool operator!=(const AuthenticationResult & lhs, const AuthenticationResult & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
