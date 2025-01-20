/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTSPEC
#define QEVERCLOUD_GENERATED_RELATEDRESULTSPEC

#include <qevercloud/Export.h>

#include "QSet"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A description of the thing for which the service will find related
 * entities, via findRelated(), together with a description of what
 * type of entities and how many you are seeking in the
 * RelatedResult.
 *
 * */
class QEVERCLOUD_EXPORT RelatedResultSpec: public Printable
{
    Q_GADGET
public:
    RelatedResultSpec();
    RelatedResultSpec(const RelatedResultSpec & other);
    RelatedResultSpec(RelatedResultSpec && other) noexcept;
    ~RelatedResultSpec() noexcept override;

    RelatedResultSpec & operator=(const RelatedResultSpec & other);
    RelatedResultSpec & operator=(RelatedResultSpec && other) noexcept;

    /**
     * Return notes that are related to the query, but no more than
     * this many. Any value greater than EDAM_RELATED_MAX_NOTES
     * will be silently capped. If you do not set this field, then
     * no notes will be returned.
     */
    [[nodiscard]] const std::optional<qint32> & maxNotes() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxNotes();
    void setMaxNotes(std::optional<qint32> maxNotes);

    /**
     * Return notebooks that are related to the query, but no more than
     * this many. Any value greater than EDAM_RELATED_MAX_NOTEBOOKS
     * will be silently capped. If you do not set this field, then
     * no notebooks will be returned.
     */
    [[nodiscard]] const std::optional<qint32> & maxNotebooks() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxNotebooks();
    void setMaxNotebooks(std::optional<qint32> maxNotebooks);

    /**
     * Return tags that are related to the query, but no more than
     * this many. Any value greater than EDAM_RELATED_MAX_TAGS
     * will be silently capped. If you do not set this field, then
     * no tags will be returned.
     */
    [[nodiscard]] const std::optional<qint32> & maxTags() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxTags();
    void setMaxTags(std::optional<qint32> maxTags);

    /**
     * Require that all returned related notebooks are writable.
     * The user will be able to create notes in all returned notebooks.
     * However, individual notes returned may still belong to notebooks
     * in which the user lacks the ability to create notes.
     */
    [[nodiscard]] const std::optional<bool> & writableNotebooksOnly() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableWritableNotebooksOnly();
    void setWritableNotebooksOnly(std::optional<bool> writableNotebooksOnly);

    /**
     * If set to <code>true</code>, return the containingNotebooks field
     * in the RelatedResult, which will contain the list of notebooks to
     * to which the returned related notes belong.
     */
    [[nodiscard]] const std::optional<bool> & includeContainingNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeContainingNotebooks();
    void setIncludeContainingNotebooks(std::optional<bool> includeContainingNotebooks);

    /**
     * If set to <code>true</code>, indicate that debug information should
     * be returned in the 'debugInfo' field of RelatedResult. Note that the call may
     * be slower if this flag is set.
     */
    [[nodiscard]] const std::optional<bool> & includeDebugInfo() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeDebugInfo();
    void setIncludeDebugInfo(std::optional<bool> includeDebugInfo);

    /**
     * This can only be used when making a findRelated call against a business.
     * Find users within your business who have knowledge about the specified query.
     * No more than this many users will be returned. Any value greater than
     * EDAM_RELATED_MAX_EXPERTS will be silently capped.
     */
    [[nodiscard]] const std::optional<qint32> & maxExperts() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxExperts();
    void setMaxExperts(std::optional<qint32> maxExperts);

    /**
     * Return snippets of related content that is related to the query, but no more than
     * this many. Any value greater than EDAM_RELATED_MAX_RELATED_CONTENT will be silently
     * capped. If you do not set this field, then no related content will be returned.
     */
    [[nodiscard]] const std::optional<qint32> & maxRelatedContent() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxRelatedContent();
    void setMaxRelatedContent(std::optional<qint32> maxRelatedContent);

    /**
     * Specifies the types of Related Content that should be returned.
     */
    [[nodiscard]] const std::optional<QSet<RelatedContentType>> & relatedContentTypes() const noexcept;
    [[nodiscard]] std::optional<QSet<RelatedContentType>> & mutableRelatedContentTypes();
    void setRelatedContentTypes(std::optional<QSet<RelatedContentType>> relatedContentTypes);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const RelatedResultSpec & relatedResultSpec);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const RelatedResultSpec & relatedResultSpec);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const RelatedResultSpec & relatedResultSpec);

    Q_PROPERTY(std::optional<qint32> maxNotes READ maxNotes WRITE setMaxNotes)
    Q_PROPERTY(std::optional<qint32> maxNotebooks READ maxNotebooks WRITE setMaxNotebooks)
    Q_PROPERTY(std::optional<qint32> maxTags READ maxTags WRITE setMaxTags)
    Q_PROPERTY(std::optional<bool> writableNotebooksOnly READ writableNotebooksOnly WRITE setWritableNotebooksOnly)
    Q_PROPERTY(std::optional<bool> includeContainingNotebooks READ includeContainingNotebooks WRITE setIncludeContainingNotebooks)
    Q_PROPERTY(std::optional<bool> includeDebugInfo READ includeDebugInfo WRITE setIncludeDebugInfo)
    Q_PROPERTY(std::optional<qint32> maxExperts READ maxExperts WRITE setMaxExperts)
    Q_PROPERTY(std::optional<qint32> maxRelatedContent READ maxRelatedContent WRITE setMaxRelatedContent)
    Q_PROPERTY(std::optional<QSet<RelatedContentType>> relatedContentTypes READ relatedContentTypes WRITE setRelatedContentTypes)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const RelatedResultSpec & lhs, const RelatedResultSpec & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const RelatedResultSpec & lhs, const RelatedResultSpec & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTSPEC
