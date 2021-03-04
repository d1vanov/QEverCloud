/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "ManageNotebookSharesParametersImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void ManageNotebookSharesParameters::Impl::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesParameters: {\n";

    if (m_notebookGuid) {
        strm << "    notebookGuid = "
            << *m_notebookGuid << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (m_inviteMessage) {
        strm << "    inviteMessage = "
            << *m_inviteMessage << "\n";
    }
    else {
        strm << "    inviteMessage is not set\n";
    }

    if (m_membershipsToUpdate) {
        strm << "    membershipsToUpdate = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: *m_membershipsToUpdate) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUpdate is not set\n";
    }

    if (m_invitationsToCreateOrUpdate) {
        strm << "    invitationsToCreateOrUpdate = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: *m_invitationsToCreateOrUpdate) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToCreateOrUpdate is not set\n";
    }

    if (m_unshares) {
        strm << "    unshares = "
            << "QList<UserIdentity> {";
        for(const auto & v: *m_unshares) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    unshares is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
