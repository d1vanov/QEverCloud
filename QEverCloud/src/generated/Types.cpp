/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/Types.h>
#include "../Impl.h"
#include "Types_io.h"
#include <Helpers.h>
#include <QDebug>
#include <QUuid>
#include <optional>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/** @cond HIDDEN_SYMBOLS  */

void readEnumEDAMErrorCode(
    ThriftBinaryBufferReader & reader,
    EDAMErrorCode & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMErrorCode::UNKNOWN): e = EDAMErrorCode::UNKNOWN; break;
    case static_cast<int>(EDAMErrorCode::BAD_DATA_FORMAT): e = EDAMErrorCode::BAD_DATA_FORMAT; break;
    case static_cast<int>(EDAMErrorCode::PERMISSION_DENIED): e = EDAMErrorCode::PERMISSION_DENIED; break;
    case static_cast<int>(EDAMErrorCode::INTERNAL_ERROR): e = EDAMErrorCode::INTERNAL_ERROR; break;
    case static_cast<int>(EDAMErrorCode::DATA_REQUIRED): e = EDAMErrorCode::DATA_REQUIRED; break;
    case static_cast<int>(EDAMErrorCode::LIMIT_REACHED): e = EDAMErrorCode::LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::QUOTA_REACHED): e = EDAMErrorCode::QUOTA_REACHED; break;
    case static_cast<int>(EDAMErrorCode::INVALID_AUTH): e = EDAMErrorCode::INVALID_AUTH; break;
    case static_cast<int>(EDAMErrorCode::AUTH_EXPIRED): e = EDAMErrorCode::AUTH_EXPIRED; break;
    case static_cast<int>(EDAMErrorCode::DATA_CONFLICT): e = EDAMErrorCode::DATA_CONFLICT; break;
    case static_cast<int>(EDAMErrorCode::ENML_VALIDATION): e = EDAMErrorCode::ENML_VALIDATION; break;
    case static_cast<int>(EDAMErrorCode::SHARD_UNAVAILABLE): e = EDAMErrorCode::SHARD_UNAVAILABLE; break;
    case static_cast<int>(EDAMErrorCode::LEN_TOO_SHORT): e = EDAMErrorCode::LEN_TOO_SHORT; break;
    case static_cast<int>(EDAMErrorCode::LEN_TOO_LONG): e = EDAMErrorCode::LEN_TOO_LONG; break;
    case static_cast<int>(EDAMErrorCode::TOO_FEW): e = EDAMErrorCode::TOO_FEW; break;
    case static_cast<int>(EDAMErrorCode::TOO_MANY): e = EDAMErrorCode::TOO_MANY; break;
    case static_cast<int>(EDAMErrorCode::UNSUPPORTED_OPERATION): e = EDAMErrorCode::UNSUPPORTED_OPERATION; break;
    case static_cast<int>(EDAMErrorCode::TAKEN_DOWN): e = EDAMErrorCode::TAKEN_DOWN; break;
    case static_cast<int>(EDAMErrorCode::RATE_LIMIT_REACHED): e = EDAMErrorCode::RATE_LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED): e = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED; break;
    case static_cast<int>(EDAMErrorCode::DEVICE_LIMIT_REACHED): e = EDAMErrorCode::DEVICE_LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::OPENID_ALREADY_TAKEN): e = EDAMErrorCode::OPENID_ALREADY_TAKEN; break;
    case static_cast<int>(EDAMErrorCode::INVALID_OPENID_TOKEN): e = EDAMErrorCode::INVALID_OPENID_TOKEN; break;
    case static_cast<int>(EDAMErrorCode::USER_NOT_ASSOCIATED): e = EDAMErrorCode::USER_NOT_ASSOCIATED; break;
    case static_cast<int>(EDAMErrorCode::USER_NOT_REGISTERED): e = EDAMErrorCode::USER_NOT_REGISTERED; break;
    case static_cast<int>(EDAMErrorCode::USER_ALREADY_ASSOCIATED): e = EDAMErrorCode::USER_ALREADY_ASSOCIATED; break;
    case static_cast<int>(EDAMErrorCode::ACCOUNT_CLEAR): e = EDAMErrorCode::ACCOUNT_CLEAR; break;
    case static_cast<int>(EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED): e = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMErrorCode"));
    }
}

void readEnumEDAMInvalidContactReason(
    ThriftBinaryBufferReader & reader,
    EDAMInvalidContactReason & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMInvalidContactReason::BAD_ADDRESS): e = EDAMInvalidContactReason::BAD_ADDRESS; break;
    case static_cast<int>(EDAMInvalidContactReason::DUPLICATE_CONTACT): e = EDAMInvalidContactReason::DUPLICATE_CONTACT; break;
    case static_cast<int>(EDAMInvalidContactReason::NO_CONNECTION): e = EDAMInvalidContactReason::NO_CONNECTION; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMInvalidContactReason"));
    }
}

void readEnumShareRelationshipPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    ShareRelationshipPrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::FULL_ACCESS): e = ShareRelationshipPrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ShareRelationshipPrivilegeLevel"));
    }
}

void readEnumPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    PrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(PrivilegeLevel::NORMAL): e = PrivilegeLevel::NORMAL; break;
    case static_cast<int>(PrivilegeLevel::PREMIUM): e = PrivilegeLevel::PREMIUM; break;
    case static_cast<int>(PrivilegeLevel::VIP): e = PrivilegeLevel::VIP; break;
    case static_cast<int>(PrivilegeLevel::MANAGER): e = PrivilegeLevel::MANAGER; break;
    case static_cast<int>(PrivilegeLevel::SUPPORT): e = PrivilegeLevel::SUPPORT; break;
    case static_cast<int>(PrivilegeLevel::ADMIN): e = PrivilegeLevel::ADMIN; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum PrivilegeLevel"));
    }
}

void readEnumServiceLevel(
    ThriftBinaryBufferReader & reader,
    ServiceLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ServiceLevel::BASIC): e = ServiceLevel::BASIC; break;
    case static_cast<int>(ServiceLevel::PLUS): e = ServiceLevel::PLUS; break;
    case static_cast<int>(ServiceLevel::PREMIUM): e = ServiceLevel::PREMIUM; break;
    case static_cast<int>(ServiceLevel::BUSINESS): e = ServiceLevel::BUSINESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ServiceLevel"));
    }
}

void readEnumQueryFormat(
    ThriftBinaryBufferReader & reader,
    QueryFormat & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(QueryFormat::USER): e = QueryFormat::USER; break;
    case static_cast<int>(QueryFormat::SEXP): e = QueryFormat::SEXP; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum QueryFormat"));
    }
}

void readEnumNoteSortOrder(
    ThriftBinaryBufferReader & reader,
    NoteSortOrder & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(NoteSortOrder::CREATED): e = NoteSortOrder::CREATED; break;
    case static_cast<int>(NoteSortOrder::UPDATED): e = NoteSortOrder::UPDATED; break;
    case static_cast<int>(NoteSortOrder::RELEVANCE): e = NoteSortOrder::RELEVANCE; break;
    case static_cast<int>(NoteSortOrder::UPDATE_SEQUENCE_NUMBER): e = NoteSortOrder::UPDATE_SEQUENCE_NUMBER; break;
    case static_cast<int>(NoteSortOrder::TITLE): e = NoteSortOrder::TITLE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum NoteSortOrder"));
    }
}

void readEnumPremiumOrderStatus(
    ThriftBinaryBufferReader & reader,
    PremiumOrderStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(PremiumOrderStatus::NONE): e = PremiumOrderStatus::NONE; break;
    case static_cast<int>(PremiumOrderStatus::PENDING): e = PremiumOrderStatus::PENDING; break;
    case static_cast<int>(PremiumOrderStatus::ACTIVE): e = PremiumOrderStatus::ACTIVE; break;
    case static_cast<int>(PremiumOrderStatus::FAILED): e = PremiumOrderStatus::FAILED; break;
    case static_cast<int>(PremiumOrderStatus::CANCELLATION_PENDING): e = PremiumOrderStatus::CANCELLATION_PENDING; break;
    case static_cast<int>(PremiumOrderStatus::CANCELED): e = PremiumOrderStatus::CANCELED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum PremiumOrderStatus"));
    }
}

void readEnumSharedNotebookPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    SharedNotebookPrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK): e = SharedNotebookPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::GROUP): e = SharedNotebookPrivilegeLevel::GROUP; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::FULL_ACCESS): e = SharedNotebookPrivilegeLevel::FULL_ACCESS; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS): e = SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookPrivilegeLevel"));
    }
}

void readEnumSharedNotePrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    SharedNotePrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotePrivilegeLevel::READ_NOTE): e = SharedNotePrivilegeLevel::READ_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::MODIFY_NOTE): e = SharedNotePrivilegeLevel::MODIFY_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::FULL_ACCESS): e = SharedNotePrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotePrivilegeLevel"));
    }
}

void readEnumSponsoredGroupRole(
    ThriftBinaryBufferReader & reader,
    SponsoredGroupRole & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SponsoredGroupRole::GROUP_MEMBER): e = SponsoredGroupRole::GROUP_MEMBER; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_ADMIN): e = SponsoredGroupRole::GROUP_ADMIN; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_OWNER): e = SponsoredGroupRole::GROUP_OWNER; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SponsoredGroupRole"));
    }
}

void readEnumBusinessUserRole(
    ThriftBinaryBufferReader & reader,
    BusinessUserRole & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserRole::ADMIN): e = BusinessUserRole::ADMIN; break;
    case static_cast<int>(BusinessUserRole::NORMAL): e = BusinessUserRole::NORMAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserRole"));
    }
}

void readEnumBusinessUserStatus(
    ThriftBinaryBufferReader & reader,
    BusinessUserStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserStatus::ACTIVE): e = BusinessUserStatus::ACTIVE; break;
    case static_cast<int>(BusinessUserStatus::DEACTIVATED): e = BusinessUserStatus::DEACTIVATED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserStatus"));
    }
}

void readEnumSharedNotebookInstanceRestrictions(
    ThriftBinaryBufferReader & reader,
    SharedNotebookInstanceRestrictions & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookInstanceRestrictions::ASSIGNED): e = SharedNotebookInstanceRestrictions::ASSIGNED; break;
    case static_cast<int>(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS): e = SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookInstanceRestrictions"));
    }
}

void readEnumReminderEmailConfig(
    ThriftBinaryBufferReader & reader,
    ReminderEmailConfig & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ReminderEmailConfig::DO_NOT_SEND): e = ReminderEmailConfig::DO_NOT_SEND; break;
    case static_cast<int>(ReminderEmailConfig::SEND_DAILY_EMAIL): e = ReminderEmailConfig::SEND_DAILY_EMAIL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ReminderEmailConfig"));
    }
}

void readEnumBusinessInvitationStatus(
    ThriftBinaryBufferReader & reader,
    BusinessInvitationStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessInvitationStatus::APPROVED): e = BusinessInvitationStatus::APPROVED; break;
    case static_cast<int>(BusinessInvitationStatus::REQUESTED): e = BusinessInvitationStatus::REQUESTED; break;
    case static_cast<int>(BusinessInvitationStatus::REDEEMED): e = BusinessInvitationStatus::REDEEMED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessInvitationStatus"));
    }
}

void readEnumContactType(
    ThriftBinaryBufferReader & reader,
    ContactType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ContactType::EVERNOTE): e = ContactType::EVERNOTE; break;
    case static_cast<int>(ContactType::SMS): e = ContactType::SMS; break;
    case static_cast<int>(ContactType::FACEBOOK): e = ContactType::FACEBOOK; break;
    case static_cast<int>(ContactType::EMAIL): e = ContactType::EMAIL; break;
    case static_cast<int>(ContactType::TWITTER): e = ContactType::TWITTER; break;
    case static_cast<int>(ContactType::LINKEDIN): e = ContactType::LINKEDIN; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ContactType"));
    }
}

void readEnumEntityType(
    ThriftBinaryBufferReader & reader,
    EntityType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EntityType::NOTE): e = EntityType::NOTE; break;
    case static_cast<int>(EntityType::NOTEBOOK): e = EntityType::NOTEBOOK; break;
    case static_cast<int>(EntityType::WORKSPACE): e = EntityType::WORKSPACE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EntityType"));
    }
}

void readEnumRecipientStatus(
    ThriftBinaryBufferReader & reader,
    RecipientStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RecipientStatus::NOT_IN_MY_LIST): e = RecipientStatus::NOT_IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST): e = RecipientStatus::IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK): e = RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RecipientStatus"));
    }
}

void readEnumCanMoveToContainerStatus(
    ThriftBinaryBufferReader & reader,
    CanMoveToContainerStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(CanMoveToContainerStatus::CAN_BE_MOVED): e = CanMoveToContainerStatus::CAN_BE_MOVED; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum CanMoveToContainerStatus"));
    }
}

void readEnumRelatedContentType(
    ThriftBinaryBufferReader & reader,
    RelatedContentType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentType::NEWS_ARTICLE): e = RelatedContentType::NEWS_ARTICLE; break;
    case static_cast<int>(RelatedContentType::PROFILE_PERSON): e = RelatedContentType::PROFILE_PERSON; break;
    case static_cast<int>(RelatedContentType::PROFILE_ORGANIZATION): e = RelatedContentType::PROFILE_ORGANIZATION; break;
    case static_cast<int>(RelatedContentType::REFERENCE_MATERIAL): e = RelatedContentType::REFERENCE_MATERIAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentType"));
    }
}

void readEnumRelatedContentAccess(
    ThriftBinaryBufferReader & reader,
    RelatedContentAccess & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentAccess::NOT_ACCESSIBLE): e = RelatedContentAccess::NOT_ACCESSIBLE; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_ACCESS_OK): e = RelatedContentAccess::DIRECT_LINK_ACCESS_OK; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED): e = RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW): e = RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentAccess"));
    }
}

void readEnumUserIdentityType(
    ThriftBinaryBufferReader & reader,
    UserIdentityType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(UserIdentityType::EVERNOTE_USERID): e = UserIdentityType::EVERNOTE_USERID; break;
    case static_cast<int>(UserIdentityType::EMAIL): e = UserIdentityType::EMAIL; break;
    case static_cast<int>(UserIdentityType::IDENTITYID): e = UserIdentityType::IDENTITYID; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum UserIdentityType"));
    }
}

