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

#include <generated/Servers.h>
#include "../Impl.h"

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

NoteStoreServer::NoteStoreServer(QObject * parent) :
    QObject(parent)
{}

void NoteStoreServer::onRequest(QByteArray data)
{
    // TODO: implement
    Q_UNUSED(data)
}

void NoteStoreServer::onGetSyncStateRequestReady(SyncState value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetFilteredSyncChunkRequestReady(SyncChunk value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady(SyncState value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady(SyncChunk value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListNotebooksRequestReady(QList<Notebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady(QList<Notebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetDefaultNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListTagsRequestReady(QList<Tag> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListTagsByNotebookRequestReady(QList<Tag> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetTagRequestReady(Tag value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateTagRequestReady(Tag value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateTagRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUntagAllRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onExpungeTagRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListSearchesRequestReady(QList<SavedSearch> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetSearchRequestReady(SavedSearch value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateSearchRequestReady(SavedSearch value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateSearchRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeSearchRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNoteOffsetRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNotesMetadataRequestReady(NotesMetadataList value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNoteCountsRequestReady(NoteCollectionCounts value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteWithResultSpecRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteApplicationDataRequestReady(LazyMap value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteApplicationDataEntryRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetNoteApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteContentRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteSearchTextRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceSearchTextRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteTagNamesRequestReady(QStringList value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onDeleteNoteRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeNoteRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCopyNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListNoteVersionsRequestReady(QList<NoteVersionId> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteVersionRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceRequestReady(Resource value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceApplicationDataRequestReady(LazyMap value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceApplicationDataEntryRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetResourceApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateResourceRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceDataRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceByHashRequestReady(Resource value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceRecognitionRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceAlternateDataRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceAttributesRequestReady(ResourceAttributes value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetPublicNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onShareNotebookRequestReady(SharedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady(CreateOrUpdateNotebookSharesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateSharedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetNotebookRecipientSettingsRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListSharedNotebooksRequestReady(QList<SharedNotebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateLinkedNotebookRequestReady(LinkedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateLinkedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListLinkedNotebooksRequestReady(QList<LinkedNotebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeLinkedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onAuthenticateToSharedNotebookRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetSharedNotebookByAuthRequestReady(SharedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onEmailNoteRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onShareNoteRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onStopSharingNoteRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onAuthenticateToSharedNoteRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindRelatedRequestReady(RelatedResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady(UpdateNoteIfUsnMatchesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onManageNotebookSharesRequestReady(ManageNotebookSharesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNotebookSharesRequestReady(ShareRelationships value)
{
    // TODO: implement
    Q_UNUSED(value)
}

////////////////////////////////////////////////////////////////////////////////

UserStoreServer::UserStoreServer(QObject * parent) :
    QObject(parent)
{}

void UserStoreServer::onRequest(QByteArray data)
{
    // TODO: implement
    Q_UNUSED(data)
}

void UserStoreServer::onCheckVersionRequestReady(bool value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetBootstrapInfoRequestReady(BootstrapInfo value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onAuthenticateLongSessionRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onRevokeLongSessionRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onAuthenticateToBusinessRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetUserRequestReady(User value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetPublicUserInfoRequestReady(PublicUserInfo value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetUserUrlsRequestReady(UserUrls value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onInviteToBusinessRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onRemoveFromBusinessRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onUpdateBusinessUserIdentifierRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onListBusinessUsersRequestReady(QList<UserProfile> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onListBusinessInvitationsRequestReady(QList<BusinessInvitation> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetAccountLimitsRequestReady(AccountLimits value)
{
    // TODO: implement
    Q_UNUSED(value)
}

} // namespace qevercloud
