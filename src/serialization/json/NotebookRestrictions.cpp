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

#include <qevercloud/serialization/json/NotebookRestrictions.h>

#include <qevercloud/serialization/json/CanMoveToContainerRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<SharedNotebookInstanceRestrictions> safeCastSharedNotebookInstanceRestrictionsToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(SharedNotebookInstanceRestrictions::ASSIGNED):
        return SharedNotebookInstanceRestrictions::ASSIGNED;
    case static_cast<qint64>(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS):
        return SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const NotebookRestrictions & value)
{
    QJsonObject object;

    if (value.noReadNotes()) {
        object[QStringLiteral("noReadNotes")] = *value.noReadNotes();
    }

    if (value.noCreateNotes()) {
        object[QStringLiteral("noCreateNotes")] = *value.noCreateNotes();
    }

    if (value.noUpdateNotes()) {
        object[QStringLiteral("noUpdateNotes")] = *value.noUpdateNotes();
    }

    if (value.noExpungeNotes()) {
        object[QStringLiteral("noExpungeNotes")] = *value.noExpungeNotes();
    }

    if (value.noShareNotes()) {
        object[QStringLiteral("noShareNotes")] = *value.noShareNotes();
    }

    if (value.noEmailNotes()) {
        object[QStringLiteral("noEmailNotes")] = *value.noEmailNotes();
    }

    if (value.noSendMessageToRecipients()) {
        object[QStringLiteral("noSendMessageToRecipients")] = *value.noSendMessageToRecipients();
    }

    if (value.noUpdateNotebook()) {
        object[QStringLiteral("noUpdateNotebook")] = *value.noUpdateNotebook();
    }

    if (value.noExpungeNotebook()) {
        object[QStringLiteral("noExpungeNotebook")] = *value.noExpungeNotebook();
    }

    if (value.noSetDefaultNotebook()) {
        object[QStringLiteral("noSetDefaultNotebook")] = *value.noSetDefaultNotebook();
    }

    if (value.noSetNotebookStack()) {
        object[QStringLiteral("noSetNotebookStack")] = *value.noSetNotebookStack();
    }

    if (value.noPublishToPublic()) {
        object[QStringLiteral("noPublishToPublic")] = *value.noPublishToPublic();
    }

    if (value.noPublishToBusinessLibrary()) {
        object[QStringLiteral("noPublishToBusinessLibrary")] = *value.noPublishToBusinessLibrary();
    }

    if (value.noCreateTags()) {
        object[QStringLiteral("noCreateTags")] = *value.noCreateTags();
    }

    if (value.noUpdateTags()) {
        object[QStringLiteral("noUpdateTags")] = *value.noUpdateTags();
    }

    if (value.noExpungeTags()) {
        object[QStringLiteral("noExpungeTags")] = *value.noExpungeTags();
    }

    if (value.noSetParentTag()) {
        object[QStringLiteral("noSetParentTag")] = *value.noSetParentTag();
    }

    if (value.noCreateSharedNotebooks()) {
        object[QStringLiteral("noCreateSharedNotebooks")] = *value.noCreateSharedNotebooks();
    }

    if (value.updateWhichSharedNotebookRestrictions()) {
        object[QStringLiteral("updateWhichSharedNotebookRestrictions")] = QString::number(static_cast<qint64>(*value.updateWhichSharedNotebookRestrictions()));
    }

    if (value.expungeWhichSharedNotebookRestrictions()) {
        object[QStringLiteral("expungeWhichSharedNotebookRestrictions")] = QString::number(static_cast<qint64>(*value.expungeWhichSharedNotebookRestrictions()));
    }

    if (value.noShareNotesWithBusiness()) {
        object[QStringLiteral("noShareNotesWithBusiness")] = *value.noShareNotesWithBusiness();
    }

    if (value.noRenameNotebook()) {
        object[QStringLiteral("noRenameNotebook")] = *value.noRenameNotebook();
    }

    if (value.noSetInMyList()) {
        object[QStringLiteral("noSetInMyList")] = *value.noSetInMyList();
    }

    if (value.noChangeContact()) {
        object[QStringLiteral("noChangeContact")] = *value.noChangeContact();
    }

    if (value.canMoveToContainerRestrictions()) {
        object[QStringLiteral("canMoveToContainerRestrictions")] = serializeToJson(*value.canMoveToContainerRestrictions());
    }

    if (value.noSetReminderNotifyEmail()) {
        object[QStringLiteral("noSetReminderNotifyEmail")] = *value.noSetReminderNotifyEmail();
    }

    if (value.noSetReminderNotifyInApp()) {
        object[QStringLiteral("noSetReminderNotifyInApp")] = *value.noSetReminderNotifyInApp();
    }

    if (value.noSetRecipientSettingsStack()) {
        object[QStringLiteral("noSetRecipientSettingsStack")] = *value.noSetRecipientSettingsStack();
    }

    if (value.noCanMoveNote()) {
        object[QStringLiteral("noCanMoveNote")] = *value.noCanMoveNote();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NotebookRestrictions & value)
{
    if (object.contains(QStringLiteral("noReadNotes"))) {
        const auto v = object[QStringLiteral("noReadNotes")];
        if (v.isBool()) {
            value.setNoReadNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noCreateNotes"))) {
        const auto v = object[QStringLiteral("noCreateNotes")];
        if (v.isBool()) {
            value.setNoCreateNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noUpdateNotes"))) {
        const auto v = object[QStringLiteral("noUpdateNotes")];
        if (v.isBool()) {
            value.setNoUpdateNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noExpungeNotes"))) {
        const auto v = object[QStringLiteral("noExpungeNotes")];
        if (v.isBool()) {
            value.setNoExpungeNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noShareNotes"))) {
        const auto v = object[QStringLiteral("noShareNotes")];
        if (v.isBool()) {
            value.setNoShareNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noEmailNotes"))) {
        const auto v = object[QStringLiteral("noEmailNotes")];
        if (v.isBool()) {
            value.setNoEmailNotes(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSendMessageToRecipients"))) {
        const auto v = object[QStringLiteral("noSendMessageToRecipients")];
        if (v.isBool()) {
            value.setNoSendMessageToRecipients(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noUpdateNotebook"))) {
        const auto v = object[QStringLiteral("noUpdateNotebook")];
        if (v.isBool()) {
            value.setNoUpdateNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noExpungeNotebook"))) {
        const auto v = object[QStringLiteral("noExpungeNotebook")];
        if (v.isBool()) {
            value.setNoExpungeNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetDefaultNotebook"))) {
        const auto v = object[QStringLiteral("noSetDefaultNotebook")];
        if (v.isBool()) {
            value.setNoSetDefaultNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetNotebookStack"))) {
        const auto v = object[QStringLiteral("noSetNotebookStack")];
        if (v.isBool()) {
            value.setNoSetNotebookStack(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noPublishToPublic"))) {
        const auto v = object[QStringLiteral("noPublishToPublic")];
        if (v.isBool()) {
            value.setNoPublishToPublic(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noPublishToBusinessLibrary"))) {
        const auto v = object[QStringLiteral("noPublishToBusinessLibrary")];
        if (v.isBool()) {
            value.setNoPublishToBusinessLibrary(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noCreateTags"))) {
        const auto v = object[QStringLiteral("noCreateTags")];
        if (v.isBool()) {
            value.setNoCreateTags(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noUpdateTags"))) {
        const auto v = object[QStringLiteral("noUpdateTags")];
        if (v.isBool()) {
            value.setNoUpdateTags(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noExpungeTags"))) {
        const auto v = object[QStringLiteral("noExpungeTags")];
        if (v.isBool()) {
            value.setNoExpungeTags(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetParentTag"))) {
        const auto v = object[QStringLiteral("noSetParentTag")];
        if (v.isBool()) {
            value.setNoSetParentTag(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noCreateSharedNotebooks"))) {
        const auto v = object[QStringLiteral("noCreateSharedNotebooks")];
        if (v.isBool()) {
            value.setNoCreateSharedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updateWhichSharedNotebookRestrictions"))) {
        const auto v = object[QStringLiteral("updateWhichSharedNotebookRestrictions")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastSharedNotebookInstanceRestrictionsToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setUpdateWhichSharedNotebookRestrictions(*e);
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

    if (object.contains(QStringLiteral("expungeWhichSharedNotebookRestrictions"))) {
        const auto v = object[QStringLiteral("expungeWhichSharedNotebookRestrictions")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastSharedNotebookInstanceRestrictionsToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setExpungeWhichSharedNotebookRestrictions(*e);
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

    if (object.contains(QStringLiteral("noShareNotesWithBusiness"))) {
        const auto v = object[QStringLiteral("noShareNotesWithBusiness")];
        if (v.isBool()) {
            value.setNoShareNotesWithBusiness(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noRenameNotebook"))) {
        const auto v = object[QStringLiteral("noRenameNotebook")];
        if (v.isBool()) {
            value.setNoRenameNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetInMyList"))) {
        const auto v = object[QStringLiteral("noSetInMyList")];
        if (v.isBool()) {
            value.setNoSetInMyList(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noChangeContact"))) {
        const auto v = object[QStringLiteral("noChangeContact")];
        if (v.isBool()) {
            value.setNoChangeContact(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("canMoveToContainerRestrictions"))) {
        const auto v = object[QStringLiteral("canMoveToContainerRestrictions")];
        if (v.isObject()) {
            auto o = v.toObject();
            CanMoveToContainerRestrictions f;
            if (deserializeFromJson(o, f)) {
                value.setCanMoveToContainerRestrictions(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetReminderNotifyEmail"))) {
        const auto v = object[QStringLiteral("noSetReminderNotifyEmail")];
        if (v.isBool()) {
            value.setNoSetReminderNotifyEmail(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetReminderNotifyInApp"))) {
        const auto v = object[QStringLiteral("noSetReminderNotifyInApp")];
        if (v.isBool()) {
            value.setNoSetReminderNotifyInApp(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetRecipientSettingsStack"))) {
        const auto v = object[QStringLiteral("noSetRecipientSettingsStack")];
        if (v.isBool()) {
            value.setNoSetRecipientSettingsStack(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noCanMoveNote"))) {
        const auto v = object[QStringLiteral("noCanMoveNote")];
        if (v.isBool()) {
            value.setNoCanMoveNote(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
