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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGS_H
#define QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGS_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Settings meant for the recipient of a notebook share.
 *
 * Some of these fields have a 3-state read value but a 2-state write value.
 * On read, it is possible to observe "unset", true, or false. The initial
 * state is "unset". When you choose to set a value, you may set it to either
 * true or false, but you cannot unset the value. Once one of these members
 * has a true/false value, it will always have a true/false value.
 *
 * */
class QEVERCLOUD_EXPORT NotebookRecipientSettings: public Printable
{
    Q_GADGET
public:
    NotebookRecipientSettings();
    NotebookRecipientSettings(const NotebookRecipientSettings & other);
    NotebookRecipientSettings(NotebookRecipientSettings && other) noexcept;
    ~NotebookRecipientSettings() noexcept override;

    NotebookRecipientSettings & operator=(const NotebookRecipientSettings & other);
    NotebookRecipientSettings & operator=(NotebookRecipientSettings && other) noexcept;

    /**
     * Indicates that the user wishes to receive daily e-mail notifications
     * for reminders associated with the notebook. This may be
     * true only for business notebooks that belong to the business of
     * which the user is a member. You may only set this value on a
     * notebook in your business. This value will initially be unset.
     */
    [[nodiscard]] const std::optional<bool> & reminderNotifyEmail() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyEmail();
    void setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail);

    /**
     * Indicates that the user wishes to receive notifications for
     * reminders by applications that support providing such
     * notifications. The exact nature of the notification is defined
     * by the individual applications. This value will initially be unset.
     */
    [[nodiscard]] const std::optional<bool> & reminderNotifyInApp() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableReminderNotifyInApp();
    void setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp);

    /**
     * DEPRECATED: Use recipientStatus instead.
     * The notebook is on the recipient's notebook list (formerly, we would say
     * that the recipient has "joined" the notebook)
     */
    [[nodiscard]] const std::optional<bool> & inMyList() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableInMyList();
    void setInMyList(std::optional<bool> inMyList);

    /**
     * The stack the recipient has put this notebook into. See Notebook.stack
     * for a definition. Every recipient can have their own stack value for the same
     * notebook.
     */
    [[nodiscard]] const std::optional<QString> & stack() const noexcept;
    void setStack(std::optional<QString> stack);

    /**
     * The notebook is on/off the recipient's notebook list (formerly, we would say
     * that the recipient has "joined" the notebook) and perhaps also their
     * default notebook
     */
    [[nodiscard]] const std::optional<RecipientStatus> & recipientStatus() const noexcept;
    [[nodiscard]] std::optional<RecipientStatus> & mutableRecipientStatus();
    void setRecipientStatus(std::optional<RecipientStatus> recipientStatus);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<bool> reminderNotifyEmail READ reminderNotifyEmail WRITE setReminderNotifyEmail)
    Q_PROPERTY(std::optional<bool> reminderNotifyInApp READ reminderNotifyInApp WRITE setReminderNotifyInApp)
    Q_PROPERTY(std::optional<bool> inMyList READ inMyList WRITE setInMyList)
    Q_PROPERTY(std::optional<QString> stack READ stack WRITE setStack)
    Q_PROPERTY(std::optional<RecipientStatus> recipientStatus READ recipientStatus WRITE setRecipientStatus)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const NotebookRecipientSettings & lhs, const NotebookRecipientSettings & rhs) noexcept;
[[nodiscard]] bool operator!=(const NotebookRecipientSettings & lhs, const NotebookRecipientSettings & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotebookRecipientSettings)

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGS_H
