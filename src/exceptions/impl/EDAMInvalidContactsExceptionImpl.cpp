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

#include "EDAMInvalidContactsExceptionImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void EDAMInvalidContactsException::Impl::print(QTextStream & strm) const
{
    strm << "EDAMInvalidContactsException: {\n";
    strm << "    contacts = "
        << "QList<Contact> {";
    for(const auto & v: m_contacts) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";

    if (m_parameter) {
        strm << "    parameter = "
            << *m_parameter << "\n";
    }
    else {
        strm << "    parameter is not set\n";
    }

    if (m_reasons) {
        strm << "    reasons = "
            << "QList<EDAMInvalidContactReason> {";
        for(const auto & v: *m_reasons) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    reasons is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
