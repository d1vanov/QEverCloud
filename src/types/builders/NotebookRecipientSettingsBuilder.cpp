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

#include <qevercloud/types/builders/NotebookRecipientSettingsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookRecipientSettingsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
    std::optional<bool> m_inMyList;
    std::optional<QString> m_stack;
    std::optional<RecipientStatus> m_recipientStatus;
};

NotebookRecipientSettingsBuilder::NotebookRecipientSettingsBuilder() :
    d(new NotebookRecipientSettingsBuilder::Impl)
{}

NotebookRecipientSettingsBuilder::NotebookRecipientSettingsBuilder(NotebookRecipientSettingsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotebookRecipientSettingsBuilder::~NotebookRecipientSettingsBuilder() noexcept = default;

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::operator=(NotebookRecipientSettingsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail)
{
    d->m_reminderNotifyEmail = std::move(reminderNotifyEmail);
    return *this;
}

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp)
{
    d->m_reminderNotifyInApp = std::move(reminderNotifyInApp);
    return *this;
}

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::setInMyList(std::optional<bool> inMyList)
{
    d->m_inMyList = std::move(inMyList);
    return *this;
}

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::setStack(std::optional<QString> stack)
{
    d->m_stack = std::move(stack);
    return *this;
}

NotebookRecipientSettingsBuilder & NotebookRecipientSettingsBuilder::setRecipientStatus(std::optional<RecipientStatus> recipientStatus)
{
    d->m_recipientStatus = std::move(recipientStatus);
    return *this;
}

NotebookRecipientSettings NotebookRecipientSettingsBuilder::build()
{
    NotebookRecipientSettings result;

    result.setReminderNotifyEmail(std::move(d->m_reminderNotifyEmail));
    result.setReminderNotifyInApp(std::move(d->m_reminderNotifyInApp));
    result.setInMyList(std::move(d->m_inMyList));
    result.setStack(std::move(d->m_stack));
    result.setRecipientStatus(std::move(d->m_recipientStatus));

    d->m_reminderNotifyEmail = {};
    d->m_reminderNotifyInApp = {};
    d->m_inMyList = {};
    d->m_stack = {};
    d->m_recipientStatus = {};

    return result;
}

} // namespace qevercloud
