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

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENTIMPL_H
#define QEVERCLOUD_GENERATED_RELATEDCONTENTIMPL_H

#include <qevercloud/generated/types/RelatedContent.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedContent::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const RelatedContent::Impl & other) = default;
    Impl(RelatedContent::Impl && other) noexcept = default;

    RelatedContent::Impl & operator=(const RelatedContent::Impl & other) = delete;
    RelatedContent::Impl & operator=(RelatedContent::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENTIMPL_H
