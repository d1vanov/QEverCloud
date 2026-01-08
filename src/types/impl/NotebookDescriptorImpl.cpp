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

#include "NotebookDescriptorImpl.h"

#include "../../Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

NotebookDescriptor::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

void NotebookDescriptor::Impl::print(QTextStream & strm) const
{
    strm << "NotebookDescriptor: {\n";
    strm << "    localId = "
        << m_localId << "\n";
    strm << "    isLocallyModified = "
        << (m_isLocallyModified ? "true" : "false") << "\n";
    strm << "    isLocalOnly = "
        << (m_isLocalOnly ? "true" : "false") << "\n";
    strm << "    isLocallyFavorited = "
        << (m_isLocallyFavorited ? "true" : "false") << "\n";
    strm << "    localData = "
        << "QHash<QString, QVariant> {";
    for(const auto & it: toRange(m_localData)) {
        strm << "    [" << it.key() << "] = ";
        QString debugStr;
        QDebug dbg{&debugStr};
        dbg << it.value();
        strm << debugStr << "\n";
    }
    strm << "    }\n";

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
            << (*m_hasSharedNotebook ? "true" : "false") << "\n";
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
