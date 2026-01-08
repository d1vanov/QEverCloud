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

#include <qevercloud/serialization/json/PublicUserInfo.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<ServiceLevel> safeCastServiceLevelToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(ServiceLevel::BASIC):
        return ServiceLevel::BASIC;
    case static_cast<qint64>(ServiceLevel::PLUS):
        return ServiceLevel::PLUS;
    case static_cast<qint64>(ServiceLevel::PREMIUM):
        return ServiceLevel::PREMIUM;
    case static_cast<qint64>(ServiceLevel::BUSINESS):
        return ServiceLevel::BUSINESS;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const PublicUserInfo & value)
{
    QJsonObject object;

    object[QStringLiteral("userId")] = value.userId();
    if (value.serviceLevel()) {
        object[QStringLiteral("serviceLevel")] = QString::number(static_cast<qint64>(*value.serviceLevel()));
    }

    if (value.username()) {
        object[QStringLiteral("username")] = *value.username();
    }

    if (value.noteStoreUrl()) {
        object[QStringLiteral("noteStoreUrl")] = *value.noteStoreUrl();
    }

    if (value.webApiUrlPrefix()) {
        object[QStringLiteral("webApiUrlPrefix")] = *value.webApiUrlPrefix();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, PublicUserInfo & value)
{
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

    if (object.contains(QStringLiteral("serviceLevel"))) {
        const auto v = object[QStringLiteral("serviceLevel")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastServiceLevelToEnum(i);
            if (e) {
                value.setServiceLevel(*e);
            }
            else {
                return false;
            }
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

    if (object.contains(QStringLiteral("noteStoreUrl"))) {
        const auto v = object[QStringLiteral("noteStoreUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteStoreUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("webApiUrlPrefix"))) {
        const auto v = object[QStringLiteral("webApiUrlPrefix")];
        if (v.isString()) {
            auto s = v.toString();
            value.setWebApiUrlPrefix(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
