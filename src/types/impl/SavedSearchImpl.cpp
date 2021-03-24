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

#include "SavedSearchImpl.h"

#include "../../Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

SavedSearch::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

void SavedSearch::Impl::print(QTextStream & strm) const
{
    strm << "SavedSearch: {\n";
        strm << "    localId = " << m_localId << "\n";
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
