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

#include <qevercloud/types/builders/SharedNotebookBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebookBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint64> m_id;
    std::optional<UserID> m_userId;
    std::optional<Guid> m_notebookGuid;
    std::optional<QString> m_email;
    std::optional<IdentityID> m_recipientIdentityId;
    std::optional<bool> m_notebookModifiable;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<QString> m_globalId;
    std::optional<QString> m_username;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
    std::optional<SharedNotebookRecipientSettings> m_recipientSettings;
    std::optional<UserID> m_sharerUserId;
    std::optional<QString> m_recipientUsername;
    std::optional<UserID> m_recipientUserId;
    std::optional<Timestamp> m_serviceAssigned;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
};

SharedNotebookBuilder::SharedNotebookBuilder() :
    d(new SharedNotebookBuilder::Impl)
{}

SharedNotebookBuilder::SharedNotebookBuilder(SharedNotebookBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SharedNotebookBuilder::~SharedNotebookBuilder() noexcept = default;

SharedNotebookBuilder & SharedNotebookBuilder::operator=(SharedNotebookBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setId(std::optional<qint64> id)
{
    d->m_id = std::move(id);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setUserId(std::optional<UserID> userId)
{
    d->m_userId = std::move(userId);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId)
{
    d->m_recipientIdentityId = std::move(recipientIdentityId);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setNotebookModifiable(std::optional<bool> notebookModifiable)
{
    d->m_notebookModifiable = std::move(notebookModifiable);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = std::move(serviceCreated);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = std::move(serviceUpdated);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setGlobalId(std::optional<QString> globalId)
{
    d->m_globalId = std::move(globalId);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setRecipientSettings(std::optional<SharedNotebookRecipientSettings> recipientSettings)
{
    d->m_recipientSettings = std::move(recipientSettings);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = std::move(sharerUserId);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setRecipientUsername(std::optional<QString> recipientUsername)
{
    d->m_recipientUsername = std::move(recipientUsername);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = std::move(recipientUserId);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setServiceAssigned(std::optional<Timestamp> serviceAssigned)
{
    d->m_serviceAssigned = std::move(serviceAssigned);
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

SharedNotebookBuilder & SharedNotebookBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

SharedNotebookBuilder &SharedNotebookBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

SharedNotebook SharedNotebookBuilder::build()
{
    SharedNotebook result;

    result.setId(std::move(d->m_id));
    result.setUserId(std::move(d->m_userId));
    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setEmail(std::move(d->m_email));
    result.setRecipientIdentityId(std::move(d->m_recipientIdentityId));
    result.setNotebookModifiable(std::move(d->m_notebookModifiable));
    result.setServiceCreated(std::move(d->m_serviceCreated));
    result.setServiceUpdated(std::move(d->m_serviceUpdated));
    result.setGlobalId(std::move(d->m_globalId));
    result.setUsername(std::move(d->m_username));
    result.setPrivilege(std::move(d->m_privilege));
    result.setRecipientSettings(std::move(d->m_recipientSettings));
    result.setSharerUserId(std::move(d->m_sharerUserId));
    result.setRecipientUsername(std::move(d->m_recipientUsername));
    result.setRecipientUserId(std::move(d->m_recipientUserId));
    result.setServiceAssigned(std::move(d->m_serviceAssigned));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));

    d->m_id = {};
    d->m_userId = {};
    d->m_notebookGuid = {};
    d->m_email = {};
    d->m_recipientIdentityId = {};
    d->m_notebookModifiable = {};
    d->m_serviceCreated = {};
    d->m_serviceUpdated = {};
    d->m_globalId = {};
    d->m_username = {};
    d->m_privilege = {};
    d->m_recipientSettings = {};
    d->m_sharerUserId = {};
    d->m_recipientUsername = {};
    d->m_recipientUserId = {};
    d->m_serviceAssigned = {};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};

    return result;
}

} // namespace qevercloud
