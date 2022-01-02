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

#include <qevercloud/types/builders/NoteFilterBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteFilterBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_order;
    std::optional<bool> m_ascending;
    std::optional<QString> m_words;
    std::optional<Guid> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<QString> m_timeZone;
    std::optional<bool> m_inactive;
    std::optional<QString> m_emphasized;
    std::optional<bool> m_includeAllReadableNotebooks;
    std::optional<bool> m_includeAllReadableWorkspaces;
    std::optional<QString> m_context;
    std::optional<QString> m_rawWords;
    std::optional<QByteArray> m_searchContextBytes;
};

NoteFilterBuilder::NoteFilterBuilder() :
    d(new NoteFilterBuilder::Impl)
{}

NoteFilterBuilder::NoteFilterBuilder(NoteFilterBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteFilterBuilder::~NoteFilterBuilder() noexcept = default;

NoteFilterBuilder & NoteFilterBuilder::operator=(NoteFilterBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setOrder(std::optional<qint32> order)
{
    d->m_order = std::move(order);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setAscending(std::optional<bool> ascending)
{
    d->m_ascending = std::move(ascending);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setWords(std::optional<QString> words)
{
    d->m_words = std::move(words);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = std::move(tagGuids);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setTimeZone(std::optional<QString> timeZone)
{
    d->m_timeZone = std::move(timeZone);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setInactive(std::optional<bool> inactive)
{
    d->m_inactive = std::move(inactive);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setEmphasized(std::optional<QString> emphasized)
{
    d->m_emphasized = std::move(emphasized);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setIncludeAllReadableNotebooks(std::optional<bool> includeAllReadableNotebooks)
{
    d->m_includeAllReadableNotebooks = std::move(includeAllReadableNotebooks);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setIncludeAllReadableWorkspaces(std::optional<bool> includeAllReadableWorkspaces)
{
    d->m_includeAllReadableWorkspaces = std::move(includeAllReadableWorkspaces);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setContext(std::optional<QString> context)
{
    d->m_context = std::move(context);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setRawWords(std::optional<QString> rawWords)
{
    d->m_rawWords = std::move(rawWords);
    return *this;
}

NoteFilterBuilder & NoteFilterBuilder::setSearchContextBytes(std::optional<QByteArray> searchContextBytes)
{
    d->m_searchContextBytes = std::move(searchContextBytes);
    return *this;
}

NoteFilter NoteFilterBuilder::build()
{
    NoteFilter result;

    result.setOrder(std::move(d->m_order));
    result.setAscending(std::move(d->m_ascending));
    result.setWords(std::move(d->m_words));
    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setTagGuids(std::move(d->m_tagGuids));
    result.setTimeZone(std::move(d->m_timeZone));
    result.setInactive(std::move(d->m_inactive));
    result.setEmphasized(std::move(d->m_emphasized));
    result.setIncludeAllReadableNotebooks(std::move(d->m_includeAllReadableNotebooks));
    result.setIncludeAllReadableWorkspaces(std::move(d->m_includeAllReadableWorkspaces));
    result.setContext(std::move(d->m_context));
    result.setRawWords(std::move(d->m_rawWords));
    result.setSearchContextBytes(std::move(d->m_searchContextBytes));

    d->m_order = {};
    d->m_ascending = {};
    d->m_words = {};
    d->m_notebookGuid = {};
    d->m_tagGuids = {};
    d->m_timeZone = {};
    d->m_inactive = {};
    d->m_emphasized = {};
    d->m_includeAllReadableNotebooks = {};
    d->m_includeAllReadableWorkspaces = {};
    d->m_context = {};
    d->m_rawWords = {};
    d->m_searchContextBytes = {};

    return result;
}

} // namespace qevercloud
