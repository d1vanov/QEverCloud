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

#include <qevercloud/generated/types/NotebookRestrictions.h>

#include "impl/NotebookRestrictionsImpl.h"

namespace qevercloud {

NotebookRestrictions::NotebookRestrictions() :
    d(new NotebookRestrictions::Impl)
 {}

NotebookRestrictions::NotebookRestrictions(const NotebookRestrictions & other) :
    d(other.d)
{}

NotebookRestrictions::NotebookRestrictions(NotebookRestrictions && other) noexcept :
    d(std::move(other.d))
{}

NotebookRestrictions::~NotebookRestrictions() noexcept {}

NotebookRestrictions & NotebookRestrictions::operator=(const NotebookRestrictions & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NotebookRestrictions & NotebookRestrictions::operator=(NotebookRestrictions && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NotebookRestrictions::noReadNotes() const noexcept
{
    return d->m_noReadNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoReadNotes()
{
    return d->m_noReadNotes;
}

void NotebookRestrictions::setNoReadNotes(std::optional<bool> noReadNotes)
{
    d->m_noReadNotes = noReadNotes;
}

const std::optional<bool> & NotebookRestrictions::noCreateNotes() const noexcept
{
    return d->m_noCreateNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoCreateNotes()
{
    return d->m_noCreateNotes;
}

void NotebookRestrictions::setNoCreateNotes(std::optional<bool> noCreateNotes)
{
    d->m_noCreateNotes = noCreateNotes;
}

const std::optional<bool> & NotebookRestrictions::noUpdateNotes() const noexcept
{
    return d->m_noUpdateNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoUpdateNotes()
{
    return d->m_noUpdateNotes;
}

void NotebookRestrictions::setNoUpdateNotes(std::optional<bool> noUpdateNotes)
{
    d->m_noUpdateNotes = noUpdateNotes;
}

const std::optional<bool> & NotebookRestrictions::noExpungeNotes() const noexcept
{
    return d->m_noExpungeNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoExpungeNotes()
{
    return d->m_noExpungeNotes;
}

void NotebookRestrictions::setNoExpungeNotes(std::optional<bool> noExpungeNotes)
{
    d->m_noExpungeNotes = noExpungeNotes;
}

const std::optional<bool> & NotebookRestrictions::noShareNotes() const noexcept
{
    return d->m_noShareNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoShareNotes()
{
    return d->m_noShareNotes;
}

void NotebookRestrictions::setNoShareNotes(std::optional<bool> noShareNotes)
{
    d->m_noShareNotes = noShareNotes;
}

const std::optional<bool> & NotebookRestrictions::noEmailNotes() const noexcept
{
    return d->m_noEmailNotes;
}

std::optional<bool> & NotebookRestrictions::mutableNoEmailNotes()
{
    return d->m_noEmailNotes;
}

void NotebookRestrictions::setNoEmailNotes(std::optional<bool> noEmailNotes)
{
    d->m_noEmailNotes = noEmailNotes;
}

const std::optional<bool> & NotebookRestrictions::noSendMessageToRecipients() const noexcept
{
    return d->m_noSendMessageToRecipients;
}

std::optional<bool> & NotebookRestrictions::mutableNoSendMessageToRecipients()
{
    return d->m_noSendMessageToRecipients;
}

void NotebookRestrictions::setNoSendMessageToRecipients(std::optional<bool> noSendMessageToRecipients)
{
    d->m_noSendMessageToRecipients = noSendMessageToRecipients;
}

const std::optional<bool> & NotebookRestrictions::noUpdateNotebook() const noexcept
{
    return d->m_noUpdateNotebook;
}

std::optional<bool> & NotebookRestrictions::mutableNoUpdateNotebook()
{
    return d->m_noUpdateNotebook;
}

void NotebookRestrictions::setNoUpdateNotebook(std::optional<bool> noUpdateNotebook)
{
    d->m_noUpdateNotebook = noUpdateNotebook;
}

const std::optional<bool> & NotebookRestrictions::noExpungeNotebook() const noexcept
{
    return d->m_noExpungeNotebook;
}

std::optional<bool> & NotebookRestrictions::mutableNoExpungeNotebook()
{
    return d->m_noExpungeNotebook;
}

void NotebookRestrictions::setNoExpungeNotebook(std::optional<bool> noExpungeNotebook)
{
    d->m_noExpungeNotebook = noExpungeNotebook;
}

const std::optional<bool> & NotebookRestrictions::noSetDefaultNotebook() const noexcept
{
    return d->m_noSetDefaultNotebook;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetDefaultNotebook()
{
    return d->m_noSetDefaultNotebook;
}

void NotebookRestrictions::setNoSetDefaultNotebook(std::optional<bool> noSetDefaultNotebook)
{
    d->m_noSetDefaultNotebook = noSetDefaultNotebook;
}

const std::optional<bool> & NotebookRestrictions::noSetNotebookStack() const noexcept
{
    return d->m_noSetNotebookStack;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetNotebookStack()
{
    return d->m_noSetNotebookStack;
}

void NotebookRestrictions::setNoSetNotebookStack(std::optional<bool> noSetNotebookStack)
{
    d->m_noSetNotebookStack = noSetNotebookStack;
}

const std::optional<bool> & NotebookRestrictions::noPublishToPublic() const noexcept
{
    return d->m_noPublishToPublic;
}

std::optional<bool> & NotebookRestrictions::mutableNoPublishToPublic()
{
    return d->m_noPublishToPublic;
}

void NotebookRestrictions::setNoPublishToPublic(std::optional<bool> noPublishToPublic)
{
    d->m_noPublishToPublic = noPublishToPublic;
}

const std::optional<bool> & NotebookRestrictions::noPublishToBusinessLibrary() const noexcept
{
    return d->m_noPublishToBusinessLibrary;
}

std::optional<bool> & NotebookRestrictions::mutableNoPublishToBusinessLibrary()
{
    return d->m_noPublishToBusinessLibrary;
}

void NotebookRestrictions::setNoPublishToBusinessLibrary(std::optional<bool> noPublishToBusinessLibrary)
{
    d->m_noPublishToBusinessLibrary = noPublishToBusinessLibrary;
}

const std::optional<bool> & NotebookRestrictions::noCreateTags() const noexcept
{
    return d->m_noCreateTags;
}

std::optional<bool> & NotebookRestrictions::mutableNoCreateTags()
{
    return d->m_noCreateTags;
}

void NotebookRestrictions::setNoCreateTags(std::optional<bool> noCreateTags)
{
    d->m_noCreateTags = noCreateTags;
}

const std::optional<bool> & NotebookRestrictions::noUpdateTags() const noexcept
{
    return d->m_noUpdateTags;
}

std::optional<bool> & NotebookRestrictions::mutableNoUpdateTags()
{
    return d->m_noUpdateTags;
}

void NotebookRestrictions::setNoUpdateTags(std::optional<bool> noUpdateTags)
{
    d->m_noUpdateTags = noUpdateTags;
}

const std::optional<bool> & NotebookRestrictions::noExpungeTags() const noexcept
{
    return d->m_noExpungeTags;
}

std::optional<bool> & NotebookRestrictions::mutableNoExpungeTags()
{
    return d->m_noExpungeTags;
}

void NotebookRestrictions::setNoExpungeTags(std::optional<bool> noExpungeTags)
{
    d->m_noExpungeTags = noExpungeTags;
}

const std::optional<bool> & NotebookRestrictions::noSetParentTag() const noexcept
{
    return d->m_noSetParentTag;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetParentTag()
{
    return d->m_noSetParentTag;
}

void NotebookRestrictions::setNoSetParentTag(std::optional<bool> noSetParentTag)
{
    d->m_noSetParentTag = noSetParentTag;
}

const std::optional<bool> & NotebookRestrictions::noCreateSharedNotebooks() const noexcept
{
    return d->m_noCreateSharedNotebooks;
}

std::optional<bool> & NotebookRestrictions::mutableNoCreateSharedNotebooks()
{
    return d->m_noCreateSharedNotebooks;
}

void NotebookRestrictions::setNoCreateSharedNotebooks(std::optional<bool> noCreateSharedNotebooks)
{
    d->m_noCreateSharedNotebooks = noCreateSharedNotebooks;
}

const std::optional<SharedNotebookInstanceRestrictions> & NotebookRestrictions::updateWhichSharedNotebookRestrictions() const noexcept
{
    return d->m_updateWhichSharedNotebookRestrictions;
}

std::optional<SharedNotebookInstanceRestrictions> & NotebookRestrictions::mutableUpdateWhichSharedNotebookRestrictions()
{
    return d->m_updateWhichSharedNotebookRestrictions;
}

void NotebookRestrictions::setUpdateWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions)
{
    d->m_updateWhichSharedNotebookRestrictions = updateWhichSharedNotebookRestrictions;
}

const std::optional<SharedNotebookInstanceRestrictions> & NotebookRestrictions::expungeWhichSharedNotebookRestrictions() const noexcept
{
    return d->m_expungeWhichSharedNotebookRestrictions;
}

std::optional<SharedNotebookInstanceRestrictions> & NotebookRestrictions::mutableExpungeWhichSharedNotebookRestrictions()
{
    return d->m_expungeWhichSharedNotebookRestrictions;
}

void NotebookRestrictions::setExpungeWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions)
{
    d->m_expungeWhichSharedNotebookRestrictions = expungeWhichSharedNotebookRestrictions;
}

const std::optional<bool> & NotebookRestrictions::noShareNotesWithBusiness() const noexcept
{
    return d->m_noShareNotesWithBusiness;
}

std::optional<bool> & NotebookRestrictions::mutableNoShareNotesWithBusiness()
{
    return d->m_noShareNotesWithBusiness;
}

void NotebookRestrictions::setNoShareNotesWithBusiness(std::optional<bool> noShareNotesWithBusiness)
{
    d->m_noShareNotesWithBusiness = noShareNotesWithBusiness;
}

const std::optional<bool> & NotebookRestrictions::noRenameNotebook() const noexcept
{
    return d->m_noRenameNotebook;
}

std::optional<bool> & NotebookRestrictions::mutableNoRenameNotebook()
{
    return d->m_noRenameNotebook;
}

void NotebookRestrictions::setNoRenameNotebook(std::optional<bool> noRenameNotebook)
{
    d->m_noRenameNotebook = noRenameNotebook;
}

const std::optional<bool> & NotebookRestrictions::noSetInMyList() const noexcept
{
    return d->m_noSetInMyList;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetInMyList()
{
    return d->m_noSetInMyList;
}

void NotebookRestrictions::setNoSetInMyList(std::optional<bool> noSetInMyList)
{
    d->m_noSetInMyList = noSetInMyList;
}

const std::optional<bool> & NotebookRestrictions::noChangeContact() const noexcept
{
    return d->m_noChangeContact;
}

std::optional<bool> & NotebookRestrictions::mutableNoChangeContact()
{
    return d->m_noChangeContact;
}

void NotebookRestrictions::setNoChangeContact(std::optional<bool> noChangeContact)
{
    d->m_noChangeContact = noChangeContact;
}

const std::optional<CanMoveToContainerRestrictions> & NotebookRestrictions::canMoveToContainerRestrictions() const noexcept
{
    return d->m_canMoveToContainerRestrictions;
}

std::optional<CanMoveToContainerRestrictions> & NotebookRestrictions::mutableCanMoveToContainerRestrictions()
{
    return d->m_canMoveToContainerRestrictions;
}

void NotebookRestrictions::setCanMoveToContainerRestrictions(std::optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions)
{
    d->m_canMoveToContainerRestrictions = canMoveToContainerRestrictions;
}

const std::optional<bool> & NotebookRestrictions::noSetReminderNotifyEmail() const noexcept
{
    return d->m_noSetReminderNotifyEmail;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetReminderNotifyEmail()
{
    return d->m_noSetReminderNotifyEmail;
}

void NotebookRestrictions::setNoSetReminderNotifyEmail(std::optional<bool> noSetReminderNotifyEmail)
{
    d->m_noSetReminderNotifyEmail = noSetReminderNotifyEmail;
}

const std::optional<bool> & NotebookRestrictions::noSetReminderNotifyInApp() const noexcept
{
    return d->m_noSetReminderNotifyInApp;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetReminderNotifyInApp()
{
    return d->m_noSetReminderNotifyInApp;
}

void NotebookRestrictions::setNoSetReminderNotifyInApp(std::optional<bool> noSetReminderNotifyInApp)
{
    d->m_noSetReminderNotifyInApp = noSetReminderNotifyInApp;
}

const std::optional<bool> & NotebookRestrictions::noSetRecipientSettingsStack() const noexcept
{
    return d->m_noSetRecipientSettingsStack;
}

std::optional<bool> & NotebookRestrictions::mutableNoSetRecipientSettingsStack()
{
    return d->m_noSetRecipientSettingsStack;
}

void NotebookRestrictions::setNoSetRecipientSettingsStack(std::optional<bool> noSetRecipientSettingsStack)
{
    d->m_noSetRecipientSettingsStack = noSetRecipientSettingsStack;
}

const std::optional<bool> & NotebookRestrictions::noCanMoveNote() const noexcept
{
    return d->m_noCanMoveNote;
}

std::optional<bool> & NotebookRestrictions::mutableNoCanMoveNote()
{
    return d->m_noCanMoveNote;
}

void NotebookRestrictions::setNoCanMoveNote(std::optional<bool> noCanMoveNote)
{
    d->m_noCanMoveNote = noCanMoveNote;
}

void NotebookRestrictions::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NotebookRestrictions::operator==(const NotebookRestrictions & other) const noexcept
{
    return *d == *other.d;
}

bool NotebookRestrictions::operator!=(const NotebookRestrictions & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
