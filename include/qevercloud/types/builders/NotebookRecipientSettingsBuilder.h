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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSBUILDER
#define QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NotebookRecipientSettings.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotebookRecipientSettingsBuilder
{
public:
    NotebookRecipientSettingsBuilder();

    NotebookRecipientSettingsBuilder(NotebookRecipientSettingsBuilder && other) noexcept;

    ~NotebookRecipientSettingsBuilder() noexcept;

    NotebookRecipientSettingsBuilder & operator=(NotebookRecipientSettingsBuilder && other) noexcept;

    NotebookRecipientSettingsBuilder & setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail);
    NotebookRecipientSettingsBuilder & setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp);
    NotebookRecipientSettingsBuilder & setInMyList(std::optional<bool> inMyList);
    NotebookRecipientSettingsBuilder & setStack(std::optional<QString> stack);
    NotebookRecipientSettingsBuilder & setRecipientStatus(std::optional<RecipientStatus> recipientStatus);

    [[nodiscard]] NotebookRecipientSettings build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSBUILDER
