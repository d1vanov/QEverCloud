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

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNKBUILDER
#define QEVERCLOUD_GENERATED_SYNCCHUNKBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/LinkedNotebook.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/Notebook.h>
#include <qevercloud/types/Resource.h>
#include <qevercloud/types/SavedSearch.h>
#include <qevercloud/types/SyncChunk.h>
#include <qevercloud/types/Tag.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SyncChunkBuilder
{
public:
    SyncChunkBuilder();

    SyncChunkBuilder(SyncChunkBuilder && other) noexcept;

    ~SyncChunkBuilder() noexcept;

    SyncChunkBuilder & operator=(SyncChunkBuilder && other) noexcept;

    SyncChunkBuilder & setCurrentTime(Timestamp currentTime);
    SyncChunkBuilder & setChunkHighUSN(std::optional<qint32> chunkHighUSN);
    SyncChunkBuilder & setUpdateCount(qint32 updateCount);
    SyncChunkBuilder & setNotes(std::optional<QList<Note>> notes);
    SyncChunkBuilder & setNotebooks(std::optional<QList<Notebook>> notebooks);
    SyncChunkBuilder & setTags(std::optional<QList<Tag>> tags);
    SyncChunkBuilder & setSearches(std::optional<QList<SavedSearch>> searches);
    SyncChunkBuilder & setResources(std::optional<QList<Resource>> resources);
    SyncChunkBuilder & setExpungedNotes(std::optional<QList<Guid>> expungedNotes);
    SyncChunkBuilder & setExpungedNotebooks(std::optional<QList<Guid>> expungedNotebooks);
    SyncChunkBuilder & setExpungedTags(std::optional<QList<Guid>> expungedTags);
    SyncChunkBuilder & setExpungedSearches(std::optional<QList<Guid>> expungedSearches);
    SyncChunkBuilder & setLinkedNotebooks(std::optional<QList<LinkedNotebook>> linkedNotebooks);
    SyncChunkBuilder & setExpungedLinkedNotebooks(std::optional<QList<Guid>> expungedLinkedNotebooks);

    [[nodiscard]] SyncChunk build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNKBUILDER
