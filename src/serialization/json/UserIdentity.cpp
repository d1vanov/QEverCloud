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

#include <qevercloud/serialization/json/UserIdentity.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<UserIdentityType> safeCastUserIdentityTypeToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(UserIdentityType::EVERNOTE_USERID):
        return UserIdentityType::EVERNOTE_USERID;
    case static_cast<qint64>(UserIdentityType::EMAIL):
        return UserIdentityType::EMAIL;
    case static_cast<qint64>(UserIdentityType::IDENTITYID):
        return UserIdentityType::IDENTITYID;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const UserIdentity & value)
{
    QJsonObject object;

    if (value.type()) {
        object[QStringLiteral("type")] = QString::number(static_cast<qint64>(*value.type()));
    }

    if (value.stringIdentifier()) {
        object[QStringLiteral("stringIdentifier")] = *value.stringIdentifier();
    }

    if (value.longIdentifier()) {
        object[QStringLiteral("longIdentifier")] = *value.longIdentifier();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, UserIdentity & value)
{
    if (object.contains(QStringLiteral("type"))) {
        const auto v = object[QStringLiteral("type")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastUserIdentityTypeToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setType(*e);
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

    if (object.contains(QStringLiteral("stringIdentifier"))) {
        const auto v = object[QStringLiteral("stringIdentifier")];
        if (v.isString()) {
            auto s = v.toString();
            value.setStringIdentifier(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("longIdentifier"))) {
        const auto v = object[QStringLiteral("longIdentifier")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setLongIdentifier(static_cast<qint64>(d));
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
