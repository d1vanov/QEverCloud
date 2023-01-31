/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/NoteCollectionCounts.h>

#include "impl/NoteCollectionCountsImpl.h"

namespace qevercloud {

NoteCollectionCounts::NoteCollectionCounts() :
    d(new NoteCollectionCounts::Impl)
{}

NoteCollectionCounts::NoteCollectionCounts(const NoteCollectionCounts & other) :
    d(other.d)
{}

NoteCollectionCounts::NoteCollectionCounts(NoteCollectionCounts && other) noexcept :
    d(std::move(other.d))
{}

NoteCollectionCounts::~NoteCollectionCounts() noexcept {}

NoteCollectionCounts & NoteCollectionCounts::operator=(const NoteCollectionCounts & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteCollectionCounts & NoteCollectionCounts::operator=(NoteCollectionCounts && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QMap<Guid, qint32>> & NoteCollectionCounts::notebookCounts() const noexcept
{
    return d->m_notebookCounts;
}

std::optional<QMap<Guid, qint32>> & NoteCollectionCounts::mutableNotebookCounts()
{
    return d->m_notebookCounts;
}

void NoteCollectionCounts::setNotebookCounts(std::optional<QMap<Guid, qint32>> notebookCounts)
{
    d->m_notebookCounts = notebookCounts;
}

const std::optional<QMap<Guid, qint32>> & NoteCollectionCounts::tagCounts() const noexcept
{
    return d->m_tagCounts;
}

std::optional<QMap<Guid, qint32>> & NoteCollectionCounts::mutableTagCounts()
{
    return d->m_tagCounts;
}

void NoteCollectionCounts::setTagCounts(std::optional<QMap<Guid, qint32>> tagCounts)
{
    d->m_tagCounts = tagCounts;
}

const std::optional<qint32> & NoteCollectionCounts::trashCount() const noexcept
{
    return d->m_trashCount;
}

std::optional<qint32> & NoteCollectionCounts::mutableTrashCount()
{
    return d->m_trashCount;
}

void NoteCollectionCounts::setTrashCount(std::optional<qint32> trashCount)
{
    d->m_trashCount = trashCount;
}

void NoteCollectionCounts::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const NoteCollectionCounts & noteCollectionCounts)
{
    strm << static_cast<const Printable&>(noteCollectionCounts);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NoteCollectionCounts & noteCollectionCounts)
{
    dbg << static_cast<const Printable&>(noteCollectionCounts);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NoteCollectionCounts & noteCollectionCounts)
{
    strm << static_cast<const Printable&>(noteCollectionCounts);
    return strm;
}

bool operator==(const NoteCollectionCounts & lhs, const NoteCollectionCounts & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.notebookCounts() == rhs.notebookCounts() &&
        lhs.tagCounts() == rhs.tagCounts() &&
        lhs.trashCount() == rhs.trashCount();
}

bool operator!=(const NoteCollectionCounts & lhs, const NoteCollectionCounts & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
