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

#include <generated/types/ResourceAttributes.h>

#include "impl/ResourceAttributesImpl.h"

namespace qevercloud {

ResourceAttributes::ResourceAttributes() : d(new ResourceAttributes::Impl) {}

ResourceAttributes::ResourceAttributes(const ResourceAttributes & other) : d(other.d) {}

ResourceAttributes::ResourceAttributes(ResourceAttributes && other) noexcept : d(std::move(other.d))
{}

ResourceAttributes::~ResourceAttributes() noexcept {}

ResourceAttributes & ResourceAttributes::operator=(const ResourceAttributes & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ResourceAttributes & ResourceAttributes::operator=(ResourceAttributes && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & ResourceAttributes::sourceURL() const noexcept
{
    return d->m_sourceURL;
}

void ResourceAttributes::setSourceURL(std::optional<QString> sourceURL)
{
    d->m_sourceURL = sourceURL;
}

const std::optional<Timestamp> & ResourceAttributes::timestamp() const noexcept
{
    return d->m_timestamp;
}

std::optional<Timestamp> & ResourceAttributes::mutableTimestamp()
{
    return d->m_timestamp;
}

void ResourceAttributes::setTimestamp(std::optional<Timestamp> timestamp)
{
    d->m_timestamp = timestamp;
}

const std::optional<double> & ResourceAttributes::latitude() const noexcept
{
    return d->m_latitude;
}

std::optional<double> & ResourceAttributes::mutableLatitude()
{
    return d->m_latitude;
}

void ResourceAttributes::setLatitude(std::optional<double> latitude)
{
    d->m_latitude = latitude;
}

const std::optional<double> & ResourceAttributes::longitude() const noexcept
{
    return d->m_longitude;
}

std::optional<double> & ResourceAttributes::mutableLongitude()
{
    return d->m_longitude;
}

void ResourceAttributes::setLongitude(std::optional<double> longitude)
{
    d->m_longitude = longitude;
}

const std::optional<double> & ResourceAttributes::altitude() const noexcept
{
    return d->m_altitude;
}

std::optional<double> & ResourceAttributes::mutableAltitude()
{
    return d->m_altitude;
}

void ResourceAttributes::setAltitude(std::optional<double> altitude)
{
    d->m_altitude = altitude;
}

const std::optional<QString> & ResourceAttributes::cameraMake() const noexcept
{
    return d->m_cameraMake;
}

void ResourceAttributes::setCameraMake(std::optional<QString> cameraMake)
{
    d->m_cameraMake = cameraMake;
}

const std::optional<QString> & ResourceAttributes::cameraModel() const noexcept
{
    return d->m_cameraModel;
}

void ResourceAttributes::setCameraModel(std::optional<QString> cameraModel)
{
    d->m_cameraModel = cameraModel;
}

const std::optional<bool> & ResourceAttributes::clientWillIndex() const noexcept
{
    return d->m_clientWillIndex;
}

std::optional<bool> & ResourceAttributes::mutableClientWillIndex()
{
    return d->m_clientWillIndex;
}

void ResourceAttributes::setClientWillIndex(std::optional<bool> clientWillIndex)
{
    d->m_clientWillIndex = clientWillIndex;
}

const std::optional<QString> & ResourceAttributes::recoType() const noexcept
{
    return d->m_recoType;
}

void ResourceAttributes::setRecoType(std::optional<QString> recoType)
{
    d->m_recoType = recoType;
}

const std::optional<QString> & ResourceAttributes::fileName() const noexcept
{
    return d->m_fileName;
}

void ResourceAttributes::setFileName(std::optional<QString> fileName)
{
    d->m_fileName = fileName;
}

const std::optional<bool> & ResourceAttributes::attachment() const noexcept
{
    return d->m_attachment;
}

std::optional<bool> & ResourceAttributes::mutableAttachment()
{
    return d->m_attachment;
}

void ResourceAttributes::setAttachment(std::optional<bool> attachment)
{
    d->m_attachment = attachment;
}

const std::optional<LazyMap> & ResourceAttributes::applicationData() const noexcept
{
    return d->m_applicationData;
}

std::optional<LazyMap> & ResourceAttributes::mutableApplicationData()
{
    return d->m_applicationData;
}

void ResourceAttributes::setApplicationData(std::optional<LazyMap> applicationData)
{
    d->m_applicationData = applicationData;
}

void ResourceAttributes::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ResourceAttributes::operator==(const ResourceAttributes & other) const noexcept
{
    return *d == *other.d;
}

bool ResourceAttributes::operator!=(const ResourceAttributes & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
