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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSIMPL_H
#define QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSIMPL_H

#include <qevercloud/generated/types/NotebookRecipientSettings.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookRecipientSettings::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NotebookRecipientSettings::Impl & other) = default;
    Impl(NotebookRecipientSettings::Impl && other) noexcept = default;

    NotebookRecipientSettings::Impl & operator=(const NotebookRecipientSettings::Impl & other) = delete;
    NotebookRecipientSettings::Impl & operator=(NotebookRecipientSettings::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
    std::optional<bool> m_inMyList;
    std::optional<QString> m_stack;
    std::optional<RecipientStatus> m_recipientStatus;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRECIPIENTSETTINGSIMPL_H
