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

#ifndef QEVERCLOUD_GENERATED_SYNCSTATEIMPL_H
#define QEVERCLOUD_GENERATED_SYNCSTATEIMPL_H

#include <generated/types/SyncState.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncState::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SyncState::Impl & other) = default;
    Impl(SyncState::Impl && other) noexcept = default;

    SyncState::Impl & operator=(const SyncState::Impl & other) = delete;
    SyncState::Impl & operator=(SyncState::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const SyncState::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const SyncState::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    Timestamp m_currentTime = 0;
    Timestamp m_fullSyncBefore = 0;
    qint32 m_updateCount = 0;
    std::optional<qint64> m_uploaded;
    std::optional<Timestamp> m_userLastUpdated;
    std::optional<MessageEventID> m_userMaxMessageEventId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCSTATEIMPL_H
