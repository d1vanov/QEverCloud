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

#ifndef QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS
#define QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS

#include <qevercloud/Types.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

QString generateRandomString(int len = 10);

qint8 generateRandomInt8();

qint16 generateRandomInt16();

qint32 generateRandomInt32();

qint64 generateRandomInt64();

quint8 generateRandomUint8();

quint16 generateRandomUint16();

quint32 generateRandomUint32();

quint64 generateRandomUint64();

double generateRandomDouble();

bool generateRandomBool();

////////////////////////////////////////////////////////////////////////////////

[[nodiscard]] SyncState generateRandomSyncState();

[[nodiscard]] SyncChunk generateRandomSyncChunk();

[[nodiscard]] SyncChunkFilter generateRandomSyncChunkFilter();

[[nodiscard]] NoteFilter generateRandomNoteFilter();

[[nodiscard]] NoteList generateRandomNoteList();

[[nodiscard]] NoteMetadata generateRandomNoteMetadata();

[[nodiscard]] NotesMetadataList generateRandomNotesMetadataList();

[[nodiscard]] NotesMetadataResultSpec generateRandomNotesMetadataResultSpec();

[[nodiscard]] NoteCollectionCounts generateRandomNoteCollectionCounts();

[[nodiscard]] NoteResultSpec generateRandomNoteResultSpec();

[[nodiscard]] NoteEmailParameters generateRandomNoteEmailParameters();

[[nodiscard]] NoteVersionId generateRandomNoteVersionId();

[[nodiscard]] RelatedQuery generateRandomRelatedQuery();

[[nodiscard]] RelatedResult generateRandomRelatedResult();

[[nodiscard]] RelatedResultSpec generateRandomRelatedResultSpec();

[[nodiscard]] UpdateNoteIfUsnMatchesResult generateRandomUpdateNoteIfUsnMatchesResult();

[[nodiscard]] ShareRelationshipRestrictions generateRandomShareRelationshipRestrictions();

[[nodiscard]] InvitationShareRelationship generateRandomInvitationShareRelationship();

[[nodiscard]] MemberShareRelationship generateRandomMemberShareRelationship();

[[nodiscard]] ShareRelationships generateRandomShareRelationships();

[[nodiscard]] ManageNotebookSharesParameters generateRandomManageNotebookSharesParameters();

[[nodiscard]] ManageNotebookSharesError generateRandomManageNotebookSharesError();

[[nodiscard]] ManageNotebookSharesResult generateRandomManageNotebookSharesResult();

[[nodiscard]] SharedNoteTemplate generateRandomSharedNoteTemplate();

[[nodiscard]] NotebookShareTemplate generateRandomNotebookShareTemplate();

[[nodiscard]] CreateOrUpdateNotebookSharesResult generateRandomCreateOrUpdateNotebookSharesResult();

[[nodiscard]] NoteShareRelationshipRestrictions generateRandomNoteShareRelationshipRestrictions();

[[nodiscard]] NoteMemberShareRelationship generateRandomNoteMemberShareRelationship();

[[nodiscard]] NoteInvitationShareRelationship generateRandomNoteInvitationShareRelationship();

[[nodiscard]] NoteShareRelationships generateRandomNoteShareRelationships();

[[nodiscard]] ManageNoteSharesParameters generateRandomManageNoteSharesParameters();

[[nodiscard]] ManageNoteSharesError generateRandomManageNoteSharesError();

[[nodiscard]] ManageNoteSharesResult generateRandomManageNoteSharesResult();

[[nodiscard]] Data generateRandomData();

[[nodiscard]] UserAttributes generateRandomUserAttributes();

[[nodiscard]] BusinessUserAttributes generateRandomBusinessUserAttributes();

[[nodiscard]] Accounting generateRandomAccounting();

[[nodiscard]] BusinessUserInfo generateRandomBusinessUserInfo();

[[nodiscard]] AccountLimits generateRandomAccountLimits();

[[nodiscard]] User generateRandomUser();

[[nodiscard]] Contact generateRandomContact();

[[nodiscard]] Identity generateRandomIdentity();

[[nodiscard]] Tag generateRandomTag();

[[nodiscard]] LazyMap generateRandomLazyMap();

[[nodiscard]] ResourceAttributes generateRandomResourceAttributes();

[[nodiscard]] Resource generateRandomResource();

[[nodiscard]] NoteAttributes generateRandomNoteAttributes();

[[nodiscard]] SharedNote generateRandomSharedNote();

[[nodiscard]] NoteRestrictions generateRandomNoteRestrictions();

[[nodiscard]] NoteLimits generateRandomNoteLimits();

[[nodiscard]] Note generateRandomNote();

[[nodiscard]] Publishing generateRandomPublishing();

[[nodiscard]] BusinessNotebook generateRandomBusinessNotebook();

[[nodiscard]] SavedSearchScope generateRandomSavedSearchScope();

[[nodiscard]] SavedSearch generateRandomSavedSearch();

[[nodiscard]] SharedNotebookRecipientSettings generateRandomSharedNotebookRecipientSettings();

[[nodiscard]] NotebookRecipientSettings generateRandomNotebookRecipientSettings();

[[nodiscard]] SharedNotebook generateRandomSharedNotebook();

[[nodiscard]] CanMoveToContainerRestrictions generateRandomCanMoveToContainerRestrictions();

[[nodiscard]] NotebookRestrictions generateRandomNotebookRestrictions();

[[nodiscard]] Notebook generateRandomNotebook();

[[nodiscard]] LinkedNotebook generateRandomLinkedNotebook();

[[nodiscard]] NotebookDescriptor generateRandomNotebookDescriptor();

[[nodiscard]] UserProfile generateRandomUserProfile();

[[nodiscard]] RelatedContentImage generateRandomRelatedContentImage();

[[nodiscard]] RelatedContent generateRandomRelatedContent();

[[nodiscard]] BusinessInvitation generateRandomBusinessInvitation();

[[nodiscard]] UserIdentity generateRandomUserIdentity();

[[nodiscard]] PublicUserInfo generateRandomPublicUserInfo();

[[nodiscard]] UserUrls generateRandomUserUrls();

[[nodiscard]] AuthenticationResult generateRandomAuthenticationResult();

[[nodiscard]] BootstrapSettings generateRandomBootstrapSettings();

[[nodiscard]] BootstrapProfile generateRandomBootstrapProfile();

[[nodiscard]] BootstrapInfo generateRandomBootstrapInfo();

[[nodiscard]] EDAMUserException generateRandomEDAMUserException();

[[nodiscard]] EDAMSystemException generateRandomEDAMSystemException();

[[nodiscard]] EDAMNotFoundException generateRandomEDAMNotFoundException();

[[nodiscard]] EDAMInvalidContactsException generateRandomEDAMInvalidContactsException();

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS
