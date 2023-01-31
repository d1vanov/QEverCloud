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

#include <qevercloud/types/SavedSearch.h>

#include "impl/SavedSearchImpl.h"

namespace qevercloud {

SavedSearch::SavedSearch() :
    d(new SavedSearch::Impl)
{}

SavedSearch::SavedSearch(const SavedSearch & other) :
    d(other.d)
{}

SavedSearch::SavedSearch(SavedSearch && other) noexcept :
    d(std::move(other.d))
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

const QString & SavedSearch::localId() const noexcept
{
    return d->m_localId;
}

void SavedSearch::setLocalId(QString localId)
{
    d->m_localId = localId;
}

bool SavedSearch::isLocallyModified() const noexcept
{
    return d->m_isLocallyModified;
}

void SavedSearch::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
}

bool SavedSearch::isLocalOnly() const noexcept
{
    return d->m_isLocalOnly;
}

void SavedSearch::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
}

bool SavedSearch::isLocallyFavorited() const noexcept
{
    return d->m_isLocallyFavorited;
}

void SavedSearch::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
}

const QHash<QString, QVariant> & SavedSearch::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & SavedSearch::mutableLocalData()
{
    return d->m_localData;
}

void SavedSearch::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = localData;
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

QTextStream & operator<<(QTextStream & strm, const SavedSearch & savedSearch)
{
    strm << static_cast<const Printable&>(savedSearch);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const SavedSearch & savedSearch)
{
    dbg << static_cast<const Printable&>(savedSearch);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const SavedSearch & savedSearch)
{
    strm << static_cast<const Printable&>(savedSearch);
    return strm;
}

bool operator==(const SavedSearch & lhs, const SavedSearch & rhs) noexcept
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
        lhs.guid() == rhs.guid() &&
        lhs.name() == rhs.name() &&
        lhs.query() == rhs.query() &&
        lhs.format() == rhs.format() &&
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.scope() == rhs.scope();
}

bool operator!=(const SavedSearch & lhs, const SavedSearch & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
