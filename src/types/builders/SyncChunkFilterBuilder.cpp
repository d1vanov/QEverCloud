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

#include <qevercloud/types/builders/SyncChunkFilterBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncChunkFilterBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_includeNotes;
    std::optional<bool> m_includeNoteResources;
    std::optional<bool> m_includeNoteAttributes;
    std::optional<bool> m_includeNotebooks;
    std::optional<bool> m_includeTags;
    std::optional<bool> m_includeSearches;
    std::optional<bool> m_includeResources;
    std::optional<bool> m_includeLinkedNotebooks;
    std::optional<bool> m_includeExpunged;
    std::optional<bool> m_includeNoteApplicationDataFullMap;
    std::optional<bool> m_includeResourceApplicationDataFullMap;
    std::optional<bool> m_includeNoteResourceApplicationDataFullMap;
    std::optional<bool> m_includeSharedNotes;
    std::optional<bool> m_omitSharedNotebooks;
    std::optional<QString> m_requireNoteContentClass;
    std::optional<QSet<QString>> m_notebookGuids;
};

SyncChunkFilterBuilder::SyncChunkFilterBuilder() :
    d(new SyncChunkFilterBuilder::Impl)
{}

SyncChunkFilterBuilder::SyncChunkFilterBuilder(SyncChunkFilterBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SyncChunkFilterBuilder::~SyncChunkFilterBuilder() noexcept = default;

SyncChunkFilterBuilder & SyncChunkFilterBuilder::operator=(SyncChunkFilterBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNotes(std::optional<bool> includeNotes)
{
    d->m_includeNotes = std::move(includeNotes);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNoteResources(std::optional<bool> includeNoteResources)
{
    d->m_includeNoteResources = std::move(includeNoteResources);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNoteAttributes(std::optional<bool> includeNoteAttributes)
{
    d->m_includeNoteAttributes = std::move(includeNoteAttributes);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNotebooks(std::optional<bool> includeNotebooks)
{
    d->m_includeNotebooks = std::move(includeNotebooks);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeTags(std::optional<bool> includeTags)
{
    d->m_includeTags = std::move(includeTags);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeSearches(std::optional<bool> includeSearches)
{
    d->m_includeSearches = std::move(includeSearches);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeResources(std::optional<bool> includeResources)
{
    d->m_includeResources = std::move(includeResources);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeLinkedNotebooks(std::optional<bool> includeLinkedNotebooks)
{
    d->m_includeLinkedNotebooks = std::move(includeLinkedNotebooks);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeExpunged(std::optional<bool> includeExpunged)
{
    d->m_includeExpunged = std::move(includeExpunged);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNoteApplicationDataFullMap(std::optional<bool> includeNoteApplicationDataFullMap)
{
    d->m_includeNoteApplicationDataFullMap = std::move(includeNoteApplicationDataFullMap);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeResourceApplicationDataFullMap(std::optional<bool> includeResourceApplicationDataFullMap)
{
    d->m_includeResourceApplicationDataFullMap = std::move(includeResourceApplicationDataFullMap);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeNoteResourceApplicationDataFullMap(std::optional<bool> includeNoteResourceApplicationDataFullMap)
{
    d->m_includeNoteResourceApplicationDataFullMap = std::move(includeNoteResourceApplicationDataFullMap);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setIncludeSharedNotes(std::optional<bool> includeSharedNotes)
{
    d->m_includeSharedNotes = std::move(includeSharedNotes);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setOmitSharedNotebooks(std::optional<bool> omitSharedNotebooks)
{
    d->m_omitSharedNotebooks = std::move(omitSharedNotebooks);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setRequireNoteContentClass(std::optional<QString> requireNoteContentClass)
{
    d->m_requireNoteContentClass = std::move(requireNoteContentClass);
    return *this;
}

SyncChunkFilterBuilder & SyncChunkFilterBuilder::setNotebookGuids(std::optional<QSet<QString>> notebookGuids)
{
    d->m_notebookGuids = std::move(notebookGuids);
    return *this;
}

SyncChunkFilter SyncChunkFilterBuilder::build()
{
    SyncChunkFilter result;

    result.setIncludeNotes(std::move(d->m_includeNotes));
    result.setIncludeNoteResources(std::move(d->m_includeNoteResources));
    result.setIncludeNoteAttributes(std::move(d->m_includeNoteAttributes));
    result.setIncludeNotebooks(std::move(d->m_includeNotebooks));
    result.setIncludeTags(std::move(d->m_includeTags));
    result.setIncludeSearches(std::move(d->m_includeSearches));
    result.setIncludeResources(std::move(d->m_includeResources));
    result.setIncludeLinkedNotebooks(std::move(d->m_includeLinkedNotebooks));
    result.setIncludeExpunged(std::move(d->m_includeExpunged));
    result.setIncludeNoteApplicationDataFullMap(std::move(d->m_includeNoteApplicationDataFullMap));
    result.setIncludeResourceApplicationDataFullMap(std::move(d->m_includeResourceApplicationDataFullMap));
    result.setIncludeNoteResourceApplicationDataFullMap(std::move(d->m_includeNoteResourceApplicationDataFullMap));
    result.setIncludeSharedNotes(std::move(d->m_includeSharedNotes));
    result.setOmitSharedNotebooks(std::move(d->m_omitSharedNotebooks));
    result.setRequireNoteContentClass(std::move(d->m_requireNoteContentClass));
    result.setNotebookGuids(std::move(d->m_notebookGuids));

    d->m_includeNotes = {};
    d->m_includeNoteResources = {};
    d->m_includeNoteAttributes = {};
    d->m_includeNotebooks = {};
    d->m_includeTags = {};
    d->m_includeSearches = {};
    d->m_includeResources = {};
    d->m_includeLinkedNotebooks = {};
    d->m_includeExpunged = {};
    d->m_includeNoteApplicationDataFullMap = {};
    d->m_includeResourceApplicationDataFullMap = {};
    d->m_includeNoteResourceApplicationDataFullMap = {};
    d->m_includeSharedNotes = {};
    d->m_omitSharedNotebooks = {};
    d->m_requireNoteContentClass = {};
    d->m_notebookGuids = {};

    return result;
}

} // namespace qevercloud
