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

#include <qevercloud/types/builders/RelatedContentBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedContentBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_contentId;
    std::optional<QString> m_title;
    std::optional<QString> m_url;
    std::optional<QString> m_sourceId;
    std::optional<QString> m_sourceUrl;
    std::optional<QString> m_sourceFaviconUrl;
    std::optional<QString> m_sourceName;
    std::optional<Timestamp> m_date;
    std::optional<QString> m_teaser;
    std::optional<QList<RelatedContentImage>> m_thumbnails;
    std::optional<RelatedContentType> m_contentType;
    std::optional<RelatedContentAccess> m_accessType;
    std::optional<QString> m_visibleUrl;
    std::optional<QString> m_clipUrl;
    std::optional<Contact> m_contact;
    std::optional<QStringList> m_authors;
};

RelatedContentBuilder::RelatedContentBuilder() :
    d(new RelatedContentBuilder::Impl)
{}

RelatedContentBuilder::RelatedContentBuilder(RelatedContentBuilder && other) noexcept :
    d{std::move(other.d)}
{}

RelatedContentBuilder::~RelatedContentBuilder() noexcept = default;

RelatedContentBuilder & RelatedContentBuilder::operator=(RelatedContentBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setContentId(std::optional<QString> contentId)
{
    d->m_contentId = std::move(contentId);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setTitle(std::optional<QString> title)
{
    d->m_title = std::move(title);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setUrl(std::optional<QString> url)
{
    d->m_url = std::move(url);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setSourceId(std::optional<QString> sourceId)
{
    d->m_sourceId = std::move(sourceId);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setSourceUrl(std::optional<QString> sourceUrl)
{
    d->m_sourceUrl = std::move(sourceUrl);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setSourceFaviconUrl(std::optional<QString> sourceFaviconUrl)
{
    d->m_sourceFaviconUrl = std::move(sourceFaviconUrl);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setSourceName(std::optional<QString> sourceName)
{
    d->m_sourceName = std::move(sourceName);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setDate(std::optional<Timestamp> date)
{
    d->m_date = std::move(date);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setTeaser(std::optional<QString> teaser)
{
    d->m_teaser = std::move(teaser);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setThumbnails(std::optional<QList<RelatedContentImage>> thumbnails)
{
    d->m_thumbnails = std::move(thumbnails);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setContentType(std::optional<RelatedContentType> contentType)
{
    d->m_contentType = std::move(contentType);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setAccessType(std::optional<RelatedContentAccess> accessType)
{
    d->m_accessType = std::move(accessType);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setVisibleUrl(std::optional<QString> visibleUrl)
{
    d->m_visibleUrl = std::move(visibleUrl);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setClipUrl(std::optional<QString> clipUrl)
{
    d->m_clipUrl = std::move(clipUrl);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setContact(std::optional<Contact> contact)
{
    d->m_contact = std::move(contact);
    return *this;
}

RelatedContentBuilder & RelatedContentBuilder::setAuthors(std::optional<QStringList> authors)
{
    d->m_authors = std::move(authors);
    return *this;
}

RelatedContent RelatedContentBuilder::build()
{
    RelatedContent result;

    result.setContentId(std::move(d->m_contentId));
    result.setTitle(std::move(d->m_title));
    result.setUrl(std::move(d->m_url));
    result.setSourceId(std::move(d->m_sourceId));
    result.setSourceUrl(std::move(d->m_sourceUrl));
    result.setSourceFaviconUrl(std::move(d->m_sourceFaviconUrl));
    result.setSourceName(std::move(d->m_sourceName));
    result.setDate(std::move(d->m_date));
    result.setTeaser(std::move(d->m_teaser));
    result.setThumbnails(std::move(d->m_thumbnails));
    result.setContentType(std::move(d->m_contentType));
    result.setAccessType(std::move(d->m_accessType));
    result.setVisibleUrl(std::move(d->m_visibleUrl));
    result.setClipUrl(std::move(d->m_clipUrl));
    result.setContact(std::move(d->m_contact));
    result.setAuthors(std::move(d->m_authors));

    d->m_contentId = {};
    d->m_title = {};
    d->m_url = {};
    d->m_sourceId = {};
    d->m_sourceUrl = {};
    d->m_sourceFaviconUrl = {};
    d->m_sourceName = {};
    d->m_date = {};
    d->m_teaser = {};
    d->m_thumbnails = {};
    d->m_contentType = {};
    d->m_accessType = {};
    d->m_visibleUrl = {};
    d->m_clipUrl = {};
    d->m_contact = {};
    d->m_authors = {};

    return result;
}

} // namespace qevercloud
