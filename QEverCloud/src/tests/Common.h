/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_COMMON_H
#define QEVERCLOUD_TEST_COMMON_H

#include <generated/Types.h>

#include <QTcpSocket>

#ifdef QEVERCLOUD_SHARED_LIBRARY
#undef QEVERCLOUD_SHARED_LIBRARY
#endif

#ifdef QEVERCLOUD_STATIC_LIBRARY
#undef QEVERCLOUD_STATIC_LIBRARY
#endif

namespace qevercloud {
namespace tests {

////////////////////////////////////////////////////////////////////////////////

QByteArray readThriftRequestFromSocket(QTcpSocket & socket);

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket);

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

////////////////////////////////////////////////////////////////////////////////

QByteArray extractBodyFromHttpRequest(QByteArray requestData);

////////////////////////////////////////////////////////////////////////////////

SyncState generateSyncState();

SyncChunkFilter generateSyncChunkFilter();

NoteFilter generateNoteFilter();

NotesMetadataResultSpec generateNotesMetadataResultSpec();

NoteCollectionCounts generateNoteCollectionCounts();

NoteResultSpec generateNoteResultSpec();

NoteVersionId generateNoteVersionId();

RelatedQuery generateRelatedQuery();

RelatedResultSpec generateRelatedResultSpec();

ShareRelationshipRestrictions generateShareRelationshipRestrictions();

MemberShareRelationship generateMemberShareRelationship();

NoteShareRelationshipRestrictions generateNoteShareRelationshipRestrictions();

NoteMemberShareRelationship generateNoteMemberShareRelationship();

NoteInvitationShareRelationship generateNoteInvitationShareRelationship();

NoteShareRelationships generateNoteShareRelationships();

ManageNoteSharesParameters generateManageNoteSharesParameters();

Data generateData();

UserAttributes generateUserAttributes();

BusinessUserAttributes generateBusinessUserAttributes();

Accounting generateAccounting();

BusinessUserInfo generateBusinessUserInfo();

AccountLimits generateAccountLimits();

User generateUser();

Contact generateContact();

Identity generateIdentity();

Tag generateTag();

LazyMap generateLazyMap();

ResourceAttributes generateResourceAttributes();

Resource generateResource();

NoteAttributes generateNoteAttributes();

SharedNote generateSharedNote();

NoteRestrictions generateNoteRestrictions();

NoteLimits generateNoteLimits();

Note generateNote();

Publishing generatePublishing();

BusinessNotebook generateBusinessNotebook();

SavedSearchScope generateSavedSearchScope();

SavedSearch generateSavedSearch();

SharedNotebookRecipientSettings generateSharedNotebookRecipientSettings();

NotebookRecipientSettings generateNotebookRecipientSettings();

SharedNotebook generateSharedNotebook();

CanMoveToContainerRestrictions generateCanMoveToContainerRestrictions();

NotebookRestrictions generateNotebookRestrictions();

Notebook generateNotebook();

LinkedNotebook generateLinkedNotebook();

NotebookDescriptor generateNotebookDescriptor();

UserProfile generateUserProfile();

RelatedContentImage generateRelatedContentImage();

RelatedContent generateRelatedContent();

BusinessInvitation generateBusinessInvitation();

UserIdentity generateUserIdentity();

PublicUserInfo generatePublicUserInfo();

UserUrls generateUserUrls();

AuthenticationResult generateAuthenticationResult();

BootstrapSettings generateBootstrapSettings();

BootstrapProfile generateBootstrapProfile();

BootstrapInfo generateBootstrapInfo();

SyncChunk generateSyncChunk();

NoteList generateNoteList();

NoteMetadata generateNoteMetadata();

NotesMetadataList generateNotesMetadataList();

NoteEmailParameters generateNoteEmailParameters();

RelatedResult generateRelatedResult();

UpdateNoteIfUsnMatchesResult generateUpdateNoteIfUsnMatchesResult();

InvitationShareRelationship generateInvitationShareRelationship();

ShareRelationships generateShareRelationships();

ManageNotebookSharesParameters generateManageNotebookSharesParameters();

ManageNotebookSharesError generateManageNotebookSharesError();

ManageNotebookSharesResult generateManageNotebookSharesResult();

SharedNoteTemplate generateSharedNoteTemplate();

NotebookShareTemplate generateNotebookShareTemplate();

CreateOrUpdateNotebookSharesResult generateCreateOrUpdateNotebookSharesResult();

ManageNoteSharesError generateManageNoteSharesError();

ManageNoteSharesResult generateManageNoteSharesResult();

} // namespace tests
} // namespace qevercloud

#endif // QEVERCLOUD_TEST_COMMON_H
