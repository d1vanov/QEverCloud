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

#include <qevercloud/serialization/json/NotebookRecipientSettings.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<RecipientStatus> safeCastRecipientStatusToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(RecipientStatus::NOT_IN_MY_LIST):
        return RecipientStatus::NOT_IN_MY_LIST;
    case static_cast<qint64>(RecipientStatus::IN_MY_LIST):
        return RecipientStatus::IN_MY_LIST;
    case static_cast<qint64>(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK):
        return RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const NotebookRecipientSettings & value)
{
    QJsonObject object;

    if (value.reminderNotifyEmail()) {
        object[QStringLiteral("reminderNotifyEmail")] = *value.reminderNotifyEmail();
    }

    if (value.reminderNotifyInApp()) {
        object[QStringLiteral("reminderNotifyInApp")] = *value.reminderNotifyInApp();
    }

    if (value.inMyList()) {
        object[QStringLiteral("inMyList")] = *value.inMyList();
    }

    if (value.stack()) {
        object[QStringLiteral("stack")] = *value.stack();
    }

    if (value.recipientStatus()) {
        object[QStringLiteral("recipientStatus")] = QString::number(static_cast<qint64>(*value.recipientStatus()));
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NotebookRecipientSettings & value)
{
    if (object.contains(QStringLiteral("reminderNotifyEmail"))) {
        const auto v = object[QStringLiteral("reminderNotifyEmail")];
        if (v.isBool()) {
            value.setReminderNotifyEmail(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("reminderNotifyInApp"))) {
        const auto v = object[QStringLiteral("reminderNotifyInApp")];
        if (v.isBool()) {
            value.setReminderNotifyInApp(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("inMyList"))) {
        const auto v = object[QStringLiteral("inMyList")];
        if (v.isBool()) {
            value.setInMyList(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("stack"))) {
        const auto v = object[QStringLiteral("stack")];
        if (v.isString()) {
            auto s = v.toString();
            value.setStack(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recipientStatus"))) {
        const auto v = object[QStringLiteral("recipientStatus")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastRecipientStatusToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setRecipientStatus(*e);
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

    return true;
}

} // namespace qevercloud
