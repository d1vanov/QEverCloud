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

#include "NotesMetadataResultSpecImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void NotesMetadataResultSpec::Impl::print(QTextStream & strm) const
{
    strm << "NotesMetadataResultSpec: {\n";

    if (m_includeTitle) {
        strm << "    includeTitle = "
            << (*m_includeTitle ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeTitle is not set\n";
    }

    if (m_includeContentLength) {
        strm << "    includeContentLength = "
            << (*m_includeContentLength ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeContentLength is not set\n";
    }

    if (m_includeCreated) {
        strm << "    includeCreated = "
            << (*m_includeCreated ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeCreated is not set\n";
    }

    if (m_includeUpdated) {
        strm << "    includeUpdated = "
            << (*m_includeUpdated ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeUpdated is not set\n";
    }

    if (m_includeDeleted) {
        strm << "    includeDeleted = "
            << (*m_includeDeleted ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeDeleted is not set\n";
    }

    if (m_includeUpdateSequenceNum) {
        strm << "    includeUpdateSequenceNum = "
            << (*m_includeUpdateSequenceNum ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeUpdateSequenceNum is not set\n";
    }

    if (m_includeNotebookGuid) {
        strm << "    includeNotebookGuid = "
            << (*m_includeNotebookGuid ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeNotebookGuid is not set\n";
    }

    if (m_includeTagGuids) {
        strm << "    includeTagGuids = "
            << (*m_includeTagGuids ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeTagGuids is not set\n";
    }

    if (m_includeAttributes) {
        strm << "    includeAttributes = "
            << (*m_includeAttributes ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeAttributes is not set\n";
    }

    if (m_includeLargestResourceMime) {
        strm << "    includeLargestResourceMime = "
            << (*m_includeLargestResourceMime ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeLargestResourceMime is not set\n";
    }

    if (m_includeLargestResourceSize) {
        strm << "    includeLargestResourceSize = "
            << (*m_includeLargestResourceSize ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeLargestResourceSize is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
