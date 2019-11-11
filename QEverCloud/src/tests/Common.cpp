/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Common.h"

#include <QDateTime>

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
    // TODO: implement
    return {};
}

RelatedResultSpec generateRelatedResultSpec()
{
    // TODO: implement
    return {};
}

ShareRelationshipRestrictions generateShareRelationshipRestrictions()
{
    // TODO: implement
    return {};
}

MemberShareRelationship generateMemberShareRelationship()
{
    // TODO: implement
    return {};
}

NoteShareRelationshipRestrictions generateNoteShareRelationshipRestrictions()
{
    // TODO: implement
    return {};
}

NoteMemberShareRelationship generateNoteMemberShareRelationship()
{
    // TODO: implement
    return {};
}

NoteInvitationShareRelationship generateNoteInvitationShareRelationship()
{
    // TODO: implement
    return {};
}

NoteShareRelationships generateNoteShareRelationships()
{
    // TODO: implement
    return {};
}

ManageNoteSharesParameters generateManageNoteSharesParameters()
{
    // TODO: implement
    return {};
}

Data generateData()
{
    // TODO: implement
    return {};
}

UserAttributes generateUserAttributes()
{
    // TODO: implement
    return {};
}

BusinessUserAttributes generateBusinessUserAttributes()
{
    // TODO: implement
    return {};
}

Accounting generateAccounting()
{
    // TODO: implement
    return {};
}

BusinessUserInfo generateBusinessUserInfo()
{
    // TODO: implement
    return {};
}

AccountLimits generateAccountLimits()
{
    // TODO: implement
    return {};
}

User generateUser()
{
    // TODO: implement
    return {};
}

Contact generateContact()
{
    // TODO: implement
    return {};
}

Identity generateIdentity()
{
    // TODO: implement
    return {};
}

Tag generateTag()
{
    // TODO: implement
    return {};
}

LazyMap generateLazyMap()
{
    // TODO: implement
    return {};
}

ResourceAttributes generateResourceAttributes()
{
    // TODO: implement
    return {};
}

Resource generateResource()
{
    // TODO: implement
    return {};
}

NoteAttributes generateNoteAttributes()
{
    // TODO: implement
    return {};
}

SharedNote generateSharedNote()
{
    // TODO: implement
    return {};
}

NoteRestrictions generateNoteRestrictions()
{
    // TODO: implement
    return {};
}

NoteLimits generateNoteLimits()
{
    // TODO: implement
    return {};
}

Note generateNote()
{
    // TODO: implement
    return {};
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
