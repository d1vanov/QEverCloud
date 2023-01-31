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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSBUILDER
#define QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/CanMoveToContainerRestrictions.h>
#include <qevercloud/types/NotebookRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotebookRestrictionsBuilder
{
public:
    NotebookRestrictionsBuilder();

    NotebookRestrictionsBuilder(NotebookRestrictionsBuilder && other) noexcept;

    ~NotebookRestrictionsBuilder() noexcept;

    NotebookRestrictionsBuilder & operator=(NotebookRestrictionsBuilder && other) noexcept;

    NotebookRestrictionsBuilder & setNoReadNotes(std::optional<bool> noReadNotes);
    NotebookRestrictionsBuilder & setNoCreateNotes(std::optional<bool> noCreateNotes);
    NotebookRestrictionsBuilder & setNoUpdateNotes(std::optional<bool> noUpdateNotes);
    NotebookRestrictionsBuilder & setNoExpungeNotes(std::optional<bool> noExpungeNotes);
    NotebookRestrictionsBuilder & setNoShareNotes(std::optional<bool> noShareNotes);
    NotebookRestrictionsBuilder & setNoEmailNotes(std::optional<bool> noEmailNotes);
    NotebookRestrictionsBuilder & setNoSendMessageToRecipients(std::optional<bool> noSendMessageToRecipients);
    NotebookRestrictionsBuilder & setNoUpdateNotebook(std::optional<bool> noUpdateNotebook);
    NotebookRestrictionsBuilder & setNoExpungeNotebook(std::optional<bool> noExpungeNotebook);
    NotebookRestrictionsBuilder & setNoSetDefaultNotebook(std::optional<bool> noSetDefaultNotebook);
    NotebookRestrictionsBuilder & setNoSetNotebookStack(std::optional<bool> noSetNotebookStack);
    NotebookRestrictionsBuilder & setNoPublishToPublic(std::optional<bool> noPublishToPublic);
    NotebookRestrictionsBuilder & setNoPublishToBusinessLibrary(std::optional<bool> noPublishToBusinessLibrary);
    NotebookRestrictionsBuilder & setNoCreateTags(std::optional<bool> noCreateTags);
    NotebookRestrictionsBuilder & setNoUpdateTags(std::optional<bool> noUpdateTags);
    NotebookRestrictionsBuilder & setNoExpungeTags(std::optional<bool> noExpungeTags);
    NotebookRestrictionsBuilder & setNoSetParentTag(std::optional<bool> noSetParentTag);
    NotebookRestrictionsBuilder & setNoCreateSharedNotebooks(std::optional<bool> noCreateSharedNotebooks);
    NotebookRestrictionsBuilder & setUpdateWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions);
    NotebookRestrictionsBuilder & setExpungeWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions);
    NotebookRestrictionsBuilder & setNoShareNotesWithBusiness(std::optional<bool> noShareNotesWithBusiness);
    NotebookRestrictionsBuilder & setNoRenameNotebook(std::optional<bool> noRenameNotebook);
    NotebookRestrictionsBuilder & setNoSetInMyList(std::optional<bool> noSetInMyList);
    NotebookRestrictionsBuilder & setNoChangeContact(std::optional<bool> noChangeContact);
    NotebookRestrictionsBuilder & setCanMoveToContainerRestrictions(std::optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions);
    NotebookRestrictionsBuilder & setNoSetReminderNotifyEmail(std::optional<bool> noSetReminderNotifyEmail);
    NotebookRestrictionsBuilder & setNoSetReminderNotifyInApp(std::optional<bool> noSetReminderNotifyInApp);
    NotebookRestrictionsBuilder & setNoSetRecipientSettingsStack(std::optional<bool> noSetRecipientSettingsStack);
    NotebookRestrictionsBuilder & setNoCanMoveNote(std::optional<bool> noCanMoveNote);

    [[nodiscard]] NotebookRestrictions build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONSBUILDER
