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

#ifndef QEVERCLOUD_GENERATED_TESTSERIALIZATIONJSON
#define QEVERCLOUD_GENERATED_TESTSERIALIZATIONJSON

#include <QObject>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class SerializationJsonTester: public QObject
{
    Q_OBJECT
public:
    explicit SerializationJsonTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldSerializeAndDeserializeAccounting();
    void shouldSerializeAndDeserializeAccountLimits();
    void shouldSerializeAndDeserializeAuthenticationResult();
    void shouldSerializeAndDeserializeBootstrapInfo();
    void shouldSerializeAndDeserializeBootstrapProfile();
    void shouldSerializeAndDeserializeBootstrapSettings();
    void shouldSerializeAndDeserializeBusinessInvitation();
    void shouldSerializeAndDeserializeBusinessNotebook();
    void shouldSerializeAndDeserializeBusinessUserAttributes();
    void shouldSerializeAndDeserializeBusinessUserInfo();
    void shouldSerializeAndDeserializeCanMoveToContainerRestrictions();
    void shouldSerializeAndDeserializeContact();
    void shouldSerializeAndDeserializeCreateOrUpdateNotebookSharesResult();
    void shouldSerializeAndDeserializeData();
    void shouldSerializeAndDeserializeEDAMInvalidContactsException();
    void shouldSerializeAndDeserializeEDAMNotFoundException();
    void shouldSerializeAndDeserializeEDAMSystemException();
    void shouldSerializeAndDeserializeEDAMUserException();
    void shouldSerializeAndDeserializeIdentity();
    void shouldSerializeAndDeserializeInvitationShareRelationship();
    void shouldSerializeAndDeserializeLazyMap();
    void shouldSerializeAndDeserializeLinkedNotebook();
    void shouldSerializeAndDeserializeManageNotebookSharesError();
    void shouldSerializeAndDeserializeManageNotebookSharesParameters();
    void shouldSerializeAndDeserializeManageNotebookSharesResult();
    void shouldSerializeAndDeserializeManageNoteSharesError();
    void shouldSerializeAndDeserializeManageNoteSharesParameters();
    void shouldSerializeAndDeserializeManageNoteSharesResult();
    void shouldSerializeAndDeserializeMemberShareRelationship();
    void shouldSerializeAndDeserializeNote();
    void shouldSerializeAndDeserializeNoteAttributes();
    void shouldSerializeAndDeserializeNotebook();
    void shouldSerializeAndDeserializeNotebookDescriptor();
    void shouldSerializeAndDeserializeNotebookRecipientSettings();
    void shouldSerializeAndDeserializeNotebookRestrictions();
    void shouldSerializeAndDeserializeNotebookShareTemplate();
    void shouldSerializeAndDeserializeNoteCollectionCounts();
    void shouldSerializeAndDeserializeNoteEmailParameters();
    void shouldSerializeAndDeserializeNoteFilter();
    void shouldSerializeAndDeserializeNoteInvitationShareRelationship();
    void shouldSerializeAndDeserializeNoteLimits();
    void shouldSerializeAndDeserializeNoteList();
    void shouldSerializeAndDeserializeNoteMemberShareRelationship();
    void shouldSerializeAndDeserializeNoteMetadata();
    void shouldSerializeAndDeserializeNoteRestrictions();
    void shouldSerializeAndDeserializeNoteResultSpec();
    void shouldSerializeAndDeserializeNoteShareRelationshipRestrictions();
    void shouldSerializeAndDeserializeNoteShareRelationships();
    void shouldSerializeAndDeserializeNotesMetadataList();
    void shouldSerializeAndDeserializeNotesMetadataResultSpec();
    void shouldSerializeAndDeserializeNoteVersionId();
    void shouldSerializeAndDeserializePublicUserInfo();
    void shouldSerializeAndDeserializePublishing();
    void shouldSerializeAndDeserializeRelatedContent();
    void shouldSerializeAndDeserializeRelatedContentImage();
    void shouldSerializeAndDeserializeRelatedQuery();
    void shouldSerializeAndDeserializeRelatedResult();
    void shouldSerializeAndDeserializeRelatedResultSpec();
    void shouldSerializeAndDeserializeResource();
    void shouldSerializeAndDeserializeResourceAttributes();
    void shouldSerializeAndDeserializeSavedSearch();
    void shouldSerializeAndDeserializeSavedSearchScope();
    void shouldSerializeAndDeserializeSharedNote();
    void shouldSerializeAndDeserializeSharedNotebook();
    void shouldSerializeAndDeserializeSharedNotebookRecipientSettings();
    void shouldSerializeAndDeserializeSharedNoteTemplate();
    void shouldSerializeAndDeserializeShareRelationshipRestrictions();
    void shouldSerializeAndDeserializeShareRelationships();
    void shouldSerializeAndDeserializeSyncChunk();
    void shouldSerializeAndDeserializeSyncChunkFilter();
    void shouldSerializeAndDeserializeSyncState();
    void shouldSerializeAndDeserializeTag();
    void shouldSerializeAndDeserializeUpdateNoteIfUsnMatchesResult();
    void shouldSerializeAndDeserializeUser();
    void shouldSerializeAndDeserializeUserAttributes();
    void shouldSerializeAndDeserializeUserIdentity();
    void shouldSerializeAndDeserializeUserProfile();
    void shouldSerializeAndDeserializeUserUrls();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTSERIALIZATIONJSON
