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

#ifndef QEVERCLOUD_GENERATED_NOTESTORESERVER
#define QEVERCLOUD_GENERATED_NOTESTORESERVER

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/IRequestContext.h>
#include <qevercloud/Types.h>
#include <QObject>
#include <exception>
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

    // Signals used to send encoded response data
    void getSyncStateRequestReady(
        QByteArray data, QUuid requestId);

    void getFilteredSyncChunkRequestReady(
        QByteArray data, QUuid requestId);

    void getLinkedNotebookSyncStateRequestReady(
        QByteArray data, QUuid requestId);

    void getLinkedNotebookSyncChunkRequestReady(
        QByteArray data, QUuid requestId);

    void listNotebooksRequestReady(
        QByteArray data, QUuid requestId);

    void listAccessibleBusinessNotebooksRequestReady(
        QByteArray data, QUuid requestId);

    void getNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void getDefaultNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void createNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void updateNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void expungeNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void listTagsRequestReady(
        QByteArray data, QUuid requestId);

    void listTagsByNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void getTagRequestReady(
        QByteArray data, QUuid requestId);

    void createTagRequestReady(
        QByteArray data, QUuid requestId);

    void updateTagRequestReady(
        QByteArray data, QUuid requestId);

    void untagAllRequestReady(
        QByteArray data, QUuid requestId);

    void expungeTagRequestReady(
        QByteArray data, QUuid requestId);

    void listSearchesRequestReady(
        QByteArray data, QUuid requestId);

    void getSearchRequestReady(
        QByteArray data, QUuid requestId);

    void createSearchRequestReady(
        QByteArray data, QUuid requestId);

    void updateSearchRequestReady(
        QByteArray data, QUuid requestId);

    void expungeSearchRequestReady(
        QByteArray data, QUuid requestId);

    void findNoteOffsetRequestReady(
        QByteArray data, QUuid requestId);

    void findNotesMetadataRequestReady(
        QByteArray data, QUuid requestId);

    void findNoteCountsRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteWithResultSpecRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteApplicationDataRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void setNoteApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void unsetNoteApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteContentRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteSearchTextRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceSearchTextRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteTagNamesRequestReady(
        QByteArray data, QUuid requestId);

    void createNoteRequestReady(
        QByteArray data, QUuid requestId);

    void updateNoteRequestReady(
        QByteArray data, QUuid requestId);

    void deleteNoteRequestReady(
        QByteArray data, QUuid requestId);

    void expungeNoteRequestReady(
        QByteArray data, QUuid requestId);

    void copyNoteRequestReady(
        QByteArray data, QUuid requestId);

    void listNoteVersionsRequestReady(
        QByteArray data, QUuid requestId);

    void getNoteVersionRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceApplicationDataRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void setResourceApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void unsetResourceApplicationDataEntryRequestReady(
        QByteArray data, QUuid requestId);

    void updateResourceRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceDataRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceByHashRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceRecognitionRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceAlternateDataRequestReady(
        QByteArray data, QUuid requestId);

    void getResourceAttributesRequestReady(
        QByteArray data, QUuid requestId);

    void getPublicNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void shareNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void createOrUpdateNotebookSharesRequestReady(
        QByteArray data, QUuid requestId);

    void updateSharedNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void setNotebookRecipientSettingsRequestReady(
        QByteArray data, QUuid requestId);

    void listSharedNotebooksRequestReady(
        QByteArray data, QUuid requestId);

    void createLinkedNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void updateLinkedNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void listLinkedNotebooksRequestReady(
        QByteArray data, QUuid requestId);

    void expungeLinkedNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void authenticateToSharedNotebookRequestReady(
        QByteArray data, QUuid requestId);

    void getSharedNotebookByAuthRequestReady(
        QByteArray data, QUuid requestId);

    void emailNoteRequestReady(
        QByteArray data, QUuid requestId);

    void shareNoteRequestReady(
        QByteArray data, QUuid requestId);

    void stopSharingNoteRequestReady(
        QByteArray data, QUuid requestId);

    void authenticateToSharedNoteRequestReady(
        QByteArray data, QUuid requestId);

    void findRelatedRequestReady(
        QByteArray data, QUuid requestId);

    void updateNoteIfUsnMatchesRequestReady(
        QByteArray data, QUuid requestId);

    void manageNotebookSharesRequestReady(
        QByteArray data, QUuid requestId);

    void getNotebookSharesRequestReady(
        QByteArray data, QUuid requestId);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data, QUuid requestId);

    // Slots for replies to requests
    void onGetSyncStateRequestReady(
        SyncState value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetFilteredSyncChunkRequestReady(
        SyncChunk value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetLinkedNotebookSyncStateRequestReady(
        SyncState value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetLinkedNotebookSyncChunkRequestReady(
        SyncChunk value,
        std::exception_ptr e,
        QUuid requestId);

    void onListNotebooksRequestReady(
        QList<Notebook> value,
        std::exception_ptr e,
        QUuid requestId);

    void onListAccessibleBusinessNotebooksRequestReady(
        QList<Notebook> value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNotebookRequestReady(
        Notebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetDefaultNotebookRequestReady(
        Notebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateNotebookRequestReady(
        Notebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateNotebookRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onExpungeNotebookRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onListTagsRequestReady(
        QList<Tag> value,
        std::exception_ptr e,
        QUuid requestId);

    void onListTagsByNotebookRequestReady(
        QList<Tag> value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetTagRequestReady(
        Tag value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateTagRequestReady(
        Tag value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateTagRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onUntagAllRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onExpungeTagRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onListSearchesRequestReady(
        QList<SavedSearch> value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetSearchRequestReady(
        SavedSearch value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateSearchRequestReady(
        SavedSearch value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateSearchRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onExpungeSearchRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onFindNoteOffsetRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onFindNotesMetadataRequestReady(
        NotesMetadataList value,
        std::exception_ptr e,
        QUuid requestId);

    void onFindNoteCountsRequestReady(
        NoteCollectionCounts value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteWithResultSpecRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteApplicationDataRequestReady(
        LazyMap value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteApplicationDataEntryRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onSetNoteApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onUnsetNoteApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteContentRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteSearchTextRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceSearchTextRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteTagNamesRequestReady(
        QStringList value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateNoteRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateNoteRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onDeleteNoteRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onExpungeNoteRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onCopyNoteRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onListNoteVersionsRequestReady(
        QList<NoteVersionId> value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNoteVersionRequestReady(
        Note value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceRequestReady(
        Resource value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceApplicationDataRequestReady(
        LazyMap value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceApplicationDataEntryRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onSetResourceApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onUnsetResourceApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateResourceRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceDataRequestReady(
        QByteArray value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceByHashRequestReady(
        Resource value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceRecognitionRequestReady(
        QByteArray value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceAlternateDataRequestReady(
        QByteArray value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetResourceAttributesRequestReady(
        ResourceAttributes value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetPublicNotebookRequestReady(
        Notebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onShareNotebookRequestReady(
        SharedNotebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateOrUpdateNotebookSharesRequestReady(
        CreateOrUpdateNotebookSharesResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateSharedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onSetNotebookRecipientSettingsRequestReady(
        Notebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onListSharedNotebooksRequestReady(
        QList<SharedNotebook> value,
        std::exception_ptr e,
        QUuid requestId);

    void onCreateLinkedNotebookRequestReady(
        LinkedNotebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateLinkedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onListLinkedNotebooksRequestReady(
        QList<LinkedNotebook> value,
        std::exception_ptr e,
        QUuid requestId);

    void onExpungeLinkedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e,
        QUuid requestId);

    void onAuthenticateToSharedNotebookRequestReady(
        AuthenticationResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetSharedNotebookByAuthRequestReady(
        SharedNotebook value,
        std::exception_ptr e,
        QUuid requestId);

    void onEmailNoteRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onShareNoteRequestReady(
        QString value,
        std::exception_ptr e,
        QUuid requestId);

    void onStopSharingNoteRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onAuthenticateToSharedNoteRequestReady(
        AuthenticationResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onFindRelatedRequestReady(
        RelatedResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateNoteIfUsnMatchesRequestReady(
        UpdateNoteIfUsnMatchesResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onManageNotebookSharesRequestReady(
        ManageNotebookSharesResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetNotebookSharesRequestReady(
        ShareRelationships value,
        std::exception_ptr e,
        QUuid requestId);

};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESTORESERVER
