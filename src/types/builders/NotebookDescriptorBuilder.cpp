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

#include <qevercloud/types/builders/NotebookDescriptorBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookDescriptorBuilder::Impl final:
    public QSharedData
{
public:
    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<Guid> m_guid;
    std::optional<QString> m_notebookDisplayName;
    std::optional<QString> m_contactName;
    std::optional<bool> m_hasSharedNotebook;
    std::optional<qint32> m_joinedUserCount;
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

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

NotebookDescriptorBuilder & NotebookDescriptorBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
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

NotebookDescriptor NotebookDescriptorBuilder::build()
{
    NotebookDescriptor result;

    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setGuid(std::move(d->m_guid));
    result.setNotebookDisplayName(std::move(d->m_notebookDisplayName));
    result.setContactName(std::move(d->m_contactName));
    result.setHasSharedNotebook(std::move(d->m_hasSharedNotebook));
    result.setJoinedUserCount(std::move(d->m_joinedUserCount));

    d->m_localId = QString{};
    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_guid = {};
    d->m_notebookDisplayName = {};
    d->m_contactName = {};
    d->m_hasSharedNotebook = {};
    d->m_joinedUserCount = {};

    return result;
}

} // namespace qevercloud
