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

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENTBUILDER
#define QEVERCLOUD_GENERATED_RELATEDCONTENTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/RelatedContent.h>
#include <qevercloud/types/RelatedContentImage.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT RelatedContentBuilder
{
public:
    RelatedContentBuilder();

    RelatedContentBuilder(RelatedContentBuilder && other) noexcept;

    ~RelatedContentBuilder() noexcept;

    RelatedContentBuilder & operator=(RelatedContentBuilder && other) noexcept;

    RelatedContentBuilder & setContentId(std::optional<QString> contentId);
    RelatedContentBuilder & setTitle(std::optional<QString> title);
    RelatedContentBuilder & setUrl(std::optional<QString> url);
    RelatedContentBuilder & setSourceId(std::optional<QString> sourceId);
    RelatedContentBuilder & setSourceUrl(std::optional<QString> sourceUrl);
    RelatedContentBuilder & setSourceFaviconUrl(std::optional<QString> sourceFaviconUrl);
    RelatedContentBuilder & setSourceName(std::optional<QString> sourceName);
    RelatedContentBuilder & setDate(std::optional<Timestamp> date);
    RelatedContentBuilder & setTeaser(std::optional<QString> teaser);
    RelatedContentBuilder & setThumbnails(std::optional<QList<RelatedContentImage>> thumbnails);
    RelatedContentBuilder & setContentType(std::optional<RelatedContentType> contentType);
    RelatedContentBuilder & setAccessType(std::optional<RelatedContentAccess> accessType);
    RelatedContentBuilder & setVisibleUrl(std::optional<QString> visibleUrl);
    RelatedContentBuilder & setClipUrl(std::optional<QString> clipUrl);
    RelatedContentBuilder & setContact(std::optional<Contact> contact);
    RelatedContentBuilder & setAuthors(std::optional<QStringList> authors);

    [[nodiscard]] RelatedContent build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENTBUILDER
