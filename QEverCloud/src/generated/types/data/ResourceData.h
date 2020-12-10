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

#ifndef QEVERCLOUD_GENERATED_RESOURCEDATA_H
#define QEVERCLOUD_GENERATED_RESOURCEDATA_H

#include <generated/types/Resource.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Resource::ResourceData final:
    public QSharedData,
    public Printable
{
public:
    ResourceData() = default;
    ResourceData(const ResourceData & other) = default;
    ResourceData(ResourceData && other) noexcept = default;

    ResourceData & operator=(const ResourceData & other) = delete;
    ResourceData & operator=(ResourceData && other) = delete;

    ~ResourceData() noexcept override = default;

    [[nodiscard]] bool operator==(const ResourceData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ResourceData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<Guid> m_guid;
    std::optional<Guid> m_noteGuid;
    std::optional<Data> m_data;
    std::optional<QString> m_mime;
    std::optional<qint16> m_width;
    std::optional<qint16> m_height;
    std::optional<qint16> m_duration;
    std::optional<bool> m_active;
    std::optional<Data> m_recognition;
    std::optional<ResourceAttributes> m_attributes;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<Data> m_alternateData;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RESOURCEDATA_H
