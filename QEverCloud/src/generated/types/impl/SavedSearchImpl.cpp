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

#include "SavedSearchImpl.h"

#include <QTextStream>

namespace qevercloud {

bool SavedSearch::Impl::operator==(
    const SavedSearch::Impl & other) const noexcept
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
        m_name == other.m_name &&
        m_query == other.m_query &&
        m_format == other.m_format &&
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_scope == other.m_scope;
}

bool SavedSearch::Impl::operator!=(
    const SavedSearch::Impl & other) const noexcept
{
    return !(*this == other);
}

void SavedSearch::Impl::print(QTextStream & strm) const
{
    strm << "SavedSearch: {\n";
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

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_query) {
        strm << "    query = "
            << *m_query << "\n";
    }
    else {
        strm << "    query is not set\n";
    }

    if (m_format) {
        strm << "    format = "
            << *m_format << "\n";
    }
    else {
        strm << "    format is not set\n";
    }

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (m_scope) {
        strm << "    scope = "
            << *m_scope << "\n";
    }
    else {
        strm << "    scope is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
