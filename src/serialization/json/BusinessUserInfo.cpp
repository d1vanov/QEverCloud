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

#include <qevercloud/serialization/json/BusinessUserInfo.h>

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

} // namespace

QJsonObject serializeToJson(const BusinessUserInfo & value)
{
    QJsonObject object;

    if (value.businessId()) {
        object[QStringLiteral("businessId")] = *value.businessId();
    }

    if (value.businessName()) {
        object[QStringLiteral("businessName")] = *value.businessName();
    }

    if (value.role()) {
        object[QStringLiteral("role")] = QString::number(static_cast<qint64>(*value.role()));
    }

    if (value.email()) {
        object[QStringLiteral("email")] = *value.email();
    }

    if (value.updated()) {
        object[QStringLiteral("updated")] = *value.updated();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BusinessUserInfo & value)
{
    if (object.contains(QStringLiteral("businessId"))) {
        const auto v = object[QStringLiteral("businessId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setBusinessId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessName"))) {
        const auto v = object[QStringLiteral("businessName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setBusinessName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("role"))) {
        const auto v = object[QStringLiteral("role")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastBusinessUserRoleToEnum(static_cast<qint64>(d));
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

    if (object.contains(QStringLiteral("updated"))) {
        const auto v = object[QStringLiteral("updated")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setUpdated(static_cast<qint64>(d));
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
