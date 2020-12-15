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

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPEC_H
#define QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPEC_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <optional>

namespace qevercloud {

/**
 * This structure is provided to the findNotesMetadata function to specify
 * the subset of fields that should be included in each NoteMetadata element
 * that is returned in the NotesMetadataList.
 * Each field on this structure is a boolean flag that indicates whether the
 * corresponding field should be included in the NoteMetadata structure when
 * it is returned.  For example, if the 'includeTitle' field is set on this
 * structure when calling findNotesMetadata, then each NoteMetadata in the
 * list should have its 'title' field set.
 * If one of the fields in this spec is not set, then it will be treated as
 * 'false' by the server, so the default behavior is to include nothing in
 * replies (but the mandatory GUID)
 */
class QEVERCLOUD_EXPORT NotesMetadataResultSpec: public Printable
{
    Q_GADGET
public:
    NotesMetadataResultSpec();
    NotesMetadataResultSpec(const NotesMetadataResultSpec & other);
    NotesMetadataResultSpec(NotesMetadataResultSpec && other) noexcept;
    ~NotesMetadataResultSpec() noexcept override;

    NotesMetadataResultSpec & operator=(const NotesMetadataResultSpec & other);
    NotesMetadataResultSpec & operator=(NotesMetadataResultSpec && other) noexcept;

    [[nodiscard]] const std::optional<bool> & includeTitle() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeTitle();
    void setIncludeTitle(std::optional<bool> includeTitle);

    [[nodiscard]] const std::optional<bool> & includeContentLength() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeContentLength();
    void setIncludeContentLength(std::optional<bool> includeContentLength);

    [[nodiscard]] const std::optional<bool> & includeCreated() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeCreated();
    void setIncludeCreated(std::optional<bool> includeCreated);

    [[nodiscard]] const std::optional<bool> & includeUpdated() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeUpdated();
    void setIncludeUpdated(std::optional<bool> includeUpdated);

    [[nodiscard]] const std::optional<bool> & includeDeleted() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeDeleted();
    void setIncludeDeleted(std::optional<bool> includeDeleted);

    [[nodiscard]] const std::optional<bool> & includeUpdateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeUpdateSequenceNum();
    void setIncludeUpdateSequenceNum(std::optional<bool> includeUpdateSequenceNum);

    [[nodiscard]] const std::optional<bool> & includeNotebookGuid() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNotebookGuid();
    void setIncludeNotebookGuid(std::optional<bool> includeNotebookGuid);

    [[nodiscard]] const std::optional<bool> & includeTagGuids() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeTagGuids();
    void setIncludeTagGuids(std::optional<bool> includeTagGuids);

    [[nodiscard]] const std::optional<bool> & includeAttributes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAttributes();
    void setIncludeAttributes(std::optional<bool> includeAttributes);

    [[nodiscard]] const std::optional<bool> & includeLargestResourceMime() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeLargestResourceMime();
    void setIncludeLargestResourceMime(std::optional<bool> includeLargestResourceMime);

    [[nodiscard]] const std::optional<bool> & includeLargestResourceSize() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeLargestResourceSize();
    void setIncludeLargestResourceSize(std::optional<bool> includeLargestResourceSize);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NotesMetadataResultSpec & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotesMetadataResultSpec & other) const noexcept;

    Q_PROPERTY(std::optional<bool> includeTitle READ includeTitle WRITE setIncludeTitle)
    Q_PROPERTY(std::optional<bool> includeContentLength READ includeContentLength WRITE setIncludeContentLength)
    Q_PROPERTY(std::optional<bool> includeCreated READ includeCreated WRITE setIncludeCreated)
    Q_PROPERTY(std::optional<bool> includeUpdated READ includeUpdated WRITE setIncludeUpdated)
    Q_PROPERTY(std::optional<bool> includeDeleted READ includeDeleted WRITE setIncludeDeleted)
    Q_PROPERTY(std::optional<bool> includeUpdateSequenceNum READ includeUpdateSequenceNum WRITE setIncludeUpdateSequenceNum)
    Q_PROPERTY(std::optional<bool> includeNotebookGuid READ includeNotebookGuid WRITE setIncludeNotebookGuid)
    Q_PROPERTY(std::optional<bool> includeTagGuids READ includeTagGuids WRITE setIncludeTagGuids)
    Q_PROPERTY(std::optional<bool> includeAttributes READ includeAttributes WRITE setIncludeAttributes)
    Q_PROPERTY(std::optional<bool> includeLargestResourceMime READ includeLargestResourceMime WRITE setIncludeLargestResourceMime)
    Q_PROPERTY(std::optional<bool> includeLargestResourceSize READ includeLargestResourceSize WRITE setIncludeLargestResourceSize)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotesMetadataResultSpec)

#endif // QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPEC_H