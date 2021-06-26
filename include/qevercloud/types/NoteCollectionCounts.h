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

#ifndef QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTS
#define QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTS

#include <qevercloud/Export.h>

#include "QMap"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A data structure representing the number of notes for each notebook
 * and tag with a non-zero set of applicable notes.
 *
 **/
class QEVERCLOUD_EXPORT NoteCollectionCounts: public Printable
{
    Q_GADGET
public:
    NoteCollectionCounts();
    NoteCollectionCounts(const NoteCollectionCounts & other);
    NoteCollectionCounts(NoteCollectionCounts && other) noexcept;
    ~NoteCollectionCounts() noexcept override;

    NoteCollectionCounts & operator=(const NoteCollectionCounts & other);
    NoteCollectionCounts & operator=(NoteCollectionCounts && other) noexcept;

    /**
     * A mapping from the Notebook GUID to the number of
     * notes (from some selection) that are in the corresponding notebook.
     */
    [[nodiscard]] const std::optional<QMap<Guid, qint32>> & notebookCounts() const noexcept;
    [[nodiscard]] std::optional<QMap<Guid, qint32>> & mutableNotebookCounts();
    void setNotebookCounts(std::optional<QMap<Guid, qint32>> notebookCounts);

    /**
     * A mapping from the Tag GUID to the number of notes (from some
     * selection) that have the corresponding tag.
     */
    [[nodiscard]] const std::optional<QMap<Guid, qint32>> & tagCounts() const noexcept;
    [[nodiscard]] std::optional<QMap<Guid, qint32>> & mutableTagCounts();
    void setTagCounts(std::optional<QMap<Guid, qint32>> tagCounts);

    /**
     * If this is set, then this is the number of notes that are in the trash.
     * If this is not set, then the number of notes in the trash hasn't been
     * reported. (I.e. if there are no notes in the trash, this will be set
     * to 0.)
     */
    [[nodiscard]] const std::optional<qint32> & trashCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableTrashCount();
    void setTrashCount(std::optional<qint32> trashCount);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const NoteCollectionCounts & noteCollectionCounts);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const NoteCollectionCounts & noteCollectionCounts);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const NoteCollectionCounts & noteCollectionCounts);

    using TagCounts = QMap<Guid, qint32>;

    Q_PROPERTY(std::optional<TagCounts> notebookCounts READ notebookCounts WRITE setNotebookCounts)
    Q_PROPERTY(std::optional<TagCounts> tagCounts READ tagCounts WRITE setTagCounts)
    Q_PROPERTY(std::optional<qint32> trashCount READ trashCount WRITE setTrashCount)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NoteCollectionCounts & lhs, const NoteCollectionCounts & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NoteCollectionCounts & lhs, const NoteCollectionCounts & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteCollectionCounts)

#endif // QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTS
