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

#include "TestTypeBuilders.h"
#include "../src/Impl.h"
#include "RandomDataGenerators.h"
#include <qevercloud/exceptions/builders/EDAMInvalidContactsExceptionBuilder.h>
#include <qevercloud/exceptions/builders/EDAMNotFoundExceptionBuilder.h>
#include <qevercloud/exceptions/builders/EDAMSystemExceptionBuilder.h>
#include <qevercloud/exceptions/builders/EDAMUserExceptionBuilder.h>
#include <qevercloud/types/builders/AccountLimitsBuilder.h>
#include <qevercloud/types/builders/AccountingBuilder.h>
#include <qevercloud/types/builders/AuthenticationResultBuilder.h>
#include <qevercloud/types/builders/BootstrapInfoBuilder.h>
#include <qevercloud/types/builders/BootstrapProfileBuilder.h>
#include <qevercloud/types/builders/BootstrapSettingsBuilder.h>
#include <qevercloud/types/builders/BusinessInvitationBuilder.h>
#include <qevercloud/types/builders/BusinessNotebookBuilder.h>
#include <qevercloud/types/builders/BusinessUserAttributesBuilder.h>
#include <qevercloud/types/builders/BusinessUserInfoBuilder.h>
#include <qevercloud/types/builders/CanMoveToContainerRestrictionsBuilder.h>
#include <qevercloud/types/builders/ContactBuilder.h>
#include <qevercloud/types/builders/CreateOrUpdateNotebookSharesResultBuilder.h>
#include <qevercloud/types/builders/DataBuilder.h>
#include <qevercloud/types/builders/IdentityBuilder.h>
#include <qevercloud/types/builders/InvitationShareRelationshipBuilder.h>
#include <qevercloud/types/builders/LazyMapBuilder.h>
#include <qevercloud/types/builders/LinkedNotebookBuilder.h>
#include <qevercloud/types/builders/ManageNoteSharesErrorBuilder.h>
#include <qevercloud/types/builders/ManageNoteSharesParametersBuilder.h>
#include <qevercloud/types/builders/ManageNoteSharesResultBuilder.h>
#include <qevercloud/types/builders/ManageNotebookSharesErrorBuilder.h>
#include <qevercloud/types/builders/ManageNotebookSharesParametersBuilder.h>
#include <qevercloud/types/builders/ManageNotebookSharesResultBuilder.h>
#include <qevercloud/types/builders/MemberShareRelationshipBuilder.h>
#include <qevercloud/types/builders/NoteAttributesBuilder.h>
#include <qevercloud/types/builders/NoteBuilder.h>
#include <qevercloud/types/builders/NoteCollectionCountsBuilder.h>
#include <qevercloud/types/builders/NoteEmailParametersBuilder.h>
#include <qevercloud/types/builders/NoteFilterBuilder.h>
#include <qevercloud/types/builders/NoteInvitationShareRelationshipBuilder.h>
#include <qevercloud/types/builders/NoteLimitsBuilder.h>
#include <qevercloud/types/builders/NoteListBuilder.h>
#include <qevercloud/types/builders/NoteMemberShareRelationshipBuilder.h>
#include <qevercloud/types/builders/NoteMetadataBuilder.h>
#include <qevercloud/types/builders/NoteRestrictionsBuilder.h>
#include <qevercloud/types/builders/NoteResultSpecBuilder.h>
#include <qevercloud/types/builders/NoteShareRelationshipRestrictionsBuilder.h>
#include <qevercloud/types/builders/NoteShareRelationshipsBuilder.h>
#include <qevercloud/types/builders/NoteVersionIdBuilder.h>
#include <qevercloud/types/builders/NotebookBuilder.h>
#include <qevercloud/types/builders/NotebookDescriptorBuilder.h>
#include <qevercloud/types/builders/NotebookRecipientSettingsBuilder.h>
#include <qevercloud/types/builders/NotebookRestrictionsBuilder.h>
#include <qevercloud/types/builders/NotebookShareTemplateBuilder.h>
#include <qevercloud/types/builders/NotesMetadataListBuilder.h>
#include <qevercloud/types/builders/NotesMetadataResultSpecBuilder.h>
#include <qevercloud/types/builders/PublicUserInfoBuilder.h>
#include <qevercloud/types/builders/PublishingBuilder.h>
#include <qevercloud/types/builders/RelatedContentBuilder.h>
#include <qevercloud/types/builders/RelatedContentImageBuilder.h>
#include <qevercloud/types/builders/RelatedQueryBuilder.h>
#include <qevercloud/types/builders/RelatedResultBuilder.h>
#include <qevercloud/types/builders/RelatedResultSpecBuilder.h>
#include <qevercloud/types/builders/ResourceAttributesBuilder.h>
#include <qevercloud/types/builders/ResourceBuilder.h>
#include <qevercloud/types/builders/SavedSearchBuilder.h>
#include <qevercloud/types/builders/SavedSearchScopeBuilder.h>
#include <qevercloud/types/builders/ShareRelationshipRestrictionsBuilder.h>
#include <qevercloud/types/builders/ShareRelationshipsBuilder.h>
#include <qevercloud/types/builders/SharedNoteBuilder.h>
#include <qevercloud/types/builders/SharedNoteTemplateBuilder.h>
#include <qevercloud/types/builders/SharedNotebookBuilder.h>
#include <qevercloud/types/builders/SharedNotebookRecipientSettingsBuilder.h>
#include <qevercloud/types/builders/SyncChunkBuilder.h>
#include <qevercloud/types/builders/SyncChunkFilterBuilder.h>
#include <qevercloud/types/builders/SyncStateBuilder.h>
#include <qevercloud/types/builders/TagBuilder.h>
#include <qevercloud/types/builders/UpdateNoteIfUsnMatchesResultBuilder.h>
#include <qevercloud/types/builders/UserAttributesBuilder.h>
#include <qevercloud/types/builders/UserBuilder.h>
#include <qevercloud/types/builders/UserIdentityBuilder.h>
#include <qevercloud/types/builders/UserProfileBuilder.h>
#include <qevercloud/types/builders/UserUrlsBuilder.h>
#include <QtTest/QtTest>

namespace qevercloud {

TypeBuildersTester::TypeBuildersTester(QObject * parent) :
    QObject(parent)
{}

void TypeBuildersTester::shouldBuildSyncState()
{
    SyncState value;
    value.setCurrentTime(generateRandomInt64());
    value.setFullSyncBefore(generateRandomInt64());
    value.setUpdateCount(generateRandomInt32());
    value.setUploaded(generateRandomInt64());
    value.setUserLastUpdated(generateRandomInt64());
    value.setUserMaxMessageEventId(generateRandomInt64());

    SyncStateBuilder builder;
    builder.setCurrentTime(value.currentTime());
    builder.setFullSyncBefore(value.fullSyncBefore());
    builder.setUpdateCount(value.updateCount());
    builder.setUploaded(value.uploaded());
    builder.setUserLastUpdated(value.userLastUpdated());
    builder.setUserMaxMessageEventId(value.userMaxMessageEventId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSyncChunk()
{
    SyncChunk value;
    value.setCurrentTime(generateRandomInt64());
    value.setChunkHighUSN(generateRandomInt32());
    value.setUpdateCount(generateRandomInt32());
    value.setNotes(QList<Note>{} << generateRandomNote());
    value.setNotebooks(QList<Notebook>{} << generateRandomNotebook());
    value.setTags(QList<Tag>{} << generateRandomTag());
    value.setSearches(QList<SavedSearch>{} << generateRandomSavedSearch());
    value.setResources(QList<Resource>{} << generateRandomResource());
    value.setExpungedNotes(QList<QString>{} << generateRandomString());
    value.setExpungedNotebooks(QList<QString>{} << generateRandomString());
    value.setExpungedTags(QList<QString>{} << generateRandomString());
    value.setExpungedSearches(QList<QString>{} << generateRandomString());
    value.setLinkedNotebooks(QList<LinkedNotebook>{} << generateRandomLinkedNotebook());
    value.setExpungedLinkedNotebooks(QList<QString>{} << generateRandomString());

    SyncChunkBuilder builder;
    builder.setCurrentTime(value.currentTime());
    builder.setChunkHighUSN(value.chunkHighUSN());
    builder.setUpdateCount(value.updateCount());
    builder.setNotes(value.notes());
    builder.setNotebooks(value.notebooks());
    builder.setTags(value.tags());
    builder.setSearches(value.searches());
    builder.setResources(value.resources());
    builder.setExpungedNotes(value.expungedNotes());
    builder.setExpungedNotebooks(value.expungedNotebooks());
    builder.setExpungedTags(value.expungedTags());
    builder.setExpungedSearches(value.expungedSearches());
    builder.setLinkedNotebooks(value.linkedNotebooks());
    builder.setExpungedLinkedNotebooks(value.expungedLinkedNotebooks());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSyncChunkFilter()
{
    SyncChunkFilter value;
    value.setIncludeNotes(generateRandomBool());
    value.setIncludeNoteResources(generateRandomBool());
    value.setIncludeNoteAttributes(generateRandomBool());
    value.setIncludeNotebooks(generateRandomBool());
    value.setIncludeTags(generateRandomBool());
    value.setIncludeSearches(generateRandomBool());
    value.setIncludeResources(generateRandomBool());
    value.setIncludeLinkedNotebooks(generateRandomBool());
    value.setIncludeExpunged(generateRandomBool());
    value.setIncludeNoteApplicationDataFullMap(generateRandomBool());
    value.setIncludeResourceApplicationDataFullMap(generateRandomBool());
    value.setIncludeNoteResourceApplicationDataFullMap(generateRandomBool());
    value.setIncludeSharedNotes(generateRandomBool());
    value.setOmitSharedNotebooks(generateRandomBool());
    value.setRequireNoteContentClass(generateRandomString());
    value.setNotebookGuids(QSet<QString>{} << generateRandomString());

    SyncChunkFilterBuilder builder;
    builder.setIncludeNotes(value.includeNotes());
    builder.setIncludeNoteResources(value.includeNoteResources());
    builder.setIncludeNoteAttributes(value.includeNoteAttributes());
    builder.setIncludeNotebooks(value.includeNotebooks());
    builder.setIncludeTags(value.includeTags());
    builder.setIncludeSearches(value.includeSearches());
    builder.setIncludeResources(value.includeResources());
    builder.setIncludeLinkedNotebooks(value.includeLinkedNotebooks());
    builder.setIncludeExpunged(value.includeExpunged());
    builder.setIncludeNoteApplicationDataFullMap(value.includeNoteApplicationDataFullMap());
    builder.setIncludeResourceApplicationDataFullMap(value.includeResourceApplicationDataFullMap());
    builder.setIncludeNoteResourceApplicationDataFullMap(value.includeNoteResourceApplicationDataFullMap());
    builder.setIncludeSharedNotes(value.includeSharedNotes());
    builder.setOmitSharedNotebooks(value.omitSharedNotebooks());
    builder.setRequireNoteContentClass(value.requireNoteContentClass());
    builder.setNotebookGuids(value.notebookGuids());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteFilter()
{
    NoteFilter value;
    value.setOrder(generateRandomInt32());
    value.setAscending(generateRandomBool());
    value.setWords(generateRandomString());
    value.setNotebookGuid(generateRandomString());
    value.setTagGuids(QList<QString>{} << generateRandomString());
    value.setTimeZone(generateRandomString());
    value.setInactive(generateRandomBool());
    value.setEmphasized(generateRandomString());
    value.setIncludeAllReadableNotebooks(generateRandomBool());
    value.setIncludeAllReadableWorkspaces(generateRandomBool());
    value.setContext(generateRandomString());
    value.setRawWords(generateRandomString());
    value.setSearchContextBytes(generateRandomString().toUtf8());

    NoteFilterBuilder builder;
    builder.setOrder(value.order());
    builder.setAscending(value.ascending());
    builder.setWords(value.words());
    builder.setNotebookGuid(value.notebookGuid());
    builder.setTagGuids(value.tagGuids());
    builder.setTimeZone(value.timeZone());
    builder.setInactive(value.inactive());
    builder.setEmphasized(value.emphasized());
    builder.setIncludeAllReadableNotebooks(value.includeAllReadableNotebooks());
    builder.setIncludeAllReadableWorkspaces(value.includeAllReadableWorkspaces());
    builder.setContext(value.context());
    builder.setRawWords(value.rawWords());
    builder.setSearchContextBytes(value.searchContextBytes());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteList()
{
    NoteList value;
    value.setStartIndex(generateRandomInt32());
    value.setTotalNotes(generateRandomInt32());
    value.setNotes(QList<Note>{} << generateRandomNote());
    value.setStoppedWords(QList<QString>{} << generateRandomString());
    value.setSearchedWords(QList<QString>{} << generateRandomString());
    value.setUpdateCount(generateRandomInt32());
    value.setSearchContextBytes(generateRandomString().toUtf8());
    value.setDebugInfo(generateRandomString());

    NoteListBuilder builder;
    builder.setStartIndex(value.startIndex());
    builder.setTotalNotes(value.totalNotes());
    builder.setNotes(value.notes());
    builder.setStoppedWords(value.stoppedWords());
    builder.setSearchedWords(value.searchedWords());
    builder.setUpdateCount(value.updateCount());
    builder.setSearchContextBytes(value.searchContextBytes());
    builder.setDebugInfo(value.debugInfo());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteMetadata()
{
    NoteMetadata value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setGuid(generateRandomString());
    value.setTitle(generateRandomString());
    value.setContentLength(generateRandomInt32());
    value.setCreated(generateRandomInt64());
    value.setUpdated(generateRandomInt64());
    value.setDeleted(generateRandomInt64());
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setNotebookGuid(generateRandomString());
    value.setTagGuids(QList<QString>{} << generateRandomString());
    value.setAttributes(generateRandomNoteAttributes());
    value.setLargestResourceMime(generateRandomString());
    value.setLargestResourceSize(generateRandomInt32());

    NoteMetadataBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setGuid(value.guid());
    builder.setTitle(value.title());
    builder.setContentLength(value.contentLength());
    builder.setCreated(value.created());
    builder.setUpdated(value.updated());
    builder.setDeleted(value.deleted());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setNotebookGuid(value.notebookGuid());
    builder.setTagGuids(value.tagGuids());
    builder.setAttributes(value.attributes());
    builder.setLargestResourceMime(value.largestResourceMime());
    builder.setLargestResourceSize(value.largestResourceSize());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotesMetadataList()
{
    NotesMetadataList value;
    value.setStartIndex(generateRandomInt32());
    value.setTotalNotes(generateRandomInt32());
    value.setNotes(QList<NoteMetadata>{} << generateRandomNoteMetadata());
    value.setStoppedWords(QList<QString>{} << generateRandomString());
    value.setSearchedWords(QList<QString>{} << generateRandomString());
    value.setUpdateCount(generateRandomInt32());
    value.setSearchContextBytes(generateRandomString().toUtf8());
    value.setDebugInfo(generateRandomString());

    NotesMetadataListBuilder builder;
    builder.setStartIndex(value.startIndex());
    builder.setTotalNotes(value.totalNotes());
    builder.setNotes(value.notes());
    builder.setStoppedWords(value.stoppedWords());
    builder.setSearchedWords(value.searchedWords());
    builder.setUpdateCount(value.updateCount());
    builder.setSearchContextBytes(value.searchContextBytes());
    builder.setDebugInfo(value.debugInfo());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotesMetadataResultSpec()
{
    NotesMetadataResultSpec value;
    value.setIncludeTitle(generateRandomBool());
    value.setIncludeContentLength(generateRandomBool());
    value.setIncludeCreated(generateRandomBool());
    value.setIncludeUpdated(generateRandomBool());
    value.setIncludeDeleted(generateRandomBool());
    value.setIncludeUpdateSequenceNum(generateRandomBool());
    value.setIncludeNotebookGuid(generateRandomBool());
    value.setIncludeTagGuids(generateRandomBool());
    value.setIncludeAttributes(generateRandomBool());
    value.setIncludeLargestResourceMime(generateRandomBool());
    value.setIncludeLargestResourceSize(generateRandomBool());

    NotesMetadataResultSpecBuilder builder;
    builder.setIncludeTitle(value.includeTitle());
    builder.setIncludeContentLength(value.includeContentLength());
    builder.setIncludeCreated(value.includeCreated());
    builder.setIncludeUpdated(value.includeUpdated());
    builder.setIncludeDeleted(value.includeDeleted());
    builder.setIncludeUpdateSequenceNum(value.includeUpdateSequenceNum());
    builder.setIncludeNotebookGuid(value.includeNotebookGuid());
    builder.setIncludeTagGuids(value.includeTagGuids());
    builder.setIncludeAttributes(value.includeAttributes());
    builder.setIncludeLargestResourceMime(value.includeLargestResourceMime());
    builder.setIncludeLargestResourceSize(value.includeLargestResourceSize());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteCollectionCounts()
{
    NoteCollectionCounts value;

    QMap<Guid, qint32> notebookCounts;
    notebookCounts[generateRandomString()] = generateRandomInt32();
    value.setNotebookCounts(std::move(notebookCounts));


    QMap<Guid, qint32> tagCounts;
    tagCounts[generateRandomString()] = generateRandomInt32();
    value.setTagCounts(std::move(tagCounts));

    value.setTrashCount(generateRandomInt32());

    NoteCollectionCountsBuilder builder;
    builder.setNotebookCounts(value.notebookCounts());
    builder.setTagCounts(value.tagCounts());
    builder.setTrashCount(value.trashCount());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteResultSpec()
{
    NoteResultSpec value;
    value.setIncludeContent(generateRandomBool());
    value.setIncludeResourcesData(generateRandomBool());
    value.setIncludeResourcesRecognition(generateRandomBool());
    value.setIncludeResourcesAlternateData(generateRandomBool());
    value.setIncludeSharedNotes(generateRandomBool());
    value.setIncludeNoteAppDataValues(generateRandomBool());
    value.setIncludeResourceAppDataValues(generateRandomBool());
    value.setIncludeAccountLimits(generateRandomBool());

    NoteResultSpecBuilder builder;
    builder.setIncludeContent(value.includeContent());
    builder.setIncludeResourcesData(value.includeResourcesData());
    builder.setIncludeResourcesRecognition(value.includeResourcesRecognition());
    builder.setIncludeResourcesAlternateData(value.includeResourcesAlternateData());
    builder.setIncludeSharedNotes(value.includeSharedNotes());
    builder.setIncludeNoteAppDataValues(value.includeNoteAppDataValues());
    builder.setIncludeResourceAppDataValues(value.includeResourceAppDataValues());
    builder.setIncludeAccountLimits(value.includeAccountLimits());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteEmailParameters()
{
    NoteEmailParameters value;
    value.setGuid(generateRandomString());
    value.setNote(generateRandomNote());
    value.setToAddresses(QList<QString>{} << generateRandomString());
    value.setCcAddresses(QList<QString>{} << generateRandomString());
    value.setSubject(generateRandomString());
    value.setMessage(generateRandomString());

    NoteEmailParametersBuilder builder;
    builder.setGuid(value.guid());
    builder.setNote(value.note());
    builder.setToAddresses(value.toAddresses());
    builder.setCcAddresses(value.ccAddresses());
    builder.setSubject(value.subject());
    builder.setMessage(value.message());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteVersionId()
{
    NoteVersionId value;
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setUpdated(generateRandomInt64());
    value.setSaved(generateRandomInt64());
    value.setTitle(generateRandomString());
    value.setLastEditorId(generateRandomInt32());

    NoteVersionIdBuilder builder;
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setUpdated(value.updated());
    builder.setSaved(value.saved());
    builder.setTitle(value.title());
    builder.setLastEditorId(value.lastEditorId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildRelatedQuery()
{
    RelatedQuery value;
    value.setNoteGuid(generateRandomString());
    value.setPlainText(generateRandomString());
    value.setFilter(generateRandomNoteFilter());
    value.setReferenceUri(generateRandomString());
    value.setContext(generateRandomString());
    value.setCacheKey(generateRandomString());

    RelatedQueryBuilder builder;
    builder.setNoteGuid(value.noteGuid());
    builder.setPlainText(value.plainText());
    builder.setFilter(value.filter());
    builder.setReferenceUri(value.referenceUri());
    builder.setContext(value.context());
    builder.setCacheKey(value.cacheKey());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildRelatedResult()
{
    RelatedResult value;
    value.setNotes(QList<Note>{} << generateRandomNote());
    value.setNotebooks(QList<Notebook>{} << generateRandomNotebook());
    value.setTags(QList<Tag>{} << generateRandomTag());
    value.setContainingNotebooks(QList<NotebookDescriptor>{} << generateRandomNotebookDescriptor());
    value.setDebugInfo(generateRandomString());
    value.setExperts(QList<UserProfile>{} << generateRandomUserProfile());
    value.setRelatedContent(QList<RelatedContent>{} << generateRandomRelatedContent());
    value.setCacheKey(generateRandomString());
    value.setCacheExpires(generateRandomInt32());

    RelatedResultBuilder builder;
    builder.setNotes(value.notes());
    builder.setNotebooks(value.notebooks());
    builder.setTags(value.tags());
    builder.setContainingNotebooks(value.containingNotebooks());
    builder.setDebugInfo(value.debugInfo());
    builder.setExperts(value.experts());
    builder.setRelatedContent(value.relatedContent());
    builder.setCacheKey(value.cacheKey());
    builder.setCacheExpires(value.cacheExpires());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildRelatedResultSpec()
{
    RelatedResultSpec value;
    value.setMaxNotes(generateRandomInt32());
    value.setMaxNotebooks(generateRandomInt32());
    value.setMaxTags(generateRandomInt32());
    value.setWritableNotebooksOnly(generateRandomBool());
    value.setIncludeContainingNotebooks(generateRandomBool());
    value.setIncludeDebugInfo(generateRandomBool());
    value.setMaxExperts(generateRandomInt32());
    value.setMaxRelatedContent(generateRandomInt32());
    value.setRelatedContentTypes(QSet<RelatedContentType>{} << RelatedContentType::NEWS_ARTICLE);

    RelatedResultSpecBuilder builder;
    builder.setMaxNotes(value.maxNotes());
    builder.setMaxNotebooks(value.maxNotebooks());
    builder.setMaxTags(value.maxTags());
    builder.setWritableNotebooksOnly(value.writableNotebooksOnly());
    builder.setIncludeContainingNotebooks(value.includeContainingNotebooks());
    builder.setIncludeDebugInfo(value.includeDebugInfo());
    builder.setMaxExperts(value.maxExperts());
    builder.setMaxRelatedContent(value.maxRelatedContent());
    builder.setRelatedContentTypes(value.relatedContentTypes());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUpdateNoteIfUsnMatchesResult()
{
    UpdateNoteIfUsnMatchesResult value;
    value.setNote(generateRandomNote());
    value.setUpdated(generateRandomBool());

    UpdateNoteIfUsnMatchesResultBuilder builder;
    builder.setNote(value.note());
    builder.setUpdated(value.updated());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildShareRelationshipRestrictions()
{
    ShareRelationshipRestrictions value;
    value.setNoSetReadOnly(generateRandomBool());
    value.setNoSetReadPlusActivity(generateRandomBool());
    value.setNoSetModify(generateRandomBool());
    value.setNoSetFullAccess(generateRandomBool());

    ShareRelationshipRestrictionsBuilder builder;
    builder.setNoSetReadOnly(value.noSetReadOnly());
    builder.setNoSetReadPlusActivity(value.noSetReadPlusActivity());
    builder.setNoSetModify(value.noSetModify());
    builder.setNoSetFullAccess(value.noSetFullAccess());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildInvitationShareRelationship()
{
    InvitationShareRelationship value;
    value.setDisplayName(generateRandomString());
    value.setRecipientUserIdentity(generateRandomUserIdentity());
    value.setPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK);
    value.setSharerUserId(generateRandomInt32());

    InvitationShareRelationshipBuilder builder;
    builder.setDisplayName(value.displayName());
    builder.setRecipientUserIdentity(value.recipientUserIdentity());
    builder.setPrivilege(value.privilege());
    builder.setSharerUserId(value.sharerUserId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildMemberShareRelationship()
{
    MemberShareRelationship value;
    value.setDisplayName(generateRandomString());
    value.setRecipientUserId(generateRandomInt32());
    value.setBestPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK);
    value.setIndividualPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK);
    value.setRestrictions(generateRandomShareRelationshipRestrictions());
    value.setSharerUserId(generateRandomInt32());

    MemberShareRelationshipBuilder builder;
    builder.setDisplayName(value.displayName());
    builder.setRecipientUserId(value.recipientUserId());
    builder.setBestPrivilege(value.bestPrivilege());
    builder.setIndividualPrivilege(value.individualPrivilege());
    builder.setRestrictions(value.restrictions());
    builder.setSharerUserId(value.sharerUserId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildShareRelationships()
{
    ShareRelationships value;
    value.setInvitations(QList<InvitationShareRelationship>{} << generateRandomInvitationShareRelationship());
    value.setMemberships(QList<MemberShareRelationship>{} << generateRandomMemberShareRelationship());
    value.setInvitationRestrictions(generateRandomShareRelationshipRestrictions());

    ShareRelationshipsBuilder builder;
    builder.setInvitations(value.invitations());
    builder.setMemberships(value.memberships());
    builder.setInvitationRestrictions(value.invitationRestrictions());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNotebookSharesParameters()
{
    ManageNotebookSharesParameters value;
    value.setNotebookGuid(generateRandomString());
    value.setInviteMessage(generateRandomString());
    value.setMembershipsToUpdate(QList<MemberShareRelationship>{} << generateRandomMemberShareRelationship());
    value.setInvitationsToCreateOrUpdate(QList<InvitationShareRelationship>{} << generateRandomInvitationShareRelationship());
    value.setUnshares(QList<UserIdentity>{} << generateRandomUserIdentity());

    ManageNotebookSharesParametersBuilder builder;
    builder.setNotebookGuid(value.notebookGuid());
    builder.setInviteMessage(value.inviteMessage());
    builder.setMembershipsToUpdate(value.membershipsToUpdate());
    builder.setInvitationsToCreateOrUpdate(value.invitationsToCreateOrUpdate());
    builder.setUnshares(value.unshares());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNotebookSharesError()
{
    ManageNotebookSharesError value;
    value.setUserIdentity(generateRandomUserIdentity());
    value.setUserException(generateRandomEDAMUserException());
    value.setNotFoundException(generateRandomEDAMNotFoundException());

    ManageNotebookSharesErrorBuilder builder;
    builder.setUserIdentity(value.userIdentity());
    builder.setUserException(value.userException());
    builder.setNotFoundException(value.notFoundException());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNotebookSharesResult()
{
    ManageNotebookSharesResult value;
    value.setErrors(QList<ManageNotebookSharesError>{} << generateRandomManageNotebookSharesError());

    ManageNotebookSharesResultBuilder builder;
    builder.setErrors(value.errors());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSharedNoteTemplate()
{
    SharedNoteTemplate value;
    value.setNoteGuid(generateRandomString());
    value.setRecipientThreadId(generateRandomInt64());
    value.setRecipientContacts(QList<Contact>{} << generateRandomContact());
    value.setPrivilege(SharedNotePrivilegeLevel::READ_NOTE);

    SharedNoteTemplateBuilder builder;
    builder.setNoteGuid(value.noteGuid());
    builder.setRecipientThreadId(value.recipientThreadId());
    builder.setRecipientContacts(value.recipientContacts());
    builder.setPrivilege(value.privilege());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotebookShareTemplate()
{
    NotebookShareTemplate value;
    value.setNotebookGuid(generateRandomString());
    value.setRecipientThreadId(generateRandomInt64());
    value.setRecipientContacts(QList<Contact>{} << generateRandomContact());
    value.setPrivilege(SharedNotebookPrivilegeLevel::READ_NOTEBOOK);

    NotebookShareTemplateBuilder builder;
    builder.setNotebookGuid(value.notebookGuid());
    builder.setRecipientThreadId(value.recipientThreadId());
    builder.setRecipientContacts(value.recipientContacts());
    builder.setPrivilege(value.privilege());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildCreateOrUpdateNotebookSharesResult()
{
    CreateOrUpdateNotebookSharesResult value;
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setMatchingShares(QList<SharedNotebook>{} << generateRandomSharedNotebook());

    CreateOrUpdateNotebookSharesResultBuilder builder;
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setMatchingShares(value.matchingShares());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteShareRelationshipRestrictions()
{
    NoteShareRelationshipRestrictions value;
    value.setNoSetReadNote(generateRandomBool());
    value.setNoSetModifyNote(generateRandomBool());
    value.setNoSetFullAccess(generateRandomBool());

    NoteShareRelationshipRestrictionsBuilder builder;
    builder.setNoSetReadNote(value.noSetReadNote());
    builder.setNoSetModifyNote(value.noSetModifyNote());
    builder.setNoSetFullAccess(value.noSetFullAccess());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteMemberShareRelationship()
{
    NoteMemberShareRelationship value;
    value.setDisplayName(generateRandomString());
    value.setRecipientUserId(generateRandomInt32());
    value.setPrivilege(SharedNotePrivilegeLevel::READ_NOTE);
    value.setRestrictions(generateRandomNoteShareRelationshipRestrictions());
    value.setSharerUserId(generateRandomInt32());

    NoteMemberShareRelationshipBuilder builder;
    builder.setDisplayName(value.displayName());
    builder.setRecipientUserId(value.recipientUserId());
    builder.setPrivilege(value.privilege());
    builder.setRestrictions(value.restrictions());
    builder.setSharerUserId(value.sharerUserId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteInvitationShareRelationship()
{
    NoteInvitationShareRelationship value;
    value.setDisplayName(generateRandomString());
    value.setRecipientIdentityId(generateRandomInt64());
    value.setPrivilege(SharedNotePrivilegeLevel::READ_NOTE);
    value.setSharerUserId(generateRandomInt32());

    NoteInvitationShareRelationshipBuilder builder;
    builder.setDisplayName(value.displayName());
    builder.setRecipientIdentityId(value.recipientIdentityId());
    builder.setPrivilege(value.privilege());
    builder.setSharerUserId(value.sharerUserId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteShareRelationships()
{
    NoteShareRelationships value;
    value.setInvitations(QList<NoteInvitationShareRelationship>{} << generateRandomNoteInvitationShareRelationship());
    value.setMemberships(QList<NoteMemberShareRelationship>{} << generateRandomNoteMemberShareRelationship());
    value.setInvitationRestrictions(generateRandomNoteShareRelationshipRestrictions());

    NoteShareRelationshipsBuilder builder;
    builder.setInvitations(value.invitations());
    builder.setMemberships(value.memberships());
    builder.setInvitationRestrictions(value.invitationRestrictions());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNoteSharesParameters()
{
    ManageNoteSharesParameters value;
    value.setNoteGuid(generateRandomString());
    value.setMembershipsToUpdate(QList<NoteMemberShareRelationship>{} << generateRandomNoteMemberShareRelationship());
    value.setInvitationsToUpdate(QList<NoteInvitationShareRelationship>{} << generateRandomNoteInvitationShareRelationship());
    value.setMembershipsToUnshare(QList<qint32>{} << generateRandomInt32());
    value.setInvitationsToUnshare(QList<qint64>{} << generateRandomInt64());

    ManageNoteSharesParametersBuilder builder;
    builder.setNoteGuid(value.noteGuid());
    builder.setMembershipsToUpdate(value.membershipsToUpdate());
    builder.setInvitationsToUpdate(value.invitationsToUpdate());
    builder.setMembershipsToUnshare(value.membershipsToUnshare());
    builder.setInvitationsToUnshare(value.invitationsToUnshare());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNoteSharesError()
{
    ManageNoteSharesError value;
    value.setIdentityID(generateRandomInt64());
    value.setUserID(generateRandomInt32());
    value.setUserException(generateRandomEDAMUserException());
    value.setNotFoundException(generateRandomEDAMNotFoundException());

    ManageNoteSharesErrorBuilder builder;
    builder.setIdentityID(value.identityID());
    builder.setUserID(value.userID());
    builder.setUserException(value.userException());
    builder.setNotFoundException(value.notFoundException());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildManageNoteSharesResult()
{
    ManageNoteSharesResult value;
    value.setErrors(QList<ManageNoteSharesError>{} << generateRandomManageNoteSharesError());

    ManageNoteSharesResultBuilder builder;
    builder.setErrors(value.errors());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildData()
{
    Data value;
    value.setBodyHash(generateRandomString().toUtf8());
    value.setSize(generateRandomInt32());
    value.setBody(generateRandomString().toUtf8());

    DataBuilder builder;
    builder.setBodyHash(value.bodyHash());
    builder.setSize(value.size());
    builder.setBody(value.body());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUserAttributes()
{
    UserAttributes value;
    value.setDefaultLocationName(generateRandomString());
    value.setDefaultLatitude(generateRandomDouble());
    value.setDefaultLongitude(generateRandomDouble());
    value.setPreactivation(generateRandomBool());
    value.setViewedPromotions(QList<QString>{} << generateRandomString());
    value.setIncomingEmailAddress(generateRandomString());
    value.setRecentMailedAddresses(QList<QString>{} << generateRandomString());
    value.setComments(generateRandomString());
    value.setDateAgreedToTermsOfService(generateRandomInt64());
    value.setMaxReferrals(generateRandomInt32());
    value.setReferralCount(generateRandomInt32());
    value.setRefererCode(generateRandomString());
    value.setSentEmailDate(generateRandomInt64());
    value.setSentEmailCount(generateRandomInt32());
    value.setDailyEmailLimit(generateRandomInt32());
    value.setEmailOptOutDate(generateRandomInt64());
    value.setPartnerEmailOptInDate(generateRandomInt64());
    value.setPreferredLanguage(generateRandomString());
    value.setPreferredCountry(generateRandomString());
    value.setClipFullPage(generateRandomBool());
    value.setTwitterUserName(generateRandomString());
    value.setTwitterId(generateRandomString());
    value.setGroupName(generateRandomString());
    value.setRecognitionLanguage(generateRandomString());
    value.setReferralProof(generateRandomString());
    value.setEducationalDiscount(generateRandomBool());
    value.setBusinessAddress(generateRandomString());
    value.setHideSponsorBilling(generateRandomBool());
    value.setUseEmailAutoFiling(generateRandomBool());
    value.setReminderEmailConfig(ReminderEmailConfig::DO_NOT_SEND);
    value.setEmailAddressLastConfirmed(generateRandomInt64());
    value.setPasswordUpdated(generateRandomInt64());
    value.setSalesforcePushEnabled(generateRandomBool());
    value.setShouldLogClientEvent(generateRandomBool());
    value.setOptOutMachineLearning(generateRandomBool());

    UserAttributesBuilder builder;
    builder.setDefaultLocationName(value.defaultLocationName());
    builder.setDefaultLatitude(value.defaultLatitude());
    builder.setDefaultLongitude(value.defaultLongitude());
    builder.setPreactivation(value.preactivation());
    builder.setViewedPromotions(value.viewedPromotions());
    builder.setIncomingEmailAddress(value.incomingEmailAddress());
    builder.setRecentMailedAddresses(value.recentMailedAddresses());
    builder.setComments(value.comments());
    builder.setDateAgreedToTermsOfService(value.dateAgreedToTermsOfService());
    builder.setMaxReferrals(value.maxReferrals());
    builder.setReferralCount(value.referralCount());
    builder.setRefererCode(value.refererCode());
    builder.setSentEmailDate(value.sentEmailDate());
    builder.setSentEmailCount(value.sentEmailCount());
    builder.setDailyEmailLimit(value.dailyEmailLimit());
    builder.setEmailOptOutDate(value.emailOptOutDate());
    builder.setPartnerEmailOptInDate(value.partnerEmailOptInDate());
    builder.setPreferredLanguage(value.preferredLanguage());
    builder.setPreferredCountry(value.preferredCountry());
    builder.setClipFullPage(value.clipFullPage());
    builder.setTwitterUserName(value.twitterUserName());
    builder.setTwitterId(value.twitterId());
    builder.setGroupName(value.groupName());
    builder.setRecognitionLanguage(value.recognitionLanguage());
    builder.setReferralProof(value.referralProof());
    builder.setEducationalDiscount(value.educationalDiscount());
    builder.setBusinessAddress(value.businessAddress());
    builder.setHideSponsorBilling(value.hideSponsorBilling());
    builder.setUseEmailAutoFiling(value.useEmailAutoFiling());
    builder.setReminderEmailConfig(value.reminderEmailConfig());
    builder.setEmailAddressLastConfirmed(value.emailAddressLastConfirmed());
    builder.setPasswordUpdated(value.passwordUpdated());
    builder.setSalesforcePushEnabled(value.salesforcePushEnabled());
    builder.setShouldLogClientEvent(value.shouldLogClientEvent());
    builder.setOptOutMachineLearning(value.optOutMachineLearning());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBusinessUserAttributes()
{
    BusinessUserAttributes value;
    value.setTitle(generateRandomString());
    value.setLocation(generateRandomString());
    value.setDepartment(generateRandomString());
    value.setMobilePhone(generateRandomString());
    value.setLinkedInProfileUrl(generateRandomString());
    value.setWorkPhone(generateRandomString());
    value.setCompanyStartDate(generateRandomInt64());

    BusinessUserAttributesBuilder builder;
    builder.setTitle(value.title());
    builder.setLocation(value.location());
    builder.setDepartment(value.department());
    builder.setMobilePhone(value.mobilePhone());
    builder.setLinkedInProfileUrl(value.linkedInProfileUrl());
    builder.setWorkPhone(value.workPhone());
    builder.setCompanyStartDate(value.companyStartDate());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildAccounting()
{
    Accounting value;
    value.setUploadLimitEnd(generateRandomInt64());
    value.setUploadLimitNextMonth(generateRandomInt64());
    value.setPremiumServiceStatus(PremiumOrderStatus::NONE);
    value.setPremiumOrderNumber(generateRandomString());
    value.setPremiumCommerceService(generateRandomString());
    value.setPremiumServiceStart(generateRandomInt64());
    value.setPremiumServiceSKU(generateRandomString());
    value.setLastSuccessfulCharge(generateRandomInt64());
    value.setLastFailedCharge(generateRandomInt64());
    value.setLastFailedChargeReason(generateRandomString());
    value.setNextPaymentDue(generateRandomInt64());
    value.setPremiumLockUntil(generateRandomInt64());
    value.setUpdated(generateRandomInt64());
    value.setPremiumSubscriptionNumber(generateRandomString());
    value.setLastRequestedCharge(generateRandomInt64());
    value.setCurrency(generateRandomString());
    value.setUnitPrice(generateRandomInt32());
    value.setBusinessId(generateRandomInt32());
    value.setBusinessName(generateRandomString());
    value.setBusinessRole(BusinessUserRole::ADMIN);
    value.setUnitDiscount(generateRandomInt32());
    value.setNextChargeDate(generateRandomInt64());
    value.setAvailablePoints(generateRandomInt32());

    AccountingBuilder builder;
    builder.setUploadLimitEnd(value.uploadLimitEnd());
    builder.setUploadLimitNextMonth(value.uploadLimitNextMonth());
    builder.setPremiumServiceStatus(value.premiumServiceStatus());
    builder.setPremiumOrderNumber(value.premiumOrderNumber());
    builder.setPremiumCommerceService(value.premiumCommerceService());
    builder.setPremiumServiceStart(value.premiumServiceStart());
    builder.setPremiumServiceSKU(value.premiumServiceSKU());
    builder.setLastSuccessfulCharge(value.lastSuccessfulCharge());
    builder.setLastFailedCharge(value.lastFailedCharge());
    builder.setLastFailedChargeReason(value.lastFailedChargeReason());
    builder.setNextPaymentDue(value.nextPaymentDue());
    builder.setPremiumLockUntil(value.premiumLockUntil());
    builder.setUpdated(value.updated());
    builder.setPremiumSubscriptionNumber(value.premiumSubscriptionNumber());
    builder.setLastRequestedCharge(value.lastRequestedCharge());
    builder.setCurrency(value.currency());
    builder.setUnitPrice(value.unitPrice());
    builder.setBusinessId(value.businessId());
    builder.setBusinessName(value.businessName());
    builder.setBusinessRole(value.businessRole());
    builder.setUnitDiscount(value.unitDiscount());
    builder.setNextChargeDate(value.nextChargeDate());
    builder.setAvailablePoints(value.availablePoints());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBusinessUserInfo()
{
    BusinessUserInfo value;
    value.setBusinessId(generateRandomInt32());
    value.setBusinessName(generateRandomString());
    value.setRole(BusinessUserRole::ADMIN);
    value.setEmail(generateRandomString());
    value.setUpdated(generateRandomInt64());

    BusinessUserInfoBuilder builder;
    builder.setBusinessId(value.businessId());
    builder.setBusinessName(value.businessName());
    builder.setRole(value.role());
    builder.setEmail(value.email());
    builder.setUpdated(value.updated());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildAccountLimits()
{
    AccountLimits value;
    value.setUserMailLimitDaily(generateRandomInt32());
    value.setNoteSizeMax(generateRandomInt64());
    value.setResourceSizeMax(generateRandomInt64());
    value.setUserLinkedNotebookMax(generateRandomInt32());
    value.setUploadLimit(generateRandomInt64());
    value.setUserNoteCountMax(generateRandomInt32());
    value.setUserNotebookCountMax(generateRandomInt32());
    value.setUserTagCountMax(generateRandomInt32());
    value.setNoteTagCountMax(generateRandomInt32());
    value.setUserSavedSearchesMax(generateRandomInt32());
    value.setNoteResourceCountMax(generateRandomInt32());

    AccountLimitsBuilder builder;
    builder.setUserMailLimitDaily(value.userMailLimitDaily());
    builder.setNoteSizeMax(value.noteSizeMax());
    builder.setResourceSizeMax(value.resourceSizeMax());
    builder.setUserLinkedNotebookMax(value.userLinkedNotebookMax());
    builder.setUploadLimit(value.uploadLimit());
    builder.setUserNoteCountMax(value.userNoteCountMax());
    builder.setUserNotebookCountMax(value.userNotebookCountMax());
    builder.setUserTagCountMax(value.userTagCountMax());
    builder.setNoteTagCountMax(value.noteTagCountMax());
    builder.setUserSavedSearchesMax(value.userSavedSearchesMax());
    builder.setNoteResourceCountMax(value.noteResourceCountMax());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUser()
{
    User value;
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setId(generateRandomInt32());
    value.setUsername(generateRandomString());
    value.setEmail(generateRandomString());
    value.setName(generateRandomString());
    value.setTimezone(generateRandomString());
    value.setPrivilege(PrivilegeLevel::NORMAL);
    value.setServiceLevel(ServiceLevel::BASIC);
    value.setCreated(generateRandomInt64());
    value.setUpdated(generateRandomInt64());
    value.setDeleted(generateRandomInt64());
    value.setActive(generateRandomBool());
    value.setShardId(generateRandomString());
    value.setAttributes(generateRandomUserAttributes());
    value.setAccounting(generateRandomAccounting());
    value.setBusinessUserInfo(generateRandomBusinessUserInfo());
    value.setPhotoUrl(generateRandomString());
    value.setPhotoLastUpdated(generateRandomInt64());
    value.setAccountLimits(generateRandomAccountLimits());

    UserBuilder builder;
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setId(value.id());
    builder.setUsername(value.username());
    builder.setEmail(value.email());
    builder.setName(value.name());
    builder.setTimezone(value.timezone());
    builder.setPrivilege(value.privilege());
    builder.setServiceLevel(value.serviceLevel());
    builder.setCreated(value.created());
    builder.setUpdated(value.updated());
    builder.setDeleted(value.deleted());
    builder.setActive(value.active());
    builder.setShardId(value.shardId());
    builder.setAttributes(value.attributes());
    builder.setAccounting(value.accounting());
    builder.setBusinessUserInfo(value.businessUserInfo());
    builder.setPhotoUrl(value.photoUrl());
    builder.setPhotoLastUpdated(value.photoLastUpdated());
    builder.setAccountLimits(value.accountLimits());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildContact()
{
    Contact value;
    value.setName(generateRandomString());
    value.setId(generateRandomString());
    value.setType(ContactType::EVERNOTE);
    value.setPhotoUrl(generateRandomString());
    value.setPhotoLastUpdated(generateRandomInt64());
    value.setMessagingPermit(generateRandomString().toUtf8());
    value.setMessagingPermitExpires(generateRandomInt64());

    ContactBuilder builder;
    builder.setName(value.name());
    builder.setId(value.id());
    builder.setType(value.type());
    builder.setPhotoUrl(value.photoUrl());
    builder.setPhotoLastUpdated(value.photoLastUpdated());
    builder.setMessagingPermit(value.messagingPermit());
    builder.setMessagingPermitExpires(value.messagingPermitExpires());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildIdentity()
{
    Identity value;
    value.setId(generateRandomInt64());
    value.setContact(generateRandomContact());
    value.setUserId(generateRandomInt32());
    value.setDeactivated(generateRandomBool());
    value.setSameBusiness(generateRandomBool());
    value.setBlocked(generateRandomBool());
    value.setUserConnected(generateRandomBool());
    value.setEventId(generateRandomInt64());

    IdentityBuilder builder;
    builder.setId(value.id());
    builder.setContact(value.contact());
    builder.setUserId(value.userId());
    builder.setDeactivated(value.deactivated());
    builder.setSameBusiness(value.sameBusiness());
    builder.setBlocked(value.blocked());
    builder.setUserConnected(value.userConnected());
    builder.setEventId(value.eventId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildTag()
{
    Tag value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setLinkedNotebookGuid(generateRandomString());
    value.setParentTagLocalId(generateRandomString());
    value.setGuid(generateRandomString());
    value.setName(generateRandomString());
    value.setParentGuid(generateRandomString());
    value.setUpdateSequenceNum(generateRandomInt32());

    TagBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setLinkedNotebookGuid(value.linkedNotebookGuid());
    builder.setParentTagLocalId(value.parentTagLocalId());
    builder.setGuid(value.guid());
    builder.setName(value.name());
    builder.setParentGuid(value.parentGuid());
    builder.setUpdateSequenceNum(value.updateSequenceNum());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildLazyMap()
{
    LazyMap value;
    value.setKeysOnly(QSet<QString>{} << generateRandomString());

    QMap<QString, QString> fullMap;
    fullMap[generateRandomString()] = generateRandomString();
    value.setFullMap(std::move(fullMap));


    LazyMapBuilder builder;
    builder.setKeysOnly(value.keysOnly());
    builder.setFullMap(value.fullMap());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildResourceAttributes()
{
    ResourceAttributes value;
    value.setSourceURL(generateRandomString());
    value.setTimestamp(generateRandomInt64());
    value.setLatitude(generateRandomDouble());
    value.setLongitude(generateRandomDouble());
    value.setAltitude(generateRandomDouble());
    value.setCameraMake(generateRandomString());
    value.setCameraModel(generateRandomString());
    value.setClientWillIndex(generateRandomBool());
    value.setRecoType(generateRandomString());
    value.setFileName(generateRandomString());
    value.setAttachment(generateRandomBool());
    value.setApplicationData(generateRandomLazyMap());

    ResourceAttributesBuilder builder;
    builder.setSourceURL(value.sourceURL());
    builder.setTimestamp(value.timestamp());
    builder.setLatitude(value.latitude());
    builder.setLongitude(value.longitude());
    builder.setAltitude(value.altitude());
    builder.setCameraMake(value.cameraMake());
    builder.setCameraModel(value.cameraModel());
    builder.setClientWillIndex(value.clientWillIndex());
    builder.setRecoType(value.recoType());
    builder.setFileName(value.fileName());
    builder.setAttachment(value.attachment());
    builder.setApplicationData(value.applicationData());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildResource()
{
    Resource value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setNoteLocalId(generateRandomString());
    value.setGuid(generateRandomString());
    value.setNoteGuid(generateRandomString());
    value.setData(generateRandomData());
    value.setMime(generateRandomString());
    value.setWidth(generateRandomInt16());
    value.setHeight(generateRandomInt16());
    value.setDuration(generateRandomInt16());
    value.setActive(generateRandomBool());
    value.setRecognition(generateRandomData());
    value.setAttributes(generateRandomResourceAttributes());
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setAlternateData(generateRandomData());

    ResourceBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setNoteLocalId(value.noteLocalId());
    builder.setGuid(value.guid());
    builder.setNoteGuid(value.noteGuid());
    builder.setData(value.data());
    builder.setMime(value.mime());
    builder.setWidth(value.width());
    builder.setHeight(value.height());
    builder.setDuration(value.duration());
    builder.setActive(value.active());
    builder.setRecognition(value.recognition());
    builder.setAttributes(value.attributes());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setAlternateData(value.alternateData());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteAttributes()
{
    NoteAttributes value;
    value.setSubjectDate(generateRandomInt64());
    value.setLatitude(generateRandomDouble());
    value.setLongitude(generateRandomDouble());
    value.setAltitude(generateRandomDouble());
    value.setAuthor(generateRandomString());
    value.setSource(generateRandomString());
    value.setSourceURL(generateRandomString());
    value.setSourceApplication(generateRandomString());
    value.setShareDate(generateRandomInt64());
    value.setReminderOrder(generateRandomInt64());
    value.setReminderDoneTime(generateRandomInt64());
    value.setReminderTime(generateRandomInt64());
    value.setPlaceName(generateRandomString());
    value.setContentClass(generateRandomString());
    value.setApplicationData(generateRandomLazyMap());
    value.setLastEditedBy(generateRandomString());

    QMap<QString, QString> classifications;
    classifications[generateRandomString()] = generateRandomString();
    value.setClassifications(std::move(classifications));

    value.setCreatorId(generateRandomInt32());
    value.setLastEditorId(generateRandomInt32());
    value.setSharedWithBusiness(generateRandomBool());
    value.setConflictSourceNoteGuid(generateRandomString());
    value.setNoteTitleQuality(generateRandomInt32());

    NoteAttributesBuilder builder;
    builder.setSubjectDate(value.subjectDate());
    builder.setLatitude(value.latitude());
    builder.setLongitude(value.longitude());
    builder.setAltitude(value.altitude());
    builder.setAuthor(value.author());
    builder.setSource(value.source());
    builder.setSourceURL(value.sourceURL());
    builder.setSourceApplication(value.sourceApplication());
    builder.setShareDate(value.shareDate());
    builder.setReminderOrder(value.reminderOrder());
    builder.setReminderDoneTime(value.reminderDoneTime());
    builder.setReminderTime(value.reminderTime());
    builder.setPlaceName(value.placeName());
    builder.setContentClass(value.contentClass());
    builder.setApplicationData(value.applicationData());
    builder.setLastEditedBy(value.lastEditedBy());
    builder.setClassifications(value.classifications());
    builder.setCreatorId(value.creatorId());
    builder.setLastEditorId(value.lastEditorId());
    builder.setSharedWithBusiness(value.sharedWithBusiness());
    builder.setConflictSourceNoteGuid(value.conflictSourceNoteGuid());
    builder.setNoteTitleQuality(value.noteTitleQuality());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSharedNote()
{
    SharedNote value;
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setNoteGuid(generateRandomString());
    value.setSharerUserID(generateRandomInt32());
    value.setRecipientIdentity(generateRandomIdentity());
    value.setPrivilege(SharedNotePrivilegeLevel::READ_NOTE);
    value.setServiceCreated(generateRandomInt64());
    value.setServiceUpdated(generateRandomInt64());
    value.setServiceAssigned(generateRandomInt64());

    SharedNoteBuilder builder;
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setNoteGuid(value.noteGuid());
    builder.setSharerUserID(value.sharerUserID());
    builder.setRecipientIdentity(value.recipientIdentity());
    builder.setPrivilege(value.privilege());
    builder.setServiceCreated(value.serviceCreated());
    builder.setServiceUpdated(value.serviceUpdated());
    builder.setServiceAssigned(value.serviceAssigned());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteRestrictions()
{
    NoteRestrictions value;
    value.setNoUpdateTitle(generateRandomBool());
    value.setNoUpdateContent(generateRandomBool());
    value.setNoEmail(generateRandomBool());
    value.setNoShare(generateRandomBool());
    value.setNoSharePublicly(generateRandomBool());

    NoteRestrictionsBuilder builder;
    builder.setNoUpdateTitle(value.noUpdateTitle());
    builder.setNoUpdateContent(value.noUpdateContent());
    builder.setNoEmail(value.noEmail());
    builder.setNoShare(value.noShare());
    builder.setNoSharePublicly(value.noSharePublicly());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNoteLimits()
{
    NoteLimits value;
    value.setNoteResourceCountMax(generateRandomInt32());
    value.setUploadLimit(generateRandomInt64());
    value.setResourceSizeMax(generateRandomInt64());
    value.setNoteSizeMax(generateRandomInt64());
    value.setUploaded(generateRandomInt64());

    NoteLimitsBuilder builder;
    builder.setNoteResourceCountMax(value.noteResourceCountMax());
    builder.setUploadLimit(value.uploadLimit());
    builder.setResourceSizeMax(value.resourceSizeMax());
    builder.setNoteSizeMax(value.noteSizeMax());
    builder.setUploaded(value.uploaded());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNote()
{
    Note value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setNotebookLocalId(generateRandomString());
    value.setTagLocalIds(QList<QString>{} << generateRandomString());
    value.setThumbnailData(generateRandomString().toUtf8());
    value.setGuid(generateRandomString());
    value.setTitle(generateRandomString());
    value.setContent(generateRandomString());
    value.setContentHash(generateRandomString().toUtf8());
    value.setContentLength(generateRandomInt32());
    value.setCreated(generateRandomInt64());
    value.setUpdated(generateRandomInt64());
    value.setDeleted(generateRandomInt64());
    value.setActive(generateRandomBool());
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setNotebookGuid(generateRandomString());
    value.setTagGuids(QList<QString>{} << generateRandomString());
    value.setResources(QList<Resource>{} << generateRandomResource());
    value.setAttributes(generateRandomNoteAttributes());
    value.setTagNames(QList<QString>{} << generateRandomString());
    value.setSharedNotes(QList<SharedNote>{} << generateRandomSharedNote());
    value.setRestrictions(generateRandomNoteRestrictions());
    value.setLimits(generateRandomNoteLimits());

    NoteBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setNotebookLocalId(value.notebookLocalId());
    builder.setTagLocalIds(value.tagLocalIds());
    builder.setThumbnailData(value.thumbnailData());
    builder.setGuid(value.guid());
    builder.setTitle(value.title());
    builder.setContent(value.content());
    builder.setContentHash(value.contentHash());
    builder.setContentLength(value.contentLength());
    builder.setCreated(value.created());
    builder.setUpdated(value.updated());
    builder.setDeleted(value.deleted());
    builder.setActive(value.active());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setNotebookGuid(value.notebookGuid());
    builder.setTagGuids(value.tagGuids());
    builder.setResources(value.resources());
    builder.setAttributes(value.attributes());
    builder.setTagNames(value.tagNames());
    builder.setSharedNotes(value.sharedNotes());
    builder.setRestrictions(value.restrictions());
    builder.setLimits(value.limits());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildPublishing()
{
    Publishing value;
    value.setUri(generateRandomString());
    value.setOrder(NoteSortOrder::CREATED);
    value.setAscending(generateRandomBool());
    value.setPublicDescription(generateRandomString());

    PublishingBuilder builder;
    builder.setUri(value.uri());
    builder.setOrder(value.order());
    builder.setAscending(value.ascending());
    builder.setPublicDescription(value.publicDescription());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBusinessNotebook()
{
    BusinessNotebook value;
    value.setNotebookDescription(generateRandomString());
    value.setPrivilege(SharedNotebookPrivilegeLevel::READ_NOTEBOOK);
    value.setRecommended(generateRandomBool());

    BusinessNotebookBuilder builder;
    builder.setNotebookDescription(value.notebookDescription());
    builder.setPrivilege(value.privilege());
    builder.setRecommended(value.recommended());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSavedSearchScope()
{
    SavedSearchScope value;
    value.setIncludeAccount(generateRandomBool());
    value.setIncludePersonalLinkedNotebooks(generateRandomBool());
    value.setIncludeBusinessLinkedNotebooks(generateRandomBool());

    SavedSearchScopeBuilder builder;
    builder.setIncludeAccount(value.includeAccount());
    builder.setIncludePersonalLinkedNotebooks(value.includePersonalLinkedNotebooks());
    builder.setIncludeBusinessLinkedNotebooks(value.includeBusinessLinkedNotebooks());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSavedSearch()
{
    SavedSearch value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setGuid(generateRandomString());
    value.setName(generateRandomString());
    value.setQuery(generateRandomString());
    value.setFormat(QueryFormat::USER);
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setScope(generateRandomSavedSearchScope());

    SavedSearchBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setGuid(value.guid());
    builder.setName(value.name());
    builder.setQuery(value.query());
    builder.setFormat(value.format());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setScope(value.scope());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSharedNotebookRecipientSettings()
{
    SharedNotebookRecipientSettings value;
    value.setReminderNotifyEmail(generateRandomBool());
    value.setReminderNotifyInApp(generateRandomBool());

    SharedNotebookRecipientSettingsBuilder builder;
    builder.setReminderNotifyEmail(value.reminderNotifyEmail());
    builder.setReminderNotifyInApp(value.reminderNotifyInApp());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotebookRecipientSettings()
{
    NotebookRecipientSettings value;
    value.setReminderNotifyEmail(generateRandomBool());
    value.setReminderNotifyInApp(generateRandomBool());
    value.setInMyList(generateRandomBool());
    value.setStack(generateRandomString());
    value.setRecipientStatus(RecipientStatus::NOT_IN_MY_LIST);

    NotebookRecipientSettingsBuilder builder;
    builder.setReminderNotifyEmail(value.reminderNotifyEmail());
    builder.setReminderNotifyInApp(value.reminderNotifyInApp());
    builder.setInMyList(value.inMyList());
    builder.setStack(value.stack());
    builder.setRecipientStatus(value.recipientStatus());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildSharedNotebook()
{
    SharedNotebook value;
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setId(generateRandomInt64());
    value.setUserId(generateRandomInt32());
    value.setNotebookGuid(generateRandomString());
    value.setEmail(generateRandomString());
    value.setRecipientIdentityId(generateRandomInt64());
    value.setNotebookModifiable(generateRandomBool());
    value.setServiceCreated(generateRandomInt64());
    value.setServiceUpdated(generateRandomInt64());
    value.setGlobalId(generateRandomString());
    value.setUsername(generateRandomString());
    value.setPrivilege(SharedNotebookPrivilegeLevel::READ_NOTEBOOK);
    value.setRecipientSettings(generateRandomSharedNotebookRecipientSettings());
    value.setSharerUserId(generateRandomInt32());
    value.setRecipientUsername(generateRandomString());
    value.setRecipientUserId(generateRandomInt32());
    value.setServiceAssigned(generateRandomInt64());

    SharedNotebookBuilder builder;
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setId(value.id());
    builder.setUserId(value.userId());
    builder.setNotebookGuid(value.notebookGuid());
    builder.setEmail(value.email());
    builder.setRecipientIdentityId(value.recipientIdentityId());
    builder.setNotebookModifiable(value.notebookModifiable());
    builder.setServiceCreated(value.serviceCreated());
    builder.setServiceUpdated(value.serviceUpdated());
    builder.setGlobalId(value.globalId());
    builder.setUsername(value.username());
    builder.setPrivilege(value.privilege());
    builder.setRecipientSettings(value.recipientSettings());
    builder.setSharerUserId(value.sharerUserId());
    builder.setRecipientUsername(value.recipientUsername());
    builder.setRecipientUserId(value.recipientUserId());
    builder.setServiceAssigned(value.serviceAssigned());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildCanMoveToContainerRestrictions()
{
    CanMoveToContainerRestrictions value;
    value.setCanMoveToContainer(CanMoveToContainerStatus::CAN_BE_MOVED);

    CanMoveToContainerRestrictionsBuilder builder;
    builder.setCanMoveToContainer(value.canMoveToContainer());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotebookRestrictions()
{
    NotebookRestrictions value;
    value.setNoReadNotes(generateRandomBool());
    value.setNoCreateNotes(generateRandomBool());
    value.setNoUpdateNotes(generateRandomBool());
    value.setNoExpungeNotes(generateRandomBool());
    value.setNoShareNotes(generateRandomBool());
    value.setNoEmailNotes(generateRandomBool());
    value.setNoSendMessageToRecipients(generateRandomBool());
    value.setNoUpdateNotebook(generateRandomBool());
    value.setNoExpungeNotebook(generateRandomBool());
    value.setNoSetDefaultNotebook(generateRandomBool());
    value.setNoSetNotebookStack(generateRandomBool());
    value.setNoPublishToPublic(generateRandomBool());
    value.setNoPublishToBusinessLibrary(generateRandomBool());
    value.setNoCreateTags(generateRandomBool());
    value.setNoUpdateTags(generateRandomBool());
    value.setNoExpungeTags(generateRandomBool());
    value.setNoSetParentTag(generateRandomBool());
    value.setNoCreateSharedNotebooks(generateRandomBool());
    value.setUpdateWhichSharedNotebookRestrictions(SharedNotebookInstanceRestrictions::ASSIGNED);
    value.setExpungeWhichSharedNotebookRestrictions(SharedNotebookInstanceRestrictions::ASSIGNED);
    value.setNoShareNotesWithBusiness(generateRandomBool());
    value.setNoRenameNotebook(generateRandomBool());
    value.setNoSetInMyList(generateRandomBool());
    value.setNoChangeContact(generateRandomBool());
    value.setCanMoveToContainerRestrictions(generateRandomCanMoveToContainerRestrictions());
    value.setNoSetReminderNotifyEmail(generateRandomBool());
    value.setNoSetReminderNotifyInApp(generateRandomBool());
    value.setNoSetRecipientSettingsStack(generateRandomBool());
    value.setNoCanMoveNote(generateRandomBool());

    NotebookRestrictionsBuilder builder;
    builder.setNoReadNotes(value.noReadNotes());
    builder.setNoCreateNotes(value.noCreateNotes());
    builder.setNoUpdateNotes(value.noUpdateNotes());
    builder.setNoExpungeNotes(value.noExpungeNotes());
    builder.setNoShareNotes(value.noShareNotes());
    builder.setNoEmailNotes(value.noEmailNotes());
    builder.setNoSendMessageToRecipients(value.noSendMessageToRecipients());
    builder.setNoUpdateNotebook(value.noUpdateNotebook());
    builder.setNoExpungeNotebook(value.noExpungeNotebook());
    builder.setNoSetDefaultNotebook(value.noSetDefaultNotebook());
    builder.setNoSetNotebookStack(value.noSetNotebookStack());
    builder.setNoPublishToPublic(value.noPublishToPublic());
    builder.setNoPublishToBusinessLibrary(value.noPublishToBusinessLibrary());
    builder.setNoCreateTags(value.noCreateTags());
    builder.setNoUpdateTags(value.noUpdateTags());
    builder.setNoExpungeTags(value.noExpungeTags());
    builder.setNoSetParentTag(value.noSetParentTag());
    builder.setNoCreateSharedNotebooks(value.noCreateSharedNotebooks());
    builder.setUpdateWhichSharedNotebookRestrictions(value.updateWhichSharedNotebookRestrictions());
    builder.setExpungeWhichSharedNotebookRestrictions(value.expungeWhichSharedNotebookRestrictions());
    builder.setNoShareNotesWithBusiness(value.noShareNotesWithBusiness());
    builder.setNoRenameNotebook(value.noRenameNotebook());
    builder.setNoSetInMyList(value.noSetInMyList());
    builder.setNoChangeContact(value.noChangeContact());
    builder.setCanMoveToContainerRestrictions(value.canMoveToContainerRestrictions());
    builder.setNoSetReminderNotifyEmail(value.noSetReminderNotifyEmail());
    builder.setNoSetReminderNotifyInApp(value.noSetReminderNotifyInApp());
    builder.setNoSetRecipientSettingsStack(value.noSetRecipientSettingsStack());
    builder.setNoCanMoveNote(value.noCanMoveNote());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotebook()
{
    Notebook value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setLinkedNotebookGuid(generateRandomString());
    value.setGuid(generateRandomString());
    value.setName(generateRandomString());
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setDefaultNotebook(generateRandomBool());
    value.setServiceCreated(generateRandomInt64());
    value.setServiceUpdated(generateRandomInt64());
    value.setPublishing(generateRandomPublishing());
    value.setPublished(generateRandomBool());
    value.setStack(generateRandomString());
    value.setSharedNotebookIds(QList<qint64>{} << generateRandomInt64());
    value.setSharedNotebooks(QList<SharedNotebook>{} << generateRandomSharedNotebook());
    value.setBusinessNotebook(generateRandomBusinessNotebook());
    value.setContact(generateRandomUser());
    value.setRestrictions(generateRandomNotebookRestrictions());
    value.setRecipientSettings(generateRandomNotebookRecipientSettings());

    NotebookBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setLinkedNotebookGuid(value.linkedNotebookGuid());
    builder.setGuid(value.guid());
    builder.setName(value.name());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setDefaultNotebook(value.defaultNotebook());
    builder.setServiceCreated(value.serviceCreated());
    builder.setServiceUpdated(value.serviceUpdated());
    builder.setPublishing(value.publishing());
    builder.setPublished(value.published());
    builder.setStack(value.stack());
    builder.setSharedNotebookIds(value.sharedNotebookIds());
    builder.setSharedNotebooks(value.sharedNotebooks());
    builder.setBusinessNotebook(value.businessNotebook());
    builder.setContact(value.contact());
    builder.setRestrictions(value.restrictions());
    builder.setRecipientSettings(value.recipientSettings());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildLinkedNotebook()
{
    LinkedNotebook value;
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setShareName(generateRandomString());
    value.setUsername(generateRandomString());
    value.setShardId(generateRandomString());
    value.setSharedNotebookGlobalId(generateRandomString());
    value.setUri(generateRandomString());
    value.setGuid(generateRandomString());
    value.setUpdateSequenceNum(generateRandomInt32());
    value.setNoteStoreUrl(generateRandomString());
    value.setWebApiUrlPrefix(generateRandomString());
    value.setStack(generateRandomString());
    value.setBusinessId(generateRandomInt32());

    LinkedNotebookBuilder builder;
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setShareName(value.shareName());
    builder.setUsername(value.username());
    builder.setShardId(value.shardId());
    builder.setSharedNotebookGlobalId(value.sharedNotebookGlobalId());
    builder.setUri(value.uri());
    builder.setGuid(value.guid());
    builder.setUpdateSequenceNum(value.updateSequenceNum());
    builder.setNoteStoreUrl(value.noteStoreUrl());
    builder.setWebApiUrlPrefix(value.webApiUrlPrefix());
    builder.setStack(value.stack());
    builder.setBusinessId(value.businessId());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildNotebookDescriptor()
{
    NotebookDescriptor value;
    value.setLocalId(generateRandomString());
    value.setLocallyModified(generateRandomBool());
    value.setLocalOnly(generateRandomBool());
    value.setLocallyFavorited(generateRandomBool());

    QHash<QString, QVariant> localData;
    localData[generateRandomString()] = generateRandomString();
    value.setLocalData(std::move(localData));

    value.setGuid(generateRandomString());
    value.setNotebookDisplayName(generateRandomString());
    value.setContactName(generateRandomString());
    value.setHasSharedNotebook(generateRandomBool());
    value.setJoinedUserCount(generateRandomInt32());

    NotebookDescriptorBuilder builder;
    builder.setLocalId(value.localId());
    builder.setLocallyModified(value.isLocallyModified());
    builder.setLocalOnly(value.isLocalOnly());
    builder.setLocallyFavorited(value.isLocallyFavorited());
    builder.setLocalData(value.localData());
    builder.setGuid(value.guid());
    builder.setNotebookDisplayName(value.notebookDisplayName());
    builder.setContactName(value.contactName());
    builder.setHasSharedNotebook(value.hasSharedNotebook());
    builder.setJoinedUserCount(value.joinedUserCount());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUserProfile()
{
    UserProfile value;
    value.setId(generateRandomInt32());
    value.setName(generateRandomString());
    value.setEmail(generateRandomString());
    value.setUsername(generateRandomString());
    value.setAttributes(generateRandomBusinessUserAttributes());
    value.setJoined(generateRandomInt64());
    value.setPhotoLastUpdated(generateRandomInt64());
    value.setPhotoUrl(generateRandomString());
    value.setRole(BusinessUserRole::ADMIN);
    value.setStatus(BusinessUserStatus::ACTIVE);

    UserProfileBuilder builder;
    builder.setId(value.id());
    builder.setName(value.name());
    builder.setEmail(value.email());
    builder.setUsername(value.username());
    builder.setAttributes(value.attributes());
    builder.setJoined(value.joined());
    builder.setPhotoLastUpdated(value.photoLastUpdated());
    builder.setPhotoUrl(value.photoUrl());
    builder.setRole(value.role());
    builder.setStatus(value.status());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildRelatedContentImage()
{
    RelatedContentImage value;
    value.setUrl(generateRandomString());
    value.setWidth(generateRandomInt32());
    value.setHeight(generateRandomInt32());
    value.setPixelRatio(generateRandomDouble());
    value.setFileSize(generateRandomInt32());

    RelatedContentImageBuilder builder;
    builder.setUrl(value.url());
    builder.setWidth(value.width());
    builder.setHeight(value.height());
    builder.setPixelRatio(value.pixelRatio());
    builder.setFileSize(value.fileSize());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildRelatedContent()
{
    RelatedContent value;
    value.setContentId(generateRandomString());
    value.setTitle(generateRandomString());
    value.setUrl(generateRandomString());
    value.setSourceId(generateRandomString());
    value.setSourceUrl(generateRandomString());
    value.setSourceFaviconUrl(generateRandomString());
    value.setSourceName(generateRandomString());
    value.setDate(generateRandomInt64());
    value.setTeaser(generateRandomString());
    value.setThumbnails(QList<RelatedContentImage>{} << generateRandomRelatedContentImage());
    value.setContentType(RelatedContentType::NEWS_ARTICLE);
    value.setAccessType(RelatedContentAccess::NOT_ACCESSIBLE);
    value.setVisibleUrl(generateRandomString());
    value.setClipUrl(generateRandomString());
    value.setContact(generateRandomContact());
    value.setAuthors(QList<QString>{} << generateRandomString());

    RelatedContentBuilder builder;
    builder.setContentId(value.contentId());
    builder.setTitle(value.title());
    builder.setUrl(value.url());
    builder.setSourceId(value.sourceId());
    builder.setSourceUrl(value.sourceUrl());
    builder.setSourceFaviconUrl(value.sourceFaviconUrl());
    builder.setSourceName(value.sourceName());
    builder.setDate(value.date());
    builder.setTeaser(value.teaser());
    builder.setThumbnails(value.thumbnails());
    builder.setContentType(value.contentType());
    builder.setAccessType(value.accessType());
    builder.setVisibleUrl(value.visibleUrl());
    builder.setClipUrl(value.clipUrl());
    builder.setContact(value.contact());
    builder.setAuthors(value.authors());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBusinessInvitation()
{
    BusinessInvitation value;
    value.setBusinessId(generateRandomInt32());
    value.setEmail(generateRandomString());
    value.setRole(BusinessUserRole::ADMIN);
    value.setStatus(BusinessInvitationStatus::APPROVED);
    value.setRequesterId(generateRandomInt32());
    value.setFromWorkChat(generateRandomBool());
    value.setCreated(generateRandomInt64());
    value.setMostRecentReminder(generateRandomInt64());

    BusinessInvitationBuilder builder;
    builder.setBusinessId(value.businessId());
    builder.setEmail(value.email());
    builder.setRole(value.role());
    builder.setStatus(value.status());
    builder.setRequesterId(value.requesterId());
    builder.setFromWorkChat(value.fromWorkChat());
    builder.setCreated(value.created());
    builder.setMostRecentReminder(value.mostRecentReminder());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUserIdentity()
{
    UserIdentity value;
    value.setType(UserIdentityType::EVERNOTE_USERID);
    value.setStringIdentifier(generateRandomString());
    value.setLongIdentifier(generateRandomInt64());

    UserIdentityBuilder builder;
    builder.setType(value.type());
    builder.setStringIdentifier(value.stringIdentifier());
    builder.setLongIdentifier(value.longIdentifier());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildPublicUserInfo()
{
    PublicUserInfo value;
    value.setUserId(generateRandomInt32());
    value.setServiceLevel(ServiceLevel::BASIC);
    value.setUsername(generateRandomString());
    value.setNoteStoreUrl(generateRandomString());
    value.setWebApiUrlPrefix(generateRandomString());

    PublicUserInfoBuilder builder;
    builder.setUserId(value.userId());
    builder.setServiceLevel(value.serviceLevel());
    builder.setUsername(value.username());
    builder.setNoteStoreUrl(value.noteStoreUrl());
    builder.setWebApiUrlPrefix(value.webApiUrlPrefix());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildUserUrls()
{
    UserUrls value;
    value.setNoteStoreUrl(generateRandomString());
    value.setWebApiUrlPrefix(generateRandomString());
    value.setUserStoreUrl(generateRandomString());
    value.setUtilityUrl(generateRandomString());
    value.setMessageStoreUrl(generateRandomString());
    value.setUserWebSocketUrl(generateRandomString());

    UserUrlsBuilder builder;
    builder.setNoteStoreUrl(value.noteStoreUrl());
    builder.setWebApiUrlPrefix(value.webApiUrlPrefix());
    builder.setUserStoreUrl(value.userStoreUrl());
    builder.setUtilityUrl(value.utilityUrl());
    builder.setMessageStoreUrl(value.messageStoreUrl());
    builder.setUserWebSocketUrl(value.userWebSocketUrl());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildAuthenticationResult()
{
    AuthenticationResult value;
    value.setCurrentTime(generateRandomInt64());
    value.setAuthenticationToken(generateRandomString());
    value.setExpiration(generateRandomInt64());
    value.setUser(generateRandomUser());
    value.setPublicUserInfo(generateRandomPublicUserInfo());
    value.setNoteStoreUrl(generateRandomString());
    value.setWebApiUrlPrefix(generateRandomString());
    value.setSecondFactorRequired(generateRandomBool());
    value.setSecondFactorDeliveryHint(generateRandomString());
    value.setUrls(generateRandomUserUrls());

    AuthenticationResultBuilder builder;
    builder.setCurrentTime(value.currentTime());
    builder.setAuthenticationToken(value.authenticationToken());
    builder.setExpiration(value.expiration());
    builder.setUser(value.user());
    builder.setPublicUserInfo(value.publicUserInfo());
    builder.setNoteStoreUrl(value.noteStoreUrl());
    builder.setWebApiUrlPrefix(value.webApiUrlPrefix());
    builder.setSecondFactorRequired(value.secondFactorRequired());
    builder.setSecondFactorDeliveryHint(value.secondFactorDeliveryHint());
    builder.setUrls(value.urls());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBootstrapSettings()
{
    BootstrapSettings value;
    value.setServiceHost(generateRandomString());
    value.setMarketingUrl(generateRandomString());
    value.setSupportUrl(generateRandomString());
    value.setAccountEmailDomain(generateRandomString());
    value.setEnableFacebookSharing(generateRandomBool());
    value.setEnableGiftSubscriptions(generateRandomBool());
    value.setEnableSupportTickets(generateRandomBool());
    value.setEnableSharedNotebooks(generateRandomBool());
    value.setEnableSingleNoteSharing(generateRandomBool());
    value.setEnableSponsoredAccounts(generateRandomBool());
    value.setEnableTwitterSharing(generateRandomBool());
    value.setEnableLinkedInSharing(generateRandomBool());
    value.setEnablePublicNotebooks(generateRandomBool());
    value.setEnableGoogle(generateRandomBool());

    BootstrapSettingsBuilder builder;
    builder.setServiceHost(value.serviceHost());
    builder.setMarketingUrl(value.marketingUrl());
    builder.setSupportUrl(value.supportUrl());
    builder.setAccountEmailDomain(value.accountEmailDomain());
    builder.setEnableFacebookSharing(value.enableFacebookSharing());
    builder.setEnableGiftSubscriptions(value.enableGiftSubscriptions());
    builder.setEnableSupportTickets(value.enableSupportTickets());
    builder.setEnableSharedNotebooks(value.enableSharedNotebooks());
    builder.setEnableSingleNoteSharing(value.enableSingleNoteSharing());
    builder.setEnableSponsoredAccounts(value.enableSponsoredAccounts());
    builder.setEnableTwitterSharing(value.enableTwitterSharing());
    builder.setEnableLinkedInSharing(value.enableLinkedInSharing());
    builder.setEnablePublicNotebooks(value.enablePublicNotebooks());
    builder.setEnableGoogle(value.enableGoogle());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBootstrapProfile()
{
    BootstrapProfile value;
    value.setName(generateRandomString());
    value.setSettings(generateRandomBootstrapSettings());

    BootstrapProfileBuilder builder;
    builder.setName(value.name());
    builder.setSettings(value.settings());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildBootstrapInfo()
{
    BootstrapInfo value;
    value.setProfiles(QList<BootstrapProfile>{} << generateRandomBootstrapProfile());

    BootstrapInfoBuilder builder;
    builder.setProfiles(value.profiles());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildEDAMUserException()
{
    EDAMUserException value;
    value.setErrorCode(EDAMErrorCode::UNKNOWN);
    value.setParameter(generateRandomString());

    EDAMUserExceptionBuilder builder;
    builder.setErrorCode(value.errorCode());
    builder.setParameter(value.parameter());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildEDAMSystemException()
{
    EDAMSystemException value;
    value.setErrorCode(EDAMErrorCode::UNKNOWN);
    value.setMessage(generateRandomString());
    value.setRateLimitDuration(generateRandomInt32());

    EDAMSystemExceptionBuilder builder;
    builder.setErrorCode(value.errorCode());
    builder.setMessage(value.message());
    builder.setRateLimitDuration(value.rateLimitDuration());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildEDAMNotFoundException()
{
    EDAMNotFoundException value;
    value.setIdentifier(generateRandomString());
    value.setKey(generateRandomString());

    EDAMNotFoundExceptionBuilder builder;
    builder.setIdentifier(value.identifier());
    builder.setKey(value.key());

    auto built = builder.build();
    QVERIFY(built == value);
}

void TypeBuildersTester::shouldBuildEDAMInvalidContactsException()
{
    EDAMInvalidContactsException value;
    value.setContacts(QList<Contact>{} << generateRandomContact());
    value.setParameter(generateRandomString());
    value.setReasons(QList<EDAMInvalidContactReason>{} << EDAMInvalidContactReason::BAD_ADDRESS);

    EDAMInvalidContactsExceptionBuilder builder;
    builder.setContacts(value.contacts());
    builder.setParameter(value.parameter());
    builder.setReasons(value.reasons());

    auto built = builder.build();
    QVERIFY(built == value);
}

} // namespace qevercloud
