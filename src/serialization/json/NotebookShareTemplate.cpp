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

#include <qevercloud/serialization/json/NotebookShareTemplate.h>

#include <qevercloud/serialization/json/Contact.h>

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

QJsonObject serializeToJson(const NotebookShareTemplate & value)
{
    QJsonObject object;

    if (value.notebookGuid()) {
        object[QStringLiteral("notebookGuid")] = *value.notebookGuid();
    }

    if (value.recipientThreadId()) {
        object[QStringLiteral("recipientThreadId")] = QString::number(*value.recipientThreadId());
    }

    if (value.recipientContacts())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.recipientContacts()))
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

bool deserializeFromJson(const QJsonObject & object, NotebookShareTemplate & value)
{
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
            for (const auto & item: qAsConst(a)) {
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

    return true;
}

} // namespace qevercloud
