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

#include "RandomDataGenerators.h"
#include "../../src/Impl.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QEventLoop>
#include <QGlobalStatic>
#include <QObject>
#include <algorithm>
#include <cstdlib>
#include <limits>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

Q_GLOBAL_STATIC_WITH_ARGS(
    QString,
    randomStringAvailableCharacters,
    (QString::fromUtf8(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")))

template <typename T>
T generateRandomIntType()
{
    T min = std::numeric_limits<T>::min() / 4;
    T max = std::numeric_limits<T>::max() / 4;
    return min + (rand() % static_cast<T>(max - min + 1));
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

QString generateRandomString(int len)
{
    if (len <= 0) {
        return {};
    }

    QString res;
    res.reserve(len);
    for(int i = 0; i < len; ++i) {
        int index = rand() % randomStringAvailableCharacters->length();
        res.append(randomStringAvailableCharacters->at(index));
    }

    return res;
}

qint8 generateRandomInt8()
{
    return generateRandomIntType<qint8>();
}

qint16 generateRandomInt16()
{
    return generateRandomIntType<qint16>();
}

qint32 generateRandomInt32()
{
    return generateRandomIntType<qint32>();
}

qint64 generateRandomInt64()
{
    return generateRandomIntType<qint64>();
}

quint8 generateRandomUint8()
{
    return generateRandomIntType<quint8>();
}

quint16 generateRandomUint16()
{
    return generateRandomIntType<quint16>();
}

quint32 generateRandomUint32()
{
    return generateRandomIntType<quint32>();
}

quint64 generateRandomUint64()
{
    return generateRandomIntType<quint64>();
}

double generateRandomDouble()
{
    double minval = std::numeric_limits<double>::min();
    double maxval = std::numeric_limits<double>::max();
    double f = (double)rand() / RAND_MAX;
    return minval + f * (maxval - minval);
}

bool generateRandomBool()
{
    return generateRandomInt8() >= 0;
}

////////////////////////////////////////////////////////////////////////////////

SyncState generateRandomSyncState()
{
    SyncState result;
    result.setCurrentTime(generateRandomInt64());
    result.setFullSyncBefore(generateRandomInt64());
    result.setUpdateCount(generateRandomInt32());
    result.setUploaded(generateRandomInt64());
    result.setUserLastUpdated(generateRandomInt64());
    result.setUserMaxMessageEventId(generateRandomInt64());
    return result;
}

SyncChunk generateRandomSyncChunk()
{
    SyncChunk result;
    result.setCurrentTime(generateRandomInt64());
    result.setChunkHighUSN(generateRandomInt32());
    result.setUpdateCount(generateRandomInt32());
    result.setNotes(QList<Note>());
    result.mutableNotes()->push_back(generateRandomNote());
    result.mutableNotes()->push_back(generateRandomNote());
    result.mutableNotes()->push_back(generateRandomNote());
    result.setNotebooks(QList<Notebook>());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.setTags(QList<Tag>());
    result.mutableTags()->push_back(generateRandomTag());
    result.mutableTags()->push_back(generateRandomTag());
    result.mutableTags()->push_back(generateRandomTag());
    result.setSearches(QList<SavedSearch>());
    result.mutableSearches()->push_back(generateRandomSavedSearch());
    result.mutableSearches()->push_back(generateRandomSavedSearch());
    result.mutableSearches()->push_back(generateRandomSavedSearch());
    result.setResources(QList<Resource>());
    result.mutableResources()->push_back(generateRandomResource());
    result.mutableResources()->push_back(generateRandomResource());
    result.mutableResources()->push_back(generateRandomResource());
    result.setExpungedNotes(QList<Guid>());
    result.mutableExpungedNotes()->push_back(generateRandomString());
    result.mutableExpungedNotes()->push_back(generateRandomString());
    result.mutableExpungedNotes()->push_back(generateRandomString());
    result.setExpungedNotebooks(QList<Guid>());
    result.mutableExpungedNotebooks()->push_back(generateRandomString());
    result.mutableExpungedNotebooks()->push_back(generateRandomString());
    result.mutableExpungedNotebooks()->push_back(generateRandomString());
    result.setExpungedTags(QList<Guid>());
    result.mutableExpungedTags()->push_back(generateRandomString());
    result.mutableExpungedTags()->push_back(generateRandomString());
    result.mutableExpungedTags()->push_back(generateRandomString());
    result.setExpungedSearches(QList<Guid>());
    result.mutableExpungedSearches()->push_back(generateRandomString());
    result.mutableExpungedSearches()->push_back(generateRandomString());
    result.mutableExpungedSearches()->push_back(generateRandomString());
    result.setLinkedNotebooks(QList<LinkedNotebook>());
    result.mutableLinkedNotebooks()->push_back(generateRandomLinkedNotebook());
    result.mutableLinkedNotebooks()->push_back(generateRandomLinkedNotebook());
    result.mutableLinkedNotebooks()->push_back(generateRandomLinkedNotebook());
    result.setExpungedLinkedNotebooks(QList<Guid>());
    result.mutableExpungedLinkedNotebooks()->push_back(generateRandomString());
    result.mutableExpungedLinkedNotebooks()->push_back(generateRandomString());
    result.mutableExpungedLinkedNotebooks()->push_back(generateRandomString());
    return result;
}

SyncChunkFilter generateRandomSyncChunkFilter()
{
    SyncChunkFilter result;
    result.setIncludeNotes(generateRandomBool());
    result.setIncludeNoteResources(generateRandomBool());
    result.setIncludeNoteAttributes(generateRandomBool());
    result.setIncludeNotebooks(generateRandomBool());
    result.setIncludeTags(generateRandomBool());
    result.setIncludeSearches(generateRandomBool());
    result.setIncludeResources(generateRandomBool());
    result.setIncludeLinkedNotebooks(generateRandomBool());
    result.setIncludeExpunged(generateRandomBool());
    result.setIncludeNoteApplicationDataFullMap(generateRandomBool());
    result.setIncludeResourceApplicationDataFullMap(generateRandomBool());
    result.setIncludeNoteResourceApplicationDataFullMap(generateRandomBool());
    result.setIncludeSharedNotes(generateRandomBool());
    result.setOmitSharedNotebooks(generateRandomBool());
    result.setRequireNoteContentClass(generateRandomString());
    result.setNotebookGuids(QSet<QString>());
    result.mutableNotebookGuids()->insert(generateRandomString());
    result.mutableNotebookGuids()->insert(generateRandomString());
    result.mutableNotebookGuids()->insert(generateRandomString());
    return result;
}

NoteFilter generateRandomNoteFilter()
{
    NoteFilter result;
    result.setOrder(generateRandomInt32());
    result.setAscending(generateRandomBool());
    result.setWords(generateRandomString());
    result.setNotebookGuid(generateRandomString());
    result.setTagGuids(QList<Guid>());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.setTimeZone(generateRandomString());
    result.setInactive(generateRandomBool());
    result.setEmphasized(generateRandomString());
    result.setIncludeAllReadableNotebooks(generateRandomBool());
    result.setIncludeAllReadableWorkspaces(generateRandomBool());
    result.setContext(generateRandomString());
    result.setRawWords(generateRandomString());
    result.setSearchContextBytes(generateRandomString().toUtf8());
    return result;
}

NoteList generateRandomNoteList()
{
    NoteList result;
    result.setStartIndex(generateRandomInt32());
    result.setTotalNotes(generateRandomInt32());
    result.mutableNotes().push_back(generateRandomNote());
    result.mutableNotes().push_back(generateRandomNote());
    result.mutableNotes().push_back(generateRandomNote());
    result.setStoppedWords(QList<QString>());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.setSearchedWords(QList<QString>());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.setUpdateCount(generateRandomInt32());
    result.setSearchContextBytes(generateRandomString().toUtf8());
    result.setDebugInfo(generateRandomString());
    return result;
}

NoteMetadata generateRandomNoteMetadata()
{
    NoteMetadata result;
    result.setGuid(generateRandomString());
    result.setTitle(generateRandomString());
    result.setContentLength(generateRandomInt32());
    result.setCreated(generateRandomInt64());
    result.setUpdated(generateRandomInt64());
    result.setDeleted(generateRandomInt64());
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setNotebookGuid(generateRandomString());
    result.setTagGuids(QList<Guid>());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.setAttributes(generateRandomNoteAttributes());
    result.setLargestResourceMime(generateRandomString());
    result.setLargestResourceSize(generateRandomInt32());
    return result;
}

NotesMetadataList generateRandomNotesMetadataList()
{
    NotesMetadataList result;
    result.setStartIndex(generateRandomInt32());
    result.setTotalNotes(generateRandomInt32());
    result.mutableNotes().push_back(generateRandomNoteMetadata());
    result.mutableNotes().push_back(generateRandomNoteMetadata());
    result.mutableNotes().push_back(generateRandomNoteMetadata());
    result.setStoppedWords(QList<QString>());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.mutableStoppedWords()->push_back(generateRandomString());
    result.setSearchedWords(QList<QString>());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.mutableSearchedWords()->push_back(generateRandomString());
    result.setUpdateCount(generateRandomInt32());
    result.setSearchContextBytes(generateRandomString().toUtf8());
    result.setDebugInfo(generateRandomString());
    return result;
}

NotesMetadataResultSpec generateRandomNotesMetadataResultSpec()
{
    NotesMetadataResultSpec result;
    result.setIncludeTitle(generateRandomBool());
    result.setIncludeContentLength(generateRandomBool());
    result.setIncludeCreated(generateRandomBool());
    result.setIncludeUpdated(generateRandomBool());
    result.setIncludeDeleted(generateRandomBool());
    result.setIncludeUpdateSequenceNum(generateRandomBool());
    result.setIncludeNotebookGuid(generateRandomBool());
    result.setIncludeTagGuids(generateRandomBool());
    result.setIncludeAttributes(generateRandomBool());
    result.setIncludeLargestResourceMime(generateRandomBool());
    result.setIncludeLargestResourceSize(generateRandomBool());
    return result;
}

NoteCollectionCounts generateRandomNoteCollectionCounts()
{
    NoteCollectionCounts result;
    result.setNotebookCounts(QMap<Guid, qint32>());
    result.mutableNotebookCounts()->insert(generateRandomString(), generateRandomInt32());
    result.mutableNotebookCounts()->insert(generateRandomString(), generateRandomInt32());
    result.mutableNotebookCounts()->insert(generateRandomString(), generateRandomInt32());
    result.setTagCounts(QMap<Guid, qint32>());
    result.mutableTagCounts()->insert(generateRandomString(), generateRandomInt32());
    result.mutableTagCounts()->insert(generateRandomString(), generateRandomInt32());
    result.mutableTagCounts()->insert(generateRandomString(), generateRandomInt32());
    result.setTrashCount(generateRandomInt32());
    return result;
}

NoteResultSpec generateRandomNoteResultSpec()
{
    NoteResultSpec result;
    result.setIncludeContent(generateRandomBool());
    result.setIncludeResourcesData(generateRandomBool());
    result.setIncludeResourcesRecognition(generateRandomBool());
    result.setIncludeResourcesAlternateData(generateRandomBool());
    result.setIncludeSharedNotes(generateRandomBool());
    result.setIncludeNoteAppDataValues(generateRandomBool());
    result.setIncludeResourceAppDataValues(generateRandomBool());
    result.setIncludeAccountLimits(generateRandomBool());
    return result;
}

NoteEmailParameters generateRandomNoteEmailParameters()
{
    NoteEmailParameters result;
    result.setGuid(generateRandomString());
    result.setNote(generateRandomNote());
    result.setToAddresses(QList<QString>());
    result.mutableToAddresses()->push_back(generateRandomString());
    result.mutableToAddresses()->push_back(generateRandomString());
    result.mutableToAddresses()->push_back(generateRandomString());
    result.setCcAddresses(QList<QString>());
    result.mutableCcAddresses()->push_back(generateRandomString());
    result.mutableCcAddresses()->push_back(generateRandomString());
    result.mutableCcAddresses()->push_back(generateRandomString());
    result.setSubject(generateRandomString());
    result.setMessage(generateRandomString());
    return result;
}

NoteVersionId generateRandomNoteVersionId()
{
    NoteVersionId result;
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setUpdated(generateRandomInt64());
    result.setSaved(generateRandomInt64());
    result.setTitle(generateRandomString());
    result.setLastEditorId(generateRandomInt32());
    return result;
}

RelatedQuery generateRandomRelatedQuery()
{
    RelatedQuery result;
    result.setNoteGuid(generateRandomString());
    result.setPlainText(generateRandomString());
    result.setFilter(generateRandomNoteFilter());
    result.setReferenceUri(generateRandomString());
    result.setContext(generateRandomString());
    result.setCacheKey(generateRandomString());
    return result;
}

RelatedResult generateRandomRelatedResult()
{
    RelatedResult result;
    result.setNotes(QList<Note>());
    result.mutableNotes()->push_back(generateRandomNote());
    result.mutableNotes()->push_back(generateRandomNote());
    result.mutableNotes()->push_back(generateRandomNote());
    result.setNotebooks(QList<Notebook>());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.mutableNotebooks()->push_back(generateRandomNotebook());
    result.setTags(QList<Tag>());
    result.mutableTags()->push_back(generateRandomTag());
    result.mutableTags()->push_back(generateRandomTag());
    result.mutableTags()->push_back(generateRandomTag());
    result.setContainingNotebooks(QList<NotebookDescriptor>());
    result.mutableContainingNotebooks()->push_back(generateRandomNotebookDescriptor());
    result.mutableContainingNotebooks()->push_back(generateRandomNotebookDescriptor());
    result.mutableContainingNotebooks()->push_back(generateRandomNotebookDescriptor());
    result.setDebugInfo(generateRandomString());
    result.setExperts(QList<UserProfile>());
    result.mutableExperts()->push_back(generateRandomUserProfile());
    result.mutableExperts()->push_back(generateRandomUserProfile());
    result.mutableExperts()->push_back(generateRandomUserProfile());
    result.setRelatedContent(QList<RelatedContent>());
    result.mutableRelatedContent()->push_back(generateRandomRelatedContent());
    result.mutableRelatedContent()->push_back(generateRandomRelatedContent());
    result.mutableRelatedContent()->push_back(generateRandomRelatedContent());
    result.setCacheKey(generateRandomString());
    result.setCacheExpires(generateRandomInt32());
    return result;
}

RelatedResultSpec generateRandomRelatedResultSpec()
{
    RelatedResultSpec result;
    result.setMaxNotes(generateRandomInt32());
    result.setMaxNotebooks(generateRandomInt32());
    result.setMaxTags(generateRandomInt32());
    result.setWritableNotebooksOnly(generateRandomBool());
    result.setIncludeContainingNotebooks(generateRandomBool());
    result.setIncludeDebugInfo(generateRandomBool());
    result.setMaxExperts(generateRandomInt32());
    result.setMaxRelatedContent(generateRandomInt32());
    result.setRelatedContentTypes(QSet<RelatedContentType>());
    result.mutableRelatedContentTypes()->insert(RelatedContentType::NEWS_ARTICLE);
    result.mutableRelatedContentTypes()->insert(RelatedContentType::NEWS_ARTICLE);
    result.mutableRelatedContentTypes()->insert(RelatedContentType::PROFILE_PERSON);
    return result;
}

UpdateNoteIfUsnMatchesResult generateRandomUpdateNoteIfUsnMatchesResult()
{
    UpdateNoteIfUsnMatchesResult result;
    result.setNote(generateRandomNote());
    result.setUpdated(generateRandomBool());
    return result;
}

ShareRelationshipRestrictions generateRandomShareRelationshipRestrictions()
{
    ShareRelationshipRestrictions result;
    result.setNoSetReadOnly(generateRandomBool());
    result.setNoSetReadPlusActivity(generateRandomBool());
    result.setNoSetModify(generateRandomBool());
    result.setNoSetFullAccess(generateRandomBool());
    return result;
}

InvitationShareRelationship generateRandomInvitationShareRelationship()
{
    InvitationShareRelationship result;
    result.setDisplayName(generateRandomString());
    result.setRecipientUserIdentity(generateRandomUserIdentity());
    result.setPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY);
    result.setSharerUserId(generateRandomInt32());
    return result;
}

MemberShareRelationship generateRandomMemberShareRelationship()
{
    MemberShareRelationship result;
    result.setDisplayName(generateRandomString());
    result.setRecipientUserId(generateRandomInt32());
    result.setBestPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK);
    result.setIndividualPrivilege(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK);
    result.setRestrictions(generateRandomShareRelationshipRestrictions());
    result.setSharerUserId(generateRandomInt32());
    return result;
}

ShareRelationships generateRandomShareRelationships()
{
    ShareRelationships result;
    result.setInvitations(QList<InvitationShareRelationship>());
    result.mutableInvitations()->push_back(generateRandomInvitationShareRelationship());
    result.mutableInvitations()->push_back(generateRandomInvitationShareRelationship());
    result.mutableInvitations()->push_back(generateRandomInvitationShareRelationship());
    result.setMemberships(QList<MemberShareRelationship>());
    result.mutableMemberships()->push_back(generateRandomMemberShareRelationship());
    result.mutableMemberships()->push_back(generateRandomMemberShareRelationship());
    result.mutableMemberships()->push_back(generateRandomMemberShareRelationship());
    result.setInvitationRestrictions(generateRandomShareRelationshipRestrictions());
    return result;
}

ManageNotebookSharesParameters generateRandomManageNotebookSharesParameters()
{
    ManageNotebookSharesParameters result;
    result.setNotebookGuid(generateRandomString());
    result.setInviteMessage(generateRandomString());
    result.setMembershipsToUpdate(QList<MemberShareRelationship>());
    result.mutableMembershipsToUpdate()->push_back(generateRandomMemberShareRelationship());
    result.mutableMembershipsToUpdate()->push_back(generateRandomMemberShareRelationship());
    result.mutableMembershipsToUpdate()->push_back(generateRandomMemberShareRelationship());
    result.setInvitationsToCreateOrUpdate(QList<InvitationShareRelationship>());
    result.mutableInvitationsToCreateOrUpdate()->push_back(generateRandomInvitationShareRelationship());
    result.mutableInvitationsToCreateOrUpdate()->push_back(generateRandomInvitationShareRelationship());
    result.mutableInvitationsToCreateOrUpdate()->push_back(generateRandomInvitationShareRelationship());
    result.setUnshares(QList<UserIdentity>());
    result.mutableUnshares()->push_back(generateRandomUserIdentity());
    result.mutableUnshares()->push_back(generateRandomUserIdentity());
    result.mutableUnshares()->push_back(generateRandomUserIdentity());
    return result;
}

ManageNotebookSharesError generateRandomManageNotebookSharesError()
{
    ManageNotebookSharesError result;
    result.setUserIdentity(generateRandomUserIdentity());
    result.setUserException(EDAMUserException());
    result.mutableUserException()->setErrorCode(EDAMErrorCode::INVALID_OPENID_TOKEN);
    result.mutableUserException()->setParameter(generateRandomString());
    result.setNotFoundException(EDAMNotFoundException());
    result.mutableNotFoundException()->setIdentifier(generateRandomString());
    result.mutableNotFoundException()->setKey(generateRandomString());
    return result;
}

ManageNotebookSharesResult generateRandomManageNotebookSharesResult()
{
    ManageNotebookSharesResult result;
    result.setErrors(QList<ManageNotebookSharesError>());
    result.mutableErrors()->push_back(generateRandomManageNotebookSharesError());
    result.mutableErrors()->push_back(generateRandomManageNotebookSharesError());
    result.mutableErrors()->push_back(generateRandomManageNotebookSharesError());
    return result;
}

SharedNoteTemplate generateRandomSharedNoteTemplate()
{
    SharedNoteTemplate result;
    result.setNoteGuid(generateRandomString());
    result.setRecipientThreadId(generateRandomInt64());
    result.setRecipientContacts(QList<Contact>());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.setPrivilege(SharedNotePrivilegeLevel::READ_NOTE);
    return result;
}

NotebookShareTemplate generateRandomNotebookShareTemplate()
{
    NotebookShareTemplate result;
    result.setNotebookGuid(generateRandomString());
    result.setRecipientThreadId(generateRandomInt64());
    result.setRecipientContacts(QList<Contact>());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.mutableRecipientContacts()->push_back(generateRandomContact());
    result.setPrivilege(SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY);
    return result;
}

CreateOrUpdateNotebookSharesResult generateRandomCreateOrUpdateNotebookSharesResult()
{
    CreateOrUpdateNotebookSharesResult result;
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setMatchingShares(QList<SharedNotebook>());
    result.mutableMatchingShares()->push_back(generateRandomSharedNotebook());
    result.mutableMatchingShares()->push_back(generateRandomSharedNotebook());
    result.mutableMatchingShares()->push_back(generateRandomSharedNotebook());
    return result;
}

NoteShareRelationshipRestrictions generateRandomNoteShareRelationshipRestrictions()
{
    NoteShareRelationshipRestrictions result;
    result.setNoSetReadNote(generateRandomBool());
    result.setNoSetModifyNote(generateRandomBool());
    result.setNoSetFullAccess(generateRandomBool());
    return result;
}

NoteMemberShareRelationship generateRandomNoteMemberShareRelationship()
{
    NoteMemberShareRelationship result;
    result.setDisplayName(generateRandomString());
    result.setRecipientUserId(generateRandomInt32());
    result.setPrivilege(SharedNotePrivilegeLevel::FULL_ACCESS);
    result.setRestrictions(generateRandomNoteShareRelationshipRestrictions());
    result.setSharerUserId(generateRandomInt32());
    return result;
}

NoteInvitationShareRelationship generateRandomNoteInvitationShareRelationship()
{
    NoteInvitationShareRelationship result;
    result.setDisplayName(generateRandomString());
    result.setRecipientIdentityId(generateRandomInt64());
    result.setPrivilege(SharedNotePrivilegeLevel::MODIFY_NOTE);
    result.setSharerUserId(generateRandomInt32());
    return result;
}

NoteShareRelationships generateRandomNoteShareRelationships()
{
    NoteShareRelationships result;
    result.setInvitations(QList<NoteInvitationShareRelationship>());
    result.mutableInvitations()->push_back(generateRandomNoteInvitationShareRelationship());
    result.mutableInvitations()->push_back(generateRandomNoteInvitationShareRelationship());
    result.mutableInvitations()->push_back(generateRandomNoteInvitationShareRelationship());
    result.setMemberships(QList<NoteMemberShareRelationship>());
    result.mutableMemberships()->push_back(generateRandomNoteMemberShareRelationship());
    result.mutableMemberships()->push_back(generateRandomNoteMemberShareRelationship());
    result.mutableMemberships()->push_back(generateRandomNoteMemberShareRelationship());
    result.setInvitationRestrictions(generateRandomNoteShareRelationshipRestrictions());
    return result;
}

ManageNoteSharesParameters generateRandomManageNoteSharesParameters()
{
    ManageNoteSharesParameters result;
    result.setNoteGuid(generateRandomString());
    result.setMembershipsToUpdate(QList<NoteMemberShareRelationship>());
    result.mutableMembershipsToUpdate()->push_back(generateRandomNoteMemberShareRelationship());
    result.mutableMembershipsToUpdate()->push_back(generateRandomNoteMemberShareRelationship());
    result.mutableMembershipsToUpdate()->push_back(generateRandomNoteMemberShareRelationship());
    result.setInvitationsToUpdate(QList<NoteInvitationShareRelationship>());
    result.mutableInvitationsToUpdate()->push_back(generateRandomNoteInvitationShareRelationship());
    result.mutableInvitationsToUpdate()->push_back(generateRandomNoteInvitationShareRelationship());
    result.mutableInvitationsToUpdate()->push_back(generateRandomNoteInvitationShareRelationship());
    result.setMembershipsToUnshare(QList<UserID>());
    result.mutableMembershipsToUnshare()->push_back(generateRandomInt32());
    result.mutableMembershipsToUnshare()->push_back(generateRandomInt32());
    result.mutableMembershipsToUnshare()->push_back(generateRandomInt32());
    result.setInvitationsToUnshare(QList<IdentityID>());
    result.mutableInvitationsToUnshare()->push_back(generateRandomInt64());
    result.mutableInvitationsToUnshare()->push_back(generateRandomInt64());
    result.mutableInvitationsToUnshare()->push_back(generateRandomInt64());
    return result;
}

ManageNoteSharesError generateRandomManageNoteSharesError()
{
    ManageNoteSharesError result;
    result.setIdentityID(generateRandomInt64());
    result.setUserID(generateRandomInt32());
    result.setUserException(EDAMUserException());
    result.mutableUserException()->setErrorCode(EDAMErrorCode::OPENID_ALREADY_TAKEN);
    result.mutableUserException()->setParameter(generateRandomString());
    result.setNotFoundException(EDAMNotFoundException());
    result.mutableNotFoundException()->setIdentifier(generateRandomString());
    result.mutableNotFoundException()->setKey(generateRandomString());
    return result;
}

ManageNoteSharesResult generateRandomManageNoteSharesResult()
{
    ManageNoteSharesResult result;
    result.setErrors(QList<ManageNoteSharesError>());
    result.mutableErrors()->push_back(generateRandomManageNoteSharesError());
    result.mutableErrors()->push_back(generateRandomManageNoteSharesError());
    result.mutableErrors()->push_back(generateRandomManageNoteSharesError());
    return result;
}

Data generateRandomData()
{
    Data result;
    result.setBodyHash(generateRandomString().toUtf8());
    result.setSize(generateRandomInt32());
    result.setBody(generateRandomString().toUtf8());
    return result;
}

UserAttributes generateRandomUserAttributes()
{
    UserAttributes result;
    result.setDefaultLocationName(generateRandomString());
    result.setDefaultLatitude(generateRandomDouble());
    result.setDefaultLongitude(generateRandomDouble());
    result.setPreactivation(generateRandomBool());
    result.setViewedPromotions(QList<QString>());
    result.mutableViewedPromotions()->push_back(generateRandomString());
    result.mutableViewedPromotions()->push_back(generateRandomString());
    result.mutableViewedPromotions()->push_back(generateRandomString());
    result.setIncomingEmailAddress(generateRandomString());
    result.setRecentMailedAddresses(QList<QString>());
    result.mutableRecentMailedAddresses()->push_back(generateRandomString());
    result.mutableRecentMailedAddresses()->push_back(generateRandomString());
    result.mutableRecentMailedAddresses()->push_back(generateRandomString());
    result.setComments(generateRandomString());
    result.setDateAgreedToTermsOfService(generateRandomInt64());
    result.setMaxReferrals(generateRandomInt32());
    result.setReferralCount(generateRandomInt32());
    result.setRefererCode(generateRandomString());
    result.setSentEmailDate(generateRandomInt64());
    result.setSentEmailCount(generateRandomInt32());
    result.setDailyEmailLimit(generateRandomInt32());
    result.setEmailOptOutDate(generateRandomInt64());
    result.setPartnerEmailOptInDate(generateRandomInt64());
    result.setPreferredLanguage(generateRandomString());
    result.setPreferredCountry(generateRandomString());
    result.setClipFullPage(generateRandomBool());
    result.setTwitterUserName(generateRandomString());
    result.setTwitterId(generateRandomString());
    result.setGroupName(generateRandomString());
    result.setRecognitionLanguage(generateRandomString());
    result.setReferralProof(generateRandomString());
    result.setEducationalDiscount(generateRandomBool());
    result.setBusinessAddress(generateRandomString());
    result.setHideSponsorBilling(generateRandomBool());
    result.setUseEmailAutoFiling(generateRandomBool());
    result.setReminderEmailConfig(ReminderEmailConfig::DO_NOT_SEND);
    result.setEmailAddressLastConfirmed(generateRandomInt64());
    result.setPasswordUpdated(generateRandomInt64());
    result.setSalesforcePushEnabled(generateRandomBool());
    result.setShouldLogClientEvent(generateRandomBool());
    result.setOptOutMachineLearning(generateRandomBool());
    return result;
}

BusinessUserAttributes generateRandomBusinessUserAttributes()
{
    BusinessUserAttributes result;
    result.setTitle(generateRandomString());
    result.setLocation(generateRandomString());
    result.setDepartment(generateRandomString());
    result.setMobilePhone(generateRandomString());
    result.setLinkedInProfileUrl(generateRandomString());
    result.setWorkPhone(generateRandomString());
    result.setCompanyStartDate(generateRandomInt64());
    return result;
}

Accounting generateRandomAccounting()
{
    Accounting result;
    result.setUploadLimitEnd(generateRandomInt64());
    result.setUploadLimitNextMonth(generateRandomInt64());
    result.setPremiumServiceStatus(PremiumOrderStatus::PENDING);
    result.setPremiumOrderNumber(generateRandomString());
    result.setPremiumCommerceService(generateRandomString());
    result.setPremiumServiceStart(generateRandomInt64());
    result.setPremiumServiceSKU(generateRandomString());
    result.setLastSuccessfulCharge(generateRandomInt64());
    result.setLastFailedCharge(generateRandomInt64());
    result.setLastFailedChargeReason(generateRandomString());
    result.setNextPaymentDue(generateRandomInt64());
    result.setPremiumLockUntil(generateRandomInt64());
    result.setUpdated(generateRandomInt64());
    result.setPremiumSubscriptionNumber(generateRandomString());
    result.setLastRequestedCharge(generateRandomInt64());
    result.setCurrency(generateRandomString());
    result.setUnitPrice(generateRandomInt32());
    result.setBusinessId(generateRandomInt32());
    result.setBusinessName(generateRandomString());
    result.setBusinessRole(BusinessUserRole::NORMAL);
    result.setUnitDiscount(generateRandomInt32());
    result.setNextChargeDate(generateRandomInt64());
    result.setAvailablePoints(generateRandomInt32());
    return result;
}

BusinessUserInfo generateRandomBusinessUserInfo()
{
    BusinessUserInfo result;
    result.setBusinessId(generateRandomInt32());
    result.setBusinessName(generateRandomString());
    result.setRole(BusinessUserRole::ADMIN);
    result.setEmail(generateRandomString());
    result.setUpdated(generateRandomInt64());
    return result;
}

AccountLimits generateRandomAccountLimits()
{
    AccountLimits result;
    result.setUserMailLimitDaily(generateRandomInt32());
    result.setNoteSizeMax(generateRandomInt64());
    result.setResourceSizeMax(generateRandomInt64());
    result.setUserLinkedNotebookMax(generateRandomInt32());
    result.setUploadLimit(generateRandomInt64());
    result.setUserNoteCountMax(generateRandomInt32());
    result.setUserNotebookCountMax(generateRandomInt32());
    result.setUserTagCountMax(generateRandomInt32());
    result.setNoteTagCountMax(generateRandomInt32());
    result.setUserSavedSearchesMax(generateRandomInt32());
    result.setNoteResourceCountMax(generateRandomInt32());
    return result;
}

User generateRandomUser()
{
    User result;
    result.setId(generateRandomInt32());
    result.setUsername(generateRandomString());
    result.setEmail(generateRandomString());
    result.setName(generateRandomString());
    result.setTimezone(generateRandomString());
    result.setPrivilege(PrivilegeLevel::MANAGER);
    result.setServiceLevel(ServiceLevel::PLUS);
    result.setCreated(generateRandomInt64());
    result.setUpdated(generateRandomInt64());
    result.setDeleted(generateRandomInt64());
    result.setActive(generateRandomBool());
    result.setShardId(generateRandomString());
    result.setAttributes(generateRandomUserAttributes());
    result.setAccounting(generateRandomAccounting());
    result.setBusinessUserInfo(generateRandomBusinessUserInfo());
    result.setPhotoUrl(generateRandomString());
    result.setPhotoLastUpdated(generateRandomInt64());
    result.setAccountLimits(generateRandomAccountLimits());
    return result;
}

Contact generateRandomContact()
{
    Contact result;
    result.setName(generateRandomString());
    result.setId(generateRandomString());
    result.setType(ContactType::EVERNOTE);
    result.setPhotoUrl(generateRandomString());
    result.setPhotoLastUpdated(generateRandomInt64());
    result.setMessagingPermit(generateRandomString().toUtf8());
    result.setMessagingPermitExpires(generateRandomInt64());
    return result;
}

Identity generateRandomIdentity()
{
    Identity result;
    result.setId(generateRandomInt64());
    result.setContact(generateRandomContact());
    result.setUserId(generateRandomInt32());
    result.setDeactivated(generateRandomBool());
    result.setSameBusiness(generateRandomBool());
    result.setBlocked(generateRandomBool());
    result.setUserConnected(generateRandomBool());
    result.setEventId(generateRandomInt64());
    return result;
}

Tag generateRandomTag()
{
    Tag result;
    result.setGuid(generateRandomString());
    result.setName(generateRandomString());
    result.setParentGuid(generateRandomString());
    result.setUpdateSequenceNum(generateRandomInt32());
    return result;
}

LazyMap generateRandomLazyMap()
{
    LazyMap result;
    result.setKeysOnly(QSet<QString>());
    result.mutableKeysOnly()->insert(generateRandomString());
    result.mutableKeysOnly()->insert(generateRandomString());
    result.mutableKeysOnly()->insert(generateRandomString());
    result.setFullMap(QMap<QString, QString>());
    result.mutableFullMap()->insert(generateRandomString(), generateRandomString());
    result.mutableFullMap()->insert(generateRandomString(), generateRandomString());
    result.mutableFullMap()->insert(generateRandomString(), generateRandomString());
    return result;
}

ResourceAttributes generateRandomResourceAttributes()
{
    ResourceAttributes result;
    result.setSourceURL(generateRandomString());
    result.setTimestamp(generateRandomInt64());
    result.setLatitude(generateRandomDouble());
    result.setLongitude(generateRandomDouble());
    result.setAltitude(generateRandomDouble());
    result.setCameraMake(generateRandomString());
    result.setCameraModel(generateRandomString());
    result.setClientWillIndex(generateRandomBool());
    result.setRecoType(generateRandomString());
    result.setFileName(generateRandomString());
    result.setAttachment(generateRandomBool());
    result.setApplicationData(generateRandomLazyMap());
    return result;
}

Resource generateRandomResource()
{
    Resource result;
    result.setGuid(generateRandomString());
    result.setNoteGuid(generateRandomString());
    result.setData(generateRandomData());
    result.setMime(generateRandomString());
    result.setWidth(generateRandomInt16());
    result.setHeight(generateRandomInt16());
    result.setDuration(generateRandomInt16());
    result.setActive(generateRandomBool());
    result.setRecognition(generateRandomData());
    result.setAttributes(generateRandomResourceAttributes());
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setAlternateData(generateRandomData());
    return result;
}

NoteAttributes generateRandomNoteAttributes()
{
    NoteAttributes result;
    result.setSubjectDate(generateRandomInt64());
    result.setLatitude(generateRandomDouble());
    result.setLongitude(generateRandomDouble());
    result.setAltitude(generateRandomDouble());
    result.setAuthor(generateRandomString());
    result.setSource(generateRandomString());
    result.setSourceURL(generateRandomString());
    result.setSourceApplication(generateRandomString());
    result.setShareDate(generateRandomInt64());
    result.setReminderOrder(generateRandomInt64());
    result.setReminderDoneTime(generateRandomInt64());
    result.setReminderTime(generateRandomInt64());
    result.setPlaceName(generateRandomString());
    result.setContentClass(generateRandomString());
    result.setApplicationData(generateRandomLazyMap());
    result.setLastEditedBy(generateRandomString());
    result.setClassifications(QMap<QString, QString>());
    result.mutableClassifications()->insert(generateRandomString(), generateRandomString());
    result.mutableClassifications()->insert(generateRandomString(), generateRandomString());
    result.mutableClassifications()->insert(generateRandomString(), generateRandomString());
    result.setCreatorId(generateRandomInt32());
    result.setLastEditorId(generateRandomInt32());
    result.setSharedWithBusiness(generateRandomBool());
    result.setConflictSourceNoteGuid(generateRandomString());
    result.setNoteTitleQuality(generateRandomInt32());
    return result;
}

SharedNote generateRandomSharedNote()
{
    SharedNote result;
    result.setSharerUserID(generateRandomInt32());
    result.setRecipientIdentity(generateRandomIdentity());
    result.setPrivilege(SharedNotePrivilegeLevel::FULL_ACCESS);
    result.setServiceCreated(generateRandomInt64());
    result.setServiceUpdated(generateRandomInt64());
    result.setServiceAssigned(generateRandomInt64());
    return result;
}

NoteRestrictions generateRandomNoteRestrictions()
{
    NoteRestrictions result;
    result.setNoUpdateTitle(generateRandomBool());
    result.setNoUpdateContent(generateRandomBool());
    result.setNoEmail(generateRandomBool());
    result.setNoShare(generateRandomBool());
    result.setNoSharePublicly(generateRandomBool());
    return result;
}

NoteLimits generateRandomNoteLimits()
{
    NoteLimits result;
    result.setNoteResourceCountMax(generateRandomInt32());
    result.setUploadLimit(generateRandomInt64());
    result.setResourceSizeMax(generateRandomInt64());
    result.setNoteSizeMax(generateRandomInt64());
    result.setUploaded(generateRandomInt64());
    return result;
}

Note generateRandomNote()
{
    Note result;
    result.setGuid(generateRandomString());
    result.setTitle(generateRandomString());
    result.setContent(generateRandomString());
    result.setContentHash(generateRandomString().toUtf8());
    result.setContentLength(generateRandomInt32());
    result.setCreated(generateRandomInt64());
    result.setUpdated(generateRandomInt64());
    result.setDeleted(generateRandomInt64());
    result.setActive(generateRandomBool());
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setNotebookGuid(generateRandomString());
    result.setTagGuids(QList<Guid>());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.mutableTagGuids()->push_back(generateRandomString());
    result.setResources(QList<Resource>());
    result.mutableResources()->push_back(generateRandomResource());
    result.mutableResources()->push_back(generateRandomResource());
    result.mutableResources()->push_back(generateRandomResource());
    result.setAttributes(generateRandomNoteAttributes());
    result.setTagNames(QList<QString>());
    result.mutableTagNames()->push_back(generateRandomString());
    result.mutableTagNames()->push_back(generateRandomString());
    result.mutableTagNames()->push_back(generateRandomString());
    result.setSharedNotes(QList<SharedNote>());
    result.mutableSharedNotes()->push_back(generateRandomSharedNote());
    result.mutableSharedNotes()->push_back(generateRandomSharedNote());
    result.mutableSharedNotes()->push_back(generateRandomSharedNote());
    result.setRestrictions(generateRandomNoteRestrictions());
    result.setLimits(generateRandomNoteLimits());
    return result;
}

Publishing generateRandomPublishing()
{
    Publishing result;
    result.setUri(generateRandomString());
    result.setOrder(NoteSortOrder::UPDATED);
    result.setAscending(generateRandomBool());
    result.setPublicDescription(generateRandomString());
    return result;
}

BusinessNotebook generateRandomBusinessNotebook()
{
    BusinessNotebook result;
    result.setNotebookDescription(generateRandomString());
    result.setPrivilege(SharedNotebookPrivilegeLevel::GROUP);
    result.setRecommended(generateRandomBool());
    return result;
}

SavedSearchScope generateRandomSavedSearchScope()
{
    SavedSearchScope result;
    result.setIncludeAccount(generateRandomBool());
    result.setIncludePersonalLinkedNotebooks(generateRandomBool());
    result.setIncludeBusinessLinkedNotebooks(generateRandomBool());
    return result;
}

SavedSearch generateRandomSavedSearch()
{
    SavedSearch result;
    result.setGuid(generateRandomString());
    result.setName(generateRandomString());
    result.setQuery(generateRandomString());
    result.setFormat(QueryFormat::USER);
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setScope(generateRandomSavedSearchScope());
    return result;
}

SharedNotebookRecipientSettings generateRandomSharedNotebookRecipientSettings()
{
    SharedNotebookRecipientSettings result;
    result.setReminderNotifyEmail(generateRandomBool());
    result.setReminderNotifyInApp(generateRandomBool());
    return result;
}

NotebookRecipientSettings generateRandomNotebookRecipientSettings()
{
    NotebookRecipientSettings result;
    result.setReminderNotifyEmail(generateRandomBool());
    result.setReminderNotifyInApp(generateRandomBool());
    result.setInMyList(generateRandomBool());
    result.setStack(generateRandomString());
    result.setRecipientStatus(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK);
    return result;
}

SharedNotebook generateRandomSharedNotebook()
{
    SharedNotebook result;
    result.setId(generateRandomInt64());
    result.setUserId(generateRandomInt32());
    result.setNotebookGuid(generateRandomString());
    result.setEmail(generateRandomString());
    result.setRecipientIdentityId(generateRandomInt64());
    result.setNotebookModifiable(generateRandomBool());
    result.setServiceCreated(generateRandomInt64());
    result.setServiceUpdated(generateRandomInt64());
    result.setGlobalId(generateRandomString());
    result.setUsername(generateRandomString());
    result.setPrivilege(SharedNotebookPrivilegeLevel::GROUP);
    result.setRecipientSettings(generateRandomSharedNotebookRecipientSettings());
    result.setSharerUserId(generateRandomInt32());
    result.setRecipientUsername(generateRandomString());
    result.setRecipientUserId(generateRandomInt32());
    result.setServiceAssigned(generateRandomInt64());
    return result;
}

CanMoveToContainerRestrictions generateRandomCanMoveToContainerRestrictions()
{
    CanMoveToContainerRestrictions result;
    result.setCanMoveToContainer(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE);
    return result;
}

NotebookRestrictions generateRandomNotebookRestrictions()
{
    NotebookRestrictions result;
    result.setNoReadNotes(generateRandomBool());
    result.setNoCreateNotes(generateRandomBool());
    result.setNoUpdateNotes(generateRandomBool());
    result.setNoExpungeNotes(generateRandomBool());
    result.setNoShareNotes(generateRandomBool());
    result.setNoEmailNotes(generateRandomBool());
    result.setNoSendMessageToRecipients(generateRandomBool());
    result.setNoUpdateNotebook(generateRandomBool());
    result.setNoExpungeNotebook(generateRandomBool());
    result.setNoSetDefaultNotebook(generateRandomBool());
    result.setNoSetNotebookStack(generateRandomBool());
    result.setNoPublishToPublic(generateRandomBool());
    result.setNoPublishToBusinessLibrary(generateRandomBool());
    result.setNoCreateTags(generateRandomBool());
    result.setNoUpdateTags(generateRandomBool());
    result.setNoExpungeTags(generateRandomBool());
    result.setNoSetParentTag(generateRandomBool());
    result.setNoCreateSharedNotebooks(generateRandomBool());
    result.setUpdateWhichSharedNotebookRestrictions(SharedNotebookInstanceRestrictions::ASSIGNED);
    result.setExpungeWhichSharedNotebookRestrictions(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS);
    result.setNoShareNotesWithBusiness(generateRandomBool());
    result.setNoRenameNotebook(generateRandomBool());
    result.setNoSetInMyList(generateRandomBool());
    result.setNoChangeContact(generateRandomBool());
    result.setCanMoveToContainerRestrictions(generateRandomCanMoveToContainerRestrictions());
    result.setNoSetReminderNotifyEmail(generateRandomBool());
    result.setNoSetReminderNotifyInApp(generateRandomBool());
    result.setNoSetRecipientSettingsStack(generateRandomBool());
    result.setNoCanMoveNote(generateRandomBool());
    return result;
}

Notebook generateRandomNotebook()
{
    Notebook result;
    result.setGuid(generateRandomString());
    result.setName(generateRandomString());
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setDefaultNotebook(generateRandomBool());
    result.setServiceCreated(generateRandomInt64());
    result.setServiceUpdated(generateRandomInt64());
    result.setPublishing(generateRandomPublishing());
    result.setPublished(generateRandomBool());
    result.setStack(generateRandomString());
    result.setSharedNotebookIds(QList<qint64>());
    result.mutableSharedNotebookIds()->push_back(generateRandomInt64());
    result.mutableSharedNotebookIds()->push_back(generateRandomInt64());
    result.mutableSharedNotebookIds()->push_back(generateRandomInt64());
    result.setSharedNotebooks(QList<SharedNotebook>());
    result.mutableSharedNotebooks()->push_back(generateRandomSharedNotebook());
    result.mutableSharedNotebooks()->push_back(generateRandomSharedNotebook());
    result.mutableSharedNotebooks()->push_back(generateRandomSharedNotebook());
    result.setBusinessNotebook(generateRandomBusinessNotebook());
    result.setContact(generateRandomUser());
    result.setRestrictions(generateRandomNotebookRestrictions());
    result.setRecipientSettings(generateRandomNotebookRecipientSettings());
    return result;
}

LinkedNotebook generateRandomLinkedNotebook()
{
    LinkedNotebook result;
    result.setShareName(generateRandomString());
    result.setUsername(generateRandomString());
    result.setShardId(generateRandomString());
    result.setSharedNotebookGlobalId(generateRandomString());
    result.setUri(generateRandomString());
    result.setGuid(generateRandomString());
    result.setUpdateSequenceNum(generateRandomInt32());
    result.setNoteStoreUrl(generateRandomString());
    result.setWebApiUrlPrefix(generateRandomString());
    result.setStack(generateRandomString());
    result.setBusinessId(generateRandomInt32());
    return result;
}

NotebookDescriptor generateRandomNotebookDescriptor()
{
    NotebookDescriptor result;
    result.setGuid(generateRandomString());
    result.setNotebookDisplayName(generateRandomString());
    result.setContactName(generateRandomString());
    result.setHasSharedNotebook(generateRandomBool());
    result.setJoinedUserCount(generateRandomInt32());
    return result;
}

UserProfile generateRandomUserProfile()
{
    UserProfile result;
    result.setId(generateRandomInt32());
    result.setName(generateRandomString());
    result.setEmail(generateRandomString());
    result.setUsername(generateRandomString());
    result.setAttributes(generateRandomBusinessUserAttributes());
    result.setJoined(generateRandomInt64());
    result.setPhotoLastUpdated(generateRandomInt64());
    result.setPhotoUrl(generateRandomString());
    result.setRole(BusinessUserRole::NORMAL);
    result.setStatus(BusinessUserStatus::ACTIVE);
    return result;
}

RelatedContentImage generateRandomRelatedContentImage()
{
    RelatedContentImage result;
    result.setUrl(generateRandomString());
    result.setWidth(generateRandomInt32());
    result.setHeight(generateRandomInt32());
    result.setPixelRatio(generateRandomDouble());
    result.setFileSize(generateRandomInt32());
    return result;
}

RelatedContent generateRandomRelatedContent()
{
    RelatedContent result;
    result.setContentId(generateRandomString());
    result.setTitle(generateRandomString());
    result.setUrl(generateRandomString());
    result.setSourceId(generateRandomString());
    result.setSourceUrl(generateRandomString());
    result.setSourceFaviconUrl(generateRandomString());
    result.setSourceName(generateRandomString());
    result.setDate(generateRandomInt64());
    result.setTeaser(generateRandomString());
    result.setThumbnails(QList<RelatedContentImage>());
    result.mutableThumbnails()->push_back(generateRandomRelatedContentImage());
    result.mutableThumbnails()->push_back(generateRandomRelatedContentImage());
    result.mutableThumbnails()->push_back(generateRandomRelatedContentImage());
    result.setContentType(RelatedContentType::NEWS_ARTICLE);
    result.setAccessType(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW);
    result.setVisibleUrl(generateRandomString());
    result.setClipUrl(generateRandomString());
    result.setContact(generateRandomContact());
    result.setAuthors(QList<QString>());
    result.mutableAuthors()->push_back(generateRandomString());
    result.mutableAuthors()->push_back(generateRandomString());
    result.mutableAuthors()->push_back(generateRandomString());
    return result;
}

BusinessInvitation generateRandomBusinessInvitation()
{
    BusinessInvitation result;
    result.setBusinessId(generateRandomInt32());
    result.setEmail(generateRandomString());
    result.setRole(BusinessUserRole::ADMIN);
    result.setStatus(BusinessInvitationStatus::APPROVED);
    result.setRequesterId(generateRandomInt32());
    result.setFromWorkChat(generateRandomBool());
    result.setCreated(generateRandomInt64());
    result.setMostRecentReminder(generateRandomInt64());
    return result;
}

UserIdentity generateRandomUserIdentity()
{
    UserIdentity result;
    result.setType(UserIdentityType::IDENTITYID);
    result.setStringIdentifier(generateRandomString());
    result.setLongIdentifier(generateRandomInt64());
    return result;
}

PublicUserInfo generateRandomPublicUserInfo()
{
    PublicUserInfo result;
    result.setUserId(generateRandomInt32());
    result.setServiceLevel(ServiceLevel::PLUS);
    result.setUsername(generateRandomString());
    result.setNoteStoreUrl(generateRandomString());
    result.setWebApiUrlPrefix(generateRandomString());
    return result;
}

UserUrls generateRandomUserUrls()
{
    UserUrls result;
    result.setNoteStoreUrl(generateRandomString());
    result.setWebApiUrlPrefix(generateRandomString());
    result.setUserStoreUrl(generateRandomString());
    result.setUtilityUrl(generateRandomString());
    result.setMessageStoreUrl(generateRandomString());
    result.setUserWebSocketUrl(generateRandomString());
    return result;
}

AuthenticationResult generateRandomAuthenticationResult()
{
    AuthenticationResult result;
    result.setCurrentTime(generateRandomInt64());
    result.setAuthenticationToken(generateRandomString());
    result.setExpiration(generateRandomInt64());
    result.setUser(generateRandomUser());
    result.setPublicUserInfo(generateRandomPublicUserInfo());
    result.setNoteStoreUrl(generateRandomString());
    result.setWebApiUrlPrefix(generateRandomString());
    result.setSecondFactorRequired(generateRandomBool());
    result.setSecondFactorDeliveryHint(generateRandomString());
    result.setUrls(generateRandomUserUrls());
    return result;
}

BootstrapSettings generateRandomBootstrapSettings()
{
    BootstrapSettings result;
    result.setServiceHost(generateRandomString());
    result.setMarketingUrl(generateRandomString());
    result.setSupportUrl(generateRandomString());
    result.setAccountEmailDomain(generateRandomString());
    result.setEnableFacebookSharing(generateRandomBool());
    result.setEnableGiftSubscriptions(generateRandomBool());
    result.setEnableSupportTickets(generateRandomBool());
    result.setEnableSharedNotebooks(generateRandomBool());
    result.setEnableSingleNoteSharing(generateRandomBool());
    result.setEnableSponsoredAccounts(generateRandomBool());
    result.setEnableTwitterSharing(generateRandomBool());
    result.setEnableLinkedInSharing(generateRandomBool());
    result.setEnablePublicNotebooks(generateRandomBool());
    result.setEnableGoogle(generateRandomBool());
    return result;
}

BootstrapProfile generateRandomBootstrapProfile()
{
    BootstrapProfile result;
    result.setName(generateRandomString());
    result.setSettings(generateRandomBootstrapSettings());
    return result;
}

BootstrapInfo generateRandomBootstrapInfo()
{
    BootstrapInfo result;
    result.mutableProfiles().push_back(generateRandomBootstrapProfile());
    result.mutableProfiles().push_back(generateRandomBootstrapProfile());
    result.mutableProfiles().push_back(generateRandomBootstrapProfile());
    return result;
}

} // namespace qevercloud
