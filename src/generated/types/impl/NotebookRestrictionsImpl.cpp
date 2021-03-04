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

#include "NotebookRestrictionsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

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
