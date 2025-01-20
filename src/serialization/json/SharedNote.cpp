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

#include <qevercloud/serialization/json/SharedNote.h>

#include <qevercloud/serialization/json/Identity.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

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

QJsonObject serializeToJson(const SharedNote & value)
{
    QJsonObject object;

    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(std::as_const(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    object[QStringLiteral("noteGuid")] = value.noteGuid();
    if (value.sharerUserID()) {
        object[QStringLiteral("sharerUserID")] = *value.sharerUserID();
    }

    if (value.recipientIdentity()) {
        object[QStringLiteral("recipientIdentity")] = serializeToJson(*value.recipientIdentity());
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    if (value.serviceCreated()) {
        object[QStringLiteral("serviceCreated")] = QString::number(*value.serviceCreated());
    }

    if (value.serviceUpdated()) {
        object[QStringLiteral("serviceUpdated")] = QString::number(*value.serviceUpdated());
    }

    if (value.serviceAssigned()) {
        object[QStringLiteral("serviceAssigned")] = QString::number(*value.serviceAssigned());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SharedNote & value)
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
            for (auto it: toRange(std::as_const(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteGuid"))) {
        const auto v = object[QStringLiteral("noteGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharerUserID"))) {
        const auto v = object[QStringLiteral("sharerUserID")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setSharerUserID(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recipientIdentity"))) {
        const auto v = object[QStringLiteral("recipientIdentity")];
        if (v.isObject()) {
            auto o = v.toObject();
            Identity f;
            if (deserializeFromJson(o, f)) {
                value.setRecipientIdentity(std::move(f));
            }
            else {
                return false;
            }
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
