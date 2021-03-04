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

#include "UserImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

User::Impl::Impl()
{
}

void User::Impl::print(QTextStream & strm) const
{
    strm << "User: {\n";
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

    if (m_username) {
        strm << "    username = "
            << *m_username << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (m_email) {
        strm << "    email = "
            << *m_email << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_timezone) {
        strm << "    timezone = "
            << *m_timezone << "\n";
    }
    else {
        strm << "    timezone is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (m_serviceLevel) {
        strm << "    serviceLevel = "
            << *m_serviceLevel << "\n";
    }
    else {
        strm << "    serviceLevel is not set\n";
    }

    if (m_created) {
        strm << "    created = "
            << *m_created << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (m_updated) {
        strm << "    updated = "
            << *m_updated << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (m_deleted) {
        strm << "    deleted = "
            << *m_deleted << "\n";
    }
    else {
        strm << "    deleted is not set\n";
    }

    if (m_active) {
        strm << "    active = "
            << *m_active << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (m_shardId) {
        strm << "    shardId = "
            << *m_shardId << "\n";
    }
    else {
        strm << "    shardId is not set\n";
    }

    if (m_attributes) {
        strm << "    attributes = "
            << *m_attributes << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (m_accounting) {
        strm << "    accounting = "
            << *m_accounting << "\n";
    }
    else {
        strm << "    accounting is not set\n";
    }

    if (m_businessUserInfo) {
        strm << "    businessUserInfo = "
            << *m_businessUserInfo << "\n";
    }
    else {
        strm << "    businessUserInfo is not set\n";
    }

    if (m_photoUrl) {
        strm << "    photoUrl = "
            << *m_photoUrl << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (m_photoLastUpdated) {
        strm << "    photoLastUpdated = "
            << *m_photoLastUpdated << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (m_accountLimits) {
        strm << "    accountLimits = "
            << *m_accountLimits << "\n";
    }
    else {
        strm << "    accountLimits is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
