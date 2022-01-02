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

#include <qevercloud/types/builders/LinkedNotebookBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN LinkedNotebookBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_shareName;
    std::optional<QString> m_username;
    std::optional<QString> m_shardId;
    std::optional<QString> m_sharedNotebookGlobalId;
    std::optional<QString> m_uri;
    std::optional<Guid> m_guid;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<QString> m_stack;
    std::optional<qint32> m_businessId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
};

LinkedNotebookBuilder::LinkedNotebookBuilder() :
    d(new LinkedNotebookBuilder::Impl)
{}

LinkedNotebookBuilder::LinkedNotebookBuilder(LinkedNotebookBuilder && other) noexcept :
    d{std::move(other.d)}
{}

LinkedNotebookBuilder::~LinkedNotebookBuilder() noexcept = default;

LinkedNotebookBuilder & LinkedNotebookBuilder::operator=(LinkedNotebookBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setShareName(std::optional<QString> shareName)
{
    d->m_shareName = std::move(shareName);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setShardId(std::optional<QString> shardId)
{
    d->m_shardId = std::move(shardId);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setSharedNotebookGlobalId(std::optional<QString> sharedNotebookGlobalId)
{
    d->m_sharedNotebookGlobalId = std::move(sharedNotebookGlobalId);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setUri(std::optional<QString> uri)
{
    d->m_uri = std::move(uri);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setNoteStoreUrl(std::optional<QString> noteStoreUrl)
{
    d->m_noteStoreUrl = std::move(noteStoreUrl);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix)
{
    d->m_webApiUrlPrefix = std::move(webApiUrlPrefix);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setStack(std::optional<QString> stack)
{
    d->m_stack = std::move(stack);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = std::move(businessId);
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

LinkedNotebookBuilder & LinkedNotebookBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

LinkedNotebookBuilder &LinkedNotebookBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

LinkedNotebook LinkedNotebookBuilder::build()
{
    LinkedNotebook result;

    result.setShareName(std::move(d->m_shareName));
    result.setUsername(std::move(d->m_username));
    result.setShardId(std::move(d->m_shardId));
    result.setSharedNotebookGlobalId(std::move(d->m_sharedNotebookGlobalId));
    result.setUri(std::move(d->m_uri));
    result.setGuid(std::move(d->m_guid));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setNoteStoreUrl(std::move(d->m_noteStoreUrl));
    result.setWebApiUrlPrefix(std::move(d->m_webApiUrlPrefix));
    result.setStack(std::move(d->m_stack));
    result.setBusinessId(std::move(d->m_businessId));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));

    d->m_shareName = {};
    d->m_username = {};
    d->m_shardId = {};
    d->m_sharedNotebookGlobalId = {};
    d->m_uri = {};
    d->m_guid = {};
    d->m_updateSequenceNum = {};
    d->m_noteStoreUrl = {};
    d->m_webApiUrlPrefix = {};
    d->m_stack = {};
    d->m_businessId = {};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};

    return result;
}

} // namespace qevercloud
