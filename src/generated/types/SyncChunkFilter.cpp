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

#include <qevercloud/generated/types/SyncChunkFilter.h>

#include "impl/SyncChunkFilterImpl.h"

namespace qevercloud {

SyncChunkFilter::SyncChunkFilter() :
    d(new SyncChunkFilter::Impl)
 {}

SyncChunkFilter::SyncChunkFilter(const SyncChunkFilter & other) :
    d(other.d)
{}

SyncChunkFilter::SyncChunkFilter(SyncChunkFilter && other) noexcept :
    d(std::move(other.d))
{}

SyncChunkFilter::~SyncChunkFilter() noexcept {}

SyncChunkFilter & SyncChunkFilter::operator=(const SyncChunkFilter & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SyncChunkFilter & SyncChunkFilter::operator=(SyncChunkFilter && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & SyncChunkFilter::includeNotes() const noexcept
{
    return d->m_includeNotes;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNotes()
{
    return d->m_includeNotes;
}

void SyncChunkFilter::setIncludeNotes(std::optional<bool> includeNotes)
{
    d->m_includeNotes = includeNotes;
}

const std::optional<bool> & SyncChunkFilter::includeNoteResources() const noexcept
{
    return d->m_includeNoteResources;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNoteResources()
{
    return d->m_includeNoteResources;
}

void SyncChunkFilter::setIncludeNoteResources(std::optional<bool> includeNoteResources)
{
    d->m_includeNoteResources = includeNoteResources;
}

const std::optional<bool> & SyncChunkFilter::includeNoteAttributes() const noexcept
{
    return d->m_includeNoteAttributes;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNoteAttributes()
{
    return d->m_includeNoteAttributes;
}

void SyncChunkFilter::setIncludeNoteAttributes(std::optional<bool> includeNoteAttributes)
{
    d->m_includeNoteAttributes = includeNoteAttributes;
}

const std::optional<bool> & SyncChunkFilter::includeNotebooks() const noexcept
{
    return d->m_includeNotebooks;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNotebooks()
{
    return d->m_includeNotebooks;
}

void SyncChunkFilter::setIncludeNotebooks(std::optional<bool> includeNotebooks)
{
    d->m_includeNotebooks = includeNotebooks;
}

const std::optional<bool> & SyncChunkFilter::includeTags() const noexcept
{
    return d->m_includeTags;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeTags()
{
    return d->m_includeTags;
}

void SyncChunkFilter::setIncludeTags(std::optional<bool> includeTags)
{
    d->m_includeTags = includeTags;
}

const std::optional<bool> & SyncChunkFilter::includeSearches() const noexcept
{
    return d->m_includeSearches;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeSearches()
{
    return d->m_includeSearches;
}

void SyncChunkFilter::setIncludeSearches(std::optional<bool> includeSearches)
{
    d->m_includeSearches = includeSearches;
}

const std::optional<bool> & SyncChunkFilter::includeResources() const noexcept
{
    return d->m_includeResources;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeResources()
{
    return d->m_includeResources;
}

void SyncChunkFilter::setIncludeResources(std::optional<bool> includeResources)
{
    d->m_includeResources = includeResources;
}

const std::optional<bool> & SyncChunkFilter::includeLinkedNotebooks() const noexcept
{
    return d->m_includeLinkedNotebooks;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeLinkedNotebooks()
{
    return d->m_includeLinkedNotebooks;
}

void SyncChunkFilter::setIncludeLinkedNotebooks(std::optional<bool> includeLinkedNotebooks)
{
    d->m_includeLinkedNotebooks = includeLinkedNotebooks;
}

const std::optional<bool> & SyncChunkFilter::includeExpunged() const noexcept
{
    return d->m_includeExpunged;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeExpunged()
{
    return d->m_includeExpunged;
}

void SyncChunkFilter::setIncludeExpunged(std::optional<bool> includeExpunged)
{
    d->m_includeExpunged = includeExpunged;
}

const std::optional<bool> & SyncChunkFilter::includeNoteApplicationDataFullMap() const noexcept
{
    return d->m_includeNoteApplicationDataFullMap;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNoteApplicationDataFullMap()
{
    return d->m_includeNoteApplicationDataFullMap;
}

void SyncChunkFilter::setIncludeNoteApplicationDataFullMap(std::optional<bool> includeNoteApplicationDataFullMap)
{
    d->m_includeNoteApplicationDataFullMap = includeNoteApplicationDataFullMap;
}

const std::optional<bool> & SyncChunkFilter::includeResourceApplicationDataFullMap() const noexcept
{
    return d->m_includeResourceApplicationDataFullMap;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeResourceApplicationDataFullMap()
{
    return d->m_includeResourceApplicationDataFullMap;
}

void SyncChunkFilter::setIncludeResourceApplicationDataFullMap(std::optional<bool> includeResourceApplicationDataFullMap)
{
    d->m_includeResourceApplicationDataFullMap = includeResourceApplicationDataFullMap;
}

const std::optional<bool> & SyncChunkFilter::includeNoteResourceApplicationDataFullMap() const noexcept
{
    return d->m_includeNoteResourceApplicationDataFullMap;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeNoteResourceApplicationDataFullMap()
{
    return d->m_includeNoteResourceApplicationDataFullMap;
}

void SyncChunkFilter::setIncludeNoteResourceApplicationDataFullMap(std::optional<bool> includeNoteResourceApplicationDataFullMap)
{
    d->m_includeNoteResourceApplicationDataFullMap = includeNoteResourceApplicationDataFullMap;
}

const std::optional<bool> & SyncChunkFilter::includeSharedNotes() const noexcept
{
    return d->m_includeSharedNotes;
}

std::optional<bool> & SyncChunkFilter::mutableIncludeSharedNotes()
{
    return d->m_includeSharedNotes;
}

void SyncChunkFilter::setIncludeSharedNotes(std::optional<bool> includeSharedNotes)
{
    d->m_includeSharedNotes = includeSharedNotes;
}

const std::optional<bool> & SyncChunkFilter::omitSharedNotebooks() const noexcept
{
    return d->m_omitSharedNotebooks;
}

std::optional<bool> & SyncChunkFilter::mutableOmitSharedNotebooks()
{
    return d->m_omitSharedNotebooks;
}

void SyncChunkFilter::setOmitSharedNotebooks(std::optional<bool> omitSharedNotebooks)
{
    d->m_omitSharedNotebooks = omitSharedNotebooks;
}

const std::optional<QString> & SyncChunkFilter::requireNoteContentClass() const noexcept
{
    return d->m_requireNoteContentClass;
}

void SyncChunkFilter::setRequireNoteContentClass(std::optional<QString> requireNoteContentClass)
{
    d->m_requireNoteContentClass = requireNoteContentClass;
}

const std::optional<QSet<QString>> & SyncChunkFilter::notebookGuids() const noexcept
{
    return d->m_notebookGuids;
}

std::optional<QSet<QString>> & SyncChunkFilter::mutableNotebookGuids()
{
    return d->m_notebookGuids;
}

void SyncChunkFilter::setNotebookGuids(std::optional<QSet<QString>> notebookGuids)
{
    d->m_notebookGuids = notebookGuids;
}

void SyncChunkFilter::print(QTextStream & strm) const
{
    d->print(strm);
}

bool SyncChunkFilter::operator==(const SyncChunkFilter & other) const noexcept
{
    return *d == *other.d;
}

bool SyncChunkFilter::operator!=(const SyncChunkFilter & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
