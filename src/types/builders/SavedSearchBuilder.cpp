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

#include <qevercloud/types/builders/SavedSearchBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearchBuilder::Impl final:
    public QSharedData
{
public:
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

SavedSearchBuilder::SavedSearchBuilder() :
    d(new SavedSearchBuilder::Impl)
{}

SavedSearchBuilder::SavedSearchBuilder(SavedSearchBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SavedSearchBuilder::~SavedSearchBuilder() noexcept = default;

SavedSearchBuilder & SavedSearchBuilder::operator=(SavedSearchBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setQuery(std::optional<QString> query)
{
    d->m_query = std::move(query);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setFormat(std::optional<QueryFormat> format)
{
    d->m_format = std::move(format);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

SavedSearchBuilder & SavedSearchBuilder::setScope(std::optional<SavedSearchScope> scope)
{
    d->m_scope = std::move(scope);
    return *this;
}

SavedSearch SavedSearchBuilder::build()
{
    SavedSearch result;

    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setGuid(std::move(d->m_guid));
    result.setName(std::move(d->m_name));
    result.setQuery(std::move(d->m_query));
    result.setFormat(std::move(d->m_format));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setScope(std::move(d->m_scope));

    d->m_localId = QString{};
    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_guid = {};
    d->m_name = {};
    d->m_query = {};
    d->m_format = {};
    d->m_updateSequenceNum = {};
    d->m_scope = {};

    return result;
}

} // namespace qevercloud
