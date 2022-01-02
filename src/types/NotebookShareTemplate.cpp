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

#include <qevercloud/types/NotebookShareTemplate.h>

#include "impl/NotebookShareTemplateImpl.h"

namespace qevercloud {

NotebookShareTemplate::NotebookShareTemplate() :
    d(new NotebookShareTemplate::Impl)
{}

NotebookShareTemplate::NotebookShareTemplate(const NotebookShareTemplate & other) :
    d(other.d)
{}

NotebookShareTemplate::NotebookShareTemplate(NotebookShareTemplate && other) noexcept :
    d(std::move(other.d))
{}

NotebookShareTemplate::~NotebookShareTemplate() noexcept {}

NotebookShareTemplate & NotebookShareTemplate::operator=(const NotebookShareTemplate & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotebookShareTemplate & NotebookShareTemplate::operator=(NotebookShareTemplate && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<Guid> & NotebookShareTemplate::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

std::optional<Guid> & NotebookShareTemplate::mutableNotebookGuid()
{
    return d->m_notebookGuid;
}

void NotebookShareTemplate::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<MessageThreadID> & NotebookShareTemplate::recipientThreadId() const noexcept
{
    return d->m_recipientThreadId;
}

std::optional<MessageThreadID> & NotebookShareTemplate::mutableRecipientThreadId()
{
    return d->m_recipientThreadId;
}

void NotebookShareTemplate::setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId)
{
    d->m_recipientThreadId = recipientThreadId;
}

const std::optional<QList<Contact>> & NotebookShareTemplate::recipientContacts() const noexcept
{
    return d->m_recipientContacts;
}

std::optional<QList<Contact>> & NotebookShareTemplate::mutableRecipientContacts()
{
    return d->m_recipientContacts;
}

void NotebookShareTemplate::setRecipientContacts(std::optional<QList<Contact>> recipientContacts)
{
    d->m_recipientContacts = recipientContacts;
}

const std::optional<SharedNotebookPrivilegeLevel> & NotebookShareTemplate::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotebookPrivilegeLevel> & NotebookShareTemplate::mutablePrivilege()
{
    return d->m_privilege;
}

void NotebookShareTemplate::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

void NotebookShareTemplate::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const NotebookShareTemplate & notebookShareTemplate)
{
    strm << static_cast<const Printable&>(notebookShareTemplate);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NotebookShareTemplate & notebookShareTemplate)
{
    dbg << static_cast<const Printable&>(notebookShareTemplate);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NotebookShareTemplate & notebookShareTemplate)
{
    strm << static_cast<const Printable&>(notebookShareTemplate);
    return strm;
}

bool operator==(const NotebookShareTemplate & lhs, const NotebookShareTemplate & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.notebookGuid() == rhs.notebookGuid() &&
        lhs.recipientThreadId() == rhs.recipientThreadId() &&
        lhs.recipientContacts() == rhs.recipientContacts() &&
        lhs.privilege() == rhs.privilege();
}

bool operator!=(const NotebookShareTemplate & lhs, const NotebookShareTemplate & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
