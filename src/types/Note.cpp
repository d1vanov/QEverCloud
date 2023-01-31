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

#include <qevercloud/types/Note.h>

#include "impl/NoteImpl.h"

namespace qevercloud {

Note::Note() :
    d(new Note::Impl)
{}

Note::Note(const Note & other) :
    d(other.d)
{}

Note::Note(Note && other) noexcept :
    d(std::move(other.d))
{}

Note::~Note() noexcept {}

Note & Note::operator=(const Note & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Note & Note::operator=(Note && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QString & Note::localId() const noexcept
{
    return d->m_localId;
}

void Note::setLocalId(QString localId)
{
    d->m_localId = localId;
}

bool Note::isLocallyModified() const noexcept
{
    return d->m_isLocallyModified;
}

void Note::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
}

bool Note::isLocalOnly() const noexcept
{
    return d->m_isLocalOnly;
}

void Note::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
}

bool Note::isLocallyFavorited() const noexcept
{
    return d->m_isLocallyFavorited;
}

void Note::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
}

const QHash<QString, QVariant> & Note::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & Note::mutableLocalData()
{
    return d->m_localData;
}

void Note::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = localData;
}

const QString & Note::notebookLocalId() const noexcept
{
    return d->m_notebookLocalId;
}

void Note::setNotebookLocalId(QString notebookLocalId)
{
    d->m_notebookLocalId = notebookLocalId;
}

const QStringList & Note::tagLocalIds() const noexcept
{
    return d->m_tagLocalIds;
}

QStringList & Note::mutableTagLocalIds()
{
    return d->m_tagLocalIds;
}

void Note::setTagLocalIds(QStringList tagLocalIds)
{
    d->m_tagLocalIds = tagLocalIds;
}

const QByteArray & Note::thumbnailData() const noexcept
{
    return d->m_thumbnailData;
}

void Note::setThumbnailData(QByteArray thumbnailData)
{
    d->m_thumbnailData = thumbnailData;
}

const std::optional<Guid> & Note::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & Note::mutableGuid()
{
    return d->m_guid;
}

void Note::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & Note::title() const noexcept
{
    return d->m_title;
}

void Note::setTitle(std::optional<QString> title)
{
    d->m_title = title;
}

const std::optional<QString> & Note::content() const noexcept
{
    return d->m_content;
}

void Note::setContent(std::optional<QString> content)
{
    d->m_content = content;
}

const std::optional<QByteArray> & Note::contentHash() const noexcept
{
    return d->m_contentHash;
}

void Note::setContentHash(std::optional<QByteArray> contentHash)
{
    d->m_contentHash = contentHash;
}

const std::optional<qint32> & Note::contentLength() const noexcept
{
    return d->m_contentLength;
}

std::optional<qint32> & Note::mutableContentLength()
{
    return d->m_contentLength;
}

void Note::setContentLength(std::optional<qint32> contentLength)
{
    d->m_contentLength = contentLength;
}

const std::optional<Timestamp> & Note::created() const noexcept
{
    return d->m_created;
}

std::optional<Timestamp> & Note::mutableCreated()
{
    return d->m_created;
}

void Note::setCreated(std::optional<Timestamp> created)
{
    d->m_created = created;
}

const std::optional<Timestamp> & Note::updated() const noexcept
{
    return d->m_updated;
}

std::optional<Timestamp> & Note::mutableUpdated()
{
    return d->m_updated;
}

void Note::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = updated;
}

const std::optional<Timestamp> & Note::deleted() const noexcept
{
    return d->m_deleted;
}

std::optional<Timestamp> & Note::mutableDeleted()
{
    return d->m_deleted;
}

void Note::setDeleted(std::optional<Timestamp> deleted)
{
    d->m_deleted = deleted;
}

const std::optional<bool> & Note::active() const noexcept
{
    return d->m_active;
}

std::optional<bool> & Note::mutableActive()
{
    return d->m_active;
}

void Note::setActive(std::optional<bool> active)
{
    d->m_active = active;
}

const std::optional<qint32> & Note::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & Note::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void Note::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<QString> & Note::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

