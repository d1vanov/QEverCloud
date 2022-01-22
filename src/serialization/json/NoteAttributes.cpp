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

#include <qevercloud/serialization/json/NoteAttributes.h>

#include <qevercloud/serialization/json/LazyMap.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteAttributes & value)
{
    QJsonObject object;

    if (value.subjectDate()) {
        object[QStringLiteral("subjectDate")] = *value.subjectDate();
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

    if (value.author()) {
        object[QStringLiteral("author")] = *value.author();
    }

    if (value.source()) {
        object[QStringLiteral("source")] = *value.source();
    }

    if (value.sourceURL()) {
        object[QStringLiteral("sourceURL")] = *value.sourceURL();
    }

    if (value.sourceApplication()) {
        object[QStringLiteral("sourceApplication")] = *value.sourceApplication();
    }

    if (value.shareDate()) {
        object[QStringLiteral("shareDate")] = *value.shareDate();
    }

    if (value.reminderOrder()) {
        object[QStringLiteral("reminderOrder")] = *value.reminderOrder();
    }

    if (value.reminderDoneTime()) {
        object[QStringLiteral("reminderDoneTime")] = *value.reminderDoneTime();
    }

    if (value.reminderTime()) {
        object[QStringLiteral("reminderTime")] = *value.reminderTime();
    }

    if (value.placeName()) {
        object[QStringLiteral("placeName")] = *value.placeName();
    }

    if (value.contentClass()) {
        object[QStringLiteral("contentClass")] = *value.contentClass();
    }

    if (value.applicationData()) {
        object[QStringLiteral("applicationData")] = serializeToJson(*value.applicationData());
    }

    if (value.lastEditedBy()) {
        object[QStringLiteral("lastEditedBy")] = *value.lastEditedBy();
    }

    if (value.classifications())
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(*value.classifications())))
        {
            subobject[it.key()] = it.value();
        }
        object[QStringLiteral("classifications")] = subobject;
    }

    if (value.creatorId()) {
        object[QStringLiteral("creatorId")] = *value.creatorId();
    }

    if (value.lastEditorId()) {
        object[QStringLiteral("lastEditorId")] = *value.lastEditorId();
    }

    if (value.sharedWithBusiness()) {
        object[QStringLiteral("sharedWithBusiness")] = *value.sharedWithBusiness();
    }

    if (value.conflictSourceNoteGuid()) {
        object[QStringLiteral("conflictSourceNoteGuid")] = *value.conflictSourceNoteGuid();
    }

    if (value.noteTitleQuality()) {
        object[QStringLiteral("noteTitleQuality")] = *value.noteTitleQuality();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteAttributes & value)
{
    if (object.contains(QStringLiteral("subjectDate"))) {
        const auto v = object[QStringLiteral("subjectDate")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setSubjectDate(static_cast<qint64>(d));
            }
            else {
                return false;
            }
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

    if (object.contains(QStringLiteral("author"))) {
        const auto v = object[QStringLiteral("author")];
        if (v.isString()) {
            auto s = v.toString();
            value.setAuthor(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("source"))) {
        const auto v = object[QStringLiteral("source")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSource(std::move(s));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("sourceApplication"))) {
        const auto v = object[QStringLiteral("sourceApplication")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceApplication(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("shareDate"))) {
        const auto v = object[QStringLiteral("shareDate")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setShareDate(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("reminderOrder"))) {
        const auto v = object[QStringLiteral("reminderOrder")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setReminderOrder(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("reminderDoneTime"))) {
        const auto v = object[QStringLiteral("reminderDoneTime")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setReminderDoneTime(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("reminderTime"))) {
        const auto v = object[QStringLiteral("reminderTime")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setReminderTime(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("placeName"))) {
        const auto v = object[QStringLiteral("placeName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPlaceName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contentClass"))) {
        const auto v = object[QStringLiteral("contentClass")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContentClass(std::move(s));
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

    if (object.contains(QStringLiteral("lastEditedBy"))) {
        const auto v = object[QStringLiteral("lastEditedBy")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLastEditedBy(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("classifications"))) {
        auto v = object[QStringLiteral("classifications")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QMap<QString, QString> map;
            for (auto it: toRange(qAsConst(o))) {
                if (it.value().isString()) {
                    auto s = it.value().toString();
                    map[it.key()] = std::move(s);
                }
                else {
                    return false;
                }
            }
            value.setClassifications(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("creatorId"))) {
        const auto v = object[QStringLiteral("creatorId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setCreatorId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("lastEditorId"))) {
        const auto v = object[QStringLiteral("lastEditorId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setLastEditorId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharedWithBusiness"))) {
        const auto v = object[QStringLiteral("sharedWithBusiness")];
        if (v.isBool()) {
            value.setSharedWithBusiness(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("conflictSourceNoteGuid"))) {
        const auto v = object[QStringLiteral("conflictSourceNoteGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setConflictSourceNoteGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteTitleQuality"))) {
        const auto v = object[QStringLiteral("noteTitleQuality")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setNoteTitleQuality(static_cast<qint32>(d));
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
