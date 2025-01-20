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

#include <qevercloud/serialization/json/SyncState.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const SyncState & value)
{
    QJsonObject object;

    object[QStringLiteral("currentTime")] = QString::number(value.currentTime());
    object[QStringLiteral("fullSyncBefore")] = QString::number(value.fullSyncBefore());
    object[QStringLiteral("updateCount")] = value.updateCount();
    if (value.uploaded()) {
        object[QStringLiteral("uploaded")] = QString::number(*value.uploaded());
    }

    if (value.userLastUpdated()) {
        object[QStringLiteral("userLastUpdated")] = QString::number(*value.userLastUpdated());
    }

    if (value.userMaxMessageEventId()) {
        object[QStringLiteral("userMaxMessageEventId")] = QString::number(*value.userMaxMessageEventId());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SyncState & value)
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

    if (object.contains(QStringLiteral("fullSyncBefore"))) {
        const auto v = object[QStringLiteral("fullSyncBefore")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setFullSyncBefore(i);
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

    if (object.contains(QStringLiteral("userLastUpdated"))) {
        const auto v = object[QStringLiteral("userLastUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUserLastUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userMaxMessageEventId"))) {
        const auto v = object[QStringLiteral("userMaxMessageEventId")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUserMaxMessageEventId(i);
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
