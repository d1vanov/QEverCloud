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

#include <qevercloud/types/builders/NoteMetadataBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteMetadataBuilder::Impl final:
    public QSharedData
{
public:
    Guid m_guid;
    std::optional<QString> m_title;
    std::optional<qint32> m_contentLength;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_updated;
    std::optional<Timestamp> m_deleted;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<NoteAttributes> m_attributes;
    std::optional<QString> m_largestResourceMime;
    std::optional<qint32> m_largestResourceSize;
    QString m_localId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
};

NoteMetadataBuilder::NoteMetadataBuilder() :
    d(new NoteMetadataBuilder::Impl)
{}

NoteMetadataBuilder::NoteMetadataBuilder(NoteMetadataBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteMetadataBuilder::~NoteMetadataBuilder() noexcept = default;

NoteMetadataBuilder & NoteMetadataBuilder::operator=(NoteMetadataBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setGuid(Guid guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setTitle(std::optional<QString> title)
{
    d->m_title = std::move(title);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setContentLength(std::optional<qint32> contentLength)
{
    d->m_contentLength = std::move(contentLength);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setCreated(std::optional<Timestamp> created)
{
    d->m_created = std::move(created);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = std::move(deleted);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = std::move(tagGuids);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setAttributes(std::optional<NoteAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLargestResourceMime(std::optional<QString> largestResourceMime)
{
    d->m_largestResourceMime = std::move(largestResourceMime);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLargestResourceSize(std::optional<qint32> largestResourceSize)
{
    d->m_largestResourceSize = std::move(largestResourceSize);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

NoteMetadataBuilder & NoteMetadataBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

NoteMetadataBuilder &NoteMetadataBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

NoteMetadata NoteMetadataBuilder::build()
{
    NoteMetadata result;

    result.setGuid(std::move(d->m_guid));
    result.setTitle(std::move(d->m_title));
    result.setContentLength(std::move(d->m_contentLength));
    result.setCreated(std::move(d->m_created));
    result.setUpdated(std::move(d->m_updated));
    result.setDeleted(std::move(d->m_deleted));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setTagGuids(std::move(d->m_tagGuids));
    result.setAttributes(std::move(d->m_attributes));
    result.setLargestResourceMime(std::move(d->m_largestResourceMime));
    result.setLargestResourceSize(std::move(d->m_largestResourceSize));
    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));

    d->m_guid = Guid{};
    d->m_title = {};
    d->m_contentLength = {};
    d->m_created = {};
    d->m_updated = {};
    d->m_deleted = {};
    d->m_updateSequenceNum = {};
    d->m_notebookGuid = {};
    d->m_tagGuids = {};
    d->m_attributes = {};
    d->m_largestResourceMime = {};
    d->m_largestResourceSize = {};
    d->m_localId = QString{};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};

    return result;
}

} // namespace qevercloud
