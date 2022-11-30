/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/services/INoteStore.h>
#include "../Impl.h"
#include "../Future.h"
#include "../Http.h"
#include "../Types_io.h"
#include <qevercloud/DurableService.h>
#include <qevercloud/utility/Log.h>
#include <algorithm>
#include <cmath>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN NoteStore: public INoteStore
{
    Q_DISABLE_COPY(NoteStore)
public:
    explicit NoteStore(
            QString noteStoreUrl = {},
            std::optional<Guid> linkedNotebookGuid = {},
            IRequestContextPtr ctx = {}) :
        m_url(std::move(noteStoreUrl)),
        m_linkedNotebookGuid(std::move(linkedNotebookGuid)),
        m_ctx(std::move(ctx))
    {
        if (!m_ctx) {
            m_ctx = newRequestContext();
        }
    }

    NoteStore() :
        m_ctx{newRequestContext()}
    {}

    [[nodiscard]] IRequestContextPtr defaultRequestContext() const override
    {
        return m_ctx;
    }

    void setDefaultRequestContext(IRequestContextPtr ctx) override
    {
        m_ctx = std::move(ctx);
    }

    [[nodiscard]] QString noteStoreUrl() const override
    {
        return m_url;
    }

    void setNoteStoreUrl(QString noteStoreUrl) override
    {
        m_url = std::move(noteStoreUrl);
    }

    [[nodiscard]] const std::optional<Guid> & linkedNotebookGuid() const override
    {
        return m_linkedNotebookGuid;
    }

    void setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid) override
    {
        m_linkedNotebookGuid = std::move(linkedNotebookGuid);
    }

    [[nodiscard]] SyncState getSyncState(
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncState> getSyncStateAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncChunk getFilteredSyncChunk(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncChunk> getFilteredSyncChunkAsync(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncState getLinkedNotebookSyncState(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncState> getLinkedNotebookSyncStateAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncChunk getLinkedNotebookSyncChunk(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncChunk> getLinkedNotebookSyncChunkAsync(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Notebook> listNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Notebook>> listNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Notebook> listAccessibleBusinessNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Notebook>> listAccessibleBusinessNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getDefaultNotebook(
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getDefaultNotebookAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook createNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> createNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Tag> listTags(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Tag>> listTagsAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Tag> listTagsByNotebook(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Tag>> listTagsByNotebookAsync(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Tag getTag(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Tag> getTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Tag createTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    QFuture<Tag> createTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    void untagAll(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> untagAllAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeTag(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<SavedSearch> listSearches(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<SavedSearch>> listSearchesAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SavedSearch getSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<SavedSearch> getSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SavedSearch createSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    QFuture<SavedSearch> createSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 findNoteOffset(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> findNoteOffsetAsync(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] NotesMetadataList findNotesMetadata(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<NotesMetadataList> findNotesMetadataAsync(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] NoteCollectionCounts findNoteCounts(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) override;

    QFuture<NoteCollectionCounts> findNoteCountsAsync(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNoteWithResultSpec(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteWithResultSpecAsync(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNote(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteAsync(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LazyMap getNoteApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<LazyMap> getNoteApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 setNoteApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> setNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 unsetNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> unsetNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteContent(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteContentAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteSearchText(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteSearchTextAsync(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getResourceSearchText(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getResourceSearchTextAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QStringList getNoteTagNames(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QStringList> getNoteTagNamesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note createNote(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> createNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note updateNote(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> updateNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 deleteNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> deleteNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note copyNote(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> copyNoteAsync(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<NoteVersionId> listNoteVersions(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<NoteVersionId>> listNoteVersionsAsync(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNoteVersion(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteVersionAsync(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Resource getResource(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Resource> getResourceAsync(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LazyMap getResourceApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<LazyMap> getResourceApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 setResourceApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> setResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 unsetResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> unsetResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateResource(
        const Resource & resource,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateResourceAsync(
        const Resource & resource,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Resource getResourceByHash(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Resource> getResourceByHashAsync(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceRecognition(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceRecognitionAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceAlternateData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceAlternateDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ResourceAttributes getResourceAttributes(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<ResourceAttributes> getResourceAttributesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getPublicNotebook(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getPublicNotebookAsync(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SharedNotebook shareNotebook(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) override;

    QFuture<SharedNotebook> shareNotebookAsync(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] CreateOrUpdateNotebookSharesResult createOrUpdateNotebookShares(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) override;

    QFuture<CreateOrUpdateNotebookSharesResult> createOrUpdateNotebookSharesAsync(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateSharedNotebook(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateSharedNotebookAsync(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook setNotebookRecipientSettings(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> setNotebookRecipientSettingsAsync(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<SharedNotebook> listSharedNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<SharedNotebook>> listSharedNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LinkedNotebook createLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<LinkedNotebook> createLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<LinkedNotebook> listLinkedNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<LinkedNotebook>> listLinkedNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeLinkedNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeLinkedNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] AuthenticationResult authenticateToSharedNotebook(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) override;

    QFuture<AuthenticationResult> authenticateToSharedNotebookAsync(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SharedNotebook getSharedNotebookByAuth(
        IRequestContextPtr ctx = {}) override;

    QFuture<SharedNotebook> getSharedNotebookByAuthAsync(
        IRequestContextPtr ctx = {}) override;

    void emailNote(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> emailNoteAsync(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString shareNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> shareNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    void stopSharingNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> stopSharingNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] AuthenticationResult authenticateToSharedNote(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) override;

    QFuture<AuthenticationResult> authenticateToSharedNoteAsync(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] RelatedResult findRelated(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<RelatedResult> findRelatedAsync(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] UpdateNoteIfUsnMatchesResult updateNoteIfUsnMatches(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<UpdateNoteIfUsnMatchesResult> updateNoteIfUsnMatchesAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ManageNotebookSharesResult manageNotebookShares(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    QFuture<ManageNotebookSharesResult> manageNotebookSharesAsync(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ShareRelationships getNotebookShares(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<ShareRelationships> getNotebookSharesAsync(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) override;

private:
    QString m_url;
    std::optional<Guid> m_linkedNotebookGuid;
    IRequestContextPtr m_ctx;
};

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetSyncStatePrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreGetSyncStatePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getSyncState"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getSyncState_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SyncState NoteStoreGetSyncStateReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncState result = SyncState();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSyncState")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncState v;
                readSyncState(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getSyncState: missing result"));
    }

    return result;
}

QVariant NoteStoreGetSyncStateReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetSyncStateReadReply(reply));
}

} // namespace

SyncState NoteStore::getSyncState(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getSyncState: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreGetSyncStatePrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetSyncStateReadReply(reply);
}

QFuture<SyncState> NoteStore::getSyncStateAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getSyncStateAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetSyncStatePrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetSyncStateReadReplyAsync);

    return convertFromVariantFuture<SyncState>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetFilteredSyncChunkPrepareParams(
    QString authenticationToken,
    qint32 afterUSN,
    qint32 maxEntries,
    const SyncChunkFilter & filter)
{
    QEC_DEBUG("note_store", "NoteStoreGetFilteredSyncChunkPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getFilteredSyncChunk"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getFilteredSyncChunk_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("afterUSN"),
        ThriftFieldType::T_I32,
        2);

    writer.writeI32(afterUSN);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("maxEntries"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(maxEntries);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("filter"),
        ThriftFieldType::T_STRUCT,
        4);

    writeSyncChunkFilter(writer, filter);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SyncChunk NoteStoreGetFilteredSyncChunkReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncChunk result = SyncChunk();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getFilteredSyncChunk")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncChunk v;
                readSyncChunk(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getFilteredSyncChunk: missing result"));
    }

    return result;
}

QVariant NoteStoreGetFilteredSyncChunkReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetFilteredSyncChunkReadReply(reply));
}

} // namespace

SyncChunk NoteStore::getFilteredSyncChunk(
    qint32 afterUSN,
    qint32 maxEntries,
    const SyncChunkFilter & filter,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getFilteredSyncChunk: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    afterUSN = " << afterUSN << "\n"
        << "    maxEntries = " << maxEntries << "\n"
        << "    filter = " << filter);

    QByteArray params = NoteStoreGetFilteredSyncChunkPrepareParams(
        ctx->authenticationToken(),
        afterUSN,
        maxEntries,
        filter);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetFilteredSyncChunkReadReply(reply);
}

QFuture<SyncChunk> NoteStore::getFilteredSyncChunkAsync(
    qint32 afterUSN,
    qint32 maxEntries,
    const SyncChunkFilter & filter,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getFilteredSyncChunkAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    afterUSN = " << afterUSN << "\n"
        << "    maxEntries = " << maxEntries << "\n"
        << "    filter = " << filter);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetFilteredSyncChunkPrepareParams(
        ctx->authenticationToken(),
        afterUSN,
        maxEntries,
        filter);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetFilteredSyncChunkReadReplyAsync);

    return convertFromVariantFuture<SyncChunk>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetLinkedNotebookSyncStatePrepareParams(
    QString authenticationToken,
    const LinkedNotebook & linkedNotebook)
{
    QEC_DEBUG("note_store", "NoteStoreGetLinkedNotebookSyncStatePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncState"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getLinkedNotebookSyncState_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("linkedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeLinkedNotebook(writer, linkedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SyncState NoteStoreGetLinkedNotebookSyncStateReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncState result = SyncState();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getLinkedNotebookSyncState")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncState v;
                readSyncState(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getLinkedNotebookSyncState: missing result"));
    }

    return result;
}

QVariant NoteStoreGetLinkedNotebookSyncStateReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetLinkedNotebookSyncStateReadReply(reply));
}

} // namespace

SyncState NoteStore::getLinkedNotebookSyncState(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getLinkedNotebookSyncState: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    QByteArray params = NoteStoreGetLinkedNotebookSyncStatePrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetLinkedNotebookSyncStateReadReply(reply);
}

QFuture<SyncState> NoteStore::getLinkedNotebookSyncStateAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getLinkedNotebookSyncStateAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetLinkedNotebookSyncStatePrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetLinkedNotebookSyncStateReadReplyAsync);

    return convertFromVariantFuture<SyncState>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetLinkedNotebookSyncChunkPrepareParams(
    QString authenticationToken,
    const LinkedNotebook & linkedNotebook,
    qint32 afterUSN,
    qint32 maxEntries,
    bool fullSyncOnly)
{
    QEC_DEBUG("note_store", "NoteStoreGetLinkedNotebookSyncChunkPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getLinkedNotebookSyncChunk_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("linkedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeLinkedNotebook(writer, linkedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("afterUSN"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(afterUSN);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("maxEntries"),
        ThriftFieldType::T_I32,
        4);

    writer.writeI32(maxEntries);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("fullSyncOnly"),
        ThriftFieldType::T_BOOL,
        5);

    writer.writeBool(fullSyncOnly);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SyncChunk NoteStoreGetLinkedNotebookSyncChunkReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncChunk result = SyncChunk();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getLinkedNotebookSyncChunk")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncChunk v;
                readSyncChunk(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getLinkedNotebookSyncChunk: missing result"));
    }

    return result;
}

QVariant NoteStoreGetLinkedNotebookSyncChunkReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetLinkedNotebookSyncChunkReadReply(reply));
}

} // namespace

SyncChunk NoteStore::getLinkedNotebookSyncChunk(
    const LinkedNotebook & linkedNotebook,
    qint32 afterUSN,
    qint32 maxEntries,
    bool fullSyncOnly,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getLinkedNotebookSyncChunk: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook << "\n"
        << "    afterUSN = " << afterUSN << "\n"
        << "    maxEntries = " << maxEntries << "\n"
        << "    fullSyncOnly = " << fullSyncOnly);

    QByteArray params = NoteStoreGetLinkedNotebookSyncChunkPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook,
        afterUSN,
        maxEntries,
        fullSyncOnly);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetLinkedNotebookSyncChunkReadReply(reply);
}

QFuture<SyncChunk> NoteStore::getLinkedNotebookSyncChunkAsync(
    const LinkedNotebook & linkedNotebook,
    qint32 afterUSN,
    qint32 maxEntries,
    bool fullSyncOnly,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getLinkedNotebookSyncChunkAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook << "\n"
        << "    afterUSN = " << afterUSN << "\n"
        << "    maxEntries = " << maxEntries << "\n"
        << "    fullSyncOnly = " << fullSyncOnly);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetLinkedNotebookSyncChunkPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook,
        afterUSN,
        maxEntries,
        fullSyncOnly);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetLinkedNotebookSyncChunkReadReplyAsync);

    return convertFromVariantFuture<SyncChunk>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListNotebooksPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListNotebooksPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listNotebooks"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listNotebooks_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<Notebook> NoteStoreListNotebooksReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<Notebook> result = QList<Notebook>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listNotebooks")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listNotebooks.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listNotebooks: missing result"));
    }

    return result;
}

QVariant NoteStoreListNotebooksReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListNotebooksReadReply(reply));
}

} // namespace

QList<Notebook> NoteStore::listNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listNotebooks: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListNotebooksPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListNotebooksReadReply(reply);
}

QFuture<QList<Notebook>> NoteStore::listNotebooksAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listNotebooksAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListNotebooksPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListNotebooksReadReplyAsync);

    return convertFromVariantFuture<QList<Notebook>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListAccessibleBusinessNotebooksPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListAccessibleBusinessNotebooksPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listAccessibleBusinessNotebooks_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<Notebook> NoteStoreListAccessibleBusinessNotebooksReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<Notebook> result = QList<Notebook>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listAccessibleBusinessNotebooks")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listAccessibleBusinessNotebooks.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listAccessibleBusinessNotebooks: missing result"));
    }

    return result;
}

QVariant NoteStoreListAccessibleBusinessNotebooksReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListAccessibleBusinessNotebooksReadReply(reply));
}

} // namespace

QList<Notebook> NoteStore::listAccessibleBusinessNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listAccessibleBusinessNotebooks: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListAccessibleBusinessNotebooksPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListAccessibleBusinessNotebooksReadReply(reply);
}

QFuture<QList<Notebook>> NoteStore::listAccessibleBusinessNotebooksAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listAccessibleBusinessNotebooksAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListAccessibleBusinessNotebooksPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListAccessibleBusinessNotebooksReadReplyAsync);

    return convertFromVariantFuture<QList<Notebook>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNotebookPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Notebook NoteStoreGetNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNotebookReadReply(reply));
}

} // namespace

Notebook NoteStore::getNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNotebookReadReply(reply);
}

QFuture<Notebook> NoteStore::getNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNotebookReadReplyAsync);

    return convertFromVariantFuture<Notebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetDefaultNotebookPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreGetDefaultNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getDefaultNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getDefaultNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Notebook NoteStoreGetDefaultNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getDefaultNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getDefaultNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreGetDefaultNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetDefaultNotebookReadReply(reply));
}

} // namespace

Notebook NoteStore::getDefaultNotebook(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getDefaultNotebook: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreGetDefaultNotebookPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetDefaultNotebookReadReply(reply);
}

QFuture<Notebook> NoteStore::getDefaultNotebookAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getDefaultNotebookAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetDefaultNotebookPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetDefaultNotebookReadReplyAsync);

    return convertFromVariantFuture<Notebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateNotebookPrepareParams(
    QString authenticationToken,
    const Notebook & notebook)
{
    QEC_DEBUG("note_store", "NoteStoreCreateNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNotebook(writer, notebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Notebook NoteStoreCreateNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateNotebookReadReply(reply));
}

} // namespace

Notebook NoteStore::createNotebook(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebook = " << notebook);

    QByteArray params = NoteStoreCreateNotebookPrepareParams(
        ctx->authenticationToken(),
        notebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateNotebookReadReply(reply);
}

QFuture<Notebook> NoteStore::createNotebookAsync(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebook = " << notebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateNotebookPrepareParams(
        ctx->authenticationToken(),
        notebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateNotebookReadReplyAsync);

    return convertFromVariantFuture<Notebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateNotebookPrepareParams(
    QString authenticationToken,
    const Notebook & notebook)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNotebook(writer, notebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateNotebookReadReply(reply));
}

} // namespace

qint32 NoteStore::updateNotebook(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebook = " << notebook);

    QByteArray params = NoteStoreUpdateNotebookPrepareParams(
        ctx->authenticationToken(),
        notebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateNotebookReadReply(reply);
}

QFuture<qint32> NoteStore::updateNotebookAsync(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebook = " << notebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateNotebookPrepareParams(
        ctx->authenticationToken(),
        notebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateNotebookReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreExpungeNotebookPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreExpungeNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("expungeNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_expungeNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreExpungeNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("expungeNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreExpungeNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreExpungeNotebookReadReply(reply));
}

} // namespace

qint32 NoteStore::expungeNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::expungeNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreExpungeNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreExpungeNotebookReadReply(reply);
}

QFuture<qint32> NoteStore::expungeNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::expungeNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreExpungeNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreExpungeNotebookReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListTagsPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListTagsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listTags"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listTags_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<Tag> NoteStoreListTagsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<Tag> result = QList<Tag>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listTags")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listTags.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listTags: missing result"));
    }

    return result;
}

QVariant NoteStoreListTagsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListTagsReadReply(reply));
}

} // namespace

