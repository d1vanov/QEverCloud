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

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNKFILTERBUILDER
#define QEVERCLOUD_GENERATED_SYNCCHUNKFILTERBUILDER

#include <qevercloud/Export.h>

#include "QSet"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SyncChunkFilter.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SyncChunkFilterBuilder
{
public:
    SyncChunkFilterBuilder();

    SyncChunkFilterBuilder(SyncChunkFilterBuilder && other) noexcept;

    ~SyncChunkFilterBuilder() noexcept;

    SyncChunkFilterBuilder & operator=(SyncChunkFilterBuilder && other) noexcept;

    SyncChunkFilterBuilder & setIncludeNotes(std::optional<bool> includeNotes);
    SyncChunkFilterBuilder & setIncludeNoteResources(std::optional<bool> includeNoteResources);
    SyncChunkFilterBuilder & setIncludeNoteAttributes(std::optional<bool> includeNoteAttributes);
    SyncChunkFilterBuilder & setIncludeNotebooks(std::optional<bool> includeNotebooks);
    SyncChunkFilterBuilder & setIncludeTags(std::optional<bool> includeTags);
    SyncChunkFilterBuilder & setIncludeSearches(std::optional<bool> includeSearches);
    SyncChunkFilterBuilder & setIncludeResources(std::optional<bool> includeResources);
    SyncChunkFilterBuilder & setIncludeLinkedNotebooks(std::optional<bool> includeLinkedNotebooks);
    SyncChunkFilterBuilder & setIncludeExpunged(std::optional<bool> includeExpunged);
    SyncChunkFilterBuilder & setIncludeNoteApplicationDataFullMap(std::optional<bool> includeNoteApplicationDataFullMap);
    SyncChunkFilterBuilder & setIncludeResourceApplicationDataFullMap(std::optional<bool> includeResourceApplicationDataFullMap);
    SyncChunkFilterBuilder & setIncludeNoteResourceApplicationDataFullMap(std::optional<bool> includeNoteResourceApplicationDataFullMap);
    SyncChunkFilterBuilder & setIncludeSharedNotes(std::optional<bool> includeSharedNotes);
    SyncChunkFilterBuilder & setOmitSharedNotebooks(std::optional<bool> omitSharedNotebooks);
    SyncChunkFilterBuilder & setRequireNoteContentClass(std::optional<QString> requireNoteContentClass);
    SyncChunkFilterBuilder & setNotebookGuids(std::optional<QSet<QString>> notebookGuids);

    [[nodiscard]] SyncChunkFilter build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNKFILTERBUILDER
