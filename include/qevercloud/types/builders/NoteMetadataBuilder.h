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

#ifndef QEVERCLOUD_GENERATED_NOTEMETADATABUILDER
#define QEVERCLOUD_GENERATED_NOTEMETADATABUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteAttributes.h>
#include <qevercloud/types/NoteMetadata.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QList>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteMetadataBuilder
{
public:
    NoteMetadataBuilder();

    NoteMetadataBuilder(NoteMetadataBuilder && other) noexcept;

    ~NoteMetadataBuilder() noexcept;

    NoteMetadataBuilder & operator=(NoteMetadataBuilder && other) noexcept;

    NoteMetadataBuilder & setLocalId(QString localId);
    NoteMetadataBuilder & setLocallyModified(bool isLocallyModified);
    NoteMetadataBuilder & setLocalOnly(bool isLocalOnly);
    NoteMetadataBuilder & setLocallyFavorited(bool isLocallyFavorited);
    NoteMetadataBuilder & setLocalData(QHash<QString, QVariant> localData);
    NoteMetadataBuilder & setGuid(Guid guid);
    NoteMetadataBuilder & setTitle(std::optional<QString> title);
    NoteMetadataBuilder & setContentLength(std::optional<qint32> contentLength);
    NoteMetadataBuilder & setCreated(std::optional<Timestamp> created);
    NoteMetadataBuilder & setUpdated(std::optional<Timestamp> updated);
    NoteMetadataBuilder & setDeleted(std::optional<Timestamp> deleted);
    NoteMetadataBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    NoteMetadataBuilder & setNotebookGuid(std::optional<QString> notebookGuid);
    NoteMetadataBuilder & setTagGuids(std::optional<QList<Guid>> tagGuids);
    NoteMetadataBuilder & setAttributes(std::optional<NoteAttributes> attributes);
    NoteMetadataBuilder & setLargestResourceMime(std::optional<QString> largestResourceMime);
    NoteMetadataBuilder & setLargestResourceSize(std::optional<qint32> largestResourceSize);

    [[nodiscard]] NoteMetadata build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMETADATABUILDER
