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

#include "ResourceAttributesData.h"

#include <QTextStream>

namespace qevercloud {

bool ResourceAttributes::ResourceAttributesData::operator==(
    const ResourceAttributesData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_sourceURL == other.m_sourceURL &&
        m_timestamp == other.m_timestamp &&
        m_latitude == other.m_latitude &&
        m_longitude == other.m_longitude &&
        m_altitude == other.m_altitude &&
        m_cameraMake == other.m_cameraMake &&
        m_cameraModel == other.m_cameraModel &&
        m_clientWillIndex == other.m_clientWillIndex &&
        m_recoType == other.m_recoType &&
        m_fileName == other.m_fileName &&
        m_attachment == other.m_attachment &&
        m_applicationData == other.m_applicationData;
}

bool ResourceAttributes::ResourceAttributesData::operator!=(
    const ResourceAttributesData & other) const noexcept
{
    return !(*this == other);
}

void ResourceAttributes::ResourceAttributesData::print(QTextStream & strm) const
{
    strm << "ResourceAttributes: {\n";

    if (m_sourceURL) {
        strm << "    sourceURL = "
            << *m_sourceURL << "\n";
    }
    else {
        strm << "    sourceURL is not set\n";
    }

    if (m_timestamp) {
        strm << "    timestamp = "
            << *m_timestamp << "\n";
    }
    else {
        strm << "    timestamp is not set\n";
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

    if (m_cameraMake) {
        strm << "    cameraMake = "
            << *m_cameraMake << "\n";
    }
    else {
        strm << "    cameraMake is not set\n";
    }

    if (m_cameraModel) {
        strm << "    cameraModel = "
            << *m_cameraModel << "\n";
    }
    else {
        strm << "    cameraModel is not set\n";
    }

    if (m_clientWillIndex) {
        strm << "    clientWillIndex = "
            << *m_clientWillIndex << "\n";
    }
    else {
        strm << "    clientWillIndex is not set\n";
    }

    if (m_recoType) {
        strm << "    recoType = "
            << *m_recoType << "\n";
    }
    else {
        strm << "    recoType is not set\n";
    }

    if (m_fileName) {
        strm << "    fileName = "
            << *m_fileName << "\n";
    }
    else {
        strm << "    fileName is not set\n";
    }

    if (m_attachment) {
        strm << "    attachment = "
            << *m_attachment << "\n";
    }
    else {
        strm << "    attachment is not set\n";
    }

    if (m_applicationData) {
        strm << "    applicationData = "
            << *m_applicationData << "\n";
    }
    else {
        strm << "    applicationData is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
