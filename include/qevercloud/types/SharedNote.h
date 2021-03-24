/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTE_H
#define QEVERCLOUD_GENERATED_SHAREDNOTE_H

#include <qevercloud/Export.h>

#include "Identity.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * Represents a relationship between a note and a single share invitation recipient. The recipient
 * is identified via an Identity, and has a given privilege that specifies what actions they may
 * take on the note.
 *
 * */
class QEVERCLOUD_EXPORT SharedNote: public Printable
{
    Q_GADGET
public:
    SharedNote();
    SharedNote(const SharedNote & other);
    SharedNote(SharedNote && other) noexcept;
    ~SharedNote() noexcept override;

    SharedNote & operator=(const SharedNote & other);
    SharedNote & operator=(SharedNote && other) noexcept;

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool favorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The user ID of the user who shared the note with the recipient.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserID() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserID();
    void setSharerUserID(std::optional<UserID> sharerUserID);

    /**
     * The identity of the recipient of the share. For a given note, there may be only one
     * SharedNote per recipient identity. Only recipientIdentity.id is guaranteed to be set.
     * Other fields on the Identity may or my not be set based on the requesting user's
     * relationship with the recipient.
     */
    [[nodiscard]] const std::optional<Identity> & recipientIdentity() const noexcept;
    [[nodiscard]] std::optional<Identity> & mutableRecipientIdentity();
    void setRecipientIdentity(std::optional<Identity> recipientIdentity);

    /**
     * The privilege level that the share grants to the recipient.
     */
    [[nodiscard]] const std::optional<SharedNotePrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotePrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    /**
     * The time at which the share was created.
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceCreated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceCreated();
    void setServiceCreated(std::optional<Timestamp> serviceCreated);

    /**
     * The time at which the share was last updated.
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceUpdated();
    void setServiceUpdated(std::optional<Timestamp> serviceUpdated);

    /**
     * The time at which the share was assigned to a specific recipient user ID.
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceAssigned() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceAssigned();
    void setServiceAssigned(std::optional<Timestamp> serviceAssigned);

    /**
     * Methods below correspond to fields which are NOT set by QEverCloud itself.
     * They exist for convenience of client code and are intended to be called
     * and used by QEverCloud's client code if/when appropriate
     */

    /**
     * Guid of a note to which this shared note belongs
     */
    [[nodiscard]] const std::optional<Guid> & noteGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNoteGuid();
    void setNoteGuid(std::optional<Guid> noteGuid);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<UserID> sharerUserID READ sharerUserID WRITE setSharerUserID)
    Q_PROPERTY(std::optional<Identity> recipientIdentity READ recipientIdentity WRITE setRecipientIdentity)
    Q_PROPERTY(std::optional<SharedNotePrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<Timestamp> serviceCreated READ serviceCreated WRITE setServiceCreated)
    Q_PROPERTY(std::optional<Timestamp> serviceUpdated READ serviceUpdated WRITE setServiceUpdated)
    Q_PROPERTY(std::optional<Timestamp> serviceAssigned READ serviceAssigned WRITE setServiceAssigned)
    Q_PROPERTY(std::optional<Guid> noteGuid READ noteGuid WRITE setNoteGuid)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const SharedNote & lhs, const SharedNote & rhs) noexcept;
[[nodiscard]] bool operator!=(const SharedNote & lhs, const SharedNote & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNote)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTE_H
