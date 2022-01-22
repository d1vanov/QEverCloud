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

#include <qevercloud/serialization/json/BusinessNotebook.h>

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

QJsonObject serializeToJson(const BusinessNotebook & value)
{
    QJsonObject object;

    if (value.notebookDescription()) {
        object[QStringLiteral("notebookDescription")] = *value.notebookDescription();
    }

    if (value.privilege()) {
        object[QStringLiteral("privilege")] = QString::number(static_cast<qint64>(*value.privilege()));
    }

    if (value.recommended()) {
        object[QStringLiteral("recommended")] = *value.recommended();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BusinessNotebook & value)
{
    if (object.contains(QStringLiteral("notebookDescription"))) {
        const auto v = object[QStringLiteral("notebookDescription")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookDescription(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("privilege"))) {
        const auto v = object[QStringLiteral("privilege")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastSharedNotebookPrivilegeLevelToEnum(static_cast<qint64>(d));
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
    }

    if (object.contains(QStringLiteral("recommended"))) {
        const auto v = object[QStringLiteral("recommended")];
        if (v.isBool()) {
            value.setRecommended(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
