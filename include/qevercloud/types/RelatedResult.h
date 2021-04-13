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

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULT
#define QEVERCLOUD_GENERATED_RELATEDRESULT

#include <qevercloud/Export.h>

#include "Note.h"
#include "Notebook.h"
#include "NotebookDescriptor.h"
#include "RelatedContent.h"
#include "Tag.h"
#include "UserProfile.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * The result of calling findRelated().  The contents of the notes,
 * notebooks, and tags fields will be in decreasing order of expected
 * relevance.  It is possible that fewer results than requested will be
 * returned even if there are enough distinct entities in the account
 * in cases where the relevance is estimated to be low.
 *
 * */
class QEVERCLOUD_EXPORT RelatedResult: public Printable
{
    Q_GADGET
public:
    RelatedResult();
    RelatedResult(const RelatedResult & other);
    RelatedResult(RelatedResult && other) noexcept;
    ~RelatedResult() noexcept override;

    RelatedResult & operator=(const RelatedResult & other);
    RelatedResult & operator=(RelatedResult && other) noexcept;

    /**
     * If notes have been requested to be included, this will be the
     * list of notes.
     */
    [[nodiscard]] const std::optional<QList<Note>> & notes() const noexcept;
    [[nodiscard]] std::optional<QList<Note>> & mutableNotes();
    void setNotes(std::optional<QList<Note>> notes);

    /**
     * If notebooks have been requested to be included, this will be the
     * list of notebooks.
     */
    [[nodiscard]] const std::optional<QList<Notebook>> & notebooks() const noexcept;
    [[nodiscard]] std::optional<QList<Notebook>> & mutableNotebooks();
    void setNotebooks(std::optional<QList<Notebook>> notebooks);

    /**
     * If tags have been requested to be included, this will be the list
     * of tags.
     */
    [[nodiscard]] const std::optional<QList<Tag>> & tags() const noexcept;
    [[nodiscard]] std::optional<QList<Tag>> & mutableTags();
    void setTags(std::optional<QList<Tag>> tags);

    /**
     * If <code>includeContainingNotebooks</code> is set to <code>true</code>
     * in the RelatedResultSpec, return the list of notebooks to
     * to which the returned related notes belong. The notebooks in this
     * list will occur once per notebook GUID and are represented as
     * NotebookDescriptor objects.
     */
    [[nodiscard]] const std::optional<QList<NotebookDescriptor>> & containingNotebooks() const noexcept;
    [[nodiscard]] std::optional<QList<NotebookDescriptor>> & mutableContainingNotebooks();
    void setContainingNotebooks(std::optional<QList<NotebookDescriptor>> containingNotebooks);

    [[nodiscard]] const std::optional<QString> & debugInfo() const noexcept;
    void setDebugInfo(std::optional<QString> debugInfo);

    /**
     * If experts have been requested to be included, this will return
     * a list of users within your business who have knowledge about the specified query.
     */
    [[nodiscard]] const std::optional<QList<UserProfile>> & experts() const noexcept;
    [[nodiscard]] std::optional<QList<UserProfile>> & mutableExperts();
    void setExperts(std::optional<QList<UserProfile>> experts);

    /**
     * If related content has been requested to be included, this will be the list of
     * related content snippets.
     */
    [[nodiscard]] const std::optional<QList<RelatedContent>> & relatedContent() const noexcept;
    [[nodiscard]] std::optional<QList<RelatedContent>> & mutableRelatedContent();
    void setRelatedContent(std::optional<QList<RelatedContent>> relatedContent);

    /**
     * If set and non-empty, this cache key may be used in subsequent
     * "NoteStore.findRelated" calls (via "RelatedQuery") to re-use previous
     * responses that were cached on the client-side, instead of actually performing
     * another search.
     * 
     * If set to an empty string, this indicates that the server could not determine
     * a specific key for this response, but the client should nevertheless remove
     * any previously cached result for this request.
     * 
     * If unset/null, it is up to the client whether to re-use cached results or to
     * use the server's response.
     * 
     * If set to the exact non-empty cache key that was specified in
     * "RelatedQuery.cacheKey", this indicates that the server decided that cached results
     * could be reused.
     * 
     * Depending on the cache key specified in the query, the "RelatedResult" may only be
     * partially filled. For each set field, the client should replace the corresponding
     * part in the previously cached result with the new partial result.
     * 
     * For example, for a specific query that has both "RelatedResultSpec.maxNotes" and
     * "RelatedResultSpec.maxRelatedContent" set to positive values, the server may decide
     * that the previously requested and cached <em>Related Content</em> are unchanged,
     * but new results for <em>Related Notes</em> are available. The
     * response will have a new cache key and have "RelatedResult.notes" set, but have
     * "RelatedResult.relatedContent" unset (not just empty, but really unset).
     * 
     * In this situation, the client should replace any cached notes with the newly
     * returned "RelatedResult.notes", but it can re-use the previously cached entries for
     * "RelatedResult.relatedContent". List fields that are set, but empty indicate that
     * no results could be found; the cache should be updated correspondingly.
     */
    [[nodiscard]] const std::optional<QString> & cacheKey() const noexcept;
    void setCacheKey(std::optional<QString> cacheKey);

    /**
     * If set, clients should reuse this response for any situations where the same input
     * parameters are applicable for up to this many seconds after receiving this result.
     * 
     * After this time has passed, the client may request a new result from the service,
     * but it should supply the stored cacheKey to the service when checking for an
     * update.
     */
    [[nodiscard]] const std::optional<qint32> & cacheExpires() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableCacheExpires();
    void setCacheExpires(std::optional<qint32> cacheExpires);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<QList<Note>> notes READ notes WRITE setNotes)
    Q_PROPERTY(std::optional<QList<Notebook>> notebooks READ notebooks WRITE setNotebooks)
    Q_PROPERTY(std::optional<QList<Tag>> tags READ tags WRITE setTags)
    Q_PROPERTY(std::optional<QList<NotebookDescriptor>> containingNotebooks READ containingNotebooks WRITE setContainingNotebooks)
    Q_PROPERTY(std::optional<QString> debugInfo READ debugInfo WRITE setDebugInfo)
    Q_PROPERTY(std::optional<QList<UserProfile>> experts READ experts WRITE setExperts)
    Q_PROPERTY(std::optional<QList<RelatedContent>> relatedContent READ relatedContent WRITE setRelatedContent)
    Q_PROPERTY(std::optional<QString> cacheKey READ cacheKey WRITE setCacheKey)
    Q_PROPERTY(std::optional<qint32> cacheExpires READ cacheExpires WRITE setCacheExpires)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const RelatedResult & lhs, const RelatedResult & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const RelatedResult & lhs, const RelatedResult & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::RelatedResult)

#endif // QEVERCLOUD_GENERATED_RELATEDRESULT