QList<Tag> NoteStore::listTags(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listTags: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListTagsPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListTagsReadReply(reply);
}

QFuture<QList<Tag>> NoteStore::listTagsAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listTagsAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListTagsPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListTagsReadReplyAsync);

    return convertFromVariantFuture<QList<Tag>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListTagsByNotebookPrepareParams(
    QString authenticationToken,
    Guid notebookGuid)
{
    QEC_DEBUG("note_store", "NoteStoreListTagsByNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listTagsByNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listTagsByNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notebookGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(notebookGuid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<Tag> NoteStoreListTagsByNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<Tag> result = QList<Tag>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listTagsByNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listTagsByNotebook.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listTagsByNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreListTagsByNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListTagsByNotebookReadReply(reply));
}

} // namespace

QList<Tag> NoteStore::listTagsByNotebook(
    Guid notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listTagsByNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid);

    QByteArray params = NoteStoreListTagsByNotebookPrepareParams(
        ctx->authenticationToken(),
        notebookGuid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListTagsByNotebookReadReply(reply);
}

QFuture<QList<Tag>> NoteStore::listTagsByNotebookAsync(
    Guid notebookGuid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listTagsByNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListTagsByNotebookPrepareParams(
        ctx->authenticationToken(),
        notebookGuid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListTagsByNotebookReadReplyAsync);

    return convertFromVariantFuture<QList<Tag>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetTagPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetTagPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getTag"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getTag_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Tag NoteStoreGetTagReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Tag result = Tag();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getTag")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Tag v;
                readTag(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getTag: missing result"));
    }

    return result;
}

QVariant NoteStoreGetTagReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetTagReadReply(reply));
}

} // namespace

Tag NoteStore::getTag(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getTag: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetTagPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetTagReadReply(reply);
}

QFuture<Tag> NoteStore::getTagAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getTagAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetTagPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetTagReadReplyAsync);

    return convertFromVariantFuture<Tag>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateTagPrepareParams(
    QString authenticationToken,
    const Tag & tag)
{
    QEC_DEBUG("note_store", "NoteStoreCreateTagPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createTag"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createTag_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("tag"),
        ThriftFieldType::T_STRUCT,
        2);

    writeTag(writer, tag);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Tag NoteStoreCreateTagReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Tag result = Tag();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createTag")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Tag v;
                readTag(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createTag: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateTagReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateTagReadReply(reply));
}

} // namespace

Tag NoteStore::createTag(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createTag: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    tag = " << tag);

    QByteArray params = NoteStoreCreateTagPrepareParams(
        ctx->authenticationToken(),
        tag);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateTagReadReply(reply);
}

QFuture<Tag> NoteStore::createTagAsync(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createTagAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    tag = " << tag);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateTagPrepareParams(
        ctx->authenticationToken(),
        tag);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateTagReadReplyAsync);

    return convertFromVariantFuture<Tag>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateTagPrepareParams(
    QString authenticationToken,
    const Tag & tag)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateTagPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateTag"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateTag_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("tag"),
        ThriftFieldType::T_STRUCT,
        2);

    writeTag(writer, tag);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateTagReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateTag")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateTag: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateTagReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateTagReadReply(reply));
}

} // namespace

qint32 NoteStore::updateTag(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateTag: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    tag = " << tag);

    QByteArray params = NoteStoreUpdateTagPrepareParams(
        ctx->authenticationToken(),
        tag);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateTagReadReply(reply);
}

QFuture<qint32> NoteStore::updateTagAsync(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateTagAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    tag = " << tag);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateTagPrepareParams(
        ctx->authenticationToken(),
        tag);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateTagReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUntagAllPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreUntagAllPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("untagAll"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_untagAll_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void NoteStoreUntagAllReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("untagAll")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

}

QVariant NoteStoreUntagAllReadReplyAsync(QByteArray reply)
{
    NoteStoreUntagAllReadReply(reply);
    return QVariant{};
}

} // namespace

void NoteStore::untagAll(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::untagAll: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreUntagAllPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    NoteStoreUntagAllReadReply(reply);
}

QFuture<void> NoteStore::untagAllAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::untagAllAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUntagAllPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUntagAllReadReplyAsync);

    return convertFromVariantFuture<void>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreExpungeTagPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreExpungeTagPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("expungeTag"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_expungeTag_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreExpungeTagReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeTag")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("expungeTag: missing result"));
    }

    return result;
}

QVariant NoteStoreExpungeTagReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreExpungeTagReadReply(reply));
}

} // namespace

qint32 NoteStore::expungeTag(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::expungeTag: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreExpungeTagPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreExpungeTagReadReply(reply);
}

QFuture<qint32> NoteStore::expungeTagAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::expungeTagAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreExpungeTagPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreExpungeTagReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListSearchesPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListSearchesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listSearches"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listSearches_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<SavedSearch> NoteStoreListSearchesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<SavedSearch> result = QList<SavedSearch>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listSearches")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<SavedSearch> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listSearches.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listSearches: missing result"));
    }

    return result;
}

QVariant NoteStoreListSearchesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListSearchesReadReply(reply));
}

} // namespace

QList<SavedSearch> NoteStore::listSearches(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listSearches: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListSearchesPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListSearchesReadReply(reply);
}

QFuture<QList<SavedSearch>> NoteStore::listSearchesAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listSearchesAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListSearchesPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListSearchesReadReplyAsync);

    return convertFromVariantFuture<QList<SavedSearch>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetSearchPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetSearchPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getSearch"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getSearch_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SavedSearch NoteStoreGetSearchReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SavedSearch result = SavedSearch();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSearch")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SavedSearch v;
                readSavedSearch(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getSearch: missing result"));
    }

    return result;
}

QVariant NoteStoreGetSearchReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetSearchReadReply(reply));
}

} // namespace

SavedSearch NoteStore::getSearch(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getSearch: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetSearchPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetSearchReadReply(reply);
}

QFuture<SavedSearch> NoteStore::getSearchAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getSearchAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetSearchPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetSearchReadReplyAsync);

    return convertFromVariantFuture<SavedSearch>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateSearchPrepareParams(
    QString authenticationToken,
    const SavedSearch & search)
{
    QEC_DEBUG("note_store", "NoteStoreCreateSearchPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createSearch"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createSearch_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("search"),
        ThriftFieldType::T_STRUCT,
        2);

    writeSavedSearch(writer, search);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SavedSearch NoteStoreCreateSearchReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SavedSearch result = SavedSearch();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createSearch")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SavedSearch v;
                readSavedSearch(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createSearch: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateSearchReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateSearchReadReply(reply));
}

} // namespace

SavedSearch NoteStore::createSearch(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createSearch: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    search = " << search);

    QByteArray params = NoteStoreCreateSearchPrepareParams(
        ctx->authenticationToken(),
        search);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateSearchReadReply(reply);
}

QFuture<SavedSearch> NoteStore::createSearchAsync(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createSearchAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    search = " << search);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateSearchPrepareParams(
        ctx->authenticationToken(),
        search);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateSearchReadReplyAsync);

    return convertFromVariantFuture<SavedSearch>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateSearchPrepareParams(
    QString authenticationToken,
    const SavedSearch & search)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateSearchPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateSearch"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateSearch_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("search"),
        ThriftFieldType::T_STRUCT,
        2);

    writeSavedSearch(writer, search);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateSearchReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateSearch")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateSearch: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateSearchReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateSearchReadReply(reply));
}

} // namespace

qint32 NoteStore::updateSearch(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateSearch: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    search = " << search);

    QByteArray params = NoteStoreUpdateSearchPrepareParams(
        ctx->authenticationToken(),
        search);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateSearchReadReply(reply);
}

QFuture<qint32> NoteStore::updateSearchAsync(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateSearchAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    search = " << search);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateSearchPrepareParams(
        ctx->authenticationToken(),
        search);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateSearchReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreExpungeSearchPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreExpungeSearchPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("expungeSearch"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_expungeSearch_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreExpungeSearchReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeSearch")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("expungeSearch: missing result"));
    }

    return result;
}

QVariant NoteStoreExpungeSearchReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreExpungeSearchReadReply(reply));
}

} // namespace

qint32 NoteStore::expungeSearch(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::expungeSearch: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreExpungeSearchPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreExpungeSearchReadReply(reply);
}

QFuture<qint32> NoteStore::expungeSearchAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::expungeSearchAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreExpungeSearchPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreExpungeSearchReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreFindNoteOffsetPrepareParams(
    QString authenticationToken,
    const NoteFilter & filter,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreFindNoteOffsetPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("findNoteOffset"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_findNoteOffset_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("filter"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNoteFilter(writer, filter);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreFindNoteOffsetReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNoteOffset")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("findNoteOffset: missing result"));
    }

    return result;
}

QVariant NoteStoreFindNoteOffsetReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreFindNoteOffsetReadReply(reply));
}

} // namespace

qint32 NoteStore::findNoteOffset(
    const NoteFilter & filter,
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::findNoteOffset: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreFindNoteOffsetPrepareParams(
        ctx->authenticationToken(),
        filter,
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreFindNoteOffsetReadReply(reply);
}

QFuture<qint32> NoteStore::findNoteOffsetAsync(
    const NoteFilter & filter,
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::findNoteOffsetAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreFindNoteOffsetPrepareParams(
        ctx->authenticationToken(),
        filter,
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreFindNoteOffsetReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreFindNotesMetadataPrepareParams(
    QString authenticationToken,
    const NoteFilter & filter,
    qint32 offset,
    qint32 maxNotes,
    const NotesMetadataResultSpec & resultSpec)
{
    QEC_DEBUG("note_store", "NoteStoreFindNotesMetadataPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("findNotesMetadata"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_findNotesMetadata_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("filter"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNoteFilter(writer, filter);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("offset"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(offset);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("maxNotes"),
        ThriftFieldType::T_I32,
        4);

    writer.writeI32(maxNotes);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("resultSpec"),
        ThriftFieldType::T_STRUCT,
        5);

    writeNotesMetadataResultSpec(writer, resultSpec);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

NotesMetadataList NoteStoreFindNotesMetadataReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    NotesMetadataList result = NotesMetadataList();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNotesMetadata")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                NotesMetadataList v;
                readNotesMetadataList(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("findNotesMetadata: missing result"));
    }

    return result;
}

QVariant NoteStoreFindNotesMetadataReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreFindNotesMetadataReadReply(reply));
}

} // namespace

NotesMetadataList NoteStore::findNotesMetadata(
    const NoteFilter & filter,
    qint32 offset,
    qint32 maxNotes,
    const NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::findNotesMetadata: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    offset = " << offset << "\n"
        << "    maxNotes = " << maxNotes << "\n"
        << "    resultSpec = " << resultSpec);

    QByteArray params = NoteStoreFindNotesMetadataPrepareParams(
        ctx->authenticationToken(),
        filter,
        offset,
        maxNotes,
        resultSpec);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreFindNotesMetadataReadReply(reply);
}

QFuture<NotesMetadataList> NoteStore::findNotesMetadataAsync(
    const NoteFilter & filter,
    qint32 offset,
    qint32 maxNotes,
    const NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::findNotesMetadataAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    offset = " << offset << "\n"
        << "    maxNotes = " << maxNotes << "\n"
        << "    resultSpec = " << resultSpec);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreFindNotesMetadataPrepareParams(
        ctx->authenticationToken(),
        filter,
        offset,
        maxNotes,
        resultSpec);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreFindNotesMetadataReadReplyAsync);

    return convertFromVariantFuture<NotesMetadataList>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreFindNoteCountsPrepareParams(
    QString authenticationToken,
    const NoteFilter & filter,
    bool withTrash)
{
    QEC_DEBUG("note_store", "NoteStoreFindNoteCountsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("findNoteCounts"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_findNoteCounts_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("filter"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNoteFilter(writer, filter);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withTrash"),
        ThriftFieldType::T_BOOL,
        3);

    writer.writeBool(withTrash);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

NoteCollectionCounts NoteStoreFindNoteCountsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    NoteCollectionCounts result = NoteCollectionCounts();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNoteCounts")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                NoteCollectionCounts v;
                readNoteCollectionCounts(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("findNoteCounts: missing result"));
    }

    return result;
}

QVariant NoteStoreFindNoteCountsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreFindNoteCountsReadReply(reply));
}

} // namespace

