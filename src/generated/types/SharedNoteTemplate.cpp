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

#include <qevercloud/generated/types/SharedNoteTemplate.h>

#include "impl/SharedNoteTemplateImpl.h"

namespace qevercloud {

SharedNoteTemplate::SharedNoteTemplate() :
    d(new SharedNoteTemplate::Impl)
 {}

SharedNoteTemplate::SharedNoteTemplate(const SharedNoteTemplate & other) :
    d(other.d)
{}

SharedNoteTemplate::SharedNoteTemplate(SharedNoteTemplate && other) noexcept :
    d(std::move(other.d))
{}

SharedNoteTemplate::~SharedNoteTemplate() noexcept {}

SharedNoteTemplate & SharedNoteTemplate::operator=(const SharedNoteTemplate & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SharedNoteTemplate & SharedNoteTemplate::operator=(SharedNoteTemplate && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<Guid> & SharedNoteTemplate::noteGuid() const noexcept
{
    return d->m_noteGuid;
}

std::optional<Guid> & SharedNoteTemplate::mutableNoteGuid()
{
    return d->m_noteGuid;
}

void SharedNoteTemplate::setNoteGuid(std::optional<Guid> noteGuid)
{
    d->m_noteGuid = noteGuid;
}

const std::optional<MessageThreadID> & SharedNoteTemplate::recipientThreadId() const noexcept
{
    return d->m_recipientThreadId;
}

std::optional<MessageThreadID> & SharedNoteTemplate::mutableRecipientThreadId()
{
    return d->m_recipientThreadId;
}

void SharedNoteTemplate::setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId)
{
    d->m_recipientThreadId = recipientThreadId;
}

const std::optional<QList<Contact>> & SharedNoteTemplate::recipientContacts() const noexcept
{
    return d->m_recipientContacts;
}

std::optional<QList<Contact>> & SharedNoteTemplate::mutableRecipientContacts()
{
    return d->m_recipientContacts;
}

void SharedNoteTemplate::setRecipientContacts(std::optional<QList<Contact>> recipientContacts)
{
    d->m_recipientContacts = recipientContacts;
}

const std::optional<SharedNotePrivilegeLevel> & SharedNoteTemplate::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotePrivilegeLevel> & SharedNoteTemplate::mutablePrivilege()
{
    return d->m_privilege;
}

void SharedNoteTemplate::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

void SharedNoteTemplate::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const SharedNoteTemplate & lhs, const SharedNoteTemplate & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noteGuid() == rhs.noteGuid() &&
        lhs.recipientThreadId() == rhs.recipientThreadId() &&
        lhs.recipientContacts() == rhs.recipientContacts() &&
        lhs.privilege() == rhs.privilege();
}

bool operator!=(const SharedNoteTemplate & lhs, const SharedNoteTemplate & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
