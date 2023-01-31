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

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNKFILTER
#define QEVERCLOUD_GENERATED_SYNCCHUNKFILTER

#include <qevercloud/Export.h>

#include "QSet"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is used with the 'getFilteredSyncChunk' call to provide
 * fine-grained control over the data that's returned when a client needs
 * to synchronize with the service. Each flag in this structure specifies
 * whether to include one class of data in the results of that call.
 *
 **/
class QEVERCLOUD_EXPORT SyncChunkFilter: public Printable
{
    Q_GADGET
public:
    SyncChunkFilter();
    SyncChunkFilter(const SyncChunkFilter & other);
    SyncChunkFilter(SyncChunkFilter && other) noexcept;
    ~SyncChunkFilter() noexcept override;

    SyncChunkFilter & operator=(const SyncChunkFilter & other);
    SyncChunkFilter & operator=(SyncChunkFilter && other) noexcept;

    /**
     * If true, then the server will include the SyncChunks.notes field
     */
    [[nodiscard]] const std::optional<bool> & includeNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNotes();
    void setIncludeNotes(std::optional<bool> includeNotes);

    /**
     * If true, then the server will include the 'resources' field on all of
     * the Notes that are in SyncChunk.notes.
     * If 'includeNotes' is false, then this will have no effect.
     */
    [[nodiscard]] const std::optional<bool> & includeNoteResources() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNoteResources();
    void setIncludeNoteResources(std::optional<bool> includeNoteResources);

    /**
     * If true, then the server will include the 'attributes' field on all of
     * the Notes that are in SyncChunks.notes.
     * If 'includeNotes' is false, then this will have no effect.
     */
    [[nodiscard]] const std::optional<bool> & includeNoteAttributes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNoteAttributes();
    void setIncludeNoteAttributes(std::optional<bool> includeNoteAttributes);

    /**
     * If true, then the server will include the SyncChunks.notebooks field
     */
    [[nodiscard]] const std::optional<bool> & includeNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNotebooks();
    void setIncludeNotebooks(std::optional<bool> includeNotebooks);

    /**
     * If true, then the server will include the SyncChunks.tags field
     */
    [[nodiscard]] const std::optional<bool> & includeTags() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeTags();
    void setIncludeTags(std::optional<bool> includeTags);

    /**
     * If true, then the server will include the SyncChunks.searches field
     */
    [[nodiscard]] const std::optional<bool> & includeSearches() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeSearches();
    void setIncludeSearches(std::optional<bool> includeSearches);

    /**
     * If true, then the server will include the SyncChunks.resources field.
     * Since the Resources are also provided with their Note
     * (in the Notes.resources list), this is primarily useful for clients that
     * want to watch for changes to individual Resources due to recognition data
     * being added.
     */
    [[nodiscard]] const std::optional<bool> & includeResources() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResources();
    void setIncludeResources(std::optional<bool> includeResources);

    /**
     * If true, then the server will include the SyncChunks.linkedNotebooks field.
     */
    [[nodiscard]] const std::optional<bool> & includeLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeLinkedNotebooks();
    void setIncludeLinkedNotebooks(std::optional<bool> includeLinkedNotebooks);

    /**
     * If true, then the server will include the 'expunged' data for any type
     * of included data. For example, if 'includeTags' and 'includeExpunged'
     * are both true, then the SyncChunks.expungedTags field will be set with
     * the GUIDs of tags that have been expunged from the server.
     */
    [[nodiscard]] const std::optional<bool> & includeExpunged() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeExpunged();
    void setIncludeExpunged(std::optional<bool> includeExpunged);

    /**
     * If true, then the values for the applicationData map will be filled
     * in, assuming notes and note attributes are being returned. Otherwise,
     * only the keysOnly field will be filled in.
     */
    [[nodiscard]] const std::optional<bool> & includeNoteApplicationDataFullMap() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNoteApplicationDataFullMap();
    void setIncludeNoteApplicationDataFullMap(std::optional<bool> includeNoteApplicationDataFullMap);

    /**
     * If true, then the fullMap values for the applicationData map will be
     * filled in, assuming resources and resource attributes are being returned
     * (includeResources is true). Otherwise, only the keysOnly field will be
     * filled in.
     */
    [[nodiscard]] const std::optional<bool> & includeResourceApplicationDataFullMap() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResourceApplicationDataFullMap();
    void setIncludeResourceApplicationDataFullMap(std::optional<bool> includeResourceApplicationDataFullMap);

    /**
     * If true, then the fullMap values for the applicationData map will be
     * filled in for resources found inside of notes, assuming resources are
     * being returned in notes (includeNoteResources is true). Otherwise,
     * only the keysOnly field will be filled in.
     */
    [[nodiscard]] const std::optional<bool> & includeNoteResourceApplicationDataFullMap() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNoteResourceApplicationDataFullMap();
    void setIncludeNoteResourceApplicationDataFullMap(std::optional<bool> includeNoteResourceApplicationDataFullMap);

    /**
     * If true, then the service will include the sharedNotes field on all
     * notes that are in SyncChunk.notes. If 'includeNotes' is false, then
     * this will have no effect.
     */
    [[nodiscard]] const std::optional<bool> & includeSharedNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeSharedNotes();
    void setIncludeSharedNotes(std::optional<bool> includeSharedNotes);

    [[nodiscard]] const std::optional<bool> & omitSharedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableOmitSharedNotebooks();
    void setOmitSharedNotebooks(std::optional<bool> omitSharedNotebooks);

    /**
     * If set, then only send notes whose content class matches this value.
     * The value can be a literal match or, if the last character is an
     * asterisk, a prefix match.
     */
    [[nodiscard]] const std::optional<QString> & requireNoteContentClass() const noexcept;
    void setRequireNoteContentClass(std::optional<QString> requireNoteContentClass);

    /**
     * If set, then restrict the returned notebooks, notes, and
     * resources to those associated with one of the notebooks whose
     * GUID is provided in this list. If not set, then no filtering on
     * notebook GUID will be performed. If you set this field, you may
     * not also set includeExpunged else an EDAMUserException with an
     * error code of DATA_CONFLICT will be thrown. You only need to set
     * this field if you want to restrict the returned entities more
     * than what your authentication token allows you to access. For
     * example, there is no need to set this field for single notebook
     * tokens such as for shared notebooks. You can use this field to
     * synchronize a newly discovered business notebook while
     * incrementally synchronizing a business account, in which case you
     * will only need to consider setting includeNotes,
     * includeNotebooks, includeNoteAttributes, includeNoteResources,
     * and maybe some of the "FullMap" fields.
     */
    [[nodiscard]] const std::optional<QSet<QString>> & notebookGuids() const noexcept;
    [[nodiscard]] std::optional<QSet<QString>> & mutableNotebookGuids();
    void setNotebookGuids(std::optional<QSet<QString>> notebookGuids);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SyncChunkFilter & syncChunkFilter);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SyncChunkFilter & syncChunkFilter);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SyncChunkFilter & syncChunkFilter);

    Q_PROPERTY(std::optional<bool> includeNotes READ includeNotes WRITE setIncludeNotes)
    Q_PROPERTY(std::optional<bool> includeNoteResources READ includeNoteResources WRITE setIncludeNoteResources)
    Q_PROPERTY(std::optional<bool> includeNoteAttributes READ includeNoteAttributes WRITE setIncludeNoteAttributes)
    Q_PROPERTY(std::optional<bool> includeNotebooks READ includeNotebooks WRITE setIncludeNotebooks)
    Q_PROPERTY(std::optional<bool> includeTags READ includeTags WRITE setIncludeTags)
    Q_PROPERTY(std::optional<bool> includeSearches READ includeSearches WRITE setIncludeSearches)
    Q_PROPERTY(std::optional<bool> includeResources READ includeResources WRITE setIncludeResources)
    Q_PROPERTY(std::optional<bool> includeLinkedNotebooks READ includeLinkedNotebooks WRITE setIncludeLinkedNotebooks)
    Q_PROPERTY(std::optional<bool> includeExpunged READ includeExpunged WRITE setIncludeExpunged)
    Q_PROPERTY(std::optional<bool> includeNoteApplicationDataFullMap READ includeNoteApplicationDataFullMap WRITE setIncludeNoteApplicationDataFullMap)
    Q_PROPERTY(std::optional<bool> includeResourceApplicationDataFullMap READ includeResourceApplicationDataFullMap WRITE setIncludeResourceApplicationDataFullMap)
    Q_PROPERTY(std::optional<bool> includeNoteResourceApplicationDataFullMap READ includeNoteResourceApplicationDataFullMap WRITE setIncludeNoteResourceApplicationDataFullMap)
    Q_PROPERTY(std::optional<bool> includeSharedNotes READ includeSharedNotes WRITE setIncludeSharedNotes)
    Q_PROPERTY(std::optional<bool> omitSharedNotebooks READ omitSharedNotebooks WRITE setOmitSharedNotebooks)
    Q_PROPERTY(std::optional<QString> requireNoteContentClass READ requireNoteContentClass WRITE setRequireNoteContentClass)
    Q_PROPERTY(std::optional<QSet<QString>> notebookGuids READ notebookGuids WRITE setNotebookGuids)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SyncChunkFilter & lhs, const SyncChunkFilter & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SyncChunkFilter & lhs, const SyncChunkFilter & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNKFILTER
