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

#include <qevercloud/types/builders/SharedNoteTemplateBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNoteTemplateBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<Guid> m_noteGuid;
    std::optional<MessageThreadID> m_recipientThreadId;
    std::optional<QList<Contact>> m_recipientContacts;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
};

SharedNoteTemplateBuilder::SharedNoteTemplateBuilder() :
    d(new SharedNoteTemplateBuilder::Impl)
{}

SharedNoteTemplateBuilder::SharedNoteTemplateBuilder(SharedNoteTemplateBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SharedNoteTemplateBuilder::~SharedNoteTemplateBuilder() noexcept = default;

SharedNoteTemplateBuilder & SharedNoteTemplateBuilder::operator=(SharedNoteTemplateBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SharedNoteTemplateBuilder & SharedNoteTemplateBuilder::setNoteGuid(std::optional<Guid> noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
    return *this;
}

SharedNoteTemplateBuilder & SharedNoteTemplateBuilder::setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId)
{
    d->m_recipientThreadId = std::move(recipientThreadId);
    return *this;
}

SharedNoteTemplateBuilder & SharedNoteTemplateBuilder::setRecipientContacts(std::optional<QList<Contact>> recipientContacts)
{
    d->m_recipientContacts = std::move(recipientContacts);
    return *this;
}

SharedNoteTemplateBuilder & SharedNoteTemplateBuilder::setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

SharedNoteTemplate SharedNoteTemplateBuilder::build()
{
    SharedNoteTemplate result;

    result.setNoteGuid(std::move(d->m_noteGuid));
    result.setRecipientThreadId(std::move(d->m_recipientThreadId));
    result.setRecipientContacts(std::move(d->m_recipientContacts));
    result.setPrivilege(std::move(d->m_privilege));

    d->m_noteGuid = {};
    d->m_recipientThreadId = {};
    d->m_recipientContacts = {};
    d->m_privilege = {};

    return result;
}

} // namespace qevercloud
