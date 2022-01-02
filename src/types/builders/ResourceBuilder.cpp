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

#include <qevercloud/types/builders/ResourceBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ResourceBuilder::Impl final:
    public QSharedData
{
public:
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
    QString m_localId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    QString m_noteLocalId;
};

ResourceBuilder::ResourceBuilder() :
    d(new ResourceBuilder::Impl)
{}

ResourceBuilder::ResourceBuilder(ResourceBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ResourceBuilder::~ResourceBuilder() noexcept = default;

ResourceBuilder & ResourceBuilder::operator=(ResourceBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ResourceBuilder & ResourceBuilder::setGuid(std::optional<Guid> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

ResourceBuilder & ResourceBuilder::setNoteGuid(std::optional<Guid> noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
    return *this;
}

ResourceBuilder & ResourceBuilder::setData(std::optional<Data> data)
{
    d->m_data = std::move(data);
    return *this;
}

ResourceBuilder & ResourceBuilder::setMime(std::optional<QString> mime)
{
    d->m_mime = std::move(mime);
    return *this;
}

ResourceBuilder & ResourceBuilder::setWidth(std::optional<qint16> width)
{
    d->m_width = std::move(width);
    return *this;
}

ResourceBuilder & ResourceBuilder::setHeight(std::optional<qint16> height)
{
    d->m_height = std::move(height);
    return *this;
}

ResourceBuilder & ResourceBuilder::setDuration(std::optional<qint16> duration)
{
    d->m_duration = std::move(duration);
    return *this;
}

ResourceBuilder & ResourceBuilder::setActive(std::optional<bool> active)
{
    d->m_active = std::move(active);
    return *this;
}

ResourceBuilder & ResourceBuilder::setRecognition(std::optional<Data> recognition)
{
    d->m_recognition = std::move(recognition);
    return *this;
}

ResourceBuilder & ResourceBuilder::setAttributes(std::optional<ResourceAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
    return *this;
}

ResourceBuilder & ResourceBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

ResourceBuilder & ResourceBuilder::setAlternateData(std::optional<Data> alternateData)
{
    d->m_alternateData = std::move(alternateData);
    return *this;
}

ResourceBuilder & ResourceBuilder::setLocalId(QString localId)
{
    d->m_localId = std::move(localId);
    return *this;
}

ResourceBuilder & ResourceBuilder::setLocallyModified(bool locallyModified)
{
    d->m_locallyModified = locallyModified;
    return *this;
}

ResourceBuilder & ResourceBuilder::setLocalOnly(bool localOnly)
{
    d->m_localOnly = localOnly;
    return *this;
}

ResourceBuilder & ResourceBuilder::setLocallyFavorited(bool favorited)
{
    d->m_locallyFavorited = favorited;
    return *this;
}

ResourceBuilder &ResourceBuilder::setLocalData(QHash<QString, QVariant> localData)
{
    d->m_localData = std::move(localData);
    return *this;
}

ResourceBuilder & ResourceBuilder::setNoteLocalId(QString noteLocalId)
{
    d->m_noteLocalId = std::move(noteLocalId);
    return *this;
}

Resource ResourceBuilder::build()
{
    Resource result;

    result.setGuid(std::move(d->m_guid));
    result.setNoteGuid(std::move(d->m_noteGuid));
    result.setData(std::move(d->m_data));
    result.setMime(std::move(d->m_mime));
    result.setWidth(std::move(d->m_width));
    result.setHeight(std::move(d->m_height));
    result.setDuration(std::move(d->m_duration));
    result.setActive(std::move(d->m_active));
    result.setRecognition(std::move(d->m_recognition));
    result.setAttributes(std::move(d->m_attributes));
    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setAlternateData(std::move(d->m_alternateData));
    result.setLocalId(std::move(d->m_localId));
    result.setLocallyModified(d->m_locallyModified);
    result.setLocalOnly(d->m_localOnly);
    result.setLocallyFavorited(d->m_locallyFavorited);
    result.setLocalData(std::move(d->m_localData));
    result.setNoteLocalId(std::move(d->m_noteLocalId));

    d->m_guid = {};
    d->m_noteGuid = {};
    d->m_data = {};
    d->m_mime = {};
    d->m_width = {};
    d->m_height = {};
    d->m_duration = {};
    d->m_active = {};
    d->m_recognition = {};
    d->m_attributes = {};
    d->m_updateSequenceNum = {};
    d->m_alternateData = {};
    d->m_localId = QString{};
    d->m_locallyModified = false;
    d->m_localOnly = false;
    d->m_locallyFavorited = false;
    d->m_localData = {};
    d->m_noteLocalId = QString{};

    return result;
}

} // namespace qevercloud
