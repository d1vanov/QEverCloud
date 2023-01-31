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

#ifndef QEVERCLOUD_GENERATED_SYNCSTATEBUILDER
#define QEVERCLOUD_GENERATED_SYNCSTATEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SyncState.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SyncStateBuilder
{
public:
    SyncStateBuilder();

    SyncStateBuilder(SyncStateBuilder && other) noexcept;

    ~SyncStateBuilder() noexcept;

    SyncStateBuilder & operator=(SyncStateBuilder && other) noexcept;

    SyncStateBuilder & setCurrentTime(Timestamp currentTime);
    SyncStateBuilder & setFullSyncBefore(Timestamp fullSyncBefore);
    SyncStateBuilder & setUpdateCount(qint32 updateCount);
    SyncStateBuilder & setUploaded(std::optional<qint64> uploaded);
    SyncStateBuilder & setUserLastUpdated(std::optional<Timestamp> userLastUpdated);
    SyncStateBuilder & setUserMaxMessageEventId(std::optional<MessageEventID> userMaxMessageEventId);

    [[nodiscard]] SyncState build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCSTATEBUILDER
