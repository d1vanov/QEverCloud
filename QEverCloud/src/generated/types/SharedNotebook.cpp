/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/types/SharedNotebook.h>

#include "impl/SharedNotebookImpl.h"

namespace qevercloud {

SharedNotebook::SharedNotebook() : d(new SharedNotebook::Impl) {}

SharedNotebook::SharedNotebook(const SharedNotebook & other) : d(other.d) {}

SharedNotebook::SharedNotebook(SharedNotebook && other) noexcept : d(std::move(other.d))
{}

SharedNotebook::~SharedNotebook() noexcept {}

SharedNotebook & SharedNotebook::operator=(const SharedNotebook & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SharedNotebook & SharedNotebook::operator=(SharedNotebook && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint64> & SharedNotebook::id() const noexcept
{
    return d->m_id;
}

std::optional<qint64> & SharedNotebook::mutableId()
{
    return d->m_id;
}

void SharedNotebook::setId(std::optional<qint64> id)
{
    d->m_id = id;
}

const std::optional<UserID> & SharedNotebook::userId() const noexcept
{
    return d->m_userId;
}

std::optional<UserID> & SharedNotebook::mutableUserId()
{
    return d->m_userId;
}

void SharedNotebook::setUserId(std::optional<UserID> userId)
{
    d->m_userId = userId;
}

const std::optional<Guid> & SharedNotebook::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

std::optional<Guid> & SharedNotebook::mutableNotebookGuid()
{
    return d->m_notebookGuid;
}

void SharedNotebook::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<QString> & SharedNotebook::email() const noexcept
{
    return d->m_email;
}

void SharedNotebook::setEmail(std::optional<QString> email)
{
    d->m_email = email;
}

const std::optional<IdentityID> & SharedNotebook::recipientIdentityId() const noexcept
{
    return d->m_recipientIdentityId;
}

std::optional<IdentityID> & SharedNotebook::mutableRecipientIdentityId()
{
    return d->m_recipientIdentityId;
}

void SharedNotebook::setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId)
{
    d->m_recipientIdentityId = recipientIdentityId;
}

const std::optional<bool> & SharedNotebook::notebookModifiable() const noexcept
{
    return d->m_notebookModifiable;
}

std::optional<bool> & SharedNotebook::mutableNotebookModifiable()
{
    return d->m_notebookModifiable;
}

void SharedNotebook::setNotebookModifiable(std::optional<bool> notebookModifiable)
{
    d->m_notebookModifiable = notebookModifiable;
}

const std::optional<Timestamp> & SharedNotebook::serviceCreated() const noexcept
{
    return d->m_serviceCreated;
}

std::optional<Timestamp> & SharedNotebook::mutableServiceCreated()
{
    return d->m_serviceCreated;
}

void SharedNotebook::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = serviceCreated;
}

const std::optional<Timestamp> & SharedNotebook::serviceUpdated() const noexcept
{
    return d->m_serviceUpdated;
}

std::optional<Timestamp> & SharedNotebook::mutableServiceUpdated()
{
    return d->m_serviceUpdated;
}

void SharedNotebook::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = serviceUpdated;
}

const std::optional<QString> & SharedNotebook::globalId() const noexcept
{
    return d->m_globalId;
}

void SharedNotebook::setGlobalId(std::optional<QString> globalId)
{
    d->m_globalId = globalId;
}

const std::optional<QString> & SharedNotebook::username() const noexcept
{
    return d->m_username;
}

void SharedNotebook::setUsername(std::optional<QString> username)
{
    d->m_username = username;
}

const std::optional<SharedNotebookPrivilegeLevel> & SharedNotebook::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotebookPrivilegeLevel> & SharedNotebook::mutablePrivilege()
{
    return d->m_privilege;
}

void SharedNotebook::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<SharedNotebookRecipientSettings> & SharedNotebook::recipientSettings() const noexcept
{
    return d->m_recipientSettings;
}

std::optional<SharedNotebookRecipientSettings> & SharedNotebook::mutableRecipientSettings()
{
    return d->m_recipientSettings;
}

void SharedNotebook::setRecipientSettings(std::optional<SharedNotebookRecipientSettings> recipientSettings)
{
    d->m_recipientSettings = recipientSettings;
}

const std::optional<UserID> & SharedNotebook::sharerUserId() const noexcept
{
    return d->m_sharerUserId;
}

std::optional<UserID> & SharedNotebook::mutableSharerUserId()
{
    return d->m_sharerUserId;
}

void SharedNotebook::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = sharerUserId;
}

const std::optional<QString> & SharedNotebook::recipientUsername() const noexcept
{
    return d->m_recipientUsername;
}

void SharedNotebook::setRecipientUsername(std::optional<QString> recipientUsername)
{
    d->m_recipientUsername = recipientUsername;
}

const std::optional<UserID> & SharedNotebook::recipientUserId() const noexcept
{
    return d->m_recipientUserId;
}

std::optional<UserID> & SharedNotebook::mutableRecipientUserId()
{
    return d->m_recipientUserId;
}

void SharedNotebook::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = recipientUserId;
}

const std::optional<Timestamp> & SharedNotebook::serviceAssigned() const noexcept
{
    return d->m_serviceAssigned;
}

std::optional<Timestamp> & SharedNotebook::mutableServiceAssigned()
{
    return d->m_serviceAssigned;
}

void SharedNotebook::setServiceAssigned(std::optional<Timestamp> serviceAssigned)
{
    d->m_serviceAssigned = serviceAssigned;
}

void SharedNotebook::print(QTextStream & strm) const
{
    d->print(strm);
}

bool SharedNotebook::operator==(const SharedNotebook & other) const noexcept
{
    return *d == *other.d;
}

bool SharedNotebook::operator!=(const SharedNotebook & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
