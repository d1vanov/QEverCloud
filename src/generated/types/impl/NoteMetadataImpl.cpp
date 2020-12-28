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

#include "NoteMetadataImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

NoteMetadata::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

bool NoteMetadata::Impl::operator==(
    const NoteMetadata::Impl & other) const noexcept
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
        m_title == other.m_title &&
        m_contentLength == other.m_contentLength &&
        m_created == other.m_created &&
        m_updated == other.m_updated &&
        m_deleted == other.m_deleted &&
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_notebookGuid == other.m_notebookGuid &&
        m_tagGuids == other.m_tagGuids &&
        m_attributes == other.m_attributes &&
        m_largestResourceMime == other.m_largestResourceMime &&
        m_largestResourceSize == other.m_largestResourceSize;
}

bool NoteMetadata::Impl::operator!=(
    const NoteMetadata::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteMetadata::Impl::print(QTextStream & strm) const
{
    strm << "NoteMetadata: {\n";
        strm << "    localId = " << m_localId << "\n";
        strm << "    parentLocalId = " << m_parentLocalId << "\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";
    strm << "    guid = "
        << m_guid << "\n";

    if (m_title) {
        strm << "    title = "
            << *m_title << "\n";
    }
    else {
        strm << "    title is not set\n";
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

    if (m_attributes) {
        strm << "    attributes = "
            << *m_attributes << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (m_largestResourceMime) {
        strm << "    largestResourceMime = "
            << *m_largestResourceMime << "\n";
    }
    else {
        strm << "    largestResourceMime is not set\n";
    }

    if (m_largestResourceSize) {
        strm << "    largestResourceSize = "
            << *m_largestResourceSize << "\n";
    }
    else {
        strm << "    largestResourceSize is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
