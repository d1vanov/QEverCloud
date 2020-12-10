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

#include "NoteListData.h"

#include <QTextStream>

namespace qevercloud {

bool NoteList::NoteListData::operator==(
    const NoteListData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_startIndex == other.m_startIndex &&
        m_totalNotes == other.m_totalNotes &&
        m_notes == other.m_notes &&
        m_stoppedWords == other.m_stoppedWords &&
        m_searchedWords == other.m_searchedWords &&
        m_updateCount == other.m_updateCount &&
        m_searchContextBytes == other.m_searchContextBytes &&
        m_debugInfo == other.m_debugInfo;
}

bool NoteList::NoteListData::operator!=(
    const NoteListData & other) const noexcept
{
    return !(*this == other);
}

void NoteList::NoteListData::print(QTextStream & strm) const
{
    strm << "NoteList: {\n";
    strm << "    startIndex = "
        << m_startIndex << "\n";
    strm << "    totalNotes = "
        << m_totalNotes << "\n";
    strm << "    notes = "
        << "QList<Note> {";
    for(const auto & v: m_notes) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";

    if (m_stoppedWords) {
        strm << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: *m_stoppedWords) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    stoppedWords is not set\n";
    }

    if (m_searchedWords) {
        strm << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: *m_searchedWords) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    searchedWords is not set\n";
    }

    if (m_updateCount) {
        strm << "    updateCount = "
            << *m_updateCount << "\n";
    }
    else {
        strm << "    updateCount is not set\n";
    }

    if (m_searchContextBytes) {
        strm << "    searchContextBytes = "
            << *m_searchContextBytes << "\n";
    }
    else {
        strm << "    searchContextBytes is not set\n";
    }

    if (m_debugInfo) {
        strm << "    debugInfo = "
            << *m_debugInfo << "\n";
    }
    else {
        strm << "    debugInfo is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
