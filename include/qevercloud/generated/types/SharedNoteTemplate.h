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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATE_H
#define QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATE_H

#include <qevercloud/Export.h>

#include "Contact.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure used to share a note with one or more recipients at a given privilege.
 *
 * */
class QEVERCLOUD_EXPORT SharedNoteTemplate: public Printable
{
    Q_GADGET
public:
    SharedNoteTemplate();
    SharedNoteTemplate(const SharedNoteTemplate & other);
    SharedNoteTemplate(SharedNoteTemplate && other) noexcept;
    ~SharedNoteTemplate() noexcept override;

    SharedNoteTemplate & operator=(const SharedNoteTemplate & other);
    SharedNoteTemplate & operator=(SharedNoteTemplate && other) noexcept;

    /**
     * The GUID of the note.
     */
    [[nodiscard]] const std::optional<Guid> & noteGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNoteGuid();
    void setNoteGuid(std::optional<Guid> noteGuid);

    /**
     * The recipients of the note share specified as a messaging thread ID. If you
     * have an existing messaging thread to share the note with, specify its ID
     * here instead of recipientContacts in order to properly support defunct
     * identities. The sharer must be a participant of the thread. Either this
     * field or recipientContacts must be set.
     */
    [[nodiscard]] const std::optional<MessageThreadID> & recipientThreadId() const noexcept;
    [[nodiscard]] std::optional<MessageThreadID> & mutableRecipientThreadId();
    void setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId);

    /**
     * The recipients of the note share specified as a list of contacts. This should
     * only be set if the sharing takes place before the thread is created. Use
     * recipientThreadId instead when sharing with an existing thread. Either this
     * field or recipientThreadId must be set.
     */
    [[nodiscard]] const std::optional<QList<Contact>> & recipientContacts() const noexcept;
    [[nodiscard]] std::optional<QList<Contact>> & mutableRecipientContacts();
    void setRecipientContacts(std::optional<QList<Contact>> recipientContacts);

    /**
     * The privilege level to be granted.
     */
    [[nodiscard]] const std::optional<SharedNotePrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotePrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<Guid> noteGuid READ noteGuid WRITE setNoteGuid)
    Q_PROPERTY(std::optional<MessageThreadID> recipientThreadId READ recipientThreadId WRITE setRecipientThreadId)
    Q_PROPERTY(std::optional<QList<Contact>> recipientContacts READ recipientContacts WRITE setRecipientContacts)
    Q_PROPERTY(std::optional<SharedNotePrivilegeLevel> privilege READ privilege WRITE setPrivilege)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const SharedNoteTemplate & lhs, const SharedNoteTemplate & rhs) noexcept;
[[nodiscard]] bool operator!=(const SharedNoteTemplate & lhs, const SharedNoteTemplate & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNoteTemplate)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATE_H
