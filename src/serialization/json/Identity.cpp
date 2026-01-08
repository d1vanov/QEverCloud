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

#include <qevercloud/serialization/json/Identity.h>

#include <qevercloud/serialization/json/Contact.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const Identity & value)
{
    QJsonObject object;

    object[QStringLiteral("id")] = QString::number(value.id());
    if (value.contact()) {
        object[QStringLiteral("contact")] = serializeToJson(*value.contact());
    }

    if (value.userId()) {
        object[QStringLiteral("userId")] = *value.userId();
    }

    if (value.deactivated()) {
        object[QStringLiteral("deactivated")] = *value.deactivated();
    }

    if (value.sameBusiness()) {
        object[QStringLiteral("sameBusiness")] = *value.sameBusiness();
    }

    if (value.blocked()) {
        object[QStringLiteral("blocked")] = *value.blocked();
    }

    if (value.userConnected()) {
        object[QStringLiteral("userConnected")] = *value.userConnected();
    }

    if (value.eventId()) {
        object[QStringLiteral("eventId")] = QString::number(*value.eventId());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Identity & value)
{
    if (object.contains(QStringLiteral("id"))) {
        const auto v = object[QStringLiteral("id")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setId(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contact"))) {
        const auto v = object[QStringLiteral("contact")];
        if (v.isObject()) {
            auto o = v.toObject();
            Contact f;
            if (deserializeFromJson(o, f)) {
                value.setContact(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userId"))) {
        const auto v = object[QStringLiteral("userId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("deactivated"))) {
        const auto v = object[QStringLiteral("deactivated")];
        if (v.isBool()) {
            value.setDeactivated(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sameBusiness"))) {
        const auto v = object[QStringLiteral("sameBusiness")];
        if (v.isBool()) {
            value.setSameBusiness(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("blocked"))) {
        const auto v = object[QStringLiteral("blocked")];
        if (v.isBool()) {
            value.setBlocked(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userConnected"))) {
        const auto v = object[QStringLiteral("userConnected")];
        if (v.isBool()) {
            value.setUserConnected(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("eventId"))) {
        const auto v = object[QStringLiteral("eventId")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setEventId(i);
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
