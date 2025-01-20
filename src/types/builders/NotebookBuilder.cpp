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

#include <qevercloud/types/builders/NotebookBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookBuilder::Impl final:
    public QSharedData
{
public:
    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<Guid> m_linkedNotebookGuid;
    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<bool> m_defaultNotebook;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<Publishing> m_publishing;
    std::optional<bool> m_published;
    std::optional<QString> m_stack;
    std::optional<QList<qint64>> m_sharedNotebookIds;
    std::optional<QList<SharedNotebook>> m_sharedNotebooks;
    std::optional<BusinessNotebook> m_businessNotebook;
    std::optional<User> m_contact;
    std::optional<NotebookRestrictions> m_restrictions;
    std::optional<NotebookRecipientSettings> m_recipientSettings;
};

NotebookBuilder::NotebookBuilder() :
    d(new NotebookBuilder::Impl)
{}

NotebookBuilder::NotebookBuilder(NotebookBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotebookBuilder::~NotebookBuilder() noexcept = default;

NotebookBuilder & NotebookBuilder::operator=(NotebookBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotebookBuilder & NotebookBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

NotebookBuilder & NotebookBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

NotebookBuilder & NotebookBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

NotebookBuilder & NotebookBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

NotebookBuilder & NotebookBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

NotebookBuilder & NotebookBuilder::setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid)
{
    d->m_linkedNotebookGuid = std::move(linkedNotebookGuid);
    return *this;
}

NotebookBuilder & NotebookBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

NotebookBuilder & NotebookBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

NotebookBuilder & NotebookBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

NotebookBuilder & NotebookBuilder::setDefaultNotebook(std::optional<bool> defaultNotebook)
{
    d->m_defaultNotebook = std::move(defaultNotebook);
    return *this;
}

NotebookBuilder & NotebookBuilder::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = std::move(serviceCreated);
    return *this;
}

NotebookBuilder & NotebookBuilder::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = std::move(serviceUpdated);
    return *this;
}

NotebookBuilder & NotebookBuilder::setPublishing(std::optional<Publishing> publishing)
{
    d->m_publishing = std::move(publishing);
    return *this;
}

NotebookBuilder & NotebookBuilder::setPublished(std::optional<bool> published)
{
    d->m_published = std::move(published);
    return *this;
}

NotebookBuilder & NotebookBuilder::setStack(std::optional<QString> stack)
{
    d->m_stack = std::move(stack);
    return *this;
}

NotebookBuilder & NotebookBuilder::setSharedNotebookIds(std::optional<QList<qint64>> sharedNotebookIds)
{
    d->m_sharedNotebookIds = std::move(sharedNotebookIds);
    return *this;
}

NotebookBuilder & NotebookBuilder::setSharedNotebooks(std::optional<QList<SharedNotebook>> sharedNotebooks)
{
    d->m_sharedNotebooks = std::move(sharedNotebooks);
    return *this;
}

NotebookBuilder & NotebookBuilder::setBusinessNotebook(std::optional<BusinessNotebook> businessNotebook)
{
    d->m_businessNotebook = std::move(businessNotebook);
    return *this;
}

NotebookBuilder & NotebookBuilder::setContact(std::optional<User> contact)
{
    d->m_contact = std::move(contact);
    return *this;
}

NotebookBuilder & NotebookBuilder::setRestrictions(std::optional<NotebookRestrictions> restrictions)
{
    d->m_restrictions = std::move(restrictions);
    return *this;
}

NotebookBuilder & NotebookBuilder::setRecipientSettings(std::optional<NotebookRecipientSettings> recipientSettings)
{
    d->m_recipientSettings = std::move(recipientSettings);
    return *this;
}

Notebook NotebookBuilder::build()
{
    Notebook result;

    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setLinkedNotebookGuid(std::move(d->m_linkedNotebookGuid));
    result.setGuid(std::move(d->m_guid));
    result.setName(std::move(d->m_name));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setDefaultNotebook(std::move(d->m_defaultNotebook));
    result.setServiceCreated(std::move(d->m_serviceCreated));
    result.setServiceUpdated(std::move(d->m_serviceUpdated));
    result.setPublishing(std::move(d->m_publishing));
    result.setPublished(std::move(d->m_published));
    result.setStack(std::move(d->m_stack));
    result.setSharedNotebookIds(std::move(d->m_sharedNotebookIds));
    result.setSharedNotebooks(std::move(d->m_sharedNotebooks));
    result.setBusinessNotebook(std::move(d->m_businessNotebook));
    result.setContact(std::move(d->m_contact));
    result.setRestrictions(std::move(d->m_restrictions));
    result.setRecipientSettings(std::move(d->m_recipientSettings));

    d->m_localId = QString{};
    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_linkedNotebookGuid = {};
    d->m_guid = {};
    d->m_name = {};
    d->m_updateSequenceNum = {};
    d->m_defaultNotebook = {};
    d->m_serviceCreated = {};
    d->m_serviceUpdated = {};
    d->m_publishing = {};
    d->m_published = {};
    d->m_stack = {};
    d->m_sharedNotebookIds = {};
    d->m_sharedNotebooks = {};
    d->m_businessNotebook = {};
    d->m_contact = {};
    d->m_restrictions = {};
    d->m_recipientSettings = {};

    return result;
}

} // namespace qevercloud
