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

#include <qevercloud/serialization/json/SharedNotebook.h>

#include <qevercloud/serialization/json/SharedNotebookRecipientSettings.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<SharedNotebookPrivilegeLevel> safeCastSharedNotebookPrivilegeLevelToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK):
        return SharedNotebookPrivilegeLevel::READ_NOTEBOOK;
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY):
        return SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY;
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY):
        return SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY;
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::GROUP):
        return SharedNotebookPrivilegeLevel::GROUP;
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::FULL_ACCESS):
        return SharedNotebookPrivilegeLevel::FULL_ACCESS;
    case static_cast<qint64>(SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS):
        return SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const SharedNotebook & value)
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
        object[QStringLiteral("id")] = QString::number(*value.id());
    }

    if (value.userId()) {
        object[QStringLiteral("userId")] = *value.userId();
    }

    if (value.notebookGuid()) {
        object[QStringLiteral("notebookGuid")] = *value.notebookGuid();
    }

    if (value.email()) {
        object[QStringLiteral("email")] = *value.email();
    }

    if (value.recipientIdentityId()) {
        object[QStringLiteral("recipientIdentityId")] = QString::number(*value.recipientIdentityId());
    }

    if (value.notebookModifiable()) {
        object[QStringLiteral("notebookModifiable")] = *value.notebookModifiable();
    }

    if (value.serviceCreated()) {
        object[QStringLiteral("serviceCreated")] = QString::number(*value.serviceCreated());
    }

    if (value.serviceUpdated()) {
        object[QStringLiteral("serviceUpdated")] = QString::number(*value.serviceUpdated());
    }

    if (value.globalId()) {
        object[QStringLiteral("globalId")] = *value.globalId();
    }

    if (value.username()) {
        object[QStringLiteral("username")] = *value.username();
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    if (value.recipientSettings()) {
        object[QStringLiteral("recipientSettings")] = serializeToJson(*value.recipientSettings());
    }

    if (value.sharerUserId()) {
        object[QStringLiteral("sharerUserId")] = *value.sharerUserId();
    }

    if (value.recipientUsername()) {
        object[QStringLiteral("recipientUsername")] = *value.recipientUsername();
    }

    if (value.recipientUserId()) {
        object[QStringLiteral("recipientUserId")] = *value.recipientUserId();
    }

    if (value.serviceAssigned()) {
        object[QStringLiteral("serviceAssigned")] = QString::number(*value.serviceAssigned());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SharedNotebook & value)
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

    if (object.contains(QStringLiteral("notebookGuid"))) {
        const auto v = object[QStringLiteral("notebookGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookGuid(std::move(s));
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

    if (object.contains(QStringLiteral("notebookModifiable"))) {
        const auto v = object[QStringLiteral("notebookModifiable")];
        if (v.isBool()) {
            value.setNotebookModifiable(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("serviceCreated"))) {
        const auto v = object[QStringLiteral("serviceCreated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setServiceCreated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("serviceUpdated"))) {
        const auto v = object[QStringLiteral("serviceUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setServiceUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("globalId"))) {
        const auto v = object[QStringLiteral("globalId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setGlobalId(std::move(s));
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

    if (object.contains(QStringLiteral("privilege"))) {
        const auto v = object[QStringLiteral("privilege")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastSharedNotebookPrivilegeLevelToEnum(i);
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

    if (object.contains(QStringLiteral("recipientSettings"))) {
        const auto v = object[QStringLiteral("recipientSettings")];
        if (v.isObject()) {
            auto o = v.toObject();
            SharedNotebookRecipientSettings f;
            if (deserializeFromJson(o, f)) {
                value.setRecipientSettings(std::move(f));
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

    if (object.contains(QStringLiteral("recipientUsername"))) {
        const auto v = object[QStringLiteral("recipientUsername")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRecipientUsername(std::move(s));
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

    if (object.contains(QStringLiteral("serviceAssigned"))) {
        const auto v = object[QStringLiteral("serviceAssigned")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setServiceAssigned(i);
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
