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

#include <qevercloud/serialization/json/User.h>

#include <qevercloud/serialization/json/AccountLimits.h>
#include <qevercloud/serialization/json/Accounting.h>
#include <qevercloud/serialization/json/BusinessUserInfo.h>
#include <qevercloud/serialization/json/UserAttributes.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<PrivilegeLevel> safeCastPrivilegeLevelToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(PrivilegeLevel::NORMAL):
        return PrivilegeLevel::NORMAL;
    case static_cast<qint64>(PrivilegeLevel::PREMIUM):
        return PrivilegeLevel::PREMIUM;
    case static_cast<qint64>(PrivilegeLevel::VIP):
        return PrivilegeLevel::VIP;
    case static_cast<qint64>(PrivilegeLevel::MANAGER):
        return PrivilegeLevel::MANAGER;
    case static_cast<qint64>(PrivilegeLevel::SUPPORT):
        return PrivilegeLevel::SUPPORT;
    case static_cast<qint64>(PrivilegeLevel::ADMIN):
        return PrivilegeLevel::ADMIN;
    default:
        return std::nullopt;
    }
}

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

QJsonObject serializeToJson(const User & value)
{
    QJsonObject object;

    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    if (value.id()) {
        object[QStringLiteral("id")] = *value.id();
    }

    if (value.username()) {
        object[QStringLiteral("username")] = *value.username();
    }

    if (value.email()) {
        object[QStringLiteral("email")] = *value.email();
    }

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.timezone()) {
        object[QStringLiteral("timezone")] = *value.timezone();
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    if (value.serviceLevel()) {
        object[QStringLiteral("serviceLevel")] = QString::number(static_cast<qint64>(*value.serviceLevel()));
    }

    if (value.created()) {
        object[QStringLiteral("created")] = QString::number(*value.created());
    }

    if (value.updated()) {
        object[QStringLiteral("updated")] = QString::number(*value.updated());
    }

    if (value.deleted()) {
        object[QStringLiteral("deleted")] = QString::number(*value.deleted());
    }

    if (value.active()) {
        object[QStringLiteral("active")] = *value.active();
    }

    if (value.shardId()) {
        object[QStringLiteral("shardId")] = *value.shardId();
    }

    if (value.attributes()) {
        object[QStringLiteral("attributes")] = serializeToJson(*value.attributes());
    }

    if (value.accounting()) {
        object[QStringLiteral("accounting")] = serializeToJson(*value.accounting());
    }

    if (value.businessUserInfo()) {
        object[QStringLiteral("businessUserInfo")] = serializeToJson(*value.businessUserInfo());
    }

    if (value.photoUrl()) {
        object[QStringLiteral("photoUrl")] = *value.photoUrl();
    }

    if (value.photoLastUpdated()) {
        object[QStringLiteral("photoLastUpdated")] = QString::number(*value.photoLastUpdated());
    }

    if (value.accountLimits()) {
        object[QStringLiteral("accountLimits")] = serializeToJson(*value.accountLimits());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, User & value)
{
    if (object.contains(QStringLiteral("isLocallyModified"))) {
        const auto v = object[QStringLiteral("isLocallyModified")];
        if (v.isBool()) {
            value.setLocallyModified(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocalOnly"))) {
        const auto v = object[QStringLiteral("isLocalOnly")];
        if (v.isBool()) {
            value.setLocalOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyFavorited"))) {
        const auto v = object[QStringLiteral("isLocallyFavorited")];
        if (v.isBool()) {
            value.setLocallyFavorited(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("localData"))) {
        auto v = object[QStringLiteral("localData")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QHash<QString, QVariant> map;
            for (auto it: toRange(qAsConst(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("timezone"))) {
        const auto v = object[QStringLiteral("timezone")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTimezone(std::move(s));
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

            const auto e = safeCastPrivilegeLevelToEnum(i);
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

    if (object.contains(QStringLiteral("created"))) {
        const auto v = object[QStringLiteral("created")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setCreated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updated"))) {
        const auto v = object[QStringLiteral("updated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("deleted"))) {
        const auto v = object[QStringLiteral("deleted")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setDeleted(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("active"))) {
        const auto v = object[QStringLiteral("active")];
        if (v.isBool()) {
            value.setActive(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("shardId"))) {
        const auto v = object[QStringLiteral("shardId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setShardId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("attributes"))) {
        const auto v = object[QStringLiteral("attributes")];
        if (v.isObject()) {
            auto o = v.toObject();
            UserAttributes f;
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

    if (object.contains(QStringLiteral("accounting"))) {
        const auto v = object[QStringLiteral("accounting")];
        if (v.isObject()) {
            auto o = v.toObject();
            Accounting f;
            if (deserializeFromJson(o, f)) {
                value.setAccounting(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessUserInfo"))) {
        const auto v = object[QStringLiteral("businessUserInfo")];
        if (v.isObject()) {
            auto o = v.toObject();
            BusinessUserInfo f;
            if (deserializeFromJson(o, f)) {
                value.setBusinessUserInfo(std::move(f));
            }
            else {
                return false;
            }
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

    if (object.contains(QStringLiteral("accountLimits"))) {
        const auto v = object[QStringLiteral("accountLimits")];
        if (v.isObject()) {
            auto o = v.toObject();
            AccountLimits f;
            if (deserializeFromJson(o, f)) {
                value.setAccountLimits(std::move(f));
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
