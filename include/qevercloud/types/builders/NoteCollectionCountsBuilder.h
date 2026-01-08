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

#ifndef QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSBUILDER
#define QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSBUILDER

#include <qevercloud/Export.h>

#include "QMap"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteCollectionCounts.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteCollectionCountsBuilder
{
public:
    NoteCollectionCountsBuilder();

    NoteCollectionCountsBuilder(NoteCollectionCountsBuilder && other) noexcept;

    ~NoteCollectionCountsBuilder() noexcept;

    NoteCollectionCountsBuilder & operator=(NoteCollectionCountsBuilder && other) noexcept;

    NoteCollectionCountsBuilder & setNotebookCounts(std::optional<QMap<Guid, qint32>> notebookCounts);
    NoteCollectionCountsBuilder & setTagCounts(std::optional<QMap<Guid, qint32>> tagCounts);
    NoteCollectionCountsBuilder & setTrashCount(std::optional<qint32> trashCount);

    [[nodiscard]] NoteCollectionCounts build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSBUILDER
