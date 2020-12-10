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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSDATA_H
#define QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSDATA_H

#include <generated/types/NotebookRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookRestrictions::NotebookRestrictionsData final:
    public QSharedData,
    public Printable
{
public:
    NotebookRestrictionsData() = default;
    NotebookRestrictionsData(const NotebookRestrictionsData & other) = default;
    NotebookRestrictionsData(NotebookRestrictionsData && other) noexcept = default;

    NotebookRestrictionsData & operator=(const NotebookRestrictionsData & other) = delete;
    NotebookRestrictionsData & operator=(NotebookRestrictionsData && other) = delete;

    ~NotebookRestrictionsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NotebookRestrictionsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotebookRestrictionsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noReadNotes;
    std::optional<bool> m_noCreateNotes;
    std::optional<bool> m_noUpdateNotes;
    std::optional<bool> m_noExpungeNotes;
    std::optional<bool> m_noShareNotes;
    std::optional<bool> m_noEmailNotes;
    std::optional<bool> m_noSendMessageToRecipients;
    std::optional<bool> m_noUpdateNotebook;
    std::optional<bool> m_noExpungeNotebook;
    std::optional<bool> m_noSetDefaultNotebook;
    std::optional<bool> m_noSetNotebookStack;
    std::optional<bool> m_noPublishToPublic;
    std::optional<bool> m_noPublishToBusinessLibrary;
    std::optional<bool> m_noCreateTags;
    std::optional<bool> m_noUpdateTags;
    std::optional<bool> m_noExpungeTags;
    std::optional<bool> m_noSetParentTag;
    std::optional<bool> m_noCreateSharedNotebooks;
    std::optional<SharedNotebookInstanceRestrictions> m_updateWhichSharedNotebookRestrictions;
    std::optional<SharedNotebookInstanceRestrictions> m_expungeWhichSharedNotebookRestrictions;
    std::optional<bool> m_noShareNotesWithBusiness;
    std::optional<bool> m_noRenameNotebook;
    std::optional<bool> m_noSetInMyList;
    std::optional<bool> m_noChangeContact;
    std::optional<CanMoveToContainerRestrictions> m_canMoveToContainerRestrictions;
    std::optional<bool> m_noSetReminderNotifyEmail;
    std::optional<bool> m_noSetReminderNotifyInApp;
    std::optional<bool> m_noSetRecipientSettingsStack;
    std::optional<bool> m_noCanMoveNote;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSDATA_H
