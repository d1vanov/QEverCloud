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

#include <qevercloud/serialization/json/RelatedResult.h>

#include <qevercloud/serialization/json/Note.h>
#include <qevercloud/serialization/json/Notebook.h>
#include <qevercloud/serialization/json/NotebookDescriptor.h>
#include <qevercloud/serialization/json/RelatedContent.h>
#include <qevercloud/serialization/json/Tag.h>
#include <qevercloud/serialization/json/UserProfile.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const RelatedResult & value)
{
    QJsonObject object;

    if (value.notes())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.notes()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("notes")] = array;
    }

    if (value.notebooks())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.notebooks()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("notebooks")] = array;
    }

    if (value.tags())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.tags()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("tags")] = array;
    }

    if (value.containingNotebooks())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.containingNotebooks()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("containingNotebooks")] = array;
    }

    if (value.debugInfo()) {
        object[QStringLiteral("debugInfo")] = *value.debugInfo();
    }

    if (value.experts())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.experts()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("experts")] = array;
    }

    if (value.relatedContent())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.relatedContent()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("relatedContent")] = array;
    }

    if (value.cacheKey()) {
        object[QStringLiteral("cacheKey")] = *value.cacheKey();
    }

    if (value.cacheExpires()) {
        object[QStringLiteral("cacheExpires")] = *value.cacheExpires();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, RelatedResult & value)
{
    if (object.contains(QStringLiteral("notes"))) {
        const auto v = object[QStringLiteral("notes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Note> values;
            for (const auto & item: std::as_const(a)) {
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
            for (const auto & item: std::as_const(a)) {
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
            for (const auto & item: std::as_const(a)) {
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

    if (object.contains(QStringLiteral("containingNotebooks"))) {
        const auto v = object[QStringLiteral("containingNotebooks")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<NotebookDescriptor> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    NotebookDescriptor f;
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
            value.setContainingNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("debugInfo"))) {
        const auto v = object[QStringLiteral("debugInfo")];
        if (v.isString()) {
            auto s = v.toString();
            value.setDebugInfo(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("experts"))) {
        const auto v = object[QStringLiteral("experts")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<UserProfile> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    UserProfile f;
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
            value.setExperts(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("relatedContent"))) {
        const auto v = object[QStringLiteral("relatedContent")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<RelatedContent> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    RelatedContent f;
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
            value.setRelatedContent(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("cacheKey"))) {
        const auto v = object[QStringLiteral("cacheKey")];
        if (v.isString()) {
            auto s = v.toString();
            value.setCacheKey(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("cacheExpires"))) {
        const auto v = object[QStringLiteral("cacheExpires")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setCacheExpires(static_cast<qint32>(d));
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
