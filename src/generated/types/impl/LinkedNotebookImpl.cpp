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

#include "LinkedNotebookImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool LinkedNotebook::Impl::operator==(
    const LinkedNotebook::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_localId == other.m_localId &&
        m_parentLocalId == other.m_parentLocalId &&
        m_locallyModified == other.m_locallyModified &&
        m_localOnly == other.m_localOnly &&
        m_locallyFavorited == other.m_locallyFavorited &&
        m_shareName == other.m_shareName &&
        m_username == other.m_username &&
        m_shardId == other.m_shardId &&
        m_sharedNotebookGlobalId == other.m_sharedNotebookGlobalId &&
        m_uri == other.m_uri &&
        m_guid == other.m_guid &&
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_noteStoreUrl == other.m_noteStoreUrl &&
        m_webApiUrlPrefix == other.m_webApiUrlPrefix &&
        m_stack == other.m_stack &&
        m_businessId == other.m_businessId;
}

bool LinkedNotebook::Impl::operator!=(
    const LinkedNotebook::Impl & other) const noexcept
{
    return !(*this == other);
}

void LinkedNotebook::Impl::print(QTextStream & strm) const
{
    strm << "LinkedNotebook: {\n";
        strm << "    localId = " << m_localId << "\n";
        strm << "    parentLocalId = " << m_parentLocalId << "\n";
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
