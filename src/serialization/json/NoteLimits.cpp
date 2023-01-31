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

#include <qevercloud/serialization/json/NoteLimits.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteLimits & value)
{
    QJsonObject object;

    if (value.noteResourceCountMax()) {
        object[QStringLiteral("noteResourceCountMax")] = *value.noteResourceCountMax();
    }

    if (value.uploadLimit()) {
        object[QStringLiteral("uploadLimit")] = QString::number(*value.uploadLimit());
    }

    if (value.resourceSizeMax()) {
        object[QStringLiteral("resourceSizeMax")] = QString::number(*value.resourceSizeMax());
    }

    if (value.noteSizeMax()) {
        object[QStringLiteral("noteSizeMax")] = QString::number(*value.noteSizeMax());
    }

    if (value.uploaded()) {
        object[QStringLiteral("uploaded")] = QString::number(*value.uploaded());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteLimits & value)
{
    if (object.contains(QStringLiteral("noteResourceCountMax"))) {
        const auto v = object[QStringLiteral("noteResourceCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setNoteResourceCountMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("uploadLimit"))) {
        const auto v = object[QStringLiteral("uploadLimit")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUploadLimit(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("resourceSizeMax"))) {
        const auto v = object[QStringLiteral("resourceSizeMax")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setResourceSizeMax(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteSizeMax"))) {
        const auto v = object[QStringLiteral("noteSizeMax")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setNoteSizeMax(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("uploaded"))) {
        const auto v = object[QStringLiteral("uploaded")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUploaded(i);
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
