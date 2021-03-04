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

#include "ResourceImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

Resource::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

void Resource::Impl::print(QTextStream & strm) const
{
    strm << "Resource: {\n";
        strm << "    noteLocalId = " << m_noteLocalId << "\n";
        strm << "\n";
        strm << "    localId = " << m_localId << "\n";
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

    if (m_noteGuid) {
        strm << "    noteGuid = "
            << *m_noteGuid << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (m_data) {
        strm << "    data = "
            << *m_data << "\n";
    }
    else {
        strm << "    data is not set\n";
    }

    if (m_mime) {
        strm << "    mime = "
            << *m_mime << "\n";
    }
    else {
        strm << "    mime is not set\n";
    }

    if (m_width) {
        strm << "    width = "
            << *m_width << "\n";
    }
    else {
        strm << "    width is not set\n";
    }

    if (m_height) {
        strm << "    height = "
            << *m_height << "\n";
    }
    else {
        strm << "    height is not set\n";
    }

    if (m_duration) {
        strm << "    duration = "
            << *m_duration << "\n";
    }
    else {
        strm << "    duration is not set\n";
    }

    if (m_active) {
        strm << "    active = "
            << *m_active << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (m_recognition) {
        strm << "    recognition = "
            << *m_recognition << "\n";
    }
    else {
        strm << "    recognition is not set\n";
    }

    if (m_attributes) {
        strm << "    attributes = "
            << *m_attributes << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (m_alternateData) {
        strm << "    alternateData = "
            << *m_alternateData << "\n";
    }
    else {
        strm << "    alternateData is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
