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

#include <qevercloud/generated/types/RelatedQuery.h>

#include "impl/RelatedQueryImpl.h"

namespace qevercloud {

RelatedQuery::RelatedQuery() :
    d(new RelatedQuery::Impl)
 {}

RelatedQuery::RelatedQuery(const RelatedQuery & other) :
    d(other.d)
{}

RelatedQuery::RelatedQuery(RelatedQuery && other) noexcept :
    d(std::move(other.d))
{}

RelatedQuery::~RelatedQuery() noexcept {}

RelatedQuery & RelatedQuery::operator=(const RelatedQuery & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

RelatedQuery & RelatedQuery::operator=(RelatedQuery && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & RelatedQuery::noteGuid() const noexcept
{
    return d->m_noteGuid;
}

void RelatedQuery::setNoteGuid(std::optional<QString> noteGuid)
{
    d->m_noteGuid = noteGuid;
}

const std::optional<QString> & RelatedQuery::plainText() const noexcept
{
    return d->m_plainText;
}

void RelatedQuery::setPlainText(std::optional<QString> plainText)
{
    d->m_plainText = plainText;
}

const std::optional<NoteFilter> & RelatedQuery::filter() const noexcept
{
    return d->m_filter;
}

std::optional<NoteFilter> & RelatedQuery::mutableFilter()
{
    return d->m_filter;
}

void RelatedQuery::setFilter(std::optional<NoteFilter> filter)
{
    d->m_filter = filter;
}

const std::optional<QString> & RelatedQuery::referenceUri() const noexcept
{
    return d->m_referenceUri;
}

void RelatedQuery::setReferenceUri(std::optional<QString> referenceUri)
{
    d->m_referenceUri = referenceUri;
}

const std::optional<QString> & RelatedQuery::context() const noexcept
{
    return d->m_context;
}

void RelatedQuery::setContext(std::optional<QString> context)
{
    d->m_context = context;
}

const std::optional<QString> & RelatedQuery::cacheKey() const noexcept
{
    return d->m_cacheKey;
}

void RelatedQuery::setCacheKey(std::optional<QString> cacheKey)
{
    d->m_cacheKey = cacheKey;
}

void RelatedQuery::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const RelatedQuery & lhs, const RelatedQuery & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noteGuid() == rhs.noteGuid() &&
        lhs.plainText() == rhs.plainText() &&
        lhs.filter() == rhs.filter() &&
        lhs.referenceUri() == rhs.referenceUri() &&
        lhs.context() == rhs.context() &&
        lhs.cacheKey() == rhs.cacheKey();
}

bool operator!=(const RelatedQuery & lhs, const RelatedQuery & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