NoteCollectionCounts NoteStore::findNoteCounts(
    const NoteFilter & filter,
    bool withTrash,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::findNoteCounts: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    withTrash = " << withTrash);

    QByteArray params = NoteStoreFindNoteCountsPrepareParams(
        ctx->authenticationToken(),
        filter,
        withTrash);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreFindNoteCountsReadReply(reply);
}

QFuture<NoteCollectionCounts> NoteStore::findNoteCountsAsync(
    const NoteFilter & filter,
    bool withTrash,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::findNoteCountsAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    filter = " << filter << "\n"
        << "    withTrash = " << withTrash);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreFindNoteCountsPrepareParams(
        ctx->authenticationToken(),
        filter,
        withTrash);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreFindNoteCountsReadReplyAsync);

    return convertFromVariantFuture<NoteCollectionCounts>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteWithResultSpecPrepareParams(
    QString authenticationToken,
    Guid guid,
    const NoteResultSpec & resultSpec)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteWithResultSpecPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteWithResultSpec"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteWithResultSpec_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("resultSpec"),
        ThriftFieldType::T_STRUCT,
        3);

    writeNoteResultSpec(writer, resultSpec);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreGetNoteWithResultSpecReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteWithResultSpec")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteWithResultSpec: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteWithResultSpecReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteWithResultSpecReadReply(reply));
}

} // namespace

Note NoteStore::getNoteWithResultSpec(
    Guid guid,
    const NoteResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteWithResultSpec: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    resultSpec = " << resultSpec);

    QByteArray params = NoteStoreGetNoteWithResultSpecPrepareParams(
        ctx->authenticationToken(),
        guid,
        resultSpec);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteWithResultSpecReadReply(reply);
}

QFuture<Note> NoteStore::getNoteWithResultSpecAsync(
    Guid guid,
    const NoteResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteWithResultSpecAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    resultSpec = " << resultSpec);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteWithResultSpecPrepareParams(
        ctx->authenticationToken(),
        guid,
        resultSpec);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteWithResultSpecReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNotePrepareParams(
    QString authenticationToken,
    Guid guid,
    bool withContent,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData)
{
    QEC_DEBUG("note_store", "NoteStoreGetNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withContent"),
        ThriftFieldType::T_BOOL,
        3);

    writer.writeBool(withContent);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesData"),
        ThriftFieldType::T_BOOL,
        4);

    writer.writeBool(withResourcesData);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesRecognition"),
        ThriftFieldType::T_BOOL,
        5);

    writer.writeBool(withResourcesRecognition);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesAlternateData"),
        ThriftFieldType::T_BOOL,
        6);

    writer.writeBool(withResourcesAlternateData);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreGetNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNote: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteReadReply(reply));
}

} // namespace

Note NoteStore::getNote(
    Guid guid,
    bool withContent,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    withContent = " << withContent << "\n"
        << "    withResourcesData = " << withResourcesData << "\n"
        << "    withResourcesRecognition = " << withResourcesRecognition << "\n"
        << "    withResourcesAlternateData = " << withResourcesAlternateData);

    QByteArray params = NoteStoreGetNotePrepareParams(
        ctx->authenticationToken(),
        guid,
        withContent,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteReadReply(reply);
}

QFuture<Note> NoteStore::getNoteAsync(
    Guid guid,
    bool withContent,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    withContent = " << withContent << "\n"
        << "    withResourcesData = " << withResourcesData << "\n"
        << "    withResourcesRecognition = " << withResourcesRecognition << "\n"
        << "    withResourcesAlternateData = " << withResourcesAlternateData);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNotePrepareParams(
        ctx->authenticationToken(),
        guid,
        withContent,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteApplicationDataPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteApplicationDataPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationData"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteApplicationData_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

LazyMap NoteStoreGetNoteApplicationDataReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    LazyMap result = LazyMap();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteApplicationData")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LazyMap v;
                readLazyMap(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteApplicationData: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteApplicationDataReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteApplicationDataReadReply(reply));
}

} // namespace

LazyMap NoteStore::getNoteApplicationData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteApplicationData: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetNoteApplicationDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteApplicationDataReadReply(reply);
}

QFuture<LazyMap> NoteStore::getNoteApplicationDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteApplicationDataAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteApplicationDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteApplicationDataReadReplyAsync);

    return convertFromVariantFuture<LazyMap>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreGetNoteApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteApplicationDataEntryReadReply(reply));
}

} // namespace

QString NoteStore::getNoteApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    QByteArray params = NoteStoreGetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteApplicationDataEntryReadReply(reply);
}

QFuture<QString> NoteStore::getNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreSetNoteApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key,
    QString value)
{
    QEC_DEBUG("note_store", "NoteStoreSetNoteApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("setNoteApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_setNoteApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("value"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreSetNoteApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setNoteApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("setNoteApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreSetNoteApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreSetNoteApplicationDataEntryReadReply(reply));
}

} // namespace

qint32 NoteStore::setNoteApplicationDataEntry(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::setNoteApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key << "\n"
        << "    value = " << value);

    QByteArray params = NoteStoreSetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key,
        value);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreSetNoteApplicationDataEntryReadReply(reply);
}

QFuture<qint32> NoteStore::setNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::setNoteApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key << "\n"
        << "    value = " << value);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreSetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key,
        value);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreSetNoteApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUnsetNoteApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key)
{
    QEC_DEBUG("note_store", "NoteStoreUnsetNoteApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_unsetNoteApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUnsetNoteApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("unsetNoteApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("unsetNoteApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreUnsetNoteApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUnsetNoteApplicationDataEntryReadReply(reply));
}

} // namespace

qint32 NoteStore::unsetNoteApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::unsetNoteApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    QByteArray params = NoteStoreUnsetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUnsetNoteApplicationDataEntryReadReply(reply);
}

QFuture<qint32> NoteStore::unsetNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::unsetNoteApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUnsetNoteApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUnsetNoteApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteContentPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteContentPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteContent"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteContent_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreGetNoteContentReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteContent")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteContent: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteContentReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteContentReadReply(reply));
}

} // namespace

QString NoteStore::getNoteContent(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteContent: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetNoteContentPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteContentReadReply(reply);
}

QFuture<QString> NoteStore::getNoteContentAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteContentAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteContentPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteContentReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteSearchTextPrepareParams(
    QString authenticationToken,
    Guid guid,
    bool noteOnly,
    bool tokenizeForIndexing)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteSearchTextPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteSearchText"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteSearchText_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteOnly"),
        ThriftFieldType::T_BOOL,
        3);

    writer.writeBool(noteOnly);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("tokenizeForIndexing"),
        ThriftFieldType::T_BOOL,
        4);

    writer.writeBool(tokenizeForIndexing);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreGetNoteSearchTextReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteSearchText")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteSearchText: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteSearchTextReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteSearchTextReadReply(reply));
}

} // namespace

QString NoteStore::getNoteSearchText(
    Guid guid,
    bool noteOnly,
    bool tokenizeForIndexing,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteSearchText: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    noteOnly = " << noteOnly << "\n"
        << "    tokenizeForIndexing = " << tokenizeForIndexing);

    QByteArray params = NoteStoreGetNoteSearchTextPrepareParams(
        ctx->authenticationToken(),
        guid,
        noteOnly,
        tokenizeForIndexing);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteSearchTextReadReply(reply);
}

QFuture<QString> NoteStore::getNoteSearchTextAsync(
    Guid guid,
    bool noteOnly,
    bool tokenizeForIndexing,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteSearchTextAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    noteOnly = " << noteOnly << "\n"
        << "    tokenizeForIndexing = " << tokenizeForIndexing);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteSearchTextPrepareParams(
        ctx->authenticationToken(),
        guid,
        noteOnly,
        tokenizeForIndexing);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteSearchTextReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceSearchTextPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceSearchTextPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceSearchText"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceSearchText_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreGetResourceSearchTextReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceSearchText")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceSearchText: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceSearchTextReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceSearchTextReadReply(reply));
}

} // namespace

QString NoteStore::getResourceSearchText(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceSearchText: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceSearchTextPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceSearchTextReadReply(reply);
}

QFuture<QString> NoteStore::getResourceSearchTextAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceSearchTextAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceSearchTextPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceSearchTextReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteTagNamesPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteTagNamesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteTagNames"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteTagNames_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QStringList NoteStoreGetNoteTagNamesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QStringList result = QStringList();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteTagNames")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (getNoteTagNames.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteTagNames: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteTagNamesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteTagNamesReadReply(reply));
}

} // namespace

QStringList NoteStore::getNoteTagNames(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteTagNames: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetNoteTagNamesPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteTagNamesReadReply(reply);
}

QFuture<QStringList> NoteStore::getNoteTagNamesAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteTagNamesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteTagNamesPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteTagNamesReadReplyAsync);

    return convertFromVariantFuture<QStringList>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateNotePrepareParams(
    QString authenticationToken,
    const Note & note)
{
    QEC_DEBUG("note_store", "NoteStoreCreateNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("note"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNote(writer, note);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreCreateNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createNote: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateNoteReadReply(reply));
}

} // namespace

Note NoteStore::createNote(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    QByteArray params = NoteStoreCreateNotePrepareParams(
        ctx->authenticationToken(),
        note);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateNoteReadReply(reply);
}

QFuture<Note> NoteStore::createNoteAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateNotePrepareParams(
        ctx->authenticationToken(),
        note);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateNoteReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateNotePrepareParams(
    QString authenticationToken,
    const Note & note)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("note"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNote(writer, note);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreUpdateNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateNote: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateNoteReadReply(reply));
}

} // namespace

Note NoteStore::updateNote(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    QByteArray params = NoteStoreUpdateNotePrepareParams(
        ctx->authenticationToken(),
        note);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateNoteReadReply(reply);
}

QFuture<Note> NoteStore::updateNoteAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateNotePrepareParams(
        ctx->authenticationToken(),
        note);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateNoteReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreDeleteNotePrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreDeleteNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("deleteNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_deleteNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreDeleteNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("deleteNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("deleteNote: missing result"));
    }

    return result;
}

QVariant NoteStoreDeleteNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreDeleteNoteReadReply(reply));
}

} // namespace

qint32 NoteStore::deleteNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::deleteNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreDeleteNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreDeleteNoteReadReply(reply);
}

QFuture<qint32> NoteStore::deleteNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::deleteNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreDeleteNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreDeleteNoteReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreExpungeNotePrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreExpungeNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("expungeNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_expungeNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreExpungeNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("expungeNote: missing result"));
    }

    return result;
}

QVariant NoteStoreExpungeNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreExpungeNoteReadReply(reply));
}

} // namespace

qint32 NoteStore::expungeNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::expungeNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreExpungeNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreExpungeNoteReadReply(reply);
}

QFuture<qint32> NoteStore::expungeNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::expungeNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreExpungeNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreExpungeNoteReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCopyNotePrepareParams(
    QString authenticationToken,
    Guid noteGuid,
    Guid toNotebookGuid)
{
    QEC_DEBUG("note_store", "NoteStoreCopyNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("copyNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_copyNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(noteGuid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("toNotebookGuid"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(toNotebookGuid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreCopyNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("copyNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("copyNote: missing result"));
    }

    return result;
}

QVariant NoteStoreCopyNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCopyNoteReadReply(reply));
}

} // namespace

Note NoteStore::copyNote(
    Guid noteGuid,
    Guid toNotebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::copyNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    toNotebookGuid = " << toNotebookGuid);

    QByteArray params = NoteStoreCopyNotePrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        toNotebookGuid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCopyNoteReadReply(reply);
}

QFuture<Note> NoteStore::copyNoteAsync(
    Guid noteGuid,
    Guid toNotebookGuid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::copyNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    toNotebookGuid = " << toNotebookGuid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCopyNotePrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        toNotebookGuid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCopyNoteReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListNoteVersionsPrepareParams(
    QString authenticationToken,
    Guid noteGuid)
{
    QEC_DEBUG("note_store", "NoteStoreListNoteVersionsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listNoteVersions"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listNoteVersions_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(noteGuid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<NoteVersionId> NoteStoreListNoteVersionsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<NoteVersionId> result = QList<NoteVersionId>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listNoteVersions")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<NoteVersionId> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listNoteVersions.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteVersionId elem;
                    readNoteVersionId(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listNoteVersions: missing result"));
    }

    return result;
}

QVariant NoteStoreListNoteVersionsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListNoteVersionsReadReply(reply));
}

} // namespace

QList<NoteVersionId> NoteStore::listNoteVersions(
    Guid noteGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listNoteVersions: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid);

    QByteArray params = NoteStoreListNoteVersionsPrepareParams(
        ctx->authenticationToken(),
        noteGuid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListNoteVersionsReadReply(reply);
}

QFuture<QList<NoteVersionId>> NoteStore::listNoteVersionsAsync(
    Guid noteGuid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listNoteVersionsAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListNoteVersionsPrepareParams(
        ctx->authenticationToken(),
        noteGuid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListNoteVersionsReadReplyAsync);

    return convertFromVariantFuture<QList<NoteVersionId>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNoteVersionPrepareParams(
    QString authenticationToken,
    Guid noteGuid,
    qint32 updateSequenceNum,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData)
{
    QEC_DEBUG("note_store", "NoteStoreGetNoteVersionPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNoteVersion"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNoteVersion_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(noteGuid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("updateSequenceNum"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(updateSequenceNum);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesData"),
        ThriftFieldType::T_BOOL,
        4);

    writer.writeBool(withResourcesData);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesRecognition"),
        ThriftFieldType::T_BOOL,
        5);

    writer.writeBool(withResourcesRecognition);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withResourcesAlternateData"),
        ThriftFieldType::T_BOOL,
        6);

    writer.writeBool(withResourcesAlternateData);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Note NoteStoreGetNoteVersionReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteVersion")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNoteVersion: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNoteVersionReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNoteVersionReadReply(reply));
}

} // namespace

Note NoteStore::getNoteVersion(
    Guid noteGuid,
    qint32 updateSequenceNum,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNoteVersion: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    updateSequenceNum = " << updateSequenceNum << "\n"
        << "    withResourcesData = " << withResourcesData << "\n"
        << "    withResourcesRecognition = " << withResourcesRecognition << "\n"
        << "    withResourcesAlternateData = " << withResourcesAlternateData);

    QByteArray params = NoteStoreGetNoteVersionPrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        updateSequenceNum,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNoteVersionReadReply(reply);
}

QFuture<Note> NoteStore::getNoteVersionAsync(
    Guid noteGuid,
    qint32 updateSequenceNum,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNoteVersionAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    updateSequenceNum = " << updateSequenceNum << "\n"
        << "    withResourcesData = " << withResourcesData << "\n"
        << "    withResourcesRecognition = " << withResourcesRecognition << "\n"
        << "    withResourcesAlternateData = " << withResourcesAlternateData);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNoteVersionPrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        updateSequenceNum,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNoteVersionReadReplyAsync);

    return convertFromVariantFuture<Note>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourcePrepareParams(
    QString authenticationToken,
    Guid guid,
    bool withData,
    bool withRecognition,
    bool withAttributes,
    bool withAlternateData)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourcePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResource"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResource_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withData"),
        ThriftFieldType::T_BOOL,
        3);

    writer.writeBool(withData);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withRecognition"),
        ThriftFieldType::T_BOOL,
        4);

    writer.writeBool(withRecognition);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withAttributes"),
        ThriftFieldType::T_BOOL,
        5);

    writer.writeBool(withAttributes);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withAlternateData"),
        ThriftFieldType::T_BOOL,
        6);

    writer.writeBool(withAlternateData);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Resource NoteStoreGetResourceReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Resource result = Resource();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResource")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Resource v;
                readResource(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResource: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceReadReply(reply));
}

} // namespace

Resource NoteStore::getResource(
    Guid guid,
    bool withData,
    bool withRecognition,
    bool withAttributes,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResource: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    withData = " << withData << "\n"
        << "    withRecognition = " << withRecognition << "\n"
        << "    withAttributes = " << withAttributes << "\n"
        << "    withAlternateData = " << withAlternateData);

    QByteArray params = NoteStoreGetResourcePrepareParams(
        ctx->authenticationToken(),
        guid,
        withData,
        withRecognition,
        withAttributes,
        withAlternateData);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceReadReply(reply);
}

QFuture<Resource> NoteStore::getResourceAsync(
    Guid guid,
    bool withData,
    bool withRecognition,
    bool withAttributes,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    withData = " << withData << "\n"
        << "    withRecognition = " << withRecognition << "\n"
        << "    withAttributes = " << withAttributes << "\n"
        << "    withAlternateData = " << withAlternateData);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourcePrepareParams(
        ctx->authenticationToken(),
        guid,
        withData,
        withRecognition,
        withAttributes,
        withAlternateData);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceReadReplyAsync);

    return convertFromVariantFuture<Resource>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceApplicationDataPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceApplicationDataPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationData"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceApplicationData_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

LazyMap NoteStoreGetResourceApplicationDataReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    LazyMap result = LazyMap();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceApplicationData")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LazyMap v;
                readLazyMap(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceApplicationData: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceApplicationDataReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceApplicationDataReadReply(reply));
}

} // namespace

LazyMap NoteStore::getResourceApplicationData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceApplicationData: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceApplicationDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceApplicationDataReadReply(reply);
}

QFuture<LazyMap> NoteStore::getResourceApplicationDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceApplicationDataAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceApplicationDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceApplicationDataReadReplyAsync);

    return convertFromVariantFuture<LazyMap>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreGetResourceApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceApplicationDataEntryReadReply(reply));
}

} // namespace

QString NoteStore::getResourceApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    QByteArray params = NoteStoreGetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceApplicationDataEntryReadReply(reply);
}

QFuture<QString> NoteStore::getResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreSetResourceApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key,
    QString value)
{
    QEC_DEBUG("note_store", "NoteStoreSetResourceApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("setResourceApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_setResourceApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("value"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreSetResourceApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setResourceApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("setResourceApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreSetResourceApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreSetResourceApplicationDataEntryReadReply(reply));
}

} // namespace

qint32 NoteStore::setResourceApplicationDataEntry(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::setResourceApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key << "\n"
        << "    value = " << value);

    QByteArray params = NoteStoreSetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key,
        value);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreSetResourceApplicationDataEntryReadReply(reply);
}

QFuture<qint32> NoteStore::setResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::setResourceApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key << "\n"
        << "    value = " << value);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreSetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key,
        value);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreSetResourceApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUnsetResourceApplicationDataEntryPrepareParams(
    QString authenticationToken,
    Guid guid,
    QString key)
{
    QEC_DEBUG("note_store", "NoteStoreUnsetResourceApplicationDataEntryPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_unsetResourceApplicationDataEntry_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("key"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(key);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUnsetResourceApplicationDataEntryReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("unsetResourceApplicationDataEntry")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("unsetResourceApplicationDataEntry: missing result"));
    }

    return result;
}

QVariant NoteStoreUnsetResourceApplicationDataEntryReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUnsetResourceApplicationDataEntryReadReply(reply));
}

} // namespace

qint32 NoteStore::unsetResourceApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::unsetResourceApplicationDataEntry: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    QByteArray params = NoteStoreUnsetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUnsetResourceApplicationDataEntryReadReply(reply);
}

QFuture<qint32> NoteStore::unsetResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::unsetResourceApplicationDataEntryAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    key = " << key);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUnsetResourceApplicationDataEntryPrepareParams(
        ctx->authenticationToken(),
        guid,
        key);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUnsetResourceApplicationDataEntryReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateResourcePrepareParams(
    QString authenticationToken,
    const Resource & resource)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateResourcePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateResource"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateResource_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("resource"),
        ThriftFieldType::T_STRUCT,
        2);

    writeResource(writer, resource);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateResourceReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateResource")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateResource: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateResourceReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateResourceReadReply(reply));
}

} // namespace

qint32 NoteStore::updateResource(
    const Resource & resource,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateResource: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    resource = " << resource);

    QByteArray params = NoteStoreUpdateResourcePrepareParams(
        ctx->authenticationToken(),
        resource);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateResourceReadReply(reply);
}

QFuture<qint32> NoteStore::updateResourceAsync(
    const Resource & resource,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateResourceAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    resource = " << resource);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateResourcePrepareParams(
        ctx->authenticationToken(),
        resource);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateResourceReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceDataPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceDataPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceData"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceData_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QByteArray NoteStoreGetResourceDataReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceData")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                reader.readBinary(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceData: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceDataReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceDataReadReply(reply));
}

} // namespace

QByteArray NoteStore::getResourceData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceData: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceDataReadReply(reply);
}

QFuture<QByteArray> NoteStore::getResourceDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceDataAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceDataReadReplyAsync);

    return convertFromVariantFuture<QByteArray>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceByHashPrepareParams(
    QString authenticationToken,
    Guid noteGuid,
    QByteArray contentHash,
    bool withData,
    bool withRecognition,
    bool withAlternateData)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceByHashPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceByHash"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceByHash_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(noteGuid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("contentHash"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeBinary(contentHash);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withData"),
        ThriftFieldType::T_BOOL,
        4);

    writer.writeBool(withData);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withRecognition"),
        ThriftFieldType::T_BOOL,
        5);

    writer.writeBool(withRecognition);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("withAlternateData"),
        ThriftFieldType::T_BOOL,
        6);

    writer.writeBool(withAlternateData);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Resource NoteStoreGetResourceByHashReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Resource result = Resource();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceByHash")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Resource v;
                readResource(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceByHash: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceByHashReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceByHashReadReply(reply));
}

} // namespace

Resource NoteStore::getResourceByHash(
    Guid noteGuid,
    QByteArray contentHash,
    bool withData,
    bool withRecognition,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceByHash: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    contentHash = " << contentHash << "\n"
        << "    withData = " << withData << "\n"
        << "    withRecognition = " << withRecognition << "\n"
        << "    withAlternateData = " << withAlternateData);

    QByteArray params = NoteStoreGetResourceByHashPrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        contentHash,
        withData,
        withRecognition,
        withAlternateData);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceByHashReadReply(reply);
}

QFuture<Resource> NoteStore::getResourceByHashAsync(
    Guid noteGuid,
    QByteArray contentHash,
    bool withData,
    bool withRecognition,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceByHashAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    noteGuid = " << noteGuid << "\n"
        << "    contentHash = " << contentHash << "\n"
        << "    withData = " << withData << "\n"
        << "    withRecognition = " << withRecognition << "\n"
        << "    withAlternateData = " << withAlternateData);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceByHashPrepareParams(
        ctx->authenticationToken(),
        noteGuid,
        contentHash,
        withData,
        withRecognition,
        withAlternateData);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceByHashReadReplyAsync);

    return convertFromVariantFuture<Resource>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceRecognitionPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceRecognitionPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceRecognition"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceRecognition_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QByteArray NoteStoreGetResourceRecognitionReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceRecognition")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                reader.readBinary(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceRecognition: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceRecognitionReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceRecognitionReadReply(reply));
}

} // namespace

QByteArray NoteStore::getResourceRecognition(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceRecognition: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceRecognitionPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceRecognitionReadReply(reply);
}

QFuture<QByteArray> NoteStore::getResourceRecognitionAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceRecognitionAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceRecognitionPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceRecognitionReadReplyAsync);

    return convertFromVariantFuture<QByteArray>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceAlternateDataPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceAlternateDataPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceAlternateData"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceAlternateData_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QByteArray NoteStoreGetResourceAlternateDataReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceAlternateData")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                reader.readBinary(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceAlternateData: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceAlternateDataReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceAlternateDataReadReply(reply));
}

} // namespace

QByteArray NoteStore::getResourceAlternateData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceAlternateData: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceAlternateDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceAlternateDataReadReply(reply);
}

QFuture<QByteArray> NoteStore::getResourceAlternateDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceAlternateDataAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceAlternateDataPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceAlternateDataReadReplyAsync);

    return convertFromVariantFuture<QByteArray>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetResourceAttributesPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreGetResourceAttributesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getResourceAttributes"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getResourceAttributes_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

ResourceAttributes NoteStoreGetResourceAttributesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    ResourceAttributes result = ResourceAttributes();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceAttributes")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ResourceAttributes v;
                readResourceAttributes(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getResourceAttributes: missing result"));
    }

    return result;
}

QVariant NoteStoreGetResourceAttributesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetResourceAttributesReadReply(reply));
}

} // namespace

ResourceAttributes NoteStore::getResourceAttributes(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getResourceAttributes: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreGetResourceAttributesPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetResourceAttributesReadReply(reply);
}

QFuture<ResourceAttributes> NoteStore::getResourceAttributesAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getResourceAttributesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetResourceAttributesPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetResourceAttributesReadReplyAsync);

    return convertFromVariantFuture<ResourceAttributes>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetPublicNotebookPrepareParams(
    UserID userId,
    QString publicUri)
{
    QEC_DEBUG("note_store", "NoteStoreGetPublicNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getPublicNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getPublicNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("userId"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(userId);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("publicUri"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(publicUri);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Notebook NoteStoreGetPublicNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getPublicNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getPublicNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreGetPublicNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetPublicNotebookReadReply(reply));
}

} // namespace

Notebook NoteStore::getPublicNotebook(
    UserID userId,
    QString publicUri,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getPublicNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    userId = " << userId << "\n"
        << "    publicUri = " << publicUri);

    QByteArray params = NoteStoreGetPublicNotebookPrepareParams(
        userId,
        publicUri);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetPublicNotebookReadReply(reply);
}

QFuture<Notebook> NoteStore::getPublicNotebookAsync(
    UserID userId,
    QString publicUri,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getPublicNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    userId = " << userId << "\n"
        << "    publicUri = " << publicUri);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetPublicNotebookPrepareParams(
        userId,
        publicUri);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetPublicNotebookReadReplyAsync);

    return convertFromVariantFuture<Notebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreShareNotebookPrepareParams(
    QString authenticationToken,
    const SharedNotebook & sharedNotebook,
    QString message)
{
    QEC_DEBUG("note_store", "NoteStoreShareNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("shareNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_shareNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("sharedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeSharedNotebook(writer, sharedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("message"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(message);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SharedNotebook NoteStoreShareNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SharedNotebook result = SharedNotebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("shareNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SharedNotebook v;
                readSharedNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("shareNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreShareNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreShareNotebookReadReply(reply));
}

} // namespace

SharedNotebook NoteStore::shareNotebook(
    const SharedNotebook & sharedNotebook,
    QString message,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::shareNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    sharedNotebook = " << sharedNotebook << "\n"
        << "    message = " << message);

    QByteArray params = NoteStoreShareNotebookPrepareParams(
        ctx->authenticationToken(),
        sharedNotebook,
        message);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreShareNotebookReadReply(reply);
}

QFuture<SharedNotebook> NoteStore::shareNotebookAsync(
    const SharedNotebook & sharedNotebook,
    QString message,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::shareNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    sharedNotebook = " << sharedNotebook << "\n"
        << "    message = " << message);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreShareNotebookPrepareParams(
        ctx->authenticationToken(),
        sharedNotebook,
        message);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreShareNotebookReadReplyAsync);

    return convertFromVariantFuture<SharedNotebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateOrUpdateNotebookSharesPrepareParams(
    QString authenticationToken,
    const NotebookShareTemplate & shareTemplate)
{
    QEC_DEBUG("note_store", "NoteStoreCreateOrUpdateNotebookSharesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createOrUpdateNotebookShares"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createOrUpdateNotebookShares_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("shareTemplate"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNotebookShareTemplate(writer, shareTemplate);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

CreateOrUpdateNotebookSharesResult NoteStoreCreateOrUpdateNotebookSharesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    CreateOrUpdateNotebookSharesResult result = CreateOrUpdateNotebookSharesResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createOrUpdateNotebookShares")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                CreateOrUpdateNotebookSharesResult v;
                readCreateOrUpdateNotebookSharesResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMInvalidContactsException e;
                readEDAMInvalidContactsException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createOrUpdateNotebookShares: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateOrUpdateNotebookSharesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateOrUpdateNotebookSharesReadReply(reply));
}

} // namespace

CreateOrUpdateNotebookSharesResult NoteStore::createOrUpdateNotebookShares(
    const NotebookShareTemplate & shareTemplate,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createOrUpdateNotebookShares: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    shareTemplate = " << shareTemplate);

    QByteArray params = NoteStoreCreateOrUpdateNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        shareTemplate);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateOrUpdateNotebookSharesReadReply(reply);
}

QFuture<CreateOrUpdateNotebookSharesResult> NoteStore::createOrUpdateNotebookSharesAsync(
    const NotebookShareTemplate & shareTemplate,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createOrUpdateNotebookSharesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    shareTemplate = " << shareTemplate);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateOrUpdateNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        shareTemplate);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateOrUpdateNotebookSharesReadReplyAsync);

    return convertFromVariantFuture<CreateOrUpdateNotebookSharesResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateSharedNotebookPrepareParams(
    QString authenticationToken,
    const SharedNotebook & sharedNotebook)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateSharedNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateSharedNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateSharedNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("sharedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeSharedNotebook(writer, sharedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateSharedNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateSharedNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateSharedNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateSharedNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateSharedNotebookReadReply(reply));
}

} // namespace

qint32 NoteStore::updateSharedNotebook(
    const SharedNotebook & sharedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateSharedNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    sharedNotebook = " << sharedNotebook);

    QByteArray params = NoteStoreUpdateSharedNotebookPrepareParams(
        ctx->authenticationToken(),
        sharedNotebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateSharedNotebookReadReply(reply);
}

QFuture<qint32> NoteStore::updateSharedNotebookAsync(
    const SharedNotebook & sharedNotebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateSharedNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    sharedNotebook = " << sharedNotebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateSharedNotebookPrepareParams(
        ctx->authenticationToken(),
        sharedNotebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateSharedNotebookReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreSetNotebookRecipientSettingsPrepareParams(
    QString authenticationToken,
    QString notebookGuid,
    const NotebookRecipientSettings & recipientSettings)
{
    QEC_DEBUG("note_store", "NoteStoreSetNotebookRecipientSettingsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("setNotebookRecipientSettings"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_setNotebookRecipientSettings_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notebookGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(notebookGuid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("recipientSettings"),
        ThriftFieldType::T_STRUCT,
        3);

    writeNotebookRecipientSettings(writer, recipientSettings);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

Notebook NoteStoreSetNotebookRecipientSettingsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setNotebookRecipientSettings")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("setNotebookRecipientSettings: missing result"));
    }

    return result;
}

QVariant NoteStoreSetNotebookRecipientSettingsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreSetNotebookRecipientSettingsReadReply(reply));
}

} // namespace

Notebook NoteStore::setNotebookRecipientSettings(
    QString notebookGuid,
    const NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::setNotebookRecipientSettings: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid << "\n"
        << "    recipientSettings = " << recipientSettings);

    QByteArray params = NoteStoreSetNotebookRecipientSettingsPrepareParams(
        ctx->authenticationToken(),
        notebookGuid,
        recipientSettings);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreSetNotebookRecipientSettingsReadReply(reply);
}

QFuture<Notebook> NoteStore::setNotebookRecipientSettingsAsync(
    QString notebookGuid,
    const NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::setNotebookRecipientSettingsAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid << "\n"
        << "    recipientSettings = " << recipientSettings);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreSetNotebookRecipientSettingsPrepareParams(
        ctx->authenticationToken(),
        notebookGuid,
        recipientSettings);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreSetNotebookRecipientSettingsReadReplyAsync);

    return convertFromVariantFuture<Notebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListSharedNotebooksPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListSharedNotebooksPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listSharedNotebooks"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listSharedNotebooks_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<SharedNotebook> NoteStoreListSharedNotebooksReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<SharedNotebook> result = QList<SharedNotebook>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listSharedNotebooks")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listSharedNotebooks.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listSharedNotebooks: missing result"));
    }

    return result;
}

QVariant NoteStoreListSharedNotebooksReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListSharedNotebooksReadReply(reply));
}

} // namespace

QList<SharedNotebook> NoteStore::listSharedNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listSharedNotebooks: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListSharedNotebooksPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListSharedNotebooksReadReply(reply);
}

QFuture<QList<SharedNotebook>> NoteStore::listSharedNotebooksAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listSharedNotebooksAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListSharedNotebooksPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListSharedNotebooksReadReplyAsync);

    return convertFromVariantFuture<QList<SharedNotebook>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreCreateLinkedNotebookPrepareParams(
    QString authenticationToken,
    const LinkedNotebook & linkedNotebook)
{
    QEC_DEBUG("note_store", "NoteStoreCreateLinkedNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("createLinkedNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_createLinkedNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("linkedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeLinkedNotebook(writer, linkedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

LinkedNotebook NoteStoreCreateLinkedNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    LinkedNotebook result = LinkedNotebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createLinkedNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("createLinkedNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreCreateLinkedNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreCreateLinkedNotebookReadReply(reply));
}

} // namespace

LinkedNotebook NoteStore::createLinkedNotebook(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::createLinkedNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    QByteArray params = NoteStoreCreateLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreCreateLinkedNotebookReadReply(reply);
}

QFuture<LinkedNotebook> NoteStore::createLinkedNotebookAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::createLinkedNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreCreateLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreCreateLinkedNotebookReadReplyAsync);

    return convertFromVariantFuture<LinkedNotebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateLinkedNotebookPrepareParams(
    QString authenticationToken,
    const LinkedNotebook & linkedNotebook)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateLinkedNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateLinkedNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateLinkedNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("linkedNotebook"),
        ThriftFieldType::T_STRUCT,
        2);

    writeLinkedNotebook(writer, linkedNotebook);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreUpdateLinkedNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateLinkedNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateLinkedNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateLinkedNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateLinkedNotebookReadReply(reply));
}

} // namespace

qint32 NoteStore::updateLinkedNotebook(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateLinkedNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    QByteArray params = NoteStoreUpdateLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateLinkedNotebookReadReply(reply);
}

QFuture<qint32> NoteStore::updateLinkedNotebookAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateLinkedNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    linkedNotebook = " << linkedNotebook);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        linkedNotebook);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateLinkedNotebookReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreListLinkedNotebooksPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreListLinkedNotebooksPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listLinkedNotebooks"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_listLinkedNotebooks_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<LinkedNotebook> NoteStoreListLinkedNotebooksReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<LinkedNotebook> result = QList<LinkedNotebook>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listLinkedNotebooks")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<LinkedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listLinkedNotebooks.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listLinkedNotebooks: missing result"));
    }

    return result;
}

QVariant NoteStoreListLinkedNotebooksReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreListLinkedNotebooksReadReply(reply));
}

} // namespace

QList<LinkedNotebook> NoteStore::listLinkedNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::listLinkedNotebooks: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreListLinkedNotebooksPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreListLinkedNotebooksReadReply(reply);
}

QFuture<QList<LinkedNotebook>> NoteStore::listLinkedNotebooksAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::listLinkedNotebooksAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreListLinkedNotebooksPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreListLinkedNotebooksReadReplyAsync);

    return convertFromVariantFuture<QList<LinkedNotebook>>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreExpungeLinkedNotebookPrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreExpungeLinkedNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("expungeLinkedNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_expungeLinkedNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

qint32 NoteStoreExpungeLinkedNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeLinkedNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                reader.readI32(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("expungeLinkedNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreExpungeLinkedNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreExpungeLinkedNotebookReadReply(reply));
}

} // namespace

qint32 NoteStore::expungeLinkedNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::expungeLinkedNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreExpungeLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreExpungeLinkedNotebookReadReply(reply);
}

QFuture<qint32> NoteStore::expungeLinkedNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::expungeLinkedNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreExpungeLinkedNotebookPrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreExpungeLinkedNotebookReadReplyAsync);

    return convertFromVariantFuture<qint32>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreAuthenticateToSharedNotebookPrepareParams(
    QString shareKeyOrGlobalId,
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreAuthenticateToSharedNotebookPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNotebook"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_authenticateToSharedNotebook_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("shareKeyOrGlobalId"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(shareKeyOrGlobalId);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AuthenticationResult NoteStoreAuthenticateToSharedNotebookReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToSharedNotebook")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("authenticateToSharedNotebook: missing result"));
    }

    return result;
}

QVariant NoteStoreAuthenticateToSharedNotebookReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreAuthenticateToSharedNotebookReadReply(reply));
}

} // namespace

AuthenticationResult NoteStore::authenticateToSharedNotebook(
    QString shareKeyOrGlobalId,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::authenticateToSharedNotebook: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    shareKeyOrGlobalId = " << shareKeyOrGlobalId);

    QByteArray params = NoteStoreAuthenticateToSharedNotebookPrepareParams(
        shareKeyOrGlobalId,
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreAuthenticateToSharedNotebookReadReply(reply);
}

QFuture<AuthenticationResult> NoteStore::authenticateToSharedNotebookAsync(
    QString shareKeyOrGlobalId,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::authenticateToSharedNotebookAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    shareKeyOrGlobalId = " << shareKeyOrGlobalId);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreAuthenticateToSharedNotebookPrepareParams(
        shareKeyOrGlobalId,
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreAuthenticateToSharedNotebookReadReplyAsync);

    return convertFromVariantFuture<AuthenticationResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetSharedNotebookByAuthPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreGetSharedNotebookByAuthPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getSharedNotebookByAuth"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getSharedNotebookByAuth_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

SharedNotebook NoteStoreGetSharedNotebookByAuthReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    SharedNotebook result = SharedNotebook();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSharedNotebookByAuth")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SharedNotebook v;
                readSharedNotebook(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getSharedNotebookByAuth: missing result"));
    }

    return result;
}

QVariant NoteStoreGetSharedNotebookByAuthReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetSharedNotebookByAuthReadReply(reply));
}

} // namespace

SharedNotebook NoteStore::getSharedNotebookByAuth(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getSharedNotebookByAuth: request id = "
        << ctx->requestId());

    QByteArray params = NoteStoreGetSharedNotebookByAuthPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetSharedNotebookByAuthReadReply(reply);
}

QFuture<SharedNotebook> NoteStore::getSharedNotebookByAuthAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getSharedNotebookByAuthAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetSharedNotebookByAuthPrepareParams(
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetSharedNotebookByAuthReadReplyAsync);

    return convertFromVariantFuture<SharedNotebook>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreEmailNotePrepareParams(
    QString authenticationToken,
    const NoteEmailParameters & parameters)
{
    QEC_DEBUG("note_store", "NoteStoreEmailNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("emailNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_emailNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("parameters"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNoteEmailParameters(writer, parameters);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void NoteStoreEmailNoteReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("emailNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

}

QVariant NoteStoreEmailNoteReadReplyAsync(QByteArray reply)
{
    NoteStoreEmailNoteReadReply(reply);
    return QVariant{};
}

} // namespace

void NoteStore::emailNote(
    const NoteEmailParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::emailNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    parameters = " << parameters);

    QByteArray params = NoteStoreEmailNotePrepareParams(
        ctx->authenticationToken(),
        parameters);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    NoteStoreEmailNoteReadReply(reply);
}

QFuture<void> NoteStore::emailNoteAsync(
    const NoteEmailParameters & parameters,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::emailNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    parameters = " << parameters);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreEmailNotePrepareParams(
        ctx->authenticationToken(),
        parameters);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreEmailNoteReadReplyAsync);

    return convertFromVariantFuture<void>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreShareNotePrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreShareNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("shareNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_shareNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QString NoteStoreShareNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("shareNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                reader.readString(v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("shareNote: missing result"));
    }

    return result;
}

QVariant NoteStoreShareNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreShareNoteReadReply(reply));
}

} // namespace

QString NoteStore::shareNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::shareNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreShareNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreShareNoteReadReply(reply);
}

QFuture<QString> NoteStore::shareNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::shareNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreShareNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreShareNoteReadReplyAsync);

    return convertFromVariantFuture<QString>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreStopSharingNotePrepareParams(
    QString authenticationToken,
    Guid guid)
{
    QEC_DEBUG("note_store", "NoteStoreStopSharingNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("stopSharingNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_stopSharingNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void NoteStoreStopSharingNoteReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("stopSharingNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

}

QVariant NoteStoreStopSharingNoteReadReplyAsync(QByteArray reply)
{
    NoteStoreStopSharingNoteReadReply(reply);
    return QVariant{};
}

} // namespace

void NoteStore::stopSharingNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::stopSharingNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    QByteArray params = NoteStoreStopSharingNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    NoteStoreStopSharingNoteReadReply(reply);
}

QFuture<void> NoteStore::stopSharingNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::stopSharingNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreStopSharingNotePrepareParams(
        ctx->authenticationToken(),
        guid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreStopSharingNoteReadReplyAsync);

    return convertFromVariantFuture<void>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreAuthenticateToSharedNotePrepareParams(
    QString guid,
    QString noteKey,
    QString authenticationToken)
{
    QEC_DEBUG("note_store", "NoteStoreAuthenticateToSharedNotePrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNote"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_authenticateToSharedNote_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(guid);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("noteKey"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(noteKey);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AuthenticationResult NoteStoreAuthenticateToSharedNoteReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToSharedNote")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("authenticateToSharedNote: missing result"));
    }

    return result;
}

QVariant NoteStoreAuthenticateToSharedNoteReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreAuthenticateToSharedNoteReadReply(reply));
}

} // namespace

AuthenticationResult NoteStore::authenticateToSharedNote(
    QString guid,
    QString noteKey,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::authenticateToSharedNote: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    noteKey = " << noteKey);

    QByteArray params = NoteStoreAuthenticateToSharedNotePrepareParams(
        guid,
        noteKey,
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreAuthenticateToSharedNoteReadReply(reply);
}

QFuture<AuthenticationResult> NoteStore::authenticateToSharedNoteAsync(
    QString guid,
    QString noteKey,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::authenticateToSharedNoteAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    guid = " << guid << "\n"
        << "    noteKey = " << noteKey);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreAuthenticateToSharedNotePrepareParams(
        guid,
        noteKey,
        ctx->authenticationToken());

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreAuthenticateToSharedNoteReadReplyAsync);

    return convertFromVariantFuture<AuthenticationResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreFindRelatedPrepareParams(
    QString authenticationToken,
    const RelatedQuery & query,
    const RelatedResultSpec & resultSpec)
{
    QEC_DEBUG("note_store", "NoteStoreFindRelatedPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("findRelated"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_findRelated_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("query"),
        ThriftFieldType::T_STRUCT,
        2);

    writeRelatedQuery(writer, query);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("resultSpec"),
        ThriftFieldType::T_STRUCT,
        3);

    writeRelatedResultSpec(writer, resultSpec);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

RelatedResult NoteStoreFindRelatedReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    RelatedResult result = RelatedResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findRelated")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                RelatedResult v;
                readRelatedResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("findRelated: missing result"));
    }

    return result;
}

QVariant NoteStoreFindRelatedReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreFindRelatedReadReply(reply));
}

} // namespace

RelatedResult NoteStore::findRelated(
    const RelatedQuery & query,
    const RelatedResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::findRelated: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    query = " << query << "\n"
        << "    resultSpec = " << resultSpec);

    QByteArray params = NoteStoreFindRelatedPrepareParams(
        ctx->authenticationToken(),
        query,
        resultSpec);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreFindRelatedReadReply(reply);
}

QFuture<RelatedResult> NoteStore::findRelatedAsync(
    const RelatedQuery & query,
    const RelatedResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::findRelatedAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    query = " << query << "\n"
        << "    resultSpec = " << resultSpec);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreFindRelatedPrepareParams(
        ctx->authenticationToken(),
        query,
        resultSpec);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreFindRelatedReadReplyAsync);

    return convertFromVariantFuture<RelatedResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreUpdateNoteIfUsnMatchesPrepareParams(
    QString authenticationToken,
    const Note & note)
{
    QEC_DEBUG("note_store", "NoteStoreUpdateNoteIfUsnMatchesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateNoteIfUsnMatches"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_updateNoteIfUsnMatches_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("note"),
        ThriftFieldType::T_STRUCT,
        2);

    writeNote(writer, note);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

UpdateNoteIfUsnMatchesResult NoteStoreUpdateNoteIfUsnMatchesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    UpdateNoteIfUsnMatchesResult result = UpdateNoteIfUsnMatchesResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNoteIfUsnMatches")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                UpdateNoteIfUsnMatchesResult v;
                readUpdateNoteIfUsnMatchesResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("updateNoteIfUsnMatches: missing result"));
    }

    return result;
}

QVariant NoteStoreUpdateNoteIfUsnMatchesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreUpdateNoteIfUsnMatchesReadReply(reply));
}

} // namespace

UpdateNoteIfUsnMatchesResult NoteStore::updateNoteIfUsnMatches(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::updateNoteIfUsnMatches: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    QByteArray params = NoteStoreUpdateNoteIfUsnMatchesPrepareParams(
        ctx->authenticationToken(),
        note);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreUpdateNoteIfUsnMatchesReadReply(reply);
}

QFuture<UpdateNoteIfUsnMatchesResult> NoteStore::updateNoteIfUsnMatchesAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::updateNoteIfUsnMatchesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    note = " << note);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreUpdateNoteIfUsnMatchesPrepareParams(
        ctx->authenticationToken(),
        note);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreUpdateNoteIfUsnMatchesReadReplyAsync);

    return convertFromVariantFuture<UpdateNoteIfUsnMatchesResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreManageNotebookSharesPrepareParams(
    QString authenticationToken,
    const ManageNotebookSharesParameters & parameters)
{
    QEC_DEBUG("note_store", "NoteStoreManageNotebookSharesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("manageNotebookShares"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_manageNotebookShares_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("parameters"),
        ThriftFieldType::T_STRUCT,
        2);

    writeManageNotebookSharesParameters(writer, parameters);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

ManageNotebookSharesResult NoteStoreManageNotebookSharesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    ManageNotebookSharesResult result = ManageNotebookSharesResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("manageNotebookShares")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ManageNotebookSharesResult v;
                readManageNotebookSharesResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("manageNotebookShares: missing result"));
    }

    return result;
}

QVariant NoteStoreManageNotebookSharesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreManageNotebookSharesReadReply(reply));
}

} // namespace

ManageNotebookSharesResult NoteStore::manageNotebookShares(
    const ManageNotebookSharesParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::manageNotebookShares: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    parameters = " << parameters);

    QByteArray params = NoteStoreManageNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        parameters);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreManageNotebookSharesReadReply(reply);
}

QFuture<ManageNotebookSharesResult> NoteStore::manageNotebookSharesAsync(
    const ManageNotebookSharesParameters & parameters,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::manageNotebookSharesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    parameters = " << parameters);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreManageNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        parameters);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreManageNotebookSharesReadReplyAsync);

    return convertFromVariantFuture<ManageNotebookSharesResult>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray NoteStoreGetNotebookSharesPrepareParams(
    QString authenticationToken,
    QString notebookGuid)
{
    QEC_DEBUG("note_store", "NoteStoreGetNotebookSharesPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getNotebookShares"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("NoteStore_getNotebookShares_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notebookGuid"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(notebookGuid);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

ShareRelationships NoteStoreGetNotebookSharesReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    ShareRelationships result = ShareRelationships();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNotebookShares")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ShareRelationships v;
                readShareRelationships(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getNotebookShares: missing result"));
    }

    return result;
}

QVariant NoteStoreGetNotebookSharesReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStoreGetNotebookSharesReadReply(reply));
}

} // namespace

ShareRelationships NoteStore::getNotebookShares(
    QString notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("note_store", "NoteStore::getNotebookShares: request id = "
        << ctx->requestId());
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid);

    QByteArray params = NoteStoreGetNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        notebookGuid);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("note_store", "received reply for request with id = "
        << ctx->requestId());
    return NoteStoreGetNotebookSharesReadReply(reply);
}

QFuture<ShareRelationships> NoteStore::getNotebookSharesAsync(
    QString notebookGuid,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("note_store", "NoteStore::getNotebookSharesAsync");
    QEC_TRACE("note_store", "Parameters:\n"
        << "    notebookGuid = " << notebookGuid);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = NoteStoreGetNotebookSharesPrepareParams(
        ctx->authenticationToken(),
        notebookGuid);

    auto variantFuture = sendRequest(
        m_url,
        params,
        ctx,
        NoteStoreGetNotebookSharesReadReplyAsync);

    return convertFromVariantFuture<ShareRelationships>(std::move(variantFuture));
}

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN DurableNoteStore: public INoteStore
{
    Q_DISABLE_COPY(DurableNoteStore)
public:
    explicit DurableNoteStore(
            INoteStorePtr service,
            IRequestContextPtr ctx = {},
            IRetryPolicyPtr retryPolicy = newRetryPolicy()) :
        m_service(std::move(service)),
        m_durableService(newDurableService(retryPolicy, ctx)),
        m_ctx(std::move(ctx))
    {
        if (!m_ctx) {
            m_ctx = newRequestContext();
        }
    }

    ~DurableNoteStore() = default;

    [[nodiscard]] IRequestContextPtr defaultRequestContext() const override
    {
        return m_service->defaultRequestContext();
    }

    void setDefaultRequestContext(IRequestContextPtr ctx) override
    {
        m_service->setDefaultRequestContext(std::move(ctx));
    }

    [[nodiscard]] QString noteStoreUrl() const override
    {
        return m_service->noteStoreUrl();
    }

    void setNoteStoreUrl(QString noteStoreUrl) override
    {
        m_service->setNoteStoreUrl(noteStoreUrl);
    }

    [[nodiscard]] const std::optional<Guid> & linkedNotebookGuid() const override
    {
        return m_service->linkedNotebookGuid();
    }

    void setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid) override
    {
        m_service->setLinkedNotebookGuid(std::move(linkedNotebookGuid));
    }

    [[nodiscard]] SyncState getSyncState(
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncState> getSyncStateAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncChunk getFilteredSyncChunk(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncChunk> getFilteredSyncChunkAsync(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncState getLinkedNotebookSyncState(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncState> getLinkedNotebookSyncStateAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SyncChunk getLinkedNotebookSyncChunk(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) override;

    QFuture<SyncChunk> getLinkedNotebookSyncChunkAsync(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Notebook> listNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Notebook>> listNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Notebook> listAccessibleBusinessNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Notebook>> listAccessibleBusinessNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getDefaultNotebook(
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getDefaultNotebookAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook createNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> createNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Tag> listTags(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Tag>> listTagsAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<Tag> listTagsByNotebook(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<Tag>> listTagsByNotebookAsync(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Tag getTag(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Tag> getTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Tag createTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    QFuture<Tag> createTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) override;

    void untagAll(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> untagAllAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeTag(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<SavedSearch> listSearches(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<SavedSearch>> listSearchesAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SavedSearch getSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<SavedSearch> getSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SavedSearch createSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    QFuture<SavedSearch> createSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 findNoteOffset(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> findNoteOffsetAsync(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] NotesMetadataList findNotesMetadata(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<NotesMetadataList> findNotesMetadataAsync(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] NoteCollectionCounts findNoteCounts(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) override;

    QFuture<NoteCollectionCounts> findNoteCountsAsync(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNoteWithResultSpec(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteWithResultSpecAsync(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNote(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteAsync(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LazyMap getNoteApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<LazyMap> getNoteApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 setNoteApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> setNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 unsetNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> unsetNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteContent(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteContentAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getNoteSearchText(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getNoteSearchTextAsync(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getResourceSearchText(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getResourceSearchTextAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QStringList getNoteTagNames(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QStringList> getNoteTagNamesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note createNote(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> createNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note updateNote(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> updateNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 deleteNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> deleteNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note copyNote(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> copyNoteAsync(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<NoteVersionId> listNoteVersions(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<NoteVersionId>> listNoteVersionsAsync(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Note getNoteVersion(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Note> getNoteVersionAsync(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Resource getResource(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Resource> getResourceAsync(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LazyMap getResourceApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<LazyMap> getResourceApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString getResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> getResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 setResourceApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> setResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 unsetResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> unsetResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateResource(
        const Resource & resource,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateResourceAsync(
        const Resource & resource,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Resource getResourceByHash(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    QFuture<Resource> getResourceByHashAsync(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceRecognition(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceRecognitionAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray getResourceAlternateData(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QByteArray> getResourceAlternateDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ResourceAttributes getResourceAttributes(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<ResourceAttributes> getResourceAttributesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook getPublicNotebook(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> getPublicNotebookAsync(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SharedNotebook shareNotebook(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) override;

    QFuture<SharedNotebook> shareNotebookAsync(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] CreateOrUpdateNotebookSharesResult createOrUpdateNotebookShares(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) override;

    QFuture<CreateOrUpdateNotebookSharesResult> createOrUpdateNotebookSharesAsync(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateSharedNotebook(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateSharedNotebookAsync(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] Notebook setNotebookRecipientSettings(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) override;

    QFuture<Notebook> setNotebookRecipientSettingsAsync(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<SharedNotebook> listSharedNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<SharedNotebook>> listSharedNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] LinkedNotebook createLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<LinkedNotebook> createLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 updateLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> updateLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QList<LinkedNotebook> listLinkedNotebooks(
        IRequestContextPtr ctx = {}) override;

    QFuture<QList<LinkedNotebook>> listLinkedNotebooksAsync(
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] qint32 expungeLinkedNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<qint32> expungeLinkedNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] AuthenticationResult authenticateToSharedNotebook(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) override;

    QFuture<AuthenticationResult> authenticateToSharedNotebookAsync(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] SharedNotebook getSharedNotebookByAuth(
        IRequestContextPtr ctx = {}) override;

    QFuture<SharedNotebook> getSharedNotebookByAuthAsync(
        IRequestContextPtr ctx = {}) override;

    void emailNote(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> emailNoteAsync(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QString shareNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<QString> shareNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    void stopSharingNote(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    QFuture<void> stopSharingNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] AuthenticationResult authenticateToSharedNote(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) override;

    QFuture<AuthenticationResult> authenticateToSharedNoteAsync(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] RelatedResult findRelated(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    QFuture<RelatedResult> findRelatedAsync(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] UpdateNoteIfUsnMatchesResult updateNoteIfUsnMatches(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    QFuture<UpdateNoteIfUsnMatchesResult> updateNoteIfUsnMatchesAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ManageNotebookSharesResult manageNotebookShares(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    QFuture<ManageNotebookSharesResult> manageNotebookSharesAsync(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) override;

    [[nodiscard]] ShareRelationships getNotebookShares(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) override;

    QFuture<ShareRelationships> getNotebookSharesAsync(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) override;

private:
    INoteStorePtr m_service;
    IDurableServicePtr m_durableService;
    IRequestContextPtr m_ctx;
};

SyncState DurableNoteStore::getSyncState(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getSyncState(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "getSyncState",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SyncState>();
}

QFuture<SyncState> DurableNoteStore::getSyncStateAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SyncState>(service->getSyncStateAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "getSyncState",
        {},
        std::move(call));

    return convertFromVariantFuture<SyncState>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SyncChunk DurableNoteStore::getFilteredSyncChunk(
    qint32 afterUSN,
    qint32 maxEntries,
    const SyncChunkFilter & filter,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getFilteredSyncChunk(
                afterUSN,
                maxEntries,
                filter,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "afterUSN = " << afterUSN << "\n";
        strm << "maxEntries = " << maxEntries << "\n";
        strm << "filter = " << filter << "\n";
    }

    IDurableService::SyncRequest request(
        "getFilteredSyncChunk",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SyncChunk>();
}

QFuture<SyncChunk> DurableNoteStore::getFilteredSyncChunkAsync(
    qint32 afterUSN,
    qint32 maxEntries,
    const SyncChunkFilter & filter,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SyncChunk>(service->getFilteredSyncChunkAsync(
                afterUSN,
                maxEntries,
                filter,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "afterUSN = " << afterUSN << "\n";
        strm << "maxEntries = " << maxEntries << "\n";
        strm << "filter = " << filter << "\n";
    }

    IDurableService::AsyncRequest request(
        "getFilteredSyncChunk",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SyncChunk>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SyncState DurableNoteStore::getLinkedNotebookSyncState(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getLinkedNotebookSyncState(
                linkedNotebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::SyncRequest request(
        "getLinkedNotebookSyncState",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SyncState>();
}

QFuture<SyncState> DurableNoteStore::getLinkedNotebookSyncStateAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SyncState>(service->getLinkedNotebookSyncStateAsync(
                linkedNotebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "getLinkedNotebookSyncState",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SyncState>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SyncChunk DurableNoteStore::getLinkedNotebookSyncChunk(
    const LinkedNotebook & linkedNotebook,
    qint32 afterUSN,
    qint32 maxEntries,
    bool fullSyncOnly,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getLinkedNotebookSyncChunk(
                linkedNotebook,
                afterUSN,
                maxEntries,
                fullSyncOnly,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
        strm << "afterUSN = " << afterUSN << "\n";
        strm << "maxEntries = " << maxEntries << "\n";
        strm << "fullSyncOnly = " << fullSyncOnly << "\n";
    }

    IDurableService::SyncRequest request(
        "getLinkedNotebookSyncChunk",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SyncChunk>();
}

QFuture<SyncChunk> DurableNoteStore::getLinkedNotebookSyncChunkAsync(
    const LinkedNotebook & linkedNotebook,
    qint32 afterUSN,
    qint32 maxEntries,
    bool fullSyncOnly,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SyncChunk>(service->getLinkedNotebookSyncChunkAsync(
                linkedNotebook,
                afterUSN,
                maxEntries,
                fullSyncOnly,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
        strm << "afterUSN = " << afterUSN << "\n";
        strm << "maxEntries = " << maxEntries << "\n";
        strm << "fullSyncOnly = " << fullSyncOnly << "\n";
    }

    IDurableService::AsyncRequest request(
        "getLinkedNotebookSyncChunk",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SyncChunk>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<Notebook> DurableNoteStore::listNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listNotebooks(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listNotebooks",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<Notebook>>();
}

QFuture<QList<Notebook>> DurableNoteStore::listNotebooksAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<Notebook>>(service->listNotebooksAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listNotebooks",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<Notebook>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<Notebook> DurableNoteStore::listAccessibleBusinessNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listAccessibleBusinessNotebooks(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listAccessibleBusinessNotebooks",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<Notebook>>();
}

QFuture<QList<Notebook>> DurableNoteStore::listAccessibleBusinessNotebooksAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<Notebook>>(service->listAccessibleBusinessNotebooksAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listAccessibleBusinessNotebooks",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<Notebook>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Notebook DurableNoteStore::getNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNotebook(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Notebook>();
}

QFuture<Notebook> DurableNoteStore::getNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Notebook>(service->getNotebookAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Notebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Notebook DurableNoteStore::getDefaultNotebook(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getDefaultNotebook(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "getDefaultNotebook",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Notebook>();
}

QFuture<Notebook> DurableNoteStore::getDefaultNotebookAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Notebook>(service->getDefaultNotebookAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "getDefaultNotebook",
        {},
        std::move(call));

    return convertFromVariantFuture<Notebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Notebook DurableNoteStore::createNotebook(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createNotebook(
                notebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebook = " << notebook << "\n";
    }

    IDurableService::SyncRequest request(
        "createNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Notebook>();
}

QFuture<Notebook> DurableNoteStore::createNotebookAsync(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Notebook>(service->createNotebookAsync(
                notebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebook = " << notebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "createNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Notebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateNotebook(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateNotebook(
                notebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebook = " << notebook << "\n";
    }

    IDurableService::SyncRequest request(
        "updateNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateNotebookAsync(
    const Notebook & notebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateNotebookAsync(
                notebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebook = " << notebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::expungeNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->expungeNotebook(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "expungeNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::expungeNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->expungeNotebookAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "expungeNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<Tag> DurableNoteStore::listTags(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listTags(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listTags",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<Tag>>();
}

QFuture<QList<Tag>> DurableNoteStore::listTagsAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<Tag>>(service->listTagsAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listTags",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<Tag>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<Tag> DurableNoteStore::listTagsByNotebook(
    Guid notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listTagsByNotebook(
                notebookGuid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
    }

    IDurableService::SyncRequest request(
        "listTagsByNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<Tag>>();
}

QFuture<QList<Tag>> DurableNoteStore::listTagsByNotebookAsync(
    Guid notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<Tag>>(service->listTagsByNotebookAsync(
                notebookGuid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
    }

    IDurableService::AsyncRequest request(
        "listTagsByNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QList<Tag>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Tag DurableNoteStore::getTag(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getTag(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getTag",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Tag>();
}

QFuture<Tag> DurableNoteStore::getTagAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Tag>(service->getTagAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getTag",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Tag>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Tag DurableNoteStore::createTag(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createTag(
                tag,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "tag = " << tag << "\n";
    }

    IDurableService::SyncRequest request(
        "createTag",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Tag>();
}

QFuture<Tag> DurableNoteStore::createTagAsync(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Tag>(service->createTagAsync(
                tag,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "tag = " << tag << "\n";
    }

    IDurableService::AsyncRequest request(
        "createTag",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Tag>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateTag(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateTag(
                tag,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "tag = " << tag << "\n";
    }

    IDurableService::SyncRequest request(
        "updateTag",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateTagAsync(
    const Tag & tag,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateTagAsync(
                tag,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "tag = " << tag << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateTag",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

void DurableNoteStore::untagAll(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->untagAll(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "untagAll",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<void> DurableNoteStore::untagAllAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<void>(service->untagAllAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "untagAll",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<void>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::expungeTag(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->expungeTag(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "expungeTag",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::expungeTagAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->expungeTagAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "expungeTag",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<SavedSearch> DurableNoteStore::listSearches(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listSearches(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listSearches",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<SavedSearch>>();
}

QFuture<QList<SavedSearch>> DurableNoteStore::listSearchesAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<SavedSearch>>(service->listSearchesAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listSearches",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<SavedSearch>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SavedSearch DurableNoteStore::getSearch(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getSearch(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getSearch",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SavedSearch>();
}

QFuture<SavedSearch> DurableNoteStore::getSearchAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SavedSearch>(service->getSearchAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getSearch",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SavedSearch>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SavedSearch DurableNoteStore::createSearch(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createSearch(
                search,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "search = " << search << "\n";
    }

    IDurableService::SyncRequest request(
        "createSearch",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SavedSearch>();
}

QFuture<SavedSearch> DurableNoteStore::createSearchAsync(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SavedSearch>(service->createSearchAsync(
                search,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "search = " << search << "\n";
    }

    IDurableService::AsyncRequest request(
        "createSearch",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SavedSearch>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateSearch(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateSearch(
                search,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "search = " << search << "\n";
    }

    IDurableService::SyncRequest request(
        "updateSearch",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateSearchAsync(
    const SavedSearch & search,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateSearchAsync(
                search,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "search = " << search << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateSearch",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::expungeSearch(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->expungeSearch(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "expungeSearch",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::expungeSearchAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->expungeSearchAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "expungeSearch",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::findNoteOffset(
    const NoteFilter & filter,
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->findNoteOffset(
                filter,
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "findNoteOffset",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::findNoteOffsetAsync(
    const NoteFilter & filter,
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->findNoteOffsetAsync(
                filter,
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "findNoteOffset",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

NotesMetadataList DurableNoteStore::findNotesMetadata(
    const NoteFilter & filter,
    qint32 offset,
    qint32 maxNotes,
    const NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->findNotesMetadata(
                filter,
                offset,
                maxNotes,
                resultSpec,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "offset = " << offset << "\n";
        strm << "maxNotes = " << maxNotes << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::SyncRequest request(
        "findNotesMetadata",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<NotesMetadataList>();
}

QFuture<NotesMetadataList> DurableNoteStore::findNotesMetadataAsync(
    const NoteFilter & filter,
    qint32 offset,
    qint32 maxNotes,
    const NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<NotesMetadataList>(service->findNotesMetadataAsync(
                filter,
                offset,
                maxNotes,
                resultSpec,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "offset = " << offset << "\n";
        strm << "maxNotes = " << maxNotes << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::AsyncRequest request(
        "findNotesMetadata",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<NotesMetadataList>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

NoteCollectionCounts DurableNoteStore::findNoteCounts(
    const NoteFilter & filter,
    bool withTrash,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->findNoteCounts(
                filter,
                withTrash,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "withTrash = " << withTrash << "\n";
    }

    IDurableService::SyncRequest request(
        "findNoteCounts",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<NoteCollectionCounts>();
}

QFuture<NoteCollectionCounts> DurableNoteStore::findNoteCountsAsync(
    const NoteFilter & filter,
    bool withTrash,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<NoteCollectionCounts>(service->findNoteCountsAsync(
                filter,
                withTrash,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "filter = " << filter << "\n";
        strm << "withTrash = " << withTrash << "\n";
    }

    IDurableService::AsyncRequest request(
        "findNoteCounts",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<NoteCollectionCounts>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::getNoteWithResultSpec(
    Guid guid,
    const NoteResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteWithResultSpec(
                guid,
                resultSpec,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteWithResultSpec",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::getNoteWithResultSpecAsync(
    Guid guid,
    const NoteResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->getNoteWithResultSpecAsync(
                guid,
                resultSpec,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteWithResultSpec",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::getNote(
    Guid guid,
    bool withContent,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNote(
                guid,
                withContent,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "withContent = " << withContent << "\n";
        strm << "withResourcesData = " << withResourcesData << "\n";
        strm << "withResourcesRecognition = " << withResourcesRecognition << "\n";
        strm << "withResourcesAlternateData = " << withResourcesAlternateData << "\n";
    }

    IDurableService::SyncRequest request(
        "getNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::getNoteAsync(
    Guid guid,
    bool withContent,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->getNoteAsync(
                guid,
                withContent,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "withContent = " << withContent << "\n";
        strm << "withResourcesData = " << withResourcesData << "\n";
        strm << "withResourcesRecognition = " << withResourcesRecognition << "\n";
        strm << "withResourcesAlternateData = " << withResourcesAlternateData << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

LazyMap DurableNoteStore::getNoteApplicationData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteApplicationData(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteApplicationData",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<LazyMap>();
}

QFuture<LazyMap> DurableNoteStore::getNoteApplicationDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<LazyMap>(service->getNoteApplicationDataAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteApplicationData",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<LazyMap>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::getNoteApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteApplicationDataEntry(
                guid,
                key,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::getNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->getNoteApplicationDataEntryAsync(
                guid,
                key,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::setNoteApplicationDataEntry(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->setNoteApplicationDataEntry(
                guid,
                key,
                value,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
        strm << "value = " << value << "\n";
    }

    IDurableService::SyncRequest request(
        "setNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::setNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->setNoteApplicationDataEntryAsync(
                guid,
                key,
                value,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
        strm << "value = " << value << "\n";
    }

    IDurableService::AsyncRequest request(
        "setNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::unsetNoteApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->unsetNoteApplicationDataEntry(
                guid,
                key,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::SyncRequest request(
        "unsetNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::unsetNoteApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->unsetNoteApplicationDataEntryAsync(
                guid,
                key,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::AsyncRequest request(
        "unsetNoteApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::getNoteContent(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteContent(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteContent",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::getNoteContentAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->getNoteContentAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteContent",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::getNoteSearchText(
    Guid guid,
    bool noteOnly,
    bool tokenizeForIndexing,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteSearchText(
                guid,
                noteOnly,
                tokenizeForIndexing,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "noteOnly = " << noteOnly << "\n";
        strm << "tokenizeForIndexing = " << tokenizeForIndexing << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteSearchText",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::getNoteSearchTextAsync(
    Guid guid,
    bool noteOnly,
    bool tokenizeForIndexing,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->getNoteSearchTextAsync(
                guid,
                noteOnly,
                tokenizeForIndexing,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "noteOnly = " << noteOnly << "\n";
        strm << "tokenizeForIndexing = " << tokenizeForIndexing << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteSearchText",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::getResourceSearchText(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceSearchText(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceSearchText",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::getResourceSearchTextAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->getResourceSearchTextAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceSearchText",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QStringList DurableNoteStore::getNoteTagNames(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteTagNames(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteTagNames",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toStringList();
}

QFuture<QStringList> DurableNoteStore::getNoteTagNamesAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QStringList>(service->getNoteTagNamesAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteTagNames",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QStringList>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::createNote(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createNote(
                note,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::SyncRequest request(
        "createNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::createNoteAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->createNoteAsync(
                note,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::AsyncRequest request(
        "createNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::updateNote(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateNote(
                note,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::SyncRequest request(
        "updateNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::updateNoteAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->updateNoteAsync(
                note,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::deleteNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->deleteNote(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "deleteNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::deleteNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->deleteNoteAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "deleteNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::expungeNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->expungeNote(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "expungeNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::expungeNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->expungeNoteAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "expungeNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::copyNote(
    Guid noteGuid,
    Guid toNotebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->copyNote(
                noteGuid,
                toNotebookGuid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "toNotebookGuid = " << toNotebookGuid << "\n";
    }

    IDurableService::SyncRequest request(
        "copyNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::copyNoteAsync(
    Guid noteGuid,
    Guid toNotebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->copyNoteAsync(
                noteGuid,
                toNotebookGuid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "toNotebookGuid = " << toNotebookGuid << "\n";
    }

    IDurableService::AsyncRequest request(
        "copyNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<NoteVersionId> DurableNoteStore::listNoteVersions(
    Guid noteGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listNoteVersions(
                noteGuid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
    }

    IDurableService::SyncRequest request(
        "listNoteVersions",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<NoteVersionId>>();
}

QFuture<QList<NoteVersionId>> DurableNoteStore::listNoteVersionsAsync(
    Guid noteGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<NoteVersionId>>(service->listNoteVersionsAsync(
                noteGuid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
    }

    IDurableService::AsyncRequest request(
        "listNoteVersions",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QList<NoteVersionId>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Note DurableNoteStore::getNoteVersion(
    Guid noteGuid,
    qint32 updateSequenceNum,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNoteVersion(
                noteGuid,
                updateSequenceNum,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "updateSequenceNum = " << updateSequenceNum << "\n";
        strm << "withResourcesData = " << withResourcesData << "\n";
        strm << "withResourcesRecognition = " << withResourcesRecognition << "\n";
        strm << "withResourcesAlternateData = " << withResourcesAlternateData << "\n";
    }

    IDurableService::SyncRequest request(
        "getNoteVersion",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Note>();
}

QFuture<Note> DurableNoteStore::getNoteVersionAsync(
    Guid noteGuid,
    qint32 updateSequenceNum,
    bool withResourcesData,
    bool withResourcesRecognition,
    bool withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Note>(service->getNoteVersionAsync(
                noteGuid,
                updateSequenceNum,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "updateSequenceNum = " << updateSequenceNum << "\n";
        strm << "withResourcesData = " << withResourcesData << "\n";
        strm << "withResourcesRecognition = " << withResourcesRecognition << "\n";
        strm << "withResourcesAlternateData = " << withResourcesAlternateData << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNoteVersion",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Note>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Resource DurableNoteStore::getResource(
    Guid guid,
    bool withData,
    bool withRecognition,
    bool withAttributes,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResource(
                guid,
                withData,
                withRecognition,
                withAttributes,
                withAlternateData,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "withData = " << withData << "\n";
        strm << "withRecognition = " << withRecognition << "\n";
        strm << "withAttributes = " << withAttributes << "\n";
        strm << "withAlternateData = " << withAlternateData << "\n";
    }

    IDurableService::SyncRequest request(
        "getResource",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Resource>();
}

QFuture<Resource> DurableNoteStore::getResourceAsync(
    Guid guid,
    bool withData,
    bool withRecognition,
    bool withAttributes,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Resource>(service->getResourceAsync(
                guid,
                withData,
                withRecognition,
                withAttributes,
                withAlternateData,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "withData = " << withData << "\n";
        strm << "withRecognition = " << withRecognition << "\n";
        strm << "withAttributes = " << withAttributes << "\n";
        strm << "withAlternateData = " << withAlternateData << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResource",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Resource>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

LazyMap DurableNoteStore::getResourceApplicationData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceApplicationData(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceApplicationData",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<LazyMap>();
}

QFuture<LazyMap> DurableNoteStore::getResourceApplicationDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<LazyMap>(service->getResourceApplicationDataAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceApplicationData",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<LazyMap>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::getResourceApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceApplicationDataEntry(
                guid,
                key,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::getResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->getResourceApplicationDataEntryAsync(
                guid,
                key,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::setResourceApplicationDataEntry(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->setResourceApplicationDataEntry(
                guid,
                key,
                value,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
        strm << "value = " << value << "\n";
    }

    IDurableService::SyncRequest request(
        "setResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::setResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    QString value,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->setResourceApplicationDataEntryAsync(
                guid,
                key,
                value,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
        strm << "value = " << value << "\n";
    }

    IDurableService::AsyncRequest request(
        "setResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::unsetResourceApplicationDataEntry(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->unsetResourceApplicationDataEntry(
                guid,
                key,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::SyncRequest request(
        "unsetResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::unsetResourceApplicationDataEntryAsync(
    Guid guid,
    QString key,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->unsetResourceApplicationDataEntryAsync(
                guid,
                key,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "key = " << key << "\n";
    }

    IDurableService::AsyncRequest request(
        "unsetResourceApplicationDataEntry",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateResource(
    const Resource & resource,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateResource(
                resource,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "resource = " << resource << "\n";
    }

    IDurableService::SyncRequest request(
        "updateResource",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateResourceAsync(
    const Resource & resource,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateResourceAsync(
                resource,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "resource = " << resource << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateResource",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QByteArray DurableNoteStore::getResourceData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceData(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceData",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toByteArray();
}

QFuture<QByteArray> DurableNoteStore::getResourceDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QByteArray>(service->getResourceDataAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceData",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QByteArray>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Resource DurableNoteStore::getResourceByHash(
    Guid noteGuid,
    QByteArray contentHash,
    bool withData,
    bool withRecognition,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceByHash(
                noteGuid,
                contentHash,
                withData,
                withRecognition,
                withAlternateData,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "contentHash = " << contentHash << "\n";
        strm << "withData = " << withData << "\n";
        strm << "withRecognition = " << withRecognition << "\n";
        strm << "withAlternateData = " << withAlternateData << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceByHash",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Resource>();
}

QFuture<Resource> DurableNoteStore::getResourceByHashAsync(
    Guid noteGuid,
    QByteArray contentHash,
    bool withData,
    bool withRecognition,
    bool withAlternateData,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Resource>(service->getResourceByHashAsync(
                noteGuid,
                contentHash,
                withData,
                withRecognition,
                withAlternateData,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "noteGuid = " << noteGuid << "\n";
        strm << "contentHash = " << contentHash << "\n";
        strm << "withData = " << withData << "\n";
        strm << "withRecognition = " << withRecognition << "\n";
        strm << "withAlternateData = " << withAlternateData << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceByHash",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Resource>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QByteArray DurableNoteStore::getResourceRecognition(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceRecognition(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceRecognition",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toByteArray();
}

QFuture<QByteArray> DurableNoteStore::getResourceRecognitionAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QByteArray>(service->getResourceRecognitionAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceRecognition",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QByteArray>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QByteArray DurableNoteStore::getResourceAlternateData(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceAlternateData(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceAlternateData",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toByteArray();
}

QFuture<QByteArray> DurableNoteStore::getResourceAlternateDataAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QByteArray>(service->getResourceAlternateDataAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceAlternateData",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QByteArray>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

ResourceAttributes DurableNoteStore::getResourceAttributes(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getResourceAttributes(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "getResourceAttributes",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<ResourceAttributes>();
}

QFuture<ResourceAttributes> DurableNoteStore::getResourceAttributesAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<ResourceAttributes>(service->getResourceAttributesAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getResourceAttributes",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<ResourceAttributes>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Notebook DurableNoteStore::getPublicNotebook(
    UserID userId,
    QString publicUri,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getPublicNotebook(
                userId,
                publicUri,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "userId = " << userId << "\n";
        strm << "publicUri = " << publicUri << "\n";
    }

    IDurableService::SyncRequest request(
        "getPublicNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Notebook>();
}

QFuture<Notebook> DurableNoteStore::getPublicNotebookAsync(
    UserID userId,
    QString publicUri,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Notebook>(service->getPublicNotebookAsync(
                userId,
                publicUri,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "userId = " << userId << "\n";
        strm << "publicUri = " << publicUri << "\n";
    }

    IDurableService::AsyncRequest request(
        "getPublicNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Notebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SharedNotebook DurableNoteStore::shareNotebook(
    const SharedNotebook & sharedNotebook,
    QString message,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->shareNotebook(
                sharedNotebook,
                message,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "sharedNotebook = " << sharedNotebook << "\n";
        strm << "message = " << message << "\n";
    }

    IDurableService::SyncRequest request(
        "shareNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SharedNotebook>();
}

QFuture<SharedNotebook> DurableNoteStore::shareNotebookAsync(
    const SharedNotebook & sharedNotebook,
    QString message,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SharedNotebook>(service->shareNotebookAsync(
                sharedNotebook,
                message,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "sharedNotebook = " << sharedNotebook << "\n";
        strm << "message = " << message << "\n";
    }

    IDurableService::AsyncRequest request(
        "shareNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<SharedNotebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

CreateOrUpdateNotebookSharesResult DurableNoteStore::createOrUpdateNotebookShares(
    const NotebookShareTemplate & shareTemplate,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createOrUpdateNotebookShares(
                shareTemplate,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "shareTemplate = " << shareTemplate << "\n";
    }

    IDurableService::SyncRequest request(
        "createOrUpdateNotebookShares",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<CreateOrUpdateNotebookSharesResult>();
}

QFuture<CreateOrUpdateNotebookSharesResult> DurableNoteStore::createOrUpdateNotebookSharesAsync(
    const NotebookShareTemplate & shareTemplate,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<CreateOrUpdateNotebookSharesResult>(service->createOrUpdateNotebookSharesAsync(
                shareTemplate,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "shareTemplate = " << shareTemplate << "\n";
    }

    IDurableService::AsyncRequest request(
        "createOrUpdateNotebookShares",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<CreateOrUpdateNotebookSharesResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateSharedNotebook(
    const SharedNotebook & sharedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateSharedNotebook(
                sharedNotebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "sharedNotebook = " << sharedNotebook << "\n";
    }

    IDurableService::SyncRequest request(
        "updateSharedNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateSharedNotebookAsync(
    const SharedNotebook & sharedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateSharedNotebookAsync(
                sharedNotebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "sharedNotebook = " << sharedNotebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateSharedNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

Notebook DurableNoteStore::setNotebookRecipientSettings(
    QString notebookGuid,
    const NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->setNotebookRecipientSettings(
                notebookGuid,
                recipientSettings,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
        strm << "recipientSettings = " << recipientSettings << "\n";
    }

    IDurableService::SyncRequest request(
        "setNotebookRecipientSettings",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<Notebook>();
}

QFuture<Notebook> DurableNoteStore::setNotebookRecipientSettingsAsync(
    QString notebookGuid,
    const NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<Notebook>(service->setNotebookRecipientSettingsAsync(
                notebookGuid,
                recipientSettings,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
        strm << "recipientSettings = " << recipientSettings << "\n";
    }

    IDurableService::AsyncRequest request(
        "setNotebookRecipientSettings",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<Notebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<SharedNotebook> DurableNoteStore::listSharedNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listSharedNotebooks(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listSharedNotebooks",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<SharedNotebook>>();
}

QFuture<QList<SharedNotebook>> DurableNoteStore::listSharedNotebooksAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<SharedNotebook>>(service->listSharedNotebooksAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listSharedNotebooks",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<SharedNotebook>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

LinkedNotebook DurableNoteStore::createLinkedNotebook(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->createLinkedNotebook(
                linkedNotebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::SyncRequest request(
        "createLinkedNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<LinkedNotebook>();
}

QFuture<LinkedNotebook> DurableNoteStore::createLinkedNotebookAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<LinkedNotebook>(service->createLinkedNotebookAsync(
                linkedNotebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "createLinkedNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<LinkedNotebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::updateLinkedNotebook(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateLinkedNotebook(
                linkedNotebook,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::SyncRequest request(
        "updateLinkedNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::updateLinkedNotebookAsync(
    const LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->updateLinkedNotebookAsync(
                linkedNotebook,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "linkedNotebook = " << linkedNotebook << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateLinkedNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QList<LinkedNotebook> DurableNoteStore::listLinkedNotebooks(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listLinkedNotebooks(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listLinkedNotebooks",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<LinkedNotebook>>();
}

QFuture<QList<LinkedNotebook>> DurableNoteStore::listLinkedNotebooksAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QList<LinkedNotebook>>(service->listLinkedNotebooksAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "listLinkedNotebooks",
        {},
        std::move(call));

    return convertFromVariantFuture<QList<LinkedNotebook>>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

qint32 DurableNoteStore::expungeLinkedNotebook(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->expungeLinkedNotebook(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "expungeLinkedNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<qint32>();
}

QFuture<qint32> DurableNoteStore::expungeLinkedNotebookAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<qint32>(service->expungeLinkedNotebookAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "expungeLinkedNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<qint32>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

AuthenticationResult DurableNoteStore::authenticateToSharedNotebook(
    QString shareKeyOrGlobalId,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->authenticateToSharedNotebook(
                shareKeyOrGlobalId,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "shareKeyOrGlobalId = " << shareKeyOrGlobalId << "\n";
    }

    IDurableService::SyncRequest request(
        "authenticateToSharedNotebook",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AuthenticationResult>();
}

QFuture<AuthenticationResult> DurableNoteStore::authenticateToSharedNotebookAsync(
    QString shareKeyOrGlobalId,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<AuthenticationResult>(service->authenticateToSharedNotebookAsync(
                shareKeyOrGlobalId,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "shareKeyOrGlobalId = " << shareKeyOrGlobalId << "\n";
    }

    IDurableService::AsyncRequest request(
        "authenticateToSharedNotebook",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<AuthenticationResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

SharedNotebook DurableNoteStore::getSharedNotebookByAuth(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getSharedNotebookByAuth(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "getSharedNotebookByAuth",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<SharedNotebook>();
}

QFuture<SharedNotebook> DurableNoteStore::getSharedNotebookByAuthAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<SharedNotebook>(service->getSharedNotebookByAuthAsync(
                ctx));
        });

    IDurableService::AsyncRequest request(
        "getSharedNotebookByAuth",
        {},
        std::move(call));

    return convertFromVariantFuture<SharedNotebook>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

void DurableNoteStore::emailNote(
    const NoteEmailParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->emailNote(
                parameters,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "parameters = " << parameters << "\n";
    }

    IDurableService::SyncRequest request(
        "emailNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<void> DurableNoteStore::emailNoteAsync(
    const NoteEmailParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<void>(service->emailNoteAsync(
                parameters,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "parameters = " << parameters << "\n";
    }

    IDurableService::AsyncRequest request(
        "emailNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<void>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

QString DurableNoteStore::shareNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->shareNote(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "shareNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toString();
}

QFuture<QString> DurableNoteStore::shareNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<QString>(service->shareNoteAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "shareNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<QString>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

void DurableNoteStore::stopSharingNote(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->stopSharingNote(
                guid,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::SyncRequest request(
        "stopSharingNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<void> DurableNoteStore::stopSharingNoteAsync(
    Guid guid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<void>(service->stopSharingNoteAsync(
                guid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
    }

    IDurableService::AsyncRequest request(
        "stopSharingNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<void>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

AuthenticationResult DurableNoteStore::authenticateToSharedNote(
    QString guid,
    QString noteKey,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->authenticateToSharedNote(
                guid,
                noteKey,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "noteKey = " << noteKey << "\n";
    }

    IDurableService::SyncRequest request(
        "authenticateToSharedNote",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AuthenticationResult>();
}

QFuture<AuthenticationResult> DurableNoteStore::authenticateToSharedNoteAsync(
    QString guid,
    QString noteKey,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<AuthenticationResult>(service->authenticateToSharedNoteAsync(
                guid,
                noteKey,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "guid = " << guid << "\n";
        strm << "noteKey = " << noteKey << "\n";
    }

    IDurableService::AsyncRequest request(
        "authenticateToSharedNote",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<AuthenticationResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

RelatedResult DurableNoteStore::findRelated(
    const RelatedQuery & query,
    const RelatedResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->findRelated(
                query,
                resultSpec,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "query = " << query << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::SyncRequest request(
        "findRelated",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<RelatedResult>();
}

QFuture<RelatedResult> DurableNoteStore::findRelatedAsync(
    const RelatedQuery & query,
    const RelatedResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<RelatedResult>(service->findRelatedAsync(
                query,
                resultSpec,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "query = " << query << "\n";
        strm << "resultSpec = " << resultSpec << "\n";
    }

    IDurableService::AsyncRequest request(
        "findRelated",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<RelatedResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

UpdateNoteIfUsnMatchesResult DurableNoteStore::updateNoteIfUsnMatches(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->updateNoteIfUsnMatches(
                note,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::SyncRequest request(
        "updateNoteIfUsnMatches",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<UpdateNoteIfUsnMatchesResult>();
}

QFuture<UpdateNoteIfUsnMatchesResult> DurableNoteStore::updateNoteIfUsnMatchesAsync(
    const Note & note,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<UpdateNoteIfUsnMatchesResult>(service->updateNoteIfUsnMatchesAsync(
                note,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "note = " << note << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateNoteIfUsnMatches",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<UpdateNoteIfUsnMatchesResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

ManageNotebookSharesResult DurableNoteStore::manageNotebookShares(
    const ManageNotebookSharesParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->manageNotebookShares(
                parameters,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "parameters = " << parameters << "\n";
    }

    IDurableService::SyncRequest request(
        "manageNotebookShares",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<ManageNotebookSharesResult>();
}

QFuture<ManageNotebookSharesResult> DurableNoteStore::manageNotebookSharesAsync(
    const ManageNotebookSharesParameters & parameters,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<ManageNotebookSharesResult>(service->manageNotebookSharesAsync(
                parameters,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "parameters = " << parameters << "\n";
    }

    IDurableService::AsyncRequest request(
        "manageNotebookShares",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<ManageNotebookSharesResult>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

ShareRelationships DurableNoteStore::getNotebookShares(
    QString notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getNotebookShares(
                notebookGuid,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
    }

    IDurableService::SyncRequest request(
        "getNotebookShares",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<ShareRelationships>();
}

QFuture<ShareRelationships> DurableNoteStore::getNotebookSharesAsync(
    QString notebookGuid,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return convertToVariantFuture<ShareRelationships>(service->getNotebookSharesAsync(
                notebookGuid,
                ctx));
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "notebookGuid = " << notebookGuid << "\n";
    }

    IDurableService::AsyncRequest request(
        "getNotebookShares",
        requestDescription,
        std::move(call));

    return convertFromVariantFuture<ShareRelationships>(m_durableService->executeAsyncRequest(
        std::move(request), ctx));
}

////////////////////////////////////////////////////////////////////////////////

INoteStorePtr newNoteStore(
    QString noteStoreUrl,
    std::optional<Guid> linkedNotebookGuid,
    IRequestContextPtr ctx,
    IRetryPolicyPtr retryPolicy)
{
    if (ctx && ctx->maxRequestRetryCount() == 0)
    {
        return std::make_shared<NoteStore>(std::move(noteStoreUrl), std::move(linkedNotebookGuid), ctx);
    }
    else
    {
        if (!retryPolicy) {
            retryPolicy = newRetryPolicy();
        }

        return std::make_shared<DurableNoteStore>(
            std::make_shared<NoteStore>(std::move(noteStoreUrl), std::move(linkedNotebookGuid), ctx),
            ctx,
            retryPolicy);
    }
}

} // namespace qevercloud
