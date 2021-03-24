/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/Notebook.h>

#include "impl/NotebookImpl.h"

namespace qevercloud {

Notebook::Notebook() :
    d(new Notebook::Impl)
 {}

Notebook::Notebook(const Notebook & other) :
    d(other.d)
{}

Notebook::Notebook(Notebook && other) noexcept :
    d(std::move(other.d))
{}

Notebook::~Notebook() noexcept {}

Notebook & Notebook::operator=(const Notebook & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Notebook & Notebook::operator=(Notebook && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & Notebook::linkedNotebookGuid() const
{
    return d->m_linkedNotebookGuid;
}

void Notebook::setLinkedNotebookGuid(std::optional<QString> linkedNotebookGuid)
{
    d->m_linkedNotebookGuid = std::move(linkedNotebookGuid);
}

const QString & Notebook::localId() const noexcept
{
    return d->m_localId;
}

void Notebook::setLocalId(QString id)
{
    d->m_localId = std::move(id);
}

bool Notebook::isLocallyModified() const noexcept
{
    return d->m_locallyModified;
}

void Notebook::setLocallyModified(const bool modified)
{
    d->m_locallyModified = modified;
}

bool Notebook::isLocalOnly() const noexcept
{
    return d->m_localOnly;
}

void Notebook::setLocalOnly(const bool localOnly)
{
    d->m_localOnly = localOnly;
}

bool Notebook::isLocallyFavorited() const noexcept
{
    return d->m_locallyFavorited;
}

void Notebook::setLocallyFavorited(const bool favorited)
{
    d->m_locallyFavorited = favorited;
}

const QHash<QString, QVariant> & Notebook::localData() const noexcept
{
    return d->m_localData;
}

QHash<QString, QVariant> & Notebook::mutableLocalData()
{
    return d->m_localData;
}

void Notebook::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
}

const std::optional<Guid> & Notebook::guid() const noexcept
{
    return d->m_guid;
}

std::optional<Guid> & Notebook::mutableGuid()
{
    return d->m_guid;
}

void Notebook::setGuid(std::optional<Guid> guid)
{
    d->m_guid = guid;
}

const std::optional<QString> & Notebook::name() const noexcept
{
    return d->m_name;
}

void Notebook::setName(std::optional<QString> name)
{
    d->m_name = name;
}

const std::optional<qint32> & Notebook::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & Notebook::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void Notebook::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<bool> & Notebook::defaultNotebook() const noexcept
{
    return d->m_defaultNotebook;
}

std::optional<bool> & Notebook::mutableDefaultNotebook()
{
    return d->m_defaultNotebook;
}

void Notebook::setDefaultNotebook(std::optional<bool> defaultNotebook)
{
    d->m_defaultNotebook = defaultNotebook;
}

const std::optional<Timestamp> & Notebook::serviceCreated() const noexcept
{
    return d->m_serviceCreated;
}

std::optional<Timestamp> & Notebook::mutableServiceCreated()
{
    return d->m_serviceCreated;
}

void Notebook::setServiceCreated(std::optional<Timestamp> serviceCreated)
{
    d->m_serviceCreated = serviceCreated;
}

const std::optional<Timestamp> & Notebook::serviceUpdated() const noexcept
{
    return d->m_serviceUpdated;
}

std::optional<Timestamp> & Notebook::mutableServiceUpdated()
{
    return d->m_serviceUpdated;
}

void Notebook::setServiceUpdated(std::optional<Timestamp> serviceUpdated)
{
    d->m_serviceUpdated = serviceUpdated;
}

const std::optional<Publishing> & Notebook::publishing() const noexcept
{
    return d->m_publishing;
}

std::optional<Publishing> & Notebook::mutablePublishing()
{
    return d->m_publishing;
}

void Notebook::setPublishing(std::optional<Publishing> publishing)
{
    d->m_publishing = publishing;
}

const std::optional<bool> & Notebook::published() const noexcept
{
    return d->m_published;
}

std::optional<bool> & Notebook::mutablePublished()
{
    return d->m_published;
}

void Notebook::setPublished(std::optional<bool> published)
{
    d->m_published = published;
}

const std::optional<QString> & Notebook::stack() const noexcept
{
    return d->m_stack;
}

void Notebook::setStack(std::optional<QString> stack)
{
    d->m_stack = stack;
}

const std::optional<QList<qint64>> & Notebook::sharedNotebookIds() const noexcept
{
    return d->m_sharedNotebookIds;
}

std::optional<QList<qint64>> & Notebook::mutableSharedNotebookIds()
{
    return d->m_sharedNotebookIds;
}

void Notebook::setSharedNotebookIds(std::optional<QList<qint64>> sharedNotebookIds)
{
    d->m_sharedNotebookIds = sharedNotebookIds;
}

const std::optional<QList<SharedNotebook>> & Notebook::sharedNotebooks() const noexcept
{
    return d->m_sharedNotebooks;
}

std::optional<QList<SharedNotebook>> & Notebook::mutableSharedNotebooks()
{
    return d->m_sharedNotebooks;
}

void Notebook::setSharedNotebooks(std::optional<QList<SharedNotebook>> sharedNotebooks)
{
    d->m_sharedNotebooks = sharedNotebooks;
}

const std::optional<BusinessNotebook> & Notebook::businessNotebook() const noexcept
{
    return d->m_businessNotebook;
}

std::optional<BusinessNotebook> & Notebook::mutableBusinessNotebook()
{
    return d->m_businessNotebook;
}

void Notebook::setBusinessNotebook(std::optional<BusinessNotebook> businessNotebook)
{
    d->m_businessNotebook = businessNotebook;
}

const std::optional<User> & Notebook::contact() const noexcept
{
    return d->m_contact;
}

std::optional<User> & Notebook::mutableContact()
{
    return d->m_contact;
}

void Notebook::setContact(std::optional<User> contact)
{
    d->m_contact = contact;
}

const std::optional<NotebookRestrictions> & Notebook::restrictions() const noexcept
{
    return d->m_restrictions;
}

std::optional<NotebookRestrictions> & Notebook::mutableRestrictions()
{
    return d->m_restrictions;
}

void Notebook::setRestrictions(std::optional<NotebookRestrictions> restrictions)
{
    d->m_restrictions = restrictions;
}

const std::optional<NotebookRecipientSettings> & Notebook::recipientSettings() const noexcept
{
    return d->m_recipientSettings;
}

std::optional<NotebookRecipientSettings> & Notebook::mutableRecipientSettings()
{
    return d->m_recipientSettings;
}

void Notebook::setRecipientSettings(std::optional<NotebookRecipientSettings> recipientSettings)
{
    d->m_recipientSettings = recipientSettings;
}

void Notebook::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const Notebook & lhs, const Notebook & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.localId() == rhs.localId() &&
        lhs.isLocallyModified() == rhs.isLocallyModified() &&
        lhs.isLocalOnly() == rhs.isLocalOnly() &&
        lhs.isLocallyFavorited() == rhs.isLocallyFavorited() &&
        lhs.linkedNotebookGuid() == rhs.linkedNotebookGuid() &&
        lhs.guid() == rhs.guid() &&
        lhs.name() == rhs.name() &&
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.defaultNotebook() == rhs.defaultNotebook() &&
        lhs.serviceCreated() == rhs.serviceCreated() &&
        lhs.serviceUpdated() == rhs.serviceUpdated() &&
        lhs.publishing() == rhs.publishing() &&
        lhs.published() == rhs.published() &&
        lhs.stack() == rhs.stack() &&
        lhs.sharedNotebookIds() == rhs.sharedNotebookIds() &&
        lhs.sharedNotebooks() == rhs.sharedNotebooks() &&
        lhs.businessNotebook() == rhs.businessNotebook() &&
        lhs.contact() == rhs.contact() &&
        lhs.restrictions() == rhs.restrictions() &&
        lhs.recipientSettings() == rhs.recipientSettings();
}

bool operator!=(const Notebook & lhs, const Notebook & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
