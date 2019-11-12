/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Common.h"

#include <QCryptographicHash>
#include <QDateTime>

#include <cstdlib>

namespace qevercloud {
namespace tests {

SyncState generateSyncState()
{
    SyncState state;
    state.currentTime = QDateTime::currentMSecsSinceEpoch();
    state.fullSyncBefore = state.currentTime + 100000;
    state.updateCount = 10;
    state.uploaded = 20000;
    state.userLastUpdated = state.currentTime - 20;
    state.userMaxMessageEventId = 50000;

    return state;
}

SyncChunkFilter generateSyncChunkFilter()
{
    SyncChunkFilter filter;
    filter.includeNotes = true;
    filter.includeNoteResources = false;
    filter.includeNoteAttributes = true;
    filter.includeNotebooks = false;
    filter.includeTags = true;
    filter.includeSearches = false;
    filter.includeResources = true;
    filter.includeLinkedNotebooks = false;
    filter.includeExpunged = true;
    filter.includeNoteApplicationDataFullMap = false;
    filter.includeResourceApplicationDataFullMap = true;
    filter.includeNoteResourceApplicationDataFullMap = false;
    filter.includeSharedNotes = true;
    filter.omitSharedNotebooks = false;
    filter.requireNoteContentClass = true;
    filter.notebookGuids = QSet<QString>() << QStringLiteral("guid1")
        << QStringLiteral("guid2") << QStringLiteral("guid3");

    return filter;
}

NoteFilter generateNoteFilter()
{
    NoteFilter filter;
    filter.order = 5;
    filter.ascending = false;
    filter.words = QStringLiteral("words");
    filter.notebookGuid = QStringLiteral("notebookGuid");
    filter.tagGuids = QList<QString>() << QStringLiteral("tagGuid1")
        << QStringLiteral("tagGuid2") << QStringLiteral("tagGuid3");
    filter.timeZone = QStringLiteral("America/Los_Angeles");
    filter.inactive = false;
    filter.emphasized = QStringLiteral("emphasized");
    filter.includeAllReadableNotebooks = true;
    filter.includeAllReadableWorkspaces = false;
    filter.context = QStringLiteral("context");
    filter.rawWords = QStringLiteral("rawWords");
    filter.searchContextBytes = QStringLiteral("searchContextBytes").toUtf8();

    return filter;
}

NotesMetadataResultSpec generateNotesMetadataResultSpec()
{
    NotesMetadataResultSpec spec;
    spec.includeTitle = true;
    spec.includeContentLength = false;
    spec.includeCreated = true;
    spec.includeUpdated = false;
    spec.includeDeleted = true;
    spec.includeUpdateSequenceNum = false;
    spec.includeNotebookGuid = true;
    spec.includeTagGuids = false;
    spec.includeAttributes = true;
    spec.includeLargestResourceMime = false;
    spec.includeLargestResourceSize = true;

    return spec;
}

NoteCollectionCounts generateNoteCollectionCounts()
{
    NoteCollectionCounts counts;

    QMap<Guid, qint32> notebookCounts;
    notebookCounts[QStringLiteral("notebookGuid1")] = 2;
    notebookCounts[QStringLiteral("notebookGuid2")] = 3;
    notebookCounts[QStringLiteral("notebookGuid3")] = 4;
    counts.notebookCounts = notebookCounts;

    QMap<Guid, qint32> tagCounts;
    tagCounts[QStringLiteral("tagGuid1")] = 2;
    tagCounts[QStringLiteral("tagGuid2")] = 3;
    tagCounts[QStringLiteral("tagGuid3")] = 4;
    counts.tagCounts = tagCounts;

    counts.trashCount = 15;

    return counts;
}

NoteResultSpec generateNoteResultSpec()
{
    NoteResultSpec spec;
    spec.includeContent = true;
    spec.includeResourcesData = false;
    spec.includeResourcesRecognition = true;
    spec.includeResourcesAlternateData = false;
    spec.includeSharedNotes = true;
    spec.includeNoteAppDataValues = false;
    spec.includeResourceAppDataValues = true;
    spec.includeAccountLimits = false;

    return spec;
}

NoteVersionId generateNoteVersionId()
{
    NoteVersionId id;
    id.updateSequenceNum = 95;
    id.updated = QDateTime::currentMSecsSinceEpoch();
    id.saved = id.updated - 100;
    id.title = QStringLiteral("title");
    id.lastEditorId = 72;

    return id;
}

RelatedQuery generateRelatedQuery()
{
    RelatedQuery query;
    query.noteGuid = QStringLiteral("noteGuid");
    query.plainText = QStringLiteral("plainText");
    query.filter = generateNoteFilter();
    query.referenceUri = QStringLiteral("referenceUri");
    query.context = QStringLiteral("context");
    query.cacheKey = QStringLiteral("cacheKey");

    return query;
}

RelatedResultSpec generateRelatedResultSpec()
{
    RelatedResultSpec spec;
    spec.maxNotes = 30;
    spec.maxNotebooks = 10;
    spec.maxTags = 20;
    spec.writableNotebooksOnly = false;
    spec.includeContainingNotebooks = true;
    spec.includeDebugInfo = false;
    spec.maxExperts = 5;
    spec.maxRelatedContent = 3;
    spec.relatedContentTypes = QSet<RelatedContentType>()
        << RelatedContentType::NEWS_ARTICLE
        << RelatedContentType::PROFILE_ORGANIZATION
        << RelatedContentType::PROFILE_PERSON;

    return spec;
}

ShareRelationshipRestrictions generateShareRelationshipRestrictions()
{
    ShareRelationshipRestrictions r;
    r.noSetReadOnly = false;
    r.noSetReadPlusActivity = true;
    r.noSetModify = false;
    r.noSetFullAccess = true;

    return r;
}

MemberShareRelationship generateMemberShareRelationship()
{
    MemberShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientUserId = 5;
    r.bestPrivilege = ShareRelationshipPrivilegeLevel::FULL_ACCESS;
    r.individualPrivilege = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK;
    r.restrictions = generateShareRelationshipRestrictions();
    r.sharerUserId = 10;

    return r;
}

NoteShareRelationshipRestrictions generateNoteShareRelationshipRestrictions()
{
    NoteShareRelationshipRestrictions r;
    r.noSetReadNote = false;
    r.noSetModifyNote = true;
    r.noSetFullAccess = false;

    return r;
}

NoteMemberShareRelationship generateNoteMemberShareRelationship()
{
    NoteMemberShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientUserId = 7;
    r.privilege = SharedNotePrivilegeLevel::READ_NOTE;
    r.restrictions = generateNoteShareRelationshipRestrictions();
    r.sharerUserId = 19;

    return r;
}

NoteInvitationShareRelationship generateNoteInvitationShareRelationship()
{
    NoteInvitationShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientIdentityId = 124;
    r.privilege = SharedNotePrivilegeLevel::FULL_ACCESS;
    r.sharerUserId = 231;

    return r;
}

NoteShareRelationships generateNoteShareRelationships()
{
    NoteShareRelationships r;
    r.invitations = QList<NoteInvitationShareRelationship>()
        << generateNoteInvitationShareRelationship();
    r.memberships = QList<NoteMemberShareRelationship>()
        << generateNoteMemberShareRelationship();
    r.invitationRestrictions = generateNoteShareRelationshipRestrictions();

    return r;
}

ManageNoteSharesParameters generateManageNoteSharesParameters()
{
    ManageNoteSharesParameters p;
    p.noteGuid = QStringLiteral("noteGuid");
    p.membershipsToUpdate = QList<NoteMemberShareRelationship>()
        << generateNoteMemberShareRelationship();
    p.invitationsToUpdate = QList<NoteInvitationShareRelationship>()
        << generateNoteInvitationShareRelationship();
    p.membershipsToUnshare = QList<UserID>() << 27 << 81 << 32;
    p.invitationsToUnshare = QList<IdentityID>() << 22 << 46 << 73;

    return p;
}

Data generateData()
{
    Data data;
    data.body = QString(QStringLiteral("data body ") + QString::number(rand() % 101)).toUtf8();
    data.size = data.body->size();
    data.bodyHash = QCryptographicHash::hash(data.body.ref(), QCryptographicHash::Md5);

    return data;
}

UserAttributes generateUserAttributes()
{
    UserAttributes a;
    a.defaultLocationName = QStringLiteral("defaultLocationName");
    a.defaultLatitude = 0.1;
    a.defaultLongitude = 0.2;
    a.preactivation = false;
    a.viewedPromotions = QStringList()
        << QStringLiteral("viewedPromotion1")
        << QStringLiteral("viewedPromotion2")
        << QStringLiteral("viewedPromotion3");
    a.incomingEmailAddress = QStringLiteral("incomingEmailAddress");
    a.recentMailedAddresses = QStringList()
        << QStringLiteral("recentMailedAddress1")
        << QStringLiteral("recentMailedAddress2")
        << QStringLiteral("recentMailedAddress3");
    a.comments = QStringLiteral("comments");
    a.dateAgreedToTermsOfService = QDateTime::currentMSecsSinceEpoch();
    a.maxReferrals = 11;
    a.referralCount = 9;
    a.refererCode = QStringLiteral("refererCode");
    a.sentEmailDate = QDateTime::currentMSecsSinceEpoch();
    a.sentEmailCount = 8;
    a.dailyEmailLimit = 22;
    a.emailOptOutDate = QDateTime::currentMSecsSinceEpoch();
    a.partnerEmailOptInDate = QDateTime::currentMSecsSinceEpoch();
    a.preferredLanguage = QStringLiteral("en");
    a.preferredCountry = QStringLiteral("US");
    a.clipFullPage = false;
    a.twitterUserName = QStringLiteral("twitterUserName");
    a.twitterId = QStringLiteral("twitterId");
    a.groupName = QStringLiteral("groupName");
    a.recognitionLanguage = QStringLiteral("ru");
    a.referralProof = QStringLiteral("referralProof");
    a.educationalDiscount = false;
    a.businessAddress = QStringLiteral("businessAddress");
    a.hideSponsorBilling = true;
    a.useEmailAutoFiling = false;
    a.reminderEmailConfig = ReminderEmailConfig::DO_NOT_SEND;
    a.passwordUpdated = QDateTime::currentMSecsSinceEpoch();
    a.salesforcePushEnabled = false;
    a.shouldLogClientEvent = true;
    a.optOutMachineLearning = false;

    return a;
}

BusinessUserAttributes generateBusinessUserAttributes()
{
    BusinessUserAttributes a;
    a.title = QStringLiteral("title");
    a.location = QStringLiteral("location");
    a.department = QStringLiteral("department");
    a.mobilePhone = QStringLiteral("mobilePhone");
    a.linkedInProfileUrl = QStringLiteral("linkedInProfileUrl");
    a.workPhone = QStringLiteral("workPhone");
    a.companyStartDate = QDateTime::currentMSecsSinceEpoch();

    return a;
}

Accounting generateAccounting()
{
    Accounting a;
    a.uploadLimitEnd = QDateTime::currentMSecsSinceEpoch() + 10000;
    a.uploadLimitNextMonth = 700;
    a.premiumServiceStatus = PremiumOrderStatus::PENDING;
    a.premiumOrderNumber = QStringLiteral("premiumOrderNumber");
    a.premiumCommerceService = QStringLiteral("premiumCommerceService");
    a.premiumServiceStart = QDateTime::currentMSecsSinceEpoch();
    a.premiumServiceSKU = QStringLiteral("premiumServiceSKU");
    a.lastSuccessfulCharge = QDateTime::currentMSecsSinceEpoch();
    a.lastFailedCharge = QDateTime::currentMSecsSinceEpoch();
    a.lastFailedChargeReason = QStringLiteral("lastFailedChargeReason");
    a.nextPaymentDue = QDateTime::currentMSecsSinceEpoch() + 200;
    a.premiumLockUntil = QDateTime::currentMSecsSinceEpoch() + 100;
    a.updated = QDateTime::currentMSecsSinceEpoch() + 50;
    a.premiumSubscriptionNumber = QStringLiteral("premiumSubscriptionNumber");
    a.lastRequestedCharge = QDateTime::currentMSecsSinceEpoch() - 50;
    a.currency = QStringLiteral("currency");
    a.unitPrice = 19;
    a.businessId = 21;
    a.businessName = QStringLiteral("businessName");
    a.businessRole = BusinessUserRole::NORMAL;
    a.unitDiscount = 14;
    a.nextChargeDate = QDateTime::currentMSecsSinceEpoch() + 400;
    a.availablePoints = 11;

    return a;
}

BusinessUserInfo generateBusinessUserInfo()
{
    BusinessUserInfo info;
    info.businessId = 13;
    info.businessName = QStringLiteral("businessName");
    info.role = BusinessUserRole::NORMAL;
    info.email = QStringLiteral("email");
    info.updated = QDateTime::currentMSecsSinceEpoch();

    return info;
}

AccountLimits generateAccountLimits()
{
    AccountLimits limits;
    limits.userMailLimitDaily = 9;
    limits.noteSizeMax = 300;
    limits.resourceSizeMax = 200;
    limits.userLinkedNotebookMax = 30;
    limits.uploadLimit = 500;
    limits.userNoteCountMax = 40;
    limits.userNotebookCountMax = 35;
    limits.userTagCountMax = 45;
    limits.noteTagCountMax = 20;
    limits.userSavedSearchesMax = 50;
    limits.noteResourceCountMax = 60;

    return limits;
}

User generateUser()
{
    User user;
    user.id = 19;
    user.username = QStringLiteral("username");
    user.email = QStringLiteral("email");
    user.name = QStringLiteral("name");
    user.timezone = QStringLiteral("America/Los_Angeles");
    user.privilege = PrivilegeLevel::MANAGER;
    user.serviceLevel = ServiceLevel::BASIC;
    user.created = QDateTime::currentMSecsSinceEpoch();
    user.updated = QDateTime::currentMSecsSinceEpoch();
    user.deleted = QDateTime::currentMSecsSinceEpoch();
    user.active = true;
    user.shardId = QStringLiteral("shardId");
    user.attributes = generateUserAttributes();
    user.accounting = generateAccounting();
    user.businessUserInfo = generateBusinessUserInfo();
    user.photoUrl = QStringLiteral("photoUrl");
    user.photoLastUpdated = QDateTime::currentMSecsSinceEpoch();
    user.accountLimits = generateAccountLimits();

    return user;
}

Contact generateContact()
{
    Contact contact;
    contact.name = QStringLiteral("name");
    contact.id = QStringLiteral("id");
    contact.type = ContactType::EVERNOTE;
    contact.photoUrl = QStringLiteral("photoUrl");
    contact.photoLastUpdated = QDateTime::currentMSecsSinceEpoch() - 20;
    contact.messagingPermit = QStringLiteral("messagingPermit").toUtf8();
    contact.messagingPermitExpires = QDateTime::currentMSecsSinceEpoch();

    return contact;
}

Identity generateIdentity()
{
    Identity identity;
    identity.id = 200;
    identity.contact = generateContact();
    identity.userId = 30;
    identity.deactivated = false;
    identity.sameBusiness = true;
    identity.blocked = false;
    identity.userConnected = true;
    identity.eventId = 341;

    return identity;
}

Tag generateTag()
{
    Tag tag;
    tag.guid = QStringLiteral("guid");
    tag.name = QStringLiteral("name");
    tag.parentGuid = QStringLiteral("parentGuid");
    tag.updateSequenceNum = 30;

    return tag;
}

LazyMap generateLazyMap()
{
    LazyMap lazyMap;

    QSet<QString> keysOnly;
    keysOnly << QStringLiteral("key1");
    keysOnly << QStringLiteral("key2");
    keysOnly << QStringLiteral("key3");
    lazyMap.keysOnly = keysOnly;

    QMap<QString, QString> fullMap;
    fullMap[QStringLiteral("key1")] = QStringLiteral("value1");
    fullMap[QStringLiteral("key2")] = QStringLiteral("value2");
    fullMap[QStringLiteral("key3")] = QStringLiteral("value3");
    lazyMap.fullMap = fullMap;

    return lazyMap;
}

ResourceAttributes generateResourceAttributes()
{
    ResourceAttributes a;
    a.sourceURL = QStringLiteral("sourceURL");
    a.timestamp = QDateTime::currentMSecsSinceEpoch();
    a.latitude = 0.1;
    a.longitude = 0.2;
    a.altitude = 0.3;
    a.cameraMake = QStringLiteral("cameraMake");
    a.clientWillIndex = false;
    a.recoType = QStringLiteral("recoType");
    a.fileName = QStringLiteral("fileName");
    a.attachment = false;
    a.applicationData = generateLazyMap();

    return a;
}

Resource generateResource()
{
    Resource r;
    r.guid = QStringLiteral("guid");
    r.noteGuid = QStringLiteral("noteGuid");
    r.data = generateData();
    r.mime = QStringLiteral("mime");
    r.width = 23;
    r.height = 19;
    r.duration = 13;
    r.active = true;
    r.recognition = generateData();
    r.attributes = generateResourceAttributes();
    r.updateSequenceNum = 31;
    r.alternateData = generateData();

    return r;
}

NoteAttributes generateNoteAttributes()
{
    NoteAttributes a;
    a.subjectDate = QDateTime::currentMSecsSinceEpoch();
    a.latitude = 0.1;
    a.longitude = 0.2;
    a.altitude = 0.3;
    a.author = QStringLiteral("author");
    a.source = QStringLiteral("source");
    a.sourceURL = QStringLiteral("sourceURL");
    a.sourceApplication = QStringLiteral("sourceApplication");
    a.shareDate = QDateTime::currentMSecsSinceEpoch() - 20;
    a.reminderOrder = 20;
    a.reminderDoneTime = QDateTime::currentMSecsSinceEpoch() - 300;
    a.reminderTime = QDateTime::currentMSecsSinceEpoch() - 100;
    a.placeName = QStringLiteral("placeName");
    a.contentClass = QStringLiteral("contentClass");
    a.applicationData = generateLazyMap();
    a.lastEditedBy = QStringLiteral("lastEditedBy");

    QMap<QString, QString> classifications;
    classifications[QStringLiteral("key1")] = QStringLiteral("value1");
    classifications[QStringLiteral("key2")] = QStringLiteral("value2");
    classifications[QStringLiteral("key3")] = QStringLiteral("value3");
    a.classifications = classifications;

    a.creatorId = 18;
    a.lastEditorId = 16;
    a.sharedWithBusiness = false;
    a.conflictSourceNoteGuid = QStringLiteral("conflictSourceNoteGuid");
    a.noteTitleQuality = 2;

    return a;
}

SharedNote generateSharedNote()
{
    SharedNote n;
    n.sharerUserID = 19;
    n.recipientIdentity = generateIdentity();
    n.privilege = SharedNotePrivilegeLevel::MODIFY_NOTE;
    n.serviceCreated = QDateTime::currentMSecsSinceEpoch() - 20;
    n.serviceUpdated = QDateTime::currentMSecsSinceEpoch() - 10;
    n.serviceAssigned = QDateTime::currentMSecsSinceEpoch();

    return n;
}

NoteRestrictions generateNoteRestrictions()
{
    NoteRestrictions r;
    r.noUpdateTitle = true;
    r.noUpdateContent = false;
    r.noEmail = true;
    r.noShare = false;
    r.noSharePublicly = true;

    return r;
}

NoteLimits generateNoteLimits()
{
    NoteLimits limits;
    limits.noteResourceCountMax = 10;
    limits.uploadLimit = 100;
    limits.resourceSizeMax = 20;
    limits.noteSizeMax = 40;
    limits.uploaded = 50;

    return limits;
}

Note generateNote()
{
    Note note;
    note.guid = QStringLiteral("guid");
    note.title = QStringLiteral("title");
    note.content = QStringLiteral("content");
    note.contentHash = QCryptographicHash::hash(
        note.content.ref().toUtf8(),
        QCryptographicHash::Md5);
    note.contentLength = note.content->size();
    note.created = QDateTime::currentMSecsSinceEpoch() - 20;
    note.updated = QDateTime::currentMSecsSinceEpoch() - 10;
    note.deleted = QDateTime::currentMSecsSinceEpoch();
    note.active = true;
    note.updateSequenceNum = 20;
    note.notebookGuid = QStringLiteral("notebookGuid");
    note.tagGuids = QList<Guid>()
        << QStringLiteral("tagGuid1")
        << QStringLiteral("tagGuid2")
        << QStringLiteral("tagGuid3");
    note.resources = QList<Resource>()
        << generateResource();
    note.attributes = generateNoteAttributes();
    note.tagNames = QStringList()
        << QStringLiteral("tagName1")
        << QStringLiteral("tagName2")
        << QStringLiteral("tagName3");
    note.sharedNotes = QList<SharedNote>()
        << generateSharedNote();
    note.restrictions = generateNoteRestrictions();
    note.limits = generateNoteLimits();

    return note;
}

Publishing generatePublishing()
{
    // TODO: implement
    return {};
}

BusinessNotebook generateBusinessNotebook()
{
    // TODO: implement
    return {};
}

SavedSearchScope generateSavedSearchScope()
{
    // TODO: implement
    return {};
}

SavedSearch generateSavedSearch()
{
    // TODO: implement
    return {};
}

SharedNotebookRecipientSettings generateSharedNotebookRecipientSettings()
{
    // TODO: implement
    return {};
}

NotebookRecipientSettings generateNotebookRecipientSettings()
{
    // TODO: implement
    return {};
}

SharedNotebook generateSharedNotebook()
{
    // TODO: implement
    return {};
}

CanMoveToContainerRestrictions generateCanMoveToContainerRestrictions()
{
    // TODO: implement
    return {};
}

NotebookRestrictions generateNotebookRestrictions()
{
    // TODO: implement
    return {};
}

Notebook generateNotebook()
{
    // TODO: implement
    return {};
}

LinkedNotebook generateLinkedNotebook()
{
    // TODO: implement
    return {};
}

NotebookDescriptor generateNotebookDescriptor()
{
    // TODO: implement
    return {};
}

UserProfile generateUserProfile()
{
    // TODO: implement
    return {};
}

RelatedContentImage generateRelatedContentImage()
{
    // TODO: implement
    return {};
}

RelatedContent generateRelatedContent()
{
    // TODO: implement
    return {};
}

BusinessInvitation generateBusinessInvitation()
{
    // TODO: implement
    return {};
}

UserIdentity generateUserIdentity()
{
    // TODO: implement
    return {};
}

PublicUserInfo generatePublicUserInfo()
{
    // TODO: implement
    return {};
}

UserUrls generateUserUrls()
{
    // TODO: implement
    return {};
}

AuthenticationResult generateAuthenticationResult()
{
    // TODO: implement
    return {};
}

BootstrapSettings generateBootstrapSettings()
{
    // TODO: implement
    return {};
}

BootstrapProfile generateBootstrapProfile()
{
    // TODO: implement
    return {};
}

BootstrapInfo generateBootstrapInfo()
{
    // TODO: implement
    return {};
}

SyncChunk generateSyncChunk()
{
    // TODO: implement
    return {};
}

NoteList generateNoteList()
{
    // TODO: implement
    return {};
}

NoteMetadata generateNoteMetadata()
{
    // TODO: implement
    return {};
}

NotesMetadataList generateNotesMetadataList()
{
    // TODO: implement
    return {};
}

NoteEmailParameters generateNoteEmailParameters()
{
    // TODO: implement
    return {};
}

RelatedResult generateRelatedResult()
{
    // TODO: implement
    return {};
}

UpdateNoteIfUsnMatchesResult generateUpdateNoteIfUsnMatchesResult()
{
    // TODO: implement
    return {};
}

InvitationShareRelationship generateInvitationShareRelationship()
{
    // TODO: implement
    return {};
}

ShareRelationships generateShareRelationships()
{
    // TODO: implement
    return {};
}

ManageNotebookSharesParameters generateManageNotebookSharesParameters()
{
    // TODO: implement
    return {};
}

ManageNotebookSharesError generateManageNotebookSharesError()
{
    // TODO: implement
    return {};
}

ManageNotebookSharesResult generateManageNotebookSharesResult()
{
    // TODO: implement
    return {};
}

SharedNoteTemplate generateSharedNoteTemplate()
{
    // TODO: implement
    return {};
}

NotebookShareTemplate generateNotebookShareTemplate()
{
    // TODO: implement
    return {};
}

CreateOrUpdateNotebookSharesResult generateCreateOrUpdateNotebookSharesResult()
{
    // TODO: implement
    return {};
}

ManageNoteSharesError generateManageNoteSharesError()
{
    // TODO: implement
    return {};
}

ManageNoteSharesResult generateManageNoteSharesResult()
{
    // TODO: implement
    return {};
}

} // namespace tests
} // namespace qevercloud
