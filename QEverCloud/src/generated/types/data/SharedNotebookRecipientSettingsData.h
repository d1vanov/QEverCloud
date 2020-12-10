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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSDATA_H
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSDATA_H

#include <generated/types/SharedNotebookRecipientSettings.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebookRecipientSettings::SharedNotebookRecipientSettingsData final:
    public QSharedData,
    public Printable
{
public:
    SharedNotebookRecipientSettingsData() = default;
    SharedNotebookRecipientSettingsData(const SharedNotebookRecipientSettingsData & other) = default;
    SharedNotebookRecipientSettingsData(SharedNotebookRecipientSettingsData && other) noexcept = default;

    SharedNotebookRecipientSettingsData & operator=(const SharedNotebookRecipientSettingsData & other) = delete;
    SharedNotebookRecipientSettingsData & operator=(SharedNotebookRecipientSettingsData && other) = delete;

    ~SharedNotebookRecipientSettingsData() noexcept override = default;

    [[nodiscard]] bool operator==(const SharedNotebookRecipientSettingsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNotebookRecipientSettingsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSDATA_H
