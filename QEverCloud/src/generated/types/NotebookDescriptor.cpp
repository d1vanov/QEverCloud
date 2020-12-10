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

#include <generated/types/NotebookDescriptor.h>

#include "data/NotebookDescriptorData.h"

namespace qevercloud {

NotebookDescriptor::NotebookDescriptor() : d(new NotebookDescriptorData) {}

NotebookDescriptor::NotebookDescriptor(const NotebookDescriptor & other) : d(other.d) {}

NotebookDescriptor::NotebookDescriptor(NotebookDescriptor && other) noexcept : d(std::move(other.d))
{}

NotebookDescriptor::~NotebookDescriptor() noexcept {}

NotebookDescriptor & NotebookDescriptor::operator=(const NotebookDescriptor & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotebookDescriptor & NotebookDescriptor::operator=(NotebookDescriptor && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

QString NotebookDescriptor::localId() const
{
    return d->m_localId;
}

void NotebookDescriptor::setLocalId(QString id)
{
    d->m_localId = id;
}

QString NotebookDescriptor::parentLocalId() const
{
    return d->m_parentLocalId;
}

void NotebookDescriptor::setParentLocalId(QString id)
{
    d->m_parentLocalId = id;
}

bool NotebookDescriptor::isLocallyModified() const
{
    return d->m_locallyModified;
}

void NotebookDescriptor::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool NotebookDescriptor::isLocalOnly() const
{
    return d->m_localOnly;
}

void NotebookDescriptor::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool NotebookDescriptor::isLocallyFavorited() const
{
    return d->m_locallyFavorited;
}

const std::optional<Guid> & NotebookDescriptor::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & NotebookDescriptor::mutableGuid()
{
    return d->m_guid;
}

void NotebookDescriptor::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & NotebookDescriptor::notebookDisplayName() const noexcept
{
    return d->m_notebookDisplayName;
}

void NotebookDescriptor::setNotebookDisplayName(std::optional<QString> notebookDisplayName)
{
    d->m_notebookDisplayName = notebookDisplayName;
}

const std::optional<QString> & NotebookDescriptor::contactName() const noexcept
{
    return d->m_contactName;
}

void NotebookDescriptor::setContactName(std::optional<QString> contactName)
{
    d->m_contactName = contactName;
}

const std::optional<bool> & NotebookDescriptor::hasSharedNotebook() const noexcept
{
    return d->m_hasSharedNotebook;
}

std::optional<bool> & NotebookDescriptor::mutableHasSharedNotebook()
{
    return d->m_hasSharedNotebook;
}

void NotebookDescriptor::setHasSharedNotebook(std::optional<bool> hasSharedNotebook)
{
    d->m_hasSharedNotebook = hasSharedNotebook;
}

const std::optional<qint32> & NotebookDescriptor::joinedUserCount() const noexcept
{
    return d->m_joinedUserCount;
}

std::optional<qint32> & NotebookDescriptor::mutableJoinedUserCount()
{
    return d->m_joinedUserCount;
}

void NotebookDescriptor::setJoinedUserCount(std::optional<qint32> joinedUserCount)
{
    d->m_joinedUserCount = joinedUserCount;
}

void NotebookDescriptor::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NotebookDescriptor::operator==(const NotebookDescriptor & other) const noexcept
{
    return *d == *other.d;
}

bool NotebookDescriptor::operator!=(const NotebookDescriptor & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
