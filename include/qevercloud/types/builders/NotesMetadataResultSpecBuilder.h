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

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECBUILDER
#define QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NotesMetadataResultSpec.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotesMetadataResultSpecBuilder
{
public:
    NotesMetadataResultSpecBuilder();

    NotesMetadataResultSpecBuilder(NotesMetadataResultSpecBuilder && other) noexcept;

    ~NotesMetadataResultSpecBuilder() noexcept;

    NotesMetadataResultSpecBuilder & operator=(NotesMetadataResultSpecBuilder && other) noexcept;

    NotesMetadataResultSpecBuilder & setIncludeTitle(std::optional<bool> includeTitle);
    NotesMetadataResultSpecBuilder & setIncludeContentLength(std::optional<bool> includeContentLength);
    NotesMetadataResultSpecBuilder & setIncludeCreated(std::optional<bool> includeCreated);
    NotesMetadataResultSpecBuilder & setIncludeUpdated(std::optional<bool> includeUpdated);
    NotesMetadataResultSpecBuilder & setIncludeDeleted(std::optional<bool> includeDeleted);
    NotesMetadataResultSpecBuilder & setIncludeUpdateSequenceNum(std::optional<bool> includeUpdateSequenceNum);
    NotesMetadataResultSpecBuilder & setIncludeNotebookGuid(std::optional<bool> includeNotebookGuid);
    NotesMetadataResultSpecBuilder & setIncludeTagGuids(std::optional<bool> includeTagGuids);
    NotesMetadataResultSpecBuilder & setIncludeAttributes(std::optional<bool> includeAttributes);
    NotesMetadataResultSpecBuilder & setIncludeLargestResourceMime(std::optional<bool> includeLargestResourceMime);
    NotesMetadataResultSpecBuilder & setIncludeLargestResourceSize(std::optional<bool> includeLargestResourceSize);

    [[nodiscard]] NotesMetadataResultSpec build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECBUILDER
