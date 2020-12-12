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

#include "NoteVersionIdData.h"

#include <QTextStream>

namespace qevercloud {

bool NoteVersionId::Impl::operator==(
    const NoteVersionId::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_updated == other.m_updated &&
        m_saved == other.m_saved &&
        m_title == other.m_title &&
        m_lastEditorId == other.m_lastEditorId;
}

bool NoteVersionId::Impl::operator!=(
    const NoteVersionId::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteVersionId::Data::print(QTextStream & strm) const
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
