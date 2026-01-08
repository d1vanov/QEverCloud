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

#include <qevercloud/serialization/json/UpdateNoteIfUsnMatchesResult.h>

#include <qevercloud/serialization/json/Note.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const UpdateNoteIfUsnMatchesResult & value)
{
    QJsonObject object;

    if (value.note()) {
        object[QStringLiteral("note")] = serializeToJson(*value.note());
    }

    if (value.updated()) {
        object[QStringLiteral("updated")] = *value.updated();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, UpdateNoteIfUsnMatchesResult & value)
{
    if (object.contains(QStringLiteral("note"))) {
        const auto v = object[QStringLiteral("note")];
        if (v.isObject()) {
            auto o = v.toObject();
            Note f;
            if (deserializeFromJson(o, f)) {
                value.setNote(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updated"))) {
        const auto v = object[QStringLiteral("updated")];
        if (v.isBool()) {
            value.setUpdated(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
