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

#include <generated/types/NotesMetadataList.h>

#include "data/NotesMetadataListData.h"

namespace qevercloud {

NotesMetadataList::NotesMetadataList() : d(new NotesMetadataListData) {}

NotesMetadataList::NotesMetadataList(const NotesMetadataList & other) : d(other.d) {}

NotesMetadataList::NotesMetadataList(NotesMetadataList && other) noexcept : d(std::move(other.d))
{}

NotesMetadataList::~NotesMetadataList() noexcept {}

NotesMetadataList & NotesMetadataList::operator=(const NotesMetadataList & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotesMetadataList & NotesMetadataList::operator=(NotesMetadataList && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

qint32 NotesMetadataList::startIndex() const noexcept
{
    return d->m_startIndex;
}

void NotesMetadataList::setStartIndex(qint32 startIndex)
{
    d->m_startIndex = startIndex;
}

qint32 NotesMetadataList::totalNotes() const noexcept
{
    return d->m_totalNotes;
}

void NotesMetadataList::setTotalNotes(qint32 totalNotes)
{
    d->m_totalNotes = totalNotes;
}

const QList<NoteMetadata> & NotesMetadataList::notes() const noexcept
{
    return d->m_notes;
}

QList<NoteMetadata> & NotesMetadataList::mutableNotes()
{
    return d->m_notes;
}

void NotesMetadataList::setNotes(QList<NoteMetadata> notes)
{
    d->m_notes = notes;
}

const std::optional<QStringList> & NotesMetadataList::stoppedWords() const noexcept
{
    return d->m_stoppedWords;
}

std::optional<QStringList> & NotesMetadataList::mutableStoppedWords()
{
    return d->m_stoppedWords;
}

void NotesMetadataList::setStoppedWords(std::optional<QStringList> stoppedWords)
{
    d->m_stoppedWords = stoppedWords;
}

const std::optional<QStringList> & NotesMetadataList::searchedWords() const noexcept
{
    return d->m_searchedWords;
}

std::optional<QStringList> & NotesMetadataList::mutableSearchedWords()
{
    return d->m_searchedWords;
}

void NotesMetadataList::setSearchedWords(std::optional<QStringList> searchedWords)
{
    d->m_searchedWords = searchedWords;
}

const std::optional<qint32> & NotesMetadataList::updateCount() const noexcept
{
    return d->m_updateCount;
}

std::optional<qint32> & NotesMetadataList::mutableUpdateCount()
{
    return d->m_updateCount;
}

void NotesMetadataList::setUpdateCount(std::optional<qint32> updateCount)
{
    d->m_updateCount = updateCount;
}

const std::optional<QByteArray> & NotesMetadataList::searchContextBytes() const noexcept
{
    return d->m_searchContextBytes;
}

void NotesMetadataList::setSearchContextBytes(std::optional<QByteArray> searchContextBytes)
{
    d->m_searchContextBytes = searchContextBytes;
}

const std::optional<QString> & NotesMetadataList::debugInfo() const noexcept
{
    return d->m_debugInfo;
}

void NotesMetadataList::setDebugInfo(std::optional<QString> debugInfo)
{
    d->m_debugInfo = debugInfo;
}

void NotesMetadataList::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NotesMetadataList::operator==(const NotesMetadataList & other) const noexcept
{
    return *d == *other.d;
}

bool NotesMetadataList::operator!=(const NotesMetadataList & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
