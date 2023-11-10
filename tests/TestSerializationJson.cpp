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

#include "TestSerializationJson.h"
#include "../src/Impl.h"
#include "RandomDataGenerators.h"
#include <qevercloud/serialization/json/AccountLimits.h>
#include <qevercloud/serialization/json/Accounting.h>
#include <qevercloud/serialization/json/AuthenticationResult.h>
#include <qevercloud/serialization/json/BootstrapInfo.h>
#include <qevercloud/serialization/json/BootstrapProfile.h>
#include <qevercloud/serialization/json/BootstrapSettings.h>
#include <qevercloud/serialization/json/BusinessInvitation.h>
#include <qevercloud/serialization/json/BusinessNotebook.h>
#include <qevercloud/serialization/json/BusinessUserAttributes.h>
#include <qevercloud/serialization/json/BusinessUserInfo.h>
#include <qevercloud/serialization/json/CanMoveToContainerRestrictions.h>
#include <qevercloud/serialization/json/Contact.h>
#include <qevercloud/serialization/json/CreateOrUpdateNotebookSharesResult.h>
#include <qevercloud/serialization/json/Data.h>
#include <qevercloud/serialization/json/EDAMInvalidContactsException.h>
#include <qevercloud/serialization/json/EDAMNotFoundException.h>
#include <qevercloud/serialization/json/EDAMSystemException.h>
#include <qevercloud/serialization/json/EDAMUserException.h>
#include <qevercloud/serialization/json/Identity.h>
#include <qevercloud/serialization/json/InvitationShareRelationship.h>
#include <qevercloud/serialization/json/LazyMap.h>
#include <qevercloud/serialization/json/LinkedNotebook.h>
#include <qevercloud/serialization/json/ManageNoteSharesError.h>
#include <qevercloud/serialization/json/ManageNoteSharesParameters.h>
#include <qevercloud/serialization/json/ManageNoteSharesResult.h>
#include <qevercloud/serialization/json/ManageNotebookSharesError.h>
#include <qevercloud/serialization/json/ManageNotebookSharesParameters.h>
#include <qevercloud/serialization/json/ManageNotebookSharesResult.h>
#include <qevercloud/serialization/json/MemberShareRelationship.h>
#include <qevercloud/serialization/json/Note.h>
#include <qevercloud/serialization/json/NoteAttributes.h>
#include <qevercloud/serialization/json/NoteCollectionCounts.h>
#include <qevercloud/serialization/json/NoteEmailParameters.h>
#include <qevercloud/serialization/json/NoteFilter.h>
#include <qevercloud/serialization/json/NoteInvitationShareRelationship.h>
#include <qevercloud/serialization/json/NoteLimits.h>
#include <qevercloud/serialization/json/NoteList.h>
#include <qevercloud/serialization/json/NoteMemberShareRelationship.h>
#include <qevercloud/serialization/json/NoteMetadata.h>
#include <qevercloud/serialization/json/NoteRestrictions.h>
#include <qevercloud/serialization/json/NoteResultSpec.h>
#include <qevercloud/serialization/json/NoteShareRelationshipRestrictions.h>
#include <qevercloud/serialization/json/NoteShareRelationships.h>
#include <qevercloud/serialization/json/NoteVersionId.h>
#include <qevercloud/serialization/json/Notebook.h>
#include <qevercloud/serialization/json/NotebookDescriptor.h>
#include <qevercloud/serialization/json/NotebookRecipientSettings.h>
#include <qevercloud/serialization/json/NotebookRestrictions.h>
#include <qevercloud/serialization/json/NotebookShareTemplate.h>
#include <qevercloud/serialization/json/NotesMetadataList.h>
#include <qevercloud/serialization/json/NotesMetadataResultSpec.h>
#include <qevercloud/serialization/json/PublicUserInfo.h>
#include <qevercloud/serialization/json/Publishing.h>
#include <qevercloud/serialization/json/RelatedContent.h>
#include <qevercloud/serialization/json/RelatedContentImage.h>
#include <qevercloud/serialization/json/RelatedQuery.h>
#include <qevercloud/serialization/json/RelatedResult.h>
#include <qevercloud/serialization/json/RelatedResultSpec.h>
#include <qevercloud/serialization/json/Resource.h>
#include <qevercloud/serialization/json/ResourceAttributes.h>
#include <qevercloud/serialization/json/SavedSearch.h>
#include <qevercloud/serialization/json/SavedSearchScope.h>
#include <qevercloud/serialization/json/ShareRelationshipRestrictions.h>
#include <qevercloud/serialization/json/ShareRelationships.h>
#include <qevercloud/serialization/json/SharedNote.h>
#include <qevercloud/serialization/json/SharedNoteTemplate.h>
#include <qevercloud/serialization/json/SharedNotebook.h>
#include <qevercloud/serialization/json/SharedNotebookRecipientSettings.h>
#include <qevercloud/serialization/json/SyncChunk.h>
#include <qevercloud/serialization/json/SyncChunkFilter.h>
#include <qevercloud/serialization/json/SyncState.h>
#include <qevercloud/serialization/json/Tag.h>
#include <qevercloud/serialization/json/UpdateNoteIfUsnMatchesResult.h>
#include <qevercloud/serialization/json/User.h>
#include <qevercloud/serialization/json/UserAttributes.h>
#include <qevercloud/serialization/json/UserIdentity.h>
#include <qevercloud/serialization/json/UserProfile.h>
#include <qevercloud/serialization/json/UserUrls.h>
#include <QJsonDocument>
#include <QTest>

