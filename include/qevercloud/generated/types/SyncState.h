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

#ifndef QEVERCLOUD_GENERATED_SYNCSTATE_H
#define QEVERCLOUD_GENERATED_SYNCSTATE_H

#include "../../Export.h"

#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <optional>

namespace qevercloud {

/**
 * This structure encapsulates the information about the state of the
 * user's account for the purpose of "state based" synchronization.
 * */
class QEVERCLOUD_EXPORT SyncState: public Printable
{
    Q_GADGET
public:
    SyncState();
    SyncState(const SyncState & other);
    SyncState(SyncState && other) noexcept;
    ~SyncState() noexcept override;

    SyncState & operator=(const SyncState & other);
    SyncState & operator=(SyncState && other) noexcept;

    /**
    The server's current date and time.
    */
    [[nodiscard]] Timestamp currentTime() const noexcept;
    void setCurrentTime(Timestamp currentTime);

    /**
    The cutoff date and time for client caches to be
       updated via incremental synchronization.  Any clients that were last
       synched with the server before this date/time must do a full resync of all
       objects.  This cutoff point will change over time as archival data is
       deleted or special circumstances on the service require resynchronization.
    */
    [[nodiscard]] Timestamp fullSyncBefore() const noexcept;
    void setFullSyncBefore(Timestamp fullSyncBefore);

    /**
    Indicates the total number of transactions that have
       been committed within the account.  This reflects (for example) the
       number of discrete additions or modifications that have been made to
       the data in this account (tags, notes, resources, etc.).
       This number is the "high water mark" for Update Sequence Numbers (USN)
       within the account.
    */
    [[nodiscard]] qint32 updateCount() const noexcept;
    void setUpdateCount(qint32 updateCount);

    /**
    The total number of bytes that have been uploaded to
       this account in the current monthly period.  This can be compared against
       Accounting.uploadLimit (from the UserStore) to determine how close the user
       is to their monthly upload limit.
       This value may not be present if the SyncState has been retrieved by
       a caller that only has read access to the account.
    */
    [[nodiscard]] const std::optional<qint64> & uploaded() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableUploaded();
    void setUploaded(std::optional<qint64> uploaded);

    /**
    The last time when a user's account level information was changed. This value
       is the latest time when a modification was made to any of the following:
       accounting information (billing, quota, premium status, etc.), user attributes
       and business user information (business name, business user attributes, etc.) if
       the user is in a business.
       Clients who need to maintain account information about a User should watch this
       field for updates rather than polling UserStore.getUser for updates. Here is the
       basic flow that clients should follow:
       <ol>
         <li>Call NoteStore.getSyncState to retrieve the SyncState object</li>
         <li>Compare SyncState.userLastUpdated to previously stored value:
             if (SyncState.userLastUpdated > previousValue)
               call UserStore.getUser to get the latest User object;
             else
               do nothing;</li>
         <li>Update previousValue = SyncState.userLastUpdated</li>
       </ol>
    */
    [[nodiscard]] const std::optional<Timestamp> & userLastUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUserLastUpdated();
    void setUserLastUpdated(std::optional<Timestamp> userLastUpdated);

    /**
    The greatest MessageEventID for this user's account. Clients that do a full
       sync should store this value locally and compare their local copy to the
       value returned by getSyncState to determine if they need to sync with
       MessageStore. This value will be omitted if the user has never sent or
       received a message.
    */
    [[nodiscard]] const std::optional<MessageEventID> & userMaxMessageEventId() const noexcept;
    [[nodiscard]] std::optional<MessageEventID> & mutableUserMaxMessageEventId();
    void setUserMaxMessageEventId(std::optional<MessageEventID> userMaxMessageEventId);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const SyncState & other) const noexcept;
    [[nodiscard]] bool operator!=(const SyncState & other) const noexcept;

    Q_PROPERTY(Timestamp currentTime READ currentTime WRITE setCurrentTime)
    Q_PROPERTY(Timestamp fullSyncBefore READ fullSyncBefore WRITE setFullSyncBefore)
    Q_PROPERTY(qint32 updateCount READ updateCount WRITE setUpdateCount)
    Q_PROPERTY(std::optional<qint64> uploaded READ uploaded WRITE setUploaded)
    Q_PROPERTY(std::optional<Timestamp> userLastUpdated READ userLastUpdated WRITE setUserLastUpdated)
    Q_PROPERTY(std::optional<MessageEventID> userMaxMessageEventId READ userMaxMessageEventId WRITE setUserMaxMessageEventId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SyncState)

#endif // QEVERCLOUD_GENERATED_SYNCSTATE_H
