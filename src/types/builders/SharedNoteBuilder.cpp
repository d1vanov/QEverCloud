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

#include <qevercloud/types/builders/SharedNoteBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNoteBuilder::Impl final:
    public QSharedData
{
public:
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    Guid m_noteGuid;
    std::optional<UserID> m_sharerUserID;
    std::optional<Identity> m_recipientIdentity;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<Timestamp> m_serviceAssigned;
};

SharedNoteBuilder::SharedNoteBuilder() :
    d(new SharedNoteBuilder::Impl)
{}

SharedNoteBuilder::SharedNoteBuilder(SharedNoteBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SharedNoteBuilder::~SharedNoteBuilder() noexcept = default;

SharedNoteBuilder & SharedNoteBuilder::operator=(SharedNoteBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setLocallyModified(bool isLocallyModified)
{
    d->m_isLocallyModified = isLocallyModified;
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setLocalOnly(bool isLocalOnly)
{
    d->m_isLocalOnly = isLocalOnly;
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setLocallyFavorited(bool isLocallyFavorited)
{
    d->m_isLocallyFavorited = isLocallyFavorited;
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setNoteGuid(Guid noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setSharerUserID(std::optional<UserID> sharerUserID)
{
    d->m_sharerUserID = std::move(sharerUserID);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setRecipientIdentity(std::optional<Identity> recipientIdentity)
{
    d->m_recipientIdentity = std::move(recipientIdentity);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = std::move(serviceCreated);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = std::move(serviceUpdated);
    return *this;
}

SharedNoteBuilder & SharedNoteBuilder::setServiceAssigned(std::optional<Timestamp> serviceAssigned)
{
    d->m_serviceAssigned = std::move(serviceAssigned);
    return *this;
}

SharedNote SharedNoteBuilder::build()
{
    SharedNote result;

    result.setLocallyModified(d->m_isLocallyModified);
    result.setLocalOnly(d->m_isLocalOnly);
    result.setLocallyFavorited(d->m_isLocallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setNoteGuid(std::move(d->m_noteGuid));
    result.setSharerUserID(std::move(d->m_sharerUserID));
    result.setRecipientIdentity(std::move(d->m_recipientIdentity));
    result.setPrivilege(std::move(d->m_privilege));
    result.setServiceCreated(std::move(d->m_serviceCreated));
    result.setServiceUpdated(std::move(d->m_serviceUpdated));
    result.setServiceAssigned(std::move(d->m_serviceAssigned));

    d->m_isLocallyModified = false;
    d->m_isLocalOnly = false;
    d->m_isLocallyFavorited = false;
    d->m_localData = {};
    d->m_noteGuid = Guid{};
    d->m_sharerUserID = {};
    d->m_recipientIdentity = {};
    d->m_privilege = {};
    d->m_serviceCreated = {};
    d->m_serviceUpdated = {};
    d->m_serviceAssigned = {};

    return result;
}

} // namespace qevercloud
