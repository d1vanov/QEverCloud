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

#include <qevercloud/serialization/json/ResourceAttributes.h>

#include <qevercloud/serialization/json/LazyMap.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ResourceAttributes & value)
{
    QJsonObject object;

    if (value.sourceURL()) {
        object[QStringLiteral("sourceURL")] = *value.sourceURL();
    }

    if (value.timestamp()) {
        object[QStringLiteral("timestamp")] = QString::number(*value.timestamp());
    }

    if (value.latitude()) {
        object[QStringLiteral("latitude")] = *value.latitude();
    }

    if (value.longitude()) {
        object[QStringLiteral("longitude")] = *value.longitude();
    }

    if (value.altitude()) {
        object[QStringLiteral("altitude")] = *value.altitude();
    }

    if (value.cameraMake()) {
        object[QStringLiteral("cameraMake")] = *value.cameraMake();
    }

    if (value.cameraModel()) {
        object[QStringLiteral("cameraModel")] = *value.cameraModel();
    }

    if (value.clientWillIndex()) {
        object[QStringLiteral("clientWillIndex")] = *value.clientWillIndex();
    }

    if (value.recoType()) {
        object[QStringLiteral("recoType")] = *value.recoType();
    }

    if (value.fileName()) {
        object[QStringLiteral("fileName")] = *value.fileName();
    }

    if (value.attachment()) {
        object[QStringLiteral("attachment")] = *value.attachment();
    }

    if (value.applicationData()) {
        object[QStringLiteral("applicationData")] = serializeToJson(*value.applicationData());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ResourceAttributes & value)
{
    if (object.contains(QStringLiteral("sourceURL"))) {
        const auto v = object[QStringLiteral("sourceURL")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceURL(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("timestamp"))) {
        const auto v = object[QStringLiteral("timestamp")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setTimestamp(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("latitude"))) {
        const auto v = object[QStringLiteral("latitude")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setLatitude(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("longitude"))) {
        const auto v = object[QStringLiteral("longitude")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setLongitude(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("altitude"))) {
        const auto v = object[QStringLiteral("altitude")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setAltitude(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("cameraMake"))) {
        const auto v = object[QStringLiteral("cameraMake")];
        if (v.isString()) {
            auto s = v.toString();
            value.setCameraMake(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("cameraModel"))) {
        const auto v = object[QStringLiteral("cameraModel")];
        if (v.isString()) {
            auto s = v.toString();
            value.setCameraModel(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("clientWillIndex"))) {
        const auto v = object[QStringLiteral("clientWillIndex")];
        if (v.isBool()) {
            value.setClientWillIndex(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recoType"))) {
        const auto v = object[QStringLiteral("recoType")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRecoType(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("fileName"))) {
        const auto v = object[QStringLiteral("fileName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setFileName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("attachment"))) {
        const auto v = object[QStringLiteral("attachment")];
        if (v.isBool()) {
            value.setAttachment(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("applicationData"))) {
        const auto v = object[QStringLiteral("applicationData")];
        if (v.isObject()) {
            auto o = v.toObject();
            LazyMap f;
            if (deserializeFromJson(o, f)) {
                value.setApplicationData(std::move(f));
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
