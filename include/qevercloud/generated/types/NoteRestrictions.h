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

#ifndef QEVERCLOUD_GENERATED_NOTERESTRICTIONS_H
#define QEVERCLOUD_GENERATED_NOTERESTRICTIONS_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure captures information about the operations that cannot be performed on a given
 * note that has been shared with a recipient via a SharedNote. The following operations are
 * <b>never</b> allowed based on SharedNotes, and as such are left out of the NoteRestrictions
 * structure for brevity:
 *
 * <ul>
 *   <li>Expunging a note (NoteStore.expungeNote)</li>
 *   <li>Moving a note to the trash (Note.active)</li>
 *   <li>Updating a note's notebook (Note.notebookGuid)</li>
 *   <li>Updating a note's tags (Note.tagGuids, Note.tagNames)</li>
 *   <li>Updating a note's attributes (Note.attributes)</li>
 *   <li>Sharing a note with the business (NoteStore.shareNoteWithBusiness</li>
 *   <li>Getting a note's version history (NoteStore.listNoteVersions,
 *     NoteStore.getNoteVersion)</li>
 * </ul>
 *
 * When a client has permission to update a note's title or content, it may also update the
 * Note.updated timestamp.
 *
 * <b>This structure reflects only the privileges / restrictions conveyed by the SharedNote.</b>
 * It does not incorporate privileges conveyed by a potential SharedNotebook to the same
 * recipient. As such, the actual permissions that the recipient has on the note may differ from
 * the permissions expressed in this structure.
 *
 * For example, consider a user with read-only access to a shared notebook, and a read-write share
 * of a specific note in the notebook. The note restrictions would contain noUpdateTitle = false,
 * while the notebook restrictions would contain noUpdateNotes = true. In this case, the user is
 * allowed to update the note title based on the note restrictions.
 *
 * Alternatively, consider a user with read-write access to a shared notebook, and a read-only
 * share of a specific note in that notebook. The note restrictions would contain
 * noUpdateTitle = true, while the notebook restrictions would contain noUpdateNotes = false. In
 * this case, the user would have full edit permissions on the note based on the notebook
 * restrictions.
 *
 * */
class QEVERCLOUD_EXPORT NoteRestrictions: public Printable
{
    Q_GADGET
public:
    NoteRestrictions();
    NoteRestrictions(const NoteRestrictions & other);
    NoteRestrictions(NoteRestrictions && other) noexcept;
    ~NoteRestrictions() noexcept override;

    NoteRestrictions & operator=(const NoteRestrictions & other);
    NoteRestrictions & operator=(NoteRestrictions && other) noexcept;

    /**
    The client may not update the note's title (Note.title).
    */
    [[nodiscard]] const std::optional<bool> & noUpdateTitle() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoUpdateTitle();
    void setNoUpdateTitle(std::optional<bool> noUpdateTitle);

    [[nodiscard]] const std::optional<bool> & noUpdateContent() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoUpdateContent();
    void setNoUpdateContent(std::optional<bool> noUpdateContent);

    /**
    The client may not email the note (NoteStore.emailNote).
    */
    [[nodiscard]] const std::optional<bool> & noEmail() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoEmail();
    void setNoEmail(std::optional<bool> noEmail);

    /**
    The client may not share the note with specific recipients
         (NoteStore.createOrUpdateSharedNotes).
    */
    [[nodiscard]] const std::optional<bool> & noShare() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoShare();
    void setNoShare(std::optional<bool> noShare);

    /**
    The client may not make the note public (NoteStore.shareNote).
    */
    [[nodiscard]] const std::optional<bool> & noSharePublicly() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSharePublicly();
    void setNoSharePublicly(std::optional<bool> noSharePublicly);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteRestrictions & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteRestrictions & other) const noexcept;

    Q_PROPERTY(std::optional<bool> noUpdateTitle READ noUpdateTitle WRITE setNoUpdateTitle)
    Q_PROPERTY(std::optional<bool> noUpdateContent READ noUpdateContent WRITE setNoUpdateContent)
    Q_PROPERTY(std::optional<bool> noEmail READ noEmail WRITE setNoEmail)
    Q_PROPERTY(std::optional<bool> noShare READ noShare WRITE setNoShare)
    Q_PROPERTY(std::optional<bool> noSharePublicly READ noSharePublicly WRITE setNoSharePublicly)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteRestrictions)

#endif // QEVERCLOUD_GENERATED_NOTERESTRICTIONS_H