namespace qevercloud {

SerializationJsonTester::SerializationJsonTester(QObject * parent) :
    QObject(parent)
{}

void SerializationJsonTester::shouldSerializeAndDeserializeAccounting()
{
    const auto original = generateRandomAccounting();
    const auto object = serializeToJson(original);
    Accounting deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeAccountLimits()
{
    const auto original = generateRandomAccountLimits();
    const auto object = serializeToJson(original);
    AccountLimits deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeAuthenticationResult()
{
    const auto original = generateRandomAuthenticationResult();
    const auto object = serializeToJson(original);
    AuthenticationResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBootstrapInfo()
{
    const auto original = generateRandomBootstrapInfo();
    const auto object = serializeToJson(original);
    BootstrapInfo deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBootstrapProfile()
{
    const auto original = generateRandomBootstrapProfile();
    const auto object = serializeToJson(original);
    BootstrapProfile deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBootstrapSettings()
{
    const auto original = generateRandomBootstrapSettings();
    const auto object = serializeToJson(original);
    BootstrapSettings deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBusinessInvitation()
{
    const auto original = generateRandomBusinessInvitation();
    const auto object = serializeToJson(original);
    BusinessInvitation deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBusinessNotebook()
{
    const auto original = generateRandomBusinessNotebook();
    const auto object = serializeToJson(original);
    BusinessNotebook deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBusinessUserAttributes()
{
    const auto original = generateRandomBusinessUserAttributes();
    const auto object = serializeToJson(original);
    BusinessUserAttributes deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeBusinessUserInfo()
{
    const auto original = generateRandomBusinessUserInfo();
    const auto object = serializeToJson(original);
    BusinessUserInfo deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeCanMoveToContainerRestrictions()
{
    const auto original = generateRandomCanMoveToContainerRestrictions();
    const auto object = serializeToJson(original);
    CanMoveToContainerRestrictions deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeContact()
{
    const auto original = generateRandomContact();
    const auto object = serializeToJson(original);
    Contact deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeCreateOrUpdateNotebookSharesResult()
{
    const auto original = generateRandomCreateOrUpdateNotebookSharesResult();
    const auto object = serializeToJson(original);
    CreateOrUpdateNotebookSharesResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeData()
{
    const auto original = generateRandomData();
    const auto object = serializeToJson(original);
    Data deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeEDAMInvalidContactsException()
{
    const auto original = generateRandomEDAMInvalidContactsException();
    const auto object = serializeToJson(original);
    EDAMInvalidContactsException deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeEDAMNotFoundException()
{
    const auto original = generateRandomEDAMNotFoundException();
    const auto object = serializeToJson(original);
    EDAMNotFoundException deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeEDAMSystemException()
{
    const auto original = generateRandomEDAMSystemException();
    const auto object = serializeToJson(original);
    EDAMSystemException deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeEDAMUserException()
{
    const auto original = generateRandomEDAMUserException();
    const auto object = serializeToJson(original);
    EDAMUserException deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeIdentity()
{
    const auto original = generateRandomIdentity();
    const auto object = serializeToJson(original);
    Identity deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeInvitationShareRelationship()
{
    const auto original = generateRandomInvitationShareRelationship();
    const auto object = serializeToJson(original);
    InvitationShareRelationship deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeLazyMap()
{
    const auto original = generateRandomLazyMap();
    const auto object = serializeToJson(original);
    LazyMap deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeLinkedNotebook()
{
    const auto original = generateRandomLinkedNotebook();
    const auto object = serializeToJson(original);
    LinkedNotebook deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNotebookSharesError()
{
    const auto original = generateRandomManageNotebookSharesError();
    const auto object = serializeToJson(original);
    ManageNotebookSharesError deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNotebookSharesParameters()
{
    const auto original = generateRandomManageNotebookSharesParameters();
    const auto object = serializeToJson(original);
    ManageNotebookSharesParameters deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNotebookSharesResult()
{
    const auto original = generateRandomManageNotebookSharesResult();
    const auto object = serializeToJson(original);
    ManageNotebookSharesResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNoteSharesError()
{
    const auto original = generateRandomManageNoteSharesError();
    const auto object = serializeToJson(original);
    ManageNoteSharesError deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNoteSharesParameters()
{
    const auto original = generateRandomManageNoteSharesParameters();
    const auto object = serializeToJson(original);
    ManageNoteSharesParameters deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeManageNoteSharesResult()
{
    const auto original = generateRandomManageNoteSharesResult();
    const auto object = serializeToJson(original);
    ManageNoteSharesResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeMemberShareRelationship()
{
    const auto original = generateRandomMemberShareRelationship();
    const auto object = serializeToJson(original);
    MemberShareRelationship deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNote()
{
    const auto original = generateRandomNote();
    const auto object = serializeToJson(original);
    Note deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteAttributes()
{
    const auto original = generateRandomNoteAttributes();
    const auto object = serializeToJson(original);
    NoteAttributes deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotebook()
{
    const auto original = generateRandomNotebook();
    const auto object = serializeToJson(original);
    Notebook deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotebookDescriptor()
{
    const auto original = generateRandomNotebookDescriptor();
    const auto object = serializeToJson(original);
    NotebookDescriptor deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotebookRecipientSettings()
{
    const auto original = generateRandomNotebookRecipientSettings();
    const auto object = serializeToJson(original);
    NotebookRecipientSettings deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotebookRestrictions()
{
    const auto original = generateRandomNotebookRestrictions();
    const auto object = serializeToJson(original);
    NotebookRestrictions deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotebookShareTemplate()
{
    const auto original = generateRandomNotebookShareTemplate();
    const auto object = serializeToJson(original);
    NotebookShareTemplate deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteCollectionCounts()
{
    const auto original = generateRandomNoteCollectionCounts();
    const auto object = serializeToJson(original);
    NoteCollectionCounts deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteEmailParameters()
{
    const auto original = generateRandomNoteEmailParameters();
    const auto object = serializeToJson(original);
    NoteEmailParameters deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteFilter()
{
    const auto original = generateRandomNoteFilter();
    const auto object = serializeToJson(original);
    NoteFilter deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteInvitationShareRelationship()
{
    const auto original = generateRandomNoteInvitationShareRelationship();
    const auto object = serializeToJson(original);
    NoteInvitationShareRelationship deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteLimits()
{
    const auto original = generateRandomNoteLimits();
    const auto object = serializeToJson(original);
    NoteLimits deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteList()
{
    const auto original = generateRandomNoteList();
    const auto object = serializeToJson(original);
    NoteList deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteMemberShareRelationship()
{
    const auto original = generateRandomNoteMemberShareRelationship();
    const auto object = serializeToJson(original);
    NoteMemberShareRelationship deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteMetadata()
{
    const auto original = generateRandomNoteMetadata();
    const auto object = serializeToJson(original);
    NoteMetadata deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteRestrictions()
{
    const auto original = generateRandomNoteRestrictions();
    const auto object = serializeToJson(original);
    NoteRestrictions deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteResultSpec()
{
    const auto original = generateRandomNoteResultSpec();
    const auto object = serializeToJson(original);
    NoteResultSpec deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteShareRelationshipRestrictions()
{
    const auto original = generateRandomNoteShareRelationshipRestrictions();
    const auto object = serializeToJson(original);
    NoteShareRelationshipRestrictions deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteShareRelationships()
{
    const auto original = generateRandomNoteShareRelationships();
    const auto object = serializeToJson(original);
    NoteShareRelationships deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotesMetadataList()
{
    const auto original = generateRandomNotesMetadataList();
    const auto object = serializeToJson(original);
    NotesMetadataList deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNotesMetadataResultSpec()
{
    const auto original = generateRandomNotesMetadataResultSpec();
    const auto object = serializeToJson(original);
    NotesMetadataResultSpec deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeNoteVersionId()
{
    const auto original = generateRandomNoteVersionId();
    const auto object = serializeToJson(original);
    NoteVersionId deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializePublicUserInfo()
{
    const auto original = generateRandomPublicUserInfo();
    const auto object = serializeToJson(original);
    PublicUserInfo deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializePublishing()
{
    const auto original = generateRandomPublishing();
    const auto object = serializeToJson(original);
    Publishing deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeRelatedContent()
{
    const auto original = generateRandomRelatedContent();
    const auto object = serializeToJson(original);
    RelatedContent deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeRelatedContentImage()
{
    const auto original = generateRandomRelatedContentImage();
    const auto object = serializeToJson(original);
    RelatedContentImage deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeRelatedQuery()
{
    const auto original = generateRandomRelatedQuery();
    const auto object = serializeToJson(original);
    RelatedQuery deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeRelatedResult()
{
    const auto original = generateRandomRelatedResult();
    const auto object = serializeToJson(original);
    RelatedResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeRelatedResultSpec()
{
    const auto original = generateRandomRelatedResultSpec();
    const auto object = serializeToJson(original);
    RelatedResultSpec deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeResource()
{
    const auto original = generateRandomResource();
    const auto object = serializeToJson(original);
    Resource deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeResourceAttributes()
{
    const auto original = generateRandomResourceAttributes();
    const auto object = serializeToJson(original);
    ResourceAttributes deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSavedSearch()
{
    const auto original = generateRandomSavedSearch();
    const auto object = serializeToJson(original);
    SavedSearch deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSavedSearchScope()
{
    const auto original = generateRandomSavedSearchScope();
    const auto object = serializeToJson(original);
    SavedSearchScope deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSharedNote()
{
    const auto original = generateRandomSharedNote();
    const auto object = serializeToJson(original);
    SharedNote deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSharedNotebook()
{
    const auto original = generateRandomSharedNotebook();
    const auto object = serializeToJson(original);
    SharedNotebook deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSharedNotebookRecipientSettings()
{
    const auto original = generateRandomSharedNotebookRecipientSettings();
    const auto object = serializeToJson(original);
    SharedNotebookRecipientSettings deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSharedNoteTemplate()
{
    const auto original = generateRandomSharedNoteTemplate();
    const auto object = serializeToJson(original);
    SharedNoteTemplate deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeShareRelationshipRestrictions()
{
    const auto original = generateRandomShareRelationshipRestrictions();
    const auto object = serializeToJson(original);
    ShareRelationshipRestrictions deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeShareRelationships()
{
    const auto original = generateRandomShareRelationships();
    const auto object = serializeToJson(original);
    ShareRelationships deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSyncChunk()
{
    const auto original = generateRandomSyncChunk();
    const auto object = serializeToJson(original);
    SyncChunk deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSyncChunkFilter()
{
    const auto original = generateRandomSyncChunkFilter();
    const auto object = serializeToJson(original);
    SyncChunkFilter deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeSyncState()
{
    const auto original = generateRandomSyncState();
    const auto object = serializeToJson(original);
    SyncState deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeTag()
{
    const auto original = generateRandomTag();
    const auto object = serializeToJson(original);
    Tag deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUpdateNoteIfUsnMatchesResult()
{
    const auto original = generateRandomUpdateNoteIfUsnMatchesResult();
    const auto object = serializeToJson(original);
    UpdateNoteIfUsnMatchesResult deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUser()
{
    const auto original = generateRandomUser();
    const auto object = serializeToJson(original);
    User deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUserAttributes()
{
    const auto original = generateRandomUserAttributes();
    const auto object = serializeToJson(original);
    UserAttributes deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUserIdentity()
{
    const auto original = generateRandomUserIdentity();
    const auto object = serializeToJson(original);
    UserIdentity deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUserProfile()
{
    const auto original = generateRandomUserProfile();
    const auto object = serializeToJson(original);
    UserProfile deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

void SerializationJsonTester::shouldSerializeAndDeserializeUserUrls()
{
    const auto original = generateRandomUserUrls();
    const auto object = serializeToJson(original);
    UserUrls deserialized;
    const bool res = deserializeFromJson(object, deserialized);
    if (deserialized != original) {
        qWarning() << "Serialization/deserialization failed: original = "
            << original << "\nDeserialized = " << deserialized
            << "\nJSON: "
            << QJsonDocument(object).toJson(QJsonDocument::Indented);
    }
    QVERIFY(deserialized == original);
}

} // namespace qevercloud
