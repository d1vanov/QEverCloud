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

#include <qevercloud/serialization/json/LinkedNotebook.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const LinkedNotebook & value)
{
    QJsonObject object;

    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    if (value.shareName()) {
        object[QStringLiteral("shareName")] = *value.shareName();
    }

    if (value.username()) {
        object[QStringLiteral("username")] = *value.username();
    }

    if (value.shardId()) {
        object[QStringLiteral("shardId")] = *value.shardId();
    }

    if (value.sharedNotebookGlobalId()) {
        object[QStringLiteral("sharedNotebookGlobalId")] = *value.sharedNotebookGlobalId();
    }

    if (value.uri()) {
        object[QStringLiteral("uri")] = *value.uri();
    }

    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.noteStoreUrl()) {
        object[QStringLiteral("noteStoreUrl")] = *value.noteStoreUrl();
    }

    if (value.webApiUrlPrefix()) {
        object[QStringLiteral("webApiUrlPrefix")] = *value.webApiUrlPrefix();
    }

    if (value.stack()) {
        object[QStringLiteral("stack")] = *value.stack();
    }

    if (value.businessId()) {
        object[QStringLiteral("businessId")] = *value.businessId();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, LinkedNotebook & value)
{
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
            for (auto it: toRange(qAsConst(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("shareName"))) {
        const auto v = object[QStringLiteral("shareName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setShareName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("username"))) {
        const auto v = object[QStringLiteral("username")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUsername(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("shardId"))) {
        const auto v = object[QStringLiteral("shardId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setShardId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharedNotebookGlobalId"))) {
        const auto v = object[QStringLiteral("sharedNotebookGlobalId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSharedNotebookGlobalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("uri"))) {
        const auto v = object[QStringLiteral("uri")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUri(std::move(s));
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

    if (object.contains(QStringLiteral("noteStoreUrl"))) {
        const auto v = object[QStringLiteral("noteStoreUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteStoreUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("webApiUrlPrefix"))) {
        const auto v = object[QStringLiteral("webApiUrlPrefix")];
        if (v.isString()) {
            auto s = v.toString();
            value.setWebApiUrlPrefix(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("stack"))) {
        const auto v = object[QStringLiteral("stack")];
        if (v.isString()) {
            auto s = v.toString();
            value.setStack(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessId"))) {
        const auto v = object[QStringLiteral("businessId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setBusinessId(static_cast<qint32>(d));
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
