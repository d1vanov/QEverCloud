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

#include <generated/types/Tag.h>

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

QString Tag::localId() const
{
    return d->m_localId;
}

void Tag::setLocalId(QString id)
{
    d->m_localId = id;
}

QString Tag::parentLocalId() const
{
    return d->m_parentLocalId;
}

void Tag::setParentLocalId(QString id)
{
    d->m_parentLocalId = id;
}

bool Tag::isLocallyModified() const
{
    return d->m_locallyModified;
}

void Tag::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool Tag::isLocalOnly() const
{
    return d->m_localOnly;
}

void Tag::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool Tag::isLocallyFavorited() const
{
    return d->m_locallyFavorited;
}

void Tag::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
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

bool Tag::operator==(const Tag & other) const noexcept
{
    return *d == *other.d;
}

bool Tag::operator!=(const Tag & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
