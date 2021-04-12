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

#ifndef QEVERCLOUD_GENERATED_NOTESTORESERVER
#define QEVERCLOUD_GENERATED_NOTESTORESERVER

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/RequestContext.h>
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
        QByteArray data);

    void getFilteredSyncChunkRequestReady(
        QByteArray data);

    void getLinkedNotebookSyncStateRequestReady(
        QByteArray data);

    void getLinkedNotebookSyncChunkRequestReady(
        QByteArray data);

    void listNotebooksRequestReady(
        QByteArray data);

    void listAccessibleBusinessNotebooksRequestReady(
        QByteArray data);

    void getNotebookRequestReady(
        QByteArray data);

    void getDefaultNotebookRequestReady(
        QByteArray data);

    void createNotebookRequestReady(
        QByteArray data);

    void updateNotebookRequestReady(
        QByteArray data);

    void expungeNotebookRequestReady(
        QByteArray data);

    void listTagsRequestReady(
        QByteArray data);

    void listTagsByNotebookRequestReady(
        QByteArray data);

    void getTagRequestReady(
        QByteArray data);

    void createTagRequestReady(
        QByteArray data);

    void updateTagRequestReady(
        QByteArray data);

    void untagAllRequestReady(
        QByteArray data);

    void expungeTagRequestReady(
        QByteArray data);

    void listSearchesRequestReady(
        QByteArray data);

    void getSearchRequestReady(
        QByteArray data);

    void createSearchRequestReady(
        QByteArray data);

    void updateSearchRequestReady(
        QByteArray data);

    void expungeSearchRequestReady(
        QByteArray data);

    void findNoteOffsetRequestReady(
        QByteArray data);

    void findNotesMetadataRequestReady(
        QByteArray data);

    void findNoteCountsRequestReady(
        QByteArray data);

    void getNoteWithResultSpecRequestReady(
        QByteArray data);

    void getNoteRequestReady(
        QByteArray data);

    void getNoteApplicationDataRequestReady(
        QByteArray data);

    void getNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void setNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void unsetNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void getNoteContentRequestReady(
        QByteArray data);

    void getNoteSearchTextRequestReady(
        QByteArray data);

    void getResourceSearchTextRequestReady(
        QByteArray data);

    void getNoteTagNamesRequestReady(
        QByteArray data);

    void createNoteRequestReady(
        QByteArray data);

    void updateNoteRequestReady(
        QByteArray data);

    void deleteNoteRequestReady(
        QByteArray data);

    void expungeNoteRequestReady(
        QByteArray data);

    void copyNoteRequestReady(
        QByteArray data);

    void listNoteVersionsRequestReady(
        QByteArray data);

    void getNoteVersionRequestReady(
        QByteArray data);

    void getResourceRequestReady(
        QByteArray data);

    void getResourceApplicationDataRequestReady(
        QByteArray data);

    void getResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void setResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void unsetResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void updateResourceRequestReady(
        QByteArray data);

    void getResourceDataRequestReady(
        QByteArray data);

    void getResourceByHashRequestReady(
        QByteArray data);

    void getResourceRecognitionRequestReady(
        QByteArray data);

    void getResourceAlternateDataRequestReady(
        QByteArray data);

    void getResourceAttributesRequestReady(
        QByteArray data);

    void getPublicNotebookRequestReady(
        QByteArray data);

    void shareNotebookRequestReady(
        QByteArray data);

    void createOrUpdateNotebookSharesRequestReady(
        QByteArray data);

    void updateSharedNotebookRequestReady(
        QByteArray data);

    void setNotebookRecipientSettingsRequestReady(
        QByteArray data);

    void listSharedNotebooksRequestReady(
        QByteArray data);

    void createLinkedNotebookRequestReady(
        QByteArray data);

    void updateLinkedNotebookRequestReady(
        QByteArray data);

    void listLinkedNotebooksRequestReady(
        QByteArray data);

    void expungeLinkedNotebookRequestReady(
        QByteArray data);

    void authenticateToSharedNotebookRequestReady(
        QByteArray data);

    void getSharedNotebookByAuthRequestReady(
        QByteArray data);

    void emailNoteRequestReady(
        QByteArray data);

    void shareNoteRequestReady(
        QByteArray data);

    void stopSharingNoteRequestReady(
        QByteArray data);

    void authenticateToSharedNoteRequestReady(
        QByteArray data);

    void findRelatedRequestReady(
        QByteArray data);

    void updateNoteIfUsnMatchesRequestReady(
        QByteArray data);

    void manageNotebookSharesRequestReady(
        QByteArray data);

    void getNotebookSharesRequestReady(
        QByteArray data);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    // Slots for replies to requests
    void onGetSyncStateRequestReady(
        SyncState value,
        std::exception_ptr e);

    void onGetFilteredSyncChunkRequestReady(
        SyncChunk value,
        std::exception_ptr e);

    void onGetLinkedNotebookSyncStateRequestReady(
        SyncState value,
        std::exception_ptr e);

    void onGetLinkedNotebookSyncChunkRequestReady(
        SyncChunk value,
        std::exception_ptr e);

    void onListNotebooksRequestReady(
        QList<Notebook> value,
        std::exception_ptr e);

    void onListAccessibleBusinessNotebooksRequestReady(
        QList<Notebook> value,
        std::exception_ptr e);

    void onGetNotebookRequestReady(
        Notebook value,
        std::exception_ptr e);

    void onGetDefaultNotebookRequestReady(
        Notebook value,
        std::exception_ptr e);

    void onCreateNotebookRequestReady(
        Notebook value,
        std::exception_ptr e);

    void onUpdateNotebookRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onExpungeNotebookRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onListTagsRequestReady(
        QList<Tag> value,
        std::exception_ptr e);

    void onListTagsByNotebookRequestReady(
        QList<Tag> value,
        std::exception_ptr e);

    void onGetTagRequestReady(
        Tag value,
        std::exception_ptr e);

    void onCreateTagRequestReady(
        Tag value,
        std::exception_ptr e);

    void onUpdateTagRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onUntagAllRequestReady(
        std::exception_ptr e);

    void onExpungeTagRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onListSearchesRequestReady(
        QList<SavedSearch> value,
        std::exception_ptr e);

    void onGetSearchRequestReady(
        SavedSearch value,
        std::exception_ptr e);

    void onCreateSearchRequestReady(
        SavedSearch value,
        std::exception_ptr e);

    void onUpdateSearchRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onExpungeSearchRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onFindNoteOffsetRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onFindNotesMetadataRequestReady(
        NotesMetadataList value,
        std::exception_ptr e);

    void onFindNoteCountsRequestReady(
        NoteCollectionCounts value,
        std::exception_ptr e);

    void onGetNoteWithResultSpecRequestReady(
        Note value,
        std::exception_ptr e);

    void onGetNoteRequestReady(
        Note value,
        std::exception_ptr e);

    void onGetNoteApplicationDataRequestReady(
        LazyMap value,
        std::exception_ptr e);

    void onGetNoteApplicationDataEntryRequestReady(
        QString value,
        std::exception_ptr e);

    void onSetNoteApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onUnsetNoteApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onGetNoteContentRequestReady(
        QString value,
        std::exception_ptr e);

    void onGetNoteSearchTextRequestReady(
        QString value,
        std::exception_ptr e);

    void onGetResourceSearchTextRequestReady(
        QString value,
        std::exception_ptr e);

    void onGetNoteTagNamesRequestReady(
        QStringList value,
        std::exception_ptr e);

    void onCreateNoteRequestReady(
        Note value,
        std::exception_ptr e);

    void onUpdateNoteRequestReady(
        Note value,
        std::exception_ptr e);

    void onDeleteNoteRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onExpungeNoteRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onCopyNoteRequestReady(
        Note value,
        std::exception_ptr e);

    void onListNoteVersionsRequestReady(
        QList<NoteVersionId> value,
        std::exception_ptr e);

    void onGetNoteVersionRequestReady(
        Note value,
        std::exception_ptr e);

    void onGetResourceRequestReady(
        Resource value,
        std::exception_ptr e);

    void onGetResourceApplicationDataRequestReady(
        LazyMap value,
        std::exception_ptr e);

    void onGetResourceApplicationDataEntryRequestReady(
        QString value,
        std::exception_ptr e);

    void onSetResourceApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onUnsetResourceApplicationDataEntryRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onUpdateResourceRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onGetResourceDataRequestReady(
        QByteArray value,
        std::exception_ptr e);

    void onGetResourceByHashRequestReady(
        Resource value,
        std::exception_ptr e);

    void onGetResourceRecognitionRequestReady(
        QByteArray value,
        std::exception_ptr e);

    void onGetResourceAlternateDataRequestReady(
        QByteArray value,
        std::exception_ptr e);

    void onGetResourceAttributesRequestReady(
        ResourceAttributes value,
        std::exception_ptr e);

    void onGetPublicNotebookRequestReady(
        Notebook value,
        std::exception_ptr e);

    void onShareNotebookRequestReady(
        SharedNotebook value,
        std::exception_ptr e);

    void onCreateOrUpdateNotebookSharesRequestReady(
        CreateOrUpdateNotebookSharesResult value,
        std::exception_ptr e);

    void onUpdateSharedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onSetNotebookRecipientSettingsRequestReady(
        Notebook value,
        std::exception_ptr e);

    void onListSharedNotebooksRequestReady(
        QList<SharedNotebook> value,
        std::exception_ptr e);

    void onCreateLinkedNotebookRequestReady(
        LinkedNotebook value,
        std::exception_ptr e);

    void onUpdateLinkedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onListLinkedNotebooksRequestReady(
        QList<LinkedNotebook> value,
        std::exception_ptr e);

    void onExpungeLinkedNotebookRequestReady(
        qint32 value,
        std::exception_ptr e);

    void onAuthenticateToSharedNotebookRequestReady(
        AuthenticationResult value,
        std::exception_ptr e);

    void onGetSharedNotebookByAuthRequestReady(
        SharedNotebook value,
        std::exception_ptr e);

    void onEmailNoteRequestReady(
        std::exception_ptr e);

    void onShareNoteRequestReady(
        QString value,
        std::exception_ptr e);

    void onStopSharingNoteRequestReady(
        std::exception_ptr e);

    void onAuthenticateToSharedNoteRequestReady(
        AuthenticationResult value,
        std::exception_ptr e);

    void onFindRelatedRequestReady(
        RelatedResult value,
        std::exception_ptr e);

    void onUpdateNoteIfUsnMatchesRequestReady(
        UpdateNoteIfUsnMatchesResult value,
        std::exception_ptr e);

    void onManageNotebookSharesRequestReady(
        ManageNotebookSharesResult value,
        std::exception_ptr e);

    void onGetNotebookSharesRequestReady(
        ShareRelationships value,
        std::exception_ptr e);

};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESTORESERVER
