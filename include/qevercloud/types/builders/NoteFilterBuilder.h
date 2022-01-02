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

#ifndef QEVERCLOUD_GENERATED_NOTEFILTERBUILDER
#define QEVERCLOUD_GENERATED_NOTEFILTERBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteFilter.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteFilterBuilder
{
public:
    NoteFilterBuilder();

    NoteFilterBuilder(NoteFilterBuilder && other) noexcept;

    ~NoteFilterBuilder() noexcept;

    NoteFilterBuilder & operator=(NoteFilterBuilder && other) noexcept;

    NoteFilterBuilder & setOrder(std::optional<qint32> order);
    NoteFilterBuilder & setAscending(std::optional<bool> ascending);
    NoteFilterBuilder & setWords(std::optional<QString> words);
    NoteFilterBuilder & setNotebookGuid(std::optional<Guid> notebookGuid);
    NoteFilterBuilder & setTagGuids(std::optional<QList<Guid>> tagGuids);
    NoteFilterBuilder & setTimeZone(std::optional<QString> timeZone);
    NoteFilterBuilder & setInactive(std::optional<bool> inactive);
    NoteFilterBuilder & setEmphasized(std::optional<QString> emphasized);
    NoteFilterBuilder & setIncludeAllReadableNotebooks(std::optional<bool> includeAllReadableNotebooks);
    NoteFilterBuilder & setIncludeAllReadableWorkspaces(std::optional<bool> includeAllReadableWorkspaces);
    NoteFilterBuilder & setContext(std::optional<QString> context);
    NoteFilterBuilder & setRawWords(std::optional<QString> rawWords);
    NoteFilterBuilder & setSearchContextBytes(std::optional<QByteArray> searchContextBytes);

    [[nodiscard]] NoteFilter build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEFILTERBUILDER
