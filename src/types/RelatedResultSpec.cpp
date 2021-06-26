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

#include <qevercloud/types/RelatedResultSpec.h>

#include "impl/RelatedResultSpecImpl.h"

namespace qevercloud {

RelatedResultSpec::RelatedResultSpec() :
    d(new RelatedResultSpec::Impl)
 {}

RelatedResultSpec::RelatedResultSpec(const RelatedResultSpec & other) :
    d(other.d)
{}

RelatedResultSpec::RelatedResultSpec(RelatedResultSpec && other) noexcept :
    d(std::move(other.d))
{}

RelatedResultSpec::~RelatedResultSpec() noexcept {}

RelatedResultSpec & RelatedResultSpec::operator=(const RelatedResultSpec & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

RelatedResultSpec & RelatedResultSpec::operator=(RelatedResultSpec && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & RelatedResultSpec::maxNotes() const noexcept
{
    return d->m_maxNotes;
}

std::optional<qint32> & RelatedResultSpec::mutableMaxNotes()
{
    return d->m_maxNotes;
}

void RelatedResultSpec::setMaxNotes(std::optional<qint32> maxNotes)
{
    d->m_maxNotes = maxNotes;
}

const std::optional<qint32> & RelatedResultSpec::maxNotebooks() const noexcept
{
    return d->m_maxNotebooks;
}

std::optional<qint32> & RelatedResultSpec::mutableMaxNotebooks()
{
    return d->m_maxNotebooks;
}

void RelatedResultSpec::setMaxNotebooks(std::optional<qint32> maxNotebooks)
{
    d->m_maxNotebooks = maxNotebooks;
}

const std::optional<qint32> & RelatedResultSpec::maxTags() const noexcept
{
    return d->m_maxTags;
}

std::optional<qint32> & RelatedResultSpec::mutableMaxTags()
{
    return d->m_maxTags;
}

void RelatedResultSpec::setMaxTags(std::optional<qint32> maxTags)
{
    d->m_maxTags = maxTags;
}

const std::optional<bool> & RelatedResultSpec::writableNotebooksOnly() const noexcept
{
    return d->m_writableNotebooksOnly;
}

std::optional<bool> & RelatedResultSpec::mutableWritableNotebooksOnly()
{
    return d->m_writableNotebooksOnly;
}

void RelatedResultSpec::setWritableNotebooksOnly(std::optional<bool> writableNotebooksOnly)
{
    d->m_writableNotebooksOnly = writableNotebooksOnly;
}

const std::optional<bool> & RelatedResultSpec::includeContainingNotebooks() const noexcept
{
    return d->m_includeContainingNotebooks;
}

std::optional<bool> & RelatedResultSpec::mutableIncludeContainingNotebooks()
{
    return d->m_includeContainingNotebooks;
}

void RelatedResultSpec::setIncludeContainingNotebooks(std::optional<bool> includeContainingNotebooks)
{
    d->m_includeContainingNotebooks = includeContainingNotebooks;
}

const std::optional<bool> & RelatedResultSpec::includeDebugInfo() const noexcept
{
    return d->m_includeDebugInfo;
}

std::optional<bool> & RelatedResultSpec::mutableIncludeDebugInfo()
{
    return d->m_includeDebugInfo;
}

void RelatedResultSpec::setIncludeDebugInfo(std::optional<bool> includeDebugInfo)
{
    d->m_includeDebugInfo = includeDebugInfo;
}

const std::optional<qint32> & RelatedResultSpec::maxExperts() const noexcept
{
    return d->m_maxExperts;
}

std::optional<qint32> & RelatedResultSpec::mutableMaxExperts()
{
    return d->m_maxExperts;
}

void RelatedResultSpec::setMaxExperts(std::optional<qint32> maxExperts)
{
    d->m_maxExperts = maxExperts;
}

const std::optional<qint32> & RelatedResultSpec::maxRelatedContent() const noexcept
{
    return d->m_maxRelatedContent;
}

std::optional<qint32> & RelatedResultSpec::mutableMaxRelatedContent()
{
    return d->m_maxRelatedContent;
}

void RelatedResultSpec::setMaxRelatedContent(std::optional<qint32> maxRelatedContent)
{
    d->m_maxRelatedContent = maxRelatedContent;
}

const std::optional<QSet<RelatedContentType>> & RelatedResultSpec::relatedContentTypes() const noexcept
{
    return d->m_relatedContentTypes;
}

std::optional<QSet<RelatedContentType>> & RelatedResultSpec::mutableRelatedContentTypes()
{
    return d->m_relatedContentTypes;
}

void RelatedResultSpec::setRelatedContentTypes(std::optional<QSet<RelatedContentType>> relatedContentTypes)
{
    d->m_relatedContentTypes = relatedContentTypes;
}

void RelatedResultSpec::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const RelatedResultSpec & relatedResultSpec)
{
    strm << static_cast<const Printable&>(relatedResultSpec);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const RelatedResultSpec & relatedResultSpec)
{
    dbg << static_cast<const Printable&>(relatedResultSpec);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const RelatedResultSpec & relatedResultSpec)
{
    strm << static_cast<const Printable&>(relatedResultSpec);
    return strm;
}

bool operator==(const RelatedResultSpec & lhs, const RelatedResultSpec & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.maxNotes() == rhs.maxNotes() &&
        lhs.maxNotebooks() == rhs.maxNotebooks() &&
        lhs.maxTags() == rhs.maxTags() &&
        lhs.writableNotebooksOnly() == rhs.writableNotebooksOnly() &&
        lhs.includeContainingNotebooks() == rhs.includeContainingNotebooks() &&
        lhs.includeDebugInfo() == rhs.includeDebugInfo() &&
        lhs.maxExperts() == rhs.maxExperts() &&
        lhs.maxRelatedContent() == rhs.maxRelatedContent() &&
        lhs.relatedContentTypes() == rhs.relatedContentTypes();
}

bool operator!=(const RelatedResultSpec & lhs, const RelatedResultSpec & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
