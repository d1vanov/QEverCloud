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

#include "SharedNotebookImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

SharedNotebook::Impl::Impl()
{
}

void SharedNotebook::Impl::print(QTextStream & strm) const
{
    strm << "SharedNotebook: {\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";

    if (m_id) {
        strm << "    id = "
            << *m_id << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (m_userId) {
        strm << "    userId = "
            << *m_userId << "\n";
    }
    else {
        strm << "    userId is not set\n";
    }

    if (m_notebookGuid) {
        strm << "    notebookGuid = "
            << *m_notebookGuid << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (m_email) {
        strm << "    email = "
            << *m_email << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (m_recipientIdentityId) {
        strm << "    recipientIdentityId = "
            << *m_recipientIdentityId << "\n";
    }
    else {
        strm << "    recipientIdentityId is not set\n";
    }

    if (m_notebookModifiable) {
        strm << "    notebookModifiable = "
            << *m_notebookModifiable << "\n";
    }
    else {
        strm << "    notebookModifiable is not set\n";
    }

    if (m_serviceCreated) {
        strm << "    serviceCreated = "
            << *m_serviceCreated << "\n";
    }
    else {
        strm << "    serviceCreated is not set\n";
    }

    if (m_serviceUpdated) {
        strm << "    serviceUpdated = "
            << *m_serviceUpdated << "\n";
    }
    else {
        strm << "    serviceUpdated is not set\n";
    }

    if (m_globalId) {
        strm << "    globalId = "
            << *m_globalId << "\n";
    }
    else {
        strm << "    globalId is not set\n";
    }

    if (m_username) {
        strm << "    username = "
            << *m_username << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (m_recipientSettings) {
        strm << "    recipientSettings = "
            << *m_recipientSettings << "\n";
    }
    else {
        strm << "    recipientSettings is not set\n";
    }

    if (m_sharerUserId) {
        strm << "    sharerUserId = "
            << *m_sharerUserId << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    if (m_recipientUsername) {
        strm << "    recipientUsername = "
            << *m_recipientUsername << "\n";
    }
    else {
        strm << "    recipientUsername is not set\n";
    }

    if (m_recipientUserId) {
        strm << "    recipientUserId = "
            << *m_recipientUserId << "\n";
    }
    else {
        strm << "    recipientUserId is not set\n";
    }

    if (m_serviceAssigned) {
        strm << "    serviceAssigned = "
            << *m_serviceAssigned << "\n";
    }
    else {
        strm << "    serviceAssigned is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
