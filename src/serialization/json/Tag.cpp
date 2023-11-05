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

#include <qevercloud/serialization/json/Tag.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const Tag & value)
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

    if (value.linkedNotebookGuid()) {
        object[QStringLiteral("linkedNotebookGuid")] = *value.linkedNotebookGuid();
    }

    object[QStringLiteral("parentTagLocalId")] = value.parentTagLocalId();
    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.parentGuid()) {
        object[QStringLiteral("parentGuid")] = *value.parentGuid();
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Tag & value)
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

    if (object.contains(QStringLiteral("linkedNotebookGuid"))) {
        const auto v = object[QStringLiteral("linkedNotebookGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLinkedNotebookGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("parentTagLocalId"))) {
        const auto v = object[QStringLiteral("parentTagLocalId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setParentTagLocalId(std::move(s));
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

    if (object.contains(QStringLiteral("name"))) {
        const auto v = object[QStringLiteral("name")];
        if (v.isString()) {
            auto s = v.toString();
            value.setName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("parentGuid"))) {
        const auto v = object[QStringLiteral("parentGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setParentGuid(std::move(s));
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

    return true;
}

} // namespace qevercloud
