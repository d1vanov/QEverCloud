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

#include <generated/types/NotebookRecipientSettings.h>

#include "data/NotebookRecipientSettingsData.h"

namespace qevercloud {

NotebookRecipientSettings::NotebookRecipientSettings() : d(new NotebookRecipientSettingsData) {}

NotebookRecipientSettings::NotebookRecipientSettings(const NotebookRecipientSettings & other) : d(other.d) {}

NotebookRecipientSettings::NotebookRecipientSettings(NotebookRecipientSettings && other) noexcept : d(std::move(other.d))
{}

NotebookRecipientSettings::~NotebookRecipientSettings() noexcept {}

NotebookRecipientSettings & NotebookRecipientSettings::operator=(const NotebookRecipientSettings & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotebookRecipientSettings & NotebookRecipientSettings::operator=(NotebookRecipientSettings && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NotebookRecipientSettings::reminderNotifyEmail() const noexcept
{
    return d->m_reminderNotifyEmail;
}

std::optional<bool> & NotebookRecipientSettings::mutableReminderNotifyEmail()
{
    return d->m_reminderNotifyEmail;
}

void NotebookRecipientSettings::setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail)
{
    d->m_reminderNotifyEmail = reminderNotifyEmail;
}

const std::optional<bool> & NotebookRecipientSettings::reminderNotifyInApp() const noexcept
{
    return d->m_reminderNotifyInApp;
}

std::optional<bool> & NotebookRecipientSettings::mutableReminderNotifyInApp()
{
    return d->m_reminderNotifyInApp;
}

void NotebookRecipientSettings::setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp)
{
    d->m_reminderNotifyInApp = reminderNotifyInApp;
}

const std::optional<bool> & NotebookRecipientSettings::inMyList() const noexcept
{
    return d->m_inMyList;
}

std::optional<bool> & NotebookRecipientSettings::mutableInMyList()
{
    return d->m_inMyList;
}

void NotebookRecipientSettings::setInMyList(std::optional<bool> inMyList)
{
    d->m_inMyList = inMyList;
}

const std::optional<QString> & NotebookRecipientSettings::stack() const noexcept
{
    return d->m_stack;
}

void NotebookRecipientSettings::setStack(std::optional<QString> stack)
{
    d->m_stack = stack;
}

const std::optional<RecipientStatus> & NotebookRecipientSettings::recipientStatus() const noexcept
{
    return d->m_recipientStatus;
}

std::optional<RecipientStatus> & NotebookRecipientSettings::mutableRecipientStatus()
{
    return d->m_recipientStatus;
}

void NotebookRecipientSettings::setRecipientStatus(std::optional<RecipientStatus> recipientStatus)
{
    d->m_recipientStatus = recipientStatus;
}

void NotebookRecipientSettings::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NotebookRecipientSettings::operator==(const NotebookRecipientSettings & other) const noexcept
{
    return *d == *other.d;
}

bool NotebookRecipientSettings::operator!=(const NotebookRecipientSettings & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
