/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RELATEDQUERY
#define QEVERCLOUD_GENERATED_RELATEDQUERY

#include <qevercloud/Export.h>

#include "NoteFilter.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A description of the thing for which we are searching for related
 * entities.
 *
 * You must specify either <em>noteGuid</em> or <em>plainText</em>, but
 * not both. <em>filter</em> and <em>referenceUri</em> are optional.
 *
 * */
class QEVERCLOUD_EXPORT RelatedQuery: public Printable
{
    Q_GADGET
public:
    RelatedQuery();
    RelatedQuery(const RelatedQuery & other);
    RelatedQuery(RelatedQuery && other) noexcept;
    ~RelatedQuery() noexcept override;

    RelatedQuery & operator=(const RelatedQuery & other);
    RelatedQuery & operator=(RelatedQuery && other) noexcept;

    /**
     * The GUID of an existing note in your account for which related
     * entities will be found.
     */
    [[nodiscard]] const std::optional<QString> & noteGuid() const noexcept;
    void setNoteGuid(std::optional<QString> noteGuid);

    /**
     * A string of plain text for which to find related entities.
     * You should provide a text block with a number of characters between
     * EDAM_RELATED_PLAINTEXT_LEN_MIN and EDAM_RELATED_PLAINTEXT_LEN_MAX.
     */
    [[nodiscard]] const std::optional<QString> & plainText() const noexcept;
    void setPlainText(std::optional<QString> plainText);

    /**
     * The list of criteria that will constrain the notes being considered
     * related.
     * Please note that some of the parameters may be ignored, such as
     * <em>order</em> and <em>ascending</em>.
     */
    [[nodiscard]] const std::optional<NoteFilter> & filter() const noexcept;
    [[nodiscard]] std::optional<NoteFilter> & mutableFilter();
    void setFilter(std::optional<NoteFilter> filter);

    /**
     * A URI string specifying a reference entity, around which "relatedness"
     * should be based. This can be an URL pointing to a web page, for example.
     */
    [[nodiscard]] const std::optional<QString> & referenceUri() const noexcept;
    void setReferenceUri(std::optional<QString> referenceUri);

    /**
     * Specifies the context to consider when determining related results.
     * Clients must leave this value unset unless they wish to explicitly specify a known
     * non-default context.
     */
    [[nodiscard]] const std::optional<QString> & context() const noexcept;
    void setContext(std::optional<QString> context);

    /**
     * If set and non-empty, this is an indicator for the server whether it is actually
     * necessary to perform a new findRelated call at all. Cache Keys are opaque strings
     * which are returned by the server as part of "RelatedResult" in response
     * to a "NoteStore.findRelated" query. Cache Keys are inherently query specific.
     *
     * If set to an empty string, this indicates that the server should generate a cache
     * key in the response as part of "RelatedResult".
     *
     * If not set, the server will not attempt to generate a cache key at all.
     */
    [[nodiscard]] const std::optional<QString> & cacheKey() const noexcept;
    void setCacheKey(std::optional<QString> cacheKey);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const RelatedQuery & relatedQuery);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const RelatedQuery & relatedQuery);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const RelatedQuery & relatedQuery);

    Q_PROPERTY(std::optional<QString> noteGuid READ noteGuid WRITE setNoteGuid)
    Q_PROPERTY(std::optional<QString> plainText READ plainText WRITE setPlainText)
    Q_PROPERTY(std::optional<NoteFilter> filter READ filter WRITE setFilter)
    Q_PROPERTY(std::optional<QString> referenceUri READ referenceUri WRITE setReferenceUri)
    Q_PROPERTY(std::optional<QString> context READ context WRITE setContext)
    Q_PROPERTY(std::optional<QString> cacheKey READ cacheKey WRITE setCacheKey)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const RelatedQuery & lhs, const RelatedQuery & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const RelatedQuery & lhs, const RelatedQuery & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDQUERY
