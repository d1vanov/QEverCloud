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

#include "ContactImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void Contact::Impl::print(QTextStream & strm) const
{
    strm << "Contact: {\n";

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_id) {
        strm << "    id = "
            << *m_id << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (m_type) {
        strm << "    type = "
            << *m_type << "\n";
    }
    else {
        strm << "    type is not set\n";
    }

    if (m_photoUrl) {
        strm << "    photoUrl = "
            << *m_photoUrl << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (m_photoLastUpdated) {
        strm << "    photoLastUpdated = "
            << *m_photoLastUpdated << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (m_messagingPermit) {
        strm << "    messagingPermit = "
            << *m_messagingPermit << "\n";
    }
    else {
        strm << "    messagingPermit is not set\n";
    }

    if (m_messagingPermitExpires) {
        strm << "    messagingPermitExpires = "
            << *m_messagingPermitExpires << "\n";
    }
    else {
        strm << "    messagingPermitExpires is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
