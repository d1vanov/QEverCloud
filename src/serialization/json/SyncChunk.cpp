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

#include <qevercloud/serialization/json/SyncChunk.h>

#include <qevercloud/serialization/json/LinkedNotebook.h>
#include <qevercloud/serialization/json/Note.h>
#include <qevercloud/serialization/json/Notebook.h>
#include <qevercloud/serialization/json/Resource.h>
#include <qevercloud/serialization/json/SavedSearch.h>
#include <qevercloud/serialization/json/Tag.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const SyncChunk & value)
{
    QJsonObject object;

    object[QStringLiteral("currentTime")] = QString::number(value.currentTime());
    if (value.chunkHighUSN()) {
        object[QStringLiteral("chunkHighUSN")] = *value.chunkHighUSN();
    }

    object[QStringLiteral("updateCount")] = value.updateCount();
    if (value.notes())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.notes()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("notes")] = array;
    }

    if (value.notebooks())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.notebooks()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("notebooks")] = array;
    }

    if (value.tags())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.tags()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("tags")] = array;
    }

    if (value.searches())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.searches()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("searches")] = array;
    }

    if (value.resources())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.resources()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("resources")] = array;
    }

    if (value.expungedNotes())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.expungedNotes()))
        {
            array << v;
        }

        object[QStringLiteral("expungedNotes")] = array;
    }

    if (value.expungedNotebooks())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.expungedNotebooks()))
        {
            array << v;
        }

        object[QStringLiteral("expungedNotebooks")] = array;
    }

    if (value.expungedTags())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.expungedTags()))
        {
            array << v;
        }

        object[QStringLiteral("expungedTags")] = array;
    }

    if (value.expungedSearches())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.expungedSearches()))
        {
            array << v;
        }

        object[QStringLiteral("expungedSearches")] = array;
    }

    if (value.linkedNotebooks())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.linkedNotebooks()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("linkedNotebooks")] = array;
    }

    if (value.expungedLinkedNotebooks())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.expungedLinkedNotebooks()))
        {
            array << v;
        }

        object[QStringLiteral("expungedLinkedNotebooks")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SyncChunk & value)
{
    if (object.contains(QStringLiteral("currentTime"))) {
        const auto v = object[QStringLiteral("currentTime")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setCurrentTime(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("chunkHighUSN"))) {
        const auto v = object[QStringLiteral("chunkHighUSN")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setChunkHighUSN(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updateCount"))) {
        const auto v = object[QStringLiteral("updateCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUpdateCount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notes"))) {
        const auto v = object[QStringLiteral("notes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Note> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Note f;
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
            value.setNotes(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notebooks"))) {
        const auto v = object[QStringLiteral("notebooks")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Notebook> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Notebook f;
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
            value.setNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("tags"))) {
        const auto v = object[QStringLiteral("tags")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Tag> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Tag f;
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
            value.setTags(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("searches"))) {
        const auto v = object[QStringLiteral("searches")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<SavedSearch> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    SavedSearch f;
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
            value.setSearches(std::move(values));
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
            for (const auto & item: qAsConst(a)) {
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

    if (object.contains(QStringLiteral("expungedNotes"))) {
        const auto v = object[QStringLiteral("expungedNotes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setExpungedNotes(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("expungedNotebooks"))) {
        const auto v = object[QStringLiteral("expungedNotebooks")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setExpungedNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("expungedTags"))) {
        const auto v = object[QStringLiteral("expungedTags")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setExpungedTags(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("expungedSearches"))) {
        const auto v = object[QStringLiteral("expungedSearches")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setExpungedSearches(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("linkedNotebooks"))) {
        const auto v = object[QStringLiteral("linkedNotebooks")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<LinkedNotebook> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    LinkedNotebook f;
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
            value.setLinkedNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("expungedLinkedNotebooks"))) {
        const auto v = object[QStringLiteral("expungedLinkedNotebooks")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setExpungedLinkedNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
