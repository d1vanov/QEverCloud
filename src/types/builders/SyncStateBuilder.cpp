/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/SyncStateBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncStateBuilder::Impl final:
    public QSharedData
{
public:
    Timestamp m_currentTime = 0;
    Timestamp m_fullSyncBefore = 0;
    qint32 m_updateCount = 0;
    std::optional<qint64> m_uploaded;
    std::optional<Timestamp> m_userLastUpdated;
    std::optional<MessageEventID> m_userMaxMessageEventId;
};

SyncStateBuilder::SyncStateBuilder() :
    d(new SyncStateBuilder::Impl)
{}

SyncStateBuilder::SyncStateBuilder(SyncStateBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SyncStateBuilder::~SyncStateBuilder() noexcept = default;

SyncStateBuilder & SyncStateBuilder::operator=(SyncStateBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SyncStateBuilder & SyncStateBuilder::setCurrentTime(Timestamp currentTime)
{
    d->m_currentTime = currentTime;
    return *this;
}

SyncStateBuilder & SyncStateBuilder::setFullSyncBefore(Timestamp fullSyncBefore)
{
    d->m_fullSyncBefore = fullSyncBefore;
    return *this;
}

SyncStateBuilder & SyncStateBuilder::setUpdateCount(qint32 updateCount)
{
    d->m_updateCount = updateCount;
    return *this;
}

SyncStateBuilder & SyncStateBuilder::setUploaded(std::optional<qint64> uploaded)
{
    d->m_uploaded = std::move(uploaded);
    return *this;
}

SyncStateBuilder & SyncStateBuilder::setUserLastUpdated(std::optional<Timestamp> userLastUpdated)
{
    d->m_userLastUpdated = std::move(userLastUpdated);
    return *this;
}

SyncStateBuilder & SyncStateBuilder::setUserMaxMessageEventId(std::optional<MessageEventID> userMaxMessageEventId)
{
    d->m_userMaxMessageEventId = std::move(userMaxMessageEventId);
    return *this;
}

SyncState SyncStateBuilder::build()
{
    SyncState result;

    result.setCurrentTime(d->m_currentTime);
    result.setFullSyncBefore(d->m_fullSyncBefore);
    result.setUpdateCount(d->m_updateCount);
    result.setUploaded(std::move(d->m_uploaded));
    result.setUserLastUpdated(std::move(d->m_userLastUpdated));
    result.setUserMaxMessageEventId(std::move(d->m_userMaxMessageEventId));

    d->m_currentTime = 0;
    d->m_fullSyncBefore = 0;
    d->m_updateCount = 0;
    d->m_uploaded = {};
    d->m_userLastUpdated = {};
    d->m_userMaxMessageEventId = {};

    return result;
}

} // namespace qevercloud
