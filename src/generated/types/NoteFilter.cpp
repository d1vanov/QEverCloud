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

#include <qevercloud/generated/types/NoteFilter.h>

#include "impl/NoteFilterImpl.h"

namespace qevercloud {

NoteFilter::NoteFilter() :
    d(new NoteFilter::Impl)
 {}

NoteFilter::NoteFilter(const NoteFilter & other) :
    d(other.d)
{}

NoteFilter::NoteFilter(NoteFilter && other) noexcept :
    d(std::move(other.d))
{}

NoteFilter::~NoteFilter() noexcept {}

NoteFilter & NoteFilter::operator=(const NoteFilter & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteFilter & NoteFilter::operator=(NoteFilter && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & NoteFilter::order() const noexcept
{
    return d->m_order;
}

std::optional<qint32> & NoteFilter::mutableOrder()
{
    return d->m_order;
}

void NoteFilter::setOrder(std::optional<qint32> order)
{
    d->m_order = order;
}

const std::optional<bool> & NoteFilter::ascending() const noexcept
{
    return d->m_ascending;
}

std::optional<bool> & NoteFilter::mutableAscending()
{
    return d->m_ascending;
}

void NoteFilter::setAscending(std::optional<bool> ascending)
{
    d->m_ascending = ascending;
}

const std::optional<QString> & NoteFilter::words() const noexcept
{
    return d->m_words;
}

void NoteFilter::setWords(std::optional<QString> words)
{
    d->m_words = words;
}

const std::optional<Guid> & NoteFilter::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

std::optional<Guid> & NoteFilter::mutableNotebookGuid()
{
    return d->m_notebookGuid;
}

void NoteFilter::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<QList<Guid>> & NoteFilter::tagGuids() const noexcept
{
    return d->m_tagGuids;
}

std::optional<QList<Guid>> & NoteFilter::mutableTagGuids()
{
    return d->m_tagGuids;
}

void NoteFilter::setTagGuids(std::optional<QList<Guid>> tagGuids)
{
    d->m_tagGuids = tagGuids;
}

const std::optional<QString> & NoteFilter::timeZone() const noexcept
{
    return d->m_timeZone;
}

void NoteFilter::setTimeZone(std::optional<QString> timeZone)
{
    d->m_timeZone = timeZone;
}

const std::optional<bool> & NoteFilter::inactive() const noexcept
{
    return d->m_inactive;
}

std::optional<bool> & NoteFilter::mutableInactive()
{
    return d->m_inactive;
}

void NoteFilter::setInactive(std::optional<bool> inactive)
{
    d->m_inactive = inactive;
}

const std::optional<QString> & NoteFilter::emphasized() const noexcept
{
    return d->m_emphasized;
}

void NoteFilter::setEmphasized(std::optional<QString> emphasized)
{
    d->m_emphasized = emphasized;
}

const std::optional<bool> & NoteFilter::includeAllReadableNotebooks() const noexcept
{
    return d->m_includeAllReadableNotebooks;
}

std::optional<bool> & NoteFilter::mutableIncludeAllReadableNotebooks()
{
    return d->m_includeAllReadableNotebooks;
}

void NoteFilter::setIncludeAllReadableNotebooks(std::optional<bool> includeAllReadableNotebooks)
{
    d->m_includeAllReadableNotebooks = includeAllReadableNotebooks;
}

const std::optional<bool> & NoteFilter::includeAllReadableWorkspaces() const noexcept
{
    return d->m_includeAllReadableWorkspaces;
}

std::optional<bool> & NoteFilter::mutableIncludeAllReadableWorkspaces()
{
    return d->m_includeAllReadableWorkspaces;
}

void NoteFilter::setIncludeAllReadableWorkspaces(std::optional<bool> includeAllReadableWorkspaces)
{
    d->m_includeAllReadableWorkspaces = includeAllReadableWorkspaces;
}

const std::optional<QString> & NoteFilter::context() const noexcept
{
    return d->m_context;
}

void NoteFilter::setContext(std::optional<QString> context)
{
    d->m_context = context;
}

const std::optional<QString> & NoteFilter::rawWords() const noexcept
{
    return d->m_rawWords;
}

void NoteFilter::setRawWords(std::optional<QString> rawWords)
{
    d->m_rawWords = rawWords;
}

const std::optional<QByteArray> & NoteFilter::searchContextBytes() const noexcept
{
    return d->m_searchContextBytes;
}

void NoteFilter::setSearchContextBytes(std::optional<QByteArray> searchContextBytes)
{
    d->m_searchContextBytes = searchContextBytes;
}

void NoteFilter::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteFilter::operator==(const NoteFilter & other) const noexcept
{
    return *d == *other.d;
}

bool NoteFilter::operator!=(const NoteFilter & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
