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

#include "ShareRelationshipsData.h"

#include <QTextStream>

namespace qevercloud {

bool ShareRelationships::Impl::operator==(
    const ShareRelationships::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_invitations == other.m_invitations &&
        m_memberships == other.m_memberships &&
        m_invitationRestrictions == other.m_invitationRestrictions;
}

bool ShareRelationships::Impl::operator!=(
    const ShareRelationships::Impl & other) const noexcept
{
    return !(*this == other);
}

void ShareRelationships::Data::print(QTextStream & strm) const
{
    strm << "ShareRelationships: {\n";

    if (m_invitations) {
        strm << "    invitations = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: *m_invitations) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitations is not set\n";
    }

    if (m_memberships) {
        strm << "    memberships = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: *m_memberships) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    memberships is not set\n";
    }

    if (m_invitationRestrictions) {
        strm << "    invitationRestrictions = "
            << *m_invitationRestrictions << "\n";
    }
    else {
        strm << "    invitationRestrictions is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
