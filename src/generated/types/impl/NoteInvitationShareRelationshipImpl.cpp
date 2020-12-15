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

#include "NoteInvitationShareRelationshipImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteInvitationShareRelationship::Impl::operator==(
    const NoteInvitationShareRelationship::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_displayName == other.m_displayName &&
        m_recipientIdentityId == other.m_recipientIdentityId &&
        m_privilege == other.m_privilege &&
        m_sharerUserId == other.m_sharerUserId;
}

bool NoteInvitationShareRelationship::Impl::operator!=(
    const NoteInvitationShareRelationship::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteInvitationShareRelationship::Impl::print(QTextStream & strm) const
{
    strm << "NoteInvitationShareRelationship: {\n";

    if (m_displayName) {
        strm << "    displayName = "
            << *m_displayName << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (m_recipientIdentityId) {
        strm << "    recipientIdentityId = "
            << *m_recipientIdentityId << "\n";
    }
    else {
        strm << "    recipientIdentityId is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
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