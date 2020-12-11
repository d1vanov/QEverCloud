/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/types/Note.h>

#include "data/NoteData.h"

namespace qevercloud {

Note::Note() : d(new NoteData) {}

Note::Note(const Note & other) : d(other.d) {}

Note::Note(Note && other) noexcept : d(std::move(other.d))
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

QString Note::localId() const
{
    return d->m_localId;
}

void Note::setLocalId(QString id)
{
    d->m_localId = id;
}

QString Note::parentLocalId() const
{
    return d->m_parentLocalId;
}

void Note::setParentLocalId(QString id)
{
    d->m_parentLocalId = id;
}

bool Note::isLocallyModified() const
{
    return d->m_locallyModified;
}

void Note::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool Note::isLocalOnly() const
{
    return d->m_localOnly;
}

void Note::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool Note::isLocallyFavorited() const
{
    return d->m_locallyFavorited;
}

void Note::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
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

bool Note::operator==(const Note & other) const noexcept
{
    return *d == *other.d;
}

bool Note::operator!=(const Note & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
