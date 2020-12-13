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

#include <qevercloud/generated/types/SyncChunk.h>

#include "impl/SyncChunkImpl.h"

namespace qevercloud {

SyncChunk::SyncChunk() :
    d(new SyncChunk::Impl)
 {}

SyncChunk::SyncChunk(const SyncChunk & other) :
    d(other.d)
{}

SyncChunk::SyncChunk(SyncChunk && other) noexcept :
    d(std::move(other.d))
{}

SyncChunk::~SyncChunk() noexcept {}

SyncChunk & SyncChunk::operator=(const SyncChunk & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SyncChunk & SyncChunk::operator=(SyncChunk && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

Timestamp SyncChunk::currentTime() const noexcept
{
    return d->m_currentTime;
}

void SyncChunk::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
}

const std::optional<qint32> & SyncChunk::chunkHighUSN() const noexcept
{
    return d->m_chunkHighUSN;
}

std::optional<qint32> & SyncChunk::mutableChunkHighUSN()
{
    return d->m_chunkHighUSN;
}

void SyncChunk::setChunkHighUSN(std::optional<qint32> chunkHighUSN)
{
    d->m_chunkHighUSN = chunkHighUSN;
}

qint32 SyncChunk::updateCount() const noexcept
{
    return d->m_updateCount;
}

void SyncChunk::setUpdateCount(qint32 updateCount)
{
    d->m_updateCount = updateCount;
}

const std::optional<QList<Note>> & SyncChunk::notes() const noexcept
{
    return d->m_notes;
}

std::optional<QList<Note>> & SyncChunk::mutableNotes()
{
    return d->m_notes;
}

void SyncChunk::setNotes(std::optional<QList<Note>> notes)
{
    d->m_notes = notes;
}

const std::optional<QList<Notebook>> & SyncChunk::notebooks() const noexcept
{
    return d->m_notebooks;
}

std::optional<QList<Notebook>> & SyncChunk::mutableNotebooks()
{
    return d->m_notebooks;
}

void SyncChunk::setNotebooks(std::optional<QList<Notebook>> notebooks)
{
    d->m_notebooks = notebooks;
}

const std::optional<QList<Tag>> & SyncChunk::tags() const noexcept
{
    return d->m_tags;
}

std::optional<QList<Tag>> & SyncChunk::mutableTags()
{
    return d->m_tags;
}

void SyncChunk::setTags(std::optional<QList<Tag>> tags)
{
    d->m_tags = tags;
}

const std::optional<QList<SavedSearch>> & SyncChunk::searches() const noexcept
{
    return d->m_searches;
}

std::optional<QList<SavedSearch>> & SyncChunk::mutableSearches()
{
    return d->m_searches;
}

void SyncChunk::setSearches(std::optional<QList<SavedSearch>> searches)
{
    d->m_searches = searches;
}

const std::optional<QList<Resource>> & SyncChunk::resources() const noexcept
{
    return d->m_resources;
}

std::optional<QList<Resource>> & SyncChunk::mutableResources()
{
    return d->m_resources;
}

void SyncChunk::setResources(std::optional<QList<Resource>> resources)
{
    d->m_resources = resources;
}

const std::optional<QList<Guid>> & SyncChunk::expungedNotes() const noexcept
{
    return d->m_expungedNotes;
}

std::optional<QList<Guid>> & SyncChunk::mutableExpungedNotes()
{
    return d->m_expungedNotes;
}

void SyncChunk::setExpungedNotes(std::optional<QList<Guid>> expungedNotes)
{
    d->m_expungedNotes = expungedNotes;
}

const std::optional<QList<Guid>> & SyncChunk::expungedNotebooks() const noexcept
{
    return d->m_expungedNotebooks;
}

std::optional<QList<Guid>> & SyncChunk::mutableExpungedNotebooks()
{
    return d->m_expungedNotebooks;
}

void SyncChunk::setExpungedNotebooks(std::optional<QList<Guid>> expungedNotebooks)
{
    d->m_expungedNotebooks = expungedNotebooks;
}

const std::optional<QList<Guid>> & SyncChunk::expungedTags() const noexcept
{
    return d->m_expungedTags;
}

std::optional<QList<Guid>> & SyncChunk::mutableExpungedTags()
{
    return d->m_expungedTags;
}

void SyncChunk::setExpungedTags(std::optional<QList<Guid>> expungedTags)
{
    d->m_expungedTags = expungedTags;
}

const std::optional<QList<Guid>> & SyncChunk::expungedSearches() const noexcept
{
    return d->m_expungedSearches;
}

std::optional<QList<Guid>> & SyncChunk::mutableExpungedSearches()
{
    return d->m_expungedSearches;
}

void SyncChunk::setExpungedSearches(std::optional<QList<Guid>> expungedSearches)
{
    d->m_expungedSearches = expungedSearches;
}

const std::optional<QList<LinkedNotebook>> & SyncChunk::linkedNotebooks() const noexcept
{
    return d->m_linkedNotebooks;
}

std::optional<QList<LinkedNotebook>> & SyncChunk::mutableLinkedNotebooks()
{
    return d->m_linkedNotebooks;
}

void SyncChunk::setLinkedNotebooks(std::optional<QList<LinkedNotebook>> linkedNotebooks)
{
    d->m_linkedNotebooks = linkedNotebooks;
}

const std::optional<QList<Guid>> & SyncChunk::expungedLinkedNotebooks() const noexcept
{
    return d->m_expungedLinkedNotebooks;
}

std::optional<QList<Guid>> & SyncChunk::mutableExpungedLinkedNotebooks()
{
    return d->m_expungedLinkedNotebooks;
}

void SyncChunk::setExpungedLinkedNotebooks(std::optional<QList<Guid>> expungedLinkedNotebooks)
{
    d->m_expungedLinkedNotebooks = expungedLinkedNotebooks;
}

void SyncChunk::print(QTextStream & strm) const
{
    d->print(strm);
}

bool SyncChunk::operator==(const SyncChunk & other) const noexcept
{
    return *d == *other.d;
}

bool SyncChunk::operator!=(const SyncChunk & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
