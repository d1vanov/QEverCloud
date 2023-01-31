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

#include <qevercloud/types/builders/NotebookRestrictionsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookRestrictionsBuilder::Impl final:
    public QSharedData
{
public:
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

NotebookRestrictionsBuilder::NotebookRestrictionsBuilder() :
    d(new NotebookRestrictionsBuilder::Impl)
{}

NotebookRestrictionsBuilder::NotebookRestrictionsBuilder(NotebookRestrictionsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotebookRestrictionsBuilder::~NotebookRestrictionsBuilder() noexcept = default;

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::operator=(NotebookRestrictionsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoReadNotes(std::optional<bool> noReadNotes)
{
    d->m_noReadNotes = std::move(noReadNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoCreateNotes(std::optional<bool> noCreateNotes)
{
    d->m_noCreateNotes = std::move(noCreateNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoUpdateNotes(std::optional<bool> noUpdateNotes)
{
    d->m_noUpdateNotes = std::move(noUpdateNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoExpungeNotes(std::optional<bool> noExpungeNotes)
{
    d->m_noExpungeNotes = std::move(noExpungeNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoShareNotes(std::optional<bool> noShareNotes)
{
    d->m_noShareNotes = std::move(noShareNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoEmailNotes(std::optional<bool> noEmailNotes)
{
    d->m_noEmailNotes = std::move(noEmailNotes);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSendMessageToRecipients(std::optional<bool> noSendMessageToRecipients)
{
    d->m_noSendMessageToRecipients = std::move(noSendMessageToRecipients);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoUpdateNotebook(std::optional<bool> noUpdateNotebook)
{
    d->m_noUpdateNotebook = std::move(noUpdateNotebook);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoExpungeNotebook(std::optional<bool> noExpungeNotebook)
{
    d->m_noExpungeNotebook = std::move(noExpungeNotebook);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetDefaultNotebook(std::optional<bool> noSetDefaultNotebook)
{
    d->m_noSetDefaultNotebook = std::move(noSetDefaultNotebook);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetNotebookStack(std::optional<bool> noSetNotebookStack)
{
    d->m_noSetNotebookStack = std::move(noSetNotebookStack);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoPublishToPublic(std::optional<bool> noPublishToPublic)
{
    d->m_noPublishToPublic = std::move(noPublishToPublic);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoPublishToBusinessLibrary(std::optional<bool> noPublishToBusinessLibrary)
{
    d->m_noPublishToBusinessLibrary = std::move(noPublishToBusinessLibrary);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoCreateTags(std::optional<bool> noCreateTags)
{
    d->m_noCreateTags = std::move(noCreateTags);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoUpdateTags(std::optional<bool> noUpdateTags)
{
    d->m_noUpdateTags = std::move(noUpdateTags);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoExpungeTags(std::optional<bool> noExpungeTags)
{
    d->m_noExpungeTags = std::move(noExpungeTags);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetParentTag(std::optional<bool> noSetParentTag)
{
    d->m_noSetParentTag = std::move(noSetParentTag);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoCreateSharedNotebooks(std::optional<bool> noCreateSharedNotebooks)
{
    d->m_noCreateSharedNotebooks = std::move(noCreateSharedNotebooks);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setUpdateWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions)
{
    d->m_updateWhichSharedNotebookRestrictions = std::move(updateWhichSharedNotebookRestrictions);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setExpungeWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions)
{
    d->m_expungeWhichSharedNotebookRestrictions = std::move(expungeWhichSharedNotebookRestrictions);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoShareNotesWithBusiness(std::optional<bool> noShareNotesWithBusiness)
{
    d->m_noShareNotesWithBusiness = std::move(noShareNotesWithBusiness);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoRenameNotebook(std::optional<bool> noRenameNotebook)
{
    d->m_noRenameNotebook = std::move(noRenameNotebook);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetInMyList(std::optional<bool> noSetInMyList)
{
    d->m_noSetInMyList = std::move(noSetInMyList);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoChangeContact(std::optional<bool> noChangeContact)
{
    d->m_noChangeContact = std::move(noChangeContact);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setCanMoveToContainerRestrictions(std::optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions)
{
    d->m_canMoveToContainerRestrictions = std::move(canMoveToContainerRestrictions);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetReminderNotifyEmail(std::optional<bool> noSetReminderNotifyEmail)
{
    d->m_noSetReminderNotifyEmail = std::move(noSetReminderNotifyEmail);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetReminderNotifyInApp(std::optional<bool> noSetReminderNotifyInApp)
{
    d->m_noSetReminderNotifyInApp = std::move(noSetReminderNotifyInApp);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoSetRecipientSettingsStack(std::optional<bool> noSetRecipientSettingsStack)
{
    d->m_noSetRecipientSettingsStack = std::move(noSetRecipientSettingsStack);
    return *this;
}

NotebookRestrictionsBuilder & NotebookRestrictionsBuilder::setNoCanMoveNote(std::optional<bool> noCanMoveNote)
{
    d->m_noCanMoveNote = std::move(noCanMoveNote);
    return *this;
}

NotebookRestrictions NotebookRestrictionsBuilder::build()
{
    NotebookRestrictions result;

    result.setNoReadNotes(std::move(d->m_noReadNotes));
    result.setNoCreateNotes(std::move(d->m_noCreateNotes));
    result.setNoUpdateNotes(std::move(d->m_noUpdateNotes));
    result.setNoExpungeNotes(std::move(d->m_noExpungeNotes));
    result.setNoShareNotes(std::move(d->m_noShareNotes));
    result.setNoEmailNotes(std::move(d->m_noEmailNotes));
    result.setNoSendMessageToRecipients(std::move(d->m_noSendMessageToRecipients));
    result.setNoUpdateNotebook(std::move(d->m_noUpdateNotebook));
    result.setNoExpungeNotebook(std::move(d->m_noExpungeNotebook));
    result.setNoSetDefaultNotebook(std::move(d->m_noSetDefaultNotebook));
    result.setNoSetNotebookStack(std::move(d->m_noSetNotebookStack));
    result.setNoPublishToPublic(std::move(d->m_noPublishToPublic));
    result.setNoPublishToBusinessLibrary(std::move(d->m_noPublishToBusinessLibrary));
    result.setNoCreateTags(std::move(d->m_noCreateTags));
    result.setNoUpdateTags(std::move(d->m_noUpdateTags));
    result.setNoExpungeTags(std::move(d->m_noExpungeTags));
    result.setNoSetParentTag(std::move(d->m_noSetParentTag));
    result.setNoCreateSharedNotebooks(std::move(d->m_noCreateSharedNotebooks));
    result.setUpdateWhichSharedNotebookRestrictions(std::move(d->m_updateWhichSharedNotebookRestrictions));
    result.setExpungeWhichSharedNotebookRestrictions(std::move(d->m_expungeWhichSharedNotebookRestrictions));
    result.setNoShareNotesWithBusiness(std::move(d->m_noShareNotesWithBusiness));
    result.setNoRenameNotebook(std::move(d->m_noRenameNotebook));
    result.setNoSetInMyList(std::move(d->m_noSetInMyList));
    result.setNoChangeContact(std::move(d->m_noChangeContact));
    result.setCanMoveToContainerRestrictions(std::move(d->m_canMoveToContainerRestrictions));
    result.setNoSetReminderNotifyEmail(std::move(d->m_noSetReminderNotifyEmail));
    result.setNoSetReminderNotifyInApp(std::move(d->m_noSetReminderNotifyInApp));
    result.setNoSetRecipientSettingsStack(std::move(d->m_noSetRecipientSettingsStack));
    result.setNoCanMoveNote(std::move(d->m_noCanMoveNote));

    d->m_noReadNotes = {};
    d->m_noCreateNotes = {};
    d->m_noUpdateNotes = {};
    d->m_noExpungeNotes = {};
    d->m_noShareNotes = {};
    d->m_noEmailNotes = {};
    d->m_noSendMessageToRecipients = {};
    d->m_noUpdateNotebook = {};
    d->m_noExpungeNotebook = {};
    d->m_noSetDefaultNotebook = {};
    d->m_noSetNotebookStack = {};
    d->m_noPublishToPublic = {};
    d->m_noPublishToBusinessLibrary = {};
    d->m_noCreateTags = {};
    d->m_noUpdateTags = {};
    d->m_noExpungeTags = {};
    d->m_noSetParentTag = {};
    d->m_noCreateSharedNotebooks = {};
    d->m_updateWhichSharedNotebookRestrictions = {};
    d->m_expungeWhichSharedNotebookRestrictions = {};
    d->m_noShareNotesWithBusiness = {};
    d->m_noRenameNotebook = {};
    d->m_noSetInMyList = {};
    d->m_noChangeContact = {};
    d->m_canMoveToContainerRestrictions = {};
    d->m_noSetReminderNotifyEmail = {};
    d->m_noSetReminderNotifyInApp = {};
    d->m_noSetRecipientSettingsStack = {};
    d->m_noCanMoveNote = {};

    return result;
}

} // namespace qevercloud
