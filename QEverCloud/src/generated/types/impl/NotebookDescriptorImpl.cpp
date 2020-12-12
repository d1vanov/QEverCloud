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

#include "NotebookDescriptorImpl.h"

#include <QTextStream>

namespace qevercloud {

bool NotebookDescriptor::Impl::operator==(
    const NotebookDescriptor::Impl & other) const noexcept
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
        m_guid == other.m_guid &&
        m_notebookDisplayName == other.m_notebookDisplayName &&
        m_contactName == other.m_contactName &&
        m_hasSharedNotebook == other.m_hasSharedNotebook &&
        m_joinedUserCount == other.m_joinedUserCount;
}

bool NotebookDescriptor::Impl::operator!=(
    const NotebookDescriptor::Impl & other) const noexcept
{
    return !(*this == other);
}

void NotebookDescriptor::Impl::print(QTextStream & strm) const
{
    strm << "NotebookDescriptor: {\n";
        strm << "    localId = " << m_localId << "\n";
        strm << "    parentLocalId = " << m_parentLocalId << "\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";

    if (m_guid) {
        strm << "    guid = "
            << *m_guid << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (m_notebookDisplayName) {
        strm << "    notebookDisplayName = "
            << *m_notebookDisplayName << "\n";
    }
    else {
        strm << "    notebookDisplayName is not set\n";
    }

    if (m_contactName) {
        strm << "    contactName = "
            << *m_contactName << "\n";
    }
    else {
        strm << "    contactName is not set\n";
    }

    if (m_hasSharedNotebook) {
        strm << "    hasSharedNotebook = "
            << *m_hasSharedNotebook << "\n";
    }
    else {
        strm << "    hasSharedNotebook is not set\n";
    }

    if (m_joinedUserCount) {
        strm << "    joinedUserCount = "
            << *m_joinedUserCount << "\n";
    }
    else {
        strm << "    joinedUserCount is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
