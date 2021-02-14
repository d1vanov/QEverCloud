/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/generated/types/NoteMetadata.h>

#include "impl/NoteMetadataImpl.h"

namespace qevercloud {

NoteMetadata::NoteMetadata() :
    d(new NoteMetadata::Impl)
 {}

NoteMetadata::NoteMetadata(const NoteMetadata & other) :
    d(other.d)
{}

NoteMetadata::NoteMetadata(NoteMetadata && other) noexcept :
    d(std::move(other.d))
{}

NoteMetadata::~NoteMetadata() noexcept {}

NoteMetadata & NoteMetadata::operator=(const NoteMetadata & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteMetadata & NoteMetadata::operator=(NoteMetadata && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QString & NoteMetadata::localId() const noexcept
{
    return d->m_localId;
}

void NoteMetadata::setLocalId(QString id)
{
    d->m_localId = std::move(id);
}

bool NoteMetadata::isLocallyModified() const noexcept
{
    return d->m_locallyModified;
}

void NoteMetadata::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool NoteMetadata::isLocalOnly() const noexcept
{
    return d->m_localOnly;
}

void NoteMetadata::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool NoteMetadata::isLocallyFavorited() const noexcept
{
    return d->m_locallyFavorited;
}

void NoteMetadata::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const QHash<QString, QVariant> & NoteMetadata::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & NoteMetadata::mutableLocalData()
{
    return d->m_localData;
}

void NoteMetadata::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
}

const Guid & NoteMetadata::guid() const noexcept
{
    return d->m_guid;
}

Guid & NoteMetadata::mutableGuid()
{
    return d->m_guid;
}

void NoteMetadata::setGuid(Guid guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & NoteMetadata::title() const noexcept
{
    return d->m_title;
}

void NoteMetadata::setTitle(std::optional<QString> title)
{
    d->m_title = title;
}

const std::optional<qint32> & NoteMetadata::contentLength() const noexcept
{
    return d->m_contentLength;
}

std::optional<qint32> & NoteMetadata::mutableContentLength()
{
    return d->m_contentLength;
}

void NoteMetadata::setContentLength(std::optional<qint32> contentLength)
{
    d->m_contentLength = contentLength;
}

const std::optional<Timestamp> & NoteMetadata::created() const noexcept
{
    return d->m_created;
}

std::optional<Timestamp> & NoteMetadata::mutableCreated()
{
    return d->m_created;
}

void NoteMetadata::setCreated(std::optional<Timestamp> created)
{
    d->m_created = created;
}

const std::optional<Timestamp> & NoteMetadata::updated() const noexcept
{
    return d->m_updated;
}

std::optional<Timestamp> & NoteMetadata::mutableUpdated()
{
    return d->m_updated;
}

void NoteMetadata::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = updated;
}

const std::optional<Timestamp> & NoteMetadata::deleted() const noexcept
{
    return d->m_deleted;
}

std::optional<Timestamp> & NoteMetadata::mutableDeleted()
{
    return d->m_deleted;
}

void NoteMetadata::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = deleted;
}

const std::optional<qint32> & NoteMetadata::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & NoteMetadata::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void NoteMetadata::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<QString> & NoteMetadata::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

void NoteMetadata::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<QList<Guid>> & NoteMetadata::tagGuids() const noexcept
{
    return d->m_tagGuids;
}

std::optional<QList<Guid>> & NoteMetadata::mutableTagGuids()
{
    return d->m_tagGuids;
}

void NoteMetadata::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = tagGuids;
}

const std::optional<NoteAttributes> & NoteMetadata::attributes() const noexcept
{
    return d->m_attributes;
}

std::optional<NoteAttributes> & NoteMetadata::mutableAttributes()
{
    return d->m_attributes;
}

void NoteMetadata::setAttributes(std::optional<NoteAttributes> attributes)
{
    d->m_attributes = attributes;
}

const std::optional<QString> & NoteMetadata::largestResourceMime() const noexcept
{
    return d->m_largestResourceMime;
}

void NoteMetadata::setLargestResourceMime(std::optional<QString> largestResourceMime)
{
    d->m_largestResourceMime = largestResourceMime;
}

const std::optional<qint32> & NoteMetadata::largestResourceSize() const noexcept
{
    return d->m_largestResourceSize;
}

std::optional<qint32> & NoteMetadata::mutableLargestResourceSize()
{
    return d->m_largestResourceSize;
}

void NoteMetadata::setLargestResourceSize(std::optional<qint32> largestResourceSize)
{
    d->m_largestResourceSize = largestResourceSize;
}

void NoteMetadata::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteMetadata::operator==(const NoteMetadata & other) const noexcept
{
    return *d == *other.d;
}

bool NoteMetadata::operator!=(const NoteMetadata & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
