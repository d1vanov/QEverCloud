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

#include <qevercloud/types/NotebookDescriptor.h>

#include "impl/NotebookDescriptorImpl.h"

namespace qevercloud {

NotebookDescriptor::NotebookDescriptor() :
    d(new NotebookDescriptor::Impl)
 {}

NotebookDescriptor::NotebookDescriptor(const NotebookDescriptor & other) :
    d(other.d)
{}

NotebookDescriptor::NotebookDescriptor(NotebookDescriptor && other) noexcept :
    d(std::move(other.d))
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

const QString & NotebookDescriptor::localId() const noexcept
{
    return d->m_localId;
}

void NotebookDescriptor::setLocalId(QString id)
{
    d->m_localId = std::move(id);
}

bool NotebookDescriptor::isLocallyModified() const noexcept
{
    return d->m_locallyModified;
}

void NotebookDescriptor::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool NotebookDescriptor::isLocalOnly() const noexcept
{
    return d->m_localOnly;
}

void NotebookDescriptor::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool NotebookDescriptor::isLocallyFavorited() const noexcept
{
    return d->m_locallyFavorited;
}

void NotebookDescriptor::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const QHash<QString, QVariant> & NotebookDescriptor::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & NotebookDescriptor::mutableLocalData()
{
    return d->m_localData;
}

void NotebookDescriptor::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
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

bool operator==(const NotebookDescriptor & lhs, const NotebookDescriptor & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.localId() == rhs.localId() &&
        lhs.isLocallyModified() == rhs.isLocallyModified() &&
        lhs.isLocalOnly() == rhs.isLocalOnly() &&
        lhs.isLocallyFavorited() == rhs.isLocallyFavorited() &&
        lhs.guid() == rhs.guid() &&
        lhs.notebookDisplayName() == rhs.notebookDisplayName() &&
        lhs.contactName() == rhs.contactName() &&
        lhs.hasSharedNotebook() == rhs.hasSharedNotebook() &&
        lhs.joinedUserCount() == rhs.joinedUserCount();
}

bool operator!=(const NotebookDescriptor & lhs, const NotebookDescriptor & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
