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

#include "SyncChunkImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool SyncChunk::Impl::operator==(
    const SyncChunk::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_currentTime == other.m_currentTime &&
        m_chunkHighUSN == other.m_chunkHighUSN &&
        m_updateCount == other.m_updateCount &&
        m_notes == other.m_notes &&
        m_notebooks == other.m_notebooks &&
        m_tags == other.m_tags &&
        m_searches == other.m_searches &&
        m_resources == other.m_resources &&
        m_expungedNotes == other.m_expungedNotes &&
        m_expungedNotebooks == other.m_expungedNotebooks &&
        m_expungedTags == other.m_expungedTags &&
        m_expungedSearches == other.m_expungedSearches &&
        m_linkedNotebooks == other.m_linkedNotebooks &&
        m_expungedLinkedNotebooks == other.m_expungedLinkedNotebooks;
}

bool SyncChunk::Impl::operator!=(
    const SyncChunk::Impl & other) const noexcept
{
    return !(*this == other);
}

void SyncChunk::Impl::print(QTextStream & strm) const
{
    strm << "SyncChunk: {\n";
    strm << "    currentTime = "
        << m_currentTime << "\n";

    if (m_chunkHighUSN) {
        strm << "    chunkHighUSN = "
            << *m_chunkHighUSN << "\n";
    }
    else {
        strm << "    chunkHighUSN is not set\n";
    }

    strm << "    updateCount = "
        << m_updateCount << "\n";

    if (m_notes) {
        strm << "    notes = "
            << "QList<Note> {";
        for(const auto & v: *m_notes) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notes is not set\n";
    }

    if (m_notebooks) {
        strm << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: *m_notebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebooks is not set\n";
    }

    if (m_tags) {
        strm << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: *m_tags) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tags is not set\n";
    }

    if (m_searches) {
        strm << "    searches = "
            << "QList<SavedSearch> {";
        for(const auto & v: *m_searches) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    searches is not set\n";
    }

    if (m_resources) {
        strm << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: *m_resources) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    resources is not set\n";
    }

    if (m_expungedNotes) {
        strm << "    expungedNotes = "
            << "QList<Guid> {";
        for(const auto & v: *m_expungedNotes) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedNotes is not set\n";
    }

    if (m_expungedNotebooks) {
        strm << "    expungedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: *m_expungedNotebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedNotebooks is not set\n";
    }

    if (m_expungedTags) {
        strm << "    expungedTags = "
            << "QList<Guid> {";
        for(const auto & v: *m_expungedTags) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedTags is not set\n";
    }

    if (m_expungedSearches) {
        strm << "    expungedSearches = "
            << "QList<Guid> {";
        for(const auto & v: *m_expungedSearches) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedSearches is not set\n";
    }

    if (m_linkedNotebooks) {
        strm << "    linkedNotebooks = "
            << "QList<LinkedNotebook> {";
        for(const auto & v: *m_linkedNotebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    linkedNotebooks is not set\n";
    }

    if (m_expungedLinkedNotebooks) {
        strm << "    expungedLinkedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: *m_expungedLinkedNotebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedLinkedNotebooks is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
