/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "NoteResultSpecImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteResultSpec::Impl::print(QTextStream & strm) const
{
    strm << "NoteResultSpec: {\n";

    if (m_includeContent) {
        strm << "    includeContent = "
            << (*m_includeContent ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeContent is not set\n";
    }

    if (m_includeResourcesData) {
        strm << "    includeResourcesData = "
            << (*m_includeResourcesData ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeResourcesData is not set\n";
    }

    if (m_includeResourcesRecognition) {
        strm << "    includeResourcesRecognition = "
            << (*m_includeResourcesRecognition ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeResourcesRecognition is not set\n";
    }

    if (m_includeResourcesAlternateData) {
        strm << "    includeResourcesAlternateData = "
            << (*m_includeResourcesAlternateData ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeResourcesAlternateData is not set\n";
    }

    if (m_includeSharedNotes) {
        strm << "    includeSharedNotes = "
            << (*m_includeSharedNotes ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeSharedNotes is not set\n";
    }

    if (m_includeNoteAppDataValues) {
        strm << "    includeNoteAppDataValues = "
            << (*m_includeNoteAppDataValues ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeNoteAppDataValues is not set\n";
    }

    if (m_includeResourceAppDataValues) {
        strm << "    includeResourceAppDataValues = "
            << (*m_includeResourceAppDataValues ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeResourceAppDataValues is not set\n";
    }

    if (m_includeAccountLimits) {
        strm << "    includeAccountLimits = "
            << (*m_includeAccountLimits ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeAccountLimits is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
