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

#include "NotebookImpl.h"

#include "../../Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

Notebook::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

void Notebook::Impl::print(QTextStream & strm) const
{
    strm << "Notebook: {\n";
    strm << "    localId = "
        << m_localId << "\n";
    strm << "    isLocallyModified = "
        << (m_isLocallyModified ? "true" : "false") << "\n";
    strm << "    isLocalOnly = "
        << (m_isLocalOnly ? "true" : "false") << "\n";
    strm << "    isLocallyFavorited = "
        << (m_isLocallyFavorited ? "true" : "false") << "\n";
    strm << "    localData = "
        << "QHash<QString, QVariant> {";
    for(const auto & it: toRange(m_localData)) {
        strm << "    [" << it.key() << "] = ";
        QString debugStr;
        QDebug dbg{&debugStr};
        dbg << it.value();
        strm << debugStr << "\n";
    }
    strm << "    }\n";

    if (m_linkedNotebookGuid) {
        strm << "    linkedNotebookGuid = "
            << *m_linkedNotebookGuid << "\n";
    }
    else {
        strm << "    linkedNotebookGuid is not set\n";
    }

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
            << (*m_defaultNotebook ? "true" : "false") << "\n";
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
            << (*m_published ? "true" : "false") << "\n";
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
