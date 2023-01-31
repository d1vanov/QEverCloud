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

#ifndef QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESBUILDER
#define QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/LazyMap.h>
#include <qevercloud/types/ResourceAttributes.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ResourceAttributesBuilder
{
public:
    ResourceAttributesBuilder();

    ResourceAttributesBuilder(ResourceAttributesBuilder && other) noexcept;

    ~ResourceAttributesBuilder() noexcept;

    ResourceAttributesBuilder & operator=(ResourceAttributesBuilder && other) noexcept;

    ResourceAttributesBuilder & setSourceURL(std::optional<QString> sourceURL);
    ResourceAttributesBuilder & setTimestamp(std::optional<Timestamp> timestamp);
    ResourceAttributesBuilder & setLatitude(std::optional<double> latitude);
    ResourceAttributesBuilder & setLongitude(std::optional<double> longitude);
    ResourceAttributesBuilder & setAltitude(std::optional<double> altitude);
    ResourceAttributesBuilder & setCameraMake(std::optional<QString> cameraMake);
    ResourceAttributesBuilder & setCameraModel(std::optional<QString> cameraModel);
    ResourceAttributesBuilder & setClientWillIndex(std::optional<bool> clientWillIndex);
    ResourceAttributesBuilder & setRecoType(std::optional<QString> recoType);
    ResourceAttributesBuilder & setFileName(std::optional<QString> fileName);
    ResourceAttributesBuilder & setAttachment(std::optional<bool> attachment);
    ResourceAttributesBuilder & setApplicationData(std::optional<LazyMap> applicationData);

    [[nodiscard]] ResourceAttributes build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESBUILDER
