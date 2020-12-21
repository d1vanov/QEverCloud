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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTE_H
#define QEVERCLOUD_GENERATED_SHAREDNOTE_H

#include <qevercloud/Export.h>

#include "Identity.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
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
     * @brief localId can be used as a local unique identifier
     * for any data item before it has been synchronized with
     * Evernote and thus before it can be identified using its guid.
     *
     * localId is generated automatically on
     * construction for convenience but can be overridden manually
     */
    [[nodiscard]] QString localId() const noexcept;
    void setLocalId(QString id);

    /**
     * @brief parentLocalId can be used as a local unique identifier
     * of the data item being a parent to this data item.
     *
     * For example, a note is a parent to a resource, a notebook
     * is a parent to a note. So note's localId is a parentLocalId for a
     * resource, notebook's localId is a parentLocalId for a note,
     * tag's localId is a parentLocalId to a child tag.
     *
     * By default the parentLocalId property is empty
     */
    [[nodiscard]] QString parentLocalId() const noexcept;
    void setParentLocalId(QString id);

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

    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
    The user ID of the user who shared the note with the recipient.
    */
    [[nodiscard]] const std::optional<UserID> & sharerUserID() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserID();
    void setSharerUserID(std::optional<UserID> sharerUserID);

    /**
    The identity of the recipient of the share. For a given note, there may be only one
         SharedNote per recipient identity. Only recipientIdentity.id is guaranteed to be set.
         Other fields on the Identity may or my not be set based on the requesting user's
         relationship with the recipient.
    */
    [[nodiscard]] const std::optional<Identity> & recipientIdentity() const noexcept;
    [[nodiscard]] std::optional<Identity> & mutableRecipientIdentity();
    void setRecipientIdentity(std::optional<Identity> recipientIdentity);

    /**
    The privilege level that the share grants to the recipient.
    */
    [[nodiscard]] const std::optional<SharedNotePrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotePrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    /**
    The time at which the share was created.
    */
    [[nodiscard]] const std::optional<Timestamp> & serviceCreated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceCreated();
    void setServiceCreated(std::optional<Timestamp> serviceCreated);

    /**
    The time at which the share was last updated.
    */
    [[nodiscard]] const std::optional<Timestamp> & serviceUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceUpdated();
    void setServiceUpdated(std::optional<Timestamp> serviceUpdated);

    /**
    The time at which the share was assigned to a specific recipient user ID.
    */
    [[nodiscard]] const std::optional<Timestamp> & serviceAssigned() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceAssigned();
    void setServiceAssigned(std::optional<Timestamp> serviceAssigned);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const SharedNote & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNote & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(QString parentLocalId READ parentLocalId WRITE setParentLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<UserID> sharerUserID READ sharerUserID WRITE setSharerUserID)
    Q_PROPERTY(std::optional<Identity> recipientIdentity READ recipientIdentity WRITE setRecipientIdentity)
    Q_PROPERTY(std::optional<SharedNotePrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<Timestamp> serviceCreated READ serviceCreated WRITE setServiceCreated)
    Q_PROPERTY(std::optional<Timestamp> serviceUpdated READ serviceUpdated WRITE setServiceUpdated)
    Q_PROPERTY(std::optional<Timestamp> serviceAssigned READ serviceAssigned WRITE setServiceAssigned)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNote)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTE_H
