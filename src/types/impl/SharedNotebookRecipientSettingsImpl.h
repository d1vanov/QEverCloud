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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSIMPL
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSIMPL

#include <qevercloud/types/SharedNotebookRecipientSettings.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebookRecipientSettings::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SharedNotebookRecipientSettings::Impl & other) = default;
    Impl(SharedNotebookRecipientSettings::Impl && other) noexcept = default;

    SharedNotebookRecipientSettings::Impl & operator=(const SharedNotebookRecipientSettings::Impl & other) = delete;
    SharedNotebookRecipientSettings::Impl & operator=(SharedNotebookRecipientSettings::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_reminderNotifyEmail;
    std::optional<bool> m_reminderNotifyInApp;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKRECIPIENTSETTINGSIMPL
