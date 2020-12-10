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

#ifndef QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESDATA_H
#define QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESDATA_H

#include <generated/types/ResourceAttributes.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ResourceAttributes::ResourceAttributesData final:
    public QSharedData,
    public Printable
{
public:
    ResourceAttributesData() = default;
    ResourceAttributesData(const ResourceAttributesData & other) = default;
    ResourceAttributesData(ResourceAttributesData && other) noexcept = default;

    ResourceAttributesData & operator=(const ResourceAttributesData & other) = delete;
    ResourceAttributesData & operator=(ResourceAttributesData && other) = delete;

    ~ResourceAttributesData() noexcept override = default;

    [[nodiscard]] bool operator==(const ResourceAttributesData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ResourceAttributesData & other) const noexcept;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RESOURCEATTRIBUTESDATA_H
