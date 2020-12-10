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

#ifndef QEVERCLOUD_GENERATED_SYNCSTATEDATA_H
#define QEVERCLOUD_GENERATED_SYNCSTATEDATA_H

#include <generated/types/SyncState.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncState::SyncStateData final:
    public QSharedData,
    public Printable
{
public:
    SyncStateData() = default;
    SyncStateData(const SyncStateData & other) = default;
    SyncStateData(SyncStateData && other) noexcept = default;

    SyncStateData & operator=(const SyncStateData & other) = delete;
    SyncStateData & operator=(SyncStateData && other) = delete;

    ~SyncStateData() noexcept override = default;

    [[nodiscard]] bool operator==(const SyncStateData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SyncStateData & other) const noexcept;

    void print(QTextStream & strm) const override;

    Timestamp m_currentTime = 0;
    Timestamp m_fullSyncBefore = 0;
    qint32 m_updateCount = 0;
    std::optional<qint64> m_uploaded;
    std::optional<Timestamp> m_userLastUpdated;
    std::optional<MessageEventID> m_userMaxMessageEventId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCSTATEDATA_H
