/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNK
#define QEVERCLOUD_GENERATED_SYNCCHUNK

#include <qevercloud/Export.h>

#include "LinkedNotebook.h"
#include "Note.h"
#include "Notebook.h"
#include "Resource.h"
#include "SavedSearch.h"
#include "Tag.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is given out by the NoteStore when a client asks to
 * receive the current state of an account.  The client asks for the server's
 * state one chunk at a time in order to allow clients to retrieve the state
 * of a large account without needing to transfer the entire account in
 * a single message.
 *
 * The server always gives SyncChunks using an ascending series of Update
 * Sequence Numbers (USNs).
 *
 **/
class QEVERCLOUD_EXPORT SyncChunk: public Printable
{
    Q_GADGET
public:
    SyncChunk();
    SyncChunk(const SyncChunk & other);
    SyncChunk(SyncChunk && other) noexcept;
    ~SyncChunk() noexcept override;

    SyncChunk & operator=(const SyncChunk & other);
    SyncChunk & operator=(SyncChunk && other) noexcept;

    /**
     * The server's current date and time.
     */
    [[nodiscard]] Timestamp currentTime() const noexcept;
    void setCurrentTime(Timestamp currentTime);

    /**
     * The highest USN for any of the data objects represented
     * in this sync chunk. If there are no objects in the chunk, this will not be
     * set.
     */
    [[nodiscard]] const std::optional<qint32> & chunkHighUSN() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableChunkHighUSN();
    void setChunkHighUSN(std::optional<qint32> chunkHighUSN);

    /**
     * The total number of updates that have been performed in
     * the service for this account. This is equal to the highest USN within the
     * account at the point that this SyncChunk was generated. If updateCount
     * and chunkHighUSN are identical, that means that this is the last chunk
     * in the account ... there is no more recent information.
     */
    [[nodiscard]] qint32 updateCount() const noexcept;
    void setUpdateCount(qint32 updateCount);

    /**
     * If present, this is a list of non-expunged notes that
     * have a USN in this chunk. This will include notes that are "deleted"
     * but not expunged (i.e. in the trash). The notes will include their list
     * of tags and resources, but the note content, resource content, resource
     * recognition data and resource alternate data will not be supplied.
     */
    [[nodiscard]] const std::optional<QList<Note>> & notes() const noexcept;
    [[nodiscard]] std::optional<QList<Note>> & mutableNotes();
    void setNotes(std::optional<QList<Note>> notes);

    /**
     * If present, this is a list of non-expunged notebooks that
     * have a USN in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Notebook>> & notebooks() const noexcept;
    [[nodiscard]] std::optional<QList<Notebook>> & mutableNotebooks();
    void setNotebooks(std::optional<QList<Notebook>> notebooks);

    /**
     * If present, this is a list of the non-expunged tags that have a
     * USN in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Tag>> & tags() const noexcept;
    [[nodiscard]] std::optional<QList<Tag>> & mutableTags();
    void setTags(std::optional<QList<Tag>> tags);

    /**
     * If present, this is a list of non-expunged searches that
     * have a USN in this chunk.
     */
    [[nodiscard]] const std::optional<QList<SavedSearch>> & searches() const noexcept;
    [[nodiscard]] std::optional<QList<SavedSearch>> & mutableSearches();
    void setSearches(std::optional<QList<SavedSearch>> searches);

    /**
     * If present, this is a list of the non-expunged resources
     * that have a USN in this chunk. This will include the metadata for each
     * resource, but not its binary contents or recognition data, which must be
     * retrieved separately.
     */
    [[nodiscard]] const std::optional<QList<Resource>> & resources() const noexcept;
    [[nodiscard]] std::optional<QList<Resource>> & mutableResources();
    void setResources(std::optional<QList<Resource>> resources);

    /**
     * If present, the GUIDs of all of the notes that were
     * permanently expunged in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & expungedNotes() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableExpungedNotes();
    void setExpungedNotes(std::optional<QList<Guid>> expungedNotes);

    /**
     * If present, the GUIDs of all of the notebooks that
     * were permanently expunged in this chunk. When a notebook is expunged,
     * this implies that all of its child notes (and their resources) were
     * also expunged.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & expungedNotebooks() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableExpungedNotebooks();
    void setExpungedNotebooks(std::optional<QList<Guid>> expungedNotebooks);

    /**
     * If present, the GUIDs of all of the tags that were
     * permanently expunged in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & expungedTags() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableExpungedTags();
    void setExpungedTags(std::optional<QList<Guid>> expungedTags);

    /**
     * If present, the GUIDs of all of the saved searches
     * that were permanently expunged in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & expungedSearches() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableExpungedSearches();
    void setExpungedSearches(std::optional<QList<Guid>> expungedSearches);

    /**
     * If present, this is a list of non-expunged LinkedNotebooks that
     * have a USN in this chunk.
     */
    [[nodiscard]] const std::optional<QList<LinkedNotebook>> & linkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<QList<LinkedNotebook>> & mutableLinkedNotebooks();
    void setLinkedNotebooks(std::optional<QList<LinkedNotebook>> linkedNotebooks);

    /**
     * If present, the GUIDs of all of the LinkedNotebooks
     * that were permanently expunged in this chunk.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & expungedLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableExpungedLinkedNotebooks();
    void setExpungedLinkedNotebooks(std::optional<QList<Guid>> expungedLinkedNotebooks);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SyncChunk & syncChunk);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SyncChunk & syncChunk);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SyncChunk & syncChunk);

    Q_PROPERTY(Timestamp currentTime READ currentTime WRITE setCurrentTime)
    Q_PROPERTY(std::optional<qint32> chunkHighUSN READ chunkHighUSN WRITE setChunkHighUSN)
    Q_PROPERTY(qint32 updateCount READ updateCount WRITE setUpdateCount)
    Q_PROPERTY(std::optional<QList<Note>> notes READ notes WRITE setNotes)
    Q_PROPERTY(std::optional<QList<Notebook>> notebooks READ notebooks WRITE setNotebooks)
    Q_PROPERTY(std::optional<QList<Tag>> tags READ tags WRITE setTags)
    Q_PROPERTY(std::optional<QList<SavedSearch>> searches READ searches WRITE setSearches)
    Q_PROPERTY(std::optional<QList<Resource>> resources READ resources WRITE setResources)
    Q_PROPERTY(std::optional<QList<Guid>> expungedNotes READ expungedNotes WRITE setExpungedNotes)
    Q_PROPERTY(std::optional<QList<Guid>> expungedNotebooks READ expungedNotebooks WRITE setExpungedNotebooks)
    Q_PROPERTY(std::optional<QList<Guid>> expungedTags READ expungedTags WRITE setExpungedTags)
    Q_PROPERTY(std::optional<QList<Guid>> expungedSearches READ expungedSearches WRITE setExpungedSearches)
    Q_PROPERTY(std::optional<QList<LinkedNotebook>> linkedNotebooks READ linkedNotebooks WRITE setLinkedNotebooks)
    Q_PROPERTY(std::optional<QList<Guid>> expungedLinkedNotebooks READ expungedLinkedNotebooks WRITE setExpungedLinkedNotebooks)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SyncChunk & lhs, const SyncChunk & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SyncChunk & lhs, const SyncChunk & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNK
