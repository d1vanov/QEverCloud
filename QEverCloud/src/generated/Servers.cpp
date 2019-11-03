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
#include "../Thrift.h"

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSyncStateParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetFilteredSyncChunkParams(
    ThriftBinaryBufferReader & r,
    qint32 & afterUSN,
    qint32 & maxEntries,
    SyncChunkFilter & filter,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(afterUSN)
    Q_UNUSED(maxEntries)
    Q_UNUSED(filter)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncStateParams(
    ThriftBinaryBufferReader & r,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(linkedNotebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncChunkParams(
    ThriftBinaryBufferReader & r,
    LinkedNotebook & linkedNotebook,
    qint32 & afterUSN,
    qint32 & maxEntries,
    bool & fullSyncOnly,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(linkedNotebook)
    Q_UNUSED(afterUSN)
    Q_UNUSED(maxEntries)
    Q_UNUSED(fullSyncOnly)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNotebooksParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListAccessibleBusinessNotebooksParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetDefaultNotebookParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNotebookParams(
    ThriftBinaryBufferReader & r,
    Notebook & notebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(notebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNotebookParams(
    ThriftBinaryBufferReader & r,
    Notebook & notebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(notebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNotebookParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsByNotebookParams(
    ThriftBinaryBufferReader & r,
    Guid & notebookGuid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(notebookGuid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetTagParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateTagParams(
    ThriftBinaryBufferReader & r,
    Tag & tag,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(tag)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateTagParams(
    ThriftBinaryBufferReader & r,
    Tag & tag,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(tag)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUntagAllParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeTagParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSearchesParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSearchParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateSearchParams(
    ThriftBinaryBufferReader & r,
    SavedSearch & search,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(search)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSearchParams(
    ThriftBinaryBufferReader & r,
    SavedSearch & search,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(search)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeSearchParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteOffsetParams(
    ThriftBinaryBufferReader & r,
    NoteFilter & filter,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(filter)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNotesMetadataParams(
    ThriftBinaryBufferReader & r,
    NoteFilter & filter,
    qint32 & offset,
    qint32 & maxNotes,
    NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(filter)
    Q_UNUSED(offset)
    Q_UNUSED(maxNotes)
    Q_UNUSED(resultSpec)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteCountsParams(
    ThriftBinaryBufferReader & r,
    NoteFilter & filter,
    bool & withTrash,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(filter)
    Q_UNUSED(withTrash)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteWithResultSpecParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    NoteResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(resultSpec)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    bool & withContent,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(withContent)
    Q_UNUSED(withResourcesData)
    Q_UNUSED(withResourcesRecognition)
    Q_UNUSED(withResourcesAlternateData)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    QString & value,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(value)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteContentParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteSearchTextParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    bool & noteOnly,
    bool & tokenizeForIndexing,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(noteOnly)
    Q_UNUSED(tokenizeForIndexing)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceSearchTextParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteTagNamesParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNoteParams(
    ThriftBinaryBufferReader & r,
    Note & note,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(note)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteParams(
    ThriftBinaryBufferReader & r,
    Note & note,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(note)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreDeleteNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCopyNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & noteGuid,
    Guid & toNotebookGuid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(noteGuid)
    Q_UNUSED(toNotebookGuid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNoteVersionsParams(
    ThriftBinaryBufferReader & r,
    Guid & noteGuid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(noteGuid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteVersionParams(
    ThriftBinaryBufferReader & r,
    Guid & noteGuid,
    qint32 & updateSequenceNum,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(noteGuid)
    Q_UNUSED(updateSequenceNum)
    Q_UNUSED(withResourcesData)
    Q_UNUSED(withResourcesRecognition)
    Q_UNUSED(withResourcesAlternateData)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    bool & withData,
    bool & withRecognition,
    bool & withAttributes,
    bool & withAlternateData,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(withData)
    Q_UNUSED(withRecognition)
    Q_UNUSED(withAttributes)
    Q_UNUSED(withAlternateData)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    QString & value,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(value)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    QString & key,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(key)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateResourceParams(
    ThriftBinaryBufferReader & r,
    Resource & resource,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(resource)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceDataParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceByHashParams(
    ThriftBinaryBufferReader & r,
    Guid & noteGuid,
    QByteArray & contentHash,
    bool & withData,
    bool & withRecognition,
    bool & withAlternateData,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(noteGuid)
    Q_UNUSED(contentHash)
    Q_UNUSED(withData)
    Q_UNUSED(withRecognition)
    Q_UNUSED(withAlternateData)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceRecognitionParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAlternateDataParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAttributesParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetPublicNotebookParams(
    ThriftBinaryBufferReader & r,
    UserID & userId,
    QString & publicUri,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(userId)
    Q_UNUSED(publicUri)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNotebookParams(
    ThriftBinaryBufferReader & r,
    SharedNotebook & sharedNotebook,
    QString & message,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(sharedNotebook)
    Q_UNUSED(message)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateOrUpdateNotebookSharesParams(
    ThriftBinaryBufferReader & r,
    NotebookShareTemplate & shareTemplate,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(shareTemplate)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSharedNotebookParams(
    ThriftBinaryBufferReader & r,
    SharedNotebook & sharedNotebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(sharedNotebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNotebookRecipientSettingsParams(
    ThriftBinaryBufferReader & r,
    QString & notebookGuid,
    NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(notebookGuid)
    Q_UNUSED(recipientSettings)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSharedNotebooksParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateLinkedNotebookParams(
    ThriftBinaryBufferReader & r,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(linkedNotebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateLinkedNotebookParams(
    ThriftBinaryBufferReader & r,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(linkedNotebook)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListLinkedNotebooksParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeLinkedNotebookParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNotebookParams(
    ThriftBinaryBufferReader & r,
    QString & shareKeyOrGlobalId,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(shareKeyOrGlobalId)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSharedNotebookByAuthParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreEmailNoteParams(
    ThriftBinaryBufferReader & r,
    NoteEmailParameters & parameters,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(parameters)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreStopSharingNoteParams(
    ThriftBinaryBufferReader & r,
    Guid & guid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNoteParams(
    ThriftBinaryBufferReader & r,
    QString & guid,
    QString & noteKey,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(guid)
    Q_UNUSED(noteKey)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindRelatedParams(
    ThriftBinaryBufferReader & r,
    RelatedQuery & query,
    RelatedResultSpec & resultSpec,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(query)
    Q_UNUSED(resultSpec)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteIfUsnMatchesParams(
    ThriftBinaryBufferReader & r,
    Note & note,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(note)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreManageNotebookSharesParams(
    ThriftBinaryBufferReader & r,
    ManageNotebookSharesParameters & parameters,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(parameters)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookSharesParams(
    ThriftBinaryBufferReader & r,
    QString & notebookGuid,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(notebookGuid)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCheckVersionParams(
    ThriftBinaryBufferReader & r,
    QString & clientName,
    qint16 & edamVersionMajor,
    qint16 & edamVersionMinor,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(clientName)
    Q_UNUSED(edamVersionMajor)
    Q_UNUSED(edamVersionMinor)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetBootstrapInfoParams(
    ThriftBinaryBufferReader & r,
    QString & locale,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(locale)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateLongSessionParams(
    ThriftBinaryBufferReader & r,
    QString & username,
    QString & password,
    QString & consumerKey,
    QString & consumerSecret,
    QString & deviceIdentifier,
    QString & deviceDescription,
    bool & supportsTwoFactor,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(username)
    Q_UNUSED(password)
    Q_UNUSED(consumerKey)
    Q_UNUSED(consumerSecret)
    Q_UNUSED(deviceIdentifier)
    Q_UNUSED(deviceDescription)
    Q_UNUSED(supportsTwoFactor)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCompleteTwoFactorAuthenticationParams(
    ThriftBinaryBufferReader & r,
    QString & oneTimeCode,
    QString & deviceIdentifier,
    QString & deviceDescription,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(oneTimeCode)
    Q_UNUSED(deviceIdentifier)
    Q_UNUSED(deviceDescription)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRevokeLongSessionParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateToBusinessParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetPublicUserInfoParams(
    ThriftBinaryBufferReader & r,
    QString & username,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(username)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserUrlsParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreInviteToBusinessParams(
    ThriftBinaryBufferReader & r,
    QString & emailAddress,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(emailAddress)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRemoveFromBusinessParams(
    ThriftBinaryBufferReader & r,
    QString & emailAddress,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(emailAddress)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreUpdateBusinessUserIdentifierParams(
    ThriftBinaryBufferReader & r,
    QString & oldEmailAddress,
    QString & newEmailAddress,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(oldEmailAddress)
    Q_UNUSED(newEmailAddress)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessUsersParams(
    ThriftBinaryBufferReader & r,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessInvitationsParams(
    ThriftBinaryBufferReader & r,
    bool & includeRequestedInvitations,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(includeRequestedInvitations)
    Q_UNUSED(ctx)
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetAccountLimitsParams(
    ThriftBinaryBufferReader & r,
    ServiceLevel & serviceLevel,
    IRequestContextPtr ctx)
{
    // TODO: implement
    Q_UNUSED(r)
    Q_UNUSED(serviceLevel)
    Q_UNUSED(ctx)
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

NoteStoreServer::NoteStoreServer(QObject * parent) :
    QObject(parent)
{}

void NoteStoreServer::onRequest(QByteArray data)
{
    ThriftBinaryBufferReader r(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    r.readMessageBegin(fname, mtype, rseqid);

    if (fname == QStringLiteral("getSyncState"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreGetSyncStateParams(
            r,
            ctx);

        Q_EMIT getSyncStateRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getFilteredSyncChunk"))
    {
        qint32 afterUSN;
        qint32 maxEntries;
        SyncChunkFilter filter;
        IRequestContextPtr ctx;
        parseNoteStoreGetFilteredSyncChunkParams(
            r,
            afterUSN,
            maxEntries,
            filter,
            ctx);

        Q_EMIT getFilteredSyncChunkRequest(
            afterUSN,
            maxEntries,
            filter,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncState"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;
        parseNoteStoreGetLinkedNotebookSyncStateParams(
            r,
            linkedNotebook,
            ctx);

        Q_EMIT getLinkedNotebookSyncStateRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncChunk"))
    {
        LinkedNotebook linkedNotebook;
        qint32 afterUSN;
        qint32 maxEntries;
        bool fullSyncOnly;
        IRequestContextPtr ctx;
        parseNoteStoreGetLinkedNotebookSyncChunkParams(
            r,
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);

        Q_EMIT getLinkedNotebookSyncChunkRequest(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
    }
    else if (fname == QStringLiteral("listNotebooks"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListNotebooksParams(
            r,
            ctx);

        Q_EMIT listNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listAccessibleBusinessNotebooks"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListAccessibleBusinessNotebooksParams(
            r,
            ctx);

        Q_EMIT listAccessibleBusinessNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetNotebookParams(
            r,
            guid,
            ctx);

        Q_EMIT getNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getDefaultNotebook"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreGetDefaultNotebookParams(
            r,
            ctx);

        Q_EMIT getDefaultNotebookRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;
        parseNoteStoreCreateNotebookParams(
            r,
            notebook,
            ctx);

        Q_EMIT createNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateNotebookParams(
            r,
            notebook,
            ctx);

        Q_EMIT updateNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreExpungeNotebookParams(
            r,
            guid,
            ctx);

        Q_EMIT expungeNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listTags"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListTagsParams(
            r,
            ctx);

        Q_EMIT listTagsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listTagsByNotebook"))
    {
        Guid notebookGuid;
        IRequestContextPtr ctx;
        parseNoteStoreListTagsByNotebookParams(
            r,
            notebookGuid,
            ctx);

        Q_EMIT listTagsByNotebookRequest(
            notebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetTagParams(
            r,
            guid,
            ctx);

        Q_EMIT getTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;
        parseNoteStoreCreateTagParams(
            r,
            tag,
            ctx);

        Q_EMIT createTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("updateTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateTagParams(
            r,
            tag,
            ctx);

        Q_EMIT updateTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("untagAll"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreUntagAllParams(
            r,
            guid,
            ctx);

        Q_EMIT untagAllRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreExpungeTagParams(
            r,
            guid,
            ctx);

        Q_EMIT expungeTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listSearches"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListSearchesParams(
            r,
            ctx);

        Q_EMIT listSearchesRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetSearchParams(
            r,
            guid,
            ctx);

        Q_EMIT getSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;
        parseNoteStoreCreateSearchParams(
            r,
            search,
            ctx);

        Q_EMIT createSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("updateSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateSearchParams(
            r,
            search,
            ctx);

        Q_EMIT updateSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("expungeSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreExpungeSearchParams(
            r,
            guid,
            ctx);

        Q_EMIT expungeSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteOffset"))
    {
        NoteFilter filter;
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreFindNoteOffsetParams(
            r,
            filter,
            guid,
            ctx);

        Q_EMIT findNoteOffsetRequest(
            filter,
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNotesMetadata"))
    {
        NoteFilter filter;
        qint32 offset;
        qint32 maxNotes;
        NotesMetadataResultSpec resultSpec;
        IRequestContextPtr ctx;
        parseNoteStoreFindNotesMetadataParams(
            r,
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);

        Q_EMIT findNotesMetadataRequest(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteCounts"))
    {
        NoteFilter filter;
        bool withTrash;
        IRequestContextPtr ctx;
        parseNoteStoreFindNoteCountsParams(
            r,
            filter,
            withTrash,
            ctx);

        Q_EMIT findNoteCountsRequest(
            filter,
            withTrash,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteWithResultSpec"))
    {
        Guid guid;
        NoteResultSpec resultSpec;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteWithResultSpecParams(
            r,
            guid,
            resultSpec,
            ctx);

        Q_EMIT getNoteWithResultSpecRequest(
            guid,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("getNote"))
    {
        Guid guid;
        bool withContent;
        bool withResourcesData;
        bool withResourcesRecognition;
        bool withResourcesAlternateData;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteParams(
            r,
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);

        Q_EMIT getNoteRequest(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteApplicationDataParams(
            r,
            guid,
            ctx);

        Q_EMIT getNoteApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteApplicationDataEntryParams(
            r,
            guid,
            key,
            ctx);

        Q_EMIT getNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;
        parseNoteStoreSetNoteApplicationDataEntryParams(
            r,
            guid,
            key,
            value,
            ctx);

        Q_EMIT setNoteApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;
        parseNoteStoreUnsetNoteApplicationDataEntryParams(
            r,
            guid,
            key,
            ctx);

        Q_EMIT unsetNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteContent"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteContentParams(
            r,
            guid,
            ctx);

        Q_EMIT getNoteContentRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteSearchText"))
    {
        Guid guid;
        bool noteOnly;
        bool tokenizeForIndexing;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteSearchTextParams(
            r,
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);

        Q_EMIT getNoteSearchTextRequest(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceSearchText"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceSearchTextParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceSearchTextRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteTagNames"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteTagNamesParams(
            r,
            guid,
            ctx);

        Q_EMIT getNoteTagNamesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createNote"))
    {
        Note note;
        IRequestContextPtr ctx;
        parseNoteStoreCreateNoteParams(
            r,
            note,
            ctx);

        Q_EMIT createNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("updateNote"))
    {
        Note note;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateNoteParams(
            r,
            note,
            ctx);

        Q_EMIT updateNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("deleteNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreDeleteNoteParams(
            r,
            guid,
            ctx);

        Q_EMIT deleteNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreExpungeNoteParams(
            r,
            guid,
            ctx);

        Q_EMIT expungeNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("copyNote"))
    {
        Guid noteGuid;
        Guid toNotebookGuid;
        IRequestContextPtr ctx;
        parseNoteStoreCopyNoteParams(
            r,
            noteGuid,
            toNotebookGuid,
            ctx);

        Q_EMIT copyNoteRequest(
            noteGuid,
            toNotebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("listNoteVersions"))
    {
        Guid noteGuid;
        IRequestContextPtr ctx;
        parseNoteStoreListNoteVersionsParams(
            r,
            noteGuid,
            ctx);

        Q_EMIT listNoteVersionsRequest(
            noteGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteVersion"))
    {
        Guid noteGuid;
        qint32 updateSequenceNum;
        bool withResourcesData;
        bool withResourcesRecognition;
        bool withResourcesAlternateData;
        IRequestContextPtr ctx;
        parseNoteStoreGetNoteVersionParams(
            r,
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);

        Q_EMIT getNoteVersionRequest(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResource"))
    {
        Guid guid;
        bool withData;
        bool withRecognition;
        bool withAttributes;
        bool withAlternateData;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceParams(
            r,
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);

        Q_EMIT getResourceRequest(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceApplicationDataParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceApplicationDataEntryParams(
            r,
            guid,
            key,
            ctx);

        Q_EMIT getResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;
        parseNoteStoreSetResourceApplicationDataEntryParams(
            r,
            guid,
            key,
            value,
            ctx);

        Q_EMIT setResourceApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;
        parseNoteStoreUnsetResourceApplicationDataEntryParams(
            r,
            guid,
            key,
            ctx);

        Q_EMIT unsetResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("updateResource"))
    {
        Resource resource;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateResourceParams(
            r,
            resource,
            ctx);

        Q_EMIT updateResourceRequest(
            resource,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceData"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceDataParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceByHash"))
    {
        Guid noteGuid;
        QByteArray contentHash;
        bool withData;
        bool withRecognition;
        bool withAlternateData;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceByHashParams(
            r,
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);

        Q_EMIT getResourceByHashRequest(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceRecognition"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceRecognitionParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceRecognitionRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAlternateData"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceAlternateDataParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceAlternateDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAttributes"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreGetResourceAttributesParams(
            r,
            guid,
            ctx);

        Q_EMIT getResourceAttributesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getPublicNotebook"))
    {
        UserID userId;
        QString publicUri;
        IRequestContextPtr ctx;
        parseNoteStoreGetPublicNotebookParams(
            r,
            userId,
            publicUri,
            ctx);

        Q_EMIT getPublicNotebookRequest(
            userId,
            publicUri,
            ctx);
    }
    else if (fname == QStringLiteral("shareNotebook"))
    {
        SharedNotebook sharedNotebook;
        QString message;
        IRequestContextPtr ctx;
        parseNoteStoreShareNotebookParams(
            r,
            sharedNotebook,
            message,
            ctx);

        Q_EMIT shareNotebookRequest(
            sharedNotebook,
            message,
            ctx);
    }
    else if (fname == QStringLiteral("createOrUpdateNotebookShares"))
    {
        NotebookShareTemplate shareTemplate;
        IRequestContextPtr ctx;
        parseNoteStoreCreateOrUpdateNotebookSharesParams(
            r,
            shareTemplate,
            ctx);

        Q_EMIT createOrUpdateNotebookSharesRequest(
            shareTemplate,
            ctx);
    }
    else if (fname == QStringLiteral("updateSharedNotebook"))
    {
        SharedNotebook sharedNotebook;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateSharedNotebookParams(
            r,
            sharedNotebook,
            ctx);

        Q_EMIT updateSharedNotebookRequest(
            sharedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("setNotebookRecipientSettings"))
    {
        QString notebookGuid;
        NotebookRecipientSettings recipientSettings;
        IRequestContextPtr ctx;
        parseNoteStoreSetNotebookRecipientSettingsParams(
            r,
            notebookGuid,
            recipientSettings,
            ctx);

        Q_EMIT setNotebookRecipientSettingsRequest(
            notebookGuid,
            recipientSettings,
            ctx);
    }
    else if (fname == QStringLiteral("listSharedNotebooks"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListSharedNotebooksParams(
            r,
            ctx);

        Q_EMIT listSharedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;
        parseNoteStoreCreateLinkedNotebookParams(
            r,
            linkedNotebook,
            ctx);

        Q_EMIT createLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateLinkedNotebookParams(
            r,
            linkedNotebook,
            ctx);

        Q_EMIT updateLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("listLinkedNotebooks"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreListLinkedNotebooksParams(
            r,
            ctx);

        Q_EMIT listLinkedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("expungeLinkedNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreExpungeLinkedNotebookParams(
            r,
            guid,
            ctx);

        Q_EMIT expungeLinkedNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNotebook"))
    {
        QString shareKeyOrGlobalId;
        IRequestContextPtr ctx;
        parseNoteStoreAuthenticateToSharedNotebookParams(
            r,
            shareKeyOrGlobalId,
            ctx);

        Q_EMIT authenticateToSharedNotebookRequest(
            shareKeyOrGlobalId,
            ctx);
    }
    else if (fname == QStringLiteral("getSharedNotebookByAuth"))
    {
        IRequestContextPtr ctx;
        parseNoteStoreGetSharedNotebookByAuthParams(
            r,
            ctx);

        Q_EMIT getSharedNotebookByAuthRequest(
            ctx);
    }
    else if (fname == QStringLiteral("emailNote"))
    {
        NoteEmailParameters parameters;
        IRequestContextPtr ctx;
        parseNoteStoreEmailNoteParams(
            r,
            parameters,
            ctx);

        Q_EMIT emailNoteRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("shareNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreShareNoteParams(
            r,
            guid,
            ctx);

        Q_EMIT shareNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("stopSharingNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;
        parseNoteStoreStopSharingNoteParams(
            r,
            guid,
            ctx);

        Q_EMIT stopSharingNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNote"))
    {
        QString guid;
        QString noteKey;
        IRequestContextPtr ctx;
        parseNoteStoreAuthenticateToSharedNoteParams(
            r,
            guid,
            noteKey,
            ctx);

        Q_EMIT authenticateToSharedNoteRequest(
            guid,
            noteKey,
            ctx);
    }
    else if (fname == QStringLiteral("findRelated"))
    {
        RelatedQuery query;
        RelatedResultSpec resultSpec;
        IRequestContextPtr ctx;
        parseNoteStoreFindRelatedParams(
            r,
            query,
            resultSpec,
            ctx);

        Q_EMIT findRelatedRequest(
            query,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("updateNoteIfUsnMatches"))
    {
        Note note;
        IRequestContextPtr ctx;
        parseNoteStoreUpdateNoteIfUsnMatchesParams(
            r,
            note,
            ctx);

        Q_EMIT updateNoteIfUsnMatchesRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("manageNotebookShares"))
    {
        ManageNotebookSharesParameters parameters;
        IRequestContextPtr ctx;
        parseNoteStoreManageNotebookSharesParams(
            r,
            parameters,
            ctx);

        Q_EMIT manageNotebookSharesRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("getNotebookShares"))
    {
        QString notebookGuid;
        IRequestContextPtr ctx;
        parseNoteStoreGetNotebookSharesParams(
            r,
            notebookGuid,
            ctx);

        Q_EMIT getNotebookSharesRequest(
            notebookGuid,
            ctx);
    }
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
    ThriftBinaryBufferReader r(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    r.readMessageBegin(fname, mtype, rseqid);

    if (fname == QStringLiteral("checkVersion"))
    {
        QString clientName;
        qint16 edamVersionMajor;
        qint16 edamVersionMinor;
        IRequestContextPtr ctx;
        parseUserStoreCheckVersionParams(
            r,
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);

        Q_EMIT checkVersionRequest(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);
    }
    else if (fname == QStringLiteral("getBootstrapInfo"))
    {
        QString locale;
        IRequestContextPtr ctx;
        parseUserStoreGetBootstrapInfoParams(
            r,
            locale,
            ctx);

        Q_EMIT getBootstrapInfoRequest(
            locale,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateLongSession"))
    {
        QString username;
        QString password;
        QString consumerKey;
        QString consumerSecret;
        QString deviceIdentifier;
        QString deviceDescription;
        bool supportsTwoFactor;
        IRequestContextPtr ctx;
        parseUserStoreAuthenticateLongSessionParams(
            r,
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        Q_EMIT authenticateLongSessionRequest(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
    }
    else if (fname == QStringLiteral("completeTwoFactorAuthentication"))
    {
        QString oneTimeCode;
        QString deviceIdentifier;
        QString deviceDescription;
        IRequestContextPtr ctx;
        parseUserStoreCompleteTwoFactorAuthenticationParams(
            r,
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        Q_EMIT completeTwoFactorAuthenticationRequest(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
    }
    else if (fname == QStringLiteral("revokeLongSession"))
    {
        IRequestContextPtr ctx;
        parseUserStoreRevokeLongSessionParams(
            r,
            ctx);

        Q_EMIT revokeLongSessionRequest(
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToBusiness"))
    {
        IRequestContextPtr ctx;
        parseUserStoreAuthenticateToBusinessParams(
            r,
            ctx);

        Q_EMIT authenticateToBusinessRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getUser"))
    {
        IRequestContextPtr ctx;
        parseUserStoreGetUserParams(
            r,
            ctx);

        Q_EMIT getUserRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getPublicUserInfo"))
    {
        QString username;
        IRequestContextPtr ctx;
        parseUserStoreGetPublicUserInfoParams(
            r,
            username,
            ctx);

        Q_EMIT getPublicUserInfoRequest(
            username,
            ctx);
    }
    else if (fname == QStringLiteral("getUserUrls"))
    {
        IRequestContextPtr ctx;
        parseUserStoreGetUserUrlsParams(
            r,
            ctx);

        Q_EMIT getUserUrlsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("inviteToBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;
        parseUserStoreInviteToBusinessParams(
            r,
            emailAddress,
            ctx);

        Q_EMIT inviteToBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("removeFromBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;
        parseUserStoreRemoveFromBusinessParams(
            r,
            emailAddress,
            ctx);

        Q_EMIT removeFromBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("updateBusinessUserIdentifier"))
    {
        QString oldEmailAddress;
        QString newEmailAddress;
        IRequestContextPtr ctx;
        parseUserStoreUpdateBusinessUserIdentifierParams(
            r,
            oldEmailAddress,
            newEmailAddress,
            ctx);

        Q_EMIT updateBusinessUserIdentifierRequest(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessUsers"))
    {
        IRequestContextPtr ctx;
        parseUserStoreListBusinessUsersParams(
            r,
            ctx);

        Q_EMIT listBusinessUsersRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessInvitations"))
    {
        bool includeRequestedInvitations;
        IRequestContextPtr ctx;
        parseUserStoreListBusinessInvitationsParams(
            r,
            includeRequestedInvitations,
            ctx);

        Q_EMIT listBusinessInvitationsRequest(
            includeRequestedInvitations,
            ctx);
    }
    else if (fname == QStringLiteral("getAccountLimits"))
    {
        ServiceLevel serviceLevel;
        IRequestContextPtr ctx;
        parseUserStoreGetAccountLimitsParams(
            r,
            serviceLevel,
            ctx);

        Q_EMIT getAccountLimitsRequest(
            serviceLevel,
            ctx);
    }
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
