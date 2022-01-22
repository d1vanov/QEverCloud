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

#include <qevercloud/serialization/json/NotesMetadataResultSpec.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NotesMetadataResultSpec & value)
{
    QJsonObject object;

    if (value.includeTitle()) {
        object[QStringLiteral("includeTitle")] = *value.includeTitle();
    }

    if (value.includeContentLength()) {
        object[QStringLiteral("includeContentLength")] = *value.includeContentLength();
    }

    if (value.includeCreated()) {
        object[QStringLiteral("includeCreated")] = *value.includeCreated();
    }

    if (value.includeUpdated()) {
        object[QStringLiteral("includeUpdated")] = *value.includeUpdated();
    }

    if (value.includeDeleted()) {
        object[QStringLiteral("includeDeleted")] = *value.includeDeleted();
    }

    if (value.includeUpdateSequenceNum()) {
        object[QStringLiteral("includeUpdateSequenceNum")] = *value.includeUpdateSequenceNum();
    }

    if (value.includeNotebookGuid()) {
        object[QStringLiteral("includeNotebookGuid")] = *value.includeNotebookGuid();
    }

    if (value.includeTagGuids()) {
        object[QStringLiteral("includeTagGuids")] = *value.includeTagGuids();
    }

    if (value.includeAttributes()) {
        object[QStringLiteral("includeAttributes")] = *value.includeAttributes();
    }

    if (value.includeLargestResourceMime()) {
        object[QStringLiteral("includeLargestResourceMime")] = *value.includeLargestResourceMime();
    }

    if (value.includeLargestResourceSize()) {
        object[QStringLiteral("includeLargestResourceSize")] = *value.includeLargestResourceSize();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NotesMetadataResultSpec & value)
{
    if (object.contains(QStringLiteral("includeTitle"))) {
        const auto v = object[QStringLiteral("includeTitle")];
        if (v.isBool()) {
            value.setIncludeTitle(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeContentLength"))) {
        const auto v = object[QStringLiteral("includeContentLength")];
        if (v.isBool()) {
            value.setIncludeContentLength(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeCreated"))) {
        const auto v = object[QStringLiteral("includeCreated")];
        if (v.isBool()) {
            value.setIncludeCreated(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeUpdated"))) {
        const auto v = object[QStringLiteral("includeUpdated")];
        if (v.isBool()) {
            value.setIncludeUpdated(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeDeleted"))) {
        const auto v = object[QStringLiteral("includeDeleted")];
        if (v.isBool()) {
            value.setIncludeDeleted(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeUpdateSequenceNum"))) {
        const auto v = object[QStringLiteral("includeUpdateSequenceNum")];
        if (v.isBool()) {
            value.setIncludeUpdateSequenceNum(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeNotebookGuid"))) {
        const auto v = object[QStringLiteral("includeNotebookGuid")];
        if (v.isBool()) {
            value.setIncludeNotebookGuid(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeTagGuids"))) {
        const auto v = object[QStringLiteral("includeTagGuids")];
        if (v.isBool()) {
            value.setIncludeTagGuids(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeAttributes"))) {
        const auto v = object[QStringLiteral("includeAttributes")];
        if (v.isBool()) {
            value.setIncludeAttributes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeLargestResourceMime"))) {
        const auto v = object[QStringLiteral("includeLargestResourceMime")];
        if (v.isBool()) {
            value.setIncludeLargestResourceMime(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeLargestResourceSize"))) {
        const auto v = object[QStringLiteral("includeLargestResourceSize")];
        if (v.isBool()) {
            value.setIncludeLargestResourceSize(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
