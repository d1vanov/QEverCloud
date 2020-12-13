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

#include <generated/types/NotesMetadataResultSpec.h>

#include "impl/NotesMetadataResultSpecImpl.h"

namespace qevercloud {

NotesMetadataResultSpec::NotesMetadataResultSpec() :
    d(new NotesMetadataResultSpec::Impl)
 {}

NotesMetadataResultSpec::NotesMetadataResultSpec(const NotesMetadataResultSpec & other) :
    d(other.d)
{}

NotesMetadataResultSpec::NotesMetadataResultSpec(NotesMetadataResultSpec && other) noexcept :
    d(std::move(other.d))
{}

NotesMetadataResultSpec::~NotesMetadataResultSpec() noexcept {}

NotesMetadataResultSpec & NotesMetadataResultSpec::operator=(const NotesMetadataResultSpec & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotesMetadataResultSpec & NotesMetadataResultSpec::operator=(NotesMetadataResultSpec && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NotesMetadataResultSpec::includeTitle() const noexcept
{
    return d->m_includeTitle;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeTitle()
{
    return d->m_includeTitle;
}

void NotesMetadataResultSpec::setIncludeTitle(std::optional<bool> includeTitle)
{
    d->m_includeTitle = includeTitle;
}

const std::optional<bool> & NotesMetadataResultSpec::includeContentLength() const noexcept
{
    return d->m_includeContentLength;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeContentLength()
{
    return d->m_includeContentLength;
}

void NotesMetadataResultSpec::setIncludeContentLength(std::optional<bool> includeContentLength)
{
    d->m_includeContentLength = includeContentLength;
}

const std::optional<bool> & NotesMetadataResultSpec::includeCreated() const noexcept
{
    return d->m_includeCreated;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeCreated()
{
    return d->m_includeCreated;
}

void NotesMetadataResultSpec::setIncludeCreated(std::optional<bool> includeCreated)
{
    d->m_includeCreated = includeCreated;
}

const std::optional<bool> & NotesMetadataResultSpec::includeUpdated() const noexcept
{
    return d->m_includeUpdated;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeUpdated()
{
    return d->m_includeUpdated;
}

void NotesMetadataResultSpec::setIncludeUpdated(std::optional<bool> includeUpdated)
{
    d->m_includeUpdated = includeUpdated;
}

const std::optional<bool> & NotesMetadataResultSpec::includeDeleted() const noexcept
{
    return d->m_includeDeleted;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeDeleted()
{
    return d->m_includeDeleted;
}

void NotesMetadataResultSpec::setIncludeDeleted(std::optional<bool> includeDeleted)
{
    d->m_includeDeleted = includeDeleted;
}

const std::optional<bool> & NotesMetadataResultSpec::includeUpdateSequenceNum() const noexcept
{
    return d->m_includeUpdateSequenceNum;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeUpdateSequenceNum()
{
    return d->m_includeUpdateSequenceNum;
}

void NotesMetadataResultSpec::setIncludeUpdateSequenceNum(std::optional<bool> includeUpdateSequenceNum)
{
    d->m_includeUpdateSequenceNum = includeUpdateSequenceNum;
}

const std::optional<bool> & NotesMetadataResultSpec::includeNotebookGuid() const noexcept
{
    return d->m_includeNotebookGuid;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeNotebookGuid()
{
    return d->m_includeNotebookGuid;
}

void NotesMetadataResultSpec::setIncludeNotebookGuid(std::optional<bool> includeNotebookGuid)
{
    d->m_includeNotebookGuid = includeNotebookGuid;
}

const std::optional<bool> & NotesMetadataResultSpec::includeTagGuids() const noexcept
{
    return d->m_includeTagGuids;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeTagGuids()
{
    return d->m_includeTagGuids;
}

void NotesMetadataResultSpec::setIncludeTagGuids(std::optional<bool> includeTagGuids)
{
    d->m_includeTagGuids = includeTagGuids;
}

const std::optional<bool> & NotesMetadataResultSpec::includeAttributes() const noexcept
{
    return d->m_includeAttributes;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeAttributes()
{
    return d->m_includeAttributes;
}

void NotesMetadataResultSpec::setIncludeAttributes(std::optional<bool> includeAttributes)
{
    d->m_includeAttributes = includeAttributes;
}

const std::optional<bool> & NotesMetadataResultSpec::includeLargestResourceMime() const noexcept
{
    return d->m_includeLargestResourceMime;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeLargestResourceMime()
{
    return d->m_includeLargestResourceMime;
}

void NotesMetadataResultSpec::setIncludeLargestResourceMime(std::optional<bool> includeLargestResourceMime)
{
    d->m_includeLargestResourceMime = includeLargestResourceMime;
}

const std::optional<bool> & NotesMetadataResultSpec::includeLargestResourceSize() const noexcept
{
    return d->m_includeLargestResourceSize;
}

std::optional<bool> & NotesMetadataResultSpec::mutableIncludeLargestResourceSize()
{
    return d->m_includeLargestResourceSize;
}

void NotesMetadataResultSpec::setIncludeLargestResourceSize(std::optional<bool> includeLargestResourceSize)
{
    d->m_includeLargestResourceSize = includeLargestResourceSize;
}

void NotesMetadataResultSpec::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NotesMetadataResultSpec::operator==(const NotesMetadataResultSpec & other) const noexcept
{
    return *d == *other.d;
}

bool NotesMetadataResultSpec::operator!=(const NotesMetadataResultSpec & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
