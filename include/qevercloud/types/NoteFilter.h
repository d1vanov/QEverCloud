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

#ifndef QEVERCLOUD_GENERATED_NOTEFILTER
#define QEVERCLOUD_GENERATED_NOTEFILTER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QByteArray>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A list of criteria that are used to indicate which notes are desired from
 * the account.  This is used in queries to the NoteStore to determine
 * which notes should be retrieved.
 *
 **/
class QEVERCLOUD_EXPORT NoteFilter: public Printable
{
    Q_GADGET
public:
    NoteFilter();
    NoteFilter(const NoteFilter & other);
    NoteFilter(NoteFilter && other) noexcept;
    ~NoteFilter() noexcept override;

    NoteFilter & operator=(const NoteFilter & other);
    NoteFilter & operator=(NoteFilter && other) noexcept;

    /**
     * The NoteSortOrder value indicating what criterion should be
     * used to sort the results of the filter.
     */
    [[nodiscard]] const std::optional<qint32> & order() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableOrder();
    void setOrder(std::optional<qint32> order);

    /**
     * If true, the results will be ascending in the requested
     * sort order. If false, the results will be descending.
     */
    [[nodiscard]] const std::optional<bool> & ascending() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableAscending();
    void setAscending(std::optional<bool> ascending);

    /**
     * If present, a search query string that will filter the set of notes to be returned.
     * Accepts the full search grammar documented in the Evernote API Overview.
     */
    [[nodiscard]] const std::optional<QString> & words() const noexcept;
    void setWords(std::optional<QString> words);

    /**
     * If present, the Guid of the notebook that must contain
     * the notes.
     */
    [[nodiscard]] const std::optional<Guid> & notebookGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNotebookGuid();
    void setNotebookGuid(std::optional<Guid> notebookGuid);

    /**
     * If present, the list of tags (by GUID) that must be present
     * on the notes.
     */
    [[nodiscard]] const std::optional<QList<Guid>> & tagGuids() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableTagGuids();
    void setTagGuids(std::optional<QList<Guid>> tagGuids);

    /**
     * The zone ID for the user, which will be used to interpret
     * any dates or times in the queries that do not include their desired zone
     * information.
     * For example, if a query requests notes created "yesterday", this
     * will be evaluated from the provided time zone, if provided.
     * The format must be encoded as a standard zone ID such as
     * "America/Los_Angeles".
     */
    [[nodiscard]] const std::optional<QString> & timeZone() const noexcept;
    void setTimeZone(std::optional<QString> timeZone);

    /**
     * If true, then only notes that are not active (i.e. notes in
     * the Trash) will be returned. Otherwise, only active notes will be returned.
     * There is no way to find both active and inactive notes in a single query.
     */
    [[nodiscard]] const std::optional<bool> & inactive() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableInactive();
    void setInactive(std::optional<bool> inactive);

    /**
     * If present, a search query string that may or may not influence the notes
     * to be returned, both in terms of coverage as well as of order. Think of it
     * as a wish list, not a requirement.
     * Accepts the full search grammar documented in the Evernote API Overview.
     */
    [[nodiscard]] const std::optional<QString> & emphasized() const noexcept;
    void setEmphasized(std::optional<QString> emphasized);

    /**
     * If true, then the search will include all business notebooks that are readable
     * by the user. A business authentication token must be supplied for
     * this option to take effect when calling search APIs.
     */
    [[nodiscard]] const std::optional<bool> & includeAllReadableNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAllReadableNotebooks();
    void setIncludeAllReadableNotebooks(std::optional<bool> includeAllReadableNotebooks);

    /**
     * If true, then the search will include all workspaces that are readable
     * by the user. A business authentication token must be supplied for
     * this option to take effect when calling search APIs.
     */
    [[nodiscard]] const std::optional<bool> & includeAllReadableWorkspaces() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAllReadableWorkspaces();
    void setIncludeAllReadableWorkspaces(std::optional<bool> includeAllReadableWorkspaces);

    /**
     * Specifies the context to consider when determining result ranking.
     * Clients must leave this value unset unless they wish to explicitly specify a known
     * non-default context.
     */
    [[nodiscard]] const std::optional<QString> & context() const noexcept;
    void setContext(std::optional<QString> context);

    /**
     * If present, the raw user query input.
     * Accepts the full search grammar documented in the Evernote API Overview.
     */
    [[nodiscard]] const std::optional<QString> & rawWords() const noexcept;
    void setRawWords(std::optional<QString> rawWords);

    /**
     * Specifies the correlating information about the current search session, in byte array.
     * If this request is not for the first page of search results, the client should populate
     * this field with the value of searchContextBytes from the NotesMetadataList of the
     * original search response.
     */
    [[nodiscard]] const std::optional<QByteArray> & searchContextBytes() const noexcept;
    void setSearchContextBytes(std::optional<QByteArray> searchContextBytes);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<qint32> order READ order WRITE setOrder)
    Q_PROPERTY(std::optional<bool> ascending READ ascending WRITE setAscending)
    Q_PROPERTY(std::optional<QString> words READ words WRITE setWords)
    Q_PROPERTY(std::optional<Guid> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QList<Guid>> tagGuids READ tagGuids WRITE setTagGuids)
    Q_PROPERTY(std::optional<QString> timeZone READ timeZone WRITE setTimeZone)
    Q_PROPERTY(std::optional<bool> inactive READ inactive WRITE setInactive)
    Q_PROPERTY(std::optional<QString> emphasized READ emphasized WRITE setEmphasized)
    Q_PROPERTY(std::optional<bool> includeAllReadableNotebooks READ includeAllReadableNotebooks WRITE setIncludeAllReadableNotebooks)
    Q_PROPERTY(std::optional<bool> includeAllReadableWorkspaces READ includeAllReadableWorkspaces WRITE setIncludeAllReadableWorkspaces)
    Q_PROPERTY(std::optional<QString> context READ context WRITE setContext)
    Q_PROPERTY(std::optional<QString> rawWords READ rawWords WRITE setRawWords)
    Q_PROPERTY(std::optional<QByteArray> searchContextBytes READ searchContextBytes WRITE setSearchContextBytes)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NoteFilter & lhs, const NoteFilter & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NoteFilter & lhs, const NoteFilter & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteFilter)

#endif // QEVERCLOUD_GENERATED_NOTEFILTER
