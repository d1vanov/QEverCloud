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

#include <qevercloud/serialization/json/RelatedQuery.h>

#include <qevercloud/serialization/json/NoteFilter.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const RelatedQuery & value)
{
    QJsonObject object;

    if (value.noteGuid()) {
        object[QStringLiteral("noteGuid")] = *value.noteGuid();
    }

    if (value.plainText()) {
        object[QStringLiteral("plainText")] = *value.plainText();
    }

    if (value.filter()) {
        object[QStringLiteral("filter")] = serializeToJson(*value.filter());
    }

    if (value.referenceUri()) {
        object[QStringLiteral("referenceUri")] = *value.referenceUri();
    }

    if (value.context()) {
        object[QStringLiteral("context")] = *value.context();
    }

    if (value.cacheKey()) {
        object[QStringLiteral("cacheKey")] = *value.cacheKey();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, RelatedQuery & value)
{
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

    if (object.contains(QStringLiteral("plainText"))) {
        const auto v = object[QStringLiteral("plainText")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPlainText(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("filter"))) {
        const auto v = object[QStringLiteral("filter")];
        if (v.isObject()) {
            auto o = v.toObject();
            NoteFilter f;
            if (deserializeFromJson(o, f)) {
                value.setFilter(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("referenceUri"))) {
        const auto v = object[QStringLiteral("referenceUri")];
        if (v.isString()) {
            auto s = v.toString();
            value.setReferenceUri(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("context"))) {
        const auto v = object[QStringLiteral("context")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContext(std::move(s));
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

    return true;
}

} // namespace qevercloud
