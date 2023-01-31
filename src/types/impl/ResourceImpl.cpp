/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "ResourceImpl.h"

#include "../../Impl.h"

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
    strm << "    noteLocalId = "
        << m_noteLocalId << "\n";

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
            << (*m_active ? "true" : "false") << "\n";
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
