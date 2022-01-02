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

#include <qevercloud/types/builders/NotebookDescriptorBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookDescriptorBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<Guid> m_guid;
    std::optional<QString> m_notebookDisplayName;
    std::optional<QString> m_contactName;
    std::optional<bool> m_hasSharedNotebook;
    std::optional<qint32> m_joinedUserCount;
    QString m_localId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
};

NotebookDescriptorBuilder::NotebookDescriptorBuilder() :
    d(new NotebookDescriptorBuilder::Impl)
{}

NotebookDescriptorBuilder::NotebookDescriptorBuilder(NotebookDescriptorBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotebookDescriptorBuilder::~NotebookDescriptorBuilder() noexcept = default;

NotebookDescriptorBuilder & NotebookDescriptorBuilder::operator=(NotebookDescriptorBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setNotebookDisplayName(std::optional<QString> notebookDisplayName)
{
    d->m_notebookDisplayName = std::move(notebookDisplayName);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setContactName(std::optional<QString> contactName)
{
    d->m_contactName = std::move(contactName);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setHasSharedNotebook(std::optional<bool> hasSharedNotebook)
{
    d->m_hasSharedNotebook = std::move(hasSharedNotebook);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setJoinedUserCount(std::optional<qint32> joinedUserCount)
{
    d->m_joinedUserCount = std::move(joinedUserCount);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

NotebookDescriptorBuilder &NotebookDescriptorBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

NotebookDescriptor NotebookDescriptorBuilder::build()
{
    NotebookDescriptor result;

    result.setGuid(std::move(d->m_guid));
    result.setNotebookDisplayName(std::move(d->m_notebookDisplayName));
    result.setContactName(std::move(d->m_contactName));
    result.setHasSharedNotebook(std::move(d->m_hasSharedNotebook));
    result.setJoinedUserCount(std::move(d->m_joinedUserCount));
    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));

    d->m_guid = {};
    d->m_notebookDisplayName = {};
    d->m_contactName = {};
    d->m_hasSharedNotebook = {};
    d->m_joinedUserCount = {};
    d->m_localId = QString{};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};

    return result;
}

} // namespace qevercloud
