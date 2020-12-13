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

#include <generated/types/NoteList.h>

#include "impl/NoteListImpl.h"

namespace qevercloud {

NoteList::NoteList() :
    d(new NoteList::Impl)
 {}

NoteList::NoteList(const NoteList & other) :
    d(other.d)
{}

NoteList::NoteList(NoteList && other) noexcept :
    d(std::move(other.d))
{}

NoteList::~NoteList() noexcept {}

NoteList & NoteList::operator=(const NoteList & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteList & NoteList::operator=(NoteList && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

qint32 NoteList::startIndex() const noexcept
{
    return d->m_startIndex;
}

void NoteList::setStartIndex(qint32 startIndex)
{
    d->m_startIndex = startIndex;
}

qint32 NoteList::totalNotes() const noexcept
{
    return d->m_totalNotes;
}

void NoteList::setTotalNotes(qint32 totalNotes)
{
    d->m_totalNotes = totalNotes;
}

const QList<Note> & NoteList::notes() const noexcept
{
    return d->m_notes;
}

QList<Note> & NoteList::mutableNotes()
{
    return d->m_notes;
}

void NoteList::setNotes(QList<Note> notes)
{
    d->m_notes = notes;
}

const std::optional<QStringList> & NoteList::stoppedWords() const noexcept
{
    return d->m_stoppedWords;
}

std::optional<QStringList> & NoteList::mutableStoppedWords()
{
    return d->m_stoppedWords;
}

void NoteList::setStoppedWords(std::optional<QStringList> stoppedWords)
{
    d->m_stoppedWords = stoppedWords;
}

const std::optional<QStringList> & NoteList::searchedWords() const noexcept
{
    return d->m_searchedWords;
}

std::optional<QStringList> & NoteList::mutableSearchedWords()
{
    return d->m_searchedWords;
}

void NoteList::setSearchedWords(std::optional<QStringList> searchedWords)
{
    d->m_searchedWords = searchedWords;
}

const std::optional<qint32> & NoteList::updateCount() const noexcept
{
    return d->m_updateCount;
}

std::optional<qint32> & NoteList::mutableUpdateCount()
{
    return d->m_updateCount;
}

void NoteList::setUpdateCount(std::optional<qint32> updateCount)
{
    d->m_updateCount = updateCount;
}

const std::optional<QByteArray> & NoteList::searchContextBytes() const noexcept
{
    return d->m_searchContextBytes;
}

void NoteList::setSearchContextBytes(std::optional<QByteArray> searchContextBytes)
{
    d->m_searchContextBytes = searchContextBytes;
}

const std::optional<QString> & NoteList::debugInfo() const noexcept
{
    return d->m_debugInfo;
}

void NoteList::setDebugInfo(std::optional<QString> debugInfo)
{
    d->m_debugInfo = debugInfo;
}

void NoteList::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteList::operator==(const NoteList & other) const noexcept
{
    return *d == *other.d;
}

bool NoteList::operator!=(const NoteList & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
