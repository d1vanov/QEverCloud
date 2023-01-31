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

#include <qevercloud/types/builders/NotebookShareTemplateBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookShareTemplateBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<Guid> m_notebookGuid;
    std::optional<MessageThreadID> m_recipientThreadId;
    std::optional<QList<Contact>> m_recipientContacts;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
};

NotebookShareTemplateBuilder::NotebookShareTemplateBuilder() :
    d(new NotebookShareTemplateBuilder::Impl)
{}

NotebookShareTemplateBuilder::NotebookShareTemplateBuilder(NotebookShareTemplateBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotebookShareTemplateBuilder::~NotebookShareTemplateBuilder() noexcept = default;

NotebookShareTemplateBuilder & NotebookShareTemplateBuilder::operator=(NotebookShareTemplateBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotebookShareTemplateBuilder & NotebookShareTemplateBuilder::setNotebookGuid(std::optional<Guid> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

NotebookShareTemplateBuilder & NotebookShareTemplateBuilder::setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId)
{
    d->m_recipientThreadId = std::move(recipientThreadId);
    return *this;
}

NotebookShareTemplateBuilder & NotebookShareTemplateBuilder::setRecipientContacts(std::optional<QList<Contact>> recipientContacts)
{
    d->m_recipientContacts = std::move(recipientContacts);
    return *this;
}

NotebookShareTemplateBuilder & NotebookShareTemplateBuilder::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

NotebookShareTemplate NotebookShareTemplateBuilder::build()
{
    NotebookShareTemplate result;

    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setRecipientThreadId(std::move(d->m_recipientThreadId));
    result.setRecipientContacts(std::move(d->m_recipientContacts));
    result.setPrivilege(std::move(d->m_privilege));

    d->m_notebookGuid = {};
    d->m_recipientThreadId = {};
    d->m_recipientContacts = {};
    d->m_privilege = {};

    return result;
}

} // namespace qevercloud
