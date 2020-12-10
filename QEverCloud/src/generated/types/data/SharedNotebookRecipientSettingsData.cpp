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

#include "SharedNotebookRecipientSettingsData.h"

#include <QTextStream>

namespace qevercloud {

bool SharedNotebookRecipientSettings::SharedNotebookRecipientSettingsData::operator==(
    const SharedNotebookRecipientSettingsData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_reminderNotifyEmail == other.m_reminderNotifyEmail &&
        m_reminderNotifyInApp == other.m_reminderNotifyInApp;
}

bool SharedNotebookRecipientSettings::SharedNotebookRecipientSettingsData::operator!=(
    const SharedNotebookRecipientSettingsData & other) const noexcept
{
    return !(*this == other);
}

void SharedNotebookRecipientSettings::SharedNotebookRecipientSettingsData::print(QTextStream & strm) const
{
    strm << "SharedNotebookRecipientSettings: {\n";

    if (m_reminderNotifyEmail) {
        strm << "    reminderNotifyEmail = "
            << *m_reminderNotifyEmail << "\n";
    }
    else {
        strm << "    reminderNotifyEmail is not set\n";
    }

    if (m_reminderNotifyInApp) {
        strm << "    reminderNotifyInApp = "
            << *m_reminderNotifyInApp << "\n";
    }
    else {
        strm << "    reminderNotifyInApp is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
