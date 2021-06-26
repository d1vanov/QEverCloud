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

#include <qevercloud/types/SharedNotebookRecipientSettings.h>

#include "impl/SharedNotebookRecipientSettingsImpl.h"

namespace qevercloud {

SharedNotebookRecipientSettings::SharedNotebookRecipientSettings() :
    d(new SharedNotebookRecipientSettings::Impl)
 {}

SharedNotebookRecipientSettings::SharedNotebookRecipientSettings(const SharedNotebookRecipientSettings & other) :
    d(other.d)
{}

SharedNotebookRecipientSettings::SharedNotebookRecipientSettings(SharedNotebookRecipientSettings && other) noexcept :
    d(std::move(other.d))
{}

SharedNotebookRecipientSettings::~SharedNotebookRecipientSettings() noexcept {}

SharedNotebookRecipientSettings & SharedNotebookRecipientSettings::operator=(const SharedNotebookRecipientSettings & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SharedNotebookRecipientSettings & SharedNotebookRecipientSettings::operator=(SharedNotebookRecipientSettings && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & SharedNotebookRecipientSettings::reminderNotifyEmail() const noexcept
{
    return d->m_reminderNotifyEmail;
}

std::optional<bool> & SharedNotebookRecipientSettings::mutableReminderNotifyEmail()
{
    return d->m_reminderNotifyEmail;
}

void SharedNotebookRecipientSettings::setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail)
{
    d->m_reminderNotifyEmail = reminderNotifyEmail;
}

const std::optional<bool> & SharedNotebookRecipientSettings::reminderNotifyInApp() const noexcept
{
    return d->m_reminderNotifyInApp;
}

std::optional<bool> & SharedNotebookRecipientSettings::mutableReminderNotifyInApp()
{
    return d->m_reminderNotifyInApp;
}

void SharedNotebookRecipientSettings::setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp)
{
    d->m_reminderNotifyInApp = reminderNotifyInApp;
}

void SharedNotebookRecipientSettings::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings)
{
    strm << static_cast<const Printable&>(sharedNotebookRecipientSettings);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings)
{
    dbg << static_cast<const Printable&>(sharedNotebookRecipientSettings);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings)
{
    strm << static_cast<const Printable&>(sharedNotebookRecipientSettings);
    return strm;
}

bool operator==(const SharedNotebookRecipientSettings & lhs, const SharedNotebookRecipientSettings & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.reminderNotifyEmail() == rhs.reminderNotifyEmail() &&
        lhs.reminderNotifyInApp() == rhs.reminderNotifyInApp();
}

bool operator!=(const SharedNotebookRecipientSettings & lhs, const SharedNotebookRecipientSettings & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
