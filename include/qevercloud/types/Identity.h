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

#ifndef QEVERCLOUD_GENERATED_IDENTITY
#define QEVERCLOUD_GENERATED_IDENTITY

#include <qevercloud/Export.h>

#include "Contact.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * An object that represents the relationship between a Contact that possibly
 * belongs to an Evernote User.
 *
 * */
class QEVERCLOUD_EXPORT Identity: public Printable
{
    Q_GADGET
public:
    Identity();
    Identity(const Identity & other);
    Identity(Identity && other) noexcept;
    ~Identity() noexcept override;

    Identity & operator=(const Identity & other);
    Identity & operator=(Identity && other) noexcept;

    /**
     * The unique identifier for this mapping.
     */
    [[nodiscard]] IdentityID id() const noexcept;
    void setId(IdentityID id);

    [[nodiscard]] const std::optional<Contact> & contact() const noexcept;
    [[nodiscard]] std::optional<Contact> & mutableContact();
    void setContact(std::optional<Contact> contact);

    /**
     * The Evernote User id that is connected to the Contact. May be unset
     * if this identity has not yet been claimed, or the caller is not
     * connected to this identity.
     */
    [[nodiscard]] const std::optional<UserID> & userId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableUserId();
    void setUserId(std::optional<UserID> userId);

    /**
     * Indicates that the contact for this identity is no longer active and
     * should not be used when creating new threads using Destination.recipients,
     * unless you know of another Identity instance with the same contact information
     * that is active. If you are connected to the user (see userConnected), you
     * can still create threads using their Evernote-type contact.
     */
    [[nodiscard]] const std::optional<bool> & deactivated() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableDeactivated();
    void setDeactivated(std::optional<bool> deactivated);

    /**
     * Does this Identity belong to someone who is in the same business as the
     * caller?
     */
    [[nodiscard]] const std::optional<bool> & sameBusiness() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableSameBusiness();
    void setSameBusiness(std::optional<bool> sameBusiness);

    /**
     * Has the caller blocked the Evernote user this Identity represents?
     */
    [[nodiscard]] const std::optional<bool> & blocked() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableBlocked();
    void setBlocked(std::optional<bool> blocked);

    /**
     * Indicates that the caller is "connected" to the user of this
     * identity via this identity. When you have a connection via an
     * identity, you should always create new threads using the
     * Evernote-type contact (see ContactType) using the userId field
     * from a connected Identity. On the Evernote service, the
     * Evernote-type contact is the most durable. Phone numbers and
     * e-mail addresses can get re-assigned but your Evernote account
     * user ID will remain the same. A connection exists when both of
     * you are in the same business or the user has replied to a thread
     * that you are on. When connected, you will also get to see more
     * information about the user who has claimed the identity. Note
     * that you are never connected to yourself since you won't be
     * sending messages to yourself, but you will obviously see your own
     * profile information.
     */
    [[nodiscard]] const std::optional<bool> & userConnected() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableUserConnected();
    void setUserConnected(std::optional<bool> userConnected);

    /**
     * A server-assigned sequence number for the events in the messages
     * subsystem.
     */
    [[nodiscard]] const std::optional<MessageEventID> & eventId() const noexcept;
    [[nodiscard]] std::optional<MessageEventID> & mutableEventId();
    void setEventId(std::optional<MessageEventID> eventId);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const Identity & identity);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const Identity & identity);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const Identity & identity);

    Q_PROPERTY(IdentityID id READ id WRITE setId)
    Q_PROPERTY(std::optional<Contact> contact READ contact WRITE setContact)
    Q_PROPERTY(std::optional<UserID> userId READ userId WRITE setUserId)
    Q_PROPERTY(std::optional<bool> deactivated READ deactivated WRITE setDeactivated)
    Q_PROPERTY(std::optional<bool> sameBusiness READ sameBusiness WRITE setSameBusiness)
    Q_PROPERTY(std::optional<bool> blocked READ blocked WRITE setBlocked)
    Q_PROPERTY(std::optional<bool> userConnected READ userConnected WRITE setUserConnected)
    Q_PROPERTY(std::optional<MessageEventID> eventId READ eventId WRITE setEventId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const Identity & lhs, const Identity & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const Identity & lhs, const Identity & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_IDENTITY
