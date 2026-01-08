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

#include <qevercloud/serialization/json/SharedNoteTemplate.h>

#include <qevercloud/serialization/json/Contact.h>

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

QJsonObject serializeToJson(const SharedNoteTemplate & value)
{
    QJsonObject object;

    if (value.noteGuid()) {
        object[QStringLiteral("noteGuid")] = *value.noteGuid();
    }

    if (value.recipientThreadId()) {
        object[QStringLiteral("recipientThreadId")] = QString::number(*value.recipientThreadId());
    }

    if (value.recipientContacts())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.recipientContacts()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("recipientContacts")] = array;
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SharedNoteTemplate & value)
{
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

    if (object.contains(QStringLiteral("recipientThreadId"))) {
        const auto v = object[QStringLiteral("recipientThreadId")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setRecipientThreadId(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recipientContacts"))) {
        const auto v = object[QStringLiteral("recipientContacts")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Contact> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Contact f;
                    if (deserializeFromJson(o, f)) {
                        values.push_back(std::move(f));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setRecipientContacts(std::move(values));
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

    return true;
}

} // namespace qevercloud
