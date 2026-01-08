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

#include <qevercloud/types/builders/SharedNotebookRecipientSettingsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebookRecipientSettingsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
};

SharedNotebookRecipientSettingsBuilder::SharedNotebookRecipientSettingsBuilder() :
    d(new SharedNotebookRecipientSettingsBuilder::Impl)
{}

SharedNotebookRecipientSettingsBuilder::SharedNotebookRecipientSettingsBuilder(SharedNotebookRecipientSettingsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SharedNotebookRecipientSettingsBuilder::~SharedNotebookRecipientSettingsBuilder() noexcept = default;

SharedNotebookRecipientSettingsBuilder & SharedNotebookRecipientSettingsBuilder::operator=(SharedNotebookRecipientSettingsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SharedNotebookRecipientSettingsBuilder & SharedNotebookRecipientSettingsBuilder::setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail)
{
    d->m_reminderNotifyEmail = std::move(reminderNotifyEmail);
    return *this;
}

SharedNotebookRecipientSettingsBuilder & SharedNotebookRecipientSettingsBuilder::setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp)
{
    d->m_reminderNotifyInApp = std::move(reminderNotifyInApp);
    return *this;
}

SharedNotebookRecipientSettings SharedNotebookRecipientSettingsBuilder::build()
{
    SharedNotebookRecipientSettings result;

    result.setReminderNotifyEmail(std::move(d->m_reminderNotifyEmail));
    result.setReminderNotifyInApp(std::move(d->m_reminderNotifyInApp));

    d->m_reminderNotifyEmail = {};
    d->m_reminderNotifyInApp = {};

    return result;
}

} // namespace qevercloud
