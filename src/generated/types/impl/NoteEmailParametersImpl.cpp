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

#include "NoteEmailParametersImpl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteEmailParameters::Impl::operator==(
    const NoteEmailParameters::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_guid == other.m_guid &&
        m_note == other.m_note &&
        m_toAddresses == other.m_toAddresses &&
        m_ccAddresses == other.m_ccAddresses &&
        m_subject == other.m_subject &&
        m_message == other.m_message;
}

bool NoteEmailParameters::Impl::operator!=(
    const NoteEmailParameters::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteEmailParameters::Impl::print(QTextStream & strm) const
{
    strm << "NoteEmailParameters: {\n";

    if (m_guid) {
        strm << "    guid = "
            << *m_guid << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (m_note) {
        strm << "    note = "
            << *m_note << "\n";
    }
    else {
        strm << "    note is not set\n";
    }

    if (m_toAddresses) {
        strm << "    toAddresses = "
            << "QList<QString> {";
        for(const auto & v: *m_toAddresses) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    toAddresses is not set\n";
    }

    if (m_ccAddresses) {
        strm << "    ccAddresses = "
            << "QList<QString> {";
        for(const auto & v: *m_ccAddresses) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    ccAddresses is not set\n";
    }

    if (m_subject) {
        strm << "    subject = "
            << *m_subject << "\n";
    }
    else {
        strm << "    subject is not set\n";
    }

    if (m_message) {
        strm << "    message = "
            << *m_message << "\n";
    }
    else {
        strm << "    message is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
