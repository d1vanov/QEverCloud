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

#include <generated/types/SavedSearch.h>

#include "impl/SavedSearchImpl.h"

namespace qevercloud {

SavedSearch::SavedSearch() : d(new SavedSearch::Impl) {}

SavedSearch::SavedSearch(const SavedSearch & other) : d(other.d) {}

SavedSearch::SavedSearch(SavedSearch && other) noexcept : d(std::move(other.d))
{}

SavedSearch::~SavedSearch() noexcept {}

SavedSearch & SavedSearch::operator=(const SavedSearch & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SavedSearch & SavedSearch::operator=(SavedSearch && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

QString SavedSearch::localId() const
{
    return d->m_localId;
}

void SavedSearch::setLocalId(QString id)
{
    d->m_localId = id;
}

QString SavedSearch::parentLocalId() const
{
    return d->m_parentLocalId;
}

void SavedSearch::setParentLocalId(QString id)
{
    d->m_parentLocalId = id;
}

bool SavedSearch::isLocallyModified() const
{
    return d->m_locallyModified;
}

void SavedSearch::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool SavedSearch::isLocalOnly() const
{
    return d->m_localOnly;
}

void SavedSearch::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool SavedSearch::isLocallyFavorited() const
{
    return d->m_locallyFavorited;
}

void SavedSearch::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const std::optional<Guid> & SavedSearch::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & SavedSearch::mutableGuid()
{
    return d->m_guid;
}

void SavedSearch::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & SavedSearch::name() const noexcept
{
    return d->m_name;
}

void SavedSearch::setName(std::optional<QString> name)
{
    d->m_name = name;
}

const std::optional<QString> & SavedSearch::query() const noexcept
{
    return d->m_query;
}

void SavedSearch::setQuery(std::optional<QString> query)
{
    d->m_query = query;
}

const std::optional<QueryFormat> & SavedSearch::format() const noexcept
{
    return d->m_format;
}

std::optional<QueryFormat> & SavedSearch::mutableFormat()
{
    return d->m_format;
}

void SavedSearch::setFormat(std::optional<QueryFormat> format)
{
    d->m_format = format;
}

const std::optional<qint32> & SavedSearch::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & SavedSearch::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void SavedSearch::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<SavedSearchScope> & SavedSearch::scope() const noexcept
{
    return d->m_scope;
}

std::optional<SavedSearchScope> & SavedSearch::mutableScope()
{
    return d->m_scope;
}

void SavedSearch::setScope(std::optional<SavedSearchScope> scope)
{
    d->m_scope = scope;
}

void SavedSearch::print(QTextStream & strm) const
{
    d->print(strm);
}

bool SavedSearch::operator==(const SavedSearch & other) const noexcept
{
    return *d == *other.d;
}

bool SavedSearch::operator!=(const SavedSearch & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
