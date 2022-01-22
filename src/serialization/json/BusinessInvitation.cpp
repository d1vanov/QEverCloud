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

#include <qevercloud/serialization/json/BusinessInvitation.h>

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

[[nodiscard]] std::optional<BusinessInvitationStatus> safeCastBusinessInvitationStatusToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(BusinessInvitationStatus::APPROVED):
        return BusinessInvitationStatus::APPROVED;
    case static_cast<qint64>(BusinessInvitationStatus::REQUESTED):
        return BusinessInvitationStatus::REQUESTED;
    case static_cast<qint64>(BusinessInvitationStatus::REDEEMED):
        return BusinessInvitationStatus::REDEEMED;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const BusinessInvitation & value)
{
    QJsonObject object;

    if (value.businessId()) {
        object[QStringLiteral("businessId")] = *value.businessId();
    }

    if (value.email()) {
        object[QStringLiteral("email")] = *value.email();
    }

    if (value.role()) {
        object[QStringLiteral("role")] = QString::number(static_cast<qint64>(*value.role()));
    }

    if (value.status()) {
        object[QStringLiteral("status")] = QString::number(static_cast<qint64>(*value.status()));
    }

    if (value.requesterId()) {
        object[QStringLiteral("requesterId")] = *value.requesterId();
    }

    if (value.fromWorkChat()) {
        object[QStringLiteral("fromWorkChat")] = *value.fromWorkChat();
    }

    if (value.created()) {
        object[QStringLiteral("created")] = *value.created();
    }

    if (value.mostRecentReminder()) {
        object[QStringLiteral("mostRecentReminder")] = *value.mostRecentReminder();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BusinessInvitation & value)
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

    if (object.contains(QStringLiteral("status"))) {
        const auto v = object[QStringLiteral("status")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastBusinessInvitationStatusToEnum(static_cast<qint64>(d));
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
    }

    if (object.contains(QStringLiteral("requesterId"))) {
        const auto v = object[QStringLiteral("requesterId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setRequesterId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("fromWorkChat"))) {
        const auto v = object[QStringLiteral("fromWorkChat")];
        if (v.isBool()) {
            value.setFromWorkChat(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("created"))) {
        const auto v = object[QStringLiteral("created")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setCreated(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("mostRecentReminder"))) {
        const auto v = object[QStringLiteral("mostRecentReminder")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setMostRecentReminder(static_cast<qint64>(d));
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
