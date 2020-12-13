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

#include "NotebookRestrictionsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NotebookRestrictions::Impl::operator==(
    const NotebookRestrictions::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_noReadNotes == other.m_noReadNotes &&
        m_noCreateNotes == other.m_noCreateNotes &&
        m_noUpdateNotes == other.m_noUpdateNotes &&
        m_noExpungeNotes == other.m_noExpungeNotes &&
        m_noShareNotes == other.m_noShareNotes &&
        m_noEmailNotes == other.m_noEmailNotes &&
        m_noSendMessageToRecipients == other.m_noSendMessageToRecipients &&
        m_noUpdateNotebook == other.m_noUpdateNotebook &&
        m_noExpungeNotebook == other.m_noExpungeNotebook &&
        m_noSetDefaultNotebook == other.m_noSetDefaultNotebook &&
        m_noSetNotebookStack == other.m_noSetNotebookStack &&
        m_noPublishToPublic == other.m_noPublishToPublic &&
        m_noPublishToBusinessLibrary == other.m_noPublishToBusinessLibrary &&
        m_noCreateTags == other.m_noCreateTags &&
        m_noUpdateTags == other.m_noUpdateTags &&
        m_noExpungeTags == other.m_noExpungeTags &&
        m_noSetParentTag == other.m_noSetParentTag &&
        m_noCreateSharedNotebooks == other.m_noCreateSharedNotebooks &&
        m_updateWhichSharedNotebookRestrictions == other.m_updateWhichSharedNotebookRestrictions &&
        m_expungeWhichSharedNotebookRestrictions == other.m_expungeWhichSharedNotebookRestrictions &&
        m_noShareNotesWithBusiness == other.m_noShareNotesWithBusiness &&
        m_noRenameNotebook == other.m_noRenameNotebook &&
        m_noSetInMyList == other.m_noSetInMyList &&
        m_noChangeContact == other.m_noChangeContact &&
        m_canMoveToContainerRestrictions == other.m_canMoveToContainerRestrictions &&
        m_noSetReminderNotifyEmail == other.m_noSetReminderNotifyEmail &&
        m_noSetReminderNotifyInApp == other.m_noSetReminderNotifyInApp &&
        m_noSetRecipientSettingsStack == other.m_noSetRecipientSettingsStack &&
        m_noCanMoveNote == other.m_noCanMoveNote;
}

bool NotebookRestrictions::Impl::operator!=(
    const NotebookRestrictions::Impl & other) const noexcept
{
    return !(*this == other);
}

void NotebookRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "NotebookRestrictions: {\n";

    if (m_noReadNotes) {
        strm << "    noReadNotes = "
            << *m_noReadNotes << "\n";
    }
    else {
        strm << "    noReadNotes is not set\n";
    }

    if (m_noCreateNotes) {
        strm << "    noCreateNotes = "
            << *m_noCreateNotes << "\n";
    }
    else {
        strm << "    noCreateNotes is not set\n";
    }

    if (m_noUpdateNotes) {
        strm << "    noUpdateNotes = "
            << *m_noUpdateNotes << "\n";
    }
    else {
        strm << "    noUpdateNotes is not set\n";
    }

    if (m_noExpungeNotes) {
        strm << "    noExpungeNotes = "
            << *m_noExpungeNotes << "\n";
    }
    else {
        strm << "    noExpungeNotes is not set\n";
    }

    if (m_noShareNotes) {
        strm << "    noShareNotes = "
            << *m_noShareNotes << "\n";
    }
    else {
        strm << "    noShareNotes is not set\n";
    }

    if (m_noEmailNotes) {
        strm << "    noEmailNotes = "
            << *m_noEmailNotes << "\n";
    }
    else {
        strm << "    noEmailNotes is not set\n";
    }

    if (m_noSendMessageToRecipients) {
        strm << "    noSendMessageToRecipients = "
            << *m_noSendMessageToRecipients << "\n";
    }
    else {
        strm << "    noSendMessageToRecipients is not set\n";
    }

    if (m_noUpdateNotebook) {
        strm << "    noUpdateNotebook = "
            << *m_noUpdateNotebook << "\n";
    }
    else {
        strm << "    noUpdateNotebook is not set\n";
    }

    if (m_noExpungeNotebook) {
        strm << "    noExpungeNotebook = "
            << *m_noExpungeNotebook << "\n";
    }
    else {
        strm << "    noExpungeNotebook is not set\n";
    }

    if (m_noSetDefaultNotebook) {
        strm << "    noSetDefaultNotebook = "
            << *m_noSetDefaultNotebook << "\n";
    }
    else {
        strm << "    noSetDefaultNotebook is not set\n";
    }

    if (m_noSetNotebookStack) {
        strm << "    noSetNotebookStack = "
            << *m_noSetNotebookStack << "\n";
    }
    else {
        strm << "    noSetNotebookStack is not set\n";
    }

    if (m_noPublishToPublic) {
        strm << "    noPublishToPublic = "
            << *m_noPublishToPublic << "\n";
    }
    else {
        strm << "    noPublishToPublic is not set\n";
    }

    if (m_noPublishToBusinessLibrary) {
        strm << "    noPublishToBusinessLibrary = "
            << *m_noPublishToBusinessLibrary << "\n";
    }
    else {
        strm << "    noPublishToBusinessLibrary is not set\n";
    }

    if (m_noCreateTags) {
        strm << "    noCreateTags = "
            << *m_noCreateTags << "\n";
    }
    else {
        strm << "    noCreateTags is not set\n";
    }

    if (m_noUpdateTags) {
        strm << "    noUpdateTags = "
            << *m_noUpdateTags << "\n";
    }
    else {
        strm << "    noUpdateTags is not set\n";
    }

    if (m_noExpungeTags) {
        strm << "    noExpungeTags = "
            << *m_noExpungeTags << "\n";
    }
    else {
        strm << "    noExpungeTags is not set\n";
    }

    if (m_noSetParentTag) {
        strm << "    noSetParentTag = "
            << *m_noSetParentTag << "\n";
    }
    else {
        strm << "    noSetParentTag is not set\n";
    }

    if (m_noCreateSharedNotebooks) {
        strm << "    noCreateSharedNotebooks = "
            << *m_noCreateSharedNotebooks << "\n";
    }
    else {
        strm << "    noCreateSharedNotebooks is not set\n";
    }

    if (m_updateWhichSharedNotebookRestrictions) {
        strm << "    updateWhichSharedNotebookRestrictions = "
            << *m_updateWhichSharedNotebookRestrictions << "\n";
    }
    else {
        strm << "    updateWhichSharedNotebookRestrictions is not set\n";
    }

    if (m_expungeWhichSharedNotebookRestrictions) {
        strm << "    expungeWhichSharedNotebookRestrictions = "
            << *m_expungeWhichSharedNotebookRestrictions << "\n";
    }
    else {
        strm << "    expungeWhichSharedNotebookRestrictions is not set\n";
    }

    if (m_noShareNotesWithBusiness) {
        strm << "    noShareNotesWithBusiness = "
            << *m_noShareNotesWithBusiness << "\n";
    }
    else {
        strm << "    noShareNotesWithBusiness is not set\n";
    }

    if (m_noRenameNotebook) {
        strm << "    noRenameNotebook = "
            << *m_noRenameNotebook << "\n";
    }
    else {
        strm << "    noRenameNotebook is not set\n";
    }

    if (m_noSetInMyList) {
        strm << "    noSetInMyList = "
            << *m_noSetInMyList << "\n";
    }
    else {
        strm << "    noSetInMyList is not set\n";
    }

    if (m_noChangeContact) {
        strm << "    noChangeContact = "
            << *m_noChangeContact << "\n";
    }
    else {
        strm << "    noChangeContact is not set\n";
    }

    if (m_canMoveToContainerRestrictions) {
        strm << "    canMoveToContainerRestrictions = "
            << *m_canMoveToContainerRestrictions << "\n";
    }
    else {
        strm << "    canMoveToContainerRestrictions is not set\n";
    }

    if (m_noSetReminderNotifyEmail) {
        strm << "    noSetReminderNotifyEmail = "
            << *m_noSetReminderNotifyEmail << "\n";
    }
    else {
        strm << "    noSetReminderNotifyEmail is not set\n";
    }

    if (m_noSetReminderNotifyInApp) {
        strm << "    noSetReminderNotifyInApp = "
            << *m_noSetReminderNotifyInApp << "\n";
    }
    else {
        strm << "    noSetReminderNotifyInApp is not set\n";
    }

    if (m_noSetRecipientSettingsStack) {
        strm << "    noSetRecipientSettingsStack = "
            << *m_noSetRecipientSettingsStack << "\n";
    }
    else {
        strm << "    noSetRecipientSettingsStack is not set\n";
    }

    if (m_noCanMoveNote) {
        strm << "    noCanMoveNote = "
            << *m_noCanMoveNote << "\n";
    }
    else {
        strm << "    noCanMoveNote is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
