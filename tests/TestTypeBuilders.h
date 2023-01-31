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

#ifndef QEVERCLOUD_GENERATED_TESTTYPEBUILDERS
#define QEVERCLOUD_GENERATED_TESTTYPEBUILDERS

#include <QObject>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class TypeBuildersTester: public QObject
{
    Q_OBJECT
public:
    explicit TypeBuildersTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldBuildSyncState();
    void shouldBuildSyncChunk();
    void shouldBuildSyncChunkFilter();
    void shouldBuildNoteFilter();
    void shouldBuildNoteList();
    void shouldBuildNoteMetadata();
    void shouldBuildNotesMetadataList();
    void shouldBuildNotesMetadataResultSpec();
    void shouldBuildNoteCollectionCounts();
    void shouldBuildNoteResultSpec();
    void shouldBuildNoteEmailParameters();
    void shouldBuildNoteVersionId();
    void shouldBuildRelatedQuery();
    void shouldBuildRelatedResult();
    void shouldBuildRelatedResultSpec();
    void shouldBuildUpdateNoteIfUsnMatchesResult();
    void shouldBuildShareRelationshipRestrictions();
    void shouldBuildInvitationShareRelationship();
    void shouldBuildMemberShareRelationship();
    void shouldBuildShareRelationships();
    void shouldBuildManageNotebookSharesParameters();
    void shouldBuildManageNotebookSharesError();
    void shouldBuildManageNotebookSharesResult();
    void shouldBuildSharedNoteTemplate();
    void shouldBuildNotebookShareTemplate();
    void shouldBuildCreateOrUpdateNotebookSharesResult();
    void shouldBuildNoteShareRelationshipRestrictions();
    void shouldBuildNoteMemberShareRelationship();
    void shouldBuildNoteInvitationShareRelationship();
    void shouldBuildNoteShareRelationships();
    void shouldBuildManageNoteSharesParameters();
    void shouldBuildManageNoteSharesError();
    void shouldBuildManageNoteSharesResult();
    void shouldBuildData();
    void shouldBuildUserAttributes();
    void shouldBuildBusinessUserAttributes();
    void shouldBuildAccounting();
    void shouldBuildBusinessUserInfo();
    void shouldBuildAccountLimits();
    void shouldBuildUser();
    void shouldBuildContact();
    void shouldBuildIdentity();
    void shouldBuildTag();
    void shouldBuildLazyMap();
    void shouldBuildResourceAttributes();
    void shouldBuildResource();
    void shouldBuildNoteAttributes();
    void shouldBuildSharedNote();
    void shouldBuildNoteRestrictions();
    void shouldBuildNoteLimits();
    void shouldBuildNote();
    void shouldBuildPublishing();
    void shouldBuildBusinessNotebook();
    void shouldBuildSavedSearchScope();
    void shouldBuildSavedSearch();
    void shouldBuildSharedNotebookRecipientSettings();
    void shouldBuildNotebookRecipientSettings();
    void shouldBuildSharedNotebook();
    void shouldBuildCanMoveToContainerRestrictions();
    void shouldBuildNotebookRestrictions();
    void shouldBuildNotebook();
    void shouldBuildLinkedNotebook();
    void shouldBuildNotebookDescriptor();
    void shouldBuildUserProfile();
    void shouldBuildRelatedContentImage();
    void shouldBuildRelatedContent();
    void shouldBuildBusinessInvitation();
    void shouldBuildUserIdentity();
    void shouldBuildPublicUserInfo();
    void shouldBuildUserUrls();
    void shouldBuildAuthenticationResult();
    void shouldBuildBootstrapSettings();
    void shouldBuildBootstrapProfile();
    void shouldBuildBootstrapInfo();

    void shouldBuildEDAMUserException();
    void shouldBuildEDAMSystemException();
    void shouldBuildEDAMNotFoundException();
    void shouldBuildEDAMInvalidContactsException();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTTYPEBUILDERS
