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

#include <qevercloud/types/builders/NotesMetadataResultSpecBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotesMetadataResultSpecBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_includeTitle;
    std::optional<bool> m_includeContentLength;
    std::optional<bool> m_includeCreated;
    std::optional<bool> m_includeUpdated;
    std::optional<bool> m_includeDeleted;
    std::optional<bool> m_includeUpdateSequenceNum;
    std::optional<bool> m_includeNotebookGuid;
    std::optional<bool> m_includeTagGuids;
    std::optional<bool> m_includeAttributes;
    std::optional<bool> m_includeLargestResourceMime;
    std::optional<bool> m_includeLargestResourceSize;
};

NotesMetadataResultSpecBuilder::NotesMetadataResultSpecBuilder() :
    d(new NotesMetadataResultSpecBuilder::Impl)
{}

NotesMetadataResultSpecBuilder::NotesMetadataResultSpecBuilder(NotesMetadataResultSpecBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotesMetadataResultSpecBuilder::~NotesMetadataResultSpecBuilder() noexcept = default;

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::operator=(NotesMetadataResultSpecBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeTitle(std::optional<bool> includeTitle)
{
    d->m_includeTitle = std::move(includeTitle);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeContentLength(std::optional<bool> includeContentLength)
{
    d->m_includeContentLength = std::move(includeContentLength);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeCreated(std::optional<bool> includeCreated)
{
    d->m_includeCreated = std::move(includeCreated);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeUpdated(std::optional<bool> includeUpdated)
{
    d->m_includeUpdated = std::move(includeUpdated);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeDeleted(std::optional<bool> includeDeleted)
{
    d->m_includeDeleted = std::move(includeDeleted);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeUpdateSequenceNum(std::optional<bool> includeUpdateSequenceNum)
{
    d->m_includeUpdateSequenceNum = std::move(includeUpdateSequenceNum);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeNotebookGuid(std::optional<bool> includeNotebookGuid)
{
    d->m_includeNotebookGuid = std::move(includeNotebookGuid);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeTagGuids(std::optional<bool> includeTagGuids)
{
    d->m_includeTagGuids = std::move(includeTagGuids);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeAttributes(std::optional<bool> includeAttributes)
{
    d->m_includeAttributes = std::move(includeAttributes);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeLargestResourceMime(std::optional<bool> includeLargestResourceMime)
{
    d->m_includeLargestResourceMime = std::move(includeLargestResourceMime);
    return *this;
}

NotesMetadataResultSpecBuilder & NotesMetadataResultSpecBuilder::setIncludeLargestResourceSize(std::optional<bool> includeLargestResourceSize)
{
    d->m_includeLargestResourceSize = std::move(includeLargestResourceSize);
    return *this;
}

NotesMetadataResultSpec NotesMetadataResultSpecBuilder::build()
{
    NotesMetadataResultSpec result;

    result.setIncludeTitle(std::move(d->m_includeTitle));
    result.setIncludeContentLength(std::move(d->m_includeContentLength));
    result.setIncludeCreated(std::move(d->m_includeCreated));
    result.setIncludeUpdated(std::move(d->m_includeUpdated));
    result.setIncludeDeleted(std::move(d->m_includeDeleted));
    result.setIncludeUpdateSequenceNum(std::move(d->m_includeUpdateSequenceNum));
    result.setIncludeNotebookGuid(std::move(d->m_includeNotebookGuid));
    result.setIncludeTagGuids(std::move(d->m_includeTagGuids));
    result.setIncludeAttributes(std::move(d->m_includeAttributes));
    result.setIncludeLargestResourceMime(std::move(d->m_includeLargestResourceMime));
    result.setIncludeLargestResourceSize(std::move(d->m_includeLargestResourceSize));

    d->m_includeTitle = {};
    d->m_includeContentLength = {};
    d->m_includeCreated = {};
    d->m_includeUpdated = {};
    d->m_includeDeleted = {};
    d->m_includeUpdateSequenceNum = {};
    d->m_includeNotebookGuid = {};
    d->m_includeTagGuids = {};
    d->m_includeAttributes = {};
    d->m_includeLargestResourceMime = {};
    d->m_includeLargestResourceSize = {};

    return result;
}

} // namespace qevercloud
