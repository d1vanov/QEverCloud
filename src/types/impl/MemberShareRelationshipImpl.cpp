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

#include "MemberShareRelationshipImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void MemberShareRelationship::Impl::print(QTextStream & strm) const
{
    strm << "MemberShareRelationship: {\n";

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

    if (m_bestPrivilege) {
        strm << "    bestPrivilege = "
            << *m_bestPrivilege << "\n";
    }
    else {
        strm << "    bestPrivilege is not set\n";
    }

    if (m_individualPrivilege) {
        strm << "    individualPrivilege = "
            << *m_individualPrivilege << "\n";
    }
    else {
        strm << "    individualPrivilege is not set\n";
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