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

#include "NoteMemberShareRelationshipImpl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteMemberShareRelationship::Impl::operator==(
    const NoteMemberShareRelationship::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_displayName == other.m_displayName &&
        m_recipientUserId == other.m_recipientUserId &&
        m_privilege == other.m_privilege &&
        m_restrictions == other.m_restrictions &&
        m_sharerUserId == other.m_sharerUserId;
}

bool NoteMemberShareRelationship::Impl::operator!=(
    const NoteMemberShareRelationship::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteMemberShareRelationship::Impl::print(QTextStream & strm) const
{
    strm << "NoteMemberShareRelationship: {\n";

    if (m_displayName) {
        strm << "    displayName = "
            << *m_displayName << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (m_recipientUserId) {
        strm << "    recipientUserId = "
            << *m_recipientUserId << "\n";
    }
    else {
        strm << "    recipientUserId is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (m_restrictions) {
        strm << "    restrictions = "
            << *m_restrictions << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (m_sharerUserId) {
        strm << "    sharerUserId = "
            << *m_sharerUserId << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
