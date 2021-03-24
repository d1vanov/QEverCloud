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

#include <qevercloud/types/RelatedResult.h>

#include "impl/RelatedResultImpl.h"

namespace qevercloud {

RelatedResult::RelatedResult() :
    d(new RelatedResult::Impl)
 {}

RelatedResult::RelatedResult(const RelatedResult & other) :
    d(other.d)
{}

RelatedResult::RelatedResult(RelatedResult && other) noexcept :
    d(std::move(other.d))
{}

RelatedResult::~RelatedResult() noexcept {}

RelatedResult & RelatedResult::operator=(const RelatedResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

RelatedResult & RelatedResult::operator=(RelatedResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QList<Note>> & RelatedResult::notes() const noexcept
{
    return d->m_notes;
}

std::optional<QList<Note>> & RelatedResult::mutableNotes()
{
    return d->m_notes;
}

void RelatedResult::setNotes(std::optional<QList<Note>> notes)
{
    d->m_notes = notes;
}

const std::optional<QList<Notebook>> & RelatedResult::notebooks() const noexcept
{
    return d->m_notebooks;
}

std::optional<QList<Notebook>> & RelatedResult::mutableNotebooks()
{
    return d->m_notebooks;
}

void RelatedResult::setNotebooks(std::optional<QList<Notebook>> notebooks)
{
    d->m_notebooks = notebooks;
}

const std::optional<QList<Tag>> & RelatedResult::tags() const noexcept
{
    return d->m_tags;
}

std::optional<QList<Tag>> & RelatedResult::mutableTags()
{
    return d->m_tags;
}

void RelatedResult::setTags(std::optional<QList<Tag>> tags)
{
    d->m_tags = tags;
}

const std::optional<QList<NotebookDescriptor>> & RelatedResult::containingNotebooks() const noexcept
{
    return d->m_containingNotebooks;
}

std::optional<QList<NotebookDescriptor>> & RelatedResult::mutableContainingNotebooks()
{
    return d->m_containingNotebooks;
}

void RelatedResult::setContainingNotebooks(std::optional<QList<NotebookDescriptor>> containingNotebooks)
{
    d->m_containingNotebooks = containingNotebooks;
}

const std::optional<QString> & RelatedResult::debugInfo() const noexcept
{
    return d->m_debugInfo;
}

void RelatedResult::setDebugInfo(std::optional<QString> debugInfo)
{
    d->m_debugInfo = debugInfo;
}

const std::optional<QList<UserProfile>> & RelatedResult::experts() const noexcept
{
    return d->m_experts;
}

std::optional<QList<UserProfile>> & RelatedResult::mutableExperts()
{
    return d->m_experts;
}

void RelatedResult::setExperts(std::optional<QList<UserProfile>> experts)
{
    d->m_experts = experts;
}

const std::optional<QList<RelatedContent>> & RelatedResult::relatedContent() const noexcept
{
    return d->m_relatedContent;
}

std::optional<QList<RelatedContent>> & RelatedResult::mutableRelatedContent()
{
    return d->m_relatedContent;
}

void RelatedResult::setRelatedContent(std::optional<QList<RelatedContent>> relatedContent)
{
    d->m_relatedContent = relatedContent;
}

const std::optional<QString> & RelatedResult::cacheKey() const noexcept
{
    return d->m_cacheKey;
}

void RelatedResult::setCacheKey(std::optional<QString> cacheKey)
{
    d->m_cacheKey = cacheKey;
}

const std::optional<qint32> & RelatedResult::cacheExpires() const noexcept
{
    return d->m_cacheExpires;
}

std::optional<qint32> & RelatedResult::mutableCacheExpires()
{
    return d->m_cacheExpires;
}

void RelatedResult::setCacheExpires(std::optional<qint32> cacheExpires)
{
    d->m_cacheExpires = cacheExpires;
}

void RelatedResult::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const RelatedResult & lhs, const RelatedResult & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.notes() == rhs.notes() &&
        lhs.notebooks() == rhs.notebooks() &&
        lhs.tags() == rhs.tags() &&
        lhs.containingNotebooks() == rhs.containingNotebooks() &&
        lhs.debugInfo() == rhs.debugInfo() &&
        lhs.experts() == rhs.experts() &&
        lhs.relatedContent() == rhs.relatedContent() &&
        lhs.cacheKey() == rhs.cacheKey() &&
        lhs.cacheExpires() == rhs.cacheExpires();
}

bool operator!=(const RelatedResult & lhs, const RelatedResult & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
