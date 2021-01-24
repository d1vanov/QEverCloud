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

#include <qevercloud/generated/types/Resource.h>

#include "impl/ResourceImpl.h"

namespace qevercloud {

Resource::Resource() :
    d(new Resource::Impl)
 {}

Resource::Resource(const Resource & other) :
    d(other.d)
{}

Resource::Resource(Resource && other) noexcept :
    d(std::move(other.d))
{}

Resource::~Resource() noexcept {}

Resource & Resource::operator=(const Resource & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Resource & Resource::operator=(Resource && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

QString Resource::noteLocalId() const
{
    return d->m_noteLocalId;
}

void Resource::setNoteLocalId(QString noteLocalId)
{
    d->m_noteLocalId = std::move(noteLocalId);
}

const std::optional<int> & Resource::indexInNote() const noexcept
{
    return d->m_indexInNote;
}

void Resource::setIndexInNote(std::optional<int> indexInNote)
{
    d->m_indexInNote = std::move(indexInNote);
}

QString Resource::localId() const noexcept
{
    return d->m_localId;
}

void Resource::setLocalId(QString id)
{
    d->m_localId = id;
}

bool Resource::isLocallyModified() const noexcept
{
    return d->m_locallyModified;
}

void Resource::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool Resource::isLocalOnly() const noexcept
{
    return d->m_localOnly;
}

void Resource::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool Resource::isLocallyFavorited() const noexcept
{
    return d->m_locallyFavorited;
}

void Resource::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const QHash<QString, QVariant> & Resource::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & Resource::mutableLocalData()
{
    return d->m_localData;
}

void Resource::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
}

const std::optional<Guid> & Resource::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & Resource::mutableGuid()
{
    return d->m_guid;
}

void Resource::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<Guid> & Resource::noteGuid() const noexcept
{
    return d->m_noteGuid;
}

std::optional<Guid> & Resource::mutableNoteGuid()
{
    return d->m_noteGuid;
}

void Resource::setNoteGuid(std::optional<Guid> noteGuid)
{
    d->m_noteGuid = noteGuid;
}

const std::optional<Data> & Resource::data() const noexcept
{
    return d->m_data;
}

std::optional<Data> & Resource::mutableData()
{
    return d->m_data;
}

void Resource::setData(std::optional<Data> data)
{
    d->m_data = data;
}

const std::optional<QString> & Resource::mime() const noexcept
{
    return d->m_mime;
}

void Resource::setMime(std::optional<QString> mime)
{
    d->m_mime = mime;
}

const std::optional<qint16> & Resource::width() const noexcept
{
    return d->m_width;
}

std::optional<qint16> & Resource::mutableWidth()
{
    return d->m_width;
}

void Resource::setWidth(std::optional<qint16> width)
{
    d->m_width = width;
}

const std::optional<qint16> & Resource::height() const noexcept
{
    return d->m_height;
}

std::optional<qint16> & Resource::mutableHeight()
{
    return d->m_height;
}

void Resource::setHeight(std::optional<qint16> height)
{
    d->m_height = height;
}

const std::optional<qint16> & Resource::duration() const noexcept
{
    return d->m_duration;
}

std::optional<qint16> & Resource::mutableDuration()
{
    return d->m_duration;
}

void Resource::setDuration(std::optional<qint16> duration)
{
    d->m_duration = duration;
}

const std::optional<bool> & Resource::active() const noexcept
{
    return d->m_active;
}

std::optional<bool> & Resource::mutableActive()
{
    return d->m_active;
}

void Resource::setActive(std::optional<bool> active)
{
    d->m_active = active;
}

const std::optional<Data> & Resource::recognition() const noexcept
{
    return d->m_recognition;
}

std::optional<Data> & Resource::mutableRecognition()
{
    return d->m_recognition;
}

void Resource::setRecognition(std::optional<Data> recognition)
{
    d->m_recognition = recognition;
}

const std::optional<ResourceAttributes> & Resource::attributes() const noexcept
{
    return d->m_attributes;
}

std::optional<ResourceAttributes> & Resource::mutableAttributes()
{
    return d->m_attributes;
}

void Resource::setAttributes(std::optional<ResourceAttributes> attributes)
{
    d->m_attributes = attributes;
}

const std::optional<qint32> & Resource::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & Resource::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void Resource::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<Data> & Resource::alternateData() const noexcept
{
    return d->m_alternateData;
}

std::optional<Data> & Resource::mutableAlternateData()
{
    return d->m_alternateData;
}

void Resource::setAlternateData(std::optional<Data> alternateData)
{
    d->m_alternateData = alternateData;
}

void Resource::print(QTextStream & strm) const
{
    d->print(strm);
}

bool Resource::operator==(const Resource & other) const noexcept
{
    return *d == *other.d;
}

bool Resource::operator!=(const Resource & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
