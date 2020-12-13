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

#include <qevercloud/generated/types/RelatedContent.h>

#include "impl/RelatedContentImpl.h"

namespace qevercloud {

RelatedContent::RelatedContent() :
    d(new RelatedContent::Impl)
 {}

RelatedContent::RelatedContent(const RelatedContent & other) :
    d(other.d)
{}

RelatedContent::RelatedContent(RelatedContent && other) noexcept :
    d(std::move(other.d))
{}

RelatedContent::~RelatedContent() noexcept {}

RelatedContent & RelatedContent::operator=(const RelatedContent & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

RelatedContent & RelatedContent::operator=(RelatedContent && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & RelatedContent::contentId() const noexcept
{
    return d->m_contentId;
}

void RelatedContent::setContentId(std::optional<QString> contentId)
{
    d->m_contentId = contentId;
}

const std::optional<QString> & RelatedContent::title() const noexcept
{
    return d->m_title;
}

void RelatedContent::setTitle(std::optional<QString> title)
{
    d->m_title = title;
}

const std::optional<QString> & RelatedContent::url() const noexcept
{
    return d->m_url;
}

void RelatedContent::setUrl(std::optional<QString> url)
{
    d->m_url = url;
}

const std::optional<QString> & RelatedContent::sourceId() const noexcept
{
    return d->m_sourceId;
}

void RelatedContent::setSourceId(std::optional<QString> sourceId)
{
    d->m_sourceId = sourceId;
}

const std::optional<QString> & RelatedContent::sourceUrl() const noexcept
{
    return d->m_sourceUrl;
}

void RelatedContent::setSourceUrl(std::optional<QString> sourceUrl)
{
    d->m_sourceUrl = sourceUrl;
}

const std::optional<QString> & RelatedContent::sourceFaviconUrl() const noexcept
{
    return d->m_sourceFaviconUrl;
}

void RelatedContent::setSourceFaviconUrl(std::optional<QString> sourceFaviconUrl)
{
    d->m_sourceFaviconUrl = sourceFaviconUrl;
}

const std::optional<QString> & RelatedContent::sourceName() const noexcept
{
    return d->m_sourceName;
}

void RelatedContent::setSourceName(std::optional<QString> sourceName)
{
    d->m_sourceName = sourceName;
}

const std::optional<Timestamp> & RelatedContent::date() const noexcept
{
    return d->m_date;
}

std::optional<Timestamp> & RelatedContent::mutableDate()
{
    return d->m_date;
}

void RelatedContent::setDate(std::optional<Timestamp> date)
{
    d->m_date = date;
}

const std::optional<QString> & RelatedContent::teaser() const noexcept
{
    return d->m_teaser;
}

void RelatedContent::setTeaser(std::optional<QString> teaser)
{
    d->m_teaser = teaser;
}

const std::optional<QList<RelatedContentImage>> & RelatedContent::thumbnails() const noexcept
{
    return d->m_thumbnails;
}

std::optional<QList<RelatedContentImage>> & RelatedContent::mutableThumbnails()
{
    return d->m_thumbnails;
}

void RelatedContent::setThumbnails(std::optional<QList<RelatedContentImage>> thumbnails)
{
    d->m_thumbnails = thumbnails;
}

const std::optional<RelatedContentType> & RelatedContent::contentType() const noexcept
{
    return d->m_contentType;
}

std::optional<RelatedContentType> & RelatedContent::mutableContentType()
{
    return d->m_contentType;
}

void RelatedContent::setContentType(std::optional<RelatedContentType> contentType)
{
    d->m_contentType = contentType;
}

const std::optional<RelatedContentAccess> & RelatedContent::accessType() const noexcept
{
    return d->m_accessType;
}

std::optional<RelatedContentAccess> & RelatedContent::mutableAccessType()
{
    return d->m_accessType;
}

void RelatedContent::setAccessType(std::optional<RelatedContentAccess> accessType)
{
    d->m_accessType = accessType;
}

const std::optional<QString> & RelatedContent::visibleUrl() const noexcept
{
    return d->m_visibleUrl;
}

void RelatedContent::setVisibleUrl(std::optional<QString> visibleUrl)
{
    d->m_visibleUrl = visibleUrl;
}

const std::optional<QString> & RelatedContent::clipUrl() const noexcept
{
    return d->m_clipUrl;
}

void RelatedContent::setClipUrl(std::optional<QString> clipUrl)
{
    d->m_clipUrl = clipUrl;
}

const std::optional<Contact> & RelatedContent::contact() const noexcept
{
    return d->m_contact;
}

std::optional<Contact> & RelatedContent::mutableContact()
{
    return d->m_contact;
}

void RelatedContent::setContact(std::optional<Contact> contact)
{
    d->m_contact = contact;
}

const std::optional<QStringList> & RelatedContent::authors() const noexcept
{
    return d->m_authors;
}

std::optional<QStringList> & RelatedContent::mutableAuthors()
{
    return d->m_authors;
}

void RelatedContent::setAuthors(std::optional<QStringList> authors)
{
    d->m_authors = authors;
}

void RelatedContent::print(QTextStream & strm) const
{
    d->print(strm);
}

bool RelatedContent::operator==(const RelatedContent & other) const noexcept
{
    return *d == *other.d;
}

bool RelatedContent::operator!=(const RelatedContent & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
