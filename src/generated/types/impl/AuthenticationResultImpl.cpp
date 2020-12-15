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

#include "AuthenticationResultImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool AuthenticationResult::Impl::operator==(
    const AuthenticationResult::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_currentTime == other.m_currentTime &&
        m_authenticationToken == other.m_authenticationToken &&
        m_expiration == other.m_expiration &&
        m_user == other.m_user &&
        m_publicUserInfo == other.m_publicUserInfo &&
        m_noteStoreUrl == other.m_noteStoreUrl &&
        m_webApiUrlPrefix == other.m_webApiUrlPrefix &&
        m_secondFactorRequired == other.m_secondFactorRequired &&
        m_secondFactorDeliveryHint == other.m_secondFactorDeliveryHint &&
        m_urls == other.m_urls;
}

bool AuthenticationResult::Impl::operator!=(
    const AuthenticationResult::Impl & other) const noexcept
{
    return !(*this == other);
}

void AuthenticationResult::Impl::print(QTextStream & strm) const
{
    strm << "AuthenticationResult: {\n";
    strm << "    currentTime = "
        << m_currentTime << "\n";
    strm << "    authenticationToken = "
        << m_authenticationToken << "\n";
    strm << "    expiration = "
        << m_expiration << "\n";

    if (m_user) {
        strm << "    user = "
            << *m_user << "\n";
    }
    else {
        strm << "    user is not set\n";
    }

    if (m_publicUserInfo) {
        strm << "    publicUserInfo = "
            << *m_publicUserInfo << "\n";
    }
    else {
        strm << "    publicUserInfo is not set\n";
    }

    if (m_noteStoreUrl) {
        strm << "    noteStoreUrl = "
            << *m_noteStoreUrl << "\n";
    }
    else {
        strm << "    noteStoreUrl is not set\n";
    }

    if (m_webApiUrlPrefix) {
        strm << "    webApiUrlPrefix = "
            << *m_webApiUrlPrefix << "\n";
    }
    else {
        strm << "    webApiUrlPrefix is not set\n";
    }

    if (m_secondFactorRequired) {
        strm << "    secondFactorRequired = "
            << *m_secondFactorRequired << "\n";
    }
    else {
        strm << "    secondFactorRequired is not set\n";
    }

    if (m_secondFactorDeliveryHint) {
        strm << "    secondFactorDeliveryHint = "
            << *m_secondFactorDeliveryHint << "\n";
    }
    else {
        strm << "    secondFactorDeliveryHint is not set\n";
    }

    if (m_urls) {
        strm << "    urls = "
            << *m_urls << "\n";
    }
    else {
        strm << "    urls is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud