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

#include <qevercloud/serialization/json/UserProfile.h>

#include <qevercloud/serialization/json/BusinessUserAttributes.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<BusinessUserRole> safeCastBusinessUserRoleToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(BusinessUserRole::ADMIN):
        return BusinessUserRole::ADMIN;
    case static_cast<qint64>(BusinessUserRole::NORMAL):
        return BusinessUserRole::NORMAL;
    default:
        return std::nullopt;
    }
}

[[nodiscard]] std::optional<BusinessUserStatus> safeCastBusinessUserStatusToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(BusinessUserStatus::ACTIVE):
        return BusinessUserStatus::ACTIVE;
    case static_cast<qint64>(BusinessUserStatus::DEACTIVATED):
        return BusinessUserStatus::DEACTIVATED;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const UserProfile & value)
{
    QJsonObject object;

    if (value.id()) {
        object[QStringLiteral("id")] = *value.id();
    }

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.email()) {
        object[QStringLiteral("email")] = *value.email();
    }

    if (value.username()) {
        object[QStringLiteral("username")] = *value.username();
    }

    if (value.attributes()) {
        object[QStringLiteral("attributes")] = serializeToJson(*value.attributes());
    }

    if (value.joined()) {
        object[QStringLiteral("joined")] = QString::number(*value.joined());
    }

    if (value.photoLastUpdated()) {
        object[QStringLiteral("photoLastUpdated")] = QString::number(*value.photoLastUpdated());
    }

    if (value.photoUrl()) {
        object[QStringLiteral("photoUrl")] = *value.photoUrl();
    }

    if (value.role()) {
        object[QStringLiteral("role")] = QString::number(static_cast<qint64>(*value.role()));
    }

    if (value.status()) {
        object[QStringLiteral("status")] = QString::number(static_cast<qint64>(*value.status()));
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, UserProfile & value)
{
    if (object.contains(QStringLiteral("id"))) {
        const auto v = object[QStringLiteral("id")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("name"))) {
        const auto v = object[QStringLiteral("name")];
        if (v.isString()) {
            auto s = v.toString();
            value.setName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("email"))) {
        const auto v = object[QStringLiteral("email")];
        if (v.isString()) {
            auto s = v.toString();
            value.setEmail(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("username"))) {
        const auto v = object[QStringLiteral("username")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUsername(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("attributes"))) {
        const auto v = object[QStringLiteral("attributes")];
        if (v.isObject()) {
            auto o = v.toObject();
            BusinessUserAttributes f;
            if (deserializeFromJson(o, f)) {
                value.setAttributes(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("joined"))) {
        const auto v = object[QStringLiteral("joined")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setJoined(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("photoLastUpdated"))) {
        const auto v = object[QStringLiteral("photoLastUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setPhotoLastUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("photoUrl"))) {
        const auto v = object[QStringLiteral("photoUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPhotoUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("role"))) {
        const auto v = object[QStringLiteral("role")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastBusinessUserRoleToEnum(i);
            if (e) {
                value.setRole(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("status"))) {
        const auto v = object[QStringLiteral("status")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastBusinessUserStatusToEnum(i);
            if (e) {
                value.setStatus(*e);
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