void writeSyncState(
    ThriftBinaryBufferWriter & writer,
    const SyncState & s)
{
    writer.writeStructBegin(QStringLiteral("SyncState"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("fullSyncBefore"),
        ThriftFieldType::T_I64,
        2);

    writer.writeI64(s.fullSyncBefore());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(s.updateCount());
    writer.writeFieldEnd();

    if (s.uploaded()) {
        writer.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(*s.uploaded());
        writer.writeFieldEnd();
    }

    if (s.userLastUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("userLastUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.userLastUpdated());
        writer.writeFieldEnd();
    }

    if (s.userMaxMessageEventId()) {
        writer.writeFieldBegin(
            QStringLiteral("userMaxMessageEventId"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(*s.userMaxMessageEventId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncState(
    ThriftBinaryBufferReader & reader,
    SyncState & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool fullSyncBefore_isset = false;
    bool updateCount_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setCurrentTime(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                fullSyncBefore_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setFullSyncBefore(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setUpdateCount(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploaded(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUserLastUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                reader.readI64(v);
                s.setUserMaxMessageEventId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.currentTime has no value"));
    if (!fullSyncBefore_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.fullSyncBefore has no value"));
    if (!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.updateCount has no value"));
}

void writeSyncChunk(
    ThriftBinaryBufferWriter & writer,
    const SyncChunk & s)
{
    writer.writeStructBegin(QStringLiteral("SyncChunk"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime());
    writer.writeFieldEnd();

    if (s.chunkHighUSN()) {
        writer.writeFieldBegin(
            QStringLiteral("chunkHighUSN"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.chunkHighUSN());
        writer.writeFieldEnd();
    }

    writer.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(s.updateCount());
    writer.writeFieldEnd();

    if (s.notes()) {
        writer.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes()->length());
        for(const auto & value: qAsConst(*s.notes())) {
            writeNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.notebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks()->length());
        for(const auto & value: qAsConst(*s.notebooks())) {
            writeNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.tags()) {
        writer.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            6);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.tags()->length());
        for(const auto & value: qAsConst(*s.tags())) {
            writeTag(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searches()) {
        writer.writeFieldBegin(
            QStringLiteral("searches"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.searches()->length());
        for(const auto & value: qAsConst(*s.searches())) {
            writeSavedSearch(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.resources()) {
        writer.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            8);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.resources()->length());
        for(const auto & value: qAsConst(*s.resources())) {
            writeResource(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedNotes"),
            ThriftFieldType::T_LIST,
            9);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotes()->length());
        for(const auto & value: qAsConst(*s.expungedNotes())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedNotebooks"),
            ThriftFieldType::T_LIST,
            10);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotebooks()->length());
        for(const auto & value: qAsConst(*s.expungedNotebooks())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedTags()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedTags"),
            ThriftFieldType::T_LIST,
            11);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedTags()->length());
        for(const auto & value: qAsConst(*s.expungedTags())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedSearches()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedSearches"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedSearches()->length());
        for(const auto & value: qAsConst(*s.expungedSearches())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.linkedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("linkedNotebooks"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.linkedNotebooks()->length());
        for(const auto & value: qAsConst(*s.linkedNotebooks())) {
            writeLinkedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedLinkedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedLinkedNotebooks"),
            ThriftFieldType::T_LIST,
            14);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedLinkedNotebooks()->length());
        for(const auto & value: qAsConst(*s.expungedLinkedNotebooks())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncChunk(
    ThriftBinaryBufferReader & reader,
    SyncChunk & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool updateCount_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setCurrentTime(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setChunkHighUSN(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setUpdateCount(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.notebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.tags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SavedSearch> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.searches)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSearches(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.resources)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setResources(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedNotes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExpungedNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExpungedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedTags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExpungedTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedSearches)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExpungedSearches(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<LinkedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.linkedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setLinkedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedLinkedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExpungedLinkedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.currentTime has no value"));
    if (!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.updateCount has no value"));
}

void writeSyncChunkFilter(
    ThriftBinaryBufferWriter & writer,
    const SyncChunkFilter & s)
{
    writer.writeStructBegin(QStringLiteral("SyncChunkFilter"));
    if (s.includeNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotes"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.includeNotes());
        writer.writeFieldEnd();
    }

    if (s.includeNoteResources()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteResources"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.includeNoteResources());
        writer.writeFieldEnd();
    }

    if (s.includeNoteAttributes()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteAttributes"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.includeNoteAttributes());
        writer.writeFieldEnd();
    }

    if (s.includeNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotebooks"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.includeNotebooks());
        writer.writeFieldEnd();
    }

    if (s.includeTags()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTags"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.includeTags());
        writer.writeFieldEnd();
    }

    if (s.includeSearches()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSearches"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.includeSearches());
        writer.writeFieldEnd();
    }

    if (s.includeResources()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResources"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.includeResources());
        writer.writeFieldEnd();
    }

    if (s.includeLinkedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.includeLinkedNotebooks());
        writer.writeFieldEnd();
    }

    if (s.includeExpunged()) {
        writer.writeFieldBegin(
            QStringLiteral("includeExpunged"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(*s.includeExpunged());
        writer.writeFieldEnd();
    }

    if (s.includeNoteApplicationDataFullMap()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(*s.includeNoteApplicationDataFullMap());
        writer.writeFieldEnd();
    }

    if (s.includeResourceApplicationDataFullMap()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(*s.includeResourceApplicationDataFullMap());
        writer.writeFieldEnd();
    }

    if (s.includeNoteResourceApplicationDataFullMap()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(*s.includeNoteResourceApplicationDataFullMap());
        writer.writeFieldEnd();
    }

    if (s.includeSharedNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            17);

        writer.writeBool(*s.includeSharedNotes());
        writer.writeFieldEnd();
    }

    if (s.omitSharedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("omitSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(*s.omitSharedNotebooks());
        writer.writeFieldEnd();
    }

    if (s.requireNoteContentClass()) {
        writer.writeFieldBegin(
            QStringLiteral("requireNoteContentClass"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.requireNoteContentClass());
        writer.writeFieldEnd();
    }

    if (s.notebookGuids()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuids"),
            ThriftFieldType::T_SET,
            15);

        writer.writeSetBegin(ThriftFieldType::T_STRING, s.notebookGuids()->count());
        for(const auto & value: qAsConst(*s.notebookGuids())) {
            writer.writeString(value);
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncChunkFilter(
    ThriftBinaryBufferReader & reader,
    SyncChunkFilter & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNoteResources(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNoteAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeSearches(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResources(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeLinkedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeExpunged(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNoteApplicationDataFullMap(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResourceApplicationDataFullMap(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNoteResourceApplicationDataFullMap(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeSharedNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setOmitSharedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRequireNoteContentClass(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (SyncChunkFilter.notebookGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.setNotebookGuids(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteFilter(
    ThriftBinaryBufferWriter & writer,
    const NoteFilter & s)
{
    writer.writeStructBegin(QStringLiteral("NoteFilter"));
    if (s.order()) {
        writer.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.order());
        writer.writeFieldEnd();
    }

    if (s.ascending()) {
        writer.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.ascending());
        writer.writeFieldEnd();
    }

    if (s.words()) {
        writer.writeFieldBegin(
            QStringLiteral("words"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.words());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.tagGuids()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids()->length());
        for(const auto & value: qAsConst(*s.tagGuids())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.timeZone()) {
        writer.writeFieldBegin(
            QStringLiteral("timeZone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.timeZone());
        writer.writeFieldEnd();
    }

    if (s.inactive()) {
        writer.writeFieldBegin(
            QStringLiteral("inactive"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.inactive());
        writer.writeFieldEnd();
    }

    if (s.emphasized()) {
        writer.writeFieldBegin(
            QStringLiteral("emphasized"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.emphasized());
        writer.writeFieldEnd();
    }

    if (s.includeAllReadableNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAllReadableNotebooks"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(*s.includeAllReadableNotebooks());
        writer.writeFieldEnd();
    }

    if (s.includeAllReadableWorkspaces()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAllReadableWorkspaces"),
            ThriftFieldType::T_BOOL,
            15);

        writer.writeBool(*s.includeAllReadableWorkspaces());
        writer.writeFieldEnd();
    }

    if (s.context()) {
        writer.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(*s.context());
        writer.writeFieldEnd();
    }

    if (s.rawWords()) {
        writer.writeFieldBegin(
            QStringLiteral("rawWords"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.rawWords());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            12);

        writer.writeBinary(*s.searchContextBytes());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteFilter(
    ThriftBinaryBufferReader & reader,
    NoteFilter & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setOrder(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setAscending(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteFilter.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTagGuids(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTimeZone(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setInactive(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmphasized(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeAllReadableNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeAllReadableWorkspaces(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContext(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRawWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setSearchContextBytes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteList(
    ThriftBinaryBufferWriter & writer,
    const NoteList & s)
{
    writer.writeStructBegin(QStringLiteral("NoteList"));
    writer.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.startIndex());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);

    writer.writeI32(s.totalNotes());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes().length());
    for(const auto & value: qAsConst(s.notes())) {
        writeNote(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.stoppedWords()) {
        writer.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords()->length());
        for(const auto & value: qAsConst(*s.stoppedWords())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searchedWords()) {
        writer.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords()->length());
        for(const auto & value: qAsConst(*s.searchedWords())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.updateCount()) {
        writer.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(*s.updateCount());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeBinary(*s.searchContextBytes());
        writer.writeFieldEnd();
    }

    if (s.debugInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.debugInfo());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteList(
    ThriftBinaryBufferReader & reader,
    NoteList & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setStartIndex(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setTotalNotes(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotes(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.stoppedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setStoppedWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.searchedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSearchedWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setSearchContextBytes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDebugInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.startIndex has no value"));
    if (!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.totalNotes has no value"));
    if (!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.notes has no value"));
}

void writeNoteMetadata(
    ThriftBinaryBufferWriter & writer,
    const NoteMetadata & s)
{
    writer.writeStructBegin(QStringLiteral("NoteMetadata"));
    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.guid());
    writer.writeFieldEnd();

    if (s.title()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.title());
        writer.writeFieldEnd();
    }

    if (s.contentLength()) {
        writer.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.contentLength());
        writer.writeFieldEnd();
    }

    if (s.created()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(*s.created());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.updated());
        writer.writeFieldEnd();
    }

    if (s.deleted()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.deleted());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.tagGuids()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids()->length());
        for(const auto & value: qAsConst(*s.tagGuids())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.attributes()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);

        writeNoteAttributes(writer, *s.attributes());
        writer.writeFieldEnd();
    }

    if (s.largestResourceMime()) {
        writer.writeFieldBegin(
            QStringLiteral("largestResourceMime"),
            ThriftFieldType::T_STRING,
            20);

        writer.writeString(*s.largestResourceMime());
        writer.writeFieldEnd();
    }

    if (s.largestResourceSize()) {
        writer.writeFieldBegin(
            QStringLiteral("largestResourceSize"),
            ThriftFieldType::T_I32,
            21);

        writer.writeI32(*s.largestResourceSize());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteMetadata(
    ThriftBinaryBufferReader & reader,
    NoteMetadata & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool guid_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                guid_isset = true;
                Guid v;
                reader.readString(v);
                s.setGuid(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setContentLength(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setDeleted(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteMetadata.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTagGuids(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(reader, v);
                s.setAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setLargestResourceMime(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setLargestResourceSize(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!guid_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteMetadata.guid has no value"));
}

void writeNotesMetadataList(
    ThriftBinaryBufferWriter & writer,
    const NotesMetadataList & s)
{
    writer.writeStructBegin(QStringLiteral("NotesMetadataList"));
    writer.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.startIndex());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);

    writer.writeI32(s.totalNotes());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes().length());
    for(const auto & value: qAsConst(s.notes())) {
        writeNoteMetadata(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.stoppedWords()) {
        writer.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords()->length());
        for(const auto & value: qAsConst(*s.stoppedWords())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searchedWords()) {
        writer.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords()->length());
        for(const auto & value: qAsConst(*s.searchedWords())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.updateCount()) {
        writer.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(*s.updateCount());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeBinary(*s.searchContextBytes());
        writer.writeFieldEnd();
    }

    if (s.debugInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.debugInfo());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotesMetadataList(
    ThriftBinaryBufferReader & reader,
    NotesMetadataList & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setStartIndex(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setTotalNotes(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<NoteMetadata> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMetadata elem;
                    readNoteMetadata(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotes(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.stoppedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setStoppedWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.searchedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSearchedWords(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setSearchContextBytes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDebugInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.startIndex has no value"));
    if (!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.totalNotes has no value"));
    if (!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.notes has no value"));
}

void writeNotesMetadataResultSpec(
    ThriftBinaryBufferWriter & writer,
    const NotesMetadataResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("NotesMetadataResultSpec"));
    if (s.includeTitle()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTitle"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.includeTitle());
        writer.writeFieldEnd();
    }

    if (s.includeContentLength()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContentLength"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.includeContentLength());
        writer.writeFieldEnd();
    }

    if (s.includeCreated()) {
        writer.writeFieldBegin(
            QStringLiteral("includeCreated"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.includeCreated());
        writer.writeFieldEnd();
    }

    if (s.includeUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("includeUpdated"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.includeUpdated());
        writer.writeFieldEnd();
    }

    if (s.includeDeleted()) {
        writer.writeFieldBegin(
            QStringLiteral("includeDeleted"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.includeDeleted());
        writer.writeFieldEnd();
    }

    if (s.includeUpdateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("includeUpdateSequenceNum"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(*s.includeUpdateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.includeNotebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotebookGuid"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(*s.includeNotebookGuid());
        writer.writeFieldEnd();
    }

    if (s.includeTagGuids()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTagGuids"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(*s.includeTagGuids());
        writer.writeFieldEnd();
    }

    if (s.includeAttributes()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAttributes"),
            ThriftFieldType::T_BOOL,
            14);

        writer.writeBool(*s.includeAttributes());
        writer.writeFieldEnd();
    }

    if (s.includeLargestResourceMime()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLargestResourceMime"),
            ThriftFieldType::T_BOOL,
            20);

        writer.writeBool(*s.includeLargestResourceMime());
        writer.writeFieldEnd();
    }

    if (s.includeLargestResourceSize()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLargestResourceSize"),
            ThriftFieldType::T_BOOL,
            21);

        writer.writeBool(*s.includeLargestResourceSize());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotesMetadataResultSpec(
    ThriftBinaryBufferReader & reader,
    NotesMetadataResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeContentLength(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeDeleted(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeTagGuids(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeLargestResourceMime(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeLargestResourceSize(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteCollectionCounts(
    ThriftBinaryBufferWriter & writer,
    const NoteCollectionCounts & s)
{
    writer.writeStructBegin(QStringLiteral("NoteCollectionCounts"));
    if (s.notebookCounts()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookCounts"),
            ThriftFieldType::T_MAP,
            1);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.notebookCounts()->size());
        for(const auto & it: toRange(*s.notebookCounts())) {
            writer.writeString(it.key());
            writer.writeI32(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.tagCounts()) {
        writer.writeFieldBegin(
            QStringLiteral("tagCounts"),
            ThriftFieldType::T_MAP,
            2);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.tagCounts()->size());
        for(const auto & it: toRange(*s.tagCounts())) {
            writer.writeString(it.key());
            writer.writeI32(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.trashCount()) {
        writer.writeFieldBegin(
            QStringLiteral("trashCount"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(*s.trashCount());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteCollectionCounts(
    ThriftBinaryBufferReader & reader,
    NoteCollectionCounts & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.notebookCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.notebookCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    reader.readString(key);
                    qint32 value;
                    reader.readI32(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.setNotebookCounts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.tagCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.tagCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    reader.readString(key);
                    qint32 value;
                    reader.readI32(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.setTagCounts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setTrashCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteResultSpec(
    ThriftBinaryBufferWriter & writer,
    const NoteResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("NoteResultSpec"));
    if (s.includeContent()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContent"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.includeContent());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesData()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesData"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.includeResourcesData());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesRecognition()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesRecognition"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.includeResourcesRecognition());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesAlternateData()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesAlternateData"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.includeResourcesAlternateData());
        writer.writeFieldEnd();
    }

    if (s.includeSharedNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.includeSharedNotes());
        writer.writeFieldEnd();
    }

    if (s.includeNoteAppDataValues()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteAppDataValues"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.includeNoteAppDataValues());
        writer.writeFieldEnd();
    }

    if (s.includeResourceAppDataValues()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourceAppDataValues"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.includeResourceAppDataValues());
        writer.writeFieldEnd();
    }

    if (s.includeAccountLimits()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAccountLimits"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.includeAccountLimits());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteResultSpec(
    ThriftBinaryBufferReader & reader,
    NoteResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeContent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResourcesData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResourcesRecognition(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResourcesAlternateData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeSharedNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeNoteAppDataValues(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeResourceAppDataValues(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeAccountLimits(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteEmailParameters(
    ThriftBinaryBufferWriter & writer,
    const NoteEmailParameters & s)
{
    writer.writeStructBegin(QStringLiteral("NoteEmailParameters"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.note()) {
        writer.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            2);

        writeNote(writer, *s.note());
        writer.writeFieldEnd();
    }

    if (s.toAddresses()) {
        writer.writeFieldBegin(
            QStringLiteral("toAddresses"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.toAddresses()->length());
        for(const auto & value: qAsConst(*s.toAddresses())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.ccAddresses()) {
        writer.writeFieldBegin(
            QStringLiteral("ccAddresses"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.ccAddresses()->length());
        for(const auto & value: qAsConst(*s.ccAddresses())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.subject()) {
        writer.writeFieldBegin(
            QStringLiteral("subject"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.subject());
        writer.writeFieldEnd();
    }

    if (s.message()) {
        writer.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.message());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteEmailParameters(
    ThriftBinaryBufferReader & reader,
    NoteEmailParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                s.setNote(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteEmailParameters.toAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setToAddresses(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteEmailParameters.ccAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setCcAddresses(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSubject(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setMessage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteVersionId(
    ThriftBinaryBufferWriter & writer,
    const NoteVersionId & s)
{
    writer.writeStructBegin(QStringLiteral("NoteVersionId"));
    writer.writeFieldBegin(
        QStringLiteral("updateSequenceNum"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.updateSequenceNum());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("updated"),
        ThriftFieldType::T_I64,
        2);

    writer.writeI64(s.updated());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("saved"),
        ThriftFieldType::T_I64,
        3);

    writer.writeI64(s.saved());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("title"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(s.title());
    writer.writeFieldEnd();

    if (s.lastEditorId()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.lastEditorId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteVersionId(
    ThriftBinaryBufferReader & reader,
    NoteVersionId & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool updateSequenceNum_isset = false;
    bool updated_isset = false;
    bool saved_isset = false;
    bool title_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateSequenceNum_isset = true;
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                updated_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setUpdated(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                saved_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setSaved(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                title_isset = true;
                QString v;
                reader.readString(v);
                s.setTitle(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setLastEditorId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!updateSequenceNum_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updateSequenceNum has no value"));
    if (!updated_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updated has no value"));
    if (!saved_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.saved has no value"));
    if (!title_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.title has no value"));
}

void writeRelatedQuery(
    ThriftBinaryBufferWriter & writer,
    const RelatedQuery & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedQuery"));
    if (s.noteGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.noteGuid());
        writer.writeFieldEnd();
    }

    if (s.plainText()) {
        writer.writeFieldBegin(
            QStringLiteral("plainText"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.plainText());
        writer.writeFieldEnd();
    }

    if (s.filter()) {
        writer.writeFieldBegin(
            QStringLiteral("filter"),
            ThriftFieldType::T_STRUCT,
            3);

        writeNoteFilter(writer, *s.filter());
        writer.writeFieldEnd();
    }

    if (s.referenceUri()) {
        writer.writeFieldBegin(
            QStringLiteral("referenceUri"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.referenceUri());
        writer.writeFieldEnd();
    }

    if (s.context()) {
        writer.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.context());
        writer.writeFieldEnd();
    }

    if (s.cacheKey()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.cacheKey());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedQuery(
    ThriftBinaryBufferReader & reader,
    RelatedQuery & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPlainText(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                s.setFilter(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setReferenceUri(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContext(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setCacheKey(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeRelatedResult(
    ThriftBinaryBufferWriter & writer,
    const RelatedResult & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedResult"));
    if (s.notes()) {
        writer.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes()->length());
        for(const auto & value: qAsConst(*s.notes())) {
            writeNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.notebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks()->length());
        for(const auto & value: qAsConst(*s.notebooks())) {
            writeNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.tags()) {
        writer.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.tags()->length());
        for(const auto & value: qAsConst(*s.tags())) {
            writeTag(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.containingNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("containingNotebooks"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.containingNotebooks()->length());
        for(const auto & value: qAsConst(*s.containingNotebooks())) {
            writeNotebookDescriptor(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.debugInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.debugInfo());
        writer.writeFieldEnd();
    }

    if (s.experts()) {
        writer.writeFieldBegin(
            QStringLiteral("experts"),
            ThriftFieldType::T_LIST,
            6);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.experts()->length());
        for(const auto & value: qAsConst(*s.experts())) {
            writeUserProfile(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.relatedContent()) {
        writer.writeFieldBegin(
            QStringLiteral("relatedContent"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.relatedContent()->length());
        for(const auto & value: qAsConst(*s.relatedContent())) {
            writeRelatedContent(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.cacheKey()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.cacheKey());
        writer.writeFieldEnd();
    }

    if (s.cacheExpires()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheExpires"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(*s.cacheExpires());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedResult(
    ThriftBinaryBufferReader & reader,
    RelatedResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.notebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.tags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NotebookDescriptor> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.containingNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NotebookDescriptor elem;
                    readNotebookDescriptor(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setContainingNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDebugInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserProfile> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.experts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setExperts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContent> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.relatedContent)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContent elem;
                    readRelatedContent(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setRelatedContent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setCacheKey(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setCacheExpires(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeRelatedResultSpec(
    ThriftBinaryBufferWriter & writer,
    const RelatedResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedResultSpec"));
    if (s.maxNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("maxNotes"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.maxNotes());
        writer.writeFieldEnd();
    }

    if (s.maxNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("maxNotebooks"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.maxNotebooks());
        writer.writeFieldEnd();
    }

    if (s.maxTags()) {
        writer.writeFieldBegin(
            QStringLiteral("maxTags"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(*s.maxTags());
        writer.writeFieldEnd();
    }

    if (s.writableNotebooksOnly()) {
        writer.writeFieldBegin(
            QStringLiteral("writableNotebooksOnly"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.writableNotebooksOnly());
        writer.writeFieldEnd();
    }

    if (s.includeContainingNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContainingNotebooks"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.includeContainingNotebooks());
        writer.writeFieldEnd();
    }

    if (s.includeDebugInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("includeDebugInfo"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.includeDebugInfo());
        writer.writeFieldEnd();
    }

    if (s.maxExperts()) {
        writer.writeFieldBegin(
            QStringLiteral("maxExperts"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(*s.maxExperts());
        writer.writeFieldEnd();
    }

    if (s.maxRelatedContent()) {
        writer.writeFieldBegin(
            QStringLiteral("maxRelatedContent"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(*s.maxRelatedContent());
        writer.writeFieldEnd();
    }

    if (s.relatedContentTypes()) {
        writer.writeFieldBegin(
            QStringLiteral("relatedContentTypes"),
            ThriftFieldType::T_SET,
            9);

        writer.writeSetBegin(ThriftFieldType::T_I32, s.relatedContentTypes()->count());
        for(const auto & value: qAsConst(*s.relatedContentTypes())) {
            writer.writeI32(static_cast<qint32>(value));
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedResultSpec(
    ThriftBinaryBufferReader & reader,
    RelatedResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setWritableNotebooksOnly(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeContainingNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeDebugInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxExperts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxRelatedContent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<RelatedContentType> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (RelatedResultSpec.relatedContentTypes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentType elem;
                    readEnumRelatedContentType(reader, elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.setRelatedContentTypes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeUpdateNoteIfUsnMatchesResult(
    ThriftBinaryBufferWriter & writer,
    const UpdateNoteIfUsnMatchesResult & s)
{
    writer.writeStructBegin(QStringLiteral("UpdateNoteIfUsnMatchesResult"));
    if (s.note()) {
        writer.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            1);

        writeNote(writer, *s.note());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.updated());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUpdateNoteIfUsnMatchesResult(
    ThriftBinaryBufferReader & reader,
    UpdateNoteIfUsnMatchesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                s.setNote(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeShareRelationshipRestrictions(
    ThriftBinaryBufferWriter & writer,
    const ShareRelationshipRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("ShareRelationshipRestrictions"));
    if (s.noSetReadOnly()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadOnly"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.noSetReadOnly());
        writer.writeFieldEnd();
    }

    if (s.noSetReadPlusActivity()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadPlusActivity"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.noSetReadPlusActivity());
        writer.writeFieldEnd();
    }

    if (s.noSetModify()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetModify"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.noSetModify());
        writer.writeFieldEnd();
    }

    if (s.noSetFullAccess()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.noSetFullAccess());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readShareRelationshipRestrictions(
    ThriftBinaryBufferReader & reader,
    ShareRelationshipRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetReadOnly(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetReadPlusActivity(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetModify(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetFullAccess(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeInvitationShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const InvitationShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("InvitationShareRelationship"));
    if (s.displayName()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.displayName());
        writer.writeFieldEnd();
    }

    if (s.recipientUserIdentity()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserIdentity"),
            ThriftFieldType::T_STRUCT,
            2);

        writeUserIdentity(writer, *s.recipientUserIdentity());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.sharerUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.sharerUserId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readInvitationShareRelationship(
    ThriftBinaryBufferReader & reader,
    InvitationShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDisplayName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(reader, v);
                s.setRecipientUserIdentity(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeMemberShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const MemberShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("MemberShareRelationship"));
    if (s.displayName()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.displayName());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.recipientUserId());
        writer.writeFieldEnd();
    }

    if (s.bestPrivilege()) {
        writer.writeFieldBegin(
            QStringLiteral("bestPrivilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.bestPrivilege()));
        writer.writeFieldEnd();
    }

    if (s.individualPrivilege()) {
        writer.writeFieldBegin(
            QStringLiteral("individualPrivilege"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(*s.individualPrivilege()));
        writer.writeFieldEnd();
    }

    if (s.restrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            5);

        writeShareRelationshipRestrictions(writer, *s.restrictions());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(*s.sharerUserId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readMemberShareRelationship(
    ThriftBinaryBufferReader & reader,
    MemberShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDisplayName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setRecipientUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.setBestPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.setIndividualPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(reader, v);
                s.setRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeShareRelationships(
    ThriftBinaryBufferWriter & writer,
    const ShareRelationships & s)
{
    writer.writeStructBegin(QStringLiteral("ShareRelationships"));
    if (s.invitations()) {
        writer.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations()->length());
        for(const auto & value: qAsConst(*s.invitations())) {
            writeInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.memberships()) {
        writer.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships()->length());
        for(const auto & value: qAsConst(*s.memberships())) {
            writeMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationRestrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);

        writeShareRelationshipRestrictions(writer, *s.invitationRestrictions());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readShareRelationships(
    ThriftBinaryBufferReader & reader,
    ShareRelationships & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ShareRelationships.invitations)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setInvitations(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ShareRelationships.memberships)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMemberships(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(reader, v);
                s.setInvitationRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNotebookSharesParameters(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesParameters & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesParameters"));
    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.inviteMessage()) {
        writer.writeFieldBegin(
            QStringLiteral("inviteMessage"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.inviteMessage());
        writer.writeFieldEnd();
    }

    if (s.membershipsToUpdate()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate()->length());
        for(const auto & value: qAsConst(*s.membershipsToUpdate())) {
            writeMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToCreateOrUpdate()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToCreateOrUpdate"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToCreateOrUpdate()->length());
        for(const auto & value: qAsConst(*s.invitationsToCreateOrUpdate())) {
            writeInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.unshares()) {
        writer.writeFieldBegin(
            QStringLiteral("unshares"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.unshares()->length());
        for(const auto & value: qAsConst(*s.unshares())) {
            writeUserIdentity(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesParameters(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setInviteMessage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.membershipsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMembershipsToUpdate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.invitationsToCreateOrUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setInvitationsToCreateOrUpdate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserIdentity> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.unshares)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserIdentity elem;
                    readUserIdentity(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setUnshares(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNotebookSharesError(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesError & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesError"));
    if (s.userIdentity()) {
        writer.writeFieldBegin(
            QStringLiteral("userIdentity"),
            ThriftFieldType::T_STRUCT,
            1);

        writeUserIdentity(writer, *s.userIdentity());
        writer.writeFieldEnd();
    }

    if (s.userException()) {
        writer.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMUserException(writer, *s.userException());
        writer.writeFieldEnd();
    }

    if (s.notFoundException()) {
        writer.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMNotFoundException(writer, *s.notFoundException());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesError(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesError & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(reader, v);
                s.setUserIdentity(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(reader, v);
                s.setUserException(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(reader, v);
                s.setNotFoundException(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNotebookSharesResult(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesResult"));
    if (s.errors()) {
        writer.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.errors()->length());
        for(const auto & value: qAsConst(*s.errors())) {
            writeManageNotebookSharesError(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesResult(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNotebookSharesError> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesResult.errors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    ManageNotebookSharesError elem;
                    readManageNotebookSharesError(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setErrors(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSharedNoteTemplate(
    ThriftBinaryBufferWriter & writer,
    const SharedNoteTemplate & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNoteTemplate"));
    if (s.noteGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.noteGuid());
        writer.writeFieldEnd();
    }

    if (s.recipientThreadId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(*s.recipientThreadId());
        writer.writeFieldEnd();
    }

    if (s.recipientContacts()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts()->length());
        for(const auto & value: qAsConst(*s.recipientContacts())) {
            writeContact(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNoteTemplate(
    ThriftBinaryBufferReader & reader,
    SharedNoteTemplate & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setNoteGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                reader.readI64(v);
                s.setRecipientThreadId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SharedNoteTemplate.recipientContacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setRecipientContacts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNotebookShareTemplate(
    ThriftBinaryBufferWriter & writer,
    const NotebookShareTemplate & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookShareTemplate"));
    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.recipientThreadId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(*s.recipientThreadId());
        writer.writeFieldEnd();
    }

    if (s.recipientContacts()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts()->length());
        for(const auto & value: qAsConst(*s.recipientContacts())) {
            writeContact(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookShareTemplate(
    ThriftBinaryBufferReader & reader,
    NotebookShareTemplate & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                reader.readI64(v);
                s.setRecipientThreadId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotebookShareTemplate.recipientContacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setRecipientContacts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeCreateOrUpdateNotebookSharesResult(
    ThriftBinaryBufferWriter & writer,
    const CreateOrUpdateNotebookSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("CreateOrUpdateNotebookSharesResult"));
    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.matchingShares()) {
        writer.writeFieldBegin(
            QStringLiteral("matchingShares"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.matchingShares()->length());
        for(const auto & value: qAsConst(*s.matchingShares())) {
            writeSharedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readCreateOrUpdateNotebookSharesResult(
    ThriftBinaryBufferReader & reader,
    CreateOrUpdateNotebookSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (CreateOrUpdateNotebookSharesResult.matchingShares)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMatchingShares(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteShareRelationshipRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NoteShareRelationshipRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NoteShareRelationshipRestrictions"));
    if (s.noSetReadNote()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadNote"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.noSetReadNote());
        writer.writeFieldEnd();
    }

    if (s.noSetModifyNote()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetModifyNote"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.noSetModifyNote());
        writer.writeFieldEnd();
    }

    if (s.noSetFullAccess()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.noSetFullAccess());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteShareRelationshipRestrictions(
    ThriftBinaryBufferReader & reader,
    NoteShareRelationshipRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetReadNote(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetModifyNote(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetFullAccess(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteMemberShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const NoteMemberShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("NoteMemberShareRelationship"));
    if (s.displayName()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.displayName());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.recipientUserId());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.restrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            4);

        writeNoteShareRelationshipRestrictions(writer, *s.restrictions());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.sharerUserId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteMemberShareRelationship(
    ThriftBinaryBufferReader & reader,
    NoteMemberShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDisplayName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setRecipientUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(reader, v);
                s.setRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteInvitationShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const NoteInvitationShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("NoteInvitationShareRelationship"));
    if (s.displayName()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.displayName());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentityId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(*s.recipientIdentityId());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.sharerUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.sharerUserId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteInvitationShareRelationship(
    ThriftBinaryBufferReader & reader,
    NoteInvitationShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDisplayName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.setRecipientIdentityId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteShareRelationships(
    ThriftBinaryBufferWriter & writer,
    const NoteShareRelationships & s)
{
    writer.writeStructBegin(QStringLiteral("NoteShareRelationships"));
    if (s.invitations()) {
        writer.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations()->length());
        for(const auto & value: qAsConst(*s.invitations())) {
            writeNoteInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.memberships()) {
        writer.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships()->length());
        for(const auto & value: qAsConst(*s.memberships())) {
            writeNoteMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationRestrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);

        writeNoteShareRelationshipRestrictions(writer, *s.invitationRestrictions());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteShareRelationships(
    ThriftBinaryBufferReader & reader,
    NoteShareRelationships & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteShareRelationships.invitations)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setInvitations(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteShareRelationships.memberships)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMemberships(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(reader, v);
                s.setInvitationRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNoteSharesParameters(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesParameters & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesParameters"));
    if (s.noteGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.noteGuid());
        writer.writeFieldEnd();
    }

    if (s.membershipsToUpdate()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate()->length());
        for(const auto & value: qAsConst(*s.membershipsToUpdate())) {
            writeNoteMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToUpdate()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToUpdate"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToUpdate()->length());
        for(const auto & value: qAsConst(*s.invitationsToUpdate())) {
            writeNoteInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.membershipsToUnshare()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUnshare"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_I32, s.membershipsToUnshare()->length());
        for(const auto & value: qAsConst(*s.membershipsToUnshare())) {
            writer.writeI32(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToUnshare()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToUnshare"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_I64, s.invitationsToUnshare()->length());
        for(const auto & value: qAsConst(*s.invitationsToUnshare())) {
            writer.writeI64(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesParameters(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMembershipsToUpdate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setInvitationsToUpdate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserID> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUnshare)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserID elem;
                    reader.readI32(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setMembershipsToUnshare(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<IdentityID> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I64) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUnshare)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    IdentityID elem;
                    reader.readI64(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setInvitationsToUnshare(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNoteSharesError(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesError & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesError"));
    if (s.identityID()) {
        writer.writeFieldBegin(
            QStringLiteral("identityID"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(*s.identityID());
        writer.writeFieldEnd();
    }

    if (s.userID()) {
        writer.writeFieldBegin(
            QStringLiteral("userID"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.userID());
        writer.writeFieldEnd();
    }

    if (s.userException()) {
        writer.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMUserException(writer, *s.userException());
        writer.writeFieldEnd();
    }

    if (s.notFoundException()) {
        writer.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            4);

        writeEDAMNotFoundException(writer, *s.notFoundException());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesError(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesError & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.setIdentityID(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setUserID(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(reader, v);
                s.setUserException(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(reader, v);
                s.setNotFoundException(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeManageNoteSharesResult(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesResult"));
    if (s.errors()) {
        writer.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.errors()->length());
        for(const auto & value: qAsConst(*s.errors())) {
            writeManageNoteSharesError(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesResult(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNoteSharesError> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesResult.errors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    ManageNoteSharesError elem;
                    readManageNoteSharesError(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setErrors(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeData(
    ThriftBinaryBufferWriter & writer,
    const Data & s)
{
    writer.writeStructBegin(QStringLiteral("Data"));
    if (s.bodyHash()) {
        writer.writeFieldBegin(
            QStringLiteral("bodyHash"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeBinary(*s.bodyHash());
        writer.writeFieldEnd();
    }

    if (s.size()) {
        writer.writeFieldBegin(
            QStringLiteral("size"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.size());
        writer.writeFieldEnd();
    }

    if (s.body()) {
        writer.writeFieldBegin(
            QStringLiteral("body"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeBinary(*s.body());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readData(
    ThriftBinaryBufferReader & reader,
    Data & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setBodyHash(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setSize(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setBody(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeUserAttributes(
    ThriftBinaryBufferWriter & writer,
    const UserAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("UserAttributes"));
    if (s.defaultLocationName()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLocationName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.defaultLocationName());
        writer.writeFieldEnd();
    }

    if (s.defaultLatitude()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLatitude"),
            ThriftFieldType::T_DOUBLE,
            2);

        writer.writeDouble(*s.defaultLatitude());
        writer.writeFieldEnd();
    }

    if (s.defaultLongitude()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLongitude"),
            ThriftFieldType::T_DOUBLE,
            3);

        writer.writeDouble(*s.defaultLongitude());
        writer.writeFieldEnd();
    }

    if (s.preactivation()) {
        writer.writeFieldBegin(
            QStringLiteral("preactivation"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.preactivation());
        writer.writeFieldEnd();
    }

    if (s.viewedPromotions()) {
        writer.writeFieldBegin(
            QStringLiteral("viewedPromotions"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.viewedPromotions()->length());
        for(const auto & value: qAsConst(*s.viewedPromotions())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.incomingEmailAddress()) {
        writer.writeFieldBegin(
            QStringLiteral("incomingEmailAddress"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.incomingEmailAddress());
        writer.writeFieldEnd();
    }

    if (s.recentMailedAddresses()) {
        writer.writeFieldBegin(
            QStringLiteral("recentMailedAddresses"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.recentMailedAddresses()->length());
        for(const auto & value: qAsConst(*s.recentMailedAddresses())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.comments()) {
        writer.writeFieldBegin(
            QStringLiteral("comments"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.comments());
        writer.writeFieldEnd();
    }

    if (s.dateAgreedToTermsOfService()) {
        writer.writeFieldBegin(
            QStringLiteral("dateAgreedToTermsOfService"),
            ThriftFieldType::T_I64,
            11);

        writer.writeI64(*s.dateAgreedToTermsOfService());
        writer.writeFieldEnd();
    }

    if (s.maxReferrals()) {
        writer.writeFieldBegin(
            QStringLiteral("maxReferrals"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(*s.maxReferrals());
        writer.writeFieldEnd();
    }

    if (s.referralCount()) {
        writer.writeFieldBegin(
            QStringLiteral("referralCount"),
            ThriftFieldType::T_I32,
            13);

        writer.writeI32(*s.referralCount());
        writer.writeFieldEnd();
    }

    if (s.refererCode()) {
        writer.writeFieldBegin(
            QStringLiteral("refererCode"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(*s.refererCode());
        writer.writeFieldEnd();
    }

    if (s.sentEmailDate()) {
        writer.writeFieldBegin(
            QStringLiteral("sentEmailDate"),
            ThriftFieldType::T_I64,
            15);

        writer.writeI64(*s.sentEmailDate());
        writer.writeFieldEnd();
    }

    if (s.sentEmailCount()) {
        writer.writeFieldBegin(
            QStringLiteral("sentEmailCount"),
            ThriftFieldType::T_I32,
            16);

        writer.writeI32(*s.sentEmailCount());
        writer.writeFieldEnd();
    }

    if (s.dailyEmailLimit()) {
        writer.writeFieldBegin(
            QStringLiteral("dailyEmailLimit"),
            ThriftFieldType::T_I32,
            17);

        writer.writeI32(*s.dailyEmailLimit());
        writer.writeFieldEnd();
    }

    if (s.emailOptOutDate()) {
        writer.writeFieldBegin(
            QStringLiteral("emailOptOutDate"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(*s.emailOptOutDate());
        writer.writeFieldEnd();
    }

    if (s.partnerEmailOptInDate()) {
        writer.writeFieldBegin(
            QStringLiteral("partnerEmailOptInDate"),
            ThriftFieldType::T_I64,
            19);

        writer.writeI64(*s.partnerEmailOptInDate());
        writer.writeFieldEnd();
    }

    if (s.preferredLanguage()) {
        writer.writeFieldBegin(
            QStringLiteral("preferredLanguage"),
            ThriftFieldType::T_STRING,
            20);

        writer.writeString(*s.preferredLanguage());
        writer.writeFieldEnd();
    }

    if (s.preferredCountry()) {
        writer.writeFieldBegin(
            QStringLiteral("preferredCountry"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(*s.preferredCountry());
        writer.writeFieldEnd();
    }

    if (s.clipFullPage()) {
        writer.writeFieldBegin(
            QStringLiteral("clipFullPage"),
            ThriftFieldType::T_BOOL,
            22);

        writer.writeBool(*s.clipFullPage());
        writer.writeFieldEnd();
    }

    if (s.twitterUserName()) {
        writer.writeFieldBegin(
            QStringLiteral("twitterUserName"),
            ThriftFieldType::T_STRING,
            23);

        writer.writeString(*s.twitterUserName());
        writer.writeFieldEnd();
    }

    if (s.twitterId()) {
        writer.writeFieldBegin(
            QStringLiteral("twitterId"),
            ThriftFieldType::T_STRING,
            24);

        writer.writeString(*s.twitterId());
        writer.writeFieldEnd();
    }

    if (s.groupName()) {
        writer.writeFieldBegin(
            QStringLiteral("groupName"),
            ThriftFieldType::T_STRING,
            25);

        writer.writeString(*s.groupName());
        writer.writeFieldEnd();
    }

    if (s.recognitionLanguage()) {
        writer.writeFieldBegin(
            QStringLiteral("recognitionLanguage"),
            ThriftFieldType::T_STRING,
            26);

        writer.writeString(*s.recognitionLanguage());
        writer.writeFieldEnd();
    }

    if (s.referralProof()) {
        writer.writeFieldBegin(
            QStringLiteral("referralProof"),
            ThriftFieldType::T_STRING,
            28);

        writer.writeString(*s.referralProof());
        writer.writeFieldEnd();
    }

    if (s.educationalDiscount()) {
        writer.writeFieldBegin(
            QStringLiteral("educationalDiscount"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(*s.educationalDiscount());
        writer.writeFieldEnd();
    }

    if (s.businessAddress()) {
        writer.writeFieldBegin(
            QStringLiteral("businessAddress"),
            ThriftFieldType::T_STRING,
            30);

        writer.writeString(*s.businessAddress());
        writer.writeFieldEnd();
    }

    if (s.hideSponsorBilling()) {
        writer.writeFieldBegin(
            QStringLiteral("hideSponsorBilling"),
            ThriftFieldType::T_BOOL,
            31);

        writer.writeBool(*s.hideSponsorBilling());
        writer.writeFieldEnd();
    }

    if (s.useEmailAutoFiling()) {
        writer.writeFieldBegin(
            QStringLiteral("useEmailAutoFiling"),
            ThriftFieldType::T_BOOL,
            33);

        writer.writeBool(*s.useEmailAutoFiling());
        writer.writeFieldEnd();
    }

    if (s.reminderEmailConfig()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderEmailConfig"),
            ThriftFieldType::T_I32,
            34);

        writer.writeI32(static_cast<qint32>(*s.reminderEmailConfig()));
        writer.writeFieldEnd();
    }

    if (s.emailAddressLastConfirmed()) {
        writer.writeFieldBegin(
            QStringLiteral("emailAddressLastConfirmed"),
            ThriftFieldType::T_I64,
            35);

        writer.writeI64(*s.emailAddressLastConfirmed());
        writer.writeFieldEnd();
    }

    if (s.passwordUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("passwordUpdated"),
            ThriftFieldType::T_I64,
            36);

        writer.writeI64(*s.passwordUpdated());
        writer.writeFieldEnd();
    }

    if (s.salesforcePushEnabled()) {
        writer.writeFieldBegin(
            QStringLiteral("salesforcePushEnabled"),
            ThriftFieldType::T_BOOL,
            37);

        writer.writeBool(*s.salesforcePushEnabled());
        writer.writeFieldEnd();
    }

    if (s.shouldLogClientEvent()) {
        writer.writeFieldBegin(
            QStringLiteral("shouldLogClientEvent"),
            ThriftFieldType::T_BOOL,
            38);

        writer.writeBool(*s.shouldLogClientEvent());
        writer.writeFieldEnd();
    }

    if (s.optOutMachineLearning()) {
        writer.writeFieldBegin(
            QStringLiteral("optOutMachineLearning"),
            ThriftFieldType::T_BOOL,
            39);

        writer.writeBool(*s.optOutMachineLearning());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserAttributes(
    ThriftBinaryBufferReader & reader,
    UserAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDefaultLocationName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setDefaultLatitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setDefaultLongitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setPreactivation(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (UserAttributes.viewedPromotions)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setViewedPromotions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setIncomingEmailAddress(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (UserAttributes.recentMailedAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setRecentMailedAddresses(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setComments(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setDateAgreedToTermsOfService(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setMaxReferrals(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setReferralCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRefererCode(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setSentEmailDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setSentEmailCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setDailyEmailLimit(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setEmailOptOutDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPartnerEmailOptInDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPreferredLanguage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPreferredCountry(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setClipFullPage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTwitterUserName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTwitterId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setGroupName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRecognitionLanguage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setReferralProof(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEducationalDiscount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setBusinessAddress(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setHideSponsorBilling(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 33) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setUseEmailAutoFiling(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 34) {
            if (fieldType == ThriftFieldType::T_I32) {
                ReminderEmailConfig v;
                readEnumReminderEmailConfig(reader, v);
                s.setReminderEmailConfig(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 35) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setEmailAddressLastConfirmed(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 36) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPasswordUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 37) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setSalesforcePushEnabled(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 38) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setShouldLogClientEvent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 39) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setOptOutMachineLearning(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeBusinessUserAttributes(
    ThriftBinaryBufferWriter & writer,
    const BusinessUserAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessUserAttributes"));
    if (s.title()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.title());
        writer.writeFieldEnd();
    }

    if (s.location()) {
        writer.writeFieldBegin(
            QStringLiteral("location"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.location());
        writer.writeFieldEnd();
    }

    if (s.department()) {
        writer.writeFieldBegin(
            QStringLiteral("department"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.department());
        writer.writeFieldEnd();
    }

    if (s.mobilePhone()) {
        writer.writeFieldBegin(
            QStringLiteral("mobilePhone"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.mobilePhone());
        writer.writeFieldEnd();
    }

    if (s.linkedInProfileUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("linkedInProfileUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.linkedInProfileUrl());
        writer.writeFieldEnd();
    }

    if (s.workPhone()) {
        writer.writeFieldBegin(
            QStringLiteral("workPhone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.workPhone());
        writer.writeFieldEnd();
    }

    if (s.companyStartDate()) {
        writer.writeFieldBegin(
            QStringLiteral("companyStartDate"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.companyStartDate());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessUserAttributes(
    ThriftBinaryBufferReader & reader,
    BusinessUserAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setLocation(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setDepartment(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setMobilePhone(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setLinkedInProfileUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWorkPhone(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setCompanyStartDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeAccounting(
    ThriftBinaryBufferWriter & writer,
    const Accounting & s)
{
    writer.writeStructBegin(QStringLiteral("Accounting"));
    if (s.uploadLimitEnd()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimitEnd"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(*s.uploadLimitEnd());
        writer.writeFieldEnd();
    }

    if (s.uploadLimitNextMonth()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimitNextMonth"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(*s.uploadLimitNextMonth());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceStatus()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceStatus"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(*s.premiumServiceStatus()));
        writer.writeFieldEnd();
    }

    if (s.premiumOrderNumber()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumOrderNumber"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.premiumOrderNumber());
        writer.writeFieldEnd();
    }

    if (s.premiumCommerceService()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumCommerceService"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.premiumCommerceService());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceStart()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceStart"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.premiumServiceStart());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceSKU()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceSKU"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.premiumServiceSKU());
        writer.writeFieldEnd();
    }

    if (s.lastSuccessfulCharge()) {
        writer.writeFieldBegin(
            QStringLiteral("lastSuccessfulCharge"),
            ThriftFieldType::T_I64,
            9);

        writer.writeI64(*s.lastSuccessfulCharge());
        writer.writeFieldEnd();
    }

    if (s.lastFailedCharge()) {
        writer.writeFieldBegin(
            QStringLiteral("lastFailedCharge"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(*s.lastFailedCharge());
        writer.writeFieldEnd();
    }

    if (s.lastFailedChargeReason()) {
        writer.writeFieldBegin(
            QStringLiteral("lastFailedChargeReason"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.lastFailedChargeReason());
        writer.writeFieldEnd();
    }

    if (s.nextPaymentDue()) {
        writer.writeFieldBegin(
            QStringLiteral("nextPaymentDue"),
            ThriftFieldType::T_I64,
            12);

        writer.writeI64(*s.nextPaymentDue());
        writer.writeFieldEnd();
    }

    if (s.premiumLockUntil()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumLockUntil"),
            ThriftFieldType::T_I64,
            13);

        writer.writeI64(*s.premiumLockUntil());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            14);

        writer.writeI64(*s.updated());
        writer.writeFieldEnd();
    }

    if (s.premiumSubscriptionNumber()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumSubscriptionNumber"),
            ThriftFieldType::T_STRING,
            16);

        writer.writeString(*s.premiumSubscriptionNumber());
        writer.writeFieldEnd();
    }

    if (s.lastRequestedCharge()) {
        writer.writeFieldBegin(
            QStringLiteral("lastRequestedCharge"),
            ThriftFieldType::T_I64,
            17);

        writer.writeI64(*s.lastRequestedCharge());
        writer.writeFieldEnd();
    }

    if (s.currency()) {
        writer.writeFieldBegin(
            QStringLiteral("currency"),
            ThriftFieldType::T_STRING,
            18);

        writer.writeString(*s.currency());
        writer.writeFieldEnd();
    }

    if (s.unitPrice()) {
        writer.writeFieldBegin(
            QStringLiteral("unitPrice"),
            ThriftFieldType::T_I32,
            19);

        writer.writeI32(*s.unitPrice());
        writer.writeFieldEnd();
    }

    if (s.businessId()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            20);

        writer.writeI32(*s.businessId());
        writer.writeFieldEnd();
    }

    if (s.businessName()) {
        writer.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(*s.businessName());
        writer.writeFieldEnd();
    }

    if (s.businessRole()) {
        writer.writeFieldBegin(
            QStringLiteral("businessRole"),
            ThriftFieldType::T_I32,
            22);

        writer.writeI32(static_cast<qint32>(*s.businessRole()));
        writer.writeFieldEnd();
    }

    if (s.unitDiscount()) {
        writer.writeFieldBegin(
            QStringLiteral("unitDiscount"),
            ThriftFieldType::T_I32,
            23);

        writer.writeI32(*s.unitDiscount());
        writer.writeFieldEnd();
    }

    if (s.nextChargeDate()) {
        writer.writeFieldBegin(
            QStringLiteral("nextChargeDate"),
            ThriftFieldType::T_I64,
            24);

        writer.writeI64(*s.nextChargeDate());
        writer.writeFieldEnd();
    }

    if (s.availablePoints()) {
        writer.writeFieldBegin(
            QStringLiteral("availablePoints"),
            ThriftFieldType::T_I32,
            25);

        writer.writeI32(*s.availablePoints());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAccounting(
    ThriftBinaryBufferReader & reader,
    Accounting & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploadLimitEnd(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploadLimitNextMonth(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                PremiumOrderStatus v;
                readEnumPremiumOrderStatus(reader, v);
                s.setPremiumServiceStatus(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPremiumOrderNumber(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPremiumCommerceService(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPremiumServiceStart(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPremiumServiceSKU(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setLastSuccessfulCharge(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setLastFailedCharge(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setLastFailedChargeReason(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setNextPaymentDue(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPremiumLockUntil(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPremiumSubscriptionNumber(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setLastRequestedCharge(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setCurrency(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUnitPrice(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setBusinessId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setBusinessName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.setBusinessRole(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUnitDiscount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setNextChargeDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setAvailablePoints(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeBusinessUserInfo(
    ThriftBinaryBufferWriter & writer,
    const BusinessUserInfo & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessUserInfo"));
    if (s.businessId()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.businessId());
        writer.writeFieldEnd();
    }

    if (s.businessName()) {
        writer.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.businessName());
        writer.writeFieldEnd();
    }

    if (s.role()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.role()));
        writer.writeFieldEnd();
    }

    if (s.email()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.email());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.updated());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessUserInfo(
    ThriftBinaryBufferReader & reader,
    BusinessUserInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setBusinessId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setBusinessName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.setRole(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeAccountLimits(
    ThriftBinaryBufferWriter & writer,
    const AccountLimits & s)
{
    writer.writeStructBegin(QStringLiteral("AccountLimits"));
    if (s.userMailLimitDaily()) {
        writer.writeFieldBegin(
            QStringLiteral("userMailLimitDaily"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.userMailLimitDaily());
        writer.writeFieldEnd();
    }

    if (s.noteSizeMax()) {
        writer.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(*s.noteSizeMax());
        writer.writeFieldEnd();
    }

    if (s.resourceSizeMax()) {
        writer.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(*s.resourceSizeMax());
        writer.writeFieldEnd();
    }

    if (s.userLinkedNotebookMax()) {
        writer.writeFieldBegin(
            QStringLiteral("userLinkedNotebookMax"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(*s.userLinkedNotebookMax());
        writer.writeFieldEnd();
    }

    if (s.uploadLimit()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.uploadLimit());
        writer.writeFieldEnd();
    }

    if (s.userNoteCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("userNoteCountMax"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(*s.userNoteCountMax());
        writer.writeFieldEnd();
    }

    if (s.userNotebookCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("userNotebookCountMax"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(*s.userNotebookCountMax());
        writer.writeFieldEnd();
    }

    if (s.userTagCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("userTagCountMax"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(*s.userTagCountMax());
        writer.writeFieldEnd();
    }

    if (s.noteTagCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("noteTagCountMax"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(*s.noteTagCountMax());
        writer.writeFieldEnd();
    }

    if (s.userSavedSearchesMax()) {
        writer.writeFieldBegin(
            QStringLiteral("userSavedSearchesMax"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(*s.userSavedSearchesMax());
        writer.writeFieldEnd();
    }

    if (s.noteResourceCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(*s.noteResourceCountMax());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAccountLimits(
    ThriftBinaryBufferReader & reader,
    AccountLimits & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserMailLimitDaily(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setNoteSizeMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setResourceSizeMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserLinkedNotebookMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploadLimit(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserNoteCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserNotebookCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserTagCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setNoteTagCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUserSavedSearchesMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setNoteResourceCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeUser(
    ThriftBinaryBufferWriter & writer,
    const User & s)
{
    writer.writeStructBegin(QStringLiteral("User"));
    if (s.id()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.id());
        writer.writeFieldEnd();
    }

    if (s.username()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.username());
        writer.writeFieldEnd();
    }

    if (s.email()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.email());
        writer.writeFieldEnd();
    }

    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.timezone()) {
        writer.writeFieldBegin(
            QStringLiteral("timezone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.timezone());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.serviceLevel()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            21);

        writer.writeI32(static_cast<qint32>(*s.serviceLevel()));
        writer.writeFieldEnd();
    }

    if (s.created()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            9);

        writer.writeI64(*s.created());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(*s.updated());
        writer.writeFieldEnd();
    }

    if (s.deleted()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            11);

        writer.writeI64(*s.deleted());
        writer.writeFieldEnd();
    }

    if (s.active()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(*s.active());
        writer.writeFieldEnd();
    }

    if (s.shardId()) {
        writer.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(*s.shardId());
        writer.writeFieldEnd();
    }

    if (s.attributes()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            15);

        writeUserAttributes(writer, *s.attributes());
        writer.writeFieldEnd();
    }

    if (s.accounting()) {
        writer.writeFieldBegin(
            QStringLiteral("accounting"),
            ThriftFieldType::T_STRUCT,
            16);

        writeAccounting(writer, *s.accounting());
        writer.writeFieldEnd();
    }

    if (s.businessUserInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("businessUserInfo"),
            ThriftFieldType::T_STRUCT,
            18);

        writeBusinessUserInfo(writer, *s.businessUserInfo());
        writer.writeFieldEnd();
    }

    if (s.photoUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            19);

        writer.writeString(*s.photoUrl());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            20);

        writer.writeI64(*s.photoLastUpdated());
        writer.writeFieldEnd();
    }

    if (s.accountLimits()) {
        writer.writeFieldBegin(
            QStringLiteral("accountLimits"),
            ThriftFieldType::T_STRUCT,
            22);

        writeAccountLimits(writer, *s.accountLimits());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUser(
    ThriftBinaryBufferReader & reader,
    User & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTimezone(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                PrivilegeLevel v;
                readEnumPrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                s.setServiceLevel(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setDeleted(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setActive(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setShardId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserAttributes v;
                readUserAttributes(reader, v);
                s.setAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Accounting v;
                readAccounting(reader, v);
                s.setAccounting(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserInfo v;
                readBusinessUserInfo(reader, v);
                s.setBusinessUserInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPhotoUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPhotoLastUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                AccountLimits v;
                readAccountLimits(reader, v);
                s.setAccountLimits(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeContact(
    ThriftBinaryBufferWriter & writer,
    const Contact & s)
{
    writer.writeStructBegin(QStringLiteral("Contact"));
    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.id()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.id());
        writer.writeFieldEnd();
    }

    if (s.type()) {
        writer.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.type()));
        writer.writeFieldEnd();
    }

    if (s.photoUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.photoUrl());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.photoLastUpdated());
        writer.writeFieldEnd();
    }

    if (s.messagingPermit()) {
        writer.writeFieldBegin(
            QStringLiteral("messagingPermit"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeBinary(*s.messagingPermit());
        writer.writeFieldEnd();
    }

    if (s.messagingPermitExpires()) {
        writer.writeFieldBegin(
            QStringLiteral("messagingPermitExpires"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.messagingPermitExpires());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readContact(
    ThriftBinaryBufferReader & reader,
    Contact & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ContactType v;
                readEnumContactType(reader, v);
                s.setType(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPhotoUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPhotoLastUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setMessagingPermit(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setMessagingPermitExpires(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeIdentity(
    ThriftBinaryBufferWriter & writer,
    const Identity & s)
{
    writer.writeStructBegin(QStringLiteral("Identity"));
    writer.writeFieldBegin(
        QStringLiteral("id"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.id());
    writer.writeFieldEnd();

    if (s.contact()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            2);

        writeContact(writer, *s.contact());
        writer.writeFieldEnd();
    }

    if (s.userId()) {
        writer.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(*s.userId());
        writer.writeFieldEnd();
    }

    if (s.deactivated()) {
        writer.writeFieldBegin(
            QStringLiteral("deactivated"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.deactivated());
        writer.writeFieldEnd();
    }

    if (s.sameBusiness()) {
        writer.writeFieldBegin(
            QStringLiteral("sameBusiness"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.sameBusiness());
        writer.writeFieldEnd();
    }

    if (s.blocked()) {
        writer.writeFieldBegin(
            QStringLiteral("blocked"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.blocked());
        writer.writeFieldEnd();
    }

    if (s.userConnected()) {
        writer.writeFieldBegin(
            QStringLiteral("userConnected"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.userConnected());
        writer.writeFieldEnd();
    }

    if (s.eventId()) {
        writer.writeFieldBegin(
            QStringLiteral("eventId"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.eventId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readIdentity(
    ThriftBinaryBufferReader & reader,
    Identity & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool id_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                id_isset = true;
                IdentityID v;
                reader.readI64(v);
                s.setId(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(reader, v);
                s.setContact(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setDeactivated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setSameBusiness(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setBlocked(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setUserConnected(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                reader.readI64(v);
                s.setEventId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!id_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Identity.id has no value"));
}

void writeTag(
    ThriftBinaryBufferWriter & writer,
    const Tag & s)
{
    writer.writeStructBegin(QStringLiteral("Tag"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.parentGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("parentGuid"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.parentGuid());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readTag(
    ThriftBinaryBufferReader & reader,
    Tag & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setParentGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeLazyMap(
    ThriftBinaryBufferWriter & writer,
    const LazyMap & s)
{
    writer.writeStructBegin(QStringLiteral("LazyMap"));
    if (s.keysOnly()) {
        writer.writeFieldBegin(
            QStringLiteral("keysOnly"),
            ThriftFieldType::T_SET,
            1);

        writer.writeSetBegin(ThriftFieldType::T_STRING, s.keysOnly()->count());
        for(const auto & value: qAsConst(*s.keysOnly())) {
            writer.writeString(value);
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    if (s.fullMap()) {
        writer.writeFieldBegin(
            QStringLiteral("fullMap"),
            ThriftFieldType::T_MAP,
            2);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.fullMap()->size());
        for(const auto & it: toRange(*s.fullMap())) {
            writer.writeString(it.key());
            writer.writeString(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readLazyMap(
    ThriftBinaryBufferReader & reader,
    LazyMap & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (LazyMap.keysOnly)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.setKeysOnly(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (LazyMap.fullMap)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (LazyMap.fullMap)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    reader.readString(key);
                    QString value;
                    reader.readString(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.setFullMap(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeResourceAttributes(
    ThriftBinaryBufferWriter & writer,
    const ResourceAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("ResourceAttributes"));
    if (s.sourceURL()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.sourceURL());
        writer.writeFieldEnd();
    }

    if (s.timestamp()) {
        writer.writeFieldBegin(
            QStringLiteral("timestamp"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(*s.timestamp());
        writer.writeFieldEnd();
    }

    if (s.latitude()) {
        writer.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            3);

        writer.writeDouble(*s.latitude());
        writer.writeFieldEnd();
    }

    if (s.longitude()) {
        writer.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            4);

        writer.writeDouble(*s.longitude());
        writer.writeFieldEnd();
    }

    if (s.altitude()) {
        writer.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            5);

        writer.writeDouble(*s.altitude());
        writer.writeFieldEnd();
    }

    if (s.cameraMake()) {
        writer.writeFieldBegin(
            QStringLiteral("cameraMake"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.cameraMake());
        writer.writeFieldEnd();
    }

    if (s.cameraModel()) {
        writer.writeFieldBegin(
            QStringLiteral("cameraModel"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(*s.cameraModel());
        writer.writeFieldEnd();
    }

    if (s.clientWillIndex()) {
        writer.writeFieldBegin(
            QStringLiteral("clientWillIndex"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.clientWillIndex());
        writer.writeFieldEnd();
    }

    if (s.recoType()) {
        writer.writeFieldBegin(
            QStringLiteral("recoType"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.recoType());
        writer.writeFieldEnd();
    }

    if (s.fileName()) {
        writer.writeFieldBegin(
            QStringLiteral("fileName"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(*s.fileName());
        writer.writeFieldEnd();
    }

    if (s.attachment()) {
        writer.writeFieldBegin(
            QStringLiteral("attachment"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(*s.attachment());
        writer.writeFieldEnd();
    }

    if (s.applicationData()) {
        writer.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            12);

        writeLazyMap(writer, *s.applicationData());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readResourceAttributes(
    ThriftBinaryBufferReader & reader,
    ResourceAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceURL(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setTimestamp(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setLatitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setLongitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setAltitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setCameraMake(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setCameraModel(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setClientWillIndex(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRecoType(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setFileName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setAttachment(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(reader, v);
                s.setApplicationData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeResource(
    ThriftBinaryBufferWriter & writer,
    const Resource & s)
{
    writer.writeStructBegin(QStringLiteral("Resource"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.noteGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.noteGuid());
        writer.writeFieldEnd();
    }

    if (s.data()) {
        writer.writeFieldBegin(
            QStringLiteral("data"),
            ThriftFieldType::T_STRUCT,
            3);

        writeData(writer, *s.data());
        writer.writeFieldEnd();
    }

    if (s.mime()) {
        writer.writeFieldBegin(
            QStringLiteral("mime"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.mime());
        writer.writeFieldEnd();
    }

    if (s.width()) {
        writer.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I16,
            5);

        writer.writeI16(*s.width());
        writer.writeFieldEnd();
    }

    if (s.height()) {
        writer.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I16,
            6);

        writer.writeI16(*s.height());
        writer.writeFieldEnd();
    }

    if (s.duration()) {
        writer.writeFieldBegin(
            QStringLiteral("duration"),
            ThriftFieldType::T_I16,
            7);

        writer.writeI16(*s.duration());
        writer.writeFieldEnd();
    }

    if (s.active()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.active());
        writer.writeFieldEnd();
    }

    if (s.recognition()) {
        writer.writeFieldBegin(
            QStringLiteral("recognition"),
            ThriftFieldType::T_STRUCT,
            9);

        writeData(writer, *s.recognition());
        writer.writeFieldEnd();
    }

    if (s.attributes()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            11);

        writeResourceAttributes(writer, *s.attributes());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.alternateData()) {
        writer.writeFieldBegin(
            QStringLiteral("alternateData"),
            ThriftFieldType::T_STRUCT,
            13);

        writeData(writer, *s.alternateData());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readResource(
    ThriftBinaryBufferReader & reader,
    Resource & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setNoteGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.setData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setMime(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.setWidth(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.setHeight(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.setDuration(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setActive(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.setRecognition(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ResourceAttributes v;
                readResourceAttributes(reader, v);
                s.setAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.setAlternateData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteAttributes(
    ThriftBinaryBufferWriter & writer,
    const NoteAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("NoteAttributes"));
    if (s.subjectDate()) {
        writer.writeFieldBegin(
            QStringLiteral("subjectDate"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(*s.subjectDate());
        writer.writeFieldEnd();
    }

    if (s.latitude()) {
        writer.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            10);

        writer.writeDouble(*s.latitude());
        writer.writeFieldEnd();
    }

    if (s.longitude()) {
        writer.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            11);

        writer.writeDouble(*s.longitude());
        writer.writeFieldEnd();
    }

    if (s.altitude()) {
        writer.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            12);

        writer.writeDouble(*s.altitude());
        writer.writeFieldEnd();
    }

    if (s.author()) {
        writer.writeFieldBegin(
            QStringLiteral("author"),
            ThriftFieldType::T_STRING,
            13);

        writer.writeString(*s.author());
        writer.writeFieldEnd();
    }

    if (s.source()) {
        writer.writeFieldBegin(
            QStringLiteral("source"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(*s.source());
        writer.writeFieldEnd();
    }

    if (s.sourceURL()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            15);

        writer.writeString(*s.sourceURL());
        writer.writeFieldEnd();
    }

    if (s.sourceApplication()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceApplication"),
            ThriftFieldType::T_STRING,
            16);

        writer.writeString(*s.sourceApplication());
        writer.writeFieldEnd();
    }

    if (s.shareDate()) {
        writer.writeFieldBegin(
            QStringLiteral("shareDate"),
            ThriftFieldType::T_I64,
            17);

        writer.writeI64(*s.shareDate());
        writer.writeFieldEnd();
    }

    if (s.reminderOrder()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderOrder"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(*s.reminderOrder());
        writer.writeFieldEnd();
    }

    if (s.reminderDoneTime()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderDoneTime"),
            ThriftFieldType::T_I64,
            19);

        writer.writeI64(*s.reminderDoneTime());
        writer.writeFieldEnd();
    }

    if (s.reminderTime()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderTime"),
            ThriftFieldType::T_I64,
            20);

        writer.writeI64(*s.reminderTime());
        writer.writeFieldEnd();
    }

    if (s.placeName()) {
        writer.writeFieldBegin(
            QStringLiteral("placeName"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(*s.placeName());
        writer.writeFieldEnd();
    }

    if (s.contentClass()) {
        writer.writeFieldBegin(
            QStringLiteral("contentClass"),
            ThriftFieldType::T_STRING,
            22);

        writer.writeString(*s.contentClass());
        writer.writeFieldEnd();
    }

    if (s.applicationData()) {
        writer.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            23);

        writeLazyMap(writer, *s.applicationData());
        writer.writeFieldEnd();
    }

    if (s.lastEditedBy()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditedBy"),
            ThriftFieldType::T_STRING,
            24);

        writer.writeString(*s.lastEditedBy());
        writer.writeFieldEnd();
    }

    if (s.classifications()) {
        writer.writeFieldBegin(
            QStringLiteral("classifications"),
            ThriftFieldType::T_MAP,
            26);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.classifications()->size());
        for(const auto & it: toRange(*s.classifications())) {
            writer.writeString(it.key());
            writer.writeString(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.creatorId()) {
        writer.writeFieldBegin(
            QStringLiteral("creatorId"),
            ThriftFieldType::T_I32,
            27);

        writer.writeI32(*s.creatorId());
        writer.writeFieldEnd();
    }

    if (s.lastEditorId()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            28);

        writer.writeI32(*s.lastEditorId());
        writer.writeFieldEnd();
    }

    if (s.sharedWithBusiness()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedWithBusiness"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(*s.sharedWithBusiness());
        writer.writeFieldEnd();
    }

    if (s.conflictSourceNoteGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("conflictSourceNoteGuid"),
            ThriftFieldType::T_STRING,
            30);

        writer.writeString(*s.conflictSourceNoteGuid());
        writer.writeFieldEnd();
    }

    if (s.noteTitleQuality()) {
        writer.writeFieldBegin(
            QStringLiteral("noteTitleQuality"),
            ThriftFieldType::T_I32,
            31);

        writer.writeI32(*s.noteTitleQuality());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteAttributes(
    ThriftBinaryBufferReader & reader,
    NoteAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setSubjectDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setLatitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setLongitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setAltitude(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setAuthor(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSource(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceURL(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceApplication(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setShareDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setReminderOrder(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setReminderDoneTime(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setReminderTime(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPlaceName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContentClass(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(reader, v);
                s.setApplicationData(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setLastEditedBy(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteAttributes.classifications)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteAttributes.classifications)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    reader.readString(key);
                    QString value;
                    reader.readString(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.setClassifications(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setCreatorId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setLastEditorId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setSharedWithBusiness(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setConflictSourceNoteGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setNoteTitleQuality(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSharedNote(
    ThriftBinaryBufferWriter & writer,
    const SharedNote & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNote"));
    if (s.sharerUserID()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserID"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.sharerUserID());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentity()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentity"),
            ThriftFieldType::T_STRUCT,
            2);

        writeIdentity(writer, *s.recipientIdentity());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.serviceCreated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(*s.serviceCreated());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.serviceUpdated());
        writer.writeFieldEnd();
    }

    if (s.serviceAssigned()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(*s.serviceAssigned());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNote(
    ThriftBinaryBufferReader & reader,
    SharedNote & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserID(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Identity v;
                readIdentity(reader, v);
                s.setRecipientIdentity(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceAssigned(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NoteRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NoteRestrictions"));
    if (s.noUpdateTitle()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateTitle"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.noUpdateTitle());
        writer.writeFieldEnd();
    }

    if (s.noUpdateContent()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateContent"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.noUpdateContent());
        writer.writeFieldEnd();
    }

    if (s.noEmail()) {
        writer.writeFieldBegin(
            QStringLiteral("noEmail"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.noEmail());
        writer.writeFieldEnd();
    }

    if (s.noShare()) {
        writer.writeFieldBegin(
            QStringLiteral("noShare"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.noShare());
        writer.writeFieldEnd();
    }

    if (s.noSharePublicly()) {
        writer.writeFieldBegin(
            QStringLiteral("noSharePublicly"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.noSharePublicly());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteRestrictions(
    ThriftBinaryBufferReader & reader,
    NoteRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoUpdateTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoUpdateContent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoShare(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSharePublicly(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNoteLimits(
    ThriftBinaryBufferWriter & writer,
    const NoteLimits & s)
{
    writer.writeStructBegin(QStringLiteral("NoteLimits"));
    if (s.noteResourceCountMax()) {
        writer.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.noteResourceCountMax());
        writer.writeFieldEnd();
    }

    if (s.uploadLimit()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(*s.uploadLimit());
        writer.writeFieldEnd();
    }

    if (s.resourceSizeMax()) {
        writer.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(*s.resourceSizeMax());
        writer.writeFieldEnd();
    }

    if (s.noteSizeMax()) {
        writer.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(*s.noteSizeMax());
        writer.writeFieldEnd();
    }

    if (s.uploaded()) {
        writer.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(*s.uploaded());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteLimits(
    ThriftBinaryBufferReader & reader,
    NoteLimits & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setNoteResourceCountMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploadLimit(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setResourceSizeMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setNoteSizeMax(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUploaded(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNote(
    ThriftBinaryBufferWriter & writer,
    const Note & s)
{
    writer.writeStructBegin(QStringLiteral("Note"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.title()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.title());
        writer.writeFieldEnd();
    }

    if (s.content()) {
        writer.writeFieldBegin(
            QStringLiteral("content"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.content());
        writer.writeFieldEnd();
    }

    if (s.contentHash()) {
        writer.writeFieldBegin(
            QStringLiteral("contentHash"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeBinary(*s.contentHash());
        writer.writeFieldEnd();
    }

    if (s.contentLength()) {
        writer.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.contentLength());
        writer.writeFieldEnd();
    }

    if (s.created()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(*s.created());
        writer.writeFieldEnd();
    }

    if (s.updated()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.updated());
        writer.writeFieldEnd();
    }

    if (s.deleted()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.deleted());
        writer.writeFieldEnd();
    }

    if (s.active()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(*s.active());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.tagGuids()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids()->length());
        for(const auto & value: qAsConst(*s.tagGuids())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.resources()) {
        writer.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.resources()->length());
        for(const auto & value: qAsConst(*s.resources())) {
            writeResource(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.attributes()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);

        writeNoteAttributes(writer, *s.attributes());
        writer.writeFieldEnd();
    }

    if (s.tagNames()) {
        writer.writeFieldBegin(
            QStringLiteral("tagNames"),
            ThriftFieldType::T_LIST,
            15);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagNames()->length());
        for(const auto & value: qAsConst(*s.tagNames())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.sharedNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotes"),
            ThriftFieldType::T_LIST,
            16);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotes()->length());
        for(const auto & value: qAsConst(*s.sharedNotes())) {
            writeSharedNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.restrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);

        writeNoteRestrictions(writer, *s.restrictions());
        writer.writeFieldEnd();
    }

    if (s.limits()) {
        writer.writeFieldBegin(
            QStringLiteral("limits"),
            ThriftFieldType::T_STRUCT,
            18);

        writeNoteLimits(writer, *s.limits());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNote(
    ThriftBinaryBufferReader & reader,
    Note & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContent(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.setContentHash(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setContentLength(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setDeleted(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setActive(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTagGuids(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.resources)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setResources(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(reader, v);
                s.setAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.tagNames)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setTagNames(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNote> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.sharedNotes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNote elem;
                    readSharedNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSharedNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteRestrictions v;
                readNoteRestrictions(reader, v);
                s.setRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteLimits v;
                readNoteLimits(reader, v);
                s.setLimits(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writePublishing(
    ThriftBinaryBufferWriter & writer,
    const Publishing & s)
{
    writer.writeStructBegin(QStringLiteral("Publishing"));
    if (s.uri()) {
        writer.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.uri());
        writer.writeFieldEnd();
    }

    if (s.order()) {
        writer.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(static_cast<qint32>(*s.order()));
        writer.writeFieldEnd();
    }

    if (s.ascending()) {
        writer.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.ascending());
        writer.writeFieldEnd();
    }

    if (s.publicDescription()) {
        writer.writeFieldBegin(
            QStringLiteral("publicDescription"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.publicDescription());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readPublishing(
    ThriftBinaryBufferReader & reader,
    Publishing & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUri(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                NoteSortOrder v;
                readEnumNoteSortOrder(reader, v);
                s.setOrder(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setAscending(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPublicDescription(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeBusinessNotebook(
    ThriftBinaryBufferWriter & writer,
    const BusinessNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessNotebook"));
    if (s.notebookDescription()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookDescription"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.notebookDescription());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.recommended()) {
        writer.writeFieldBegin(
            QStringLiteral("recommended"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.recommended());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessNotebook(
    ThriftBinaryBufferReader & reader,
    BusinessNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNotebookDescription(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setRecommended(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSavedSearchScope(
    ThriftBinaryBufferWriter & writer,
    const SavedSearchScope & s)
{
    writer.writeStructBegin(QStringLiteral("SavedSearchScope"));
    if (s.includeAccount()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAccount"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.includeAccount());
        writer.writeFieldEnd();
    }

    if (s.includePersonalLinkedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includePersonalLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.includePersonalLinkedNotebooks());
        writer.writeFieldEnd();
    }

    if (s.includeBusinessLinkedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("includeBusinessLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.includeBusinessLinkedNotebooks());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSavedSearchScope(
    ThriftBinaryBufferReader & reader,
    SavedSearchScope & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeAccount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludePersonalLinkedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setIncludeBusinessLinkedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSavedSearch(
    ThriftBinaryBufferWriter & writer,
    const SavedSearch & s)
{
    writer.writeStructBegin(QStringLiteral("SavedSearch"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.query()) {
        writer.writeFieldBegin(
            QStringLiteral("query"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.query());
        writer.writeFieldEnd();
    }

    if (s.format()) {
        writer.writeFieldBegin(
            QStringLiteral("format"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(*s.format()));
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.scope()) {
        writer.writeFieldBegin(
            QStringLiteral("scope"),
            ThriftFieldType::T_STRUCT,
            6);

        writeSavedSearchScope(writer, *s.scope());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSavedSearch(
    ThriftBinaryBufferReader & reader,
    SavedSearch & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setQuery(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                QueryFormat v;
                readEnumQueryFormat(reader, v);
                s.setFormat(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearchScope v;
                readSavedSearchScope(reader, v);
                s.setScope(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSharedNotebookRecipientSettings(
    ThriftBinaryBufferWriter & writer,
    const SharedNotebookRecipientSettings & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNotebookRecipientSettings"));
    if (s.reminderNotifyEmail()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.reminderNotifyEmail());
        writer.writeFieldEnd();
    }

    if (s.reminderNotifyInApp()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.reminderNotifyInApp());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNotebookRecipientSettings(
    ThriftBinaryBufferReader & reader,
    SharedNotebookRecipientSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setReminderNotifyEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setReminderNotifyInApp(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNotebookRecipientSettings(
    ThriftBinaryBufferWriter & writer,
    const NotebookRecipientSettings & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookRecipientSettings"));
    if (s.reminderNotifyEmail()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.reminderNotifyEmail());
        writer.writeFieldEnd();
    }

    if (s.reminderNotifyInApp()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.reminderNotifyInApp());
        writer.writeFieldEnd();
    }

    if (s.inMyList()) {
        writer.writeFieldBegin(
            QStringLiteral("inMyList"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.inMyList());
        writer.writeFieldEnd();
    }

    if (s.stack()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.stack());
        writer.writeFieldEnd();
    }

    if (s.recipientStatus()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientStatus"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(static_cast<qint32>(*s.recipientStatus()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookRecipientSettings(
    ThriftBinaryBufferReader & reader,
    NotebookRecipientSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setReminderNotifyEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setReminderNotifyInApp(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setInMyList(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setStack(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                RecipientStatus v;
                readEnumRecipientStatus(reader, v);
                s.setRecipientStatus(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeSharedNotebook(
    ThriftBinaryBufferWriter & writer,
    const SharedNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNotebook"));
    if (s.id()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(*s.id());
        writer.writeFieldEnd();
    }

    if (s.userId()) {
        writer.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.userId());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.notebookGuid());
        writer.writeFieldEnd();
    }

    if (s.email()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.email());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentityId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(*s.recipientIdentityId());
        writer.writeFieldEnd();
    }

    if (s.notebookModifiable()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookModifiable"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.notebookModifiable());
        writer.writeFieldEnd();
    }

    if (s.serviceCreated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.serviceCreated());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(*s.serviceUpdated());
        writer.writeFieldEnd();
    }

    if (s.globalId()) {
        writer.writeFieldBegin(
            QStringLiteral("globalId"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.globalId());
        writer.writeFieldEnd();
    }

    if (s.username()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.username());
        writer.writeFieldEnd();
    }

    if (s.privilege()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(static_cast<qint32>(*s.privilege()));
        writer.writeFieldEnd();
    }

    if (s.recipientSettings()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            13);

        writeSharedNotebookRecipientSettings(writer, *s.recipientSettings());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            14);

        writer.writeI32(*s.sharerUserId());
        writer.writeFieldEnd();
    }

    if (s.recipientUsername()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUsername"),
            ThriftFieldType::T_STRING,
            15);

        writer.writeString(*s.recipientUsername());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            17);

        writer.writeI32(*s.recipientUserId());
        writer.writeFieldEnd();
    }

    if (s.serviceAssigned()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            16);

        writer.writeI64(*s.serviceAssigned());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNotebook(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setNotebookGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.setRecipientIdentityId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNotebookModifiable(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setGlobalId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.setPrivilege(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebookRecipientSettings v;
                readSharedNotebookRecipientSettings(reader, v);
                s.setRecipientSettings(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setSharerUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setRecipientUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setRecipientUserId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceAssigned(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeCanMoveToContainerRestrictions(
    ThriftBinaryBufferWriter & writer,
    const CanMoveToContainerRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("CanMoveToContainerRestrictions"));
    if (s.canMoveToContainer()) {
        writer.writeFieldBegin(
            QStringLiteral("canMoveToContainer"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(static_cast<qint32>(*s.canMoveToContainer()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readCanMoveToContainerRestrictions(
    ThriftBinaryBufferReader & reader,
    CanMoveToContainerRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                CanMoveToContainerStatus v;
                readEnumCanMoveToContainerStatus(reader, v);
                s.setCanMoveToContainer(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNotebookRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NotebookRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookRestrictions"));
    if (s.noReadNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noReadNotes"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(*s.noReadNotes());
        writer.writeFieldEnd();
    }

    if (s.noCreateNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateNotes"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(*s.noCreateNotes());
        writer.writeFieldEnd();
    }

    if (s.noUpdateNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateNotes"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(*s.noUpdateNotes());
        writer.writeFieldEnd();
    }

    if (s.noExpungeNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeNotes"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.noExpungeNotes());
        writer.writeFieldEnd();
    }

    if (s.noShareNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noShareNotes"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.noShareNotes());
        writer.writeFieldEnd();
    }

    if (s.noEmailNotes()) {
        writer.writeFieldBegin(
            QStringLiteral("noEmailNotes"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.noEmailNotes());
        writer.writeFieldEnd();
    }

    if (s.noSendMessageToRecipients()) {
        writer.writeFieldBegin(
            QStringLiteral("noSendMessageToRecipients"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.noSendMessageToRecipients());
        writer.writeFieldEnd();
    }

    if (s.noUpdateNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateNotebook"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.noUpdateNotebook());
        writer.writeFieldEnd();
    }

    if (s.noExpungeNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeNotebook"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(*s.noExpungeNotebook());
        writer.writeFieldEnd();
    }

    if (s.noSetDefaultNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetDefaultNotebook"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(*s.noSetDefaultNotebook());
        writer.writeFieldEnd();
    }

    if (s.noSetNotebookStack()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetNotebookStack"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(*s.noSetNotebookStack());
        writer.writeFieldEnd();
    }

    if (s.noPublishToPublic()) {
        writer.writeFieldBegin(
            QStringLiteral("noPublishToPublic"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(*s.noPublishToPublic());
        writer.writeFieldEnd();
    }

    if (s.noPublishToBusinessLibrary()) {
        writer.writeFieldBegin(
            QStringLiteral("noPublishToBusinessLibrary"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(*s.noPublishToBusinessLibrary());
        writer.writeFieldEnd();
    }

    if (s.noCreateTags()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateTags"),
            ThriftFieldType::T_BOOL,
            14);

        writer.writeBool(*s.noCreateTags());
        writer.writeFieldEnd();
    }

    if (s.noUpdateTags()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateTags"),
            ThriftFieldType::T_BOOL,
            15);

        writer.writeBool(*s.noUpdateTags());
        writer.writeFieldEnd();
    }

    if (s.noExpungeTags()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeTags"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(*s.noExpungeTags());
        writer.writeFieldEnd();
    }

    if (s.noSetParentTag()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetParentTag"),
            ThriftFieldType::T_BOOL,
            17);

        writer.writeBool(*s.noSetParentTag());
        writer.writeFieldEnd();
    }

    if (s.noCreateSharedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            18);

        writer.writeBool(*s.noCreateSharedNotebooks());
        writer.writeFieldEnd();
    }

    if (s.updateWhichSharedNotebookRestrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("updateWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            19);

        writer.writeI32(static_cast<qint32>(*s.updateWhichSharedNotebookRestrictions()));
        writer.writeFieldEnd();
    }

    if (s.expungeWhichSharedNotebookRestrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("expungeWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            20);

        writer.writeI32(static_cast<qint32>(*s.expungeWhichSharedNotebookRestrictions()));
        writer.writeFieldEnd();
    }

    if (s.noShareNotesWithBusiness()) {
        writer.writeFieldBegin(
            QStringLiteral("noShareNotesWithBusiness"),
            ThriftFieldType::T_BOOL,
            21);

        writer.writeBool(*s.noShareNotesWithBusiness());
        writer.writeFieldEnd();
    }

    if (s.noRenameNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("noRenameNotebook"),
            ThriftFieldType::T_BOOL,
            22);

        writer.writeBool(*s.noRenameNotebook());
        writer.writeFieldEnd();
    }

    if (s.noSetInMyList()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetInMyList"),
            ThriftFieldType::T_BOOL,
            23);

        writer.writeBool(*s.noSetInMyList());
        writer.writeFieldEnd();
    }

    if (s.noChangeContact()) {
        writer.writeFieldBegin(
            QStringLiteral("noChangeContact"),
            ThriftFieldType::T_BOOL,
            24);

        writer.writeBool(*s.noChangeContact());
        writer.writeFieldEnd();
    }

    if (s.canMoveToContainerRestrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("canMoveToContainerRestrictions"),
            ThriftFieldType::T_STRUCT,
            26);

        writeCanMoveToContainerRestrictions(writer, *s.canMoveToContainerRestrictions());
        writer.writeFieldEnd();
    }

    if (s.noSetReminderNotifyEmail()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            27);

        writer.writeBool(*s.noSetReminderNotifyEmail());
        writer.writeFieldEnd();
    }

    if (s.noSetReminderNotifyInApp()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            28);

        writer.writeBool(*s.noSetReminderNotifyInApp());
        writer.writeFieldEnd();
    }

    if (s.noSetRecipientSettingsStack()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetRecipientSettingsStack"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(*s.noSetRecipientSettingsStack());
        writer.writeFieldEnd();
    }

    if (s.noCanMoveNote()) {
        writer.writeFieldBegin(
            QStringLiteral("noCanMoveNote"),
            ThriftFieldType::T_BOOL,
            30);

        writer.writeBool(*s.noCanMoveNote());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookRestrictions(
    ThriftBinaryBufferReader & reader,
    NotebookRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoReadNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoCreateNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoUpdateNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoExpungeNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoShareNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoEmailNotes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSendMessageToRecipients(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoUpdateNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoExpungeNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetDefaultNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetNotebookStack(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoPublishToPublic(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoPublishToBusinessLibrary(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoCreateTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoUpdateTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoExpungeTags(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetParentTag(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoCreateSharedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(reader, v);
                s.setUpdateWhichSharedNotebookRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(reader, v);
                s.setExpungeWhichSharedNotebookRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoShareNotesWithBusiness(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoRenameNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetInMyList(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoChangeContact(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                CanMoveToContainerRestrictions v;
                readCanMoveToContainerRestrictions(reader, v);
                s.setCanMoveToContainerRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetReminderNotifyEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetReminderNotifyInApp(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoSetRecipientSettingsStack(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setNoCanMoveNote(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNotebook(
    ThriftBinaryBufferWriter & writer,
    const Notebook & s)
{
    writer.writeStructBegin(QStringLiteral("Notebook"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.defaultNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultNotebook"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.defaultNotebook());
        writer.writeFieldEnd();
    }

    if (s.serviceCreated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.serviceCreated());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.serviceUpdated());
        writer.writeFieldEnd();
    }

    if (s.publishing()) {
        writer.writeFieldBegin(
            QStringLiteral("publishing"),
            ThriftFieldType::T_STRUCT,
            10);

        writePublishing(writer, *s.publishing());
        writer.writeFieldEnd();
    }

    if (s.published()) {
        writer.writeFieldBegin(
            QStringLiteral("published"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(*s.published());
        writer.writeFieldEnd();
    }

    if (s.stack()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            12);

        writer.writeString(*s.stack());
        writer.writeFieldEnd();
    }

    if (s.sharedNotebookIds()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebookIds"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_I64, s.sharedNotebookIds()->length());
        for(const auto & value: qAsConst(*s.sharedNotebookIds())) {
            writer.writeI64(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.sharedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebooks"),
            ThriftFieldType::T_LIST,
            14);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotebooks()->length());
        for(const auto & value: qAsConst(*s.sharedNotebooks())) {
            writeSharedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.businessNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("businessNotebook"),
            ThriftFieldType::T_STRUCT,
            15);

        writeBusinessNotebook(writer, *s.businessNotebook());
        writer.writeFieldEnd();
    }

    if (s.contact()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            16);

        writeUser(writer, *s.contact());
        writer.writeFieldEnd();
    }

    if (s.restrictions()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);

        writeNotebookRestrictions(writer, *s.restrictions());
        writer.writeFieldEnd();
    }

    if (s.recipientSettings()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            18);

        writeNotebookRecipientSettings(writer, *s.recipientSettings());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebook(
    ThriftBinaryBufferReader & reader,
    Notebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setDefaultNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setServiceUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Publishing v;
                readPublishing(reader, v);
                s.setPublishing(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setPublished(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setStack(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<qint64> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I64) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Notebook.sharedNotebookIds)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    qint64 elem;
                    reader.readI64(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSharedNotebookIds(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Notebook.sharedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setSharedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessNotebook v;
                readBusinessNotebook(reader, v);
                s.setBusinessNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(reader, v);
                s.setContact(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRestrictions v;
                readNotebookRestrictions(reader, v);
                s.setRestrictions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(reader, v);
                s.setRecipientSettings(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeLinkedNotebook(
    ThriftBinaryBufferWriter & writer,
    const LinkedNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("LinkedNotebook"));
    if (s.shareName()) {
        writer.writeFieldBegin(
            QStringLiteral("shareName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.shareName());
        writer.writeFieldEnd();
    }

    if (s.username()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.username());
        writer.writeFieldEnd();
    }

    if (s.shardId()) {
        writer.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.shardId());
        writer.writeFieldEnd();
    }

    if (s.sharedNotebookGlobalId()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebookGlobalId"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.sharedNotebookGlobalId());
        writer.writeFieldEnd();
    }

    if (s.uri()) {
        writer.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.uri());
        writer.writeFieldEnd();
    }

    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(*s.updateSequenceNum());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.noteStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(*s.webApiUrlPrefix());
        writer.writeFieldEnd();
    }

    if (s.stack()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(*s.stack());
        writer.writeFieldEnd();
    }

    if (s.businessId()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(*s.businessId());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readLinkedNotebook(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setShareName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setShardId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSharedNotebookGlobalId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUri(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setUpdateSequenceNum(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWebApiUrlPrefix(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setStack(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setBusinessId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeNotebookDescriptor(
    ThriftBinaryBufferWriter & writer,
    const NotebookDescriptor & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookDescriptor"));
    if (s.guid()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.guid());
        writer.writeFieldEnd();
    }

    if (s.notebookDisplayName()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookDisplayName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.notebookDisplayName());
        writer.writeFieldEnd();
    }

    if (s.contactName()) {
        writer.writeFieldBegin(
            QStringLiteral("contactName"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.contactName());
        writer.writeFieldEnd();
    }

    if (s.hasSharedNotebook()) {
        writer.writeFieldBegin(
            QStringLiteral("hasSharedNotebook"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(*s.hasSharedNotebook());
        writer.writeFieldEnd();
    }

    if (s.joinedUserCount()) {
        writer.writeFieldBegin(
            QStringLiteral("joinedUserCount"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.joinedUserCount());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookDescriptor(
    ThriftBinaryBufferReader & reader,
    NotebookDescriptor & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.setGuid(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNotebookDisplayName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContactName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setHasSharedNotebook(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setJoinedUserCount(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeUserProfile(
    ThriftBinaryBufferWriter & writer,
    const UserProfile & s)
{
    writer.writeStructBegin(QStringLiteral("UserProfile"));
    if (s.id()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.id());
        writer.writeFieldEnd();
    }

    if (s.name()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.name());
        writer.writeFieldEnd();
    }

    if (s.email()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.email());
        writer.writeFieldEnd();
    }

    if (s.username()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.username());
        writer.writeFieldEnd();
    }

    if (s.attributes()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            5);

        writeBusinessUserAttributes(writer, *s.attributes());
        writer.writeFieldEnd();
    }

    if (s.joined()) {
        writer.writeFieldBegin(
            QStringLiteral("joined"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(*s.joined());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.photoLastUpdated());
        writer.writeFieldEnd();
    }

    if (s.photoUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(*s.photoUrl());
        writer.writeFieldEnd();
    }

    if (s.role()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(static_cast<qint32>(*s.role()));
        writer.writeFieldEnd();
    }

    if (s.status()) {
        writer.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(static_cast<qint32>(*s.status()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserProfile(
    ThriftBinaryBufferReader & reader,
    UserProfile & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserAttributes v;
                readBusinessUserAttributes(reader, v);
                s.setAttributes(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setJoined(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setPhotoLastUpdated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setPhotoUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.setRole(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserStatus v;
                readEnumBusinessUserStatus(reader, v);
                s.setStatus(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeRelatedContentImage(
    ThriftBinaryBufferWriter & writer,
    const RelatedContentImage & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedContentImage"));
    if (s.url()) {
        writer.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.url());
        writer.writeFieldEnd();
    }

    if (s.width()) {
        writer.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(*s.width());
        writer.writeFieldEnd();
    }

    if (s.height()) {
        writer.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(*s.height());
        writer.writeFieldEnd();
    }

    if (s.pixelRatio()) {
        writer.writeFieldBegin(
            QStringLiteral("pixelRatio"),
            ThriftFieldType::T_DOUBLE,
            4);

        writer.writeDouble(*s.pixelRatio());
        writer.writeFieldEnd();
    }

    if (s.fileSize()) {
        writer.writeFieldBegin(
            QStringLiteral("fileSize"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.fileSize());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedContentImage(
    ThriftBinaryBufferReader & reader,
    RelatedContentImage & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setWidth(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setHeight(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.setPixelRatio(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setFileSize(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeRelatedContent(
    ThriftBinaryBufferWriter & writer,
    const RelatedContent & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedContent"));
    if (s.contentId()) {
        writer.writeFieldBegin(
            QStringLiteral("contentId"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.contentId());
        writer.writeFieldEnd();
    }

    if (s.title()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.title());
        writer.writeFieldEnd();
    }

    if (s.url()) {
        writer.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.url());
        writer.writeFieldEnd();
    }

    if (s.sourceId()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceId"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.sourceId());
        writer.writeFieldEnd();
    }

    if (s.sourceUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.sourceUrl());
        writer.writeFieldEnd();
    }

    if (s.sourceFaviconUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceFaviconUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.sourceFaviconUrl());
        writer.writeFieldEnd();
    }

    if (s.sourceName()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceName"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(*s.sourceName());
        writer.writeFieldEnd();
    }

    if (s.date()) {
        writer.writeFieldBegin(
            QStringLiteral("date"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.date());
        writer.writeFieldEnd();
    }

    if (s.teaser()) {
        writer.writeFieldBegin(
            QStringLiteral("teaser"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.teaser());
        writer.writeFieldEnd();
    }

    if (s.thumbnails()) {
        writer.writeFieldBegin(
            QStringLiteral("thumbnails"),
            ThriftFieldType::T_LIST,
            10);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.thumbnails()->length());
        for(const auto & value: qAsConst(*s.thumbnails())) {
            writeRelatedContentImage(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.contentType()) {
        writer.writeFieldBegin(
            QStringLiteral("contentType"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(static_cast<qint32>(*s.contentType()));
        writer.writeFieldEnd();
    }

    if (s.accessType()) {
        writer.writeFieldBegin(
            QStringLiteral("accessType"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(static_cast<qint32>(*s.accessType()));
        writer.writeFieldEnd();
    }

    if (s.visibleUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("visibleUrl"),
            ThriftFieldType::T_STRING,
            13);

        writer.writeString(*s.visibleUrl());
        writer.writeFieldEnd();
    }

    if (s.clipUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("clipUrl"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(*s.clipUrl());
        writer.writeFieldEnd();
    }

    if (s.contact()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            15);

        writeContact(writer, *s.contact());
        writer.writeFieldEnd();
    }

    if (s.authors()) {
        writer.writeFieldBegin(
            QStringLiteral("authors"),
            ThriftFieldType::T_LIST,
            16);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.authors()->length());
        for(const auto & value: qAsConst(*s.authors())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedContent(
    ThriftBinaryBufferReader & reader,
    RelatedContent & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setContentId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTitle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceFaviconUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSourceName(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setDate(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setTeaser(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContentImage> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedContent.thumbnails)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentImage elem;
                    readRelatedContentImage(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setThumbnails(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentType v;
                readEnumRelatedContentType(reader, v);
                s.setContentType(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentAccess v;
                readEnumRelatedContentAccess(reader, v);
                s.setAccessType(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setVisibleUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setClipUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(reader, v);
                s.setContact(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedContent.authors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setAuthors(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeBusinessInvitation(
    ThriftBinaryBufferWriter & writer,
    const BusinessInvitation & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessInvitation"));
    if (s.businessId()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(*s.businessId());
        writer.writeFieldEnd();
    }

    if (s.email()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.email());
        writer.writeFieldEnd();
    }

    if (s.role()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(*s.role()));
        writer.writeFieldEnd();
    }

    if (s.status()) {
        writer.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(*s.status()));
        writer.writeFieldEnd();
    }

    if (s.requesterId()) {
        writer.writeFieldBegin(
            QStringLiteral("requesterId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(*s.requesterId());
        writer.writeFieldEnd();
    }

    if (s.fromWorkChat()) {
        writer.writeFieldBegin(
            QStringLiteral("fromWorkChat"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.fromWorkChat());
        writer.writeFieldEnd();
    }

    if (s.created()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(*s.created());
        writer.writeFieldEnd();
    }

    if (s.mostRecentReminder()) {
        writer.writeFieldBegin(
            QStringLiteral("mostRecentReminder"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(*s.mostRecentReminder());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessInvitation(
    ThriftBinaryBufferReader & reader,
    BusinessInvitation & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setBusinessId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setEmail(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.setRole(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessInvitationStatus v;
                readEnumBusinessInvitationStatus(reader, v);
                s.setStatus(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.setRequesterId(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setFromWorkChat(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setCreated(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setMostRecentReminder(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeUserIdentity(
    ThriftBinaryBufferWriter & writer,
    const UserIdentity & s)
{
    writer.writeStructBegin(QStringLiteral("UserIdentity"));
    if (s.type()) {
        writer.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(static_cast<qint32>(*s.type()));
        writer.writeFieldEnd();
    }

    if (s.stringIdentifier()) {
        writer.writeFieldBegin(
            QStringLiteral("stringIdentifier"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.stringIdentifier());
        writer.writeFieldEnd();
    }

    if (s.longIdentifier()) {
        writer.writeFieldBegin(
            QStringLiteral("longIdentifier"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(*s.longIdentifier());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserIdentity(
    ThriftBinaryBufferReader & reader,
    UserIdentity & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserIdentityType v;
                readEnumUserIdentityType(reader, v);
                s.setType(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setStringIdentifier(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.setLongIdentifier(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writePublicUserInfo(
    ThriftBinaryBufferWriter & writer,
    const PublicUserInfo & s)
{
    writer.writeStructBegin(QStringLiteral("PublicUserInfo"));
    writer.writeFieldBegin(
        QStringLiteral("userId"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.userId());
    writer.writeFieldEnd();

    if (s.serviceLevel()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(static_cast<qint32>(*s.serviceLevel()));
        writer.writeFieldEnd();
    }

    if (s.username()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.username());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.noteStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.webApiUrlPrefix());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readPublicUserInfo(
    ThriftBinaryBufferReader & reader,
    PublicUserInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool userId_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                userId_isset = true;
                UserID v;
                reader.readI32(v);
                s.setUserId(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                s.setServiceLevel(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUsername(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWebApiUrlPrefix(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!userId_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("PublicUserInfo.userId has no value"));
}

void writeUserUrls(
    ThriftBinaryBufferWriter & writer,
    const UserUrls & s)
{
    writer.writeStructBegin(QStringLiteral("UserUrls"));
    if (s.noteStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.noteStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.webApiUrlPrefix());
        writer.writeFieldEnd();
    }

    if (s.userStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("userStoreUrl"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(*s.userStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.utilityUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("utilityUrl"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(*s.utilityUrl());
        writer.writeFieldEnd();
    }

    if (s.messageStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("messageStoreUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(*s.messageStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.userWebSocketUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("userWebSocketUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.userWebSocketUrl());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserUrls(
    ThriftBinaryBufferReader & reader,
    UserUrls & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWebApiUrlPrefix(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUserStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUtilityUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setMessageStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setUserWebSocketUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeAuthenticationResult(
    ThriftBinaryBufferWriter & writer,
    const AuthenticationResult & s)
{
    writer.writeStructBegin(QStringLiteral("AuthenticationResult"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(s.authenticationToken());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("expiration"),
        ThriftFieldType::T_I64,
        3);

    writer.writeI64(s.expiration());
    writer.writeFieldEnd();

    if (s.user()) {
        writer.writeFieldBegin(
            QStringLiteral("user"),
            ThriftFieldType::T_STRUCT,
            4);

        writeUser(writer, *s.user());
        writer.writeFieldEnd();
    }

    if (s.publicUserInfo()) {
        writer.writeFieldBegin(
            QStringLiteral("publicUserInfo"),
            ThriftFieldType::T_STRUCT,
            5);

        writePublicUserInfo(writer, *s.publicUserInfo());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(*s.noteStoreUrl());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(*s.webApiUrlPrefix());
        writer.writeFieldEnd();
    }

    if (s.secondFactorRequired()) {
        writer.writeFieldBegin(
            QStringLiteral("secondFactorRequired"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.secondFactorRequired());
        writer.writeFieldEnd();
    }

    if (s.secondFactorDeliveryHint()) {
        writer.writeFieldBegin(
            QStringLiteral("secondFactorDeliveryHint"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(*s.secondFactorDeliveryHint());
        writer.writeFieldEnd();
    }

    if (s.urls()) {
        writer.writeFieldBegin(
            QStringLiteral("urls"),
            ThriftFieldType::T_STRUCT,
            10);

        writeUserUrls(writer, *s.urls());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAuthenticationResult(
    ThriftBinaryBufferReader & reader,
    AuthenticationResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool authenticationToken_isset = false;
    bool expiration_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setCurrentTime(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                authenticationToken_isset = true;
                QString v;
                reader.readString(v);
                s.setAuthenticationToken(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                expiration_isset = true;
                qint64 v;
                reader.readI64(v);
                s.setExpiration(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(reader, v);
                s.setUser(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                PublicUserInfo v;
                readPublicUserInfo(reader, v);
                s.setPublicUserInfo(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setNoteStoreUrl(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setWebApiUrlPrefix(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setSecondFactorRequired(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setSecondFactorDeliveryHint(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserUrls v;
                readUserUrls(reader, v);
                s.setUrls(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.currentTime has no value"));
    if (!authenticationToken_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.authenticationToken has no value"));
    if (!expiration_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.expiration has no value"));
}

void writeBootstrapSettings(
    ThriftBinaryBufferWriter & writer,
    const BootstrapSettings & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapSettings"));
    writer.writeFieldBegin(
        QStringLiteral("serviceHost"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.serviceHost());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("marketingUrl"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(s.marketingUrl());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("supportUrl"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(s.supportUrl());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("accountEmailDomain"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(s.accountEmailDomain());
    writer.writeFieldEnd();

    if (s.enableFacebookSharing()) {
        writer.writeFieldBegin(
            QStringLiteral("enableFacebookSharing"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(*s.enableFacebookSharing());
        writer.writeFieldEnd();
    }

    if (s.enableGiftSubscriptions()) {
        writer.writeFieldBegin(
            QStringLiteral("enableGiftSubscriptions"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(*s.enableGiftSubscriptions());
        writer.writeFieldEnd();
    }

    if (s.enableSupportTickets()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSupportTickets"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(*s.enableSupportTickets());
        writer.writeFieldEnd();
    }

    if (s.enableSharedNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(*s.enableSharedNotebooks());
        writer.writeFieldEnd();
    }

    if (s.enableSingleNoteSharing()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSingleNoteSharing"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(*s.enableSingleNoteSharing());
        writer.writeFieldEnd();
    }

    if (s.enableSponsoredAccounts()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSponsoredAccounts"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(*s.enableSponsoredAccounts());
        writer.writeFieldEnd();
    }

    if (s.enableTwitterSharing()) {
        writer.writeFieldBegin(
            QStringLiteral("enableTwitterSharing"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(*s.enableTwitterSharing());
        writer.writeFieldEnd();
    }

    if (s.enableLinkedInSharing()) {
        writer.writeFieldBegin(
            QStringLiteral("enableLinkedInSharing"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(*s.enableLinkedInSharing());
        writer.writeFieldEnd();
    }

    if (s.enablePublicNotebooks()) {
        writer.writeFieldBegin(
            QStringLiteral("enablePublicNotebooks"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(*s.enablePublicNotebooks());
        writer.writeFieldEnd();
    }

    if (s.enableGoogle()) {
        writer.writeFieldBegin(
            QStringLiteral("enableGoogle"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(*s.enableGoogle());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapSettings(
    ThriftBinaryBufferReader & reader,
    BootstrapSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool serviceHost_isset = false;
    bool marketingUrl_isset = false;
    bool supportUrl_isset = false;
    bool accountEmailDomain_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                serviceHost_isset = true;
                QString v;
                reader.readString(v);
                s.setServiceHost(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                marketingUrl_isset = true;
                QString v;
                reader.readString(v);
                s.setMarketingUrl(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                supportUrl_isset = true;
                QString v;
                reader.readString(v);
                s.setSupportUrl(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                accountEmailDomain_isset = true;
                QString v;
                reader.readString(v);
                s.setAccountEmailDomain(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableFacebookSharing(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableGiftSubscriptions(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableSupportTickets(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableSharedNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableSingleNoteSharing(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableSponsoredAccounts(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableTwitterSharing(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableLinkedInSharing(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnablePublicNotebooks(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.setEnableGoogle(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!serviceHost_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.serviceHost has no value"));
    if (!marketingUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.marketingUrl has no value"));
    if (!supportUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.supportUrl has no value"));
    if (!accountEmailDomain_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.accountEmailDomain has no value"));
}

void writeBootstrapProfile(
    ThriftBinaryBufferWriter & writer,
    const BootstrapProfile & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapProfile"));
    writer.writeFieldBegin(
        QStringLiteral("name"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.name());
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("settings"),
        ThriftFieldType::T_STRUCT,
        2);

    writeBootstrapSettings(writer, s.settings());
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapProfile(
    ThriftBinaryBufferReader & reader,
    BootstrapProfile & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool name_isset = false;
    bool settings_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                name_isset = true;
                QString v;
                reader.readString(v);
                s.setName(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                settings_isset = true;
                BootstrapSettings v;
                readBootstrapSettings(reader, v);
                s.setSettings(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!name_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.name has no value"));
    if (!settings_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.settings has no value"));
}

void writeBootstrapInfo(
    ThriftBinaryBufferWriter & writer,
    const BootstrapInfo & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapInfo"));
    writer.writeFieldBegin(
        QStringLiteral("profiles"),
        ThriftFieldType::T_LIST,
        1);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.profiles().length());
    for(const auto & value: qAsConst(s.profiles())) {
        writeBootstrapProfile(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapInfo(
    ThriftBinaryBufferReader & reader,
    BootstrapInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool profiles_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                profiles_isset = true;
                QList<BootstrapProfile> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (BootstrapInfo.profiles)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    BootstrapProfile elem;
                    readBootstrapProfile(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setProfiles(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!profiles_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapInfo.profiles has no value"));
}

void writeEDAMUserException(
    ThriftBinaryBufferWriter & writer,
    const EDAMUserException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMUserException"));
    writer.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(static_cast<qint32>(s.errorCode()));
    writer.writeFieldEnd();

    if (s.parameter()) {
        writer.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.parameter());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMUserException(
    ThriftBinaryBufferReader & reader,
    EDAMUserException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(reader, v);
                s.setErrorCode(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setParameter(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMUserException.errorCode has no value"));
}

void writeEDAMSystemException(
    ThriftBinaryBufferWriter & writer,
    const EDAMSystemException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMSystemException"));
    writer.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(static_cast<qint32>(s.errorCode()));
    writer.writeFieldEnd();

    if (s.message()) {
        writer.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.message());
        writer.writeFieldEnd();
    }

    if (s.rateLimitDuration()) {
        writer.writeFieldBegin(
            QStringLiteral("rateLimitDuration"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(*s.rateLimitDuration());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMSystemException(
    ThriftBinaryBufferReader & reader,
    EDAMSystemException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(reader, v);
                s.setErrorCode(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setMessage(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.setRateLimitDuration(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMSystemException.errorCode has no value"));
}

void writeEDAMNotFoundException(
    ThriftBinaryBufferWriter & writer,
    const EDAMNotFoundException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMNotFoundException"));
    if (s.identifier()) {
        writer.writeFieldBegin(
            QStringLiteral("identifier"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(*s.identifier());
        writer.writeFieldEnd();
    }

    if (s.key()) {
        writer.writeFieldBegin(
            QStringLiteral("key"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.key());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMNotFoundException(
    ThriftBinaryBufferReader & reader,
    EDAMNotFoundException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setIdentifier(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setKey(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void writeEDAMInvalidContactsException(
    ThriftBinaryBufferWriter & writer,
    const EDAMInvalidContactsException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMInvalidContactsException"));
    writer.writeFieldBegin(
        QStringLiteral("contacts"),
        ThriftFieldType::T_LIST,
        1);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.contacts().length());
    for(const auto & value: qAsConst(s.contacts())) {
        writeContact(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.parameter()) {
        writer.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(*s.parameter());
        writer.writeFieldEnd();
    }

    if (s.reasons()) {
        writer.writeFieldBegin(
            QStringLiteral("reasons"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_I32, s.reasons()->length());
        for(const auto & value: qAsConst(*s.reasons())) {
            writer.writeI32(static_cast<qint32>(value));
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMInvalidContactsException(
    ThriftBinaryBufferReader & reader,
    EDAMInvalidContactsException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool contacts_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                contacts_isset = true;
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (EDAMInvalidContactsException.contacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setContacts(v);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.setParameter(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<EDAMInvalidContactReason> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (EDAMInvalidContactsException.reasons)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    EDAMInvalidContactReason elem;
                    readEnumEDAMInvalidContactReason(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.setReasons(std::make_optional(v));
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!contacts_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMInvalidContactsException.contacts has no value"));
}

/** @endcond */

} // namespace qevercloud
