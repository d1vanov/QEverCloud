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

#ifndef QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERS_H
#define QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERS_H

#include <qevercloud/Export.h>

#include "Note.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <optional>

namespace qevercloud {

/**
 * Parameters that must be given to the NoteStore emailNote call. These allow
 * the caller to specify the note to send, the recipient addresses, etc.
 *
 * */
class QEVERCLOUD_EXPORT NoteEmailParameters: public Printable
{
    Q_GADGET
public:
    NoteEmailParameters();
    NoteEmailParameters(const NoteEmailParameters & other);
    NoteEmailParameters(NoteEmailParameters && other) noexcept;
    ~NoteEmailParameters() noexcept override;

    NoteEmailParameters & operator=(const NoteEmailParameters & other);
    NoteEmailParameters & operator=(NoteEmailParameters && other) noexcept;

    /**
    If set, this must be the GUID of a note within the user's account that
          should be retrieved from the service and sent as email.  If not set,
          the 'note' field must be provided instead.
    */
    [[nodiscard]] const std::optional<QString> & guid() const noexcept;
    void setGuid(std::optional<QString> guid);

    /**
    If the 'guid' field is not set, this field must be provided, including
          the full contents of the note note (and all of its Resources) to send.
          This can be used for a Note that as not been created in the service,
          for example by a local client with local notes.
    */
    [[nodiscard]] const std::optional<Note> & note() const noexcept;
    [[nodiscard]] std::optional<Note> & mutableNote();
    void setNote(std::optional<Note> note);

    /**
    If provided, this should contain a list of the SMTP email addresses
          that should be included in the "To:" line of the email.
          Callers must specify at least one "to" or "cc" email address.
    */
    [[nodiscard]] const std::optional<QStringList> & toAddresses() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableToAddresses();
    void setToAddresses(std::optional<QStringList> toAddresses);

    /**
    If provided, this should contain a list of the SMTP email addresses
          that should be included in the "Cc:" line of the email.
          Callers must specify at least one "to" or "cc" email address.
    */
    [[nodiscard]] const std::optional<QStringList> & ccAddresses() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableCcAddresses();
    void setCcAddresses(std::optional<QStringList> ccAddresses);

    /**
    If provided, this should contain the subject line of the email that
          will be sent.  If not provided, the title of the note will be used
          as the subject of the email.
    */
    [[nodiscard]] const std::optional<QString> & subject() const noexcept;
    void setSubject(std::optional<QString> subject);

    /**
    If provided, this is additional personal text that should be included
          into the email as a message from the owner to the recipient(s).
    */
    [[nodiscard]] const std::optional<QString> & message() const noexcept;
    void setMessage(std::optional<QString> message);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteEmailParameters & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteEmailParameters & other) const noexcept;

    Q_PROPERTY(std::optional<QString> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<Note> note READ note WRITE setNote)
    Q_PROPERTY(std::optional<QStringList> toAddresses READ toAddresses WRITE setToAddresses)
    Q_PROPERTY(std::optional<QStringList> ccAddresses READ ccAddresses WRITE setCcAddresses)
    Q_PROPERTY(std::optional<QString> subject READ subject WRITE setSubject)
    Q_PROPERTY(std::optional<QString> message READ message WRITE setMessage)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteEmailParameters)

#endif // QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERS_H
