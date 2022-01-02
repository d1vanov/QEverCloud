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

#include "UserProfileImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void UserProfile::Impl::print(QTextStream & strm) const
{
    strm << "UserProfile: {\n";

    if (m_id) {
        strm << "    id = "
            << *m_id << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_email) {
        strm << "    email = "
            << *m_email << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (m_username) {
        strm << "    username = "
            << *m_username << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (m_attributes) {
        strm << "    attributes = "
            << *m_attributes << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (m_joined) {
        strm << "    joined = "
            << *m_joined << "\n";
    }
    else {
        strm << "    joined is not set\n";
    }

    if (m_photoLastUpdated) {
        strm << "    photoLastUpdated = "
            << *m_photoLastUpdated << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (m_photoUrl) {
        strm << "    photoUrl = "
            << *m_photoUrl << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
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

    strm << "}\n";
}

} // namespace qevercloud
