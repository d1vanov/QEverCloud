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

#include "NotebookShareTemplateData.h"

#include <QTextStream>

namespace qevercloud {

bool NotebookShareTemplate::NotebookShareTemplateData::operator==(
    const NotebookShareTemplateData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_notebookGuid == other.m_notebookGuid &&
        m_recipientThreadId == other.m_recipientThreadId &&
        m_recipientContacts == other.m_recipientContacts &&
        m_privilege == other.m_privilege;
}

bool NotebookShareTemplate::NotebookShareTemplateData::operator!=(
    const NotebookShareTemplateData & other) const noexcept
{
    return !(*this == other);
}

void NotebookShareTemplate::NotebookShareTemplateData::print(QTextStream & strm) const
{
    strm << "NotebookShareTemplate: {\n";

    if (m_notebookGuid) {
        strm << "    notebookGuid = "
            << *m_notebookGuid << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (m_recipientThreadId) {
        strm << "    recipientThreadId = "
            << *m_recipientThreadId << "\n";
    }
    else {
        strm << "    recipientThreadId is not set\n";
    }

    if (m_recipientContacts) {
        strm << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: *m_recipientContacts) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    recipientContacts is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
