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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSBUILDER
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SharedNotebookRecipientSettings.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SharedNotebookRecipientSettingsBuilder
{
public:
    SharedNotebookRecipientSettingsBuilder();

    SharedNotebookRecipientSettingsBuilder(SharedNotebookRecipientSettingsBuilder && other) noexcept;

    ~SharedNotebookRecipientSettingsBuilder() noexcept;

    SharedNotebookRecipientSettingsBuilder & operator=(SharedNotebookRecipientSettingsBuilder && other) noexcept;

    SharedNotebookRecipientSettingsBuilder & setReminderNotifyEmail(std::optional<bool> reminderNotifyEmail);
    SharedNotebookRecipientSettingsBuilder & setReminderNotifyInApp(std::optional<bool> reminderNotifyInApp);

    [[nodiscard]] SharedNotebookRecipientSettings build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSBUILDER
