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

#include <qevercloud/serialization/json/Resource.h>

#include <qevercloud/serialization/json/Data.h>
#include <qevercloud/serialization/json/ResourceAttributes.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const Resource & value)
{
    QJsonObject object;

    object[QStringLiteral("localId")] = value.localId();
    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(std::as_const(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    object[QStringLiteral("noteLocalId")] = value.noteLocalId();
    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.noteGuid()) {
        object[QStringLiteral("noteGuid")] = *value.noteGuid();
    }

    if (value.data()) {
        object[QStringLiteral("data")] = serializeToJson(*value.data());
    }

    if (value.mime()) {
        object[QStringLiteral("mime")] = *value.mime();
    }

    if (value.width()) {
        object[QStringLiteral("width")] = *value.width();
    }

    if (value.height()) {
        object[QStringLiteral("height")] = *value.height();
    }

    if (value.duration()) {
        object[QStringLiteral("duration")] = *value.duration();
    }

    if (value.active()) {
        object[QStringLiteral("active")] = *value.active();
    }

    if (value.recognition()) {
        object[QStringLiteral("recognition")] = serializeToJson(*value.recognition());
    }

    if (value.attributes()) {
        object[QStringLiteral("attributes")] = serializeToJson(*value.attributes());
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.alternateData()) {
        object[QStringLiteral("alternateData")] = serializeToJson(*value.alternateData());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Resource & value)
{
    if (object.contains(QStringLiteral("localId"))) {
        const auto v = object[QStringLiteral("localId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLocalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyModified"))) {
        const auto v = object[QStringLiteral("isLocallyModified")];
        if (v.isBool()) {
            value.setLocallyModified(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocalOnly"))) {
        const auto v = object[QStringLiteral("isLocalOnly")];
        if (v.isBool()) {
            value.setLocalOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyFavorited"))) {
        const auto v = object[QStringLiteral("isLocallyFavorited")];
        if (v.isBool()) {
            value.setLocallyFavorited(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("localData"))) {
        auto v = object[QStringLiteral("localData")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QHash<QString, QVariant> map;
            for (auto it: toRange(std::as_const(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteLocalId"))) {
        const auto v = object[QStringLiteral("noteLocalId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteLocalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("guid"))) {
        const auto v = object[QStringLiteral("guid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteGuid"))) {
        const auto v = object[QStringLiteral("noteGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("data"))) {
        const auto v = object[QStringLiteral("data")];
        if (v.isObject()) {
            auto o = v.toObject();
            Data f;
            if (deserializeFromJson(o, f)) {
                value.setData(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("mime"))) {
        const auto v = object[QStringLiteral("mime")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMime(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("width"))) {
        const auto v = object[QStringLiteral("width")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint16>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint16>::max())))
            {
                value.setWidth(static_cast<qint16>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("height"))) {
        const auto v = object[QStringLiteral("height")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint16>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint16>::max())))
            {
                value.setHeight(static_cast<qint16>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("duration"))) {
        const auto v = object[QStringLiteral("duration")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint16>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint16>::max())))
            {
                value.setDuration(static_cast<qint16>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("active"))) {
        const auto v = object[QStringLiteral("active")];
        if (v.isBool()) {
            value.setActive(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recognition"))) {
        const auto v = object[QStringLiteral("recognition")];
        if (v.isObject()) {
            auto o = v.toObject();
            Data f;
            if (deserializeFromJson(o, f)) {
                value.setRecognition(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("attributes"))) {
        const auto v = object[QStringLiteral("attributes")];
        if (v.isObject()) {
            auto o = v.toObject();
            ResourceAttributes f;
            if (deserializeFromJson(o, f)) {
                value.setAttributes(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updateSequenceNum"))) {
        const auto v = object[QStringLiteral("updateSequenceNum")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUpdateSequenceNum(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("alternateData"))) {
        const auto v = object[QStringLiteral("alternateData")];
        if (v.isObject()) {
            auto o = v.toObject();
            Data f;
            if (deserializeFromJson(o, f)) {
                value.setAlternateData(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
