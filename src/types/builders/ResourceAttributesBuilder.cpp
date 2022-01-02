/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/ResourceAttributesBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ResourceAttributesBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_sourceURL;
    std::optional<Timestamp> m_timestamp;
    std::optional<double> m_latitude;
    std::optional<double> m_longitude;
    std::optional<double> m_altitude;
    std::optional<QString> m_cameraMake;
    std::optional<QString> m_cameraModel;
    std::optional<bool> m_clientWillIndex;
    std::optional<QString> m_recoType;
    std::optional<QString> m_fileName;
    std::optional<bool> m_attachment;
    std::optional<LazyMap> m_applicationData;
};

ResourceAttributesBuilder::ResourceAttributesBuilder() :
    d(new ResourceAttributesBuilder::Impl)
{}

ResourceAttributesBuilder::ResourceAttributesBuilder(ResourceAttributesBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ResourceAttributesBuilder::~ResourceAttributesBuilder() noexcept = default;

ResourceAttributesBuilder & ResourceAttributesBuilder::operator=(ResourceAttributesBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setSourceURL(std::optional<QString> sourceURL)
{
    d->m_sourceURL = std::move(sourceURL);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setTimestamp(std::optional<Timestamp> timestamp)
{
    d->m_timestamp = std::move(timestamp);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setLatitude(std::optional<double> latitude)
{
    d->m_latitude = std::move(latitude);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setLongitude(std::optional<double> longitude)
{
    d->m_longitude = std::move(longitude);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setAltitude(std::optional<double> altitude)
{
    d->m_altitude = std::move(altitude);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setCameraMake(std::optional<QString> cameraMake)
{
    d->m_cameraMake = std::move(cameraMake);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setCameraModel(std::optional<QString> cameraModel)
{
    d->m_cameraModel = std::move(cameraModel);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setClientWillIndex(std::optional<bool> clientWillIndex)
{
    d->m_clientWillIndex = std::move(clientWillIndex);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setRecoType(std::optional<QString> recoType)
{
    d->m_recoType = std::move(recoType);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setFileName(std::optional<QString> fileName)
{
    d->m_fileName = std::move(fileName);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setAttachment(std::optional<bool> attachment)
{
    d->m_attachment = std::move(attachment);
    return *this;
}

ResourceAttributesBuilder & ResourceAttributesBuilder::setApplicationData(std::optional<LazyMap> applicationData)
{
    d->m_applicationData = std::move(applicationData);
    return *this;
}

ResourceAttributes ResourceAttributesBuilder::build()
{
    ResourceAttributes result;

    result.setSourceURL(std::move(d->m_sourceURL));
    result.setTimestamp(std::move(d->m_timestamp));
    result.setLatitude(std::move(d->m_latitude));
    result.setLongitude(std::move(d->m_longitude));
    result.setAltitude(std::move(d->m_altitude));
    result.setCameraMake(std::move(d->m_cameraMake));
    result.setCameraModel(std::move(d->m_cameraModel));
    result.setClientWillIndex(std::move(d->m_clientWillIndex));
    result.setRecoType(std::move(d->m_recoType));
    result.setFileName(std::move(d->m_fileName));
    result.setAttachment(std::move(d->m_attachment));
    result.setApplicationData(std::move(d->m_applicationData));

    d->m_sourceURL = {};
    d->m_timestamp = {};
    d->m_latitude = {};
    d->m_longitude = {};
    d->m_altitude = {};
    d->m_cameraMake = {};
    d->m_cameraModel = {};
    d->m_clientWillIndex = {};
    d->m_recoType = {};
    d->m_fileName = {};
    d->m_attachment = {};
    d->m_applicationData = {};

    return result;
}

} // namespace qevercloud
