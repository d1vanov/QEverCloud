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

#ifndef QEVERCLOUD_GENERATED_SERVERS_H
#define QEVERCLOUD_GENERATED_SERVERS_H

#include "../Export.h"

#include "../Optional.h"
#include "../RequestContext.h"
#include "Constants.h"
#include "Types.h"
#include <QObject>
#include <functional>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The NoteStoreServer class represents 
 * customizable server for NoteStore requests. 
 * It is primarily used for testing of QEverCloud
 */
class QEVERCLOUD_EXPORT NoteStoreServer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(NoteStoreServer)
public:
    explicit NoteStoreServer(QObject * parent = nullptr);

Q_SIGNALS:
    // Signals notifying listeners about incoming requests
    void getSyncStateRequest(
        IRequestContextPtr ctx);

    void getFilteredSyncChunkRequest(
        qint32 afterUSN,
        qint32 maxEntries,
        SyncChunkFilter filter,
        IRequestContextPtr ctx);

    void getLinkedNotebookSyncStateRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void getLinkedNotebookSyncChunkRequest(
        LinkedNotebook linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx);

    void listNotebooksRequest(
        IRequestContextPtr ctx);

    void listAccessibleBusinessNotebooksRequest(
        IRequestContextPtr ctx);

    void getNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getDefaultNotebookRequest(
        IRequestContextPtr ctx);

    void createNotebookRequest(
        Notebook notebook,
        IRequestContextPtr ctx);

    void updateNotebookRequest(
        Notebook notebook,
        IRequestContextPtr ctx);

    void expungeNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void listTagsRequest(
        IRequestContextPtr ctx);

    void listTagsByNotebookRequest(
        Guid notebookGuid,
        IRequestContextPtr ctx);

    void getTagRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createTagRequest(
        Tag tag,
        IRequestContextPtr ctx);

    void updateTagRequest(
        Tag tag,
        IRequestContextPtr ctx);

    void untagAllRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void expungeTagRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void listSearchesRequest(
        IRequestContextPtr ctx);

    void getSearchRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createSearchRequest(
        SavedSearch search,
        IRequestContextPtr ctx);

    void updateSearchRequest(
        SavedSearch search,
        IRequestContextPtr ctx);

    void expungeSearchRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void findNoteOffsetRequest(
        NoteFilter filter,
        Guid guid,
        IRequestContextPtr ctx);

    void findNotesMetadataRequest(
        NoteFilter filter,
        qint32 offset,
        qint32 maxNotes,
        NotesMetadataResultSpec resultSpec,
        IRequestContextPtr ctx);

    void findNoteCountsRequest(
        NoteFilter filter,
        bool withTrash,
        IRequestContextPtr ctx);

    void getNoteWithResultSpecRequest(
        Guid guid,
        NoteResultSpec resultSpec,
        IRequestContextPtr ctx);

    void getNoteRequest(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx);

    void getNoteApplicationDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void setNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx);

    void unsetNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void getNoteContentRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteSearchTextRequest(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx);

    void getResourceSearchTextRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteTagNamesRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createNoteRequest(
        Note note,
        IRequestContextPtr ctx);

    void updateNoteRequest(
        Note note,
        IRequestContextPtr ctx);

    void deleteNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void expungeNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void copyNoteRequest(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx);

    void listNoteVersionsRequest(
        Guid noteGuid,
        IRequestContextPtr ctx);

    void getNoteVersionRequest(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx);

    void getResourceRequest(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx);

    void getResourceApplicationDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void setResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx);

    void unsetResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void updateResourceRequest(
        Resource resource,
        IRequestContextPtr ctx);

    void getResourceDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceByHashRequest(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx);

    void getResourceRecognitionRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceAlternateDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceAttributesRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getPublicNotebookRequest(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx);

    void shareNotebookRequest(
        SharedNotebook sharedNotebook,
        QString message,
        IRequestContextPtr ctx);

    void createOrUpdateNotebookSharesRequest(
        NotebookShareTemplate shareTemplate,
        IRequestContextPtr ctx);

    void updateSharedNotebookRequest(
        SharedNotebook sharedNotebook,
        IRequestContextPtr ctx);

    void setNotebookRecipientSettingsRequest(
        QString notebookGuid,
        NotebookRecipientSettings recipientSettings,
        IRequestContextPtr ctx);

    void listSharedNotebooksRequest(
        IRequestContextPtr ctx);

    void createLinkedNotebookRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void updateLinkedNotebookRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void listLinkedNotebooksRequest(
        IRequestContextPtr ctx);

    void expungeLinkedNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void authenticateToSharedNotebookRequest(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx);

    void getSharedNotebookByAuthRequest(
        IRequestContextPtr ctx);

    void emailNoteRequest(
        NoteEmailParameters parameters,
        IRequestContextPtr ctx);

    void shareNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void stopSharingNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void authenticateToSharedNoteRequest(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx);

    void findRelatedRequest(
        RelatedQuery query,
        RelatedResultSpec resultSpec,
        IRequestContextPtr ctx);

    void updateNoteIfUsnMatchesRequest(
        Note note,
        IRequestContextPtr ctx);

    void manageNotebookSharesRequest(
        ManageNotebookSharesParameters parameters,
        IRequestContextPtr ctx);

    void getNotebookSharesRequest(
        QString notebookGuid,
        IRequestContextPtr ctx);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    void onGetSyncStateRequestReady(SyncState value);
    void onGetFilteredSyncChunkRequestReady(SyncChunk value);
    void onGetLinkedNotebookSyncStateRequestReady(SyncState value);
    void onGetLinkedNotebookSyncChunkRequestReady(SyncChunk value);
    void onListNotebooksRequestReady(QList<Notebook> value);
    void onListAccessibleBusinessNotebooksRequestReady(QList<Notebook> value);
    void onGetNotebookRequestReady(Notebook value);
    void onGetDefaultNotebookRequestReady(Notebook value);
    void onCreateNotebookRequestReady(Notebook value);
    void onUpdateNotebookRequestReady(qint32 value);
    void onExpungeNotebookRequestReady(qint32 value);
    void onListTagsRequestReady(QList<Tag> value);
    void onListTagsByNotebookRequestReady(QList<Tag> value);
    void onGetTagRequestReady(Tag value);
    void onCreateTagRequestReady(Tag value);
    void onUpdateTagRequestReady(qint32 value);
    void onUntagAllRequestReady();
    void onExpungeTagRequestReady(qint32 value);
    void onListSearchesRequestReady(QList<SavedSearch> value);
    void onGetSearchRequestReady(SavedSearch value);
    void onCreateSearchRequestReady(SavedSearch value);
    void onUpdateSearchRequestReady(qint32 value);
    void onExpungeSearchRequestReady(qint32 value);
    void onFindNoteOffsetRequestReady(qint32 value);
    void onFindNotesMetadataRequestReady(NotesMetadataList value);
    void onFindNoteCountsRequestReady(NoteCollectionCounts value);
    void onGetNoteWithResultSpecRequestReady(Note value);
    void onGetNoteRequestReady(Note value);
    void onGetNoteApplicationDataRequestReady(LazyMap value);
    void onGetNoteApplicationDataEntryRequestReady(QString value);
    void onSetNoteApplicationDataEntryRequestReady(qint32 value);
    void onUnsetNoteApplicationDataEntryRequestReady(qint32 value);
    void onGetNoteContentRequestReady(QString value);
    void onGetNoteSearchTextRequestReady(QString value);
    void onGetResourceSearchTextRequestReady(QString value);
    void onGetNoteTagNamesRequestReady(QStringList value);
    void onCreateNoteRequestReady(Note value);
    void onUpdateNoteRequestReady(Note value);
    void onDeleteNoteRequestReady(qint32 value);
    void onExpungeNoteRequestReady(qint32 value);
    void onCopyNoteRequestReady(Note value);
    void onListNoteVersionsRequestReady(QList<NoteVersionId> value);
    void onGetNoteVersionRequestReady(Note value);
    void onGetResourceRequestReady(Resource value);
    void onGetResourceApplicationDataRequestReady(LazyMap value);
    void onGetResourceApplicationDataEntryRequestReady(QString value);
    void onSetResourceApplicationDataEntryRequestReady(qint32 value);
    void onUnsetResourceApplicationDataEntryRequestReady(qint32 value);
    void onUpdateResourceRequestReady(qint32 value);
    void onGetResourceDataRequestReady(QByteArray value);
    void onGetResourceByHashRequestReady(Resource value);
    void onGetResourceRecognitionRequestReady(QByteArray value);
    void onGetResourceAlternateDataRequestReady(QByteArray value);
    void onGetResourceAttributesRequestReady(ResourceAttributes value);
    void onGetPublicNotebookRequestReady(Notebook value);
    void onShareNotebookRequestReady(SharedNotebook value);
    void onCreateOrUpdateNotebookSharesRequestReady(CreateOrUpdateNotebookSharesResult value);
    void onUpdateSharedNotebookRequestReady(qint32 value);
    void onSetNotebookRecipientSettingsRequestReady(Notebook value);
    void onListSharedNotebooksRequestReady(QList<SharedNotebook> value);
    void onCreateLinkedNotebookRequestReady(LinkedNotebook value);
    void onUpdateLinkedNotebookRequestReady(qint32 value);
    void onListLinkedNotebooksRequestReady(QList<LinkedNotebook> value);
    void onExpungeLinkedNotebookRequestReady(qint32 value);
    void onAuthenticateToSharedNotebookRequestReady(AuthenticationResult value);
    void onGetSharedNotebookByAuthRequestReady(SharedNotebook value);
    void onEmailNoteRequestReady();
    void onShareNoteRequestReady(QString value);
    void onStopSharingNoteRequestReady();
    void onAuthenticateToSharedNoteRequestReady(AuthenticationResult value);
    void onFindRelatedRequestReady(RelatedResult value);
    void onUpdateNoteIfUsnMatchesRequestReady(UpdateNoteIfUsnMatchesResult value);
    void onManageNotebookSharesRequestReady(ManageNotebookSharesResult value);
    void onGetNotebookSharesRequestReady(ShareRelationships value);
};

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The UserStoreServer class represents 
 * customizable server for UserStore requests. 
 * It is primarily used for testing of QEverCloud
 */
