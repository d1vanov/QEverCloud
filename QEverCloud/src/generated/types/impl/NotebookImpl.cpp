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

#include "NotebookImpl.h"

#include <QTextStream>

namespace qevercloud {

bool Notebook::Impl::operator==(
    const Notebook::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_localId == other.m_localId &&
        m_parentLocalId == other.m_parentLocalId &&
        m_locallyModified == other.m_locallyModified &&
        m_localOnly == other.m_localOnly &&
        m_locallyFavorited == other.m_locallyFavorited &&
        m_guid == other.m_guid &&
        m_name == other.m_name &&
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_defaultNotebook == other.m_defaultNotebook &&
        m_serviceCreated == other.m_serviceCreated &&
        m_serviceUpdated == other.m_serviceUpdated &&
        m_publishing == other.m_publishing &&
        m_published == other.m_published &&
        m_stack == other.m_stack &&
        m_sharedNotebookIds == other.m_sharedNotebookIds &&
        m_sharedNotebooks == other.m_sharedNotebooks &&
        m_businessNotebook == other.m_businessNotebook &&
        m_contact == other.m_contact &&
        m_restrictions == other.m_restrictions &&
        m_recipientSettings == other.m_recipientSettings;
}

bool Notebook::Impl::operator!=(
    const Notebook::Impl & other) const noexcept
{
    return !(*this == other);
}

void Notebook::Impl::print(QTextStream & strm) const
{
    strm << "Notebook: {\n";
        strm << "    localId = " << m_localId << "\n";
        strm << "    parentLocalId = " << m_parentLocalId << "\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";

    if (m_guid) {
        strm << "    guid = "
            << *m_guid << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (m_defaultNotebook) {
        strm << "    defaultNotebook = "
            << *m_defaultNotebook << "\n";
    }
    else {
        strm << "    defaultNotebook is not set\n";
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

    if (m_publishing) {
        strm << "    publishing = "
            << *m_publishing << "\n";
    }
    else {
        strm << "    publishing is not set\n";
    }

    if (m_published) {
        strm << "    published = "
            << *m_published << "\n";
    }
    else {
        strm << "    published is not set\n";
    }

    if (m_stack) {
        strm << "    stack = "
            << *m_stack << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (m_sharedNotebookIds) {
        strm << "    sharedNotebookIds = "
            << "QList<qint64> {";
        for(const auto & v: *m_sharedNotebookIds) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotebookIds is not set\n";
    }

    if (m_sharedNotebooks) {
        strm << "    sharedNotebooks = "
            << "QList<SharedNotebook> {";
        for(const auto & v: *m_sharedNotebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotebooks is not set\n";
    }

    if (m_businessNotebook) {
        strm << "    businessNotebook = "
            << *m_businessNotebook << "\n";
    }
    else {
        strm << "    businessNotebook is not set\n";
    }

    if (m_contact) {
        strm << "    contact = "
            << *m_contact << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (m_restrictions) {
        strm << "    restrictions = "
            << *m_restrictions << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (m_recipientSettings) {
        strm << "    recipientSettings = "
            << *m_recipientSettings << "\n";
    }
    else {
        strm << "    recipientSettings is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
