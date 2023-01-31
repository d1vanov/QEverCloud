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

#include <qevercloud/types/SyncState.h>

#include "impl/SyncStateImpl.h"

namespace qevercloud {

SyncState::SyncState() :
    d(new SyncState::Impl)
{}

SyncState::SyncState(const SyncState & other) :
    d(other.d)
{}

SyncState::SyncState(SyncState && other) noexcept :
    d(std::move(other.d))
{}

SyncState::~SyncState() noexcept {}

SyncState & SyncState::operator=(const SyncState & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SyncState & SyncState::operator=(SyncState && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

Timestamp SyncState::currentTime() const noexcept
{
    return d->m_currentTime;
}

void SyncState::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
}

Timestamp SyncState::fullSyncBefore() const noexcept
{
    return d->m_fullSyncBefore;
}

void SyncState::setFullSyncBefore(Timestamp fullSyncBefore)
{
    d->m_fullSyncBefore = fullSyncBefore;
}

qint32 SyncState::updateCount() const noexcept
{
    return d->m_updateCount;
}

void SyncState::setUpdateCount(qint32 updateCount)
{
    d->m_updateCount = updateCount;
}

const std::optional<qint64> & SyncState::uploaded() const noexcept
{
    return d->m_uploaded;
}

std::optional<qint64> & SyncState::mutableUploaded()
{
    return d->m_uploaded;
}

void SyncState::setUploaded(std::optional<qint64> uploaded)
{
    d->m_uploaded = uploaded;
}

const std::optional<Timestamp> & SyncState::userLastUpdated() const noexcept
{
    return d->m_userLastUpdated;
}

std::optional<Timestamp> & SyncState::mutableUserLastUpdated()
{
    return d->m_userLastUpdated;
}

void SyncState::setUserLastUpdated(std::optional<Timestamp> userLastUpdated)
{
    d->m_userLastUpdated = userLastUpdated;
}

const std::optional<MessageEventID> & SyncState::userMaxMessageEventId() const noexcept
{
    return d->m_userMaxMessageEventId;
}

std::optional<MessageEventID> & SyncState::mutableUserMaxMessageEventId()
{
    return d->m_userMaxMessageEventId;
}

void SyncState::setUserMaxMessageEventId(std::optional<MessageEventID> userMaxMessageEventId)
{
    d->m_userMaxMessageEventId = userMaxMessageEventId;
}

void SyncState::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const SyncState & syncState)
{
    strm << static_cast<const Printable&>(syncState);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const SyncState & syncState)
{
    dbg << static_cast<const Printable&>(syncState);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const SyncState & syncState)
{
    strm << static_cast<const Printable&>(syncState);
    return strm;
}

bool operator==(const SyncState & lhs, const SyncState & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.currentTime() == rhs.currentTime() &&
        lhs.fullSyncBefore() == rhs.fullSyncBefore() &&
        lhs.updateCount() == rhs.updateCount() &&
        lhs.uploaded() == rhs.uploaded() &&
        lhs.userLastUpdated() == rhs.userLastUpdated() &&
        lhs.userMaxMessageEventId() == rhs.userMaxMessageEventId();
}

bool operator!=(const SyncState & lhs, const SyncState & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
