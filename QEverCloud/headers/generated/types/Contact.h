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

#ifndef QEVERCLOUD_GENERATED_CONTACT_H
#define QEVERCLOUD_GENERATED_CONTACT_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <QByteArray>
#include <optional>

namespace qevercloud {

/**
 * A structure that represents contact information. Note this does not necessarily correspond to
 * an Evernote user.
 *
 * */
class QEVERCLOUD_EXPORT Contact: public Printable
{
    Q_GADGET
public:
    Contact();
    Contact(const Contact & other);
    Contact(Contact && other) noexcept;
    ~Contact() noexcept override;

    Contact & operator=(const Contact & other);
    Contact & operator=(Contact && other) noexcept;

    /**
    The displayable name of this contact. This field is filled in by the service and
         is read-only to clients.
    */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
    A unique identifier for this ContactType.
    */
    [[nodiscard]] const std::optional<QString> & id() const noexcept;
    void setId(std::optional<QString> id);

    /**
    What service does this contact come from?
    */
    [[nodiscard]] const std::optional<ContactType> & type() const noexcept;
    [[nodiscard]] std::optional<ContactType> & mutableType();
    void setType(std::optional<ContactType> type);

    /**
    A URL of a profile photo representing this Contact. This field is filled in by the
         service and is read-only to clients.
    */
    [[nodiscard]] const std::optional<QString> & photoUrl() const noexcept;
    void setPhotoUrl(std::optional<QString> photoUrl);

    /**
    timestamp when the profile photo at 'photoUrl' was last updated.
         This field will be null if the user has never set a profile photo.
         This field is filled in by the service and is read-only to clients.
    */
    [[nodiscard]] const std::optional<Timestamp> & photoLastUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePhotoLastUpdated();
    void setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);

    /**
    This field will only be filled by the service when it is giving a Contact record
         to a client, and that client does not normally have enough permission to send a
         new message to the person represented through this Contact. In that case, this
         whole Contact record could be used to send a new Message to the Contact, and the
         service will inspect this permit to confirm that operation was allowed.
    */
    [[nodiscard]] const std::optional<QByteArray> & messagingPermit() const noexcept;
    void setMessagingPermit(std::optional<QByteArray> messagingPermit);

    /**
    If this field is set, then this (whole) Contact record may be used in calls to
         sendMessage until this time. After that time, those calls may be rejected by the
         service if the caller does not have direct permission to initiate a message with
         the represented Evernote user.
    */
    [[nodiscard]] const std::optional<Timestamp> & messagingPermitExpires() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableMessagingPermitExpires();
    void setMessagingPermitExpires(std::optional<Timestamp> messagingPermitExpires);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Contact & other) const noexcept;
    [[nodiscard]] bool operator!=(const Contact & other) const noexcept;

    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<QString> id READ id WRITE setId)
    Q_PROPERTY(std::optional<ContactType> type READ type WRITE setType)
    Q_PROPERTY(std::optional<QString> photoUrl READ photoUrl WRITE setPhotoUrl)
    Q_PROPERTY(std::optional<Timestamp> photoLastUpdated READ photoLastUpdated WRITE setPhotoLastUpdated)
    Q_PROPERTY(std::optional<QByteArray> messagingPermit READ messagingPermit WRITE setMessagingPermit)
    Q_PROPERTY(std::optional<Timestamp> messagingPermitExpires READ messagingPermitExpires WRITE setMessagingPermitExpires)

private:
    class ContactData;
    QSharedDataPointer<ContactData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Contact)

#endif // QEVERCLOUD_GENERATED_CONTACT_H
