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

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATALIST
#define QEVERCLOUD_GENERATED_NOTESMETADATALIST

#include <qevercloud/Export.h>

#include "NoteMetadata.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QByteArray>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is returned from calls to the findNotesMetadata function to
 * give the high-level metadata about a subset of Notes that are found to
 * match a specified NoteFilter in a search.
 *
 **/
class QEVERCLOUD_EXPORT NotesMetadataList: public Printable
{
    Q_GADGET
public:
    NotesMetadataList();
    NotesMetadataList(const NotesMetadataList & other);
    NotesMetadataList(NotesMetadataList && other) noexcept;
    ~NotesMetadataList() noexcept override;

    NotesMetadataList & operator=(const NotesMetadataList & other);
    NotesMetadataList & operator=(NotesMetadataList && other) noexcept;

    /**
     * The starting index within the overall set of notes. This
     * is also the number of notes that are "before" this list in the set.
     */
    [[nodiscard]] qint32 startIndex() const noexcept;
    void setStartIndex(qint32 startIndex);

    /**
     * The number of notes in the larger set. This can be used
     * to calculate how many notes are "after" this note in the set.
     * (I.e. remaining = totalNotes - (startIndex + notes.length) )
     */
    [[nodiscard]] qint32 totalNotes() const noexcept;
    void setTotalNotes(qint32 totalNotes);

    /**
     * The list of metadata for Notes in this range. The set of optional fields
     * that are set in each metadata structure will depend on the
     * NotesMetadataResultSpec provided by the caller when the search was
     * performed. Only the 'guid' field will be guaranteed to be set in each
     * Note.
     */
    [[nodiscard]] const QList<NoteMetadata> & notes() const noexcept;
    [[nodiscard]] QList<NoteMetadata> & mutableNotes();
    void setNotes(QList<NoteMetadata> notes);

    /**
     * If the NoteList was produced using a text based search
     * query that included words that are not indexed or searched by the service,
     * this will include a list of those ignored words.
     */
    [[nodiscard]] const std::optional<QStringList> & stoppedWords() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableStoppedWords();
    void setStoppedWords(std::optional<QStringList> stoppedWords);

    /**
     * If the NoteList was produced using a text based search
     * query that included viable search words or quoted expressions, this will
     * include a list of those words. Any stopped words will not be included
     * in this list.
     */
    [[nodiscard]] const std::optional<QStringList> & searchedWords() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableSearchedWords();
    void setSearchedWords(std::optional<QStringList> searchedWords);

    /**
     * Indicates the total number of transactions that have
     * been committed within the account. This reflects (for example) the
     * number of discrete additions or modifications that have been made to
     * the data in this account (tags, notes, resources, etc.).
     * This number is the "high water mark" for Update Sequence Numbers (USN)
     * within the account.
     */
    [[nodiscard]] const std::optional<qint32> & updateCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateCount();
    void setUpdateCount(std::optional<qint32> updateCount);

    /**
     * Specifies the correlating information about the current search session, in byte array.
     */
    [[nodiscard]] const std::optional<QByteArray> & searchContextBytes() const noexcept;
    void setSearchContextBytes(std::optional<QByteArray> searchContextBytes);

    /**
     * Depends on the value of <code>context</code> in NoteFilter, this field
     * may contain debug information if the service decides to do so.
     */
    [[nodiscard]] const std::optional<QString> & debugInfo() const noexcept;
    void setDebugInfo(std::optional<QString> debugInfo);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(qint32 startIndex READ startIndex WRITE setStartIndex)
    Q_PROPERTY(qint32 totalNotes READ totalNotes WRITE setTotalNotes)
    Q_PROPERTY(QList<NoteMetadata> notes READ notes WRITE setNotes)
    Q_PROPERTY(std::optional<QStringList> stoppedWords READ stoppedWords WRITE setStoppedWords)
    Q_PROPERTY(std::optional<QStringList> searchedWords READ searchedWords WRITE setSearchedWords)
    Q_PROPERTY(std::optional<qint32> updateCount READ updateCount WRITE setUpdateCount)
    Q_PROPERTY(std::optional<QByteArray> searchContextBytes READ searchContextBytes WRITE setSearchContextBytes)
    Q_PROPERTY(std::optional<QString> debugInfo READ debugInfo WRITE setDebugInfo)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NotesMetadataList & lhs, const NotesMetadataList & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NotesMetadataList & lhs, const NotesMetadataList & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotesMetadataList)

#endif // QEVERCLOUD_GENERATED_NOTESMETADATALIST
