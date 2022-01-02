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

#include <qevercloud/types/LinkedNotebook.h>

#include "impl/LinkedNotebookImpl.h"

namespace qevercloud {

LinkedNotebook::LinkedNotebook() :
    d(new LinkedNotebook::Impl)
{}

LinkedNotebook::LinkedNotebook(const LinkedNotebook & other) :
    d(other.d)
{}

LinkedNotebook::LinkedNotebook(LinkedNotebook && other) noexcept :
    d(std::move(other.d))
{}

LinkedNotebook::~LinkedNotebook() noexcept {}

LinkedNotebook & LinkedNotebook::operator=(const LinkedNotebook & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

LinkedNotebook & LinkedNotebook::operator=(LinkedNotebook && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

bool LinkedNotebook::isLocallyModified() const noexcept
{
    return d->m_locallyModified;
}

void LinkedNotebook::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool LinkedNotebook::isLocalOnly() const noexcept
{
    return d->m_localOnly;
}

void LinkedNotebook::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool LinkedNotebook::isLocallyFavorited() const noexcept
{
    return d->m_locallyFavorited;
}

void LinkedNotebook::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const QHash<QString, QVariant> & LinkedNotebook::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & LinkedNotebook::mutableLocalData()
{
    return d->m_localData;
}

void LinkedNotebook::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
}

const std::optional<QString> & LinkedNotebook::shareName() const noexcept
{
    return d->m_shareName;
}

void LinkedNotebook::setShareName(std::optional<QString> shareName)
{
    d->m_shareName = shareName;
}

const std::optional<QString> & LinkedNotebook::username() const noexcept
{
    return d->m_username;
}

void LinkedNotebook::setUsername(std::optional<QString> username)
{
    d->m_username = username;
}

const std::optional<QString> & LinkedNotebook::shardId() const noexcept
{
    return d->m_shardId;
}

void LinkedNotebook::setShardId(std::optional<QString> shardId)
{
    d->m_shardId = shardId;
}

const std::optional<QString> & LinkedNotebook::sharedNotebookGlobalId() const noexcept
{
    return d->m_sharedNotebookGlobalId;
}

void LinkedNotebook::setSharedNotebookGlobalId(std::optional<QString> sharedNotebookGlobalId)
{
    d->m_sharedNotebookGlobalId = sharedNotebookGlobalId;
}

const std::optional<QString> & LinkedNotebook::uri() const noexcept
{
    return d->m_uri;
}

void LinkedNotebook::setUri(std::optional<QString> uri)
{
    d->m_uri = uri;
}

const std::optional<Guid> & LinkedNotebook::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & LinkedNotebook::mutableGuid()
{
    return d->m_guid;
}

void LinkedNotebook::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<qint32> & LinkedNotebook::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & LinkedNotebook::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void LinkedNotebook::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<QString> & LinkedNotebook::noteStoreUrl() const noexcept
{
    return d->m_noteStoreUrl;
}

void LinkedNotebook::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = noteStoreUrl;
}

const std::optional<QString> & LinkedNotebook::webApiUrlPrefix() const noexcept
{
    return d->m_webApiUrlPrefix;
}

void LinkedNotebook::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = webApiUrlPrefix;
}

const std::optional<QString> & LinkedNotebook::stack() const noexcept
{
    return d->m_stack;
}

void LinkedNotebook::setStack(std::optional<QString> stack)
{
    d->m_stack = stack;
}

const std::optional<qint32> & LinkedNotebook::businessId() const noexcept
{
    return d->m_businessId;
}

std::optional<qint32> & LinkedNotebook::mutableBusinessId()
{
    return d->m_businessId;
}

void LinkedNotebook::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = businessId;
}

void LinkedNotebook::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const LinkedNotebook & linkedNotebook)
{
    strm << static_cast<const Printable&>(linkedNotebook);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const LinkedNotebook & linkedNotebook)
{
    dbg << static_cast<const Printable&>(linkedNotebook);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const LinkedNotebook & linkedNotebook)
{
    strm << static_cast<const Printable&>(linkedNotebook);
    return strm;
}

bool operator==(const LinkedNotebook & lhs, const LinkedNotebook & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.isLocallyModified() == rhs.isLocallyModified() &&
        lhs.isLocalOnly() == rhs.isLocalOnly() &&
        lhs.isLocallyFavorited() == rhs.isLocallyFavorited() &&
        lhs.shareName() == rhs.shareName() &&
        lhs.username() == rhs.username() &&
        lhs.shardId() == rhs.shardId() &&
        lhs.sharedNotebookGlobalId() == rhs.sharedNotebookGlobalId() &&
        lhs.uri() == rhs.uri() &&
        lhs.guid() == rhs.guid() &&
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.noteStoreUrl() == rhs.noteStoreUrl() &&
        lhs.webApiUrlPrefix() == rhs.webApiUrlPrefix() &&
        lhs.stack() == rhs.stack() &&
        lhs.businessId() == rhs.businessId();
}

bool operator!=(const LinkedNotebook & lhs, const LinkedNotebook & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
