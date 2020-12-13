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

#include "NotebookRecipientSettingsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NotebookRecipientSettings::Impl::operator==(
    const NotebookRecipientSettings::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_reminderNotifyEmail == other.m_reminderNotifyEmail &&
        m_reminderNotifyInApp == other.m_reminderNotifyInApp &&
        m_inMyList == other.m_inMyList &&
        m_stack == other.m_stack &&
        m_recipientStatus == other.m_recipientStatus;
}

bool NotebookRecipientSettings::Impl::operator!=(
    const NotebookRecipientSettings::Impl & other) const noexcept
{
    return !(*this == other);
}

void NotebookRecipientSettings::Impl::print(QTextStream & strm) const
{
    strm << "NotebookRecipientSettings: {\n";

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

    if (m_inMyList) {
        strm << "    inMyList = "
            << *m_inMyList << "\n";
    }
    else {
        strm << "    inMyList is not set\n";
    }

    if (m_stack) {
        strm << "    stack = "
            << *m_stack << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (m_recipientStatus) {
        strm << "    recipientStatus = "
            << *m_recipientStatus << "\n";
    }
    else {
        strm << "    recipientStatus is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
