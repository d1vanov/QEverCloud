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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCH
#define QEVERCLOUD_GENERATED_SAVEDSEARCH

#include <qevercloud/Export.h>

#include "SavedSearchScope.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * A named search associated with the account that can be quickly re-used.
 * */
class QEVERCLOUD_EXPORT SavedSearch: public Printable
{
    Q_GADGET
public:
    SavedSearch();
    SavedSearch(const SavedSearch & other);
    SavedSearch(SavedSearch && other) noexcept;
    ~SavedSearch() noexcept override;

    SavedSearch & operator=(const SavedSearch & other);
    SavedSearch & operator=(SavedSearch && other) noexcept;

    /**
     * @brief localId can be used as a local unique identifier
     * for any data item before it has been synchronized with
     * Evernote and thus before it can be identified using its guid.
     *
     * localId is generated automatically on
     * construction for convenience but can be overridden manually
     */
    [[nodiscard]] const QString & localId() const noexcept;
    void setLocalId(QString localId);

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool isLocallyModified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool isLocalOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool isLocallyFavorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The unique identifier of this search. Will be set by the
     * service, so may be omitted by the client when creating.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
     * The name of the saved search to display in the GUI. The
     * account may only contain one search with a given name (case-insensitive
     * compare). Can't begin or end with a space.
     * Length: EDAM_SAVED_SEARCH_NAME_LEN_MIN - EDAM_SAVED_SEARCH_NAME_LEN_MAX
     * Regex: EDAM_SAVED_SEARCH_NAME_REGEX
     */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
     * A string expressing the search to be performed.
     * Length: EDAM_SAVED_SEARCH_QUERY_LEN_MIN - EDAM_SAVED_SEARCH_QUERY_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & query() const noexcept;
    void setQuery(std::optional<QString> query);

    /**
     * The format of the query string, to determine how to parse
     * and process it.
     */
    [[nodiscard]] const std::optional<QueryFormat> & format() const noexcept;
    [[nodiscard]] std::optional<QueryFormat> & mutableFormat();
    void setFormat(std::optional<QueryFormat> format);

    /**
     * A number identifying the last transaction to
     * modify the state of this object. The USN values are sequential within an
     * account, and can be used to compare the order of modifications within the
     * service.
     */
    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    /**
     * <p>Specifies the set of notes that should be included in the search, if
     * possible.</p>
     * <p>Clients are expected to search as much of the desired scope as possible,
     * with the understanding that a given client may not be able to cover the full
     * specified scope. For example, when executing a search that includes notes in both
     * the owner's account and business notebooks, a mobile client may choose to only
     * search within the user's account because it is not capable of searching both
     * scopes simultaneously. When a search across multiple scopes is not possible,
     * a client may choose which scope to search based on the current application
     * context. If a client cannot search any of the desired scopes, it should refuse
     * to execute the search.</p>
     */
    [[nodiscard]] const std::optional<SavedSearchScope> & scope() const noexcept;
    [[nodiscard]] std::optional<SavedSearchScope> & mutableScope();
    void setScope(std::optional<SavedSearchScope> scope);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SavedSearch & savedSearch);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SavedSearch & savedSearch);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SavedSearch & savedSearch);

    using LocalData = QHash<QString, QVariant>;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(LocalData localData READ localData WRITE setLocalData)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<QString> query READ query WRITE setQuery)
    Q_PROPERTY(std::optional<QueryFormat> format READ format WRITE setFormat)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<SavedSearchScope> scope READ scope WRITE setScope)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SavedSearch & lhs, const SavedSearch & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SavedSearch & lhs, const SavedSearch & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCH