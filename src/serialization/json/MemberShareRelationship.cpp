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

#include <qevercloud/serialization/json/MemberShareRelationship.h>

#include <qevercloud/serialization/json/ShareRelationshipRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<ShareRelationshipPrivilegeLevel> safeCastShareRelationshipPrivilegeLevelToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK):
        return ShareRelationshipPrivilegeLevel::READ_NOTEBOOK;
    case static_cast<qint64>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY):
        return ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY;
    case static_cast<qint64>(ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY):
        return ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY;
    case static_cast<qint64>(ShareRelationshipPrivilegeLevel::FULL_ACCESS):
        return ShareRelationshipPrivilegeLevel::FULL_ACCESS;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const MemberShareRelationship & value)
{
    QJsonObject object;

    if (value.displayName()) {
        object[QStringLiteral("displayName")] = *value.displayName();
    }

    if (value.recipientUserId()) {
        object[QStringLiteral("recipientUserId")] = *value.recipientUserId();
    }

    if (value.bestPrivilege()) {
        object[QStringLiteral("bestPrivilege")] = QString::number(static_cast<qint64>(*value.bestPrivilege()));
    }

    if (value.individualPrivilege()) {
        object[QStringLiteral("individualPrivilege")] = QString::number(static_cast<qint64>(*value.individualPrivilege()));
    }

    if (value.restrictions()) {
        object[QStringLiteral("restrictions")] = serializeToJson(*value.restrictions());
    }

    if (value.sharerUserId()) {
        object[QStringLiteral("sharerUserId")] = *value.sharerUserId();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, MemberShareRelationship & value)
{
    if (object.contains(QStringLiteral("displayName"))) {
        const auto v = object[QStringLiteral("displayName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setDisplayName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recipientUserId"))) {
        const auto v = object[QStringLiteral("recipientUserId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setRecipientUserId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("bestPrivilege"))) {
        const auto v = object[QStringLiteral("bestPrivilege")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastShareRelationshipPrivilegeLevelToEnum(i);
            if (e) {
                value.setBestPrivilege(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("individualPrivilege"))) {
        const auto v = object[QStringLiteral("individualPrivilege")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastShareRelationshipPrivilegeLevelToEnum(i);
            if (e) {
                value.setIndividualPrivilege(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("restrictions"))) {
        const auto v = object[QStringLiteral("restrictions")];
        if (v.isObject()) {
            auto o = v.toObject();
            ShareRelationshipRestrictions f;
            if (deserializeFromJson(o, f)) {
                value.setRestrictions(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharerUserId"))) {
        const auto v = object[QStringLiteral("sharerUserId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setSharerUserId(static_cast<qint32>(d));
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
