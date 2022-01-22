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

#include <qevercloud/serialization/json/SharedNotebookRecipientSettings.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const SharedNotebookRecipientSettings & value)
{
    QJsonObject object;

    if (value.reminderNotifyEmail()) {
        object[QStringLiteral("reminderNotifyEmail")] = *value.reminderNotifyEmail();
    }

    if (value.reminderNotifyInApp()) {
        object[QStringLiteral("reminderNotifyInApp")] = *value.reminderNotifyInApp();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SharedNotebookRecipientSettings & value)
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

    return true;
}

} // namespace qevercloud
