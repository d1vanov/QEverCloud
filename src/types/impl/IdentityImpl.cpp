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

#include "IdentityImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void Identity::Impl::print(QTextStream & strm) const
{
    strm << "Identity: {\n";
    strm << "    id = "
        << m_id << "\n";

    if (m_contact) {
        strm << "    contact = "
            << *m_contact << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (m_userId) {
        strm << "    userId = "
            << *m_userId << "\n";
    }
    else {
        strm << "    userId is not set\n";
    }

    if (m_deactivated) {
        strm << "    deactivated = "
            << (*m_deactivated ? "true" : "false") << "\n";
    }
    else {
        strm << "    deactivated is not set\n";
    }

    if (m_sameBusiness) {
        strm << "    sameBusiness = "
            << (*m_sameBusiness ? "true" : "false") << "\n";
    }
    else {
        strm << "    sameBusiness is not set\n";
    }

    if (m_blocked) {
        strm << "    blocked = "
            << (*m_blocked ? "true" : "false") << "\n";
    }
    else {
        strm << "    blocked is not set\n";
    }

    if (m_userConnected) {
        strm << "    userConnected = "
            << (*m_userConnected ? "true" : "false") << "\n";
    }
    else {
        strm << "    userConnected is not set\n";
    }

    if (m_eventId) {
        strm << "    eventId = "
            << *m_eventId << "\n";
    }
    else {
        strm << "    eventId is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
