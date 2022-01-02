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

#include <qevercloud/types/builders/SyncChunkBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncChunkBuilder::Impl final:
    public QSharedData
{
public:
    Timestamp m_currentTime = 0;
    std::optional<qint32> m_chunkHighUSN;
    qint32 m_updateCount = 0;
    std::optional<QList<Note>> m_notes;
    std::optional<QList<Notebook>> m_notebooks;
    std::optional<QList<Tag>> m_tags;
    std::optional<QList<SavedSearch>> m_searches;
    std::optional<QList<Resource>> m_resources;
    std::optional<QList<Guid>> m_expungedNotes;
    std::optional<QList<Guid>> m_expungedNotebooks;
    std::optional<QList<Guid>> m_expungedTags;
    std::optional<QList<Guid>> m_expungedSearches;
    std::optional<QList<LinkedNotebook>> m_linkedNotebooks;
    std::optional<QList<Guid>> m_expungedLinkedNotebooks;
};

SyncChunkBuilder::SyncChunkBuilder() :
    d(new SyncChunkBuilder::Impl)
{}

SyncChunkBuilder::SyncChunkBuilder(SyncChunkBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SyncChunkBuilder::~SyncChunkBuilder() noexcept = default;

SyncChunkBuilder & SyncChunkBuilder::operator=(SyncChunkBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setChunkHighUSN(std::optional<qint32> chunkHighUSN)
{
    d->m_chunkHighUSN = std::move(chunkHighUSN);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setUpdateCount(qint32 updateCount)
{
    d->m_updateCount = updateCount;
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setNotes(std::optional<QList<Note>> notes)
{
    d->m_notes = std::move(notes);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setNotebooks(std::optional<QList<Notebook>> notebooks)
{
    d->m_notebooks = std::move(notebooks);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setTags(std::optional<QList<Tag>> tags)
{
    d->m_tags = std::move(tags);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setSearches(std::optional<QList<SavedSearch>> searches)
{
    d->m_searches = std::move(searches);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setResources(std::optional<QList<Resource>> resources)
{
    d->m_resources = std::move(resources);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setExpungedNotes(std::optional<QList<Guid>> expungedNotes)
{
    d->m_expungedNotes = std::move(expungedNotes);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setExpungedNotebooks(std::optional<QList<Guid>> expungedNotebooks)
{
    d->m_expungedNotebooks = std::move(expungedNotebooks);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setExpungedTags(std::optional<QList<Guid>> expungedTags)
{
    d->m_expungedTags = std::move(expungedTags);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setExpungedSearches(std::optional<QList<Guid>> expungedSearches)
{
    d->m_expungedSearches = std::move(expungedSearches);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setLinkedNotebooks(std::optional<QList<LinkedNotebook>> linkedNotebooks)
{
    d->m_linkedNotebooks = std::move(linkedNotebooks);
    return *this;
}

SyncChunkBuilder & SyncChunkBuilder::setExpungedLinkedNotebooks(std::optional<QList<Guid>> expungedLinkedNotebooks)
{
    d->m_expungedLinkedNotebooks = std::move(expungedLinkedNotebooks);
    return *this;
}

SyncChunk SyncChunkBuilder::build()
{
    SyncChunk result;

    result.setCurrentTime(d->m_currentTime);
    result.setChunkHighUSN(std::move(d->m_chunkHighUSN));
    result.setUpdateCount(d->m_updateCount);
    result.setNotes(std::move(d->m_notes));
    result.setNotebooks(std::move(d->m_notebooks));
    result.setTags(std::move(d->m_tags));
    result.setSearches(std::move(d->m_searches));
    result.setResources(std::move(d->m_resources));
    result.setExpungedNotes(std::move(d->m_expungedNotes));
    result.setExpungedNotebooks(std::move(d->m_expungedNotebooks));
    result.setExpungedTags(std::move(d->m_expungedTags));
    result.setExpungedSearches(std::move(d->m_expungedSearches));
    result.setLinkedNotebooks(std::move(d->m_linkedNotebooks));
    result.setExpungedLinkedNotebooks(std::move(d->m_expungedLinkedNotebooks));

    d->m_currentTime = 0;
    d->m_chunkHighUSN = {};
    d->m_updateCount = 0;
    d->m_notes = {};
    d->m_notebooks = {};
    d->m_tags = {};
    d->m_searches = {};
    d->m_resources = {};
    d->m_expungedNotes = {};
    d->m_expungedNotebooks = {};
    d->m_expungedTags = {};
    d->m_expungedSearches = {};
    d->m_linkedNotebooks = {};
    d->m_expungedLinkedNotebooks = {};

    return result;
}

} // namespace qevercloud
