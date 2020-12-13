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

#include "NoteImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool Note::Impl::operator==(
    const Note::Impl & other) const noexcept
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
        m_content == other.m_content &&
        m_contentHash == other.m_contentHash &&
        m_contentLength == other.m_contentLength &&
        m_created == other.m_created &&
        m_updated == other.m_updated &&
        m_deleted == other.m_deleted &&
        m_active == other.m_active &&
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_notebookGuid == other.m_notebookGuid &&
        m_tagGuids == other.m_tagGuids &&
        m_resources == other.m_resources &&
        m_attributes == other.m_attributes &&
        m_tagNames == other.m_tagNames &&
        m_sharedNotes == other.m_sharedNotes &&
        m_restrictions == other.m_restrictions &&
        m_limits == other.m_limits;
}

bool Note::Impl::operator!=(
    const Note::Impl & other) const noexcept
{
    return !(*this == other);
}

void Note::Impl::print(QTextStream & strm) const
{
    strm << "Note: {\n";
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
            << *m_contentHash << "\n";
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
            << *m_active << "\n";
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
