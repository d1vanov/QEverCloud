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

#ifndef QEVERCLOUD_GENERATED_NOTEVERSIONID_H
#define QEVERCLOUD_GENERATED_NOTEVERSIONID_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * Identifying information about previous versions of a note that are backed up
 * within Evernote's servers.  Used in the return value of the listNoteVersions
 * call.
 *
 * */
class QEVERCLOUD_EXPORT NoteVersionId: public Printable
{
    Q_GADGET
public:
    NoteVersionId();
    NoteVersionId(const NoteVersionId & other);
    NoteVersionId(NoteVersionId && other) noexcept;
    ~NoteVersionId() noexcept override;

    NoteVersionId & operator=(const NoteVersionId & other);
    NoteVersionId & operator=(NoteVersionId && other) noexcept;

    /**
    The update sequence number for the Note when it last had this content.
        This serves to uniquely identify each version of the note, since USN
        values are unique within an account for each update.
    */
    [[nodiscard]] qint32 updateSequenceNum() const noexcept;
    void setUpdateSequenceNum(qint32 updateSequenceNum);

    /**
    The 'updated' time that was set on the Note when it had this version
        of the content.  This is the user-modifiable modification time on the
        note, so it's not reliable for guaranteeing the order of various
        versions.  (E.g. if someone modifies the note, then changes this time
        manually into the past and then updates the note again.)
    */
    [[nodiscard]] Timestamp updated() const noexcept;
    void setUpdated(Timestamp updated);

    /**
    A timestamp that holds the date and time when this version of the note
        was backed up by Evernote's servers.
    */
    [[nodiscard]] Timestamp saved() const noexcept;
    void setSaved(Timestamp saved);

    /**
    The title of the note when this particular version was saved.  (The
        current title of the note may differ from this value.)
    */
    [[nodiscard]] const QString & title() const noexcept;
    void setTitle(QString title);

    /**
    The ID of the user who made the change to this version of the note. This will be
        unset if the note version was edited by the owner of the account.
    */
    [[nodiscard]] const std::optional<UserID> & lastEditorId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableLastEditorId();
    void setLastEditorId(std::optional<UserID> lastEditorId);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteVersionId & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteVersionId & other) const noexcept;

    Q_PROPERTY(qint32 updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(Timestamp updated READ updated WRITE setUpdated)
    Q_PROPERTY(Timestamp saved READ saved WRITE setSaved)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(std::optional<UserID> lastEditorId READ lastEditorId WRITE setLastEditorId)

private:
    class NoteVersionIdData;
    QSharedDataPointer<NoteVersionIdData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteVersionId)

#endif // QEVERCLOUD_GENERATED_NOTEVERSIONID_H
