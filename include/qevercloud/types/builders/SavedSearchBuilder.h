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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHBUILDER
#define QEVERCLOUD_GENERATED_SAVEDSEARCHBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SavedSearch.h>
#include <qevercloud/types/SavedSearchScope.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SavedSearchBuilder
{
public:
    SavedSearchBuilder();

    SavedSearchBuilder(SavedSearchBuilder && other) noexcept;

    ~SavedSearchBuilder() noexcept;

    SavedSearchBuilder & operator=(SavedSearchBuilder && other) noexcept;

    SavedSearchBuilder & setLocalId(QString localId);
    SavedSearchBuilder & setLocallyModified(bool isLocallyModified);
    SavedSearchBuilder & setLocalOnly(bool isLocalOnly);
    SavedSearchBuilder & setLocallyFavorited(bool isLocallyFavorited);
    SavedSearchBuilder & setLocalData(QHash<QString, QVariant> localData);
    SavedSearchBuilder & setGuid(std::optional<Guid> guid);
    SavedSearchBuilder & setName(std::optional<QString> name);
    SavedSearchBuilder & setQuery(std::optional<QString> query);
    SavedSearchBuilder & setFormat(std::optional<QueryFormat> format);
    SavedSearchBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    SavedSearchBuilder & setScope(std::optional<SavedSearchScope> scope);

    [[nodiscard]] SavedSearch build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHBUILDER
