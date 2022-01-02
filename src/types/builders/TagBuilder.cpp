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

#include <qevercloud/types/builders/TagBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN TagBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<Guid> m_parentGuid;
    std::optional<qint32> m_updateSequenceNum;
    QString m_localId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<Guid> m_linkedNotebookGuid;
    QString m_parentTagLocalId;

};

TagBuilder::TagBuilder() :
    d(new TagBuilder::Impl)
{}

TagBuilder::TagBuilder(TagBuilder && other) noexcept :
    d{std::move(other.d)}
{}

TagBuilder::~TagBuilder() noexcept = default;

TagBuilder & TagBuilder::operator=(TagBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

TagBuilder & TagBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

TagBuilder & TagBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

TagBuilder & TagBuilder::setParentGuid(std::optional<Guid> parentGuid)
{
    d->m_parentGuid = std::move(parentGuid);
    return *this;
}

TagBuilder & TagBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

TagBuilder & TagBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

TagBuilder & TagBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

TagBuilder & TagBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

TagBuilder & TagBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

TagBuilder &TagBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

TagBuilder & TagBuilder::setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid)
{
    d->m_linkedNotebookGuid = std::move(linkedNotebookGuid);
    return *this;
}

TagBuilder & TagBuilder::setParentTagLocalId(QString parentTagLocalId)
{
    d->m_parentTagLocalId = std::move(parentTagLocalId);    return *this;

}

Tag TagBuilder::build()
{
    Tag result;

    result.setGuid(std::move(d->m_guid));
    result.setName(std::move(d->m_name));
    result.setParentGuid(std::move(d->m_parentGuid));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setLinkedNotebookGuid(std::move(d->m_linkedNotebookGuid));
    result.setParentTagLocalId(std::move(d->m_parentTagLocalId));

    d->m_guid = {};
    d->m_name = {};
    d->m_parentGuid = {};
    d->m_updateSequenceNum = {};
    d->m_localId = QString{};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};
    d->m_linkedNotebookGuid = Guid{};
    d->m_parentTagLocalId = QString{};

    return result;
}

} // namespace qevercloud
