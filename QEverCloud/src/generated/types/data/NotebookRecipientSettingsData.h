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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSDATA_H
#define QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSDATA_H

#include <generated/types/NotebookRecipientSettings.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookRecipientSettings::NotebookRecipientSettingsData final:
    public QSharedData,
    public Printable
{
public:
    NotebookRecipientSettingsData() = default;
    NotebookRecipientSettingsData(const NotebookRecipientSettingsData & other) = default;
    NotebookRecipientSettingsData(NotebookRecipientSettingsData && other) noexcept = default;

    NotebookRecipientSettingsData & operator=(const NotebookRecipientSettingsData & other) = delete;
    NotebookRecipientSettingsData & operator=(NotebookRecipientSettingsData && other) = delete;

    ~NotebookRecipientSettingsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NotebookRecipientSettingsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotebookRecipientSettingsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
    std::optional<bool> m_inMyList;
    std::optional<QString> m_stack;
    std::optional<RecipientStatus> m_recipientStatus;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSDATA_H
