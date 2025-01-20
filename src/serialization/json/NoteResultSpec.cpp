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

#include <qevercloud/serialization/json/NoteResultSpec.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteResultSpec & value)
{
    QJsonObject object;

    if (value.includeContent()) {
        object[QStringLiteral("includeContent")] = *value.includeContent();
    }

    if (value.includeResourcesData()) {
        object[QStringLiteral("includeResourcesData")] = *value.includeResourcesData();
    }

    if (value.includeResourcesRecognition()) {
        object[QStringLiteral("includeResourcesRecognition")] = *value.includeResourcesRecognition();
    }

    if (value.includeResourcesAlternateData()) {
        object[QStringLiteral("includeResourcesAlternateData")] = *value.includeResourcesAlternateData();
    }

    if (value.includeSharedNotes()) {
        object[QStringLiteral("includeSharedNotes")] = *value.includeSharedNotes();
    }

    if (value.includeNoteAppDataValues()) {
        object[QStringLiteral("includeNoteAppDataValues")] = *value.includeNoteAppDataValues();
    }

    if (value.includeResourceAppDataValues()) {
        object[QStringLiteral("includeResourceAppDataValues")] = *value.includeResourceAppDataValues();
    }

    if (value.includeAccountLimits()) {
        object[QStringLiteral("includeAccountLimits")] = *value.includeAccountLimits();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteResultSpec & value)
{
    if (object.contains(QStringLiteral("includeContent"))) {
        const auto v = object[QStringLiteral("includeContent")];
        if (v.isBool()) {
            value.setIncludeContent(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResourcesData"))) {
        const auto v = object[QStringLiteral("includeResourcesData")];
        if (v.isBool()) {
            value.setIncludeResourcesData(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResourcesRecognition"))) {
        const auto v = object[QStringLiteral("includeResourcesRecognition")];
        if (v.isBool()) {
            value.setIncludeResourcesRecognition(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResourcesAlternateData"))) {
        const auto v = object[QStringLiteral("includeResourcesAlternateData")];
        if (v.isBool()) {
            value.setIncludeResourcesAlternateData(v.toBool());
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

    if (object.contains(QStringLiteral("includeNoteAppDataValues"))) {
        const auto v = object[QStringLiteral("includeNoteAppDataValues")];
        if (v.isBool()) {
            value.setIncludeNoteAppDataValues(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeResourceAppDataValues"))) {
        const auto v = object[QStringLiteral("includeResourceAppDataValues")];
        if (v.isBool()) {
            value.setIncludeResourceAppDataValues(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeAccountLimits"))) {
        const auto v = object[QStringLiteral("includeAccountLimits")];
        if (v.isBool()) {
            value.setIncludeAccountLimits(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
