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

#include <qevercloud/types/Metatypes.h>
#include "../Impl.h"

namespace qevercloud {

void registerMetatypes()
{
    qRegisterMetaType<AccountLimits>("AccountLimits");
    qRegisterMetaType<Accounting>("Accounting");
    qRegisterMetaType<AuthenticationResult>("AuthenticationResult");
    qRegisterMetaType<BootstrapInfo>("BootstrapInfo");
    qRegisterMetaType<BootstrapProfile>("BootstrapProfile");
    qRegisterMetaType<BootstrapSettings>("BootstrapSettings");
    qRegisterMetaType<BusinessInvitation>("BusinessInvitation");
    qRegisterMetaType<BusinessNotebook>("BusinessNotebook");
    qRegisterMetaType<BusinessUserAttributes>("BusinessUserAttributes");
    qRegisterMetaType<BusinessUserInfo>("BusinessUserInfo");
    qRegisterMetaType<CanMoveToContainerRestrictions>("CanMoveToContainerRestrictions");
    qRegisterMetaType<Contact>("Contact");
    qRegisterMetaType<CreateOrUpdateNotebookSharesResult>("CreateOrUpdateNotebookSharesResult");
    qRegisterMetaType<Data>("Data");
    qRegisterMetaType<EDAMInvalidContactsException>("EDAMInvalidContactsException");
    qRegisterMetaType<EDAMNotFoundException>("EDAMNotFoundException");
    qRegisterMetaType<EDAMSystemException>("EDAMSystemException");
    qRegisterMetaType<EDAMUserException>("EDAMUserException");
    qRegisterMetaType<Identity>("Identity");
    qRegisterMetaType<InvitationShareRelationship>("InvitationShareRelationship");
    qRegisterMetaType<LazyMap>("LazyMap");
    qRegisterMetaType<LinkedNotebook>("LinkedNotebook");
    qRegisterMetaType<ManageNoteSharesError>("ManageNoteSharesError");
    qRegisterMetaType<ManageNoteSharesParameters>("ManageNoteSharesParameters");
    qRegisterMetaType<ManageNoteSharesResult>("ManageNoteSharesResult");
    qRegisterMetaType<ManageNotebookSharesError>("ManageNotebookSharesError");
    qRegisterMetaType<ManageNotebookSharesParameters>("ManageNotebookSharesParameters");
    qRegisterMetaType<ManageNotebookSharesResult>("ManageNotebookSharesResult");
    qRegisterMetaType<MemberShareRelationship>("MemberShareRelationship");
    qRegisterMetaType<Note>("Note");
    qRegisterMetaType<NoteAttributes>("NoteAttributes");
    qRegisterMetaType<NoteCollectionCounts>("NoteCollectionCounts");
    qRegisterMetaType<NoteEmailParameters>("NoteEmailParameters");
    qRegisterMetaType<NoteFilter>("NoteFilter");
    qRegisterMetaType<NoteInvitationShareRelationship>("NoteInvitationShareRelationship");
    qRegisterMetaType<NoteLimits>("NoteLimits");
    qRegisterMetaType<NoteList>("NoteList");
    qRegisterMetaType<NoteMemberShareRelationship>("NoteMemberShareRelationship");
    qRegisterMetaType<NoteMetadata>("NoteMetadata");
    qRegisterMetaType<NoteRestrictions>("NoteRestrictions");
    qRegisterMetaType<NoteResultSpec>("NoteResultSpec");
    qRegisterMetaType<NoteShareRelationshipRestrictions>("NoteShareRelationshipRestrictions");
    qRegisterMetaType<NoteShareRelationships>("NoteShareRelationships");
    qRegisterMetaType<NoteVersionId>("NoteVersionId");
    qRegisterMetaType<Notebook>("Notebook");
    qRegisterMetaType<NotebookDescriptor>("NotebookDescriptor");
    qRegisterMetaType<NotebookRecipientSettings>("NotebookRecipientSettings");
    qRegisterMetaType<NotebookRestrictions>("NotebookRestrictions");
    qRegisterMetaType<NotebookShareTemplate>("NotebookShareTemplate");
    qRegisterMetaType<NotesMetadataList>("NotesMetadataList");
    qRegisterMetaType<NotesMetadataResultSpec>("NotesMetadataResultSpec");
    qRegisterMetaType<PublicUserInfo>("PublicUserInfo");
    qRegisterMetaType<Publishing>("Publishing");
    qRegisterMetaType<RelatedContent>("RelatedContent");
    qRegisterMetaType<RelatedContentImage>("RelatedContentImage");
    qRegisterMetaType<RelatedQuery>("RelatedQuery");
    qRegisterMetaType<RelatedResult>("RelatedResult");
    qRegisterMetaType<RelatedResultSpec>("RelatedResultSpec");
    qRegisterMetaType<Resource>("Resource");
    qRegisterMetaType<ResourceAttributes>("ResourceAttributes");
    qRegisterMetaType<SavedSearch>("SavedSearch");
    qRegisterMetaType<SavedSearchScope>("SavedSearchScope");
    qRegisterMetaType<ShareRelationshipRestrictions>("ShareRelationshipRestrictions");
    qRegisterMetaType<ShareRelationships>("ShareRelationships");
    qRegisterMetaType<SharedNote>("SharedNote");
    qRegisterMetaType<SharedNoteTemplate>("SharedNoteTemplate");
    qRegisterMetaType<SharedNotebook>("SharedNotebook");
    qRegisterMetaType<SharedNotebookRecipientSettings>("SharedNotebookRecipientSettings");
    qRegisterMetaType<SyncChunk>("SyncChunk");
    qRegisterMetaType<SyncChunkFilter>("SyncChunkFilter");
    qRegisterMetaType<SyncState>("SyncState");
    qRegisterMetaType<Tag>("Tag");
    qRegisterMetaType<UpdateNoteIfUsnMatchesResult>("UpdateNoteIfUsnMatchesResult");
    qRegisterMetaType<User>("User");
    qRegisterMetaType<UserAttributes>("UserAttributes");
    qRegisterMetaType<UserIdentity>("UserIdentity");
    qRegisterMetaType<UserProfile>("UserProfile");
    qRegisterMetaType<UserUrls>("UserUrls");

    qRegisterMetaType<std::optional<AccountLimits>>("std::optional<AccountLimits>");
    qRegisterMetaType<std::optional<Accounting>>("std::optional<Accounting>");
    qRegisterMetaType<std::optional<BusinessInvitationStatus>>("std::optional<BusinessInvitationStatus>");
    qRegisterMetaType<std::optional<BusinessNotebook>>("std::optional<BusinessNotebook>");
    qRegisterMetaType<std::optional<BusinessUserAttributes>>("std::optional<BusinessUserAttributes>");
    qRegisterMetaType<std::optional<BusinessUserInfo>>("std::optional<BusinessUserInfo>");
    qRegisterMetaType<std::optional<BusinessUserRole>>("std::optional<BusinessUserRole>");
    qRegisterMetaType<std::optional<BusinessUserStatus>>("std::optional<BusinessUserStatus>");
    qRegisterMetaType<std::optional<CanMoveToContainerRestrictions>>("std::optional<CanMoveToContainerRestrictions>");
    qRegisterMetaType<std::optional<CanMoveToContainerStatus>>("std::optional<CanMoveToContainerStatus>");
    qRegisterMetaType<std::optional<Contact>>("std::optional<Contact>");
    qRegisterMetaType<std::optional<ContactType>>("std::optional<ContactType>");
    qRegisterMetaType<std::optional<Data>>("std::optional<Data>");
    qRegisterMetaType<std::optional<EDAMNotFoundException>>("std::optional<EDAMNotFoundException>");
    qRegisterMetaType<std::optional<EDAMUserException>>("std::optional<EDAMUserException>");
    qRegisterMetaType<std::optional<Identity>>("std::optional<Identity>");
    qRegisterMetaType<std::optional<LazyMap>>("std::optional<LazyMap>");
    qRegisterMetaType<std::optional<Note>>("std::optional<Note>");
    qRegisterMetaType<std::optional<NoteAttributes>>("std::optional<NoteAttributes>");
    qRegisterMetaType<std::optional<NoteFilter>>("std::optional<NoteFilter>");
    qRegisterMetaType<std::optional<NoteLimits>>("std::optional<NoteLimits>");
    qRegisterMetaType<std::optional<NoteRestrictions>>("std::optional<NoteRestrictions>");
    qRegisterMetaType<std::optional<NoteShareRelationshipRestrictions>>("std::optional<NoteShareRelationshipRestrictions>");
    qRegisterMetaType<std::optional<NoteSortOrder>>("std::optional<NoteSortOrder>");
    qRegisterMetaType<std::optional<NotebookRecipientSettings>>("std::optional<NotebookRecipientSettings>");
    qRegisterMetaType<std::optional<NotebookRestrictions>>("std::optional<NotebookRestrictions>");
    qRegisterMetaType<std::optional<PremiumOrderStatus>>("std::optional<PremiumOrderStatus>");
    qRegisterMetaType<std::optional<PrivilegeLevel>>("std::optional<PrivilegeLevel>");
    qRegisterMetaType<std::optional<PublicUserInfo>>("std::optional<PublicUserInfo>");
    qRegisterMetaType<std::optional<Publishing>>("std::optional<Publishing>");
    qRegisterMetaType<std::optional<QByteArray>>("std::optional<QByteArray>");
    qRegisterMetaType<std::optional<QList<Contact>>>("std::optional<QList<Contact>>");
    qRegisterMetaType<std::optional<QList<EDAMInvalidContactReason>>>("std::optional<QList<EDAMInvalidContactReason>>");
    qRegisterMetaType<std::optional<QList<InvitationShareRelationship>>>("std::optional<QList<InvitationShareRelationship>>");
    qRegisterMetaType<std::optional<QList<LinkedNotebook>>>("std::optional<QList<LinkedNotebook>>");
    qRegisterMetaType<std::optional<QList<ManageNoteSharesError>>>("std::optional<QList<ManageNoteSharesError>>");
    qRegisterMetaType<std::optional<QList<ManageNotebookSharesError>>>("std::optional<QList<ManageNotebookSharesError>>");
    qRegisterMetaType<std::optional<QList<MemberShareRelationship>>>("std::optional<QList<MemberShareRelationship>>");
    qRegisterMetaType<std::optional<QList<Note>>>("std::optional<QList<Note>>");
    qRegisterMetaType<std::optional<QList<NoteInvitationShareRelationship>>>("std::optional<QList<NoteInvitationShareRelationship>>");
    qRegisterMetaType<std::optional<QList<NoteMemberShareRelationship>>>("std::optional<QList<NoteMemberShareRelationship>>");
    qRegisterMetaType<std::optional<QList<Notebook>>>("std::optional<QList<Notebook>>");
    qRegisterMetaType<std::optional<QList<NotebookDescriptor>>>("std::optional<QList<NotebookDescriptor>>");
    qRegisterMetaType<std::optional<QList<QString>>>("std::optional<QList<QString>>");
    qRegisterMetaType<std::optional<QList<RelatedContent>>>("std::optional<QList<RelatedContent>>");
    qRegisterMetaType<std::optional<QList<RelatedContentImage>>>("std::optional<QList<RelatedContentImage>>");
    qRegisterMetaType<std::optional<QList<Resource>>>("std::optional<QList<Resource>>");
    qRegisterMetaType<std::optional<QList<SavedSearch>>>("std::optional<QList<SavedSearch>>");
    qRegisterMetaType<std::optional<QList<SharedNote>>>("std::optional<QList<SharedNote>>");
    qRegisterMetaType<std::optional<QList<SharedNotebook>>>("std::optional<QList<SharedNotebook>>");
    qRegisterMetaType<std::optional<QList<Tag>>>("std::optional<QList<Tag>>");
    qRegisterMetaType<std::optional<QList<UserIdentity>>>("std::optional<QList<UserIdentity>>");
    qRegisterMetaType<std::optional<QList<UserProfile>>>("std::optional<QList<UserProfile>>");
    qRegisterMetaType<std::optional<QList<qint32>>>("std::optional<QList<qint32>>");
    qRegisterMetaType<std::optional<QList<qint64>>>("std::optional<QList<qint64>>");
    qRegisterMetaType<std::optional<QMap<QString, QString>>>("std::optional<QMap<QString, QString>>");
    qRegisterMetaType<std::optional<QMap<QString, qint32>>>("std::optional<QMap<QString, qint32>>");
    qRegisterMetaType<std::optional<QSet<QString>>>("std::optional<QSet<QString>>");
    qRegisterMetaType<std::optional<QSet<RelatedContentType>>>("std::optional<QSet<RelatedContentType>>");
    qRegisterMetaType<std::optional<QString>>("std::optional<QString>");
    qRegisterMetaType<std::optional<QueryFormat>>("std::optional<QueryFormat>");
    qRegisterMetaType<std::optional<RecipientStatus>>("std::optional<RecipientStatus>");
    qRegisterMetaType<std::optional<RelatedContentAccess>>("std::optional<RelatedContentAccess>");
    qRegisterMetaType<std::optional<RelatedContentType>>("std::optional<RelatedContentType>");
    qRegisterMetaType<std::optional<ReminderEmailConfig>>("std::optional<ReminderEmailConfig>");
    qRegisterMetaType<std::optional<ResourceAttributes>>("std::optional<ResourceAttributes>");
    qRegisterMetaType<std::optional<SavedSearchScope>>("std::optional<SavedSearchScope>");
    qRegisterMetaType<std::optional<ServiceLevel>>("std::optional<ServiceLevel>");
    qRegisterMetaType<std::optional<ShareRelationshipPrivilegeLevel>>("std::optional<ShareRelationshipPrivilegeLevel>");
    qRegisterMetaType<std::optional<ShareRelationshipRestrictions>>("std::optional<ShareRelationshipRestrictions>");
    qRegisterMetaType<std::optional<SharedNotePrivilegeLevel>>("std::optional<SharedNotePrivilegeLevel>");
    qRegisterMetaType<std::optional<SharedNotebookInstanceRestrictions>>("std::optional<SharedNotebookInstanceRestrictions>");
    qRegisterMetaType<std::optional<SharedNotebookPrivilegeLevel>>("std::optional<SharedNotebookPrivilegeLevel>");
    qRegisterMetaType<std::optional<SharedNotebookRecipientSettings>>("std::optional<SharedNotebookRecipientSettings>");
    qRegisterMetaType<std::optional<User>>("std::optional<User>");
    qRegisterMetaType<std::optional<UserAttributes>>("std::optional<UserAttributes>");
    qRegisterMetaType<std::optional<UserIdentity>>("std::optional<UserIdentity>");
    qRegisterMetaType<std::optional<UserIdentityType>>("std::optional<UserIdentityType>");
    qRegisterMetaType<std::optional<UserUrls>>("std::optional<UserUrls>");
    qRegisterMetaType<std::optional<bool>>("std::optional<bool>");
    qRegisterMetaType<std::optional<double>>("std::optional<double>");
    qRegisterMetaType<std::optional<qint16>>("std::optional<qint16>");
    qRegisterMetaType<std::optional<qint32>>("std::optional<qint32>");
    qRegisterMetaType<std::optional<qint64>>("std::optional<qint64>");
}

} // namespace qevercloud
