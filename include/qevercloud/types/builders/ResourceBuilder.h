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

#ifndef QEVERCLOUD_GENERATED_RESOURCEBUILDER
#define QEVERCLOUD_GENERATED_RESOURCEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Data.h>
#include <qevercloud/types/Resource.h>
#include <qevercloud/types/ResourceAttributes.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ResourceBuilder
{
public:
    ResourceBuilder();

    ResourceBuilder(ResourceBuilder && other) noexcept;

    ~ResourceBuilder() noexcept;

    ResourceBuilder & operator=(ResourceBuilder && other) noexcept;

    ResourceBuilder & setLocalId(QString localId);
    ResourceBuilder & setLocallyModified(bool isLocallyModified);
    ResourceBuilder & setLocalOnly(bool isLocalOnly);
    ResourceBuilder & setLocallyFavorited(bool isLocallyFavorited);
    ResourceBuilder & setLocalData(QHash<QString, QVariant> localData);
    ResourceBuilder & setNoteLocalId(QString noteLocalId);
    ResourceBuilder & setGuid(std::optional<Guid> guid);
    ResourceBuilder & setNoteGuid(std::optional<Guid> noteGuid);
    ResourceBuilder & setData(std::optional<Data> data);
    ResourceBuilder & setMime(std::optional<QString> mime);
    ResourceBuilder & setWidth(std::optional<qint16> width);
    ResourceBuilder & setHeight(std::optional<qint16> height);
    ResourceBuilder & setDuration(std::optional<qint16> duration);
    ResourceBuilder & setActive(std::optional<bool> active);
    ResourceBuilder & setRecognition(std::optional<Data> recognition);
    ResourceBuilder & setAttributes(std::optional<ResourceAttributes> attributes);
    ResourceBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    ResourceBuilder & setAlternateData(std::optional<Data> alternateData);

    [[nodiscard]] Resource build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RESOURCEBUILDER
