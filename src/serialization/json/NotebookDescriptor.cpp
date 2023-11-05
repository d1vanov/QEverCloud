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

#include <qevercloud/serialization/json/NotebookDescriptor.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const NotebookDescriptor & value)
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

    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.notebookDisplayName()) {
        object[QStringLiteral("notebookDisplayName")] = *value.notebookDisplayName();
    }

    if (value.contactName()) {
        object[QStringLiteral("contactName")] = *value.contactName();
    }

    if (value.hasSharedNotebook()) {
        object[QStringLiteral("hasSharedNotebook")] = *value.hasSharedNotebook();
    }

    if (value.joinedUserCount()) {
        object[QStringLiteral("joinedUserCount")] = *value.joinedUserCount();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NotebookDescriptor & value)
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

    if (object.contains(QStringLiteral("notebookDisplayName"))) {
        const auto v = object[QStringLiteral("notebookDisplayName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookDisplayName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contactName"))) {
        const auto v = object[QStringLiteral("contactName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContactName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("hasSharedNotebook"))) {
        const auto v = object[QStringLiteral("hasSharedNotebook")];
        if (v.isBool()) {
            value.setHasSharedNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("joinedUserCount"))) {
        const auto v = object[QStringLiteral("joinedUserCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setJoinedUserCount(static_cast<qint32>(d));
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
