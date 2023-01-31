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

#include <qevercloud/serialization/json/NoteInvitationShareRelationship.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<SharedNotePrivilegeLevel> safeCastSharedNotePrivilegeLevelToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(SharedNotePrivilegeLevel::READ_NOTE):
        return SharedNotePrivilegeLevel::READ_NOTE;
    case static_cast<qint64>(SharedNotePrivilegeLevel::MODIFY_NOTE):
        return SharedNotePrivilegeLevel::MODIFY_NOTE;
    case static_cast<qint64>(SharedNotePrivilegeLevel::FULL_ACCESS):
        return SharedNotePrivilegeLevel::FULL_ACCESS;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const NoteInvitationShareRelationship & value)
{
    QJsonObject object;

    if (value.displayName()) {
        object[QStringLiteral("displayName")] = *value.displayName();
    }

    if (value.recipientIdentityId()) {
        object[QStringLiteral("recipientIdentityId")] = QString::number(*value.recipientIdentityId());
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    if (value.sharerUserId()) {
        object[QStringLiteral("sharerUserId")] = *value.sharerUserId();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteInvitationShareRelationship & value)
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

    if (object.contains(QStringLiteral("recipientIdentityId"))) {
        const auto v = object[QStringLiteral("recipientIdentityId")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setRecipientIdentityId(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("privilege"))) {
        const auto v = object[QStringLiteral("privilege")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastSharedNotePrivilegeLevelToEnum(i);
            if (e) {
                value.setPrivilege(*e);
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
