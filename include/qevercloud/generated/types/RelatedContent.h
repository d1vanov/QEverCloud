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

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENT_H
#define QEVERCLOUD_GENERATED_RELATEDCONTENT_H

#include <qevercloud/Export.h>

#include "Contact.h"
#include "RelatedContentImage.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure identifying one snippet of related content (some information that is not
 * part of an Evernote account but might still be relevant to the user).
 *
 * */
class QEVERCLOUD_EXPORT RelatedContent: public Printable
{
    Q_GADGET
public:
    RelatedContent();
    RelatedContent(const RelatedContent & other);
    RelatedContent(RelatedContent && other) noexcept;
    ~RelatedContent() noexcept override;

    RelatedContent & operator=(const RelatedContent & other);
    RelatedContent & operator=(RelatedContent && other) noexcept;

    /**
    An identifier that uniquely identifies the content.
    */
    [[nodiscard]] const std::optional<QString> & contentId() const noexcept;
    void setContentId(std::optional<QString> contentId);

    /**
    The main title to show.
    */
    [[nodiscard]] const std::optional<QString> & title() const noexcept;
    void setTitle(std::optional<QString> title);

    /**
    The URL the client can use to retrieve the content.
    */
    [[nodiscard]] const std::optional<QString> & url() const noexcept;
    void setUrl(std::optional<QString> url);

    /**
    An identifier that uniquely identifies the source.
    */
    [[nodiscard]] const std::optional<QString> & sourceId() const noexcept;
    void setSourceId(std::optional<QString> sourceId);

    /**
    A URL the client can access to know more about the source.
    */
    [[nodiscard]] const std::optional<QString> & sourceUrl() const noexcept;
    void setSourceUrl(std::optional<QString> sourceUrl);

    /**
    The favicon URL of the source which the content belongs to.
    */
    [[nodiscard]] const std::optional<QString> & sourceFaviconUrl() const noexcept;
    void setSourceFaviconUrl(std::optional<QString> sourceFaviconUrl);

    /**
    A human-readable name of the source that provided this content.
    */
    [[nodiscard]] const std::optional<QString> & sourceName() const noexcept;
    void setSourceName(std::optional<QString> sourceName);

    /**
    A timestamp telling the user about the recency of the content.
    */
    [[nodiscard]] const std::optional<Timestamp> & date() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableDate();
    void setDate(std::optional<Timestamp> date);

    /**
    A teaser text to show to the user; usually the first few sentences of the content,
         excluding the title.
    */
    [[nodiscard]] const std::optional<QString> & teaser() const noexcept;
    void setTeaser(std::optional<QString> teaser);

    /**
    A list of thumbnails the client can show in the snippet.
    */
    [[nodiscard]] const std::optional<QList<RelatedContentImage>> & thumbnails() const noexcept;
    [[nodiscard]] std::optional<QList<RelatedContentImage>> & mutableThumbnails();
    void setThumbnails(std::optional<QList<RelatedContentImage>> thumbnails);

    /**
    The type of this related content.
    */
    [[nodiscard]] const std::optional<RelatedContentType> & contentType() const noexcept;
    [[nodiscard]] std::optional<RelatedContentType> & mutableContentType();
    void setContentType(std::optional<RelatedContentType> contentType);

    /**
    An indication of how this content can be accessed. This type influences the
         semantics of the <code>url</code> parameter.
    */
    [[nodiscard]] const std::optional<RelatedContentAccess> & accessType() const noexcept;
    [[nodiscard]] std::optional<RelatedContentAccess> & mutableAccessType();
    void setAccessType(std::optional<RelatedContentAccess> accessType);

    /**
    If set, the client should show this URL to the user, instead of the URL that was
         used to retrieve the content. This URL should be used when opening the content
         in an external browser window, or when sharing with another person.
    */
    [[nodiscard]] const std::optional<QString> & visibleUrl() const noexcept;
    void setVisibleUrl(std::optional<QString> visibleUrl);

    /**
    If set, the client should use this URL for clipping purposes, instead of the URL
         that was used to retrieve the content. The clipUrl may directly point to an .enex
         file, for example.
    */
    [[nodiscard]] const std::optional<QString> & clipUrl() const noexcept;
    void setClipUrl(std::optional<QString> clipUrl);

    /**
    If set, the client may use this Contact for messaging purposes. This will typically
         only be set for user profiles.
    */
    [[nodiscard]] const std::optional<Contact> & contact() const noexcept;
    [[nodiscard]] std::optional<Contact> & mutableContact();
    void setContact(std::optional<Contact> contact);

    /**
    For News articles only. A list of names of the article authors, if available.
    */
    [[nodiscard]] const std::optional<QStringList> & authors() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableAuthors();
    void setAuthors(std::optional<QStringList> authors);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const RelatedContent & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedContent & other) const noexcept;

    Q_PROPERTY(std::optional<QString> contentId READ contentId WRITE setContentId)
    Q_PROPERTY(std::optional<QString> title READ title WRITE setTitle)
    Q_PROPERTY(std::optional<QString> url READ url WRITE setUrl)
    Q_PROPERTY(std::optional<QString> sourceId READ sourceId WRITE setSourceId)
    Q_PROPERTY(std::optional<QString> sourceUrl READ sourceUrl WRITE setSourceUrl)
    Q_PROPERTY(std::optional<QString> sourceFaviconUrl READ sourceFaviconUrl WRITE setSourceFaviconUrl)
    Q_PROPERTY(std::optional<QString> sourceName READ sourceName WRITE setSourceName)
    Q_PROPERTY(std::optional<Timestamp> date READ date WRITE setDate)
    Q_PROPERTY(std::optional<QString> teaser READ teaser WRITE setTeaser)
    Q_PROPERTY(std::optional<QList<RelatedContentImage>> thumbnails READ thumbnails WRITE setThumbnails)
    Q_PROPERTY(std::optional<RelatedContentType> contentType READ contentType WRITE setContentType)
    Q_PROPERTY(std::optional<RelatedContentAccess> accessType READ accessType WRITE setAccessType)
    Q_PROPERTY(std::optional<QString> visibleUrl READ visibleUrl WRITE setVisibleUrl)
    Q_PROPERTY(std::optional<QString> clipUrl READ clipUrl WRITE setClipUrl)
    Q_PROPERTY(std::optional<Contact> contact READ contact WRITE setContact)
    Q_PROPERTY(std::optional<QStringList> authors READ authors WRITE setAuthors)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::RelatedContent)

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENT_H
