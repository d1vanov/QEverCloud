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

#include <qevercloud/serialization/json/NoteVersionId.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteVersionId & value)
{
    QJsonObject object;

    object[QStringLiteral("updateSequenceNum")] = value.updateSequenceNum();
    object[QStringLiteral("updated")] = QString::number(value.updated());
    object[QStringLiteral("saved")] = QString::number(value.saved());
    object[QStringLiteral("title")] = value.title();
    if (value.lastEditorId()) {
        object[QStringLiteral("lastEditorId")] = *value.lastEditorId();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteVersionId & value)
{
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

    if (object.contains(QStringLiteral("saved"))) {
        const auto v = object[QStringLiteral("saved")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setSaved(i);
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

    return true;
}

} // namespace qevercloud
