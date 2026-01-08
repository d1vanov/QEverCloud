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

#include <qevercloud/serialization/json/SyncChunkFilter.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const SyncChunkFilter & value)
{
    QJsonObject object;

    if (value.includeNotes()) {
        object[QStringLiteral("includeNotes")] = *value.includeNotes();
    }

    if (value.includeNoteResources()) {
        object[QStringLiteral("includeNoteResources")] = *value.includeNoteResources();
    }

    if (value.includeNoteAttributes()) {
        object[QStringLiteral("includeNoteAttributes")] = *value.includeNoteAttributes();
    }

    if (value.includeNotebooks()) {
        object[QStringLiteral("includeNotebooks")] = *value.includeNotebooks();
    }

    if (value.includeTags()) {
        object[QStringLiteral("includeTags")] = *value.includeTags();
    }

    if (value.includeSearches()) {
        object[QStringLiteral("includeSearches")] = *value.includeSearches();
    }

    if (value.includeResources()) {
        object[QStringLiteral("includeResources")] = *value.includeResources();
    }

    if (value.includeLinkedNotebooks()) {
        object[QStringLiteral("includeLinkedNotebooks")] = *value.includeLinkedNotebooks();
    }

    if (value.includeExpunged()) {
        object[QStringLiteral("includeExpunged")] = *value.includeExpunged();
    }

    if (value.includeNoteApplicationDataFullMap()) {
        object[QStringLiteral("includeNoteApplicationDataFullMap")] = *value.includeNoteApplicationDataFullMap();
    }

    if (value.includeResourceApplicationDataFullMap()) {
        object[QStringLiteral("includeResourceApplicationDataFullMap")] = *value.includeResourceApplicationDataFullMap();
    }

    if (value.includeNoteResourceApplicationDataFullMap()) {
        object[QStringLiteral("includeNoteResourceApplicationDataFullMap")] = *value.includeNoteResourceApplicationDataFullMap();
    }

    if (value.includeSharedNotes()) {
        object[QStringLiteral("includeSharedNotes")] = *value.includeSharedNotes();
    }

    if (value.omitSharedNotebooks()) {
        object[QStringLiteral("omitSharedNotebooks")] = *value.omitSharedNotebooks();
    }

    if (value.requireNoteContentClass()) {
        object[QStringLiteral("requireNoteContentClass")] = *value.requireNoteContentClass();
    }

    if (value.notebookGuids())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.notebookGuids()))
        {
            array << v;
        }

        object[QStringLiteral("notebookGuids")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SyncChunkFilter & value)
{
    if (object.contains(QStringLiteral("includeNotes"))) {
        const auto v = object[QStringLiteral("includeNotes")];
        if (v.isBool()) {
            value.setIncludeNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNoteResources"))) {
        const auto v = object[QStringLiteral("includeNoteResources")];
        if (v.isBool()) {
            value.setIncludeNoteResources(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNoteAttributes"))) {
        const auto v = object[QStringLiteral("includeNoteAttributes")];
        if (v.isBool()) {
            value.setIncludeNoteAttributes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNotebooks"))) {
        const auto v = object[QStringLiteral("includeNotebooks")];
        if (v.isBool()) {
            value.setIncludeNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeTags"))) {
        const auto v = object[QStringLiteral("includeTags")];
        if (v.isBool()) {
            value.setIncludeTags(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeSearches"))) {
        const auto v = object[QStringLiteral("includeSearches")];
        if (v.isBool()) {
            value.setIncludeSearches(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResources"))) {
        const auto v = object[QStringLiteral("includeResources")];
        if (v.isBool()) {
            value.setIncludeResources(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeLinkedNotebooks"))) {
        const auto v = object[QStringLiteral("includeLinkedNotebooks")];
        if (v.isBool()) {
            value.setIncludeLinkedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeExpunged"))) {
        const auto v = object[QStringLiteral("includeExpunged")];
        if (v.isBool()) {
            value.setIncludeExpunged(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNoteApplicationDataFullMap"))) {
        const auto v = object[QStringLiteral("includeNoteApplicationDataFullMap")];
        if (v.isBool()) {
            value.setIncludeNoteApplicationDataFullMap(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResourceApplicationDataFullMap"))) {
        const auto v = object[QStringLiteral("includeResourceApplicationDataFullMap")];
        if (v.isBool()) {
            value.setIncludeResourceApplicationDataFullMap(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNoteResourceApplicationDataFullMap"))) {
        const auto v = object[QStringLiteral("includeNoteResourceApplicationDataFullMap")];
        if (v.isBool()) {
            value.setIncludeNoteResourceApplicationDataFullMap(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeSharedNotes"))) {
        const auto v = object[QStringLiteral("includeSharedNotes")];
        if (v.isBool()) {
            value.setIncludeSharedNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("omitSharedNotebooks"))) {
        const auto v = object[QStringLiteral("omitSharedNotebooks")];
        if (v.isBool()) {
            value.setOmitSharedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("requireNoteContentClass"))) {
        const auto v = object[QStringLiteral("requireNoteContentClass")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRequireNoteContentClass(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notebookGuids"))) {
        const auto v = object[QStringLiteral("notebookGuids")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QSet<QString> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.insert(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setNotebookGuids(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
