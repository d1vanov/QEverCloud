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

#include "NoteAttributesData.h"

#include <QTextStream>

namespace qevercloud {

bool NoteAttributes::Impl::operator==(
    const NoteAttributes::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_subjectDate == other.m_subjectDate &&
        m_latitude == other.m_latitude &&
        m_longitude == other.m_longitude &&
        m_altitude == other.m_altitude &&
        m_author == other.m_author &&
        m_source == other.m_source &&
        m_sourceURL == other.m_sourceURL &&
        m_sourceApplication == other.m_sourceApplication &&
        m_shareDate == other.m_shareDate &&
        m_reminderOrder == other.m_reminderOrder &&
        m_reminderDoneTime == other.m_reminderDoneTime &&
        m_reminderTime == other.m_reminderTime &&
        m_placeName == other.m_placeName &&
        m_contentClass == other.m_contentClass &&
        m_applicationData == other.m_applicationData &&
        m_lastEditedBy == other.m_lastEditedBy &&
        m_classifications == other.m_classifications &&
        m_creatorId == other.m_creatorId &&
        m_lastEditorId == other.m_lastEditorId &&
        m_sharedWithBusiness == other.m_sharedWithBusiness &&
        m_conflictSourceNoteGuid == other.m_conflictSourceNoteGuid &&
        m_noteTitleQuality == other.m_noteTitleQuality;
}

bool NoteAttributes::Impl::operator!=(
    const NoteAttributes::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteAttributes::Data::print(QTextStream & strm) const
{
    strm << "NoteAttributes: {\n";

    if (m_subjectDate) {
        strm << "    subjectDate = "
            << *m_subjectDate << "\n";
    }
    else {
        strm << "    subjectDate is not set\n";
    }

    if (m_latitude) {
        strm << "    latitude = "
            << *m_latitude << "\n";
    }
    else {
        strm << "    latitude is not set\n";
    }

    if (m_longitude) {
        strm << "    longitude = "
            << *m_longitude << "\n";
    }
    else {
        strm << "    longitude is not set\n";
    }

    if (m_altitude) {
        strm << "    altitude = "
            << *m_altitude << "\n";
    }
    else {
        strm << "    altitude is not set\n";
    }

    if (m_author) {
        strm << "    author = "
            << *m_author << "\n";
    }
    else {
        strm << "    author is not set\n";
    }

    if (m_source) {
        strm << "    source = "
            << *m_source << "\n";
    }
    else {
        strm << "    source is not set\n";
    }

    if (m_sourceURL) {
        strm << "    sourceURL = "
            << *m_sourceURL << "\n";
    }
    else {
        strm << "    sourceURL is not set\n";
    }

    if (m_sourceApplication) {
        strm << "    sourceApplication = "
            << *m_sourceApplication << "\n";
    }
    else {
        strm << "    sourceApplication is not set\n";
    }

    if (m_shareDate) {
        strm << "    shareDate = "
            << *m_shareDate << "\n";
    }
    else {
        strm << "    shareDate is not set\n";
    }

    if (m_reminderOrder) {
        strm << "    reminderOrder = "
            << *m_reminderOrder << "\n";
    }
    else {
        strm << "    reminderOrder is not set\n";
    }

    if (m_reminderDoneTime) {
        strm << "    reminderDoneTime = "
            << *m_reminderDoneTime << "\n";
    }
    else {
        strm << "    reminderDoneTime is not set\n";
    }

    if (m_reminderTime) {
        strm << "    reminderTime = "
            << *m_reminderTime << "\n";
    }
    else {
        strm << "    reminderTime is not set\n";
    }

    if (m_placeName) {
        strm << "    placeName = "
            << *m_placeName << "\n";
    }
    else {
        strm << "    placeName is not set\n";
    }

    if (m_contentClass) {
        strm << "    contentClass = "
            << *m_contentClass << "\n";
    }
    else {
        strm << "    contentClass is not set\n";
    }

    if (m_applicationData) {
        strm << "    applicationData = "
            << *m_applicationData << "\n";
    }
    else {
        strm << "    applicationData is not set\n";
    }

    if (m_lastEditedBy) {
        strm << "    lastEditedBy = "
            << *m_lastEditedBy << "\n";
    }
    else {
        strm << "    lastEditedBy is not set\n";
    }

    if (m_classifications) {
        strm << "    classifications = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(*m_classifications)) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    classifications is not set\n";
    }

    if (m_creatorId) {
        strm << "    creatorId = "
            << *m_creatorId << "\n";
    }
    else {
        strm << "    creatorId is not set\n";
    }

    if (m_lastEditorId) {
        strm << "    lastEditorId = "
            << *m_lastEditorId << "\n";
    }
    else {
        strm << "    lastEditorId is not set\n";
    }

    if (m_sharedWithBusiness) {
        strm << "    sharedWithBusiness = "
            << *m_sharedWithBusiness << "\n";
    }
    else {
        strm << "    sharedWithBusiness is not set\n";
    }

    if (m_conflictSourceNoteGuid) {
        strm << "    conflictSourceNoteGuid = "
            << *m_conflictSourceNoteGuid << "\n";
    }
    else {
        strm << "    conflictSourceNoteGuid is not set\n";
    }

    if (m_noteTitleQuality) {
        strm << "    noteTitleQuality = "
            << *m_noteTitleQuality << "\n";
    }
    else {
        strm << "    noteTitleQuality is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
