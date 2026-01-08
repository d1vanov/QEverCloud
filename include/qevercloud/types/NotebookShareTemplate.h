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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATE
#define QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATE

#include <qevercloud/Export.h>

#include "Contact.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure used to share a notebook with one or more recipients at a given privilege.
 *
 * */
class QEVERCLOUD_EXPORT NotebookShareTemplate: public Printable
{
    Q_GADGET
public:
    NotebookShareTemplate();
    NotebookShareTemplate(const NotebookShareTemplate & other);
    NotebookShareTemplate(NotebookShareTemplate && other) noexcept;
    ~NotebookShareTemplate() noexcept override;

    NotebookShareTemplate & operator=(const NotebookShareTemplate & other);
    NotebookShareTemplate & operator=(NotebookShareTemplate && other) noexcept;

    /**
     * The GUID of the notebook.
     */
    [[nodiscard]] const std::optional<Guid> & notebookGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNotebookGuid();
    void setNotebookGuid(std::optional<Guid> notebookGuid);

    /**
     * The recipients of the notebook share specified as a messaging thread ID. If you
     * have an existing messaging thread to share the note with, specify its ID
     * here instead of recipientContacts in order to properly support defunct
     * identities. The sharer must be a participant of the thread. Either this field
     * or recipientContacts must be set.
     */
    [[nodiscard]] const std::optional<MessageThreadID> & recipientThreadId() const noexcept;
    [[nodiscard]] std::optional<MessageThreadID> & mutableRecipientThreadId();
    void setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId);

    /**
     * The recipients of the notebook share specified as a list of contacts. This should
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
    [[nodiscard]] const std::optional<SharedNotebookPrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookPrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const NotebookShareTemplate & notebookShareTemplate);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const NotebookShareTemplate & notebookShareTemplate);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const NotebookShareTemplate & notebookShareTemplate);

    Q_PROPERTY(std::optional<Guid> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<MessageThreadID> recipientThreadId READ recipientThreadId WRITE setRecipientThreadId)
    Q_PROPERTY(std::optional<QList<Contact>> recipientContacts READ recipientContacts WRITE setRecipientContacts)
    Q_PROPERTY(std::optional<SharedNotebookPrivilegeLevel> privilege READ privilege WRITE setPrivilege)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NotebookShareTemplate & lhs, const NotebookShareTemplate & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NotebookShareTemplate & lhs, const NotebookShareTemplate & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATE
