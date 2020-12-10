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

#include "PublicUserInfoData.h"

#include <QTextStream>

namespace qevercloud {

bool PublicUserInfo::PublicUserInfoData::operator==(
    const PublicUserInfoData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_userId == other.m_userId &&
        m_serviceLevel == other.m_serviceLevel &&
        m_username == other.m_username &&
        m_noteStoreUrl == other.m_noteStoreUrl &&
        m_webApiUrlPrefix == other.m_webApiUrlPrefix;
}

bool PublicUserInfo::PublicUserInfoData::operator!=(
    const PublicUserInfoData & other) const noexcept
{
    return !(*this == other);
}

void PublicUserInfo::PublicUserInfoData::print(QTextStream & strm) const
{
    strm << "PublicUserInfo: {\n";
    strm << "    userId = "
        << m_userId << "\n";

    if (m_serviceLevel) {
        strm << "    serviceLevel = "
            << *m_serviceLevel << "\n";
    }
    else {
        strm << "    serviceLevel is not set\n";
    }

    if (m_username) {
        strm << "    username = "
            << *m_username << "\n";
    }
    else {
        strm << "    username is not set\n";
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

    strm << "}\n";
}

} // namespace qevercloud
