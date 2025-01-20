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

#include "NoteVersionIdImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteVersionId::Impl::print(QTextStream & strm) const
{
    strm << "NoteVersionId: {\n";
    strm << "    updateSequenceNum = "
        << m_updateSequenceNum << "\n";
    strm << "    updated = "
        << m_updated << "\n";
    strm << "    saved = "
        << m_saved << "\n";
    strm << "    title = "
        << m_title << "\n";

    if (m_lastEditorId) {
        strm << "    lastEditorId = "
            << *m_lastEditorId << "\n";
    }
    else {
        strm << "    lastEditorId is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
