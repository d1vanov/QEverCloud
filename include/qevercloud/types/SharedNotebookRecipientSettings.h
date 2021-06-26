/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
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
     * Indicates that the user wishes to receive daily e-mail notifications
     * for reminders associated with the notebook. This may be true only for
     * business notebooks that belong to the business of which the user is a
     * member. You may only set this value on a notebook in your business.
     */
    [[nodiscard]] const std::optional<bool> & reminderNotifyEmail() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyEmail();
    void setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail);

    /**
     * Indicates that the user wishes to receive notifications for
     * reminders by applications that support providing such
     * notifications. The exact nature of the notification is defined
     * by the individual applications.
     */
    [[nodiscard]] const std::optional<bool> & reminderNotifyInApp() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyInApp();
    void setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SharedNotebookRecipientSettings & sharedNotebookRecipientSettings);

    Q_PROPERTY(std::optional<bool> reminderNotifyEmail READ reminderNotifyEmail WRITE setReminderNotifyEmail)
    Q_PROPERTY(std::optional<bool> reminderNotifyInApp READ reminderNotifyInApp WRITE setReminderNotifyInApp)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SharedNotebookRecipientSettings & lhs, const SharedNotebookRecipientSettings & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SharedNotebookRecipientSettings & lhs, const SharedNotebookRecipientSettings & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNotebookRecipientSettings)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGS
