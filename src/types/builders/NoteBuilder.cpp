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

#include <qevercloud/types/builders/NoteBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteBuilder::Impl final:
    public QSharedData
{
public:
    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    QString m_notebookLocalId;
    QStringList m_tagLocalIds;
    QByteArray m_thumbnailData;
    std::optional<Guid> m_guid;
    std::optional<QString> m_title;
    std::optional<QString> m_content;
    std::optional<QByteArray> m_contentHash;
    std::optional<qint32> m_contentLength;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_updated;
    std::optional<Timestamp> m_deleted;
    std::optional<bool> m_active;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<QList<Resource>> m_resources;
    std::optional<NoteAttributes> m_attributes;
    std::optional<QStringList> m_tagNames;
    std::optional<QList<SharedNote>> m_sharedNotes;
    std::optional<NoteRestrictions> m_restrictions;
    std::optional<NoteLimits> m_limits;
};

NoteBuilder::NoteBuilder() :
    d(new NoteBuilder::Impl)
{}

NoteBuilder::NoteBuilder(NoteBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteBuilder::~NoteBuilder() noexcept = default;

NoteBuilder & NoteBuilder::operator=(NoteBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteBuilder & NoteBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

NoteBuilder & NoteBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

NoteBuilder & NoteBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

NoteBuilder & NoteBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

NoteBuilder & NoteBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

NoteBuilder & NoteBuilder::setNotebookLocalId(QString notebookLocalId)
{
    d->m_notebookLocalId = std::move(notebookLocalId);
    return *this;
}

NoteBuilder & NoteBuilder::setTagLocalIds(QStringList tagLocalIds)
{
    d->m_tagLocalIds = std::move(tagLocalIds);
    return *this;
}

NoteBuilder & NoteBuilder::setThumbnailData(QByteArray thumbnailData)
{
    d->m_thumbnailData = std::move(thumbnailData);
    return *this;
}

NoteBuilder & NoteBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

NoteBuilder & NoteBuilder::setTitle(std::optional<QString> title)
{
    d->m_title = std::move(title);
    return *this;
}

NoteBuilder & NoteBuilder::setContent(std::optional<QString> content)
{
    d->m_content = std::move(content);
    return *this;
}

NoteBuilder & NoteBuilder::setContentHash(std::optional<QByteArray> contentHash)
{
    d->m_contentHash = std::move(contentHash);
    return *this;
}

NoteBuilder & NoteBuilder::setContentLength(std::optional<qint32> contentLength)
{
    d->m_contentLength = std::move(contentLength);
    return *this;
}

NoteBuilder & NoteBuilder::setCreated(std::optional<Timestamp> created)
{
    d->m_created = std::move(created);
    return *this;
}

NoteBuilder & NoteBuilder::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

NoteBuilder & NoteBuilder::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = std::move(deleted);
    return *this;
}

NoteBuilder & NoteBuilder::setActive(std::optional<bool> active)
{
    d->m_active = std::move(active);
    return *this;
}

NoteBuilder & NoteBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

NoteBuilder & NoteBuilder::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

NoteBuilder & NoteBuilder::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = std::move(tagGuids);
    return *this;
}

NoteBuilder & NoteBuilder::setResources(std::optional<QList<Resource>> resources)
{
    d->m_resources = std::move(resources);
    return *this;
}

NoteBuilder & NoteBuilder::setAttributes(std::optional<NoteAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
    return *this;
}

NoteBuilder & NoteBuilder::setTagNames(std::optional<QStringList> tagNames)
{
    d->m_tagNames = std::move(tagNames);
    return *this;
}

NoteBuilder & NoteBuilder::setSharedNotes(std::optional<QList<SharedNote>> sharedNotes)
{
    d->m_sharedNotes = std::move(sharedNotes);
    return *this;
}

NoteBuilder & NoteBuilder::setRestrictions(std::optional<NoteRestrictions> restrictions)
{
    d->m_restrictions = std::move(restrictions);
    return *this;
}

NoteBuilder & NoteBuilder::setLimits(std::optional<NoteLimits> limits)
{
    d->m_limits = std::move(limits);
    return *this;
}

Note NoteBuilder::build()
{
    Note result;

    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setNotebookLocalId(std::move(d->m_notebookLocalId));
    result.setTagLocalIds(std::move(d->m_tagLocalIds));
    result.setThumbnailData(std::move(d->m_thumbnailData));
    result.setGuid(std::move(d->m_guid));
    result.setTitle(std::move(d->m_title));
    result.setContent(std::move(d->m_content));
    result.setContentHash(std::move(d->m_contentHash));
    result.setContentLength(std::move(d->m_contentLength));
    result.setCreated(std::move(d->m_created));
    result.setUpdated(std::move(d->m_updated));
    result.setDeleted(std::move(d->m_deleted));
    result.setActive(std::move(d->m_active));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setTagGuids(std::move(d->m_tagGuids));
    result.setResources(std::move(d->m_resources));
    result.setAttributes(std::move(d->m_attributes));
    result.setTagNames(std::move(d->m_tagNames));
    result.setSharedNotes(std::move(d->m_sharedNotes));
    result.setRestrictions(std::move(d->m_restrictions));
    result.setLimits(std::move(d->m_limits));

    d->m_localId = QString{};
    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_notebookLocalId = QString{};
    d->m_tagLocalIds = QStringList{};
    d->m_thumbnailData = {};
    d->m_guid = {};
    d->m_title = {};
    d->m_content = {};
    d->m_contentHash = {};
    d->m_contentLength = {};
    d->m_created = {};
    d->m_updated = {};
    d->m_deleted = {};
    d->m_active = {};
    d->m_updateSequenceNum = {};
    d->m_notebookGuid = {};
    d->m_tagGuids = {};
    d->m_resources = {};
    d->m_attributes = {};
    d->m_tagNames = {};
    d->m_sharedNotes = {};
    d->m_restrictions = {};
    d->m_limits = {};

    return result;
}

} // namespace qevercloud
