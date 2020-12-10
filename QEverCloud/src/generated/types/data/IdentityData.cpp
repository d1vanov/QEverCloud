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

#include "IdentityData.h"

#include <QTextStream>

namespace qevercloud {

bool Identity::IdentityData::operator==(
    const IdentityData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_id == other.m_id &&
        m_contact == other.m_contact &&
        m_userId == other.m_userId &&
        m_deactivated == other.m_deactivated &&
        m_sameBusiness == other.m_sameBusiness &&
        m_blocked == other.m_blocked &&
        m_userConnected == other.m_userConnected &&
        m_eventId == other.m_eventId;
}

bool Identity::IdentityData::operator!=(
    const IdentityData & other) const noexcept
{
    return !(*this == other);
}

void Identity::IdentityData::print(QTextStream & strm) const
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
            << *m_deactivated << "\n";
    }
    else {
        strm << "    deactivated is not set\n";
    }

    if (m_sameBusiness) {
        strm << "    sameBusiness = "
            << *m_sameBusiness << "\n";
    }
    else {
        strm << "    sameBusiness is not set\n";
    }

    if (m_blocked) {
        strm << "    blocked = "
            << *m_blocked << "\n";
    }
    else {
        strm << "    blocked is not set\n";
    }

    if (m_userConnected) {
        strm << "    userConnected = "
            << *m_userConnected << "\n";
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
