/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
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
    qRegisterMetaType<EDAMInvalidContactsException>("qevercloud::EDAMInvalidContactsException");
    qRegisterMetaType<EDAMNotFoundException>("qevercloud::EDAMNotFoundException");
    qRegisterMetaType<EDAMSystemException>("qevercloud::EDAMSystemException");
    qRegisterMetaType<EDAMUserException>("qevercloud::EDAMUserException");

    qRegisterMetaType<AccountLimits>("qevercloud::AccountLimits");
    qRegisterMetaType<Accounting>("qevercloud::Accounting");
    qRegisterMetaType<AuthenticationResult>("qevercloud::AuthenticationResult");
    qRegisterMetaType<BootstrapInfo>("qevercloud::BootstrapInfo");
    qRegisterMetaType<BootstrapProfile>("qevercloud::BootstrapProfile");
    qRegisterMetaType<BootstrapSettings>("qevercloud::BootstrapSettings");
    qRegisterMetaType<BusinessInvitation>("qevercloud::BusinessInvitation");
    qRegisterMetaType<BusinessNotebook>("qevercloud::BusinessNotebook");
    qRegisterMetaType<BusinessUserAttributes>("qevercloud::BusinessUserAttributes");
    qRegisterMetaType<BusinessUserInfo>("qevercloud::BusinessUserInfo");
    qRegisterMetaType<CanMoveToContainerRestrictions>("qevercloud::CanMoveToContainerRestrictions");
    qRegisterMetaType<Contact>("qevercloud::Contact");
    qRegisterMetaType<CreateOrUpdateNotebookSharesResult>("qevercloud::CreateOrUpdateNotebookSharesResult");
    qRegisterMetaType<Data>("qevercloud::Data");
    qRegisterMetaType<Identity>("qevercloud::Identity");
    qRegisterMetaType<InvitationShareRelationship>("qevercloud::InvitationShareRelationship");
    qRegisterMetaType<LazyMap>("qevercloud::LazyMap");
    qRegisterMetaType<LinkedNotebook>("qevercloud::LinkedNotebook");
    qRegisterMetaType<ManageNoteSharesError>("qevercloud::ManageNoteSharesError");
    qRegisterMetaType<ManageNoteSharesParameters>("qevercloud::ManageNoteSharesParameters");
    qRegisterMetaType<ManageNoteSharesResult>("qevercloud::ManageNoteSharesResult");
    qRegisterMetaType<ManageNotebookSharesError>("qevercloud::ManageNotebookSharesError");
    qRegisterMetaType<ManageNotebookSharesParameters>("qevercloud::ManageNotebookSharesParameters");
    qRegisterMetaType<ManageNotebookSharesResult>("qevercloud::ManageNotebookSharesResult");
    qRegisterMetaType<MemberShareRelationship>("qevercloud::MemberShareRelationship");
    qRegisterMetaType<Note>("qevercloud::Note");
    qRegisterMetaType<NoteAttributes>("qevercloud::NoteAttributes");
    qRegisterMetaType<NoteCollectionCounts>("qevercloud::NoteCollectionCounts");
    qRegisterMetaType<NoteEmailParameters>("qevercloud::NoteEmailParameters");
    qRegisterMetaType<NoteFilter>("qevercloud::NoteFilter");
    qRegisterMetaType<NoteInvitationShareRelationship>("qevercloud::NoteInvitationShareRelationship");
    qRegisterMetaType<NoteLimits>("qevercloud::NoteLimits");
    qRegisterMetaType<NoteList>("qevercloud::NoteList");
    qRegisterMetaType<NoteMemberShareRelationship>("qevercloud::NoteMemberShareRelationship");
    qRegisterMetaType<NoteMetadata>("qevercloud::NoteMetadata");
    qRegisterMetaType<NoteRestrictions>("qevercloud::NoteRestrictions");
    qRegisterMetaType<NoteResultSpec>("qevercloud::NoteResultSpec");
    qRegisterMetaType<NoteShareRelationshipRestrictions>("qevercloud::NoteShareRelationshipRestrictions");
    qRegisterMetaType<NoteShareRelationships>("qevercloud::NoteShareRelationships");
    qRegisterMetaType<NoteVersionId>("qevercloud::NoteVersionId");
    qRegisterMetaType<Notebook>("qevercloud::Notebook");
    qRegisterMetaType<NotebookDescriptor>("qevercloud::NotebookDescriptor");
    qRegisterMetaType<NotebookRecipientSettings>("qevercloud::NotebookRecipientSettings");
    qRegisterMetaType<NotebookRestrictions>("qevercloud::NotebookRestrictions");
    qRegisterMetaType<NotebookShareTemplate>("qevercloud::NotebookShareTemplate");
    qRegisterMetaType<NotesMetadataList>("qevercloud::NotesMetadataList");
    qRegisterMetaType<NotesMetadataResultSpec>("qevercloud::NotesMetadataResultSpec");
    qRegisterMetaType<PublicUserInfo>("qevercloud::PublicUserInfo");
    qRegisterMetaType<Publishing>("qevercloud::Publishing");
    qRegisterMetaType<RelatedContent>("qevercloud::RelatedContent");
    qRegisterMetaType<RelatedContentImage>("qevercloud::RelatedContentImage");
    qRegisterMetaType<RelatedQuery>("qevercloud::RelatedQuery");
    qRegisterMetaType<RelatedResult>("qevercloud::RelatedResult");
    qRegisterMetaType<RelatedResultSpec>("qevercloud::RelatedResultSpec");
    qRegisterMetaType<Resource>("qevercloud::Resource");
    qRegisterMetaType<ResourceAttributes>("qevercloud::ResourceAttributes");
    qRegisterMetaType<SavedSearch>("qevercloud::SavedSearch");
    qRegisterMetaType<SavedSearchScope>("qevercloud::SavedSearchScope");
    qRegisterMetaType<ShareRelationshipRestrictions>("qevercloud::ShareRelationshipRestrictions");
    qRegisterMetaType<ShareRelationships>("qevercloud::ShareRelationships");
    qRegisterMetaType<SharedNote>("qevercloud::SharedNote");
    qRegisterMetaType<SharedNoteTemplate>("qevercloud::SharedNoteTemplate");
    qRegisterMetaType<SharedNotebook>("qevercloud::SharedNotebook");
    qRegisterMetaType<SharedNotebookRecipientSettings>("qevercloud::SharedNotebookRecipientSettings");
    qRegisterMetaType<SyncChunk>("qevercloud::SyncChunk");
    qRegisterMetaType<SyncChunkFilter>("qevercloud::SyncChunkFilter");
    qRegisterMetaType<SyncState>("qevercloud::SyncState");
    qRegisterMetaType<Tag>("qevercloud::Tag");
    qRegisterMetaType<UpdateNoteIfUsnMatchesResult>("qevercloud::UpdateNoteIfUsnMatchesResult");
    qRegisterMetaType<User>("qevercloud::User");
    qRegisterMetaType<UserAttributes>("qevercloud::UserAttributes");
    qRegisterMetaType<UserIdentity>("qevercloud::UserIdentity");
    qRegisterMetaType<UserProfile>("qevercloud::UserProfile");
    qRegisterMetaType<UserUrls>("qevercloud::UserUrls");

    qRegisterMetaType<InvalidationSequenceNumber>("qevercloud::InvalidationSequenceNumber");
    qRegisterMetaType<IdentityID>("qevercloud::IdentityID");
    qRegisterMetaType<UserID>("qevercloud::UserID");
    qRegisterMetaType<Guid>("qevercloud::Guid");
    qRegisterMetaType<Timestamp>("qevercloud::Timestamp");
    qRegisterMetaType<MessageEventID>("qevercloud::MessageEventID");
    qRegisterMetaType<MessageThreadID>("qevercloud::MessageThreadID");

    qRegisterMetaType<std::optional<AccountLimits>>("std::optional<qevercloud::AccountLimits>");
    qRegisterMetaType<std::optional<Accounting>>("std::optional<qevercloud::Accounting>");
    qRegisterMetaType<std::optional<BusinessInvitationStatus>>("std::optional<qevercloud::BusinessInvitationStatus>");
    qRegisterMetaType<std::optional<BusinessNotebook>>("std::optional<qevercloud::BusinessNotebook>");
    qRegisterMetaType<std::optional<BusinessUserAttributes>>("std::optional<qevercloud::BusinessUserAttributes>");
    qRegisterMetaType<std::optional<BusinessUserInfo>>("std::optional<qevercloud::BusinessUserInfo>");
    qRegisterMetaType<std::optional<BusinessUserRole>>("std::optional<qevercloud::BusinessUserRole>");
    qRegisterMetaType<std::optional<BusinessUserStatus>>("std::optional<qevercloud::BusinessUserStatus>");
    qRegisterMetaType<std::optional<CanMoveToContainerRestrictions>>("std::optional<qevercloud::CanMoveToContainerRestrictions>");
    qRegisterMetaType<std::optional<CanMoveToContainerStatus>>("std::optional<qevercloud::CanMoveToContainerStatus>");
    qRegisterMetaType<std::optional<Contact>>("std::optional<qevercloud::Contact>");
    qRegisterMetaType<std::optional<ContactType>>("std::optional<qevercloud::ContactType>");
    qRegisterMetaType<std::optional<Data>>("std::optional<qevercloud::Data>");
    qRegisterMetaType<std::optional<EDAMInvalidContactReason>>("std::optional<qevercloud::EDAMInvalidContactReason>");
    qRegisterMetaType<std::optional<EDAMNotFoundException>>("std::optional<qevercloud::EDAMNotFoundException>");
    qRegisterMetaType<std::optional<EDAMUserException>>("std::optional<qevercloud::EDAMUserException>");
    qRegisterMetaType<std::optional<Identity>>("std::optional<qevercloud::Identity>");
    qRegisterMetaType<std::optional<InvitationShareRelationship>>("std::optional<qevercloud::InvitationShareRelationship>");
    qRegisterMetaType<std::optional<LazyMap>>("std::optional<qevercloud::LazyMap>");
    qRegisterMetaType<std::optional<LinkedNotebook>>("std::optional<qevercloud::LinkedNotebook>");
    qRegisterMetaType<std::optional<ManageNoteSharesError>>("std::optional<qevercloud::ManageNoteSharesError>");
    qRegisterMetaType<std::optional<ManageNotebookSharesError>>("std::optional<qevercloud::ManageNotebookSharesError>");
    qRegisterMetaType<std::optional<MemberShareRelationship>>("std::optional<qevercloud::MemberShareRelationship>");
    qRegisterMetaType<std::optional<Note>>("std::optional<qevercloud::Note>");
    qRegisterMetaType<std::optional<NoteAttributes>>("std::optional<qevercloud::NoteAttributes>");
    qRegisterMetaType<std::optional<NoteFilter>>("std::optional<qevercloud::NoteFilter>");
    qRegisterMetaType<std::optional<NoteInvitationShareRelationship>>("std::optional<qevercloud::NoteInvitationShareRelationship>");
    qRegisterMetaType<std::optional<NoteLimits>>("std::optional<qevercloud::NoteLimits>");
    qRegisterMetaType<std::optional<NoteMemberShareRelationship>>("std::optional<qevercloud::NoteMemberShareRelationship>");
    qRegisterMetaType<std::optional<NoteRestrictions>>("std::optional<qevercloud::NoteRestrictions>");
    qRegisterMetaType<std::optional<NoteShareRelationshipRestrictions>>("std::optional<qevercloud::NoteShareRelationshipRestrictions>");
    qRegisterMetaType<std::optional<NoteSortOrder>>("std::optional<qevercloud::NoteSortOrder>");
    qRegisterMetaType<std::optional<Notebook>>("std::optional<qevercloud::Notebook>");
    qRegisterMetaType<std::optional<NotebookDescriptor>>("std::optional<qevercloud::NotebookDescriptor>");
    qRegisterMetaType<std::optional<NotebookRecipientSettings>>("std::optional<qevercloud::NotebookRecipientSettings>");
    qRegisterMetaType<std::optional<NotebookRestrictions>>("std::optional<qevercloud::NotebookRestrictions>");
    qRegisterMetaType<std::optional<PremiumOrderStatus>>("std::optional<qevercloud::PremiumOrderStatus>");
    qRegisterMetaType<std::optional<PrivilegeLevel>>("std::optional<qevercloud::PrivilegeLevel>");
    qRegisterMetaType<std::optional<PublicUserInfo>>("std::optional<qevercloud::PublicUserInfo>");
    qRegisterMetaType<std::optional<Publishing>>("std::optional<qevercloud::Publishing>");
    qRegisterMetaType<std::optional<QByteArray>>("std::optional<QByteArray>");
    qRegisterMetaType<std::optional<QMap<QString, QString>>>("std::optional<QMap<QString, QString>>");
    qRegisterMetaType<std::optional<QMap<QString, qint32>>>("std::optional<QMap<QString, qint32>>");
    qRegisterMetaType<std::optional<QString>>("std::optional<QString>");
    qRegisterMetaType<std::optional<QueryFormat>>("std::optional<qevercloud::QueryFormat>");
    qRegisterMetaType<std::optional<RecipientStatus>>("std::optional<qevercloud::RecipientStatus>");
    qRegisterMetaType<std::optional<RelatedContent>>("std::optional<qevercloud::RelatedContent>");
    qRegisterMetaType<std::optional<RelatedContentAccess>>("std::optional<qevercloud::RelatedContentAccess>");
    qRegisterMetaType<std::optional<RelatedContentImage>>("std::optional<qevercloud::RelatedContentImage>");
    qRegisterMetaType<std::optional<RelatedContentType>>("std::optional<qevercloud::RelatedContentType>");
    qRegisterMetaType<std::optional<ReminderEmailConfig>>("std::optional<qevercloud::ReminderEmailConfig>");
    qRegisterMetaType<std::optional<Resource>>("std::optional<qevercloud::Resource>");
    qRegisterMetaType<std::optional<ResourceAttributes>>("std::optional<qevercloud::ResourceAttributes>");
    qRegisterMetaType<std::optional<SavedSearch>>("std::optional<qevercloud::SavedSearch>");
    qRegisterMetaType<std::optional<SavedSearchScope>>("std::optional<qevercloud::SavedSearchScope>");
    qRegisterMetaType<std::optional<ServiceLevel>>("std::optional<qevercloud::ServiceLevel>");
    qRegisterMetaType<std::optional<ShareRelationshipPrivilegeLevel>>("std::optional<qevercloud::ShareRelationshipPrivilegeLevel>");
    qRegisterMetaType<std::optional<ShareRelationshipRestrictions>>("std::optional<qevercloud::ShareRelationshipRestrictions>");
    qRegisterMetaType<std::optional<SharedNote>>("std::optional<qevercloud::SharedNote>");
    qRegisterMetaType<std::optional<SharedNotePrivilegeLevel>>("std::optional<qevercloud::SharedNotePrivilegeLevel>");
    qRegisterMetaType<std::optional<SharedNotebook>>("std::optional<qevercloud::SharedNotebook>");
    qRegisterMetaType<std::optional<SharedNotebookInstanceRestrictions>>("std::optional<qevercloud::SharedNotebookInstanceRestrictions>");
    qRegisterMetaType<std::optional<SharedNotebookPrivilegeLevel>>("std::optional<qevercloud::SharedNotebookPrivilegeLevel>");
    qRegisterMetaType<std::optional<SharedNotebookRecipientSettings>>("std::optional<qevercloud::SharedNotebookRecipientSettings>");
    qRegisterMetaType<std::optional<Tag>>("std::optional<qevercloud::Tag>");
    qRegisterMetaType<std::optional<User>>("std::optional<qevercloud::User>");
    qRegisterMetaType<std::optional<UserAttributes>>("std::optional<qevercloud::UserAttributes>");
    qRegisterMetaType<std::optional<UserIdentity>>("std::optional<qevercloud::UserIdentity>");
    qRegisterMetaType<std::optional<UserIdentityType>>("std::optional<qevercloud::UserIdentityType>");
    qRegisterMetaType<std::optional<UserProfile>>("std::optional<qevercloud::UserProfile>");
    qRegisterMetaType<std::optional<UserUrls>>("std::optional<qevercloud::UserUrls>");
    qRegisterMetaType<std::optional<bool>>("std::optional<bool>");
    qRegisterMetaType<std::optional<double>>("std::optional<double>");
    qRegisterMetaType<std::optional<qint16>>("std::optional<qint16>");
    qRegisterMetaType<std::optional<qint32>>("std::optional<qint32>");
    qRegisterMetaType<std::optional<qint64>>("std::optional<qint64>");
}

} // namespace qevercloud
