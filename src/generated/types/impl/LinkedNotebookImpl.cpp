/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "LinkedNotebookImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

LinkedNotebook::Impl::Impl()
{
}

void LinkedNotebook::Impl::print(QTextStream & strm) const
{
    strm << "LinkedNotebook: {\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";

    if (m_shareName) {
        strm << "    shareName = "
            << *m_shareName << "\n";
    }
    else {
        strm << "    shareName is not set\n";
    }

    if (m_username) {
        strm << "    username = "
            << *m_username << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (m_shardId) {
        strm << "    shardId = "
            << *m_shardId << "\n";
    }
    else {
        strm << "    shardId is not set\n";
    }

    if (m_sharedNotebookGlobalId) {
        strm << "    sharedNotebookGlobalId = "
            << *m_sharedNotebookGlobalId << "\n";
    }
    else {
        strm << "    sharedNotebookGlobalId is not set\n";
    }

    if (m_uri) {
        strm << "    uri = "
            << *m_uri << "\n";
    }
    else {
        strm << "    uri is not set\n";
    }

    if (m_guid) {
        strm << "    guid = "
            << *m_guid << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
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

    if (m_stack) {
        strm << "    stack = "
            << *m_stack << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (m_businessId) {
        strm << "    businessId = "
            << *m_businessId << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