class QEVERCLOUD_EXPORT UserStoreServer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UserStoreServer)
public:
    explicit UserStoreServer(QObject * parent = nullptr);

Q_SIGNALS:
    // Signals notifying listeners about incoming requests
    void checkVersionRequest(
        QString clientName,
        qint16 edamVersionMajor,
        qint16 edamVersionMinor,
        IRequestContextPtr ctx);

    void getBootstrapInfoRequest(
        QString locale,
        IRequestContextPtr ctx);

    void authenticateLongSessionRequest(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx);

    void completeTwoFactorAuthenticationRequest(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx);

    void revokeLongSessionRequest(
        IRequestContextPtr ctx);

    void authenticateToBusinessRequest(
        IRequestContextPtr ctx);

    void getUserRequest(
        IRequestContextPtr ctx);

    void getPublicUserInfoRequest(
        QString username,
        IRequestContextPtr ctx);

    void getUserUrlsRequest(
        IRequestContextPtr ctx);

    void inviteToBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void removeFromBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void updateBusinessUserIdentifierRequest(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx);

    void listBusinessUsersRequest(
        IRequestContextPtr ctx);

    void listBusinessInvitationsRequest(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx);

    void getAccountLimitsRequest(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    void onCheckVersionRequestReady(bool value);
    void onGetBootstrapInfoRequestReady(BootstrapInfo value);
    void onAuthenticateLongSessionRequestReady(AuthenticationResult value);
    void onCompleteTwoFactorAuthenticationRequestReady(AuthenticationResult value);
    void onRevokeLongSessionRequestReady();
    void onAuthenticateToBusinessRequestReady(AuthenticationResult value);
    void onGetUserRequestReady(User value);
    void onGetPublicUserInfoRequestReady(PublicUserInfo value);
    void onGetUserUrlsRequestReady(UserUrls value);
    void onInviteToBusinessRequestReady();
    void onRemoveFromBusinessRequestReady();
    void onUpdateBusinessUserIdentifierRequestReady();
    void onListBusinessUsersRequestReady(QList<UserProfile> value);
    void onListBusinessInvitationsRequestReady(QList<BusinessInvitation> value);
    void onGetAccountLimitsRequestReady(AccountLimits value);
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SERVERS_H
