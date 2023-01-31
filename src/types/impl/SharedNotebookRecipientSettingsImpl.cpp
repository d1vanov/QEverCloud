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

#include "SharedNotebookRecipientSettingsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void SharedNotebookRecipientSettings::Impl::print(QTextStream & strm) const
{
    strm << "SharedNotebookRecipientSettings: {\n";

    if (m_reminderNotifyEmail) {
        strm << "    reminderNotifyEmail = "
            << (*m_reminderNotifyEmail ? "true" : "false") << "\n";
    }
    else {
        strm << "    reminderNotifyEmail is not set\n";
    }

    if (m_reminderNotifyInApp) {
        strm << "    reminderNotifyInApp = "
            << (*m_reminderNotifyInApp ? "true" : "false") << "\n";
    }
    else {
        strm << "    reminderNotifyInApp is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
