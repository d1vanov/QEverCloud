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

#ifndef QEVERCLOUD_GENERATED_RESOURCEATTRIBUTES
#define QEVERCLOUD_GENERATED_RESOURCEATTRIBUTES

#include <qevercloud/Export.h>

#include "LazyMap.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Structure holding the optional attributes of a Resource
 * */
class QEVERCLOUD_EXPORT ResourceAttributes: public Printable
{
    Q_GADGET
public:
    ResourceAttributes();
    ResourceAttributes(const ResourceAttributes & other);
    ResourceAttributes(ResourceAttributes && other) noexcept;
    ~ResourceAttributes() noexcept override;

    ResourceAttributes & operator=(const ResourceAttributes & other);
    ResourceAttributes & operator=(ResourceAttributes && other) noexcept;

    /**
     * the original location where the resource was hosted
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & sourceURL() const noexcept;
    void setSourceURL(std::optional<QString> sourceURL);

    /**
     * the date and time that is associated with this resource
     * (e.g. the time embedded in an image from a digital camera with a clock)
     */
    [[nodiscard]] const std::optional<Timestamp> & timestamp() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableTimestamp();
    void setTimestamp(std::optional<Timestamp> timestamp);

    /**
     * the latitude where the resource was captured
     */
    [[nodiscard]] const std::optional<double> & latitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableLatitude();
    void setLatitude(std::optional<double> latitude);

    /**
     * the longitude where the resource was captured
     */
    [[nodiscard]] const std::optional<double> & longitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableLongitude();
    void setLongitude(std::optional<double> longitude);

    /**
     * the altitude where the resource was captured
     */
    [[nodiscard]] const std::optional<double> & altitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableAltitude();
    void setAltitude(std::optional<double> altitude);

    /**
     * information about an image's camera, e.g. as embedded in
     * the image's EXIF data
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & cameraMake() const noexcept;
    void setCameraMake(std::optional<QString> cameraMake);

    /**
     * information about an image's camera, e.g. as embedded
     * in the image's EXIF data
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & cameraModel() const noexcept;
    void setCameraModel(std::optional<QString> cameraModel);

    /**
     * if true, then the original client that submitted
     * the resource plans to submit the recognition index for this resource at a
     * later time.
     */
    [[nodiscard]] const std::optional<bool> & clientWillIndex() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableClientWillIndex();
    void setClientWillIndex(std::optional<bool> clientWillIndex);

    /**
     * DEPRECATED - this field is no longer set by the service, so should
     * be ignored.
     */
    [[nodiscard]] const std::optional<QString> & recoType() const noexcept;
    void setRecoType(std::optional<QString> recoType);

    /**
     * if the resource came from a source that provided an
     * explicit file name, the original name will be stored here. Many resources
     * come from unnamed sources, so this will not always be set.
     */
    [[nodiscard]] const std::optional<QString> & fileName() const noexcept;
    void setFileName(std::optional<QString> fileName);

    /**
     * this will be true if the resource should be displayed as an attachment,
     * or false if the resource should be displayed inline (if possible).
     */
    [[nodiscard]] const std::optional<bool> & attachment() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableAttachment();
    void setAttachment(std::optional<bool> attachment);

    /**
     * Provides a location for applications to store a relatively small
     * (4kb) blob of data associated with a Resource that is not visible to the user
     * and that is opaque to the Evernote service. A single application may use at most
     * one entry in this map, using its API consumer key as the map key. See the
     * documentation for LazyMap for a description of when the actual map values
     * are returned by the service.
     * <p>To safely add or modify your application's entry in the map, use
     * NoteStore.setResourceApplicationDataEntry. To safely remove your application's
     * entry from the map, use NoteStore.unsetResourceApplicationDataEntry.</p>
     * Minimum length of a name (key): EDAM_APPLICATIONDATA_NAME_LEN_MIN
     * Sum max size of key and value: EDAM_APPLICATIONDATA_ENTRY_LEN_MAX
     * Syntax regex for name (key): EDAM_APPLICATIONDATA_NAME_REGEX
     */
    [[nodiscard]] const std::optional<LazyMap> & applicationData() const noexcept;
    [[nodiscard]] std::optional<LazyMap> & mutableApplicationData();
    void setApplicationData(std::optional<LazyMap> applicationData);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<QString> sourceURL READ sourceURL WRITE setSourceURL)
    Q_PROPERTY(std::optional<Timestamp> timestamp READ timestamp WRITE setTimestamp)
    Q_PROPERTY(std::optional<double> latitude READ latitude WRITE setLatitude)
    Q_PROPERTY(std::optional<double> longitude READ longitude WRITE setLongitude)
    Q_PROPERTY(std::optional<double> altitude READ altitude WRITE setAltitude)
    Q_PROPERTY(std::optional<QString> cameraMake READ cameraMake WRITE setCameraMake)
    Q_PROPERTY(std::optional<QString> cameraModel READ cameraModel WRITE setCameraModel)
    Q_PROPERTY(std::optional<bool> clientWillIndex READ clientWillIndex WRITE setClientWillIndex)
    Q_PROPERTY(std::optional<QString> recoType READ recoType WRITE setRecoType)
    Q_PROPERTY(std::optional<QString> fileName READ fileName WRITE setFileName)
    Q_PROPERTY(std::optional<bool> attachment READ attachment WRITE setAttachment)
    Q_PROPERTY(std::optional<LazyMap> applicationData READ applicationData WRITE setApplicationData)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ResourceAttributes & lhs, const ResourceAttributes & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ResourceAttributes & lhs, const ResourceAttributes & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ResourceAttributes)

#endif // QEVERCLOUD_GENERATED_RESOURCEATTRIBUTES
