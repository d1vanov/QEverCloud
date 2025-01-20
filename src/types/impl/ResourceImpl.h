/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RESOURCEIMPL
#define QEVERCLOUD_GENERATED_RESOURCEIMPL

#include <qevercloud/types/Resource.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN Resource::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl();
    Impl(const Resource::Impl & other) = default;
    Impl(Resource::Impl && other) noexcept = default;

    Resource::Impl & operator=(const Resource::Impl & other) = delete;
    Resource::Impl & operator=(Resource::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    QString m_noteLocalId;
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

#endif // QEVERCLOUD_GENERATED_RESOURCEIMPL
