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

#ifndef QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIP
#define QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIP

#include <qevercloud/Export.h>

#include "NoteShareRelationshipRestrictions.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Describes the association between a Note and an Evernote User who is
 * a member of that note.
 *
 * */
class QEVERCLOUD_EXPORT NoteMemberShareRelationship: public Printable
{
    Q_GADGET
public:
    NoteMemberShareRelationship();
    NoteMemberShareRelationship(const NoteMemberShareRelationship & other);
    NoteMemberShareRelationship(NoteMemberShareRelationship && other) noexcept;
    ~NoteMemberShareRelationship() noexcept override;

    NoteMemberShareRelationship & operator=(const NoteMemberShareRelationship & other);
    NoteMemberShareRelationship & operator=(NoteMemberShareRelationship && other) noexcept;

    /**
     * The string that clients should show to users to represent this
     * member.
     */
    [[nodiscard]] const std::optional<QString> & displayName() const noexcept;
    void setDisplayName(std::optional<QString> displayName);

    /**
     * The Evernote UserID of the user who is a member to the note.
     */
    [[nodiscard]] const std::optional<UserID> & recipientUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableRecipientUserId();
    void setRecipientUserId(std::optional<UserID> recipientUserId);

    /**
     * The privilege at which the member can access the note,
     * which is the best privilege granted to the user across all of their
     * individual shares for this note. This field is used by the service
     * to convey information to the user, so clients should treat it as
     * read-only.
     */
    [[nodiscard]] const std::optional<SharedNotePrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotePrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    /**
     * The restrictions on which privileges may be individually
     * assigned to the recipient of this share relationship. This field
     * is used by the service to convey information to the user, so
     * clients should treat it as read-only.
     */
    [[nodiscard]] const std::optional<NoteShareRelationshipRestrictions> & restrictions() const noexcept;
    [[nodiscard]] std::optional<NoteShareRelationshipRestrictions> & mutableRestrictions();
    void setRestrictions(std::optional<NoteShareRelationshipRestrictions> restrictions);

    /**
     * The user id of the user who most recently shared the note with
     * this user. This field is used by the service to convey information
     * to the user, so clients should treat it as read-only.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserId();
    void setSharerUserId(std::optional<UserID> sharerUserId);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const NoteMemberShareRelationship & noteMemberShareRelationship);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const NoteMemberShareRelationship & noteMemberShareRelationship);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const NoteMemberShareRelationship & noteMemberShareRelationship);

    Q_PROPERTY(std::optional<QString> displayName READ displayName WRITE setDisplayName)
    Q_PROPERTY(std::optional<UserID> recipientUserId READ recipientUserId WRITE setRecipientUserId)
    Q_PROPERTY(std::optional<SharedNotePrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<NoteShareRelationshipRestrictions> restrictions READ restrictions WRITE setRestrictions)
    Q_PROPERTY(std::optional<UserID> sharerUserId READ sharerUserId WRITE setSharerUserId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NoteMemberShareRelationship & lhs, const NoteMemberShareRelationship & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NoteMemberShareRelationship & lhs, const NoteMemberShareRelationship & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIP
