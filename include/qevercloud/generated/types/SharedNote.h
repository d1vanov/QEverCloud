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

#include "../../Export.h"

#include "Identity.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
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
