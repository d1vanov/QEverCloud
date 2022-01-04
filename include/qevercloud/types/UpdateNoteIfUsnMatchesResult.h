/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULT
#define QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULT

#include <qevercloud/Export.h>

#include "Note.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * The result of a call to updateNoteIfUsnMatches, which optionally updates a note
 * based on the current value of the note's update sequence number on the service.
 *
 * */
class QEVERCLOUD_EXPORT UpdateNoteIfUsnMatchesResult: public Printable
{
    Q_GADGET
public:
    UpdateNoteIfUsnMatchesResult();
    UpdateNoteIfUsnMatchesResult(const UpdateNoteIfUsnMatchesResult & other);
    UpdateNoteIfUsnMatchesResult(UpdateNoteIfUsnMatchesResult && other) noexcept;
    ~UpdateNoteIfUsnMatchesResult() noexcept override;

    UpdateNoteIfUsnMatchesResult & operator=(const UpdateNoteIfUsnMatchesResult & other);
    UpdateNoteIfUsnMatchesResult & operator=(UpdateNoteIfUsnMatchesResult && other) noexcept;

    /**
     * Either the current state of the note if <tt>updated</tt> is false or the
     * result of updating the note as would be done via the <tt>updateNote</tt> method.
     * If the note was not updated, you will receive a Note that does not include note
     * content, resources data, resources recognition data, or resources alternate data.
     * You can check for updates to these large objects by checking the Data.bodyHash
     * values and downloading accordingly.
     */
    [[nodiscard]] const std::optional<Note> & note() const noexcept;
    [[nodiscard]] std::optional<Note> & mutableNote();
    void setNote(std::optional<Note> note);

    /**
     * Whether or not the note was updated by the operation.
     */
    [[nodiscard]] const std::optional<bool> & updated() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableUpdated();
    void setUpdated(std::optional<bool> updated);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult);

    Q_PROPERTY(std::optional<Note> note READ note WRITE setNote)
    Q_PROPERTY(std::optional<bool> updated READ updated WRITE setUpdated)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const UpdateNoteIfUsnMatchesResult & lhs, const UpdateNoteIfUsnMatchesResult & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const UpdateNoteIfUsnMatchesResult & lhs, const UpdateNoteIfUsnMatchesResult & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULT
