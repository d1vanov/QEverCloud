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

#include "NoteShareRelationshipsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteShareRelationships::Impl::print(QTextStream & strm) const
{
    strm << "NoteShareRelationships: {\n";

    if (m_invitations) {
        strm << "    invitations = "
            << "QList<NoteInvitationShareRelationship> {";
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
            << "QList<NoteMemberShareRelationship> {";
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