void Note::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<QList<Guid>> & Note::tagGuids() const noexcept
{
    return d->m_tagGuids;
}

std::optional<QList<Guid>> & Note::mutableTagGuids()
{
    return d->m_tagGuids;
}

void Note::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = tagGuids;
}

const std::optional<QList<Resource>> & Note::resources() const noexcept
{
    return d->m_resources;
}

std::optional<QList<Resource>> & Note::mutableResources()
{
    return d->m_resources;
}

void Note::setResources(std::optional<QList<Resource>> resources)
{
    d->m_resources = resources;
}

const std::optional<NoteAttributes> & Note::attributes() const noexcept
{
    return d->m_attributes;
}

std::optional<NoteAttributes> & Note::mutableAttributes()
{
    return d->m_attributes;
}

void Note::setAttributes(std::optional<NoteAttributes> attributes)
{
    d->m_attributes = attributes;
}

const std::optional<QStringList> & Note::tagNames() const noexcept
{
    return d->m_tagNames;
}

std::optional<QStringList> & Note::mutableTagNames()
{
    return d->m_tagNames;
}

void Note::setTagNames(std::optional<QStringList> tagNames)
{
    d->m_tagNames = tagNames;
}

const std::optional<QList<SharedNote>> & Note::sharedNotes() const noexcept
{
    return d->m_sharedNotes;
}

std::optional<QList<SharedNote>> & Note::mutableSharedNotes()
{
    return d->m_sharedNotes;
}

void Note::setSharedNotes(std::optional<QList<SharedNote>> sharedNotes)
{
    d->m_sharedNotes = sharedNotes;
}

const std::optional<NoteRestrictions> & Note::restrictions() const noexcept
{
    return d->m_restrictions;
}

std::optional<NoteRestrictions> & Note::mutableRestrictions()
{
    return d->m_restrictions;
}

void Note::setRestrictions(std::optional<NoteRestrictions> restrictions)
{
    d->m_restrictions = restrictions;
}

const std::optional<NoteLimits> & Note::limits() const noexcept
{
    return d->m_limits;
}

std::optional<NoteLimits> & Note::mutableLimits()
{
    return d->m_limits;
}

void Note::setLimits(std::optional<NoteLimits> limits)
{
    d->m_limits = limits;
}

void Note::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const Note & note)
{
    strm << static_cast<const Printable&>(note);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Note & note)
{
    dbg << static_cast<const Printable&>(note);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Note & note)
{
    strm << static_cast<const Printable&>(note);
    return strm;
}

bool operator==(const Note & lhs, const Note & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.localId() == rhs.localId() &&
        lhs.isLocallyModified() == rhs.isLocallyModified() &&
        lhs.isLocalOnly() == rhs.isLocalOnly() &&
        lhs.isLocallyFavorited() == rhs.isLocallyFavorited() &&
        lhs.localData() == rhs.localData() &&
        lhs.notebookLocalId() == rhs.notebookLocalId() &&
        lhs.tagLocalIds() == rhs.tagLocalIds() &&
        lhs.thumbnailData() == rhs.thumbnailData() &&
        lhs.guid() == rhs.guid() &&
        lhs.title() == rhs.title() &&
        lhs.content() == rhs.content() &&
        lhs.contentHash() == rhs.contentHash() &&
        lhs.contentLength() == rhs.contentLength() &&
        lhs.created() == rhs.created() &&
        lhs.updated() == rhs.updated() &&
        lhs.deleted() == rhs.deleted() &&
        lhs.active() == rhs.active() &&
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.notebookGuid() == rhs.notebookGuid() &&
        lhs.tagGuids() == rhs.tagGuids() &&
        lhs.resources() == rhs.resources() &&
        lhs.attributes() == rhs.attributes() &&
        lhs.tagNames() == rhs.tagNames() &&
        lhs.sharedNotes() == rhs.sharedNotes() &&
        lhs.restrictions() == rhs.restrictions() &&
        lhs.limits() == rhs.limits();
}

bool operator!=(const Note & lhs, const Note & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
