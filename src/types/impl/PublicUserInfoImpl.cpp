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

#include "PublicUserInfoImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void PublicUserInfo::Impl::print(QTextStream & strm) const
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
