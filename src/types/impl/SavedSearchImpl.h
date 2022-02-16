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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHIMPL
#define QEVERCLOUD_GENERATED_SAVEDSEARCHIMPL

#include <qevercloud/types/SavedSearch.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearch::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl();
    Impl(const SavedSearch::Impl & other) = default;
    Impl(SavedSearch::Impl && other) noexcept = default;

    SavedSearch::Impl & operator=(const SavedSearch::Impl & other) = delete;
    SavedSearch::Impl & operator=(SavedSearch::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<QString> m_query;
    std::optional<QueryFormat> m_format;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<SavedSearchScope> m_scope;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHIMPL