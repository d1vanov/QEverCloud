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

#include "BusinessInvitationImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool BusinessInvitation::Impl::operator==(
    const BusinessInvitation::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_businessId == other.m_businessId &&
        m_email == other.m_email &&
        m_role == other.m_role &&
        m_status == other.m_status &&
        m_requesterId == other.m_requesterId &&
        m_fromWorkChat == other.m_fromWorkChat &&
        m_created == other.m_created &&
        m_mostRecentReminder == other.m_mostRecentReminder;
}

bool BusinessInvitation::Impl::operator!=(
    const BusinessInvitation::Impl & other) const noexcept
{
    return !(*this == other);
}

void BusinessInvitation::Impl::print(QTextStream & strm) const
{
    strm << "BusinessInvitation: {\n";

    if (m_businessId) {
        strm << "    businessId = "
            << *m_businessId << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (m_email) {
        strm << "    email = "
            << *m_email << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (m_role) {
        strm << "    role = "
            << *m_role << "\n";
    }
    else {
        strm << "    role is not set\n";
    }

    if (m_status) {
        strm << "    status = "
            << *m_status << "\n";
    }
    else {
        strm << "    status is not set\n";
    }

    if (m_requesterId) {
        strm << "    requesterId = "
            << *m_requesterId << "\n";
    }
    else {
        strm << "    requesterId is not set\n";
    }

    if (m_fromWorkChat) {
        strm << "    fromWorkChat = "
            << *m_fromWorkChat << "\n";
    }
    else {
        strm << "    fromWorkChat is not set\n";
    }

    if (m_created) {
        strm << "    created = "
            << *m_created << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (m_mostRecentReminder) {
        strm << "    mostRecentReminder = "
            << *m_mostRecentReminder << "\n";
    }
    else {
        strm << "    mostRecentReminder is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud