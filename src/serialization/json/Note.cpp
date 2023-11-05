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

#include <qevercloud/serialization/json/Note.h>

#include <qevercloud/serialization/json/NoteAttributes.h>
#include <qevercloud/serialization/json/NoteLimits.h>
#include <qevercloud/serialization/json/NoteRestrictions.h>
#include <qevercloud/serialization/json/Resource.h>
#include <qevercloud/serialization/json/SharedNote.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const Note & value)
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

    object[QStringLiteral("notebookLocalId")] = value.notebookLocalId();
    {
        QJsonArray array;
        for (const auto & v: std::as_const(value.tagLocalIds()))
        {
            array << v;
        }

        object[QStringLiteral("tagLocalIds")] = array;
    }

    object[QStringLiteral("thumbnailData")] = QString::fromUtf8(value.thumbnailData().toBase64());
    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.title()) {
        object[QStringLiteral("title")] = *value.title();
    }

    if (value.content()) {
        object[QStringLiteral("content")] = *value.content();
    }

    if (value.contentHash()) {
        object[QStringLiteral("contentHash")] = QString::fromUtf8(value.contentHash()->toBase64());
    }

    if (value.contentLength()) {
        object[QStringLiteral("contentLength")] = *value.contentLength();
    }

    if (value.created()) {
        object[QStringLiteral("created")] = QString::number(*value.created());
    }

    if (value.updated()) {
        object[QStringLiteral("updated")] = QString::number(*value.updated());
    }

    if (value.deleted()) {
        object[QStringLiteral("deleted")] = QString::number(*value.deleted());
    }

    if (value.active()) {
        object[QStringLiteral("active")] = *value.active();
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.notebookGuid()) {
        object[QStringLiteral("notebookGuid")] = *value.notebookGuid();
    }

    if (value.tagGuids())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.tagGuids()))
        {
            array << v;
        }

        object[QStringLiteral("tagGuids")] = array;
    }

    if (value.resources())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.resources()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("resources")] = array;
    }

    if (value.attributes()) {
        object[QStringLiteral("attributes")] = serializeToJson(*value.attributes());
    }

    if (value.tagNames())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.tagNames()))
        {
            array << v;
        }

        object[QStringLiteral("tagNames")] = array;
    }

    if (value.sharedNotes())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.sharedNotes()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("sharedNotes")] = array;
    }

    if (value.restrictions()) {
        object[QStringLiteral("restrictions")] = serializeToJson(*value.restrictions());
    }

    if (value.limits()) {
        object[QStringLiteral("limits")] = serializeToJson(*value.limits());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Note & value)
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

    if (object.contains(QStringLiteral("notebookLocalId"))) {
        const auto v = object[QStringLiteral("notebookLocalId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookLocalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("tagLocalIds"))) {
        const auto v = object[QStringLiteral("tagLocalIds")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setTagLocalIds(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("thumbnailData"))) {
        const auto v = object[QStringLiteral("thumbnailData")];
        if (v.isString()) {
            auto s = v.toString();
            value.setThumbnailData(QByteArray::fromBase64(s.toUtf8()));
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

    if (object.contains(QStringLiteral("title"))) {
        const auto v = object[QStringLiteral("title")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTitle(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("content"))) {
        const auto v = object[QStringLiteral("content")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContent(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contentHash"))) {
        const auto v = object[QStringLiteral("contentHash")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContentHash(QByteArray::fromBase64(s.toUtf8()));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contentLength"))) {
        const auto v = object[QStringLiteral("contentLength")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setContentLength(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("created"))) {
        const auto v = object[QStringLiteral("created")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setCreated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updated"))) {
        const auto v = object[QStringLiteral("updated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("deleted"))) {
        const auto v = object[QStringLiteral("deleted")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setDeleted(i);
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

    if (object.contains(QStringLiteral("notebookGuid"))) {
        const auto v = object[QStringLiteral("notebookGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("tagGuids"))) {
        const auto v = object[QStringLiteral("tagGuids")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setTagGuids(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("resources"))) {
        const auto v = object[QStringLiteral("resources")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Resource> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Resource f;
                    if (deserializeFromJson(o, f)) {
                        values.push_back(std::move(f));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setResources(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("attributes"))) {
        const auto v = object[QStringLiteral("attributes")];
        if (v.isObject()) {
            auto o = v.toObject();
            NoteAttributes f;
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

    if (object.contains(QStringLiteral("tagNames"))) {
        const auto v = object[QStringLiteral("tagNames")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setTagNames(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharedNotes"))) {
        const auto v = object[QStringLiteral("sharedNotes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<SharedNote> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    SharedNote f;
                    if (deserializeFromJson(o, f)) {
                        values.push_back(std::move(f));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setSharedNotes(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("restrictions"))) {
        const auto v = object[QStringLiteral("restrictions")];
        if (v.isObject()) {
            auto o = v.toObject();
            NoteRestrictions f;
            if (deserializeFromJson(o, f)) {
                value.setRestrictions(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("limits"))) {
        const auto v = object[QStringLiteral("limits")];
        if (v.isObject()) {
            auto o = v.toObject();
            NoteLimits f;
            if (deserializeFromJson(o, f)) {
                value.setLimits(std::move(f));
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
