/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATALISTBUILDER
#define QEVERCLOUD_GENERATED_NOTESMETADATALISTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteMetadata.h>
#include <qevercloud/types/NotesMetadataList.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotesMetadataListBuilder
{
public:
    NotesMetadataListBuilder();

    NotesMetadataListBuilder(NotesMetadataListBuilder && other) noexcept;

    ~NotesMetadataListBuilder() noexcept;

    NotesMetadataListBuilder & operator=(NotesMetadataListBuilder && other) noexcept;

    NotesMetadataListBuilder & setStartIndex(qint32 startIndex);
    NotesMetadataListBuilder & setTotalNotes(qint32 totalNotes);
    NotesMetadataListBuilder & setNotes(QList<NoteMetadata> notes);
    NotesMetadataListBuilder & setStoppedWords(std::optional<QStringList> stoppedWords);
    NotesMetadataListBuilder & setSearchedWords(std::optional<QStringList> searchedWords);
    NotesMetadataListBuilder & setUpdateCount(std::optional<qint32> updateCount);
    NotesMetadataListBuilder & setSearchContextBytes(std::optional<QByteArray> searchContextBytes);
    NotesMetadataListBuilder & setDebugInfo(std::optional<QString> debugInfo);

    [[nodiscard]] NotesMetadataList build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESMETADATALISTBUILDER
