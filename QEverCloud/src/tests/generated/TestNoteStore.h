/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_TESTNOTESTORE_H
#define QEVERCLOUD_GENERATED_TESTNOTESTORE_H

#include "../Common.h"
#include <QObject>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class NoteStoreTester: public QObject
{
    Q_OBJECT
public:
    explicit NoteStoreTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldExecuteGetSyncState();
    void shouldExecuteGetFilteredSyncChunk();
    void shouldExecuteGetLinkedNotebookSyncState();
    void shouldExecuteGetLinkedNotebookSyncChunk();
    void shouldExecuteListNotebooks();
    void shouldExecuteListAccessibleBusinessNotebooks();
    void shouldExecuteGetNotebook();
    void shouldExecuteGetDefaultNotebook();
    void shouldExecuteCreateNotebook();
    void shouldExecuteUpdateNotebook();
    void shouldExecuteExpungeNotebook();
    void shouldExecuteListTags();
    void shouldExecuteListTagsByNotebook();
    void shouldExecuteGetTag();
    void shouldExecuteCreateTag();
    void shouldExecuteUpdateTag();
    void shouldExecuteUntagAll();
    void shouldExecuteExpungeTag();
    void shouldExecuteListSearches();
    void shouldExecuteGetSearch();
    void shouldExecuteCreateSearch();
    void shouldExecuteUpdateSearch();
    void shouldExecuteExpungeSearch();
    void shouldExecuteFindNoteOffset();
    void shouldExecuteFindNotesMetadata();
    void shouldExecuteFindNoteCounts();
    void shouldExecuteGetNoteWithResultSpec();
    void shouldExecuteGetNote();
    void shouldExecuteGetNoteApplicationData();
    void shouldExecuteGetNoteApplicationDataEntry();
    void shouldExecuteSetNoteApplicationDataEntry();
    void shouldExecuteUnsetNoteApplicationDataEntry();
    void shouldExecuteGetNoteContent();
    void shouldExecuteGetNoteSearchText();
    void shouldExecuteGetResourceSearchText();
    void shouldExecuteGetNoteTagNames();
    void shouldExecuteCreateNote();
    void shouldExecuteUpdateNote();
    void shouldExecuteDeleteNote();
    void shouldExecuteExpungeNote();
    void shouldExecuteCopyNote();
    void shouldExecuteListNoteVersions();
    void shouldExecuteGetNoteVersion();
    void shouldExecuteGetResource();
    void shouldExecuteGetResourceApplicationData();
    void shouldExecuteGetResourceApplicationDataEntry();
    void shouldExecuteSetResourceApplicationDataEntry();
    void shouldExecuteUnsetResourceApplicationDataEntry();
    void shouldExecuteUpdateResource();
    void shouldExecuteGetResourceData();
    void shouldExecuteGetResourceByHash();
    void shouldExecuteGetResourceRecognition();
    void shouldExecuteGetResourceAlternateData();
    void shouldExecuteGetResourceAttributes();
    void shouldExecuteGetPublicNotebook();
    void shouldExecuteShareNotebook();
    void shouldExecuteCreateOrUpdateNotebookShares();
    void shouldExecuteUpdateSharedNotebook();
    void shouldExecuteSetNotebookRecipientSettings();
    void shouldExecuteListSharedNotebooks();
    void shouldExecuteCreateLinkedNotebook();
    void shouldExecuteUpdateLinkedNotebook();
    void shouldExecuteListLinkedNotebooks();
    void shouldExecuteExpungeLinkedNotebook();
    void shouldExecuteAuthenticateToSharedNotebook();
    void shouldExecuteGetSharedNotebookByAuth();
    void shouldExecuteEmailNote();
    void shouldExecuteShareNote();
    void shouldExecuteStopSharingNote();
    void shouldExecuteAuthenticateToSharedNote();
    void shouldExecuteFindRelated();
    void shouldExecuteUpdateNoteIfUsnMatches();
    void shouldExecuteManageNotebookShares();
    void shouldExecuteGetNotebookShares();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTNOTESTORE_H
