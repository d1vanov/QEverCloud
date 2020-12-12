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

#include "SyncStateImpl.h"

#include <QTextStream>

namespace qevercloud {

bool SyncState::Impl::operator==(
    const SyncState::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_currentTime == other.m_currentTime &&
        m_fullSyncBefore == other.m_fullSyncBefore &&
        m_updateCount == other.m_updateCount &&
        m_uploaded == other.m_uploaded &&
        m_userLastUpdated == other.m_userLastUpdated &&
        m_userMaxMessageEventId == other.m_userMaxMessageEventId;
}

bool SyncState::Impl::operator!=(
    const SyncState::Impl & other) const noexcept
{
    return !(*this == other);
}

void SyncState::Impl::print(QTextStream & strm) const
{
    strm << "SyncState: {\n";
    strm << "    currentTime = "
        << m_currentTime << "\n";
    strm << "    fullSyncBefore = "
        << m_fullSyncBefore << "\n";
    strm << "    updateCount = "
        << m_updateCount << "\n";

    if (m_uploaded) {
        strm << "    uploaded = "
            << *m_uploaded << "\n";
    }
    else {
        strm << "    uploaded is not set\n";
    }

    if (m_userLastUpdated) {
        strm << "    userLastUpdated = "
            << *m_userLastUpdated << "\n";
    }
    else {
        strm << "    userLastUpdated is not set\n";
    }

    if (m_userMaxMessageEventId) {
        strm << "    userMaxMessageEventId = "
            << *m_userMaxMessageEventId << "\n";
    }
    else {
        strm << "    userMaxMessageEventId is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
