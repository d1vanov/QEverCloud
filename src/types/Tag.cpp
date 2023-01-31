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

#include <qevercloud/types/Tag.h>

#include "impl/TagImpl.h"

namespace qevercloud {

Tag::Tag() :
    d(new Tag::Impl)
{}

Tag::Tag(const Tag & other) :
    d(other.d)
{}

Tag::Tag(Tag && other) noexcept :
    d(std::move(other.d))
{}

Tag::~Tag() noexcept {}

Tag & Tag::operator=(const Tag & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Tag & Tag::operator=(Tag && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QString & Tag::localId() const noexcept
{
    return d->m_localId;
}

void Tag::setLocalId(QString localId)
{
    d->m_localId = localId;
}

bool Tag::isLocallyModified() const noexcept
{
    return d->m_isLocallyModified;
}

void Tag::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
}

bool Tag::isLocalOnly() const noexcept
{
    return d->m_isLocalOnly;
}

void Tag::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
}

bool Tag::isLocallyFavorited() const noexcept
{
    return d->m_isLocallyFavorited;
}

void Tag::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
}

const QHash<QString, QVariant> & Tag::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & Tag::mutableLocalData()
{
    return d->m_localData;
}

void Tag::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = localData;
}

const std::optional<Guid> & Tag::linkedNotebookGuid() const noexcept
{
    return d->m_linkedNotebookGuid;
}

std::optional<Guid> & Tag::mutableLinkedNotebookGuid()
{
    return d->m_linkedNotebookGuid;
}

void Tag::setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid)
{
    d->m_linkedNotebookGuid = linkedNotebookGuid;
}

const QString & Tag::parentTagLocalId() const noexcept
{
    return d->m_parentTagLocalId;
}

void Tag::setParentTagLocalId(QString parentTagLocalId)
{
    d->m_parentTagLocalId = parentTagLocalId;
}

const std::optional<Guid> & Tag::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & Tag::mutableGuid()
{
    return d->m_guid;
}

void Tag::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & Tag::name() const noexcept
{
    return d->m_name;
}

void Tag::setName(std::optional<QString> name)
{
    d->m_name = name;
}

const std::optional<Guid> & Tag::parentGuid() const noexcept
{
    return d->m_parentGuid;
}

std::optional<Guid> & Tag::mutableParentGuid()
{
    return d->m_parentGuid;
}

void Tag::setParentGuid(std::optional<Guid> parentGuid)
{
    d->m_parentGuid = parentGuid;
}

const std::optional<qint32> & Tag::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & Tag::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void Tag::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

void Tag::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const Tag & tag)
{
    strm << static_cast<const Printable&>(tag);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Tag & tag)
{
    dbg << static_cast<const Printable&>(tag);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Tag & tag)
{
    strm << static_cast<const Printable&>(tag);
    return strm;
}

bool operator==(const Tag & lhs, const Tag & rhs) noexcept
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
        lhs.linkedNotebookGuid() == rhs.linkedNotebookGuid() &&
        lhs.parentTagLocalId() == rhs.parentTagLocalId() &&
        lhs.guid() == rhs.guid() &&
        lhs.name() == rhs.name() &&
        lhs.parentGuid() == rhs.parentGuid() &&
        lhs.updateSequenceNum() == rhs.updateSequenceNum();
}

bool operator!=(const Tag & lhs, const Tag & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud