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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHDATA_H
#define QEVERCLOUD_GENERATED_SAVEDSEARCHDATA_H

#include <generated/types/SavedSearch.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearch::SavedSearchData final:
    public QSharedData,
    public Printable
{
public:
    SavedSearchData() = default;
    SavedSearchData(const SavedSearchData & other) = default;
    SavedSearchData(SavedSearchData && other) noexcept = default;

    SavedSearchData & operator=(const SavedSearchData & other) = delete;
    SavedSearchData & operator=(SavedSearchData && other) = delete;

    ~SavedSearchData() noexcept override = default;

    [[nodiscard]] bool operator==(const SavedSearchData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SavedSearchData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<QString> m_query;
    std::optional<QueryFormat> m_format;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<SavedSearchScope> m_scope;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHDATA_H
