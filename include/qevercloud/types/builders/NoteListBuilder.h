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

#ifndef QEVERCLOUD_GENERATED_NOTELISTBUILDER
#define QEVERCLOUD_GENERATED_NOTELISTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/NoteList.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteListBuilder
{
public:
    NoteListBuilder();

    NoteListBuilder(NoteListBuilder && other) noexcept;

    ~NoteListBuilder() noexcept;

    NoteListBuilder & operator=(NoteListBuilder && other) noexcept;

    NoteListBuilder & setStartIndex(qint32 startIndex);
    NoteListBuilder & setTotalNotes(qint32 totalNotes);
    NoteListBuilder & setNotes(QList<Note> notes);
    NoteListBuilder & setStoppedWords(std::optional<QStringList> stoppedWords);
    NoteListBuilder & setSearchedWords(std::optional<QStringList> searchedWords);
    NoteListBuilder & setUpdateCount(std::optional<qint32> updateCount);
    NoteListBuilder & setSearchContextBytes(std::optional<QByteArray> searchContextBytes);
    NoteListBuilder & setDebugInfo(std::optional<QString> debugInfo);

    [[nodiscard]] NoteList build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTELISTBUILDER
