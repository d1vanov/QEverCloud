/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "NoteEmailParametersImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

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
