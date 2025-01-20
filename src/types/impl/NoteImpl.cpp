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

#include "NoteImpl.h"

#include "../../Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

Note::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

void Note::Impl::print(QTextStream & strm) const
{
    strm << "Note: {\n";
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
    strm << "    notebookLocalId = "
        << m_notebookLocalId << "\n";
    strm << "    tagLocalIds = "
        << "QList<QString> {";
    for(const auto & v: m_tagLocalIds) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";
    strm << "    thumbnailData = ";
    if (m_thumbnailData.size() <= 1024) {
        strm << m_thumbnailData.toHex() << "\n";
    }
    else {
        strm << "<binary data, " << m_thumbnailData.size() << " bytes>" << "\n";
    }

    if (m_guid) {
        strm << "    guid = "
            << *m_guid << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (m_title) {
        strm << "    title = "
            << *m_title << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (m_content) {
        strm << "    content = "
            << *m_content << "\n";
    }
    else {
        strm << "    content is not set\n";
    }

    if (m_contentHash) {
        strm << "    contentHash = "
            << m_contentHash->toHex() << "\n";
    }
    else {
        strm << "    contentHash is not set\n";
    }

    if (m_contentLength) {
        strm << "    contentLength = "
            << *m_contentLength << "\n";
    }
    else {
        strm << "    contentLength is not set\n";
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
            << (*m_active ? "true" : "false") << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (m_notebookGuid) {
        strm << "    notebookGuid = "
            << *m_notebookGuid << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (m_tagGuids) {
        strm << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: *m_tagGuids) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagGuids is not set\n";
    }

    if (m_resources) {
        strm << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: *m_resources) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    resources is not set\n";
    }

    if (m_attributes) {
        strm << "    attributes = "
            << *m_attributes << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (m_tagNames) {
        strm << "    tagNames = "
            << "QList<QString> {";
        for(const auto & v: *m_tagNames) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagNames is not set\n";
    }

    if (m_sharedNotes) {
        strm << "    sharedNotes = "
            << "QList<SharedNote> {";
        for(const auto & v: *m_sharedNotes) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotes is not set\n";
    }

    if (m_restrictions) {
        strm << "    restrictions = "
            << *m_restrictions << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (m_limits) {
        strm << "    limits = "
            << *m_limits << "\n";
    }
    else {
        strm << "    limits is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
