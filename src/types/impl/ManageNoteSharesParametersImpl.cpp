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

#include "ManageNoteSharesParametersImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void ManageNoteSharesParameters::Impl::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesParameters: {\n";

    if (m_noteGuid) {
        strm << "    noteGuid = "
            << *m_noteGuid << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (m_membershipsToUpdate) {
        strm << "    membershipsToUpdate = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: *m_membershipsToUpdate) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUpdate is not set\n";
    }

    if (m_invitationsToUpdate) {
        strm << "    invitationsToUpdate = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: *m_invitationsToUpdate) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToUpdate is not set\n";
    }

    if (m_membershipsToUnshare) {
        strm << "    membershipsToUnshare = "
            << "QList<UserID> {";
        for(const auto & v: *m_membershipsToUnshare) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUnshare is not set\n";
    }

    if (m_invitationsToUnshare) {
        strm << "    invitationsToUnshare = "
            << "QList<IdentityID> {";
        for(const auto & v: *m_invitationsToUnshare) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToUnshare is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
