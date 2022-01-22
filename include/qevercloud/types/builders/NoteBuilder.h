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

#ifndef QEVERCLOUD_GENERATED_NOTEBUILDER
#define QEVERCLOUD_GENERATED_NOTEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/NoteAttributes.h>
#include <qevercloud/types/NoteLimits.h>
#include <qevercloud/types/NoteRestrictions.h>
#include <qevercloud/types/Resource.h>
#include <qevercloud/types/SharedNote.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QHash>
#include <QList>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteBuilder
{
public:
    NoteBuilder();

    NoteBuilder(NoteBuilder && other) noexcept;

    ~NoteBuilder() noexcept;

    NoteBuilder & operator=(NoteBuilder && other) noexcept;

    NoteBuilder & setLocalId(QString localId);
    NoteBuilder & setLocallyModified(bool isLocallyModified);
    NoteBuilder & setLocalOnly(bool isLocalOnly);
    NoteBuilder & setLocallyFavorited(bool isLocallyFavorited);
    NoteBuilder & setLocalData(QHash<QString, QVariant> localData);
    NoteBuilder & setNotebookLocalId(QString notebookLocalId);
    NoteBuilder & setTagLocalIds(QStringList tagLocalIds);
    NoteBuilder & setThumbnailData(QByteArray thumbnailData);
    NoteBuilder & setGuid(std::optional<Guid> guid);
    NoteBuilder & setTitle(std::optional<QString> title);
    NoteBuilder & setContent(std::optional<QString> content);
    NoteBuilder & setContentHash(std::optional<QByteArray> contentHash);
    NoteBuilder & setContentLength(std::optional<qint32> contentLength);
    NoteBuilder & setCreated(std::optional<Timestamp> created);
    NoteBuilder & setUpdated(std::optional<Timestamp> updated);
    NoteBuilder & setDeleted(std::optional<Timestamp> deleted);
    NoteBuilder & setActive(std::optional<bool> active);
    NoteBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    NoteBuilder & setNotebookGuid(std::optional<QString> notebookGuid);
    NoteBuilder & setTagGuids(std::optional<QList<Guid>> tagGuids);
    NoteBuilder & setResources(std::optional<QList<Resource>> resources);
    NoteBuilder & setAttributes(std::optional<NoteAttributes> attributes);
    NoteBuilder & setTagNames(std::optional<QStringList> tagNames);
    NoteBuilder & setSharedNotes(std::optional<QList<SharedNote>> sharedNotes);
    NoteBuilder & setRestrictions(std::optional<NoteRestrictions> restrictions);
    NoteBuilder & setLimits(std::optional<NoteLimits> limits);

    [[nodiscard]] Note build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBUILDER
