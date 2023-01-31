/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "UserUrlsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void UserUrls::Impl::print(QTextStream & strm) const
{
    strm << "UserUrls: {\n";

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

    if (m_userStoreUrl) {
        strm << "    userStoreUrl = "
            << *m_userStoreUrl << "\n";
    }
    else {
        strm << "    userStoreUrl is not set\n";
    }

    if (m_utilityUrl) {
        strm << "    utilityUrl = "
            << *m_utilityUrl << "\n";
    }
    else {
        strm << "    utilityUrl is not set\n";
    }

    if (m_messageStoreUrl) {
        strm << "    messageStoreUrl = "
            << *m_messageStoreUrl << "\n";
    }
    else {
        strm << "    messageStoreUrl is not set\n";
    }

    if (m_userWebSocketUrl) {
        strm << "    userWebSocketUrl = "
            << *m_userWebSocketUrl << "\n";
    }
    else {
        strm << "    userWebSocketUrl is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
