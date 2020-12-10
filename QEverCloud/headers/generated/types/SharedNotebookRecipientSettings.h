/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS_H
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * Settings meant for the recipient of a shared notebook, such as
 * for indicating which types of notifications the recipient wishes
 * for reminders, etc.
 *
 * The reminderNotifyEmail and reminderNotifyInApp fields have a
 * 3-state read value but a 2-state write value.  On read, it is
 * possible to observe "unset", true, or false.  The initial state is
 * "unset".  When you choose to set a value, you may set it to either
 * true or false, but you cannot unset the value.  Once one of these
 * members has a true/false value, it will always have a true/false
 * value.
 *
 * */
class QEVERCLOUD_EXPORT SharedNotebookRecipientSettings: public Printable
{
    Q_GADGET
public:
    SharedNotebookRecipientSettings();
    SharedNotebookRecipientSettings(const SharedNotebookRecipientSettings & other);
    SharedNotebookRecipientSettings(SharedNotebookRecipientSettings && other) noexcept;
    ~SharedNotebookRecipientSettings() noexcept override;

    SharedNotebookRecipientSettings & operator=(const SharedNotebookRecipientSettings & other);
    SharedNotebookRecipientSettings & operator=(SharedNotebookRecipientSettings && other) noexcept;

    /**
    Indicates that the user wishes to receive daily e-mail notifications
         for reminders associated with the notebook. This may be true only for
         business notebooks that belong to the business of which the user is a
         member. You may only set this value on a notebook in your business.
    */
    [[nodiscard]] const std::optional<bool> & reminderNotifyEmail() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyEmail();
    void setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail);

    /**
    Indicates that the user wishes to receive notifications for
         reminders by applications that support providing such
         notifications.  The exact nature of the notification is defined
         by the individual applications.
    */
    [[nodiscard]] const std::optional<bool> & reminderNotifyInApp() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyInApp();
    void setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const SharedNotebookRecipientSettings & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNotebookRecipientSettings & other) const noexcept;

    Q_PROPERTY(std::optional<bool> reminderNotifyEmail READ reminderNotifyEmail WRITE setReminderNotifyEmail)
    Q_PROPERTY(std::optional<bool> reminderNotifyInApp READ reminderNotifyInApp WRITE setReminderNotifyInApp)

private:
    class SharedNotebookRecipientSettingsData;
    QSharedDataPointer<SharedNotebookRecipientSettingsData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNotebookRecipientSettings)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS_H
