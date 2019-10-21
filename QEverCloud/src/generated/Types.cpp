/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/Types.h>
#include "../Impl.h"
#include "../Impl.h"
#include "Types_io.h"
#include <Helpers.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/** @cond HIDDEN_SYMBOLS  */

void readEnumEDAMErrorCode(ThriftBinaryBufferReader & r, EDAMErrorCode & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumEDAMInvalidContactReason(ThriftBinaryBufferReader & r, EDAMInvalidContactReason & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMInvalidContactReason::BAD_ADDRESS): e = EDAMInvalidContactReason::BAD_ADDRESS; break;
    case static_cast<int>(EDAMInvalidContactReason::DUPLICATE_CONTACT): e = EDAMInvalidContactReason::DUPLICATE_CONTACT; break;
    case static_cast<int>(EDAMInvalidContactReason::NO_CONNECTION): e = EDAMInvalidContactReason::NO_CONNECTION; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMInvalidContactReason"));
    }
}

void readEnumShareRelationshipPrivilegeLevel(ThriftBinaryBufferReader & r, ShareRelationshipPrivilegeLevel & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::FULL_ACCESS): e = ShareRelationshipPrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ShareRelationshipPrivilegeLevel"));
    }
}

void readEnumPrivilegeLevel(ThriftBinaryBufferReader & r, PrivilegeLevel & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumServiceLevel(ThriftBinaryBufferReader & r, ServiceLevel & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ServiceLevel::BASIC): e = ServiceLevel::BASIC; break;
    case static_cast<int>(ServiceLevel::PLUS): e = ServiceLevel::PLUS; break;
    case static_cast<int>(ServiceLevel::PREMIUM): e = ServiceLevel::PREMIUM; break;
    case static_cast<int>(ServiceLevel::BUSINESS): e = ServiceLevel::BUSINESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ServiceLevel"));
    }
}

void readEnumQueryFormat(ThriftBinaryBufferReader & r, QueryFormat & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(QueryFormat::USER): e = QueryFormat::USER; break;
    case static_cast<int>(QueryFormat::SEXP): e = QueryFormat::SEXP; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum QueryFormat"));
    }
}

void readEnumNoteSortOrder(ThriftBinaryBufferReader & r, NoteSortOrder & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(NoteSortOrder::CREATED): e = NoteSortOrder::CREATED; break;
    case static_cast<int>(NoteSortOrder::UPDATED): e = NoteSortOrder::UPDATED; break;
    case static_cast<int>(NoteSortOrder::RELEVANCE): e = NoteSortOrder::RELEVANCE; break;
    case static_cast<int>(NoteSortOrder::UPDATE_SEQUENCE_NUMBER): e = NoteSortOrder::UPDATE_SEQUENCE_NUMBER; break;
    case static_cast<int>(NoteSortOrder::TITLE): e = NoteSortOrder::TITLE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum NoteSortOrder"));
    }
}

void readEnumPremiumOrderStatus(ThriftBinaryBufferReader & r, PremiumOrderStatus & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumSharedNotebookPrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotebookPrivilegeLevel & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumSharedNotePrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotePrivilegeLevel & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotePrivilegeLevel::READ_NOTE): e = SharedNotePrivilegeLevel::READ_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::MODIFY_NOTE): e = SharedNotePrivilegeLevel::MODIFY_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::FULL_ACCESS): e = SharedNotePrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotePrivilegeLevel"));
    }
}

void readEnumSponsoredGroupRole(ThriftBinaryBufferReader & r, SponsoredGroupRole & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SponsoredGroupRole::GROUP_MEMBER): e = SponsoredGroupRole::GROUP_MEMBER; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_ADMIN): e = SponsoredGroupRole::GROUP_ADMIN; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_OWNER): e = SponsoredGroupRole::GROUP_OWNER; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SponsoredGroupRole"));
    }
}

void readEnumBusinessUserRole(ThriftBinaryBufferReader & r, BusinessUserRole & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserRole::ADMIN): e = BusinessUserRole::ADMIN; break;
    case static_cast<int>(BusinessUserRole::NORMAL): e = BusinessUserRole::NORMAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserRole"));
    }
}

void readEnumBusinessUserStatus(ThriftBinaryBufferReader & r, BusinessUserStatus & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserStatus::ACTIVE): e = BusinessUserStatus::ACTIVE; break;
    case static_cast<int>(BusinessUserStatus::DEACTIVATED): e = BusinessUserStatus::DEACTIVATED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserStatus"));
    }
}

void readEnumSharedNotebookInstanceRestrictions(ThriftBinaryBufferReader & r, SharedNotebookInstanceRestrictions & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookInstanceRestrictions::ASSIGNED): e = SharedNotebookInstanceRestrictions::ASSIGNED; break;
    case static_cast<int>(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS): e = SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookInstanceRestrictions"));
    }
}

void readEnumReminderEmailConfig(ThriftBinaryBufferReader & r, ReminderEmailConfig & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ReminderEmailConfig::DO_NOT_SEND): e = ReminderEmailConfig::DO_NOT_SEND; break;
    case static_cast<int>(ReminderEmailConfig::SEND_DAILY_EMAIL): e = ReminderEmailConfig::SEND_DAILY_EMAIL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ReminderEmailConfig"));
    }
}

void readEnumBusinessInvitationStatus(ThriftBinaryBufferReader & r, BusinessInvitationStatus & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessInvitationStatus::APPROVED): e = BusinessInvitationStatus::APPROVED; break;
    case static_cast<int>(BusinessInvitationStatus::REQUESTED): e = BusinessInvitationStatus::REQUESTED; break;
    case static_cast<int>(BusinessInvitationStatus::REDEEMED): e = BusinessInvitationStatus::REDEEMED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessInvitationStatus"));
    }
}

void readEnumContactType(ThriftBinaryBufferReader & r, ContactType & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumEntityType(ThriftBinaryBufferReader & r, EntityType & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(EntityType::NOTE): e = EntityType::NOTE; break;
    case static_cast<int>(EntityType::NOTEBOOK): e = EntityType::NOTEBOOK; break;
    case static_cast<int>(EntityType::WORKSPACE): e = EntityType::WORKSPACE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EntityType"));
    }
}

void readEnumRecipientStatus(ThriftBinaryBufferReader & r, RecipientStatus & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RecipientStatus::NOT_IN_MY_LIST): e = RecipientStatus::NOT_IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST): e = RecipientStatus::IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK): e = RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RecipientStatus"));
    }
}

void readEnumCanMoveToContainerStatus(ThriftBinaryBufferReader & r, CanMoveToContainerStatus & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(CanMoveToContainerStatus::CAN_BE_MOVED): e = CanMoveToContainerStatus::CAN_BE_MOVED; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum CanMoveToContainerStatus"));
    }
}

void readEnumRelatedContentType(ThriftBinaryBufferReader & r, RelatedContentType & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentType::NEWS_ARTICLE): e = RelatedContentType::NEWS_ARTICLE; break;
    case static_cast<int>(RelatedContentType::PROFILE_PERSON): e = RelatedContentType::PROFILE_PERSON; break;
    case static_cast<int>(RelatedContentType::PROFILE_ORGANIZATION): e = RelatedContentType::PROFILE_ORGANIZATION; break;
    case static_cast<int>(RelatedContentType::REFERENCE_MATERIAL): e = RelatedContentType::REFERENCE_MATERIAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentType"));
    }
}

void readEnumRelatedContentAccess(ThriftBinaryBufferReader & r, RelatedContentAccess & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentAccess::NOT_ACCESSIBLE): e = RelatedContentAccess::NOT_ACCESSIBLE; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_ACCESS_OK): e = RelatedContentAccess::DIRECT_LINK_ACCESS_OK; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED): e = RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW): e = RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentAccess"));
    }
}

void readEnumUserIdentityType(ThriftBinaryBufferReader & r, UserIdentityType & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(UserIdentityType::EVERNOTE_USERID): e = UserIdentityType::EVERNOTE_USERID; break;
    case static_cast<int>(UserIdentityType::EMAIL): e = UserIdentityType::EMAIL; break;
    case static_cast<int>(UserIdentityType::IDENTITYID): e = UserIdentityType::IDENTITYID; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum UserIdentityType"));
    }
}

void writeSyncState(ThriftBinaryBufferWriter & w, const SyncState & s) {
    w.writeStructBegin(QStringLiteral("SyncState"));
    w.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("fullSyncBefore"),
        ThriftFieldType::T_I64,
        2);
    w.writeI64(s.fullSyncBefore);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);
    w.writeI32(s.updateCount);
    w.writeFieldEnd();
    if (s.uploaded.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            4);
        w.writeI64(s.uploaded.ref());
        w.writeFieldEnd();
    }
    if (s.userLastUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userLastUpdated"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.userLastUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.userMaxMessageEventId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userMaxMessageEventId"),
            ThriftFieldType::T_I64,
            6);
        w.writeI64(s.userMaxMessageEventId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncState(ThriftBinaryBufferReader & r, SyncState & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool fullSyncBefore_isset = false;
    bool updateCount_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                fullSyncBefore_isset = true;
                qint64 v;
                r.readI64(v);
                s.fullSyncBefore = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploaded = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.userLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                r.readI64(v);
                s.userMaxMessageEventId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.currentTime has no value"));
    if(!fullSyncBefore_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.fullSyncBefore has no value"));
    if(!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.updateCount has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SyncState & value)
{
    out << "SyncState: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";
    out << "    fullSyncBefore = "
        << "Timestamp" << "\n";
    out << "    updateCount = "
        << "qint32" << "\n";

    if (value.uploaded.isSet()) {
        out << "    uploaded = "
            << value.uploaded.ref() << "\n";
    }
    else {
        out << "    uploaded is not set\n";
    }

    if (value.userLastUpdated.isSet()) {
        out << "    userLastUpdated = "
            << value.userLastUpdated.ref() << "\n";
    }
    else {
        out << "    userLastUpdated is not set\n";
    }

    if (value.userMaxMessageEventId.isSet()) {
        out << "    userMaxMessageEventId = "
            << value.userMaxMessageEventId.ref() << "\n";
    }
    else {
        out << "    userMaxMessageEventId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SyncState & value)
{
    out << "SyncState: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";
    out << "    fullSyncBefore = "
        << "Timestamp" << "\n";
    out << "    updateCount = "
        << "qint32" << "\n";

    if (value.uploaded.isSet()) {
        out << "    uploaded = "
            << value.uploaded.ref() << "\n";
    }
    else {
        out << "    uploaded is not set\n";
    }

    if (value.userLastUpdated.isSet()) {
        out << "    userLastUpdated = "
            << value.userLastUpdated.ref() << "\n";
    }
    else {
        out << "    userLastUpdated is not set\n";
    }

    if (value.userMaxMessageEventId.isSet()) {
        out << "    userMaxMessageEventId = "
            << value.userMaxMessageEventId.ref() << "\n";
    }
    else {
        out << "    userMaxMessageEventId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSyncChunk(ThriftBinaryBufferWriter & w, const SyncChunk & s) {
    w.writeStructBegin(QStringLiteral("SyncChunk"));
    w.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    if (s.chunkHighUSN.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("chunkHighUSN"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.chunkHighUSN.ref());
        w.writeFieldEnd();
    }
    w.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);
    w.writeI32(s.updateCount);
    w.writeFieldEnd();
    if (s.notes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(const auto & value: qAsConst(s.notes.ref())) {
            writeNote(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.notebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(const auto & value: qAsConst(s.notebooks.ref())) {
            writeNotebook(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.tags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            6);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(const auto & value: qAsConst(s.tags.ref())) {
            writeTag(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.searches.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searches"),
            ThriftFieldType::T_LIST,
            7);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.searches.ref().length());
        for(const auto & value: qAsConst(s.searches.ref())) {
            writeSavedSearch(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.resources.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            8);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(const auto & value: qAsConst(s.resources.ref())) {
            writeResource(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.expungedNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungedNotes"),
            ThriftFieldType::T_LIST,
            9);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotes.ref().length());
        for(const auto & value: qAsConst(s.expungedNotes.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.expungedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungedNotebooks"),
            ThriftFieldType::T_LIST,
            10);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.expungedNotebooks.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.expungedTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungedTags"),
            ThriftFieldType::T_LIST,
            11);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedTags.ref().length());
        for(const auto & value: qAsConst(s.expungedTags.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.expungedSearches.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungedSearches"),
            ThriftFieldType::T_LIST,
            12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedSearches.ref().length());
        for(const auto & value: qAsConst(s.expungedSearches.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.linkedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("linkedNotebooks"),
            ThriftFieldType::T_LIST,
            13);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.linkedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.linkedNotebooks.ref())) {
            writeLinkedNotebook(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.expungedLinkedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungedLinkedNotebooks"),
            ThriftFieldType::T_LIST,
            14);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedLinkedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.expungedLinkedNotebooks.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncChunk(ThriftBinaryBufferReader & r, SyncChunk & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool updateCount_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.chunkHighUSN = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.notebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.tags)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SavedSearch> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.searches)"));
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.resources)"));
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.resources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedNotes)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedTags)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedSearches)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedSearches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<LinkedNotebook> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.linkedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.linkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedLinkedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.currentTime has no value"));
    if(!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.updateCount has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SyncChunk & value)
{
    out << "SyncChunk: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";

    if (value.chunkHighUSN.isSet()) {
        out << "    chunkHighUSN = "
            << value.chunkHighUSN.ref() << "\n";
    }
    else {
        out << "    chunkHighUSN is not set\n";
    }

    out << "    updateCount = "
        << "qint32" << "\n";

    if (value.notes.isSet()) {
        out << "    notes = "
            << "QList<Note> {";
        for(const auto & v: value.notes.ref()) {
            out << v;
        }
    }
    else {
        out << "    notes is not set\n";
    }

    if (value.notebooks.isSet()) {
        out << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: value.notebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebooks is not set\n";
    }

    if (value.tags.isSet()) {
        out << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: value.tags.ref()) {
            out << v;
        }
    }
    else {
        out << "    tags is not set\n";
    }

    if (value.searches.isSet()) {
        out << "    searches = "
            << "QList<SavedSearch> {";
        for(const auto & v: value.searches.ref()) {
            out << v;
        }
    }
    else {
        out << "    searches is not set\n";
    }

    if (value.resources.isSet()) {
        out << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: value.resources.ref()) {
            out << v;
        }
    }
    else {
        out << "    resources is not set\n";
    }

    if (value.expungedNotes.isSet()) {
        out << "    expungedNotes = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedNotes.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedNotes is not set\n";
    }

    if (value.expungedNotebooks.isSet()) {
        out << "    expungedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedNotebooks is not set\n";
    }

    if (value.expungedTags.isSet()) {
        out << "    expungedTags = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedTags.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedTags is not set\n";
    }

    if (value.expungedSearches.isSet()) {
        out << "    expungedSearches = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedSearches.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedSearches is not set\n";
    }

    if (value.linkedNotebooks.isSet()) {
        out << "    linkedNotebooks = "
            << "QList<LinkedNotebook> {";
        for(const auto & v: value.linkedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    linkedNotebooks is not set\n";
    }

    if (value.expungedLinkedNotebooks.isSet()) {
        out << "    expungedLinkedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedLinkedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedLinkedNotebooks is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SyncChunk & value)
{
    out << "SyncChunk: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";

    if (value.chunkHighUSN.isSet()) {
        out << "    chunkHighUSN = "
            << value.chunkHighUSN.ref() << "\n";
    }
    else {
        out << "    chunkHighUSN is not set\n";
    }

    out << "    updateCount = "
        << "qint32" << "\n";

    if (value.notes.isSet()) {
        out << "    notes = "
            << "QList<Note> {";
        for(const auto & v: value.notes.ref()) {
            out << v;
        }
    }
    else {
        out << "    notes is not set\n";
    }

    if (value.notebooks.isSet()) {
        out << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: value.notebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebooks is not set\n";
    }

    if (value.tags.isSet()) {
        out << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: value.tags.ref()) {
            out << v;
        }
    }
    else {
        out << "    tags is not set\n";
    }

    if (value.searches.isSet()) {
        out << "    searches = "
            << "QList<SavedSearch> {";
        for(const auto & v: value.searches.ref()) {
            out << v;
        }
    }
    else {
        out << "    searches is not set\n";
    }

    if (value.resources.isSet()) {
        out << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: value.resources.ref()) {
            out << v;
        }
    }
    else {
        out << "    resources is not set\n";
    }

    if (value.expungedNotes.isSet()) {
        out << "    expungedNotes = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedNotes.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedNotes is not set\n";
    }

    if (value.expungedNotebooks.isSet()) {
        out << "    expungedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedNotebooks is not set\n";
    }

    if (value.expungedTags.isSet()) {
        out << "    expungedTags = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedTags.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedTags is not set\n";
    }

    if (value.expungedSearches.isSet()) {
        out << "    expungedSearches = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedSearches.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedSearches is not set\n";
    }

    if (value.linkedNotebooks.isSet()) {
        out << "    linkedNotebooks = "
            << "QList<LinkedNotebook> {";
        for(const auto & v: value.linkedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    linkedNotebooks is not set\n";
    }

    if (value.expungedLinkedNotebooks.isSet()) {
        out << "    expungedLinkedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: value.expungedLinkedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    expungedLinkedNotebooks is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSyncChunkFilter(ThriftBinaryBufferWriter & w, const SyncChunkFilter & s) {
    w.writeStructBegin(QStringLiteral("SyncChunkFilter"));
    if (s.includeNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNotes"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.includeNotes.ref());
        w.writeFieldEnd();
    }
    if (s.includeNoteResources.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNoteResources"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.includeNoteResources.ref());
        w.writeFieldEnd();
    }
    if (s.includeNoteAttributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNoteAttributes"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.includeNoteAttributes.ref());
        w.writeFieldEnd();
    }
    if (s.includeNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNotebooks"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.includeNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.includeTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeTags"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.includeTags.ref());
        w.writeFieldEnd();
    }
    if (s.includeSearches.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeSearches"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.includeSearches.ref());
        w.writeFieldEnd();
    }
    if (s.includeResources.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResources"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.includeResources.ref());
        w.writeFieldEnd();
    }
    if (s.includeLinkedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.includeLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.includeExpunged.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeExpunged"),
            ThriftFieldType::T_BOOL,
            9);
        w.writeBool(s.includeExpunged.ref());
        w.writeFieldEnd();
    }
    if (s.includeNoteApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNoteApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            10);
        w.writeBool(s.includeNoteApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if (s.includeResourceApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            12);
        w.writeBool(s.includeResourceApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if (s.includeNoteResourceApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNoteResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            13);
        w.writeBool(s.includeNoteResourceApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if (s.includeSharedNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            17);
        w.writeBool(s.includeSharedNotes.ref());
        w.writeFieldEnd();
    }
    if (s.omitSharedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("omitSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            16);
        w.writeBool(s.omitSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.requireNoteContentClass.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("requireNoteContentClass"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.requireNoteContentClass.ref());
        w.writeFieldEnd();
    }
    if (s.notebookGuids.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuids"),
            ThriftFieldType::T_SET,
            15);
        w.writeSetBegin(ThriftFieldType::T_STRING, s.notebookGuids.ref().count());
        for(const auto & value: qAsConst(s.notebookGuids.ref())) {
            w.writeString(value);
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncChunkFilter(ThriftBinaryBufferReader & r, SyncChunkFilter & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteResources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteAttributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSearches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeExpunged = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourceApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteResourceApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.omitSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.requireNoteContentClass = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (SyncChunkFilter.notebookGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.notebookGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SyncChunkFilter & value)
{
    out << "SyncChunkFilter: {\n";

    if (value.includeNotes.isSet()) {
        out << "    includeNotes = "
            << value.includeNotes.ref() << "\n";
    }
    else {
        out << "    includeNotes is not set\n";
    }

    if (value.includeNoteResources.isSet()) {
        out << "    includeNoteResources = "
            << value.includeNoteResources.ref() << "\n";
    }
    else {
        out << "    includeNoteResources is not set\n";
    }

    if (value.includeNoteAttributes.isSet()) {
        out << "    includeNoteAttributes = "
            << value.includeNoteAttributes.ref() << "\n";
    }
    else {
        out << "    includeNoteAttributes is not set\n";
    }

    if (value.includeNotebooks.isSet()) {
        out << "    includeNotebooks = "
            << value.includeNotebooks.ref() << "\n";
    }
    else {
        out << "    includeNotebooks is not set\n";
    }

    if (value.includeTags.isSet()) {
        out << "    includeTags = "
            << value.includeTags.ref() << "\n";
    }
    else {
        out << "    includeTags is not set\n";
    }

    if (value.includeSearches.isSet()) {
        out << "    includeSearches = "
            << value.includeSearches.ref() << "\n";
    }
    else {
        out << "    includeSearches is not set\n";
    }

    if (value.includeResources.isSet()) {
        out << "    includeResources = "
            << value.includeResources.ref() << "\n";
    }
    else {
        out << "    includeResources is not set\n";
    }

    if (value.includeLinkedNotebooks.isSet()) {
        out << "    includeLinkedNotebooks = "
            << value.includeLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includeLinkedNotebooks is not set\n";
    }

    if (value.includeExpunged.isSet()) {
        out << "    includeExpunged = "
            << value.includeExpunged.ref() << "\n";
    }
    else {
        out << "    includeExpunged is not set\n";
    }

    if (value.includeNoteApplicationDataFullMap.isSet()) {
        out << "    includeNoteApplicationDataFullMap = "
            << value.includeNoteApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeNoteApplicationDataFullMap is not set\n";
    }

    if (value.includeResourceApplicationDataFullMap.isSet()) {
        out << "    includeResourceApplicationDataFullMap = "
            << value.includeResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeResourceApplicationDataFullMap is not set\n";
    }

    if (value.includeNoteResourceApplicationDataFullMap.isSet()) {
        out << "    includeNoteResourceApplicationDataFullMap = "
            << value.includeNoteResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeNoteResourceApplicationDataFullMap is not set\n";
    }

    if (value.includeSharedNotes.isSet()) {
        out << "    includeSharedNotes = "
            << value.includeSharedNotes.ref() << "\n";
    }
    else {
        out << "    includeSharedNotes is not set\n";
    }

    if (value.omitSharedNotebooks.isSet()) {
        out << "    omitSharedNotebooks = "
            << value.omitSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    omitSharedNotebooks is not set\n";
    }

    if (value.requireNoteContentClass.isSet()) {
        out << "    requireNoteContentClass = "
            << value.requireNoteContentClass.ref() << "\n";
    }
    else {
        out << "    requireNoteContentClass is not set\n";
    }

    if (value.notebookGuids.isSet()) {
        out << "    notebookGuids = "
            << "QSet<QString> {";
        for(const auto & v: value.notebookGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebookGuids is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SyncChunkFilter & value)
{
    out << "SyncChunkFilter: {\n";

    if (value.includeNotes.isSet()) {
        out << "    includeNotes = "
            << value.includeNotes.ref() << "\n";
    }
    else {
        out << "    includeNotes is not set\n";
    }

    if (value.includeNoteResources.isSet()) {
        out << "    includeNoteResources = "
            << value.includeNoteResources.ref() << "\n";
    }
    else {
        out << "    includeNoteResources is not set\n";
    }

    if (value.includeNoteAttributes.isSet()) {
        out << "    includeNoteAttributes = "
            << value.includeNoteAttributes.ref() << "\n";
    }
    else {
        out << "    includeNoteAttributes is not set\n";
    }

    if (value.includeNotebooks.isSet()) {
        out << "    includeNotebooks = "
            << value.includeNotebooks.ref() << "\n";
    }
    else {
        out << "    includeNotebooks is not set\n";
    }

    if (value.includeTags.isSet()) {
        out << "    includeTags = "
            << value.includeTags.ref() << "\n";
    }
    else {
        out << "    includeTags is not set\n";
    }

    if (value.includeSearches.isSet()) {
        out << "    includeSearches = "
            << value.includeSearches.ref() << "\n";
    }
    else {
        out << "    includeSearches is not set\n";
    }

    if (value.includeResources.isSet()) {
        out << "    includeResources = "
            << value.includeResources.ref() << "\n";
    }
    else {
        out << "    includeResources is not set\n";
    }

    if (value.includeLinkedNotebooks.isSet()) {
        out << "    includeLinkedNotebooks = "
            << value.includeLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includeLinkedNotebooks is not set\n";
    }

    if (value.includeExpunged.isSet()) {
        out << "    includeExpunged = "
            << value.includeExpunged.ref() << "\n";
    }
    else {
        out << "    includeExpunged is not set\n";
    }

    if (value.includeNoteApplicationDataFullMap.isSet()) {
        out << "    includeNoteApplicationDataFullMap = "
            << value.includeNoteApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeNoteApplicationDataFullMap is not set\n";
    }

    if (value.includeResourceApplicationDataFullMap.isSet()) {
        out << "    includeResourceApplicationDataFullMap = "
            << value.includeResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeResourceApplicationDataFullMap is not set\n";
    }

    if (value.includeNoteResourceApplicationDataFullMap.isSet()) {
        out << "    includeNoteResourceApplicationDataFullMap = "
            << value.includeNoteResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        out << "    includeNoteResourceApplicationDataFullMap is not set\n";
    }

    if (value.includeSharedNotes.isSet()) {
        out << "    includeSharedNotes = "
            << value.includeSharedNotes.ref() << "\n";
    }
    else {
        out << "    includeSharedNotes is not set\n";
    }

    if (value.omitSharedNotebooks.isSet()) {
        out << "    omitSharedNotebooks = "
            << value.omitSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    omitSharedNotebooks is not set\n";
    }

    if (value.requireNoteContentClass.isSet()) {
        out << "    requireNoteContentClass = "
            << value.requireNoteContentClass.ref() << "\n";
    }
    else {
        out << "    requireNoteContentClass is not set\n";
    }

    if (value.notebookGuids.isSet()) {
        out << "    notebookGuids = "
            << "QSet<QString> {";
        for(const auto & v: value.notebookGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebookGuids is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteFilter(ThriftBinaryBufferWriter & w, const NoteFilter & s) {
    w.writeStructBegin(QStringLiteral("NoteFilter"));
    if (s.order.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.order.ref());
        w.writeFieldEnd();
    }
    if (s.ascending.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.ascending.ref());
        w.writeFieldEnd();
    }
    if (s.words.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("words"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.words.ref());
        w.writeFieldEnd();
    }
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.tagGuids.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.timeZone.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("timeZone"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.timeZone.ref());
        w.writeFieldEnd();
    }
    if (s.inactive.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("inactive"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.inactive.ref());
        w.writeFieldEnd();
    }
    if (s.emphasized.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("emphasized"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.emphasized.ref());
        w.writeFieldEnd();
    }
    if (s.includeAllReadableNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeAllReadableNotebooks"),
            ThriftFieldType::T_BOOL,
            9);
        w.writeBool(s.includeAllReadableNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.includeAllReadableWorkspaces.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeAllReadableWorkspaces"),
            ThriftFieldType::T_BOOL,
            15);
        w.writeBool(s.includeAllReadableWorkspaces.ref());
        w.writeFieldEnd();
    }
    if (s.context.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            10);
        w.writeString(s.context.ref());
        w.writeFieldEnd();
    }
    if (s.rawWords.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("rawWords"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.rawWords.ref());
        w.writeFieldEnd();
    }
    if (s.searchContextBytes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            12);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteFilter(ThriftBinaryBufferReader & r, NoteFilter & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.order = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.ascending = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.words = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteFilter.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.timeZone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.inactive = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.emphasized = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAllReadableNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAllReadableWorkspaces = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.context = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.rawWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteFilter & value)
{
    out << "NoteFilter: {\n";

    if (value.order.isSet()) {
        out << "    order = "
            << value.order.ref() << "\n";
    }
    else {
        out << "    order is not set\n";
    }

    if (value.ascending.isSet()) {
        out << "    ascending = "
            << value.ascending.ref() << "\n";
    }
    else {
        out << "    ascending is not set\n";
    }

    if (value.words.isSet()) {
        out << "    words = "
            << value.words.ref() << "\n";
    }
    else {
        out << "    words is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.timeZone.isSet()) {
        out << "    timeZone = "
            << value.timeZone.ref() << "\n";
    }
    else {
        out << "    timeZone is not set\n";
    }

    if (value.inactive.isSet()) {
        out << "    inactive = "
            << value.inactive.ref() << "\n";
    }
    else {
        out << "    inactive is not set\n";
    }

    if (value.emphasized.isSet()) {
        out << "    emphasized = "
            << value.emphasized.ref() << "\n";
    }
    else {
        out << "    emphasized is not set\n";
    }

    if (value.includeAllReadableNotebooks.isSet()) {
        out << "    includeAllReadableNotebooks = "
            << value.includeAllReadableNotebooks.ref() << "\n";
    }
    else {
        out << "    includeAllReadableNotebooks is not set\n";
    }

    if (value.includeAllReadableWorkspaces.isSet()) {
        out << "    includeAllReadableWorkspaces = "
            << value.includeAllReadableWorkspaces.ref() << "\n";
    }
    else {
        out << "    includeAllReadableWorkspaces is not set\n";
    }

    if (value.context.isSet()) {
        out << "    context = "
            << value.context.ref() << "\n";
    }
    else {
        out << "    context is not set\n";
    }

    if (value.rawWords.isSet()) {
        out << "    rawWords = "
            << value.rawWords.ref() << "\n";
    }
    else {
        out << "    rawWords is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteFilter & value)
{
    out << "NoteFilter: {\n";

    if (value.order.isSet()) {
        out << "    order = "
            << value.order.ref() << "\n";
    }
    else {
        out << "    order is not set\n";
    }

    if (value.ascending.isSet()) {
        out << "    ascending = "
            << value.ascending.ref() << "\n";
    }
    else {
        out << "    ascending is not set\n";
    }

    if (value.words.isSet()) {
        out << "    words = "
            << value.words.ref() << "\n";
    }
    else {
        out << "    words is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.timeZone.isSet()) {
        out << "    timeZone = "
            << value.timeZone.ref() << "\n";
    }
    else {
        out << "    timeZone is not set\n";
    }

    if (value.inactive.isSet()) {
        out << "    inactive = "
            << value.inactive.ref() << "\n";
    }
    else {
        out << "    inactive is not set\n";
    }

    if (value.emphasized.isSet()) {
        out << "    emphasized = "
            << value.emphasized.ref() << "\n";
    }
    else {
        out << "    emphasized is not set\n";
    }

    if (value.includeAllReadableNotebooks.isSet()) {
        out << "    includeAllReadableNotebooks = "
            << value.includeAllReadableNotebooks.ref() << "\n";
    }
    else {
        out << "    includeAllReadableNotebooks is not set\n";
    }

    if (value.includeAllReadableWorkspaces.isSet()) {
        out << "    includeAllReadableWorkspaces = "
            << value.includeAllReadableWorkspaces.ref() << "\n";
    }
    else {
        out << "    includeAllReadableWorkspaces is not set\n";
    }

    if (value.context.isSet()) {
        out << "    context = "
            << value.context.ref() << "\n";
    }
    else {
        out << "    context is not set\n";
    }

    if (value.rawWords.isSet()) {
        out << "    rawWords = "
            << value.rawWords.ref() << "\n";
    }
    else {
        out << "    rawWords is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteList(ThriftBinaryBufferWriter & w, const NoteList & s) {
    w.writeStructBegin(QStringLiteral("NoteList"));
    w.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(s.startIndex);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);
    w.writeI32(s.totalNotes);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(const auto & value: qAsConst(s.notes)) {
        writeNote(w, value);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if (s.stoppedWords.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(const auto & value: qAsConst(s.stoppedWords.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.searchedWords.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(const auto & value: qAsConst(s.searchedWords.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.updateCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);
        w.writeI32(s.updateCount.ref());
        w.writeFieldEnd();
    }
    if (s.searchContextBytes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    if (s.debugInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteList(ThriftBinaryBufferReader & r, NoteList & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                r.readI32(v);
                s.startIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                r.readI32(v);
                s.totalNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<Note> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.stoppedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.stoppedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.searchedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searchedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.startIndex has no value"));
    if(!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.totalNotes has no value"));
    if(!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.notes has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteList & value)
{
    out << "NoteList: {\n";
    out << "    startIndex = "
        << "qint32" << "\n";
    out << "    totalNotes = "
        << "qint32" << "\n";
    out << "    notes = "
        << "QList<Note>" << "\n";

    if (value.stoppedWords.isSet()) {
        out << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: value.stoppedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    stoppedWords is not set\n";
    }

    if (value.searchedWords.isSet()) {
        out << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: value.searchedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    searchedWords is not set\n";
    }

    if (value.updateCount.isSet()) {
        out << "    updateCount = "
            << value.updateCount.ref() << "\n";
    }
    else {
        out << "    updateCount is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteList & value)
{
    out << "NoteList: {\n";
    out << "    startIndex = "
        << "qint32" << "\n";
    out << "    totalNotes = "
        << "qint32" << "\n";
    out << "    notes = "
        << "QList<Note>" << "\n";

    if (value.stoppedWords.isSet()) {
        out << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: value.stoppedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    stoppedWords is not set\n";
    }

    if (value.searchedWords.isSet()) {
        out << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: value.searchedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    searchedWords is not set\n";
    }

    if (value.updateCount.isSet()) {
        out << "    updateCount = "
            << value.updateCount.ref() << "\n";
    }
    else {
        out << "    updateCount is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteMetadata(ThriftBinaryBufferWriter & w, const NoteMetadata & s) {
    w.writeStructBegin(QStringLiteral("NoteMetadata"));
    w.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        1);
    w.writeString(s.guid);
    w.writeFieldEnd();
    if (s.title.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if (s.contentLength.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.contentLength.ref());
        w.writeFieldEnd();
    }
    if (s.created.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if (s.deleted.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.tagGuids.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.attributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);
        writeNoteAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if (s.largestResourceMime.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("largestResourceMime"),
            ThriftFieldType::T_STRING,
            20);
        w.writeString(s.largestResourceMime.ref());
        w.writeFieldEnd();
    }
    if (s.largestResourceSize.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("largestResourceSize"),
            ThriftFieldType::T_I32,
            21);
        w.writeI32(s.largestResourceSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteMetadata(ThriftBinaryBufferReader & r, NoteMetadata & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool guid_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                guid_isset = true;
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.contentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteMetadata.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.largestResourceMime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.largestResourceSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!guid_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteMetadata.guid has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteMetadata & value)
{
    out << "NoteMetadata: {\n";
    out << "    guid = "
        << "Guid" << "\n";

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.contentLength.isSet()) {
        out << "    contentLength = "
            << value.contentLength.ref() << "\n";
    }
    else {
        out << "    contentLength is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.largestResourceMime.isSet()) {
        out << "    largestResourceMime = "
            << value.largestResourceMime.ref() << "\n";
    }
    else {
        out << "    largestResourceMime is not set\n";
    }

    if (value.largestResourceSize.isSet()) {
        out << "    largestResourceSize = "
            << value.largestResourceSize.ref() << "\n";
    }
    else {
        out << "    largestResourceSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteMetadata & value)
{
    out << "NoteMetadata: {\n";
    out << "    guid = "
        << "Guid" << "\n";

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.contentLength.isSet()) {
        out << "    contentLength = "
            << value.contentLength.ref() << "\n";
    }
    else {
        out << "    contentLength is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.largestResourceMime.isSet()) {
        out << "    largestResourceMime = "
            << value.largestResourceMime.ref() << "\n";
    }
    else {
        out << "    largestResourceMime is not set\n";
    }

    if (value.largestResourceSize.isSet()) {
        out << "    largestResourceSize = "
            << value.largestResourceSize.ref() << "\n";
    }
    else {
        out << "    largestResourceSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotesMetadataList(ThriftBinaryBufferWriter & w, const NotesMetadataList & s) {
    w.writeStructBegin(QStringLiteral("NotesMetadataList"));
    w.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(s.startIndex);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);
    w.writeI32(s.totalNotes);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(const auto & value: qAsConst(s.notes)) {
        writeNoteMetadata(w, value);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if (s.stoppedWords.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(const auto & value: qAsConst(s.stoppedWords.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.searchedWords.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(const auto & value: qAsConst(s.searchedWords.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.updateCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);
        w.writeI32(s.updateCount.ref());
        w.writeFieldEnd();
    }
    if (s.searchContextBytes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    if (s.debugInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotesMetadataList(ThriftBinaryBufferReader & r, NotesMetadataList & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                r.readI32(v);
                s.startIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                r.readI32(v);
                s.totalNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<NoteMetadata> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMetadata elem;
                    readNoteMetadata(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.stoppedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.stoppedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.searchedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searchedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.startIndex has no value"));
    if(!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.totalNotes has no value"));
    if(!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.notes has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotesMetadataList & value)
{
    out << "NotesMetadataList: {\n";
    out << "    startIndex = "
        << "qint32" << "\n";
    out << "    totalNotes = "
        << "qint32" << "\n";
    out << "    notes = "
        << "QList<NoteMetadata>" << "\n";

    if (value.stoppedWords.isSet()) {
        out << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: value.stoppedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    stoppedWords is not set\n";
    }

    if (value.searchedWords.isSet()) {
        out << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: value.searchedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    searchedWords is not set\n";
    }

    if (value.updateCount.isSet()) {
        out << "    updateCount = "
            << value.updateCount.ref() << "\n";
    }
    else {
        out << "    updateCount is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotesMetadataList & value)
{
    out << "NotesMetadataList: {\n";
    out << "    startIndex = "
        << "qint32" << "\n";
    out << "    totalNotes = "
        << "qint32" << "\n";
    out << "    notes = "
        << "QList<NoteMetadata>" << "\n";

    if (value.stoppedWords.isSet()) {
        out << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: value.stoppedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    stoppedWords is not set\n";
    }

    if (value.searchedWords.isSet()) {
        out << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: value.searchedWords.ref()) {
            out << v;
        }
    }
    else {
        out << "    searchedWords is not set\n";
    }

    if (value.updateCount.isSet()) {
        out << "    updateCount = "
            << value.updateCount.ref() << "\n";
    }
    else {
        out << "    updateCount is not set\n";
    }

    if (value.searchContextBytes.isSet()) {
        out << "    searchContextBytes = "
            << value.searchContextBytes.ref() << "\n";
    }
    else {
        out << "    searchContextBytes is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotesMetadataResultSpec(ThriftBinaryBufferWriter & w, const NotesMetadataResultSpec & s) {
    w.writeStructBegin(QStringLiteral("NotesMetadataResultSpec"));
    if (s.includeTitle.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeTitle"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.includeTitle.ref());
        w.writeFieldEnd();
    }
    if (s.includeContentLength.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeContentLength"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.includeContentLength.ref());
        w.writeFieldEnd();
    }
    if (s.includeCreated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeCreated"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.includeCreated.ref());
        w.writeFieldEnd();
    }
    if (s.includeUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeUpdated"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.includeUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.includeDeleted.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeDeleted"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.includeDeleted.ref());
        w.writeFieldEnd();
    }
    if (s.includeUpdateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeUpdateSequenceNum"),
            ThriftFieldType::T_BOOL,
            10);
        w.writeBool(s.includeUpdateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.includeNotebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNotebookGuid"),
            ThriftFieldType::T_BOOL,
            11);
        w.writeBool(s.includeNotebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.includeTagGuids.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeTagGuids"),
            ThriftFieldType::T_BOOL,
            12);
        w.writeBool(s.includeTagGuids.ref());
        w.writeFieldEnd();
    }
    if (s.includeAttributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeAttributes"),
            ThriftFieldType::T_BOOL,
            14);
        w.writeBool(s.includeAttributes.ref());
        w.writeFieldEnd();
    }
    if (s.includeLargestResourceMime.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeLargestResourceMime"),
            ThriftFieldType::T_BOOL,
            20);
        w.writeBool(s.includeLargestResourceMime.ref());
        w.writeFieldEnd();
    }
    if (s.includeLargestResourceSize.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeLargestResourceSize"),
            ThriftFieldType::T_BOOL,
            21);
        w.writeBool(s.includeLargestResourceSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotesMetadataResultSpec(ThriftBinaryBufferReader & r, NotesMetadataResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTitle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeDeleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeUpdateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAttributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLargestResourceMime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLargestResourceSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotesMetadataResultSpec & value)
{
    out << "NotesMetadataResultSpec: {\n";

    if (value.includeTitle.isSet()) {
        out << "    includeTitle = "
            << value.includeTitle.ref() << "\n";
    }
    else {
        out << "    includeTitle is not set\n";
    }

    if (value.includeContentLength.isSet()) {
        out << "    includeContentLength = "
            << value.includeContentLength.ref() << "\n";
    }
    else {
        out << "    includeContentLength is not set\n";
    }

    if (value.includeCreated.isSet()) {
        out << "    includeCreated = "
            << value.includeCreated.ref() << "\n";
    }
    else {
        out << "    includeCreated is not set\n";
    }

    if (value.includeUpdated.isSet()) {
        out << "    includeUpdated = "
            << value.includeUpdated.ref() << "\n";
    }
    else {
        out << "    includeUpdated is not set\n";
    }

    if (value.includeDeleted.isSet()) {
        out << "    includeDeleted = "
            << value.includeDeleted.ref() << "\n";
    }
    else {
        out << "    includeDeleted is not set\n";
    }

    if (value.includeUpdateSequenceNum.isSet()) {
        out << "    includeUpdateSequenceNum = "
            << value.includeUpdateSequenceNum.ref() << "\n";
    }
    else {
        out << "    includeUpdateSequenceNum is not set\n";
    }

    if (value.includeNotebookGuid.isSet()) {
        out << "    includeNotebookGuid = "
            << value.includeNotebookGuid.ref() << "\n";
    }
    else {
        out << "    includeNotebookGuid is not set\n";
    }

    if (value.includeTagGuids.isSet()) {
        out << "    includeTagGuids = "
            << value.includeTagGuids.ref() << "\n";
    }
    else {
        out << "    includeTagGuids is not set\n";
    }

    if (value.includeAttributes.isSet()) {
        out << "    includeAttributes = "
            << value.includeAttributes.ref() << "\n";
    }
    else {
        out << "    includeAttributes is not set\n";
    }

    if (value.includeLargestResourceMime.isSet()) {
        out << "    includeLargestResourceMime = "
            << value.includeLargestResourceMime.ref() << "\n";
    }
    else {
        out << "    includeLargestResourceMime is not set\n";
    }

    if (value.includeLargestResourceSize.isSet()) {
        out << "    includeLargestResourceSize = "
            << value.includeLargestResourceSize.ref() << "\n";
    }
    else {
        out << "    includeLargestResourceSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotesMetadataResultSpec & value)
{
    out << "NotesMetadataResultSpec: {\n";

    if (value.includeTitle.isSet()) {
        out << "    includeTitle = "
            << value.includeTitle.ref() << "\n";
    }
    else {
        out << "    includeTitle is not set\n";
    }

    if (value.includeContentLength.isSet()) {
        out << "    includeContentLength = "
            << value.includeContentLength.ref() << "\n";
    }
    else {
        out << "    includeContentLength is not set\n";
    }

    if (value.includeCreated.isSet()) {
        out << "    includeCreated = "
            << value.includeCreated.ref() << "\n";
    }
    else {
        out << "    includeCreated is not set\n";
    }

    if (value.includeUpdated.isSet()) {
        out << "    includeUpdated = "
            << value.includeUpdated.ref() << "\n";
    }
    else {
        out << "    includeUpdated is not set\n";
    }

    if (value.includeDeleted.isSet()) {
        out << "    includeDeleted = "
            << value.includeDeleted.ref() << "\n";
    }
    else {
        out << "    includeDeleted is not set\n";
    }

    if (value.includeUpdateSequenceNum.isSet()) {
        out << "    includeUpdateSequenceNum = "
            << value.includeUpdateSequenceNum.ref() << "\n";
    }
    else {
        out << "    includeUpdateSequenceNum is not set\n";
    }

    if (value.includeNotebookGuid.isSet()) {
        out << "    includeNotebookGuid = "
            << value.includeNotebookGuid.ref() << "\n";
    }
    else {
        out << "    includeNotebookGuid is not set\n";
    }

    if (value.includeTagGuids.isSet()) {
        out << "    includeTagGuids = "
            << value.includeTagGuids.ref() << "\n";
    }
    else {
        out << "    includeTagGuids is not set\n";
    }

    if (value.includeAttributes.isSet()) {
        out << "    includeAttributes = "
            << value.includeAttributes.ref() << "\n";
    }
    else {
        out << "    includeAttributes is not set\n";
    }

    if (value.includeLargestResourceMime.isSet()) {
        out << "    includeLargestResourceMime = "
            << value.includeLargestResourceMime.ref() << "\n";
    }
    else {
        out << "    includeLargestResourceMime is not set\n";
    }

    if (value.includeLargestResourceSize.isSet()) {
        out << "    includeLargestResourceSize = "
            << value.includeLargestResourceSize.ref() << "\n";
    }
    else {
        out << "    includeLargestResourceSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteCollectionCounts(ThriftBinaryBufferWriter & w, const NoteCollectionCounts & s) {
    w.writeStructBegin(QStringLiteral("NoteCollectionCounts"));
    if (s.notebookCounts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookCounts"),
            ThriftFieldType::T_MAP,
            1);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.notebookCounts.ref().size());
        for(const auto & it: toRange(s.notebookCounts.ref())) {
            w.writeString(it.key());
            w.writeI32(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if (s.tagCounts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tagCounts"),
            ThriftFieldType::T_MAP,
            2);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.tagCounts.ref().size());
        for(const auto & it: toRange(s.tagCounts.ref())) {
            w.writeString(it.key());
            w.writeI32(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if (s.trashCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("trashCount"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(s.trashCount.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteCollectionCounts(ThriftBinaryBufferReader & r, NoteCollectionCounts & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.notebookCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.notebookCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    r.readString(key);
                    qint32 value;
                    r.readI32(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.notebookCounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.tagCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.tagCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    r.readString(key);
                    qint32 value;
                    r.readI32(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.tagCounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.trashCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteCollectionCounts & value)
{
    out << "NoteCollectionCounts: {\n";

    if (value.notebookCounts.isSet()) {
        out << "    notebookCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(value.notebookCounts.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    notebookCounts is not set\n";
    }

    if (value.tagCounts.isSet()) {
        out << "    tagCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(value.tagCounts.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    tagCounts is not set\n";
    }

    if (value.trashCount.isSet()) {
        out << "    trashCount = "
            << value.trashCount.ref() << "\n";
    }
    else {
        out << "    trashCount is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteCollectionCounts & value)
{
    out << "NoteCollectionCounts: {\n";

    if (value.notebookCounts.isSet()) {
        out << "    notebookCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(value.notebookCounts.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    notebookCounts is not set\n";
    }

    if (value.tagCounts.isSet()) {
        out << "    tagCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(value.tagCounts.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    tagCounts is not set\n";
    }

    if (value.trashCount.isSet()) {
        out << "    trashCount = "
            << value.trashCount.ref() << "\n";
    }
    else {
        out << "    trashCount is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteResultSpec(ThriftBinaryBufferWriter & w, const NoteResultSpec & s) {
    w.writeStructBegin(QStringLiteral("NoteResultSpec"));
    if (s.includeContent.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeContent"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.includeContent.ref());
        w.writeFieldEnd();
    }
    if (s.includeResourcesData.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResourcesData"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.includeResourcesData.ref());
        w.writeFieldEnd();
    }
    if (s.includeResourcesRecognition.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResourcesRecognition"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.includeResourcesRecognition.ref());
        w.writeFieldEnd();
    }
    if (s.includeResourcesAlternateData.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResourcesAlternateData"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.includeResourcesAlternateData.ref());
        w.writeFieldEnd();
    }
    if (s.includeSharedNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.includeSharedNotes.ref());
        w.writeFieldEnd();
    }
    if (s.includeNoteAppDataValues.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeNoteAppDataValues"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.includeNoteAppDataValues.ref());
        w.writeFieldEnd();
    }
    if (s.includeResourceAppDataValues.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeResourceAppDataValues"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.includeResourceAppDataValues.ref());
        w.writeFieldEnd();
    }
    if (s.includeAccountLimits.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeAccountLimits"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.includeAccountLimits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteResultSpec(ThriftBinaryBufferReader & r, NoteResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesRecognition = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesAlternateData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteAppDataValues = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourceAppDataValues = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAccountLimits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteResultSpec & value)
{
    out << "NoteResultSpec: {\n";

    if (value.includeContent.isSet()) {
        out << "    includeContent = "
            << value.includeContent.ref() << "\n";
    }
    else {
        out << "    includeContent is not set\n";
    }

    if (value.includeResourcesData.isSet()) {
        out << "    includeResourcesData = "
            << value.includeResourcesData.ref() << "\n";
    }
    else {
        out << "    includeResourcesData is not set\n";
    }

    if (value.includeResourcesRecognition.isSet()) {
        out << "    includeResourcesRecognition = "
            << value.includeResourcesRecognition.ref() << "\n";
    }
    else {
        out << "    includeResourcesRecognition is not set\n";
    }

    if (value.includeResourcesAlternateData.isSet()) {
        out << "    includeResourcesAlternateData = "
            << value.includeResourcesAlternateData.ref() << "\n";
    }
    else {
        out << "    includeResourcesAlternateData is not set\n";
    }

    if (value.includeSharedNotes.isSet()) {
        out << "    includeSharedNotes = "
            << value.includeSharedNotes.ref() << "\n";
    }
    else {
        out << "    includeSharedNotes is not set\n";
    }

    if (value.includeNoteAppDataValues.isSet()) {
        out << "    includeNoteAppDataValues = "
            << value.includeNoteAppDataValues.ref() << "\n";
    }
    else {
        out << "    includeNoteAppDataValues is not set\n";
    }

    if (value.includeResourceAppDataValues.isSet()) {
        out << "    includeResourceAppDataValues = "
            << value.includeResourceAppDataValues.ref() << "\n";
    }
    else {
        out << "    includeResourceAppDataValues is not set\n";
    }

    if (value.includeAccountLimits.isSet()) {
        out << "    includeAccountLimits = "
            << value.includeAccountLimits.ref() << "\n";
    }
    else {
        out << "    includeAccountLimits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteResultSpec & value)
{
    out << "NoteResultSpec: {\n";

    if (value.includeContent.isSet()) {
        out << "    includeContent = "
            << value.includeContent.ref() << "\n";
    }
    else {
        out << "    includeContent is not set\n";
    }

    if (value.includeResourcesData.isSet()) {
        out << "    includeResourcesData = "
            << value.includeResourcesData.ref() << "\n";
    }
    else {
        out << "    includeResourcesData is not set\n";
    }

    if (value.includeResourcesRecognition.isSet()) {
        out << "    includeResourcesRecognition = "
            << value.includeResourcesRecognition.ref() << "\n";
    }
    else {
        out << "    includeResourcesRecognition is not set\n";
    }

    if (value.includeResourcesAlternateData.isSet()) {
        out << "    includeResourcesAlternateData = "
            << value.includeResourcesAlternateData.ref() << "\n";
    }
    else {
        out << "    includeResourcesAlternateData is not set\n";
    }

    if (value.includeSharedNotes.isSet()) {
        out << "    includeSharedNotes = "
            << value.includeSharedNotes.ref() << "\n";
    }
    else {
        out << "    includeSharedNotes is not set\n";
    }

    if (value.includeNoteAppDataValues.isSet()) {
        out << "    includeNoteAppDataValues = "
            << value.includeNoteAppDataValues.ref() << "\n";
    }
    else {
        out << "    includeNoteAppDataValues is not set\n";
    }

    if (value.includeResourceAppDataValues.isSet()) {
        out << "    includeResourceAppDataValues = "
            << value.includeResourceAppDataValues.ref() << "\n";
    }
    else {
        out << "    includeResourceAppDataValues is not set\n";
    }

    if (value.includeAccountLimits.isSet()) {
        out << "    includeAccountLimits = "
            << value.includeAccountLimits.ref() << "\n";
    }
    else {
        out << "    includeAccountLimits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteEmailParameters(ThriftBinaryBufferWriter & w, const NoteEmailParameters & s) {
    w.writeStructBegin(QStringLiteral("NoteEmailParameters"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.note.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            2);
        writeNote(w, s.note.ref());
        w.writeFieldEnd();
    }
    if (s.toAddresses.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("toAddresses"),
            ThriftFieldType::T_LIST,
            3);
        w.writeListBegin(ThriftFieldType::T_STRING, s.toAddresses.ref().length());
        for(const auto & value: qAsConst(s.toAddresses.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.ccAddresses.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("ccAddresses"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.ccAddresses.ref().length());
        for(const auto & value: qAsConst(s.ccAddresses.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.subject.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("subject"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.subject.ref());
        w.writeFieldEnd();
    }
    if (s.message.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.message.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteEmailParameters(ThriftBinaryBufferReader & r, NoteEmailParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(r, v);
                s.note = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteEmailParameters.toAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.toAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteEmailParameters.ccAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.ccAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.subject = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.message = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteEmailParameters & value)
{
    out << "NoteEmailParameters: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.note.isSet()) {
        out << "    note = "
            << value.note.ref() << "\n";
    }
    else {
        out << "    note is not set\n";
    }

    if (value.toAddresses.isSet()) {
        out << "    toAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.toAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    toAddresses is not set\n";
    }

    if (value.ccAddresses.isSet()) {
        out << "    ccAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.ccAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    ccAddresses is not set\n";
    }

    if (value.subject.isSet()) {
        out << "    subject = "
            << value.subject.ref() << "\n";
    }
    else {
        out << "    subject is not set\n";
    }

    if (value.message.isSet()) {
        out << "    message = "
            << value.message.ref() << "\n";
    }
    else {
        out << "    message is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteEmailParameters & value)
{
    out << "NoteEmailParameters: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.note.isSet()) {
        out << "    note = "
            << value.note.ref() << "\n";
    }
    else {
        out << "    note is not set\n";
    }

    if (value.toAddresses.isSet()) {
        out << "    toAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.toAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    toAddresses is not set\n";
    }

    if (value.ccAddresses.isSet()) {
        out << "    ccAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.ccAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    ccAddresses is not set\n";
    }

    if (value.subject.isSet()) {
        out << "    subject = "
            << value.subject.ref() << "\n";
    }
    else {
        out << "    subject is not set\n";
    }

    if (value.message.isSet()) {
        out << "    message = "
            << value.message.ref() << "\n";
    }
    else {
        out << "    message is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteVersionId(ThriftBinaryBufferWriter & w, const NoteVersionId & s) {
    w.writeStructBegin(QStringLiteral("NoteVersionId"));
    w.writeFieldBegin(
        QStringLiteral("updateSequenceNum"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(s.updateSequenceNum);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("updated"),
        ThriftFieldType::T_I64,
        2);
    w.writeI64(s.updated);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("saved"),
        ThriftFieldType::T_I64,
        3);
    w.writeI64(s.saved);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("title"),
        ThriftFieldType::T_STRING,
        4);
    w.writeString(s.title);
    w.writeFieldEnd();
    if (s.lastEditorId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.lastEditorId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteVersionId(ThriftBinaryBufferReader & r, NoteVersionId & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool updateSequenceNum_isset = false;
    bool updated_isset = false;
    bool saved_isset = false;
    bool title_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateSequenceNum_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                updated_isset = true;
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                saved_isset = true;
                qint64 v;
                r.readI64(v);
                s.saved = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                title_isset = true;
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.lastEditorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!updateSequenceNum_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updateSequenceNum has no value"));
    if(!updated_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updated has no value"));
    if(!saved_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.saved has no value"));
    if(!title_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.title has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteVersionId & value)
{
    out << "NoteVersionId: {\n";
    out << "    updateSequenceNum = "
        << "qint32" << "\n";
    out << "    updated = "
        << "Timestamp" << "\n";
    out << "    saved = "
        << "Timestamp" << "\n";
    out << "    title = "
        << "QString" << "\n";

    if (value.lastEditorId.isSet()) {
        out << "    lastEditorId = "
            << value.lastEditorId.ref() << "\n";
    }
    else {
        out << "    lastEditorId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteVersionId & value)
{
    out << "NoteVersionId: {\n";
    out << "    updateSequenceNum = "
        << "qint32" << "\n";
    out << "    updated = "
        << "Timestamp" << "\n";
    out << "    saved = "
        << "Timestamp" << "\n";
    out << "    title = "
        << "QString" << "\n";

    if (value.lastEditorId.isSet()) {
        out << "    lastEditorId = "
            << value.lastEditorId.ref() << "\n";
    }
    else {
        out << "    lastEditorId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedQuery(ThriftBinaryBufferWriter & w, const RelatedQuery & s) {
    w.writeStructBegin(QStringLiteral("RelatedQuery"));
    if (s.noteGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if (s.plainText.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("plainText"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.plainText.ref());
        w.writeFieldEnd();
    }
    if (s.filter.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("filter"),
            ThriftFieldType::T_STRUCT,
            3);
        writeNoteFilter(w, s.filter.ref());
        w.writeFieldEnd();
    }
    if (s.referenceUri.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("referenceUri"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.referenceUri.ref());
        w.writeFieldEnd();
    }
    if (s.context.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.context.ref());
        w.writeFieldEnd();
    }
    if (s.cacheKey.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.cacheKey.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedQuery(ThriftBinaryBufferReader & r, RelatedQuery & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.plainText = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(r, v);
                s.filter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.referenceUri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.context = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cacheKey = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedQuery & value)
{
    out << "RelatedQuery: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.plainText.isSet()) {
        out << "    plainText = "
            << value.plainText.ref() << "\n";
    }
    else {
        out << "    plainText is not set\n";
    }

    if (value.filter.isSet()) {
        out << "    filter = "
            << value.filter.ref() << "\n";
    }
    else {
        out << "    filter is not set\n";
    }

    if (value.referenceUri.isSet()) {
        out << "    referenceUri = "
            << value.referenceUri.ref() << "\n";
    }
    else {
        out << "    referenceUri is not set\n";
    }

    if (value.context.isSet()) {
        out << "    context = "
            << value.context.ref() << "\n";
    }
    else {
        out << "    context is not set\n";
    }

    if (value.cacheKey.isSet()) {
        out << "    cacheKey = "
            << value.cacheKey.ref() << "\n";
    }
    else {
        out << "    cacheKey is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedQuery & value)
{
    out << "RelatedQuery: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.plainText.isSet()) {
        out << "    plainText = "
            << value.plainText.ref() << "\n";
    }
    else {
        out << "    plainText is not set\n";
    }

    if (value.filter.isSet()) {
        out << "    filter = "
            << value.filter.ref() << "\n";
    }
    else {
        out << "    filter is not set\n";
    }

    if (value.referenceUri.isSet()) {
        out << "    referenceUri = "
            << value.referenceUri.ref() << "\n";
    }
    else {
        out << "    referenceUri is not set\n";
    }

    if (value.context.isSet()) {
        out << "    context = "
            << value.context.ref() << "\n";
    }
    else {
        out << "    context is not set\n";
    }

    if (value.cacheKey.isSet()) {
        out << "    cacheKey = "
            << value.cacheKey.ref() << "\n";
    }
    else {
        out << "    cacheKey is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedResult(ThriftBinaryBufferWriter & w, const RelatedResult & s) {
    w.writeStructBegin(QStringLiteral("RelatedResult"));
    if (s.notes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(const auto & value: qAsConst(s.notes.ref())) {
            writeNote(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.notebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(const auto & value: qAsConst(s.notebooks.ref())) {
            writeNotebook(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.tags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(const auto & value: qAsConst(s.tags.ref())) {
            writeTag(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.containingNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("containingNotebooks"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.containingNotebooks.ref().length());
        for(const auto & value: qAsConst(s.containingNotebooks.ref())) {
            writeNotebookDescriptor(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.debugInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    if (s.experts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("experts"),
            ThriftFieldType::T_LIST,
            6);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.experts.ref().length());
        for(const auto & value: qAsConst(s.experts.ref())) {
            writeUserProfile(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.relatedContent.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("relatedContent"),
            ThriftFieldType::T_LIST,
            7);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.relatedContent.ref().length());
        for(const auto & value: qAsConst(s.relatedContent.ref())) {
            writeRelatedContent(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.cacheKey.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.cacheKey.ref());
        w.writeFieldEnd();
    }
    if (s.cacheExpires.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("cacheExpires"),
            ThriftFieldType::T_I32,
            9);
        w.writeI32(s.cacheExpires.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedResult(ThriftBinaryBufferReader & r, RelatedResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.notebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.tags)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NotebookDescriptor> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.containingNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    NotebookDescriptor elem;
                    readNotebookDescriptor(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.containingNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserProfile> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.experts)"));
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.experts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContent> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.relatedContent)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContent elem;
                    readRelatedContent(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.relatedContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cacheKey = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.cacheExpires = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedResult & value)
{
    out << "RelatedResult: {\n";

    if (value.notes.isSet()) {
        out << "    notes = "
            << "QList<Note> {";
        for(const auto & v: value.notes.ref()) {
            out << v;
        }
    }
    else {
        out << "    notes is not set\n";
    }

    if (value.notebooks.isSet()) {
        out << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: value.notebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebooks is not set\n";
    }

    if (value.tags.isSet()) {
        out << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: value.tags.ref()) {
            out << v;
        }
    }
    else {
        out << "    tags is not set\n";
    }

    if (value.containingNotebooks.isSet()) {
        out << "    containingNotebooks = "
            << "QList<NotebookDescriptor> {";
        for(const auto & v: value.containingNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    containingNotebooks is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    if (value.experts.isSet()) {
        out << "    experts = "
            << "QList<UserProfile> {";
        for(const auto & v: value.experts.ref()) {
            out << v;
        }
    }
    else {
        out << "    experts is not set\n";
    }

    if (value.relatedContent.isSet()) {
        out << "    relatedContent = "
            << "QList<RelatedContent> {";
        for(const auto & v: value.relatedContent.ref()) {
            out << v;
        }
    }
    else {
        out << "    relatedContent is not set\n";
    }

    if (value.cacheKey.isSet()) {
        out << "    cacheKey = "
            << value.cacheKey.ref() << "\n";
    }
    else {
        out << "    cacheKey is not set\n";
    }

    if (value.cacheExpires.isSet()) {
        out << "    cacheExpires = "
            << value.cacheExpires.ref() << "\n";
    }
    else {
        out << "    cacheExpires is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedResult & value)
{
    out << "RelatedResult: {\n";

    if (value.notes.isSet()) {
        out << "    notes = "
            << "QList<Note> {";
        for(const auto & v: value.notes.ref()) {
            out << v;
        }
    }
    else {
        out << "    notes is not set\n";
    }

    if (value.notebooks.isSet()) {
        out << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: value.notebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    notebooks is not set\n";
    }

    if (value.tags.isSet()) {
        out << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: value.tags.ref()) {
            out << v;
        }
    }
    else {
        out << "    tags is not set\n";
    }

    if (value.containingNotebooks.isSet()) {
        out << "    containingNotebooks = "
            << "QList<NotebookDescriptor> {";
        for(const auto & v: value.containingNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    containingNotebooks is not set\n";
    }

    if (value.debugInfo.isSet()) {
        out << "    debugInfo = "
            << value.debugInfo.ref() << "\n";
    }
    else {
        out << "    debugInfo is not set\n";
    }

    if (value.experts.isSet()) {
        out << "    experts = "
            << "QList<UserProfile> {";
        for(const auto & v: value.experts.ref()) {
            out << v;
        }
    }
    else {
        out << "    experts is not set\n";
    }

    if (value.relatedContent.isSet()) {
        out << "    relatedContent = "
            << "QList<RelatedContent> {";
        for(const auto & v: value.relatedContent.ref()) {
            out << v;
        }
    }
    else {
        out << "    relatedContent is not set\n";
    }

    if (value.cacheKey.isSet()) {
        out << "    cacheKey = "
            << value.cacheKey.ref() << "\n";
    }
    else {
        out << "    cacheKey is not set\n";
    }

    if (value.cacheExpires.isSet()) {
        out << "    cacheExpires = "
            << value.cacheExpires.ref() << "\n";
    }
    else {
        out << "    cacheExpires is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedResultSpec(ThriftBinaryBufferWriter & w, const RelatedResultSpec & s) {
    w.writeStructBegin(QStringLiteral("RelatedResultSpec"));
    if (s.maxNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxNotes"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.maxNotes.ref());
        w.writeFieldEnd();
    }
    if (s.maxNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxNotebooks"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.maxNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.maxTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxTags"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(s.maxTags.ref());
        w.writeFieldEnd();
    }
    if (s.writableNotebooksOnly.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("writableNotebooksOnly"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.writableNotebooksOnly.ref());
        w.writeFieldEnd();
    }
    if (s.includeContainingNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeContainingNotebooks"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.includeContainingNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.includeDebugInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeDebugInfo"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.includeDebugInfo.ref());
        w.writeFieldEnd();
    }
    if (s.maxExperts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxExperts"),
            ThriftFieldType::T_I32,
            7);
        w.writeI32(s.maxExperts.ref());
        w.writeFieldEnd();
    }
    if (s.maxRelatedContent.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxRelatedContent"),
            ThriftFieldType::T_I32,
            8);
        w.writeI32(s.maxRelatedContent.ref());
        w.writeFieldEnd();
    }
    if (s.relatedContentTypes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("relatedContentTypes"),
            ThriftFieldType::T_SET,
            9);
        w.writeSetBegin(ThriftFieldType::T_I32, s.relatedContentTypes.ref().count());
        for(const auto & value: qAsConst(s.relatedContentTypes.ref())) {
            w.writeI32(static_cast<qint32>(value));
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedResultSpec(ThriftBinaryBufferReader & r, RelatedResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.writableNotebooksOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContainingNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeDebugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxExperts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxRelatedContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<RelatedContentType> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (RelatedResultSpec.relatedContentTypes)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentType elem;
                    readEnumRelatedContentType(r, elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.relatedContentTypes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedResultSpec & value)
{
    out << "RelatedResultSpec: {\n";

    if (value.maxNotes.isSet()) {
        out << "    maxNotes = "
            << value.maxNotes.ref() << "\n";
    }
    else {
        out << "    maxNotes is not set\n";
    }

    if (value.maxNotebooks.isSet()) {
        out << "    maxNotebooks = "
            << value.maxNotebooks.ref() << "\n";
    }
    else {
        out << "    maxNotebooks is not set\n";
    }

    if (value.maxTags.isSet()) {
        out << "    maxTags = "
            << value.maxTags.ref() << "\n";
    }
    else {
        out << "    maxTags is not set\n";
    }

    if (value.writableNotebooksOnly.isSet()) {
        out << "    writableNotebooksOnly = "
            << value.writableNotebooksOnly.ref() << "\n";
    }
    else {
        out << "    writableNotebooksOnly is not set\n";
    }

    if (value.includeContainingNotebooks.isSet()) {
        out << "    includeContainingNotebooks = "
            << value.includeContainingNotebooks.ref() << "\n";
    }
    else {
        out << "    includeContainingNotebooks is not set\n";
    }

    if (value.includeDebugInfo.isSet()) {
        out << "    includeDebugInfo = "
            << value.includeDebugInfo.ref() << "\n";
    }
    else {
        out << "    includeDebugInfo is not set\n";
    }

    if (value.maxExperts.isSet()) {
        out << "    maxExperts = "
            << value.maxExperts.ref() << "\n";
    }
    else {
        out << "    maxExperts is not set\n";
    }

    if (value.maxRelatedContent.isSet()) {
        out << "    maxRelatedContent = "
            << value.maxRelatedContent.ref() << "\n";
    }
    else {
        out << "    maxRelatedContent is not set\n";
    }

    if (value.relatedContentTypes.isSet()) {
        out << "    relatedContentTypes = "
            << "QSet<RelatedContentType> {";
        for(const auto & v: value.relatedContentTypes.ref()) {
            out << v;
        }
    }
    else {
        out << "    relatedContentTypes is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedResultSpec & value)
{
    out << "RelatedResultSpec: {\n";

    if (value.maxNotes.isSet()) {
        out << "    maxNotes = "
            << value.maxNotes.ref() << "\n";
    }
    else {
        out << "    maxNotes is not set\n";
    }

    if (value.maxNotebooks.isSet()) {
        out << "    maxNotebooks = "
            << value.maxNotebooks.ref() << "\n";
    }
    else {
        out << "    maxNotebooks is not set\n";
    }

    if (value.maxTags.isSet()) {
        out << "    maxTags = "
            << value.maxTags.ref() << "\n";
    }
    else {
        out << "    maxTags is not set\n";
    }

    if (value.writableNotebooksOnly.isSet()) {
        out << "    writableNotebooksOnly = "
            << value.writableNotebooksOnly.ref() << "\n";
    }
    else {
        out << "    writableNotebooksOnly is not set\n";
    }

    if (value.includeContainingNotebooks.isSet()) {
        out << "    includeContainingNotebooks = "
            << value.includeContainingNotebooks.ref() << "\n";
    }
    else {
        out << "    includeContainingNotebooks is not set\n";
    }

    if (value.includeDebugInfo.isSet()) {
        out << "    includeDebugInfo = "
            << value.includeDebugInfo.ref() << "\n";
    }
    else {
        out << "    includeDebugInfo is not set\n";
    }

    if (value.maxExperts.isSet()) {
        out << "    maxExperts = "
            << value.maxExperts.ref() << "\n";
    }
    else {
        out << "    maxExperts is not set\n";
    }

    if (value.maxRelatedContent.isSet()) {
        out << "    maxRelatedContent = "
            << value.maxRelatedContent.ref() << "\n";
    }
    else {
        out << "    maxRelatedContent is not set\n";
    }

    if (value.relatedContentTypes.isSet()) {
        out << "    relatedContentTypes = "
            << "QSet<RelatedContentType> {";
        for(const auto & v: value.relatedContentTypes.ref()) {
            out << v;
        }
    }
    else {
        out << "    relatedContentTypes is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferWriter & w, const UpdateNoteIfUsnMatchesResult & s) {
    w.writeStructBegin(QStringLiteral("UpdateNoteIfUsnMatchesResult"));
    if (s.note.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            1);
        writeNote(w, s.note.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.updated.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferReader & r, UpdateNoteIfUsnMatchesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(r, v);
                s.note = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UpdateNoteIfUsnMatchesResult & value)
{
    out << "UpdateNoteIfUsnMatchesResult: {\n";

    if (value.note.isSet()) {
        out << "    note = "
            << value.note.ref() << "\n";
    }
    else {
        out << "    note is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UpdateNoteIfUsnMatchesResult & value)
{
    out << "UpdateNoteIfUsnMatchesResult: {\n";

    if (value.note.isSet()) {
        out << "    note = "
            << value.note.ref() << "\n";
    }
    else {
        out << "    note is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const ShareRelationshipRestrictions & s) {
    w.writeStructBegin(QStringLiteral("ShareRelationshipRestrictions"));
    if (s.noSetReadOnly.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetReadOnly"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.noSetReadOnly.ref());
        w.writeFieldEnd();
    }
    if (s.noSetReadPlusActivity.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetReadPlusActivity"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.noSetReadPlusActivity.ref());
        w.writeFieldEnd();
    }
    if (s.noSetModify.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetModify"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.noSetModify.ref());
        w.writeFieldEnd();
    }
    if (s.noSetFullAccess.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.noSetFullAccess.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readShareRelationshipRestrictions(ThriftBinaryBufferReader & r, ShareRelationshipRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadPlusActivity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetModify = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetFullAccess = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ShareRelationshipRestrictions & value)
{
    out << "ShareRelationshipRestrictions: {\n";

    if (value.noSetReadOnly.isSet()) {
        out << "    noSetReadOnly = "
            << value.noSetReadOnly.ref() << "\n";
    }
    else {
        out << "    noSetReadOnly is not set\n";
    }

    if (value.noSetReadPlusActivity.isSet()) {
        out << "    noSetReadPlusActivity = "
            << value.noSetReadPlusActivity.ref() << "\n";
    }
    else {
        out << "    noSetReadPlusActivity is not set\n";
    }

    if (value.noSetModify.isSet()) {
        out << "    noSetModify = "
            << value.noSetModify.ref() << "\n";
    }
    else {
        out << "    noSetModify is not set\n";
    }

    if (value.noSetFullAccess.isSet()) {
        out << "    noSetFullAccess = "
            << value.noSetFullAccess.ref() << "\n";
    }
    else {
        out << "    noSetFullAccess is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ShareRelationshipRestrictions & value)
{
    out << "ShareRelationshipRestrictions: {\n";

    if (value.noSetReadOnly.isSet()) {
        out << "    noSetReadOnly = "
            << value.noSetReadOnly.ref() << "\n";
    }
    else {
        out << "    noSetReadOnly is not set\n";
    }

    if (value.noSetReadPlusActivity.isSet()) {
        out << "    noSetReadPlusActivity = "
            << value.noSetReadPlusActivity.ref() << "\n";
    }
    else {
        out << "    noSetReadPlusActivity is not set\n";
    }

    if (value.noSetModify.isSet()) {
        out << "    noSetModify = "
            << value.noSetModify.ref() << "\n";
    }
    else {
        out << "    noSetModify is not set\n";
    }

    if (value.noSetFullAccess.isSet()) {
        out << "    noSetFullAccess = "
            << value.noSetFullAccess.ref() << "\n";
    }
    else {
        out << "    noSetFullAccess is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeInvitationShareRelationship(ThriftBinaryBufferWriter & w, const InvitationShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("InvitationShareRelationship"));
    if (s.displayName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if (s.recipientUserIdentity.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientUserIdentity"),
            ThriftFieldType::T_STRUCT,
            2);
        writeUserIdentity(w, s.recipientUserIdentity.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.sharerUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readInvitationShareRelationship(ThriftBinaryBufferReader & r, InvitationShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(r, v);
                s.recipientUserIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const InvitationShareRelationship & value)
{
    out << "InvitationShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserIdentity.isSet()) {
        out << "    recipientUserIdentity = "
            << value.recipientUserIdentity.ref() << "\n";
    }
    else {
        out << "    recipientUserIdentity is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const InvitationShareRelationship & value)
{
    out << "InvitationShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserIdentity.isSet()) {
        out << "    recipientUserIdentity = "
            << value.recipientUserIdentity.ref() << "\n";
    }
    else {
        out << "    recipientUserIdentity is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeMemberShareRelationship(ThriftBinaryBufferWriter & w, const MemberShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("MemberShareRelationship"));
    if (s.displayName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if (s.recipientUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if (s.bestPrivilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("bestPrivilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.bestPrivilege.ref()));
        w.writeFieldEnd();
    }
    if (s.individualPrivilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("individualPrivilege"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(static_cast<qint32>(s.individualPrivilege.ref()));
        w.writeFieldEnd();
    }
    if (s.restrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            5);
        writeShareRelationshipRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if (s.sharerUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            6);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readMemberShareRelationship(ThriftBinaryBufferReader & r, MemberShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.bestPrivilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.individualPrivilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const MemberShareRelationship & value)
{
    out << "MemberShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.bestPrivilege.isSet()) {
        out << "    bestPrivilege = "
            << value.bestPrivilege.ref() << "\n";
    }
    else {
        out << "    bestPrivilege is not set\n";
    }

    if (value.individualPrivilege.isSet()) {
        out << "    individualPrivilege = "
            << value.individualPrivilege.ref() << "\n";
    }
    else {
        out << "    individualPrivilege is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const MemberShareRelationship & value)
{
    out << "MemberShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.bestPrivilege.isSet()) {
        out << "    bestPrivilege = "
            << value.bestPrivilege.ref() << "\n";
    }
    else {
        out << "    bestPrivilege is not set\n";
    }

    if (value.individualPrivilege.isSet()) {
        out << "    individualPrivilege = "
            << value.individualPrivilege.ref() << "\n";
    }
    else {
        out << "    individualPrivilege is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeShareRelationships(ThriftBinaryBufferWriter & w, const ShareRelationships & s) {
    w.writeStructBegin(QStringLiteral("ShareRelationships"));
    if (s.invitations.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(const auto & value: qAsConst(s.invitations.ref())) {
            writeInvitationShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.memberships.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(const auto & value: qAsConst(s.memberships.ref())) {
            writeMemberShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.invitationRestrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);
        writeShareRelationshipRestrictions(w, s.invitationRestrictions.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readShareRelationships(ThriftBinaryBufferReader & r, ShareRelationships & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ShareRelationships.invitations)"));
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitations = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ShareRelationships.memberships)"));
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.memberships = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(r, v);
                s.invitationRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ShareRelationships & value)
{
    out << "ShareRelationships: {\n";

    if (value.invitations.isSet()) {
        out << "    invitations = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: value.invitations.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitations is not set\n";
    }

    if (value.memberships.isSet()) {
        out << "    memberships = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: value.memberships.ref()) {
            out << v;
        }
    }
    else {
        out << "    memberships is not set\n";
    }

    if (value.invitationRestrictions.isSet()) {
        out << "    invitationRestrictions = "
            << value.invitationRestrictions.ref() << "\n";
    }
    else {
        out << "    invitationRestrictions is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ShareRelationships & value)
{
    out << "ShareRelationships: {\n";

    if (value.invitations.isSet()) {
        out << "    invitations = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: value.invitations.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitations is not set\n";
    }

    if (value.memberships.isSet()) {
        out << "    memberships = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: value.memberships.ref()) {
            out << v;
        }
    }
    else {
        out << "    memberships is not set\n";
    }

    if (value.invitationRestrictions.isSet()) {
        out << "    invitationRestrictions = "
            << value.invitationRestrictions.ref() << "\n";
    }
    else {
        out << "    invitationRestrictions is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesParameters(ThriftBinaryBufferWriter & w, const ManageNotebookSharesParameters & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesParameters"));
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.inviteMessage.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("inviteMessage"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.inviteMessage.ref());
        w.writeFieldEnd();
    }
    if (s.membershipsToUpdate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUpdate.ref())) {
            writeMemberShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.invitationsToCreateOrUpdate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitationsToCreateOrUpdate"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToCreateOrUpdate.ref().length());
        for(const auto & value: qAsConst(s.invitationsToCreateOrUpdate.ref())) {
            writeInvitationShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.unshares.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("unshares"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.unshares.ref().length());
        for(const auto & value: qAsConst(s.unshares.ref())) {
            writeUserIdentity(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesParameters(ThriftBinaryBufferReader & r, ManageNotebookSharesParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.inviteMessage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.membershipsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.invitationsToCreateOrUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToCreateOrUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserIdentity> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.unshares)"));
                for(qint32 i = 0; i < size; i++) {
                    UserIdentity elem;
                    readUserIdentity(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.unshares = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNotebookSharesParameters & value)
{
    out << "ManageNotebookSharesParameters: {\n";

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.inviteMessage.isSet()) {
        out << "    inviteMessage = "
            << value.inviteMessage.ref() << "\n";
    }
    else {
        out << "    inviteMessage is not set\n";
    }

    if (value.membershipsToUpdate.isSet()) {
        out << "    membershipsToUpdate = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: value.membershipsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUpdate is not set\n";
    }

    if (value.invitationsToCreateOrUpdate.isSet()) {
        out << "    invitationsToCreateOrUpdate = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: value.invitationsToCreateOrUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToCreateOrUpdate is not set\n";
    }

    if (value.unshares.isSet()) {
        out << "    unshares = "
            << "QList<UserIdentity> {";
        for(const auto & v: value.unshares.ref()) {
            out << v;
        }
    }
    else {
        out << "    unshares is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNotebookSharesParameters & value)
{
    out << "ManageNotebookSharesParameters: {\n";

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.inviteMessage.isSet()) {
        out << "    inviteMessage = "
            << value.inviteMessage.ref() << "\n";
    }
    else {
        out << "    inviteMessage is not set\n";
    }

    if (value.membershipsToUpdate.isSet()) {
        out << "    membershipsToUpdate = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: value.membershipsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUpdate is not set\n";
    }

    if (value.invitationsToCreateOrUpdate.isSet()) {
        out << "    invitationsToCreateOrUpdate = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: value.invitationsToCreateOrUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToCreateOrUpdate is not set\n";
    }

    if (value.unshares.isSet()) {
        out << "    unshares = "
            << "QList<UserIdentity> {";
        for(const auto & v: value.unshares.ref()) {
            out << v;
        }
    }
    else {
        out << "    unshares is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesError(ThriftBinaryBufferWriter & w, const ManageNotebookSharesError & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesError"));
    if (s.userIdentity.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userIdentity"),
            ThriftFieldType::T_STRUCT,
            1);
        writeUserIdentity(w, s.userIdentity.ref());
        w.writeFieldEnd();
    }
    if (s.userException.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            2);
        writeEDAMUserException(w, s.userException.ref());
        w.writeFieldEnd();
    }
    if (s.notFoundException.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            3);
        writeEDAMNotFoundException(w, s.notFoundException.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesError(ThriftBinaryBufferReader & r, ManageNotebookSharesError & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(r, v);
                s.userIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(r, v);
                s.userException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(r, v);
                s.notFoundException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNotebookSharesError & value)
{
    out << "ManageNotebookSharesError: {\n";

    if (value.userIdentity.isSet()) {
        out << "    userIdentity = "
            << value.userIdentity.ref() << "\n";
    }
    else {
        out << "    userIdentity is not set\n";
    }

    if (value.userException.isSet()) {
        out << "    userException = "
            << value.userException.ref() << "\n";
    }
    else {
        out << "    userException is not set\n";
    }

    if (value.notFoundException.isSet()) {
        out << "    notFoundException = "
            << value.notFoundException.ref() << "\n";
    }
    else {
        out << "    notFoundException is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNotebookSharesError & value)
{
    out << "ManageNotebookSharesError: {\n";

    if (value.userIdentity.isSet()) {
        out << "    userIdentity = "
            << value.userIdentity.ref() << "\n";
    }
    else {
        out << "    userIdentity is not set\n";
    }

    if (value.userException.isSet()) {
        out << "    userException = "
            << value.userException.ref() << "\n";
    }
    else {
        out << "    userException is not set\n";
    }

    if (value.notFoundException.isSet()) {
        out << "    notFoundException = "
            << value.notFoundException.ref() << "\n";
    }
    else {
        out << "    notFoundException is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesResult(ThriftBinaryBufferWriter & w, const ManageNotebookSharesResult & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesResult"));
    if (s.errors.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(const auto & value: qAsConst(s.errors.ref())) {
            writeManageNotebookSharesError(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesResult(ThriftBinaryBufferReader & r, ManageNotebookSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNotebookSharesError> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesResult.errors)"));
                for(qint32 i = 0; i < size; i++) {
                    ManageNotebookSharesError elem;
                    readManageNotebookSharesError(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.errors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNotebookSharesResult & value)
{
    out << "ManageNotebookSharesResult: {\n";

    if (value.errors.isSet()) {
        out << "    errors = "
            << "QList<ManageNotebookSharesError> {";
        for(const auto & v: value.errors.ref()) {
            out << v;
        }
    }
    else {
        out << "    errors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNotebookSharesResult & value)
{
    out << "ManageNotebookSharesResult: {\n";

    if (value.errors.isSet()) {
        out << "    errors = "
            << "QList<ManageNotebookSharesError> {";
        for(const auto & v: value.errors.ref()) {
            out << v;
        }
    }
    else {
        out << "    errors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNoteTemplate(ThriftBinaryBufferWriter & w, const SharedNoteTemplate & s) {
    w.writeStructBegin(QStringLiteral("SharedNoteTemplate"));
    if (s.noteGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if (s.recipientThreadId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);
        w.writeI64(s.recipientThreadId.ref());
        w.writeFieldEnd();
    }
    if (s.recipientContacts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(const auto & value: qAsConst(s.recipientContacts.ref())) {
            writeContact(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNoteTemplate(ThriftBinaryBufferReader & r, SharedNoteTemplate & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                r.readI64(v);
                s.recipientThreadId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SharedNoteTemplate.recipientContacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recipientContacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNoteTemplate & value)
{
    out << "SharedNoteTemplate: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.recipientThreadId.isSet()) {
        out << "    recipientThreadId = "
            << value.recipientThreadId.ref() << "\n";
    }
    else {
        out << "    recipientThreadId is not set\n";
    }

    if (value.recipientContacts.isSet()) {
        out << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: value.recipientContacts.ref()) {
            out << v;
        }
    }
    else {
        out << "    recipientContacts is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNoteTemplate & value)
{
    out << "SharedNoteTemplate: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.recipientThreadId.isSet()) {
        out << "    recipientThreadId = "
            << value.recipientThreadId.ref() << "\n";
    }
    else {
        out << "    recipientThreadId is not set\n";
    }

    if (value.recipientContacts.isSet()) {
        out << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: value.recipientContacts.ref()) {
            out << v;
        }
    }
    else {
        out << "    recipientContacts is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookShareTemplate(ThriftBinaryBufferWriter & w, const NotebookShareTemplate & s) {
    w.writeStructBegin(QStringLiteral("NotebookShareTemplate"));
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.recipientThreadId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);
        w.writeI64(s.recipientThreadId.ref());
        w.writeFieldEnd();
    }
    if (s.recipientContacts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(const auto & value: qAsConst(s.recipientContacts.ref())) {
            writeContact(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookShareTemplate(ThriftBinaryBufferReader & r, NotebookShareTemplate & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                r.readI64(v);
                s.recipientThreadId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotebookShareTemplate.recipientContacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recipientContacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotebookShareTemplate & value)
{
    out << "NotebookShareTemplate: {\n";

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.recipientThreadId.isSet()) {
        out << "    recipientThreadId = "
            << value.recipientThreadId.ref() << "\n";
    }
    else {
        out << "    recipientThreadId is not set\n";
    }

    if (value.recipientContacts.isSet()) {
        out << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: value.recipientContacts.ref()) {
            out << v;
        }
    }
    else {
        out << "    recipientContacts is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotebookShareTemplate & value)
{
    out << "NotebookShareTemplate: {\n";

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.recipientThreadId.isSet()) {
        out << "    recipientThreadId = "
            << value.recipientThreadId.ref() << "\n";
    }
    else {
        out << "    recipientThreadId is not set\n";
    }

    if (value.recipientContacts.isSet()) {
        out << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: value.recipientContacts.ref()) {
            out << v;
        }
    }
    else {
        out << "    recipientContacts is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferWriter & w, const CreateOrUpdateNotebookSharesResult & s) {
    w.writeStructBegin(QStringLiteral("CreateOrUpdateNotebookSharesResult"));
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.matchingShares.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("matchingShares"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.matchingShares.ref().length());
        for(const auto & value: qAsConst(s.matchingShares.ref())) {
            writeSharedNotebook(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferReader & r, CreateOrUpdateNotebookSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (CreateOrUpdateNotebookSharesResult.matchingShares)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.matchingShares = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const CreateOrUpdateNotebookSharesResult & value)
{
    out << "CreateOrUpdateNotebookSharesResult: {\n";

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.matchingShares.isSet()) {
        out << "    matchingShares = "
            << "QList<SharedNotebook> {";
        for(const auto & v: value.matchingShares.ref()) {
            out << v;
        }
    }
    else {
        out << "    matchingShares is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const CreateOrUpdateNotebookSharesResult & value)
{
    out << "CreateOrUpdateNotebookSharesResult: {\n";

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.matchingShares.isSet()) {
        out << "    matchingShares = "
            << "QList<SharedNotebook> {";
        for(const auto & v: value.matchingShares.ref()) {
            out << v;
        }
    }
    else {
        out << "    matchingShares is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const NoteShareRelationshipRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NoteShareRelationshipRestrictions"));
    if (s.noSetReadNote.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetReadNote"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.noSetReadNote.ref());
        w.writeFieldEnd();
    }
    if (s.noSetModifyNote.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetModifyNote"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.noSetModifyNote.ref());
        w.writeFieldEnd();
    }
    if (s.noSetFullAccess.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.noSetFullAccess.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteShareRelationshipRestrictions(ThriftBinaryBufferReader & r, NoteShareRelationshipRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetModifyNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetFullAccess = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteShareRelationshipRestrictions & value)
{
    out << "NoteShareRelationshipRestrictions: {\n";

    if (value.noSetReadNote.isSet()) {
        out << "    noSetReadNote = "
            << value.noSetReadNote.ref() << "\n";
    }
    else {
        out << "    noSetReadNote is not set\n";
    }

    if (value.noSetModifyNote.isSet()) {
        out << "    noSetModifyNote = "
            << value.noSetModifyNote.ref() << "\n";
    }
    else {
        out << "    noSetModifyNote is not set\n";
    }

    if (value.noSetFullAccess.isSet()) {
        out << "    noSetFullAccess = "
            << value.noSetFullAccess.ref() << "\n";
    }
    else {
        out << "    noSetFullAccess is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteShareRelationshipRestrictions & value)
{
    out << "NoteShareRelationshipRestrictions: {\n";

    if (value.noSetReadNote.isSet()) {
        out << "    noSetReadNote = "
            << value.noSetReadNote.ref() << "\n";
    }
    else {
        out << "    noSetReadNote is not set\n";
    }

    if (value.noSetModifyNote.isSet()) {
        out << "    noSetModifyNote = "
            << value.noSetModifyNote.ref() << "\n";
    }
    else {
        out << "    noSetModifyNote is not set\n";
    }

    if (value.noSetFullAccess.isSet()) {
        out << "    noSetFullAccess = "
            << value.noSetFullAccess.ref() << "\n";
    }
    else {
        out << "    noSetFullAccess is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteMemberShareRelationship(ThriftBinaryBufferWriter & w, const NoteMemberShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("NoteMemberShareRelationship"));
    if (s.displayName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if (s.recipientUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.restrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            4);
        writeNoteShareRelationshipRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if (s.sharerUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteMemberShareRelationship(ThriftBinaryBufferReader & r, NoteMemberShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteMemberShareRelationship & value)
{
    out << "NoteMemberShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteMemberShareRelationship & value)
{
    out << "NoteMemberShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteInvitationShareRelationship(ThriftBinaryBufferWriter & w, const NoteInvitationShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("NoteInvitationShareRelationship"));
    if (s.displayName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if (s.recipientIdentityId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            2);
        w.writeI64(s.recipientIdentityId.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.sharerUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteInvitationShareRelationship(ThriftBinaryBufferReader & r, NoteInvitationShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.recipientIdentityId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteInvitationShareRelationship & value)
{
    out << "NoteInvitationShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientIdentityId.isSet()) {
        out << "    recipientIdentityId = "
            << value.recipientIdentityId.ref() << "\n";
    }
    else {
        out << "    recipientIdentityId is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteInvitationShareRelationship & value)
{
    out << "NoteInvitationShareRelationship: {\n";

    if (value.displayName.isSet()) {
        out << "    displayName = "
            << value.displayName.ref() << "\n";
    }
    else {
        out << "    displayName is not set\n";
    }

    if (value.recipientIdentityId.isSet()) {
        out << "    recipientIdentityId = "
            << value.recipientIdentityId.ref() << "\n";
    }
    else {
        out << "    recipientIdentityId is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteShareRelationships(ThriftBinaryBufferWriter & w, const NoteShareRelationships & s) {
    w.writeStructBegin(QStringLiteral("NoteShareRelationships"));
    if (s.invitations.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(const auto & value: qAsConst(s.invitations.ref())) {
            writeNoteInvitationShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.memberships.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(const auto & value: qAsConst(s.memberships.ref())) {
            writeNoteMemberShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.invitationRestrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);
        writeNoteShareRelationshipRestrictions(w, s.invitationRestrictions.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteShareRelationships(ThriftBinaryBufferReader & r, NoteShareRelationships & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteShareRelationships.invitations)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitations = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteShareRelationships.memberships)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.memberships = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(r, v);
                s.invitationRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteShareRelationships & value)
{
    out << "NoteShareRelationships: {\n";

    if (value.invitations.isSet()) {
        out << "    invitations = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: value.invitations.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitations is not set\n";
    }

    if (value.memberships.isSet()) {
        out << "    memberships = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: value.memberships.ref()) {
            out << v;
        }
    }
    else {
        out << "    memberships is not set\n";
    }

    if (value.invitationRestrictions.isSet()) {
        out << "    invitationRestrictions = "
            << value.invitationRestrictions.ref() << "\n";
    }
    else {
        out << "    invitationRestrictions is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteShareRelationships & value)
{
    out << "NoteShareRelationships: {\n";

    if (value.invitations.isSet()) {
        out << "    invitations = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: value.invitations.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitations is not set\n";
    }

    if (value.memberships.isSet()) {
        out << "    memberships = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: value.memberships.ref()) {
            out << v;
        }
    }
    else {
        out << "    memberships is not set\n";
    }

    if (value.invitationRestrictions.isSet()) {
        out << "    invitationRestrictions = "
            << value.invitationRestrictions.ref() << "\n";
    }
    else {
        out << "    invitationRestrictions is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesParameters(ThriftBinaryBufferWriter & w, const ManageNoteSharesParameters & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesParameters"));
    if (s.noteGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if (s.membershipsToUpdate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUpdate.ref())) {
            writeNoteMemberShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.invitationsToUpdate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitationsToUpdate"),
            ThriftFieldType::T_LIST,
            3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.invitationsToUpdate.ref())) {
            writeNoteInvitationShareRelationship(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.membershipsToUnshare.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("membershipsToUnshare"),
            ThriftFieldType::T_LIST,
            4);
        w.writeListBegin(ThriftFieldType::T_I32, s.membershipsToUnshare.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUnshare.ref())) {
            w.writeI32(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.invitationsToUnshare.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("invitationsToUnshare"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_I64, s.invitationsToUnshare.ref().length());
        for(const auto & value: qAsConst(s.invitationsToUnshare.ref())) {
            w.writeI64(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesParameters(ThriftBinaryBufferReader & r, ManageNoteSharesParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserID> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUnshare)"));
                for(qint32 i = 0; i < size; i++) {
                    UserID elem;
                    r.readI32(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUnshare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<IdentityID> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I64) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUnshare)"));
                for(qint32 i = 0; i < size; i++) {
                    IdentityID elem;
                    r.readI64(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToUnshare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNoteSharesParameters & value)
{
    out << "ManageNoteSharesParameters: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.membershipsToUpdate.isSet()) {
        out << "    membershipsToUpdate = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: value.membershipsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUpdate is not set\n";
    }

    if (value.invitationsToUpdate.isSet()) {
        out << "    invitationsToUpdate = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: value.invitationsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToUpdate is not set\n";
    }

    if (value.membershipsToUnshare.isSet()) {
        out << "    membershipsToUnshare = "
            << "QList<UserID> {";
        for(const auto & v: value.membershipsToUnshare.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUnshare is not set\n";
    }

    if (value.invitationsToUnshare.isSet()) {
        out << "    invitationsToUnshare = "
            << "QList<IdentityID> {";
        for(const auto & v: value.invitationsToUnshare.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToUnshare is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNoteSharesParameters & value)
{
    out << "ManageNoteSharesParameters: {\n";

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.membershipsToUpdate.isSet()) {
        out << "    membershipsToUpdate = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: value.membershipsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUpdate is not set\n";
    }

    if (value.invitationsToUpdate.isSet()) {
        out << "    invitationsToUpdate = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: value.invitationsToUpdate.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToUpdate is not set\n";
    }

    if (value.membershipsToUnshare.isSet()) {
        out << "    membershipsToUnshare = "
            << "QList<UserID> {";
        for(const auto & v: value.membershipsToUnshare.ref()) {
            out << v;
        }
    }
    else {
        out << "    membershipsToUnshare is not set\n";
    }

    if (value.invitationsToUnshare.isSet()) {
        out << "    invitationsToUnshare = "
            << "QList<IdentityID> {";
        for(const auto & v: value.invitationsToUnshare.ref()) {
            out << v;
        }
    }
    else {
        out << "    invitationsToUnshare is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesError(ThriftBinaryBufferWriter & w, const ManageNoteSharesError & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesError"));
    if (s.identityID.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("identityID"),
            ThriftFieldType::T_I64,
            1);
        w.writeI64(s.identityID.ref());
        w.writeFieldEnd();
    }
    if (s.userID.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userID"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.userID.ref());
        w.writeFieldEnd();
    }
    if (s.userException.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            3);
        writeEDAMUserException(w, s.userException.ref());
        w.writeFieldEnd();
    }
    if (s.notFoundException.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            4);
        writeEDAMNotFoundException(w, s.notFoundException.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesError(ThriftBinaryBufferReader & r, ManageNoteSharesError & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.identityID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(r, v);
                s.userException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(r, v);
                s.notFoundException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNoteSharesError & value)
{
    out << "ManageNoteSharesError: {\n";

    if (value.identityID.isSet()) {
        out << "    identityID = "
            << value.identityID.ref() << "\n";
    }
    else {
        out << "    identityID is not set\n";
    }

    if (value.userID.isSet()) {
        out << "    userID = "
            << value.userID.ref() << "\n";
    }
    else {
        out << "    userID is not set\n";
    }

    if (value.userException.isSet()) {
        out << "    userException = "
            << value.userException.ref() << "\n";
    }
    else {
        out << "    userException is not set\n";
    }

    if (value.notFoundException.isSet()) {
        out << "    notFoundException = "
            << value.notFoundException.ref() << "\n";
    }
    else {
        out << "    notFoundException is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNoteSharesError & value)
{
    out << "ManageNoteSharesError: {\n";

    if (value.identityID.isSet()) {
        out << "    identityID = "
            << value.identityID.ref() << "\n";
    }
    else {
        out << "    identityID is not set\n";
    }

    if (value.userID.isSet()) {
        out << "    userID = "
            << value.userID.ref() << "\n";
    }
    else {
        out << "    userID is not set\n";
    }

    if (value.userException.isSet()) {
        out << "    userException = "
            << value.userException.ref() << "\n";
    }
    else {
        out << "    userException is not set\n";
    }

    if (value.notFoundException.isSet()) {
        out << "    notFoundException = "
            << value.notFoundException.ref() << "\n";
    }
    else {
        out << "    notFoundException is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesResult(ThriftBinaryBufferWriter & w, const ManageNoteSharesResult & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesResult"));
    if (s.errors.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(const auto & value: qAsConst(s.errors.ref())) {
            writeManageNoteSharesError(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesResult(ThriftBinaryBufferReader & r, ManageNoteSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNoteSharesError> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesResult.errors)"));
                for(qint32 i = 0; i < size; i++) {
                    ManageNoteSharesError elem;
                    readManageNoteSharesError(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.errors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ManageNoteSharesResult & value)
{
    out << "ManageNoteSharesResult: {\n";

    if (value.errors.isSet()) {
        out << "    errors = "
            << "QList<ManageNoteSharesError> {";
        for(const auto & v: value.errors.ref()) {
            out << v;
        }
    }
    else {
        out << "    errors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ManageNoteSharesResult & value)
{
    out << "ManageNoteSharesResult: {\n";

    if (value.errors.isSet()) {
        out << "    errors = "
            << "QList<ManageNoteSharesError> {";
        for(const auto & v: value.errors.ref()) {
            out << v;
        }
    }
    else {
        out << "    errors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeData(ThriftBinaryBufferWriter & w, const Data & s) {
    w.writeStructBegin(QStringLiteral("Data"));
    if (s.bodyHash.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("bodyHash"),
            ThriftFieldType::T_STRING,
            1);
        w.writeBinary(s.bodyHash.ref());
        w.writeFieldEnd();
    }
    if (s.size.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("size"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.size.ref());
        w.writeFieldEnd();
    }
    if (s.body.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("body"),
            ThriftFieldType::T_STRING,
            3);
        w.writeBinary(s.body.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readData(ThriftBinaryBufferReader & r, Data & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.bodyHash = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.size = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.body = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Data & value)
{
    out << "Data: {\n";

    if (value.bodyHash.isSet()) {
        out << "    bodyHash = "
            << value.bodyHash.ref() << "\n";
    }
    else {
        out << "    bodyHash is not set\n";
    }

    if (value.size.isSet()) {
        out << "    size = "
            << value.size.ref() << "\n";
    }
    else {
        out << "    size is not set\n";
    }

    if (value.body.isSet()) {
        out << "    body = "
            << value.body.ref() << "\n";
    }
    else {
        out << "    body is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Data & value)
{
    out << "Data: {\n";

    if (value.bodyHash.isSet()) {
        out << "    bodyHash = "
            << value.bodyHash.ref() << "\n";
    }
    else {
        out << "    bodyHash is not set\n";
    }

    if (value.size.isSet()) {
        out << "    size = "
            << value.size.ref() << "\n";
    }
    else {
        out << "    size is not set\n";
    }

    if (value.body.isSet()) {
        out << "    body = "
            << value.body.ref() << "\n";
    }
    else {
        out << "    body is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUserAttributes(ThriftBinaryBufferWriter & w, const UserAttributes & s) {
    w.writeStructBegin(QStringLiteral("UserAttributes"));
    if (s.defaultLocationName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("defaultLocationName"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.defaultLocationName.ref());
        w.writeFieldEnd();
    }
    if (s.defaultLatitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("defaultLatitude"),
            ThriftFieldType::T_DOUBLE,
            2);
        w.writeDouble(s.defaultLatitude.ref());
        w.writeFieldEnd();
    }
    if (s.defaultLongitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("defaultLongitude"),
            ThriftFieldType::T_DOUBLE,
            3);
        w.writeDouble(s.defaultLongitude.ref());
        w.writeFieldEnd();
    }
    if (s.preactivation.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("preactivation"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.preactivation.ref());
        w.writeFieldEnd();
    }
    if (s.viewedPromotions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("viewedPromotions"),
            ThriftFieldType::T_LIST,
            5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.viewedPromotions.ref().length());
        for(const auto & value: qAsConst(s.viewedPromotions.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.incomingEmailAddress.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("incomingEmailAddress"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.incomingEmailAddress.ref());
        w.writeFieldEnd();
    }
    if (s.recentMailedAddresses.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recentMailedAddresses"),
            ThriftFieldType::T_LIST,
            7);
        w.writeListBegin(ThriftFieldType::T_STRING, s.recentMailedAddresses.ref().length());
        for(const auto & value: qAsConst(s.recentMailedAddresses.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.comments.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("comments"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.comments.ref());
        w.writeFieldEnd();
    }
    if (s.dateAgreedToTermsOfService.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("dateAgreedToTermsOfService"),
            ThriftFieldType::T_I64,
            11);
        w.writeI64(s.dateAgreedToTermsOfService.ref());
        w.writeFieldEnd();
    }
    if (s.maxReferrals.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("maxReferrals"),
            ThriftFieldType::T_I32,
            12);
        w.writeI32(s.maxReferrals.ref());
        w.writeFieldEnd();
    }
    if (s.referralCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("referralCount"),
            ThriftFieldType::T_I32,
            13);
        w.writeI32(s.referralCount.ref());
        w.writeFieldEnd();
    }
    if (s.refererCode.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("refererCode"),
            ThriftFieldType::T_STRING,
            14);
        w.writeString(s.refererCode.ref());
        w.writeFieldEnd();
    }
    if (s.sentEmailDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sentEmailDate"),
            ThriftFieldType::T_I64,
            15);
        w.writeI64(s.sentEmailDate.ref());
        w.writeFieldEnd();
    }
    if (s.sentEmailCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sentEmailCount"),
            ThriftFieldType::T_I32,
            16);
        w.writeI32(s.sentEmailCount.ref());
        w.writeFieldEnd();
    }
    if (s.dailyEmailLimit.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("dailyEmailLimit"),
            ThriftFieldType::T_I32,
            17);
        w.writeI32(s.dailyEmailLimit.ref());
        w.writeFieldEnd();
    }
    if (s.emailOptOutDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("emailOptOutDate"),
            ThriftFieldType::T_I64,
            18);
        w.writeI64(s.emailOptOutDate.ref());
        w.writeFieldEnd();
    }
    if (s.partnerEmailOptInDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("partnerEmailOptInDate"),
            ThriftFieldType::T_I64,
            19);
        w.writeI64(s.partnerEmailOptInDate.ref());
        w.writeFieldEnd();
    }
    if (s.preferredLanguage.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("preferredLanguage"),
            ThriftFieldType::T_STRING,
            20);
        w.writeString(s.preferredLanguage.ref());
        w.writeFieldEnd();
    }
    if (s.preferredCountry.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("preferredCountry"),
            ThriftFieldType::T_STRING,
            21);
        w.writeString(s.preferredCountry.ref());
        w.writeFieldEnd();
    }
    if (s.clipFullPage.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("clipFullPage"),
            ThriftFieldType::T_BOOL,
            22);
        w.writeBool(s.clipFullPage.ref());
        w.writeFieldEnd();
    }
    if (s.twitterUserName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("twitterUserName"),
            ThriftFieldType::T_STRING,
            23);
        w.writeString(s.twitterUserName.ref());
        w.writeFieldEnd();
    }
    if (s.twitterId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("twitterId"),
            ThriftFieldType::T_STRING,
            24);
        w.writeString(s.twitterId.ref());
        w.writeFieldEnd();
    }
    if (s.groupName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("groupName"),
            ThriftFieldType::T_STRING,
            25);
        w.writeString(s.groupName.ref());
        w.writeFieldEnd();
    }
    if (s.recognitionLanguage.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recognitionLanguage"),
            ThriftFieldType::T_STRING,
            26);
        w.writeString(s.recognitionLanguage.ref());
        w.writeFieldEnd();
    }
    if (s.referralProof.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("referralProof"),
            ThriftFieldType::T_STRING,
            28);
        w.writeString(s.referralProof.ref());
        w.writeFieldEnd();
    }
    if (s.educationalDiscount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("educationalDiscount"),
            ThriftFieldType::T_BOOL,
            29);
        w.writeBool(s.educationalDiscount.ref());
        w.writeFieldEnd();
    }
    if (s.businessAddress.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessAddress"),
            ThriftFieldType::T_STRING,
            30);
        w.writeString(s.businessAddress.ref());
        w.writeFieldEnd();
    }
    if (s.hideSponsorBilling.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("hideSponsorBilling"),
            ThriftFieldType::T_BOOL,
            31);
        w.writeBool(s.hideSponsorBilling.ref());
        w.writeFieldEnd();
    }
    if (s.useEmailAutoFiling.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("useEmailAutoFiling"),
            ThriftFieldType::T_BOOL,
            33);
        w.writeBool(s.useEmailAutoFiling.ref());
        w.writeFieldEnd();
    }
    if (s.reminderEmailConfig.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderEmailConfig"),
            ThriftFieldType::T_I32,
            34);
        w.writeI32(static_cast<qint32>(s.reminderEmailConfig.ref()));
        w.writeFieldEnd();
    }
    if (s.emailAddressLastConfirmed.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("emailAddressLastConfirmed"),
            ThriftFieldType::T_I64,
            35);
        w.writeI64(s.emailAddressLastConfirmed.ref());
        w.writeFieldEnd();
    }
    if (s.passwordUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("passwordUpdated"),
            ThriftFieldType::T_I64,
            36);
        w.writeI64(s.passwordUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.salesforcePushEnabled.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("salesforcePushEnabled"),
            ThriftFieldType::T_BOOL,
            37);
        w.writeBool(s.salesforcePushEnabled.ref());
        w.writeFieldEnd();
    }
    if (s.shouldLogClientEvent.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("shouldLogClientEvent"),
            ThriftFieldType::T_BOOL,
            38);
        w.writeBool(s.shouldLogClientEvent.ref());
        w.writeFieldEnd();
    }
    if (s.optOutMachineLearning.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("optOutMachineLearning"),
            ThriftFieldType::T_BOOL,
            39);
        w.writeBool(s.optOutMachineLearning.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserAttributes(ThriftBinaryBufferReader & r, UserAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.defaultLocationName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.defaultLatitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.defaultLongitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.preactivation = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (UserAttributes.viewedPromotions)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.viewedPromotions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.incomingEmailAddress = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (UserAttributes.recentMailedAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recentMailedAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.comments = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.dateAgreedToTermsOfService = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxReferrals = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.referralCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.refererCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.sentEmailDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.sentEmailCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.dailyEmailLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.emailOptOutDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.partnerEmailOptInDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.preferredLanguage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.preferredCountry = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.clipFullPage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.twitterUserName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.twitterId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.groupName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recognitionLanguage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.referralProof = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.educationalDiscount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessAddress = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.hideSponsorBilling = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 33) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.useEmailAutoFiling = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 34) {
            if (fieldType == ThriftFieldType::T_I32) {
                ReminderEmailConfig v;
                readEnumReminderEmailConfig(r, v);
                s.reminderEmailConfig = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 35) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.emailAddressLastConfirmed = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 36) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.passwordUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 37) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.salesforcePushEnabled = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 38) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.shouldLogClientEvent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 39) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.optOutMachineLearning = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UserAttributes & value)
{
    out << "UserAttributes: {\n";

    if (value.defaultLocationName.isSet()) {
        out << "    defaultLocationName = "
            << value.defaultLocationName.ref() << "\n";
    }
    else {
        out << "    defaultLocationName is not set\n";
    }

    if (value.defaultLatitude.isSet()) {
        out << "    defaultLatitude = "
            << value.defaultLatitude.ref() << "\n";
    }
    else {
        out << "    defaultLatitude is not set\n";
    }

    if (value.defaultLongitude.isSet()) {
        out << "    defaultLongitude = "
            << value.defaultLongitude.ref() << "\n";
    }
    else {
        out << "    defaultLongitude is not set\n";
    }

    if (value.preactivation.isSet()) {
        out << "    preactivation = "
            << value.preactivation.ref() << "\n";
    }
    else {
        out << "    preactivation is not set\n";
    }

    if (value.viewedPromotions.isSet()) {
        out << "    viewedPromotions = "
            << "QList<QString> {";
        for(const auto & v: value.viewedPromotions.ref()) {
            out << v;
        }
    }
    else {
        out << "    viewedPromotions is not set\n";
    }

    if (value.incomingEmailAddress.isSet()) {
        out << "    incomingEmailAddress = "
            << value.incomingEmailAddress.ref() << "\n";
    }
    else {
        out << "    incomingEmailAddress is not set\n";
    }

    if (value.recentMailedAddresses.isSet()) {
        out << "    recentMailedAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.recentMailedAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    recentMailedAddresses is not set\n";
    }

    if (value.comments.isSet()) {
        out << "    comments = "
            << value.comments.ref() << "\n";
    }
    else {
        out << "    comments is not set\n";
    }

    if (value.dateAgreedToTermsOfService.isSet()) {
        out << "    dateAgreedToTermsOfService = "
            << value.dateAgreedToTermsOfService.ref() << "\n";
    }
    else {
        out << "    dateAgreedToTermsOfService is not set\n";
    }

    if (value.maxReferrals.isSet()) {
        out << "    maxReferrals = "
            << value.maxReferrals.ref() << "\n";
    }
    else {
        out << "    maxReferrals is not set\n";
    }

    if (value.referralCount.isSet()) {
        out << "    referralCount = "
            << value.referralCount.ref() << "\n";
    }
    else {
        out << "    referralCount is not set\n";
    }

    if (value.refererCode.isSet()) {
        out << "    refererCode = "
            << value.refererCode.ref() << "\n";
    }
    else {
        out << "    refererCode is not set\n";
    }

    if (value.sentEmailDate.isSet()) {
        out << "    sentEmailDate = "
            << value.sentEmailDate.ref() << "\n";
    }
    else {
        out << "    sentEmailDate is not set\n";
    }

    if (value.sentEmailCount.isSet()) {
        out << "    sentEmailCount = "
            << value.sentEmailCount.ref() << "\n";
    }
    else {
        out << "    sentEmailCount is not set\n";
    }

    if (value.dailyEmailLimit.isSet()) {
        out << "    dailyEmailLimit = "
            << value.dailyEmailLimit.ref() << "\n";
    }
    else {
        out << "    dailyEmailLimit is not set\n";
    }

    if (value.emailOptOutDate.isSet()) {
        out << "    emailOptOutDate = "
            << value.emailOptOutDate.ref() << "\n";
    }
    else {
        out << "    emailOptOutDate is not set\n";
    }

    if (value.partnerEmailOptInDate.isSet()) {
        out << "    partnerEmailOptInDate = "
            << value.partnerEmailOptInDate.ref() << "\n";
    }
    else {
        out << "    partnerEmailOptInDate is not set\n";
    }

    if (value.preferredLanguage.isSet()) {
        out << "    preferredLanguage = "
            << value.preferredLanguage.ref() << "\n";
    }
    else {
        out << "    preferredLanguage is not set\n";
    }

    if (value.preferredCountry.isSet()) {
        out << "    preferredCountry = "
            << value.preferredCountry.ref() << "\n";
    }
    else {
        out << "    preferredCountry is not set\n";
    }

    if (value.clipFullPage.isSet()) {
        out << "    clipFullPage = "
            << value.clipFullPage.ref() << "\n";
    }
    else {
        out << "    clipFullPage is not set\n";
    }

    if (value.twitterUserName.isSet()) {
        out << "    twitterUserName = "
            << value.twitterUserName.ref() << "\n";
    }
    else {
        out << "    twitterUserName is not set\n";
    }

    if (value.twitterId.isSet()) {
        out << "    twitterId = "
            << value.twitterId.ref() << "\n";
    }
    else {
        out << "    twitterId is not set\n";
    }

    if (value.groupName.isSet()) {
        out << "    groupName = "
            << value.groupName.ref() << "\n";
    }
    else {
        out << "    groupName is not set\n";
    }

    if (value.recognitionLanguage.isSet()) {
        out << "    recognitionLanguage = "
            << value.recognitionLanguage.ref() << "\n";
    }
    else {
        out << "    recognitionLanguage is not set\n";
    }

    if (value.referralProof.isSet()) {
        out << "    referralProof = "
            << value.referralProof.ref() << "\n";
    }
    else {
        out << "    referralProof is not set\n";
    }

    if (value.educationalDiscount.isSet()) {
        out << "    educationalDiscount = "
            << value.educationalDiscount.ref() << "\n";
    }
    else {
        out << "    educationalDiscount is not set\n";
    }

    if (value.businessAddress.isSet()) {
        out << "    businessAddress = "
            << value.businessAddress.ref() << "\n";
    }
    else {
        out << "    businessAddress is not set\n";
    }

    if (value.hideSponsorBilling.isSet()) {
        out << "    hideSponsorBilling = "
            << value.hideSponsorBilling.ref() << "\n";
    }
    else {
        out << "    hideSponsorBilling is not set\n";
    }

    if (value.useEmailAutoFiling.isSet()) {
        out << "    useEmailAutoFiling = "
            << value.useEmailAutoFiling.ref() << "\n";
    }
    else {
        out << "    useEmailAutoFiling is not set\n";
    }

    if (value.reminderEmailConfig.isSet()) {
        out << "    reminderEmailConfig = "
            << value.reminderEmailConfig.ref() << "\n";
    }
    else {
        out << "    reminderEmailConfig is not set\n";
    }

    if (value.emailAddressLastConfirmed.isSet()) {
        out << "    emailAddressLastConfirmed = "
            << value.emailAddressLastConfirmed.ref() << "\n";
    }
    else {
        out << "    emailAddressLastConfirmed is not set\n";
    }

    if (value.passwordUpdated.isSet()) {
        out << "    passwordUpdated = "
            << value.passwordUpdated.ref() << "\n";
    }
    else {
        out << "    passwordUpdated is not set\n";
    }

    if (value.salesforcePushEnabled.isSet()) {
        out << "    salesforcePushEnabled = "
            << value.salesforcePushEnabled.ref() << "\n";
    }
    else {
        out << "    salesforcePushEnabled is not set\n";
    }

    if (value.shouldLogClientEvent.isSet()) {
        out << "    shouldLogClientEvent = "
            << value.shouldLogClientEvent.ref() << "\n";
    }
    else {
        out << "    shouldLogClientEvent is not set\n";
    }

    if (value.optOutMachineLearning.isSet()) {
        out << "    optOutMachineLearning = "
            << value.optOutMachineLearning.ref() << "\n";
    }
    else {
        out << "    optOutMachineLearning is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UserAttributes & value)
{
    out << "UserAttributes: {\n";

    if (value.defaultLocationName.isSet()) {
        out << "    defaultLocationName = "
            << value.defaultLocationName.ref() << "\n";
    }
    else {
        out << "    defaultLocationName is not set\n";
    }

    if (value.defaultLatitude.isSet()) {
        out << "    defaultLatitude = "
            << value.defaultLatitude.ref() << "\n";
    }
    else {
        out << "    defaultLatitude is not set\n";
    }

    if (value.defaultLongitude.isSet()) {
        out << "    defaultLongitude = "
            << value.defaultLongitude.ref() << "\n";
    }
    else {
        out << "    defaultLongitude is not set\n";
    }

    if (value.preactivation.isSet()) {
        out << "    preactivation = "
            << value.preactivation.ref() << "\n";
    }
    else {
        out << "    preactivation is not set\n";
    }

    if (value.viewedPromotions.isSet()) {
        out << "    viewedPromotions = "
            << "QList<QString> {";
        for(const auto & v: value.viewedPromotions.ref()) {
            out << v;
        }
    }
    else {
        out << "    viewedPromotions is not set\n";
    }

    if (value.incomingEmailAddress.isSet()) {
        out << "    incomingEmailAddress = "
            << value.incomingEmailAddress.ref() << "\n";
    }
    else {
        out << "    incomingEmailAddress is not set\n";
    }

    if (value.recentMailedAddresses.isSet()) {
        out << "    recentMailedAddresses = "
            << "QList<QString> {";
        for(const auto & v: value.recentMailedAddresses.ref()) {
            out << v;
        }
    }
    else {
        out << "    recentMailedAddresses is not set\n";
    }

    if (value.comments.isSet()) {
        out << "    comments = "
            << value.comments.ref() << "\n";
    }
    else {
        out << "    comments is not set\n";
    }

    if (value.dateAgreedToTermsOfService.isSet()) {
        out << "    dateAgreedToTermsOfService = "
            << value.dateAgreedToTermsOfService.ref() << "\n";
    }
    else {
        out << "    dateAgreedToTermsOfService is not set\n";
    }

    if (value.maxReferrals.isSet()) {
        out << "    maxReferrals = "
            << value.maxReferrals.ref() << "\n";
    }
    else {
        out << "    maxReferrals is not set\n";
    }

    if (value.referralCount.isSet()) {
        out << "    referralCount = "
            << value.referralCount.ref() << "\n";
    }
    else {
        out << "    referralCount is not set\n";
    }

    if (value.refererCode.isSet()) {
        out << "    refererCode = "
            << value.refererCode.ref() << "\n";
    }
    else {
        out << "    refererCode is not set\n";
    }

    if (value.sentEmailDate.isSet()) {
        out << "    sentEmailDate = "
            << value.sentEmailDate.ref() << "\n";
    }
    else {
        out << "    sentEmailDate is not set\n";
    }

    if (value.sentEmailCount.isSet()) {
        out << "    sentEmailCount = "
            << value.sentEmailCount.ref() << "\n";
    }
    else {
        out << "    sentEmailCount is not set\n";
    }

    if (value.dailyEmailLimit.isSet()) {
        out << "    dailyEmailLimit = "
            << value.dailyEmailLimit.ref() << "\n";
    }
    else {
        out << "    dailyEmailLimit is not set\n";
    }

    if (value.emailOptOutDate.isSet()) {
        out << "    emailOptOutDate = "
            << value.emailOptOutDate.ref() << "\n";
    }
    else {
        out << "    emailOptOutDate is not set\n";
    }

    if (value.partnerEmailOptInDate.isSet()) {
        out << "    partnerEmailOptInDate = "
            << value.partnerEmailOptInDate.ref() << "\n";
    }
    else {
        out << "    partnerEmailOptInDate is not set\n";
    }

    if (value.preferredLanguage.isSet()) {
        out << "    preferredLanguage = "
            << value.preferredLanguage.ref() << "\n";
    }
    else {
        out << "    preferredLanguage is not set\n";
    }

    if (value.preferredCountry.isSet()) {
        out << "    preferredCountry = "
            << value.preferredCountry.ref() << "\n";
    }
    else {
        out << "    preferredCountry is not set\n";
    }

    if (value.clipFullPage.isSet()) {
        out << "    clipFullPage = "
            << value.clipFullPage.ref() << "\n";
    }
    else {
        out << "    clipFullPage is not set\n";
    }

    if (value.twitterUserName.isSet()) {
        out << "    twitterUserName = "
            << value.twitterUserName.ref() << "\n";
    }
    else {
        out << "    twitterUserName is not set\n";
    }

    if (value.twitterId.isSet()) {
        out << "    twitterId = "
            << value.twitterId.ref() << "\n";
    }
    else {
        out << "    twitterId is not set\n";
    }

    if (value.groupName.isSet()) {
        out << "    groupName = "
            << value.groupName.ref() << "\n";
    }
    else {
        out << "    groupName is not set\n";
    }

    if (value.recognitionLanguage.isSet()) {
        out << "    recognitionLanguage = "
            << value.recognitionLanguage.ref() << "\n";
    }
    else {
        out << "    recognitionLanguage is not set\n";
    }

    if (value.referralProof.isSet()) {
        out << "    referralProof = "
            << value.referralProof.ref() << "\n";
    }
    else {
        out << "    referralProof is not set\n";
    }

    if (value.educationalDiscount.isSet()) {
        out << "    educationalDiscount = "
            << value.educationalDiscount.ref() << "\n";
    }
    else {
        out << "    educationalDiscount is not set\n";
    }

    if (value.businessAddress.isSet()) {
        out << "    businessAddress = "
            << value.businessAddress.ref() << "\n";
    }
    else {
        out << "    businessAddress is not set\n";
    }

    if (value.hideSponsorBilling.isSet()) {
        out << "    hideSponsorBilling = "
            << value.hideSponsorBilling.ref() << "\n";
    }
    else {
        out << "    hideSponsorBilling is not set\n";
    }

    if (value.useEmailAutoFiling.isSet()) {
        out << "    useEmailAutoFiling = "
            << value.useEmailAutoFiling.ref() << "\n";
    }
    else {
        out << "    useEmailAutoFiling is not set\n";
    }

    if (value.reminderEmailConfig.isSet()) {
        out << "    reminderEmailConfig = "
            << value.reminderEmailConfig.ref() << "\n";
    }
    else {
        out << "    reminderEmailConfig is not set\n";
    }

    if (value.emailAddressLastConfirmed.isSet()) {
        out << "    emailAddressLastConfirmed = "
            << value.emailAddressLastConfirmed.ref() << "\n";
    }
    else {
        out << "    emailAddressLastConfirmed is not set\n";
    }

    if (value.passwordUpdated.isSet()) {
        out << "    passwordUpdated = "
            << value.passwordUpdated.ref() << "\n";
    }
    else {
        out << "    passwordUpdated is not set\n";
    }

    if (value.salesforcePushEnabled.isSet()) {
        out << "    salesforcePushEnabled = "
            << value.salesforcePushEnabled.ref() << "\n";
    }
    else {
        out << "    salesforcePushEnabled is not set\n";
    }

    if (value.shouldLogClientEvent.isSet()) {
        out << "    shouldLogClientEvent = "
            << value.shouldLogClientEvent.ref() << "\n";
    }
    else {
        out << "    shouldLogClientEvent is not set\n";
    }

    if (value.optOutMachineLearning.isSet()) {
        out << "    optOutMachineLearning = "
            << value.optOutMachineLearning.ref() << "\n";
    }
    else {
        out << "    optOutMachineLearning is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessUserAttributes(ThriftBinaryBufferWriter & w, const BusinessUserAttributes & s) {
    w.writeStructBegin(QStringLiteral("BusinessUserAttributes"));
    if (s.title.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if (s.location.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("location"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.location.ref());
        w.writeFieldEnd();
    }
    if (s.department.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("department"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.department.ref());
        w.writeFieldEnd();
    }
    if (s.mobilePhone.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("mobilePhone"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.mobilePhone.ref());
        w.writeFieldEnd();
    }
    if (s.linkedInProfileUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("linkedInProfileUrl"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.linkedInProfileUrl.ref());
        w.writeFieldEnd();
    }
    if (s.workPhone.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("workPhone"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.workPhone.ref());
        w.writeFieldEnd();
    }
    if (s.companyStartDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("companyStartDate"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.companyStartDate.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessUserAttributes(ThriftBinaryBufferReader & r, BusinessUserAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.location = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.department = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.mobilePhone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.linkedInProfileUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.workPhone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.companyStartDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessUserAttributes & value)
{
    out << "BusinessUserAttributes: {\n";

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.location.isSet()) {
        out << "    location = "
            << value.location.ref() << "\n";
    }
    else {
        out << "    location is not set\n";
    }

    if (value.department.isSet()) {
        out << "    department = "
            << value.department.ref() << "\n";
    }
    else {
        out << "    department is not set\n";
    }

    if (value.mobilePhone.isSet()) {
        out << "    mobilePhone = "
            << value.mobilePhone.ref() << "\n";
    }
    else {
        out << "    mobilePhone is not set\n";
    }

    if (value.linkedInProfileUrl.isSet()) {
        out << "    linkedInProfileUrl = "
            << value.linkedInProfileUrl.ref() << "\n";
    }
    else {
        out << "    linkedInProfileUrl is not set\n";
    }

    if (value.workPhone.isSet()) {
        out << "    workPhone = "
            << value.workPhone.ref() << "\n";
    }
    else {
        out << "    workPhone is not set\n";
    }

    if (value.companyStartDate.isSet()) {
        out << "    companyStartDate = "
            << value.companyStartDate.ref() << "\n";
    }
    else {
        out << "    companyStartDate is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessUserAttributes & value)
{
    out << "BusinessUserAttributes: {\n";

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.location.isSet()) {
        out << "    location = "
            << value.location.ref() << "\n";
    }
    else {
        out << "    location is not set\n";
    }

    if (value.department.isSet()) {
        out << "    department = "
            << value.department.ref() << "\n";
    }
    else {
        out << "    department is not set\n";
    }

    if (value.mobilePhone.isSet()) {
        out << "    mobilePhone = "
            << value.mobilePhone.ref() << "\n";
    }
    else {
        out << "    mobilePhone is not set\n";
    }

    if (value.linkedInProfileUrl.isSet()) {
        out << "    linkedInProfileUrl = "
            << value.linkedInProfileUrl.ref() << "\n";
    }
    else {
        out << "    linkedInProfileUrl is not set\n";
    }

    if (value.workPhone.isSet()) {
        out << "    workPhone = "
            << value.workPhone.ref() << "\n";
    }
    else {
        out << "    workPhone is not set\n";
    }

    if (value.companyStartDate.isSet()) {
        out << "    companyStartDate = "
            << value.companyStartDate.ref() << "\n";
    }
    else {
        out << "    companyStartDate is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeAccounting(ThriftBinaryBufferWriter & w, const Accounting & s) {
    w.writeStructBegin(QStringLiteral("Accounting"));
    if (s.uploadLimitEnd.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploadLimitEnd"),
            ThriftFieldType::T_I64,
            2);
        w.writeI64(s.uploadLimitEnd.ref());
        w.writeFieldEnd();
    }
    if (s.uploadLimitNextMonth.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploadLimitNextMonth"),
            ThriftFieldType::T_I64,
            3);
        w.writeI64(s.uploadLimitNextMonth.ref());
        w.writeFieldEnd();
    }
    if (s.premiumServiceStatus.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumServiceStatus"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(static_cast<qint32>(s.premiumServiceStatus.ref()));
        w.writeFieldEnd();
    }
    if (s.premiumOrderNumber.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumOrderNumber"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.premiumOrderNumber.ref());
        w.writeFieldEnd();
    }
    if (s.premiumCommerceService.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumCommerceService"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.premiumCommerceService.ref());
        w.writeFieldEnd();
    }
    if (s.premiumServiceStart.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumServiceStart"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.premiumServiceStart.ref());
        w.writeFieldEnd();
    }
    if (s.premiumServiceSKU.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumServiceSKU"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.premiumServiceSKU.ref());
        w.writeFieldEnd();
    }
    if (s.lastSuccessfulCharge.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastSuccessfulCharge"),
            ThriftFieldType::T_I64,
            9);
        w.writeI64(s.lastSuccessfulCharge.ref());
        w.writeFieldEnd();
    }
    if (s.lastFailedCharge.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastFailedCharge"),
            ThriftFieldType::T_I64,
            10);
        w.writeI64(s.lastFailedCharge.ref());
        w.writeFieldEnd();
    }
    if (s.lastFailedChargeReason.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastFailedChargeReason"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.lastFailedChargeReason.ref());
        w.writeFieldEnd();
    }
    if (s.nextPaymentDue.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("nextPaymentDue"),
            ThriftFieldType::T_I64,
            12);
        w.writeI64(s.nextPaymentDue.ref());
        w.writeFieldEnd();
    }
    if (s.premiumLockUntil.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumLockUntil"),
            ThriftFieldType::T_I64,
            13);
        w.writeI64(s.premiumLockUntil.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            14);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if (s.premiumSubscriptionNumber.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("premiumSubscriptionNumber"),
            ThriftFieldType::T_STRING,
            16);
        w.writeString(s.premiumSubscriptionNumber.ref());
        w.writeFieldEnd();
    }
    if (s.lastRequestedCharge.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastRequestedCharge"),
            ThriftFieldType::T_I64,
            17);
        w.writeI64(s.lastRequestedCharge.ref());
        w.writeFieldEnd();
    }
    if (s.currency.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("currency"),
            ThriftFieldType::T_STRING,
            18);
        w.writeString(s.currency.ref());
        w.writeFieldEnd();
    }
    if (s.unitPrice.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("unitPrice"),
            ThriftFieldType::T_I32,
            19);
        w.writeI32(s.unitPrice.ref());
        w.writeFieldEnd();
    }
    if (s.businessId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            20);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if (s.businessName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            21);
        w.writeString(s.businessName.ref());
        w.writeFieldEnd();
    }
    if (s.businessRole.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessRole"),
            ThriftFieldType::T_I32,
            22);
        w.writeI32(static_cast<qint32>(s.businessRole.ref()));
        w.writeFieldEnd();
    }
    if (s.unitDiscount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("unitDiscount"),
            ThriftFieldType::T_I32,
            23);
        w.writeI32(s.unitDiscount.ref());
        w.writeFieldEnd();
    }
    if (s.nextChargeDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("nextChargeDate"),
            ThriftFieldType::T_I64,
            24);
        w.writeI64(s.nextChargeDate.ref());
        w.writeFieldEnd();
    }
    if (s.availablePoints.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("availablePoints"),
            ThriftFieldType::T_I32,
            25);
        w.writeI32(s.availablePoints.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAccounting(ThriftBinaryBufferReader & r, Accounting & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimitEnd = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimitNextMonth = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                PremiumOrderStatus v;
                readEnumPremiumOrderStatus(r, v);
                s.premiumServiceStatus = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumOrderNumber = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumCommerceService = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.premiumServiceStart = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumServiceSKU = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastSuccessfulCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastFailedCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.lastFailedChargeReason = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.nextPaymentDue = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.premiumLockUntil = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumSubscriptionNumber = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastRequestedCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.currency = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.unitPrice = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(r, v);
                s.businessRole = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.unitDiscount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.nextChargeDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.availablePoints = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Accounting & value)
{
    out << "Accounting: {\n";

    if (value.uploadLimitEnd.isSet()) {
        out << "    uploadLimitEnd = "
            << value.uploadLimitEnd.ref() << "\n";
    }
    else {
        out << "    uploadLimitEnd is not set\n";
    }

    if (value.uploadLimitNextMonth.isSet()) {
        out << "    uploadLimitNextMonth = "
            << value.uploadLimitNextMonth.ref() << "\n";
    }
    else {
        out << "    uploadLimitNextMonth is not set\n";
    }

    if (value.premiumServiceStatus.isSet()) {
        out << "    premiumServiceStatus = "
            << value.premiumServiceStatus.ref() << "\n";
    }
    else {
        out << "    premiumServiceStatus is not set\n";
    }

    if (value.premiumOrderNumber.isSet()) {
        out << "    premiumOrderNumber = "
            << value.premiumOrderNumber.ref() << "\n";
    }
    else {
        out << "    premiumOrderNumber is not set\n";
    }

    if (value.premiumCommerceService.isSet()) {
        out << "    premiumCommerceService = "
            << value.premiumCommerceService.ref() << "\n";
    }
    else {
        out << "    premiumCommerceService is not set\n";
    }

    if (value.premiumServiceStart.isSet()) {
        out << "    premiumServiceStart = "
            << value.premiumServiceStart.ref() << "\n";
    }
    else {
        out << "    premiumServiceStart is not set\n";
    }

    if (value.premiumServiceSKU.isSet()) {
        out << "    premiumServiceSKU = "
            << value.premiumServiceSKU.ref() << "\n";
    }
    else {
        out << "    premiumServiceSKU is not set\n";
    }

    if (value.lastSuccessfulCharge.isSet()) {
        out << "    lastSuccessfulCharge = "
            << value.lastSuccessfulCharge.ref() << "\n";
    }
    else {
        out << "    lastSuccessfulCharge is not set\n";
    }

    if (value.lastFailedCharge.isSet()) {
        out << "    lastFailedCharge = "
            << value.lastFailedCharge.ref() << "\n";
    }
    else {
        out << "    lastFailedCharge is not set\n";
    }

    if (value.lastFailedChargeReason.isSet()) {
        out << "    lastFailedChargeReason = "
            << value.lastFailedChargeReason.ref() << "\n";
    }
    else {
        out << "    lastFailedChargeReason is not set\n";
    }

    if (value.nextPaymentDue.isSet()) {
        out << "    nextPaymentDue = "
            << value.nextPaymentDue.ref() << "\n";
    }
    else {
        out << "    nextPaymentDue is not set\n";
    }

    if (value.premiumLockUntil.isSet()) {
        out << "    premiumLockUntil = "
            << value.premiumLockUntil.ref() << "\n";
    }
    else {
        out << "    premiumLockUntil is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.premiumSubscriptionNumber.isSet()) {
        out << "    premiumSubscriptionNumber = "
            << value.premiumSubscriptionNumber.ref() << "\n";
    }
    else {
        out << "    premiumSubscriptionNumber is not set\n";
    }

    if (value.lastRequestedCharge.isSet()) {
        out << "    lastRequestedCharge = "
            << value.lastRequestedCharge.ref() << "\n";
    }
    else {
        out << "    lastRequestedCharge is not set\n";
    }

    if (value.currency.isSet()) {
        out << "    currency = "
            << value.currency.ref() << "\n";
    }
    else {
        out << "    currency is not set\n";
    }

    if (value.unitPrice.isSet()) {
        out << "    unitPrice = "
            << value.unitPrice.ref() << "\n";
    }
    else {
        out << "    unitPrice is not set\n";
    }

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.businessName.isSet()) {
        out << "    businessName = "
            << value.businessName.ref() << "\n";
    }
    else {
        out << "    businessName is not set\n";
    }

    if (value.businessRole.isSet()) {
        out << "    businessRole = "
            << value.businessRole.ref() << "\n";
    }
    else {
        out << "    businessRole is not set\n";
    }

    if (value.unitDiscount.isSet()) {
        out << "    unitDiscount = "
            << value.unitDiscount.ref() << "\n";
    }
    else {
        out << "    unitDiscount is not set\n";
    }

    if (value.nextChargeDate.isSet()) {
        out << "    nextChargeDate = "
            << value.nextChargeDate.ref() << "\n";
    }
    else {
        out << "    nextChargeDate is not set\n";
    }

    if (value.availablePoints.isSet()) {
        out << "    availablePoints = "
            << value.availablePoints.ref() << "\n";
    }
    else {
        out << "    availablePoints is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Accounting & value)
{
    out << "Accounting: {\n";

    if (value.uploadLimitEnd.isSet()) {
        out << "    uploadLimitEnd = "
            << value.uploadLimitEnd.ref() << "\n";
    }
    else {
        out << "    uploadLimitEnd is not set\n";
    }

    if (value.uploadLimitNextMonth.isSet()) {
        out << "    uploadLimitNextMonth = "
            << value.uploadLimitNextMonth.ref() << "\n";
    }
    else {
        out << "    uploadLimitNextMonth is not set\n";
    }

    if (value.premiumServiceStatus.isSet()) {
        out << "    premiumServiceStatus = "
            << value.premiumServiceStatus.ref() << "\n";
    }
    else {
        out << "    premiumServiceStatus is not set\n";
    }

    if (value.premiumOrderNumber.isSet()) {
        out << "    premiumOrderNumber = "
            << value.premiumOrderNumber.ref() << "\n";
    }
    else {
        out << "    premiumOrderNumber is not set\n";
    }

    if (value.premiumCommerceService.isSet()) {
        out << "    premiumCommerceService = "
            << value.premiumCommerceService.ref() << "\n";
    }
    else {
        out << "    premiumCommerceService is not set\n";
    }

    if (value.premiumServiceStart.isSet()) {
        out << "    premiumServiceStart = "
            << value.premiumServiceStart.ref() << "\n";
    }
    else {
        out << "    premiumServiceStart is not set\n";
    }

    if (value.premiumServiceSKU.isSet()) {
        out << "    premiumServiceSKU = "
            << value.premiumServiceSKU.ref() << "\n";
    }
    else {
        out << "    premiumServiceSKU is not set\n";
    }

    if (value.lastSuccessfulCharge.isSet()) {
        out << "    lastSuccessfulCharge = "
            << value.lastSuccessfulCharge.ref() << "\n";
    }
    else {
        out << "    lastSuccessfulCharge is not set\n";
    }

    if (value.lastFailedCharge.isSet()) {
        out << "    lastFailedCharge = "
            << value.lastFailedCharge.ref() << "\n";
    }
    else {
        out << "    lastFailedCharge is not set\n";
    }

    if (value.lastFailedChargeReason.isSet()) {
        out << "    lastFailedChargeReason = "
            << value.lastFailedChargeReason.ref() << "\n";
    }
    else {
        out << "    lastFailedChargeReason is not set\n";
    }

    if (value.nextPaymentDue.isSet()) {
        out << "    nextPaymentDue = "
            << value.nextPaymentDue.ref() << "\n";
    }
    else {
        out << "    nextPaymentDue is not set\n";
    }

    if (value.premiumLockUntil.isSet()) {
        out << "    premiumLockUntil = "
            << value.premiumLockUntil.ref() << "\n";
    }
    else {
        out << "    premiumLockUntil is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.premiumSubscriptionNumber.isSet()) {
        out << "    premiumSubscriptionNumber = "
            << value.premiumSubscriptionNumber.ref() << "\n";
    }
    else {
        out << "    premiumSubscriptionNumber is not set\n";
    }

    if (value.lastRequestedCharge.isSet()) {
        out << "    lastRequestedCharge = "
            << value.lastRequestedCharge.ref() << "\n";
    }
    else {
        out << "    lastRequestedCharge is not set\n";
    }

    if (value.currency.isSet()) {
        out << "    currency = "
            << value.currency.ref() << "\n";
    }
    else {
        out << "    currency is not set\n";
    }

    if (value.unitPrice.isSet()) {
        out << "    unitPrice = "
            << value.unitPrice.ref() << "\n";
    }
    else {
        out << "    unitPrice is not set\n";
    }

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.businessName.isSet()) {
        out << "    businessName = "
            << value.businessName.ref() << "\n";
    }
    else {
        out << "    businessName is not set\n";
    }

    if (value.businessRole.isSet()) {
        out << "    businessRole = "
            << value.businessRole.ref() << "\n";
    }
    else {
        out << "    businessRole is not set\n";
    }

    if (value.unitDiscount.isSet()) {
        out << "    unitDiscount = "
            << value.unitDiscount.ref() << "\n";
    }
    else {
        out << "    unitDiscount is not set\n";
    }

    if (value.nextChargeDate.isSet()) {
        out << "    nextChargeDate = "
            << value.nextChargeDate.ref() << "\n";
    }
    else {
        out << "    nextChargeDate is not set\n";
    }

    if (value.availablePoints.isSet()) {
        out << "    availablePoints = "
            << value.availablePoints.ref() << "\n";
    }
    else {
        out << "    availablePoints is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessUserInfo(ThriftBinaryBufferWriter & w, const BusinessUserInfo & s) {
    w.writeStructBegin(QStringLiteral("BusinessUserInfo"));
    if (s.businessId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if (s.businessName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.businessName.ref());
        w.writeFieldEnd();
    }
    if (s.role.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if (s.email.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessUserInfo(ThriftBinaryBufferReader & r, BusinessUserInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessUserInfo & value)
{
    out << "BusinessUserInfo: {\n";

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.businessName.isSet()) {
        out << "    businessName = "
            << value.businessName.ref() << "\n";
    }
    else {
        out << "    businessName is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessUserInfo & value)
{
    out << "BusinessUserInfo: {\n";

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.businessName.isSet()) {
        out << "    businessName = "
            << value.businessName.ref() << "\n";
    }
    else {
        out << "    businessName is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeAccountLimits(ThriftBinaryBufferWriter & w, const AccountLimits & s) {
    w.writeStructBegin(QStringLiteral("AccountLimits"));
    if (s.userMailLimitDaily.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userMailLimitDaily"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.userMailLimitDaily.ref());
        w.writeFieldEnd();
    }
    if (s.noteSizeMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            2);
        w.writeI64(s.noteSizeMax.ref());
        w.writeFieldEnd();
    }
    if (s.resourceSizeMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);
        w.writeI64(s.resourceSizeMax.ref());
        w.writeFieldEnd();
    }
    if (s.userLinkedNotebookMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userLinkedNotebookMax"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(s.userLinkedNotebookMax.ref());
        w.writeFieldEnd();
    }
    if (s.uploadLimit.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.uploadLimit.ref());
        w.writeFieldEnd();
    }
    if (s.userNoteCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userNoteCountMax"),
            ThriftFieldType::T_I32,
            6);
        w.writeI32(s.userNoteCountMax.ref());
        w.writeFieldEnd();
    }
    if (s.userNotebookCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userNotebookCountMax"),
            ThriftFieldType::T_I32,
            7);
        w.writeI32(s.userNotebookCountMax.ref());
        w.writeFieldEnd();
    }
    if (s.userTagCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userTagCountMax"),
            ThriftFieldType::T_I32,
            8);
        w.writeI32(s.userTagCountMax.ref());
        w.writeFieldEnd();
    }
    if (s.noteTagCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteTagCountMax"),
            ThriftFieldType::T_I32,
            9);
        w.writeI32(s.noteTagCountMax.ref());
        w.writeFieldEnd();
    }
    if (s.userSavedSearchesMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userSavedSearchesMax"),
            ThriftFieldType::T_I32,
            10);
        w.writeI32(s.userSavedSearchesMax.ref());
        w.writeFieldEnd();
    }
    if (s.noteResourceCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            11);
        w.writeI32(s.noteResourceCountMax.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAccountLimits(ThriftBinaryBufferReader & r, AccountLimits & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userMailLimitDaily = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.noteSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.resourceSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userLinkedNotebookMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userNoteCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userNotebookCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userTagCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteTagCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userSavedSearchesMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteResourceCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const AccountLimits & value)
{
    out << "AccountLimits: {\n";

    if (value.userMailLimitDaily.isSet()) {
        out << "    userMailLimitDaily = "
            << value.userMailLimitDaily.ref() << "\n";
    }
    else {
        out << "    userMailLimitDaily is not set\n";
    }

    if (value.noteSizeMax.isSet()) {
        out << "    noteSizeMax = "
            << value.noteSizeMax.ref() << "\n";
    }
    else {
        out << "    noteSizeMax is not set\n";
    }

    if (value.resourceSizeMax.isSet()) {
        out << "    resourceSizeMax = "
            << value.resourceSizeMax.ref() << "\n";
    }
    else {
        out << "    resourceSizeMax is not set\n";
    }

    if (value.userLinkedNotebookMax.isSet()) {
        out << "    userLinkedNotebookMax = "
            << value.userLinkedNotebookMax.ref() << "\n";
    }
    else {
        out << "    userLinkedNotebookMax is not set\n";
    }

    if (value.uploadLimit.isSet()) {
        out << "    uploadLimit = "
            << value.uploadLimit.ref() << "\n";
    }
    else {
        out << "    uploadLimit is not set\n";
    }

    if (value.userNoteCountMax.isSet()) {
        out << "    userNoteCountMax = "
            << value.userNoteCountMax.ref() << "\n";
    }
    else {
        out << "    userNoteCountMax is not set\n";
    }

    if (value.userNotebookCountMax.isSet()) {
        out << "    userNotebookCountMax = "
            << value.userNotebookCountMax.ref() << "\n";
    }
    else {
        out << "    userNotebookCountMax is not set\n";
    }

    if (value.userTagCountMax.isSet()) {
        out << "    userTagCountMax = "
            << value.userTagCountMax.ref() << "\n";
    }
    else {
        out << "    userTagCountMax is not set\n";
    }

    if (value.noteTagCountMax.isSet()) {
        out << "    noteTagCountMax = "
            << value.noteTagCountMax.ref() << "\n";
    }
    else {
        out << "    noteTagCountMax is not set\n";
    }

    if (value.userSavedSearchesMax.isSet()) {
        out << "    userSavedSearchesMax = "
            << value.userSavedSearchesMax.ref() << "\n";
    }
    else {
        out << "    userSavedSearchesMax is not set\n";
    }

    if (value.noteResourceCountMax.isSet()) {
        out << "    noteResourceCountMax = "
            << value.noteResourceCountMax.ref() << "\n";
    }
    else {
        out << "    noteResourceCountMax is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const AccountLimits & value)
{
    out << "AccountLimits: {\n";

    if (value.userMailLimitDaily.isSet()) {
        out << "    userMailLimitDaily = "
            << value.userMailLimitDaily.ref() << "\n";
    }
    else {
        out << "    userMailLimitDaily is not set\n";
    }

    if (value.noteSizeMax.isSet()) {
        out << "    noteSizeMax = "
            << value.noteSizeMax.ref() << "\n";
    }
    else {
        out << "    noteSizeMax is not set\n";
    }

    if (value.resourceSizeMax.isSet()) {
        out << "    resourceSizeMax = "
            << value.resourceSizeMax.ref() << "\n";
    }
    else {
        out << "    resourceSizeMax is not set\n";
    }

    if (value.userLinkedNotebookMax.isSet()) {
        out << "    userLinkedNotebookMax = "
            << value.userLinkedNotebookMax.ref() << "\n";
    }
    else {
        out << "    userLinkedNotebookMax is not set\n";
    }

    if (value.uploadLimit.isSet()) {
        out << "    uploadLimit = "
            << value.uploadLimit.ref() << "\n";
    }
    else {
        out << "    uploadLimit is not set\n";
    }

    if (value.userNoteCountMax.isSet()) {
        out << "    userNoteCountMax = "
            << value.userNoteCountMax.ref() << "\n";
    }
    else {
        out << "    userNoteCountMax is not set\n";
    }

    if (value.userNotebookCountMax.isSet()) {
        out << "    userNotebookCountMax = "
            << value.userNotebookCountMax.ref() << "\n";
    }
    else {
        out << "    userNotebookCountMax is not set\n";
    }

    if (value.userTagCountMax.isSet()) {
        out << "    userTagCountMax = "
            << value.userTagCountMax.ref() << "\n";
    }
    else {
        out << "    userTagCountMax is not set\n";
    }

    if (value.noteTagCountMax.isSet()) {
        out << "    noteTagCountMax = "
            << value.noteTagCountMax.ref() << "\n";
    }
    else {
        out << "    noteTagCountMax is not set\n";
    }

    if (value.userSavedSearchesMax.isSet()) {
        out << "    userSavedSearchesMax = "
            << value.userSavedSearchesMax.ref() << "\n";
    }
    else {
        out << "    userSavedSearchesMax is not set\n";
    }

    if (value.noteResourceCountMax.isSet()) {
        out << "    noteResourceCountMax = "
            << value.noteResourceCountMax.ref() << "\n";
    }
    else {
        out << "    noteResourceCountMax is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUser(ThriftBinaryBufferWriter & w, const User & s) {
    w.writeStructBegin(QStringLiteral("User"));
    if (s.id.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.id.ref());
        w.writeFieldEnd();
    }
    if (s.username.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if (s.email.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.timezone.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("timezone"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.timezone.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            7);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.serviceLevel.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            21);
        w.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        w.writeFieldEnd();
    }
    if (s.created.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            9);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            10);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if (s.deleted.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            11);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if (s.active.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            13);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if (s.shardId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            14);
        w.writeString(s.shardId.ref());
        w.writeFieldEnd();
    }
    if (s.attributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            15);
        writeUserAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if (s.accounting.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("accounting"),
            ThriftFieldType::T_STRUCT,
            16);
        writeAccounting(w, s.accounting.ref());
        w.writeFieldEnd();
    }
    if (s.businessUserInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessUserInfo"),
            ThriftFieldType::T_STRUCT,
            18);
        writeBusinessUserInfo(w, s.businessUserInfo.ref());
        w.writeFieldEnd();
    }
    if (s.photoUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            19);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if (s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            20);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.accountLimits.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("accountLimits"),
            ThriftFieldType::T_STRUCT,
            22);
        writeAccountLimits(w, s.accountLimits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUser(ThriftBinaryBufferReader & r, User & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.timezone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                PrivilegeLevel v;
                readEnumPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(r, v);
                s.serviceLevel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shardId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserAttributes v;
                readUserAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Accounting v;
                readAccounting(r, v);
                s.accounting = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserInfo v;
                readBusinessUserInfo(r, v);
                s.businessUserInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                AccountLimits v;
                readAccountLimits(r, v);
                s.accountLimits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const User & value)
{
    out << "User: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.timezone.isSet()) {
        out << "    timezone = "
            << value.timezone.ref() << "\n";
    }
    else {
        out << "    timezone is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.serviceLevel.isSet()) {
        out << "    serviceLevel = "
            << value.serviceLevel.ref() << "\n";
    }
    else {
        out << "    serviceLevel is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.shardId.isSet()) {
        out << "    shardId = "
            << value.shardId.ref() << "\n";
    }
    else {
        out << "    shardId is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.accounting.isSet()) {
        out << "    accounting = "
            << value.accounting.ref() << "\n";
    }
    else {
        out << "    accounting is not set\n";
    }

    if (value.businessUserInfo.isSet()) {
        out << "    businessUserInfo = "
            << value.businessUserInfo.ref() << "\n";
    }
    else {
        out << "    businessUserInfo is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.accountLimits.isSet()) {
        out << "    accountLimits = "
            << value.accountLimits.ref() << "\n";
    }
    else {
        out << "    accountLimits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const User & value)
{
    out << "User: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.timezone.isSet()) {
        out << "    timezone = "
            << value.timezone.ref() << "\n";
    }
    else {
        out << "    timezone is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.serviceLevel.isSet()) {
        out << "    serviceLevel = "
            << value.serviceLevel.ref() << "\n";
    }
    else {
        out << "    serviceLevel is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.shardId.isSet()) {
        out << "    shardId = "
            << value.shardId.ref() << "\n";
    }
    else {
        out << "    shardId is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.accounting.isSet()) {
        out << "    accounting = "
            << value.accounting.ref() << "\n";
    }
    else {
        out << "    accounting is not set\n";
    }

    if (value.businessUserInfo.isSet()) {
        out << "    businessUserInfo = "
            << value.businessUserInfo.ref() << "\n";
    }
    else {
        out << "    businessUserInfo is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.accountLimits.isSet()) {
        out << "    accountLimits = "
            << value.accountLimits.ref() << "\n";
    }
    else {
        out << "    accountLimits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeContact(ThriftBinaryBufferWriter & w, const Contact & s) {
    w.writeStructBegin(QStringLiteral("Contact"));
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.id.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.id.ref());
        w.writeFieldEnd();
    }
    if (s.type.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.type.ref()));
        w.writeFieldEnd();
    }
    if (s.photoUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if (s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.messagingPermit.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("messagingPermit"),
            ThriftFieldType::T_STRING,
            6);
        w.writeBinary(s.messagingPermit.ref());
        w.writeFieldEnd();
    }
    if (s.messagingPermitExpires.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("messagingPermitExpires"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.messagingPermitExpires.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readContact(ThriftBinaryBufferReader & r, Contact & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ContactType v;
                readEnumContactType(r, v);
                s.type = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.messagingPermit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.messagingPermitExpires = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Contact & value)
{
    out << "Contact: {\n";

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.type.isSet()) {
        out << "    type = "
            << value.type.ref() << "\n";
    }
    else {
        out << "    type is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.messagingPermit.isSet()) {
        out << "    messagingPermit = "
            << value.messagingPermit.ref() << "\n";
    }
    else {
        out << "    messagingPermit is not set\n";
    }

    if (value.messagingPermitExpires.isSet()) {
        out << "    messagingPermitExpires = "
            << value.messagingPermitExpires.ref() << "\n";
    }
    else {
        out << "    messagingPermitExpires is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Contact & value)
{
    out << "Contact: {\n";

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.type.isSet()) {
        out << "    type = "
            << value.type.ref() << "\n";
    }
    else {
        out << "    type is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.messagingPermit.isSet()) {
        out << "    messagingPermit = "
            << value.messagingPermit.ref() << "\n";
    }
    else {
        out << "    messagingPermit is not set\n";
    }

    if (value.messagingPermitExpires.isSet()) {
        out << "    messagingPermitExpires = "
            << value.messagingPermitExpires.ref() << "\n";
    }
    else {
        out << "    messagingPermitExpires is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeIdentity(ThriftBinaryBufferWriter & w, const Identity & s) {
    w.writeStructBegin(QStringLiteral("Identity"));
    w.writeFieldBegin(
        QStringLiteral("id"),
        ThriftFieldType::T_I64,
        1);
    w.writeI64(s.id);
    w.writeFieldEnd();
    if (s.contact.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            2);
        writeContact(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if (s.userId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(s.userId.ref());
        w.writeFieldEnd();
    }
    if (s.deactivated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("deactivated"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.deactivated.ref());
        w.writeFieldEnd();
    }
    if (s.sameBusiness.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sameBusiness"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.sameBusiness.ref());
        w.writeFieldEnd();
    }
    if (s.blocked.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("blocked"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.blocked.ref());
        w.writeFieldEnd();
    }
    if (s.userConnected.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userConnected"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.userConnected.ref());
        w.writeFieldEnd();
    }
    if (s.eventId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("eventId"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.eventId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readIdentity(ThriftBinaryBufferReader & r, Identity & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool id_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                id_isset = true;
                IdentityID v;
                r.readI64(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.deactivated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.sameBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.blocked = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.userConnected = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                r.readI64(v);
                s.eventId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!id_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Identity.id has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Identity & value)
{
    out << "Identity: {\n";
    out << "    id = "
        << "IdentityID" << "\n";

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.userId.isSet()) {
        out << "    userId = "
            << value.userId.ref() << "\n";
    }
    else {
        out << "    userId is not set\n";
    }

    if (value.deactivated.isSet()) {
        out << "    deactivated = "
            << value.deactivated.ref() << "\n";
    }
    else {
        out << "    deactivated is not set\n";
    }

    if (value.sameBusiness.isSet()) {
        out << "    sameBusiness = "
            << value.sameBusiness.ref() << "\n";
    }
    else {
        out << "    sameBusiness is not set\n";
    }

    if (value.blocked.isSet()) {
        out << "    blocked = "
            << value.blocked.ref() << "\n";
    }
    else {
        out << "    blocked is not set\n";
    }

    if (value.userConnected.isSet()) {
        out << "    userConnected = "
            << value.userConnected.ref() << "\n";
    }
    else {
        out << "    userConnected is not set\n";
    }

    if (value.eventId.isSet()) {
        out << "    eventId = "
            << value.eventId.ref() << "\n";
    }
    else {
        out << "    eventId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Identity & value)
{
    out << "Identity: {\n";
    out << "    id = "
        << "IdentityID" << "\n";

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.userId.isSet()) {
        out << "    userId = "
            << value.userId.ref() << "\n";
    }
    else {
        out << "    userId is not set\n";
    }

    if (value.deactivated.isSet()) {
        out << "    deactivated = "
            << value.deactivated.ref() << "\n";
    }
    else {
        out << "    deactivated is not set\n";
    }

    if (value.sameBusiness.isSet()) {
        out << "    sameBusiness = "
            << value.sameBusiness.ref() << "\n";
    }
    else {
        out << "    sameBusiness is not set\n";
    }

    if (value.blocked.isSet()) {
        out << "    blocked = "
            << value.blocked.ref() << "\n";
    }
    else {
        out << "    blocked is not set\n";
    }

    if (value.userConnected.isSet()) {
        out << "    userConnected = "
            << value.userConnected.ref() << "\n";
    }
    else {
        out << "    userConnected is not set\n";
    }

    if (value.eventId.isSet()) {
        out << "    eventId = "
            << value.eventId.ref() << "\n";
    }
    else {
        out << "    eventId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeTag(ThriftBinaryBufferWriter & w, const Tag & s) {
    w.writeStructBegin(QStringLiteral("Tag"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.parentGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("parentGuid"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.parentGuid.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readTag(ThriftBinaryBufferReader & r, Tag & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.parentGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Tag & value)
{
    out << "Tag: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.parentGuid.isSet()) {
        out << "    parentGuid = "
            << value.parentGuid.ref() << "\n";
    }
    else {
        out << "    parentGuid is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Tag & value)
{
    out << "Tag: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.parentGuid.isSet()) {
        out << "    parentGuid = "
            << value.parentGuid.ref() << "\n";
    }
    else {
        out << "    parentGuid is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeLazyMap(ThriftBinaryBufferWriter & w, const LazyMap & s) {
    w.writeStructBegin(QStringLiteral("LazyMap"));
    if (s.keysOnly.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("keysOnly"),
            ThriftFieldType::T_SET,
            1);
        w.writeSetBegin(ThriftFieldType::T_STRING, s.keysOnly.ref().count());
        for(const auto & value: qAsConst(s.keysOnly.ref())) {
            w.writeString(value);
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    if (s.fullMap.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("fullMap"),
            ThriftFieldType::T_MAP,
            2);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.fullMap.ref().size());
        for(const auto & it: toRange(s.fullMap.ref())) {
            w.writeString(it.key());
            w.writeString(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readLazyMap(ThriftBinaryBufferReader & r, LazyMap & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (LazyMap.keysOnly)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.keysOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (LazyMap.fullMap)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (LazyMap.fullMap)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    r.readString(key);
                    QString value;
                    r.readString(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.fullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const LazyMap & value)
{
    out << "LazyMap: {\n";

    if (value.keysOnly.isSet()) {
        out << "    keysOnly = "
            << "QSet<QString> {";
        for(const auto & v: value.keysOnly.ref()) {
            out << v;
        }
    }
    else {
        out << "    keysOnly is not set\n";
    }

    if (value.fullMap.isSet()) {
        out << "    fullMap = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(value.fullMap.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    fullMap is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const LazyMap & value)
{
    out << "LazyMap: {\n";

    if (value.keysOnly.isSet()) {
        out << "    keysOnly = "
            << "QSet<QString> {";
        for(const auto & v: value.keysOnly.ref()) {
            out << v;
        }
    }
    else {
        out << "    keysOnly is not set\n";
    }

    if (value.fullMap.isSet()) {
        out << "    fullMap = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(value.fullMap.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    fullMap is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeResourceAttributes(ThriftBinaryBufferWriter & w, const ResourceAttributes & s) {
    w.writeStructBegin(QStringLiteral("ResourceAttributes"));
    if (s.sourceURL.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.sourceURL.ref());
        w.writeFieldEnd();
    }
    if (s.timestamp.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("timestamp"),
            ThriftFieldType::T_I64,
            2);
        w.writeI64(s.timestamp.ref());
        w.writeFieldEnd();
    }
    if (s.latitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            3);
        w.writeDouble(s.latitude.ref());
        w.writeFieldEnd();
    }
    if (s.longitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            4);
        w.writeDouble(s.longitude.ref());
        w.writeFieldEnd();
    }
    if (s.altitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            5);
        w.writeDouble(s.altitude.ref());
        w.writeFieldEnd();
    }
    if (s.cameraMake.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("cameraMake"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.cameraMake.ref());
        w.writeFieldEnd();
    }
    if (s.cameraModel.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("cameraModel"),
            ThriftFieldType::T_STRING,
            7);
        w.writeString(s.cameraModel.ref());
        w.writeFieldEnd();
    }
    if (s.clientWillIndex.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("clientWillIndex"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.clientWillIndex.ref());
        w.writeFieldEnd();
    }
    if (s.recoType.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recoType"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.recoType.ref());
        w.writeFieldEnd();
    }
    if (s.fileName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("fileName"),
            ThriftFieldType::T_STRING,
            10);
        w.writeString(s.fileName.ref());
        w.writeFieldEnd();
    }
    if (s.attachment.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attachment"),
            ThriftFieldType::T_BOOL,
            11);
        w.writeBool(s.attachment.ref());
        w.writeFieldEnd();
    }
    if (s.applicationData.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            12);
        writeLazyMap(w, s.applicationData.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readResourceAttributes(ThriftBinaryBufferReader & r, ResourceAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceURL = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.timestamp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.latitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.longitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.altitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cameraMake = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cameraModel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.clientWillIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recoType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.fileName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.attachment = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(r, v);
                s.applicationData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ResourceAttributes & value)
{
    out << "ResourceAttributes: {\n";

    if (value.sourceURL.isSet()) {
        out << "    sourceURL = "
            << value.sourceURL.ref() << "\n";
    }
    else {
        out << "    sourceURL is not set\n";
    }

    if (value.timestamp.isSet()) {
        out << "    timestamp = "
            << value.timestamp.ref() << "\n";
    }
    else {
        out << "    timestamp is not set\n";
    }

    if (value.latitude.isSet()) {
        out << "    latitude = "
            << value.latitude.ref() << "\n";
    }
    else {
        out << "    latitude is not set\n";
    }

    if (value.longitude.isSet()) {
        out << "    longitude = "
            << value.longitude.ref() << "\n";
    }
    else {
        out << "    longitude is not set\n";
    }

    if (value.altitude.isSet()) {
        out << "    altitude = "
            << value.altitude.ref() << "\n";
    }
    else {
        out << "    altitude is not set\n";
    }

    if (value.cameraMake.isSet()) {
        out << "    cameraMake = "
            << value.cameraMake.ref() << "\n";
    }
    else {
        out << "    cameraMake is not set\n";
    }

    if (value.cameraModel.isSet()) {
        out << "    cameraModel = "
            << value.cameraModel.ref() << "\n";
    }
    else {
        out << "    cameraModel is not set\n";
    }

    if (value.clientWillIndex.isSet()) {
        out << "    clientWillIndex = "
            << value.clientWillIndex.ref() << "\n";
    }
    else {
        out << "    clientWillIndex is not set\n";
    }

    if (value.recoType.isSet()) {
        out << "    recoType = "
            << value.recoType.ref() << "\n";
    }
    else {
        out << "    recoType is not set\n";
    }

    if (value.fileName.isSet()) {
        out << "    fileName = "
            << value.fileName.ref() << "\n";
    }
    else {
        out << "    fileName is not set\n";
    }

    if (value.attachment.isSet()) {
        out << "    attachment = "
            << value.attachment.ref() << "\n";
    }
    else {
        out << "    attachment is not set\n";
    }

    if (value.applicationData.isSet()) {
        out << "    applicationData = "
            << value.applicationData.ref() << "\n";
    }
    else {
        out << "    applicationData is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ResourceAttributes & value)
{
    out << "ResourceAttributes: {\n";

    if (value.sourceURL.isSet()) {
        out << "    sourceURL = "
            << value.sourceURL.ref() << "\n";
    }
    else {
        out << "    sourceURL is not set\n";
    }

    if (value.timestamp.isSet()) {
        out << "    timestamp = "
            << value.timestamp.ref() << "\n";
    }
    else {
        out << "    timestamp is not set\n";
    }

    if (value.latitude.isSet()) {
        out << "    latitude = "
            << value.latitude.ref() << "\n";
    }
    else {
        out << "    latitude is not set\n";
    }

    if (value.longitude.isSet()) {
        out << "    longitude = "
            << value.longitude.ref() << "\n";
    }
    else {
        out << "    longitude is not set\n";
    }

    if (value.altitude.isSet()) {
        out << "    altitude = "
            << value.altitude.ref() << "\n";
    }
    else {
        out << "    altitude is not set\n";
    }

    if (value.cameraMake.isSet()) {
        out << "    cameraMake = "
            << value.cameraMake.ref() << "\n";
    }
    else {
        out << "    cameraMake is not set\n";
    }

    if (value.cameraModel.isSet()) {
        out << "    cameraModel = "
            << value.cameraModel.ref() << "\n";
    }
    else {
        out << "    cameraModel is not set\n";
    }

    if (value.clientWillIndex.isSet()) {
        out << "    clientWillIndex = "
            << value.clientWillIndex.ref() << "\n";
    }
    else {
        out << "    clientWillIndex is not set\n";
    }

    if (value.recoType.isSet()) {
        out << "    recoType = "
            << value.recoType.ref() << "\n";
    }
    else {
        out << "    recoType is not set\n";
    }

    if (value.fileName.isSet()) {
        out << "    fileName = "
            << value.fileName.ref() << "\n";
    }
    else {
        out << "    fileName is not set\n";
    }

    if (value.attachment.isSet()) {
        out << "    attachment = "
            << value.attachment.ref() << "\n";
    }
    else {
        out << "    attachment is not set\n";
    }

    if (value.applicationData.isSet()) {
        out << "    applicationData = "
            << value.applicationData.ref() << "\n";
    }
    else {
        out << "    applicationData is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeResource(ThriftBinaryBufferWriter & w, const Resource & s) {
    w.writeStructBegin(QStringLiteral("Resource"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.noteGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if (s.data.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("data"),
            ThriftFieldType::T_STRUCT,
            3);
        writeData(w, s.data.ref());
        w.writeFieldEnd();
    }
    if (s.mime.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("mime"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.mime.ref());
        w.writeFieldEnd();
    }
    if (s.width.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I16,
            5);
        w.writeI16(s.width.ref());
        w.writeFieldEnd();
    }
    if (s.height.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I16,
            6);
        w.writeI16(s.height.ref());
        w.writeFieldEnd();
    }
    if (s.duration.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("duration"),
            ThriftFieldType::T_I16,
            7);
        w.writeI16(s.duration.ref());
        w.writeFieldEnd();
    }
    if (s.active.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if (s.recognition.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recognition"),
            ThriftFieldType::T_STRUCT,
            9);
        writeData(w, s.recognition.ref());
        w.writeFieldEnd();
    }
    if (s.attributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            11);
        writeResourceAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            12);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.alternateData.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("alternateData"),
            ThriftFieldType::T_STRUCT,
            13);
        writeData(w, s.alternateData.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readResource(ThriftBinaryBufferReader & r, Resource & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.data = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.mime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.width = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.height = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.duration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.recognition = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ResourceAttributes v;
                readResourceAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.alternateData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Resource & value)
{
    out << "Resource: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.data.isSet()) {
        out << "    data = "
            << value.data.ref() << "\n";
    }
    else {
        out << "    data is not set\n";
    }

    if (value.mime.isSet()) {
        out << "    mime = "
            << value.mime.ref() << "\n";
    }
    else {
        out << "    mime is not set\n";
    }

    if (value.width.isSet()) {
        out << "    width = "
            << value.width.ref() << "\n";
    }
    else {
        out << "    width is not set\n";
    }

    if (value.height.isSet()) {
        out << "    height = "
            << value.height.ref() << "\n";
    }
    else {
        out << "    height is not set\n";
    }

    if (value.duration.isSet()) {
        out << "    duration = "
            << value.duration.ref() << "\n";
    }
    else {
        out << "    duration is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.recognition.isSet()) {
        out << "    recognition = "
            << value.recognition.ref() << "\n";
    }
    else {
        out << "    recognition is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.alternateData.isSet()) {
        out << "    alternateData = "
            << value.alternateData.ref() << "\n";
    }
    else {
        out << "    alternateData is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Resource & value)
{
    out << "Resource: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.noteGuid.isSet()) {
        out << "    noteGuid = "
            << value.noteGuid.ref() << "\n";
    }
    else {
        out << "    noteGuid is not set\n";
    }

    if (value.data.isSet()) {
        out << "    data = "
            << value.data.ref() << "\n";
    }
    else {
        out << "    data is not set\n";
    }

    if (value.mime.isSet()) {
        out << "    mime = "
            << value.mime.ref() << "\n";
    }
    else {
        out << "    mime is not set\n";
    }

    if (value.width.isSet()) {
        out << "    width = "
            << value.width.ref() << "\n";
    }
    else {
        out << "    width is not set\n";
    }

    if (value.height.isSet()) {
        out << "    height = "
            << value.height.ref() << "\n";
    }
    else {
        out << "    height is not set\n";
    }

    if (value.duration.isSet()) {
        out << "    duration = "
            << value.duration.ref() << "\n";
    }
    else {
        out << "    duration is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.recognition.isSet()) {
        out << "    recognition = "
            << value.recognition.ref() << "\n";
    }
    else {
        out << "    recognition is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.alternateData.isSet()) {
        out << "    alternateData = "
            << value.alternateData.ref() << "\n";
    }
    else {
        out << "    alternateData is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteAttributes(ThriftBinaryBufferWriter & w, const NoteAttributes & s) {
    w.writeStructBegin(QStringLiteral("NoteAttributes"));
    if (s.subjectDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("subjectDate"),
            ThriftFieldType::T_I64,
            1);
        w.writeI64(s.subjectDate.ref());
        w.writeFieldEnd();
    }
    if (s.latitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            10);
        w.writeDouble(s.latitude.ref());
        w.writeFieldEnd();
    }
    if (s.longitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            11);
        w.writeDouble(s.longitude.ref());
        w.writeFieldEnd();
    }
    if (s.altitude.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            12);
        w.writeDouble(s.altitude.ref());
        w.writeFieldEnd();
    }
    if (s.author.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("author"),
            ThriftFieldType::T_STRING,
            13);
        w.writeString(s.author.ref());
        w.writeFieldEnd();
    }
    if (s.source.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("source"),
            ThriftFieldType::T_STRING,
            14);
        w.writeString(s.source.ref());
        w.writeFieldEnd();
    }
    if (s.sourceURL.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            15);
        w.writeString(s.sourceURL.ref());
        w.writeFieldEnd();
    }
    if (s.sourceApplication.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceApplication"),
            ThriftFieldType::T_STRING,
            16);
        w.writeString(s.sourceApplication.ref());
        w.writeFieldEnd();
    }
    if (s.shareDate.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("shareDate"),
            ThriftFieldType::T_I64,
            17);
        w.writeI64(s.shareDate.ref());
        w.writeFieldEnd();
    }
    if (s.reminderOrder.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderOrder"),
            ThriftFieldType::T_I64,
            18);
        w.writeI64(s.reminderOrder.ref());
        w.writeFieldEnd();
    }
    if (s.reminderDoneTime.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderDoneTime"),
            ThriftFieldType::T_I64,
            19);
        w.writeI64(s.reminderDoneTime.ref());
        w.writeFieldEnd();
    }
    if (s.reminderTime.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderTime"),
            ThriftFieldType::T_I64,
            20);
        w.writeI64(s.reminderTime.ref());
        w.writeFieldEnd();
    }
    if (s.placeName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("placeName"),
            ThriftFieldType::T_STRING,
            21);
        w.writeString(s.placeName.ref());
        w.writeFieldEnd();
    }
    if (s.contentClass.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentClass"),
            ThriftFieldType::T_STRING,
            22);
        w.writeString(s.contentClass.ref());
        w.writeFieldEnd();
    }
    if (s.applicationData.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            23);
        writeLazyMap(w, s.applicationData.ref());
        w.writeFieldEnd();
    }
    if (s.lastEditedBy.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastEditedBy"),
            ThriftFieldType::T_STRING,
            24);
        w.writeString(s.lastEditedBy.ref());
        w.writeFieldEnd();
    }
    if (s.classifications.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("classifications"),
            ThriftFieldType::T_MAP,
            26);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.classifications.ref().size());
        for(const auto & it: toRange(s.classifications.ref())) {
            w.writeString(it.key());
            w.writeString(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if (s.creatorId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("creatorId"),
            ThriftFieldType::T_I32,
            27);
        w.writeI32(s.creatorId.ref());
        w.writeFieldEnd();
    }
    if (s.lastEditorId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            28);
        w.writeI32(s.lastEditorId.ref());
        w.writeFieldEnd();
    }
    if (s.sharedWithBusiness.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharedWithBusiness"),
            ThriftFieldType::T_BOOL,
            29);
        w.writeBool(s.sharedWithBusiness.ref());
        w.writeFieldEnd();
    }
    if (s.conflictSourceNoteGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("conflictSourceNoteGuid"),
            ThriftFieldType::T_STRING,
            30);
        w.writeString(s.conflictSourceNoteGuid.ref());
        w.writeFieldEnd();
    }
    if (s.noteTitleQuality.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteTitleQuality"),
            ThriftFieldType::T_I32,
            31);
        w.writeI32(s.noteTitleQuality.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteAttributes(ThriftBinaryBufferReader & r, NoteAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.subjectDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.latitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.longitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.altitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.author = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.source = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceURL = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceApplication = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.shareDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderOrder = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderDoneTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.placeName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contentClass = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(r, v);
                s.applicationData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.lastEditedBy = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteAttributes.classifications)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteAttributes.classifications)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    r.readString(key);
                    QString value;
                    r.readString(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.classifications = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.creatorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.lastEditorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.sharedWithBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.conflictSourceNoteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteTitleQuality = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteAttributes & value)
{
    out << "NoteAttributes: {\n";

    if (value.subjectDate.isSet()) {
        out << "    subjectDate = "
            << value.subjectDate.ref() << "\n";
    }
    else {
        out << "    subjectDate is not set\n";
    }

    if (value.latitude.isSet()) {
        out << "    latitude = "
            << value.latitude.ref() << "\n";
    }
    else {
        out << "    latitude is not set\n";
    }

    if (value.longitude.isSet()) {
        out << "    longitude = "
            << value.longitude.ref() << "\n";
    }
    else {
        out << "    longitude is not set\n";
    }

    if (value.altitude.isSet()) {
        out << "    altitude = "
            << value.altitude.ref() << "\n";
    }
    else {
        out << "    altitude is not set\n";
    }

    if (value.author.isSet()) {
        out << "    author = "
            << value.author.ref() << "\n";
    }
    else {
        out << "    author is not set\n";
    }

    if (value.source.isSet()) {
        out << "    source = "
            << value.source.ref() << "\n";
    }
    else {
        out << "    source is not set\n";
    }

    if (value.sourceURL.isSet()) {
        out << "    sourceURL = "
            << value.sourceURL.ref() << "\n";
    }
    else {
        out << "    sourceURL is not set\n";
    }

    if (value.sourceApplication.isSet()) {
        out << "    sourceApplication = "
            << value.sourceApplication.ref() << "\n";
    }
    else {
        out << "    sourceApplication is not set\n";
    }

    if (value.shareDate.isSet()) {
        out << "    shareDate = "
            << value.shareDate.ref() << "\n";
    }
    else {
        out << "    shareDate is not set\n";
    }

    if (value.reminderOrder.isSet()) {
        out << "    reminderOrder = "
            << value.reminderOrder.ref() << "\n";
    }
    else {
        out << "    reminderOrder is not set\n";
    }

    if (value.reminderDoneTime.isSet()) {
        out << "    reminderDoneTime = "
            << value.reminderDoneTime.ref() << "\n";
    }
    else {
        out << "    reminderDoneTime is not set\n";
    }

    if (value.reminderTime.isSet()) {
        out << "    reminderTime = "
            << value.reminderTime.ref() << "\n";
    }
    else {
        out << "    reminderTime is not set\n";
    }

    if (value.placeName.isSet()) {
        out << "    placeName = "
            << value.placeName.ref() << "\n";
    }
    else {
        out << "    placeName is not set\n";
    }

    if (value.contentClass.isSet()) {
        out << "    contentClass = "
            << value.contentClass.ref() << "\n";
    }
    else {
        out << "    contentClass is not set\n";
    }

    if (value.applicationData.isSet()) {
        out << "    applicationData = "
            << value.applicationData.ref() << "\n";
    }
    else {
        out << "    applicationData is not set\n";
    }

    if (value.lastEditedBy.isSet()) {
        out << "    lastEditedBy = "
            << value.lastEditedBy.ref() << "\n";
    }
    else {
        out << "    lastEditedBy is not set\n";
    }

    if (value.classifications.isSet()) {
        out << "    classifications = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(value.classifications.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    classifications is not set\n";
    }

    if (value.creatorId.isSet()) {
        out << "    creatorId = "
            << value.creatorId.ref() << "\n";
    }
    else {
        out << "    creatorId is not set\n";
    }

    if (value.lastEditorId.isSet()) {
        out << "    lastEditorId = "
            << value.lastEditorId.ref() << "\n";
    }
    else {
        out << "    lastEditorId is not set\n";
    }

    if (value.sharedWithBusiness.isSet()) {
        out << "    sharedWithBusiness = "
            << value.sharedWithBusiness.ref() << "\n";
    }
    else {
        out << "    sharedWithBusiness is not set\n";
    }

    if (value.conflictSourceNoteGuid.isSet()) {
        out << "    conflictSourceNoteGuid = "
            << value.conflictSourceNoteGuid.ref() << "\n";
    }
    else {
        out << "    conflictSourceNoteGuid is not set\n";
    }

    if (value.noteTitleQuality.isSet()) {
        out << "    noteTitleQuality = "
            << value.noteTitleQuality.ref() << "\n";
    }
    else {
        out << "    noteTitleQuality is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteAttributes & value)
{
    out << "NoteAttributes: {\n";

    if (value.subjectDate.isSet()) {
        out << "    subjectDate = "
            << value.subjectDate.ref() << "\n";
    }
    else {
        out << "    subjectDate is not set\n";
    }

    if (value.latitude.isSet()) {
        out << "    latitude = "
            << value.latitude.ref() << "\n";
    }
    else {
        out << "    latitude is not set\n";
    }

    if (value.longitude.isSet()) {
        out << "    longitude = "
            << value.longitude.ref() << "\n";
    }
    else {
        out << "    longitude is not set\n";
    }

    if (value.altitude.isSet()) {
        out << "    altitude = "
            << value.altitude.ref() << "\n";
    }
    else {
        out << "    altitude is not set\n";
    }

    if (value.author.isSet()) {
        out << "    author = "
            << value.author.ref() << "\n";
    }
    else {
        out << "    author is not set\n";
    }

    if (value.source.isSet()) {
        out << "    source = "
            << value.source.ref() << "\n";
    }
    else {
        out << "    source is not set\n";
    }

    if (value.sourceURL.isSet()) {
        out << "    sourceURL = "
            << value.sourceURL.ref() << "\n";
    }
    else {
        out << "    sourceURL is not set\n";
    }

    if (value.sourceApplication.isSet()) {
        out << "    sourceApplication = "
            << value.sourceApplication.ref() << "\n";
    }
    else {
        out << "    sourceApplication is not set\n";
    }

    if (value.shareDate.isSet()) {
        out << "    shareDate = "
            << value.shareDate.ref() << "\n";
    }
    else {
        out << "    shareDate is not set\n";
    }

    if (value.reminderOrder.isSet()) {
        out << "    reminderOrder = "
            << value.reminderOrder.ref() << "\n";
    }
    else {
        out << "    reminderOrder is not set\n";
    }

    if (value.reminderDoneTime.isSet()) {
        out << "    reminderDoneTime = "
            << value.reminderDoneTime.ref() << "\n";
    }
    else {
        out << "    reminderDoneTime is not set\n";
    }

    if (value.reminderTime.isSet()) {
        out << "    reminderTime = "
            << value.reminderTime.ref() << "\n";
    }
    else {
        out << "    reminderTime is not set\n";
    }

    if (value.placeName.isSet()) {
        out << "    placeName = "
            << value.placeName.ref() << "\n";
    }
    else {
        out << "    placeName is not set\n";
    }

    if (value.contentClass.isSet()) {
        out << "    contentClass = "
            << value.contentClass.ref() << "\n";
    }
    else {
        out << "    contentClass is not set\n";
    }

    if (value.applicationData.isSet()) {
        out << "    applicationData = "
            << value.applicationData.ref() << "\n";
    }
    else {
        out << "    applicationData is not set\n";
    }

    if (value.lastEditedBy.isSet()) {
        out << "    lastEditedBy = "
            << value.lastEditedBy.ref() << "\n";
    }
    else {
        out << "    lastEditedBy is not set\n";
    }

    if (value.classifications.isSet()) {
        out << "    classifications = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(value.classifications.ref())) {
            out << "[" << it.key() << "] = " << it.value() << "\n";
        }
    }
    else {
        out << "    classifications is not set\n";
    }

    if (value.creatorId.isSet()) {
        out << "    creatorId = "
            << value.creatorId.ref() << "\n";
    }
    else {
        out << "    creatorId is not set\n";
    }

    if (value.lastEditorId.isSet()) {
        out << "    lastEditorId = "
            << value.lastEditorId.ref() << "\n";
    }
    else {
        out << "    lastEditorId is not set\n";
    }

    if (value.sharedWithBusiness.isSet()) {
        out << "    sharedWithBusiness = "
            << value.sharedWithBusiness.ref() << "\n";
    }
    else {
        out << "    sharedWithBusiness is not set\n";
    }

    if (value.conflictSourceNoteGuid.isSet()) {
        out << "    conflictSourceNoteGuid = "
            << value.conflictSourceNoteGuid.ref() << "\n";
    }
    else {
        out << "    conflictSourceNoteGuid is not set\n";
    }

    if (value.noteTitleQuality.isSet()) {
        out << "    noteTitleQuality = "
            << value.noteTitleQuality.ref() << "\n";
    }
    else {
        out << "    noteTitleQuality is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNote(ThriftBinaryBufferWriter & w, const SharedNote & s) {
    w.writeStructBegin(QStringLiteral("SharedNote"));
    if (s.sharerUserID.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserID"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.sharerUserID.ref());
        w.writeFieldEnd();
    }
    if (s.recipientIdentity.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientIdentity"),
            ThriftFieldType::T_STRUCT,
            2);
        writeIdentity(w, s.recipientIdentity.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.serviceCreated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            4);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if (s.serviceUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.serviceAssigned.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            6);
        w.writeI64(s.serviceAssigned.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNote(ThriftBinaryBufferReader & r, SharedNote & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Identity v;
                readIdentity(r, v);
                s.recipientIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceAssigned = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNote & value)
{
    out << "SharedNote: {\n";

    if (value.sharerUserID.isSet()) {
        out << "    sharerUserID = "
            << value.sharerUserID.ref() << "\n";
    }
    else {
        out << "    sharerUserID is not set\n";
    }

    if (value.recipientIdentity.isSet()) {
        out << "    recipientIdentity = "
            << value.recipientIdentity.ref() << "\n";
    }
    else {
        out << "    recipientIdentity is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.serviceAssigned.isSet()) {
        out << "    serviceAssigned = "
            << value.serviceAssigned.ref() << "\n";
    }
    else {
        out << "    serviceAssigned is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNote & value)
{
    out << "SharedNote: {\n";

    if (value.sharerUserID.isSet()) {
        out << "    sharerUserID = "
            << value.sharerUserID.ref() << "\n";
    }
    else {
        out << "    sharerUserID is not set\n";
    }

    if (value.recipientIdentity.isSet()) {
        out << "    recipientIdentity = "
            << value.recipientIdentity.ref() << "\n";
    }
    else {
        out << "    recipientIdentity is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.serviceAssigned.isSet()) {
        out << "    serviceAssigned = "
            << value.serviceAssigned.ref() << "\n";
    }
    else {
        out << "    serviceAssigned is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteRestrictions(ThriftBinaryBufferWriter & w, const NoteRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NoteRestrictions"));
    if (s.noUpdateTitle.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noUpdateTitle"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.noUpdateTitle.ref());
        w.writeFieldEnd();
    }
    if (s.noUpdateContent.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noUpdateContent"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.noUpdateContent.ref());
        w.writeFieldEnd();
    }
    if (s.noEmail.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noEmail"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.noEmail.ref());
        w.writeFieldEnd();
    }
    if (s.noShare.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noShare"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.noShare.ref());
        w.writeFieldEnd();
    }
    if (s.noSharePublicly.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSharePublicly"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.noSharePublicly.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteRestrictions(ThriftBinaryBufferReader & r, NoteRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateTitle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSharePublicly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteRestrictions & value)
{
    out << "NoteRestrictions: {\n";

    if (value.noUpdateTitle.isSet()) {
        out << "    noUpdateTitle = "
            << value.noUpdateTitle.ref() << "\n";
    }
    else {
        out << "    noUpdateTitle is not set\n";
    }

    if (value.noUpdateContent.isSet()) {
        out << "    noUpdateContent = "
            << value.noUpdateContent.ref() << "\n";
    }
    else {
        out << "    noUpdateContent is not set\n";
    }

    if (value.noEmail.isSet()) {
        out << "    noEmail = "
            << value.noEmail.ref() << "\n";
    }
    else {
        out << "    noEmail is not set\n";
    }

    if (value.noShare.isSet()) {
        out << "    noShare = "
            << value.noShare.ref() << "\n";
    }
    else {
        out << "    noShare is not set\n";
    }

    if (value.noSharePublicly.isSet()) {
        out << "    noSharePublicly = "
            << value.noSharePublicly.ref() << "\n";
    }
    else {
        out << "    noSharePublicly is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteRestrictions & value)
{
    out << "NoteRestrictions: {\n";

    if (value.noUpdateTitle.isSet()) {
        out << "    noUpdateTitle = "
            << value.noUpdateTitle.ref() << "\n";
    }
    else {
        out << "    noUpdateTitle is not set\n";
    }

    if (value.noUpdateContent.isSet()) {
        out << "    noUpdateContent = "
            << value.noUpdateContent.ref() << "\n";
    }
    else {
        out << "    noUpdateContent is not set\n";
    }

    if (value.noEmail.isSet()) {
        out << "    noEmail = "
            << value.noEmail.ref() << "\n";
    }
    else {
        out << "    noEmail is not set\n";
    }

    if (value.noShare.isSet()) {
        out << "    noShare = "
            << value.noShare.ref() << "\n";
    }
    else {
        out << "    noShare is not set\n";
    }

    if (value.noSharePublicly.isSet()) {
        out << "    noSharePublicly = "
            << value.noSharePublicly.ref() << "\n";
    }
    else {
        out << "    noSharePublicly is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteLimits(ThriftBinaryBufferWriter & w, const NoteLimits & s) {
    w.writeStructBegin(QStringLiteral("NoteLimits"));
    if (s.noteResourceCountMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.noteResourceCountMax.ref());
        w.writeFieldEnd();
    }
    if (s.uploadLimit.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            2);
        w.writeI64(s.uploadLimit.ref());
        w.writeFieldEnd();
    }
    if (s.resourceSizeMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);
        w.writeI64(s.resourceSizeMax.ref());
        w.writeFieldEnd();
    }
    if (s.noteSizeMax.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            4);
        w.writeI64(s.noteSizeMax.ref());
        w.writeFieldEnd();
    }
    if (s.uploaded.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            5);
        w.writeI64(s.uploaded.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteLimits(ThriftBinaryBufferReader & r, NoteLimits & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteResourceCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.resourceSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.noteSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploaded = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteLimits & value)
{
    out << "NoteLimits: {\n";

    if (value.noteResourceCountMax.isSet()) {
        out << "    noteResourceCountMax = "
            << value.noteResourceCountMax.ref() << "\n";
    }
    else {
        out << "    noteResourceCountMax is not set\n";
    }

    if (value.uploadLimit.isSet()) {
        out << "    uploadLimit = "
            << value.uploadLimit.ref() << "\n";
    }
    else {
        out << "    uploadLimit is not set\n";
    }

    if (value.resourceSizeMax.isSet()) {
        out << "    resourceSizeMax = "
            << value.resourceSizeMax.ref() << "\n";
    }
    else {
        out << "    resourceSizeMax is not set\n";
    }

    if (value.noteSizeMax.isSet()) {
        out << "    noteSizeMax = "
            << value.noteSizeMax.ref() << "\n";
    }
    else {
        out << "    noteSizeMax is not set\n";
    }

    if (value.uploaded.isSet()) {
        out << "    uploaded = "
            << value.uploaded.ref() << "\n";
    }
    else {
        out << "    uploaded is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteLimits & value)
{
    out << "NoteLimits: {\n";

    if (value.noteResourceCountMax.isSet()) {
        out << "    noteResourceCountMax = "
            << value.noteResourceCountMax.ref() << "\n";
    }
    else {
        out << "    noteResourceCountMax is not set\n";
    }

    if (value.uploadLimit.isSet()) {
        out << "    uploadLimit = "
            << value.uploadLimit.ref() << "\n";
    }
    else {
        out << "    uploadLimit is not set\n";
    }

    if (value.resourceSizeMax.isSet()) {
        out << "    resourceSizeMax = "
            << value.resourceSizeMax.ref() << "\n";
    }
    else {
        out << "    resourceSizeMax is not set\n";
    }

    if (value.noteSizeMax.isSet()) {
        out << "    noteSizeMax = "
            << value.noteSizeMax.ref() << "\n";
    }
    else {
        out << "    noteSizeMax is not set\n";
    }

    if (value.uploaded.isSet()) {
        out << "    uploaded = "
            << value.uploaded.ref() << "\n";
    }
    else {
        out << "    uploaded is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNote(ThriftBinaryBufferWriter & w, const Note & s) {
    w.writeStructBegin(QStringLiteral("Note"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.title.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if (s.content.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("content"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.content.ref());
        w.writeFieldEnd();
    }
    if (s.contentHash.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentHash"),
            ThriftFieldType::T_STRING,
            4);
        w.writeBinary(s.contentHash.ref());
        w.writeFieldEnd();
    }
    if (s.contentLength.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.contentLength.ref());
        w.writeFieldEnd();
    }
    if (s.created.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if (s.updated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if (s.deleted.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if (s.active.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            9);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.tagGuids.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.resources.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            13);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(const auto & value: qAsConst(s.resources.ref())) {
            writeResource(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.attributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);
        writeNoteAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if (s.tagNames.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("tagNames"),
            ThriftFieldType::T_LIST,
            15);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagNames.ref().length());
        for(const auto & value: qAsConst(s.tagNames.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.sharedNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharedNotes"),
            ThriftFieldType::T_LIST,
            16);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotes.ref().length());
        for(const auto & value: qAsConst(s.sharedNotes.ref())) {
            writeSharedNote(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.restrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);
        writeNoteRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if (s.limits.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("limits"),
            ThriftFieldType::T_STRUCT,
            18);
        writeNoteLimits(w, s.limits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNote(ThriftBinaryBufferReader & r, Note & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.content = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.contentHash = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.contentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.resources)"));
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.resources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.tagNames)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagNames = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNote> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.sharedNotes)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNote elem;
                    readSharedNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteRestrictions v;
                readNoteRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteLimits v;
                readNoteLimits(r, v);
                s.limits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Note & value)
{
    out << "Note: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.content.isSet()) {
        out << "    content = "
            << value.content.ref() << "\n";
    }
    else {
        out << "    content is not set\n";
    }

    if (value.contentHash.isSet()) {
        out << "    contentHash = "
            << value.contentHash.ref() << "\n";
    }
    else {
        out << "    contentHash is not set\n";
    }

    if (value.contentLength.isSet()) {
        out << "    contentLength = "
            << value.contentLength.ref() << "\n";
    }
    else {
        out << "    contentLength is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.resources.isSet()) {
        out << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: value.resources.ref()) {
            out << v;
        }
    }
    else {
        out << "    resources is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.tagNames.isSet()) {
        out << "    tagNames = "
            << "QList<QString> {";
        for(const auto & v: value.tagNames.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagNames is not set\n";
    }

    if (value.sharedNotes.isSet()) {
        out << "    sharedNotes = "
            << "QList<SharedNote> {";
        for(const auto & v: value.sharedNotes.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotes is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.limits.isSet()) {
        out << "    limits = "
            << value.limits.ref() << "\n";
    }
    else {
        out << "    limits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Note & value)
{
    out << "Note: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.content.isSet()) {
        out << "    content = "
            << value.content.ref() << "\n";
    }
    else {
        out << "    content is not set\n";
    }

    if (value.contentHash.isSet()) {
        out << "    contentHash = "
            << value.contentHash.ref() << "\n";
    }
    else {
        out << "    contentHash is not set\n";
    }

    if (value.contentLength.isSet()) {
        out << "    contentLength = "
            << value.contentLength.ref() << "\n";
    }
    else {
        out << "    contentLength is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.updated.isSet()) {
        out << "    updated = "
            << value.updated.ref() << "\n";
    }
    else {
        out << "    updated is not set\n";
    }

    if (value.deleted.isSet()) {
        out << "    deleted = "
            << value.deleted.ref() << "\n";
    }
    else {
        out << "    deleted is not set\n";
    }

    if (value.active.isSet()) {
        out << "    active = "
            << value.active.ref() << "\n";
    }
    else {
        out << "    active is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.tagGuids.isSet()) {
        out << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: value.tagGuids.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagGuids is not set\n";
    }

    if (value.resources.isSet()) {
        out << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: value.resources.ref()) {
            out << v;
        }
    }
    else {
        out << "    resources is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.tagNames.isSet()) {
        out << "    tagNames = "
            << "QList<QString> {";
        for(const auto & v: value.tagNames.ref()) {
            out << v;
        }
    }
    else {
        out << "    tagNames is not set\n";
    }

    if (value.sharedNotes.isSet()) {
        out << "    sharedNotes = "
            << "QList<SharedNote> {";
        for(const auto & v: value.sharedNotes.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotes is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.limits.isSet()) {
        out << "    limits = "
            << value.limits.ref() << "\n";
    }
    else {
        out << "    limits is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writePublishing(ThriftBinaryBufferWriter & w, const Publishing & s) {
    w.writeStructBegin(QStringLiteral("Publishing"));
    if (s.uri.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.uri.ref());
        w.writeFieldEnd();
    }
    if (s.order.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(static_cast<qint32>(s.order.ref()));
        w.writeFieldEnd();
    }
    if (s.ascending.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.ascending.ref());
        w.writeFieldEnd();
    }
    if (s.publicDescription.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("publicDescription"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.publicDescription.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readPublishing(ThriftBinaryBufferReader & r, Publishing & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.uri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                NoteSortOrder v;
                readEnumNoteSortOrder(r, v);
                s.order = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.ascending = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.publicDescription = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Publishing & value)
{
    out << "Publishing: {\n";

    if (value.uri.isSet()) {
        out << "    uri = "
            << value.uri.ref() << "\n";
    }
    else {
        out << "    uri is not set\n";
    }

    if (value.order.isSet()) {
        out << "    order = "
            << value.order.ref() << "\n";
    }
    else {
        out << "    order is not set\n";
    }

    if (value.ascending.isSet()) {
        out << "    ascending = "
            << value.ascending.ref() << "\n";
    }
    else {
        out << "    ascending is not set\n";
    }

    if (value.publicDescription.isSet()) {
        out << "    publicDescription = "
            << value.publicDescription.ref() << "\n";
    }
    else {
        out << "    publicDescription is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Publishing & value)
{
    out << "Publishing: {\n";

    if (value.uri.isSet()) {
        out << "    uri = "
            << value.uri.ref() << "\n";
    }
    else {
        out << "    uri is not set\n";
    }

    if (value.order.isSet()) {
        out << "    order = "
            << value.order.ref() << "\n";
    }
    else {
        out << "    order is not set\n";
    }

    if (value.ascending.isSet()) {
        out << "    ascending = "
            << value.ascending.ref() << "\n";
    }
    else {
        out << "    ascending is not set\n";
    }

    if (value.publicDescription.isSet()) {
        out << "    publicDescription = "
            << value.publicDescription.ref() << "\n";
    }
    else {
        out << "    publicDescription is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessNotebook(ThriftBinaryBufferWriter & w, const BusinessNotebook & s) {
    w.writeStructBegin(QStringLiteral("BusinessNotebook"));
    if (s.notebookDescription.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookDescription"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.notebookDescription.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.recommended.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recommended"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.recommended.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessNotebook(ThriftBinaryBufferReader & r, BusinessNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookDescription = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.recommended = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessNotebook & value)
{
    out << "BusinessNotebook: {\n";

    if (value.notebookDescription.isSet()) {
        out << "    notebookDescription = "
            << value.notebookDescription.ref() << "\n";
    }
    else {
        out << "    notebookDescription is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.recommended.isSet()) {
        out << "    recommended = "
            << value.recommended.ref() << "\n";
    }
    else {
        out << "    recommended is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessNotebook & value)
{
    out << "BusinessNotebook: {\n";

    if (value.notebookDescription.isSet()) {
        out << "    notebookDescription = "
            << value.notebookDescription.ref() << "\n";
    }
    else {
        out << "    notebookDescription is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.recommended.isSet()) {
        out << "    recommended = "
            << value.recommended.ref() << "\n";
    }
    else {
        out << "    recommended is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSavedSearchScope(ThriftBinaryBufferWriter & w, const SavedSearchScope & s) {
    w.writeStructBegin(QStringLiteral("SavedSearchScope"));
    if (s.includeAccount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeAccount"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.includeAccount.ref());
        w.writeFieldEnd();
    }
    if (s.includePersonalLinkedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includePersonalLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.includePersonalLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.includeBusinessLinkedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("includeBusinessLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.includeBusinessLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSavedSearchScope(ThriftBinaryBufferReader & r, SavedSearchScope & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAccount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includePersonalLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeBusinessLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SavedSearchScope & value)
{
    out << "SavedSearchScope: {\n";

    if (value.includeAccount.isSet()) {
        out << "    includeAccount = "
            << value.includeAccount.ref() << "\n";
    }
    else {
        out << "    includeAccount is not set\n";
    }

    if (value.includePersonalLinkedNotebooks.isSet()) {
        out << "    includePersonalLinkedNotebooks = "
            << value.includePersonalLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includePersonalLinkedNotebooks is not set\n";
    }

    if (value.includeBusinessLinkedNotebooks.isSet()) {
        out << "    includeBusinessLinkedNotebooks = "
            << value.includeBusinessLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includeBusinessLinkedNotebooks is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SavedSearchScope & value)
{
    out << "SavedSearchScope: {\n";

    if (value.includeAccount.isSet()) {
        out << "    includeAccount = "
            << value.includeAccount.ref() << "\n";
    }
    else {
        out << "    includeAccount is not set\n";
    }

    if (value.includePersonalLinkedNotebooks.isSet()) {
        out << "    includePersonalLinkedNotebooks = "
            << value.includePersonalLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includePersonalLinkedNotebooks is not set\n";
    }

    if (value.includeBusinessLinkedNotebooks.isSet()) {
        out << "    includeBusinessLinkedNotebooks = "
            << value.includeBusinessLinkedNotebooks.ref() << "\n";
    }
    else {
        out << "    includeBusinessLinkedNotebooks is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSavedSearch(ThriftBinaryBufferWriter & w, const SavedSearch & s) {
    w.writeStructBegin(QStringLiteral("SavedSearch"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.query.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("query"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.query.ref());
        w.writeFieldEnd();
    }
    if (s.format.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("format"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(static_cast<qint32>(s.format.ref()));
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.scope.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("scope"),
            ThriftFieldType::T_STRUCT,
            6);
        writeSavedSearchScope(w, s.scope.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSavedSearch(ThriftBinaryBufferReader & r, SavedSearch & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.query = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                QueryFormat v;
                readEnumQueryFormat(r, v);
                s.format = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearchScope v;
                readSavedSearchScope(r, v);
                s.scope = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SavedSearch & value)
{
    out << "SavedSearch: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.query.isSet()) {
        out << "    query = "
            << value.query.ref() << "\n";
    }
    else {
        out << "    query is not set\n";
    }

    if (value.format.isSet()) {
        out << "    format = "
            << value.format.ref() << "\n";
    }
    else {
        out << "    format is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.scope.isSet()) {
        out << "    scope = "
            << value.scope.ref() << "\n";
    }
    else {
        out << "    scope is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SavedSearch & value)
{
    out << "SavedSearch: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.query.isSet()) {
        out << "    query = "
            << value.query.ref() << "\n";
    }
    else {
        out << "    query is not set\n";
    }

    if (value.format.isSet()) {
        out << "    format = "
            << value.format.ref() << "\n";
    }
    else {
        out << "    format is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.scope.isSet()) {
        out << "    scope = "
            << value.scope.ref() << "\n";
    }
    else {
        out << "    scope is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const SharedNotebookRecipientSettings & s) {
    w.writeStructBegin(QStringLiteral("SharedNotebookRecipientSettings"));
    if (s.reminderNotifyEmail.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.reminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if (s.reminderNotifyInApp.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.reminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNotebookRecipientSettings(ThriftBinaryBufferReader & r, SharedNotebookRecipientSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNotebookRecipientSettings & value)
{
    out << "SharedNotebookRecipientSettings: {\n";

    if (value.reminderNotifyEmail.isSet()) {
        out << "    reminderNotifyEmail = "
            << value.reminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    reminderNotifyEmail is not set\n";
    }

    if (value.reminderNotifyInApp.isSet()) {
        out << "    reminderNotifyInApp = "
            << value.reminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    reminderNotifyInApp is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNotebookRecipientSettings & value)
{
    out << "SharedNotebookRecipientSettings: {\n";

    if (value.reminderNotifyEmail.isSet()) {
        out << "    reminderNotifyEmail = "
            << value.reminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    reminderNotifyEmail is not set\n";
    }

    if (value.reminderNotifyInApp.isSet()) {
        out << "    reminderNotifyInApp = "
            << value.reminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    reminderNotifyInApp is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const NotebookRecipientSettings & s) {
    w.writeStructBegin(QStringLiteral("NotebookRecipientSettings"));
    if (s.reminderNotifyEmail.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.reminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if (s.reminderNotifyInApp.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.reminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    if (s.inMyList.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("inMyList"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.inMyList.ref());
        w.writeFieldEnd();
    }
    if (s.stack.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if (s.recipientStatus.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientStatus"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(static_cast<qint32>(s.recipientStatus.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookRecipientSettings(ThriftBinaryBufferReader & r, NotebookRecipientSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.inMyList = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                RecipientStatus v;
                readEnumRecipientStatus(r, v);
                s.recipientStatus = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotebookRecipientSettings & value)
{
    out << "NotebookRecipientSettings: {\n";

    if (value.reminderNotifyEmail.isSet()) {
        out << "    reminderNotifyEmail = "
            << value.reminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    reminderNotifyEmail is not set\n";
    }

    if (value.reminderNotifyInApp.isSet()) {
        out << "    reminderNotifyInApp = "
            << value.reminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    reminderNotifyInApp is not set\n";
    }

    if (value.inMyList.isSet()) {
        out << "    inMyList = "
            << value.inMyList.ref() << "\n";
    }
    else {
        out << "    inMyList is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.recipientStatus.isSet()) {
        out << "    recipientStatus = "
            << value.recipientStatus.ref() << "\n";
    }
    else {
        out << "    recipientStatus is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotebookRecipientSettings & value)
{
    out << "NotebookRecipientSettings: {\n";

    if (value.reminderNotifyEmail.isSet()) {
        out << "    reminderNotifyEmail = "
            << value.reminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    reminderNotifyEmail is not set\n";
    }

    if (value.reminderNotifyInApp.isSet()) {
        out << "    reminderNotifyInApp = "
            << value.reminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    reminderNotifyInApp is not set\n";
    }

    if (value.inMyList.isSet()) {
        out << "    inMyList = "
            << value.inMyList.ref() << "\n";
    }
    else {
        out << "    inMyList is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.recipientStatus.isSet()) {
        out << "    recipientStatus = "
            << value.recipientStatus.ref() << "\n";
    }
    else {
        out << "    recipientStatus is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNotebook(ThriftBinaryBufferWriter & w, const SharedNotebook & s) {
    w.writeStructBegin(QStringLiteral("SharedNotebook"));
    if (s.id.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I64,
            1);
        w.writeI64(s.id.ref());
        w.writeFieldEnd();
    }
    if (s.userId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.userId.ref());
        w.writeFieldEnd();
    }
    if (s.notebookGuid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if (s.email.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if (s.recipientIdentityId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            18);
        w.writeI64(s.recipientIdentityId.ref());
        w.writeFieldEnd();
    }
    if (s.notebookModifiable.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookModifiable"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.notebookModifiable.ref());
        w.writeFieldEnd();
    }
    if (s.serviceCreated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if (s.serviceUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            10);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.globalId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("globalId"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.globalId.ref());
        w.writeFieldEnd();
    }
    if (s.username.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if (s.privilege.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            11);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if (s.recipientSettings.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            13);
        writeSharedNotebookRecipientSettings(w, s.recipientSettings.ref());
        w.writeFieldEnd();
    }
    if (s.sharerUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            14);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    if (s.recipientUsername.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientUsername"),
            ThriftFieldType::T_STRING,
            15);
        w.writeString(s.recipientUsername.ref());
        w.writeFieldEnd();
    }
    if (s.recipientUserId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            17);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if (s.serviceAssigned.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            16);
        w.writeI64(s.serviceAssigned.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNotebook(ThriftBinaryBufferReader & r, SharedNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.recipientIdentityId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.notebookModifiable = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.globalId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebookRecipientSettings v;
                readSharedNotebookRecipientSettings(r, v);
                s.recipientSettings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recipientUsername = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceAssigned = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNotebook & value)
{
    out << "SharedNotebook: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.userId.isSet()) {
        out << "    userId = "
            << value.userId.ref() << "\n";
    }
    else {
        out << "    userId is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.recipientIdentityId.isSet()) {
        out << "    recipientIdentityId = "
            << value.recipientIdentityId.ref() << "\n";
    }
    else {
        out << "    recipientIdentityId is not set\n";
    }

    if (value.notebookModifiable.isSet()) {
        out << "    notebookModifiable = "
            << value.notebookModifiable.ref() << "\n";
    }
    else {
        out << "    notebookModifiable is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.globalId.isSet()) {
        out << "    globalId = "
            << value.globalId.ref() << "\n";
    }
    else {
        out << "    globalId is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.recipientSettings.isSet()) {
        out << "    recipientSettings = "
            << value.recipientSettings.ref() << "\n";
    }
    else {
        out << "    recipientSettings is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    if (value.recipientUsername.isSet()) {
        out << "    recipientUsername = "
            << value.recipientUsername.ref() << "\n";
    }
    else {
        out << "    recipientUsername is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.serviceAssigned.isSet()) {
        out << "    serviceAssigned = "
            << value.serviceAssigned.ref() << "\n";
    }
    else {
        out << "    serviceAssigned is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNotebook & value)
{
    out << "SharedNotebook: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.userId.isSet()) {
        out << "    userId = "
            << value.userId.ref() << "\n";
    }
    else {
        out << "    userId is not set\n";
    }

    if (value.notebookGuid.isSet()) {
        out << "    notebookGuid = "
            << value.notebookGuid.ref() << "\n";
    }
    else {
        out << "    notebookGuid is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.recipientIdentityId.isSet()) {
        out << "    recipientIdentityId = "
            << value.recipientIdentityId.ref() << "\n";
    }
    else {
        out << "    recipientIdentityId is not set\n";
    }

    if (value.notebookModifiable.isSet()) {
        out << "    notebookModifiable = "
            << value.notebookModifiable.ref() << "\n";
    }
    else {
        out << "    notebookModifiable is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.globalId.isSet()) {
        out << "    globalId = "
            << value.globalId.ref() << "\n";
    }
    else {
        out << "    globalId is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.privilege.isSet()) {
        out << "    privilege = "
            << value.privilege.ref() << "\n";
    }
    else {
        out << "    privilege is not set\n";
    }

    if (value.recipientSettings.isSet()) {
        out << "    recipientSettings = "
            << value.recipientSettings.ref() << "\n";
    }
    else {
        out << "    recipientSettings is not set\n";
    }

    if (value.sharerUserId.isSet()) {
        out << "    sharerUserId = "
            << value.sharerUserId.ref() << "\n";
    }
    else {
        out << "    sharerUserId is not set\n";
    }

    if (value.recipientUsername.isSet()) {
        out << "    recipientUsername = "
            << value.recipientUsername.ref() << "\n";
    }
    else {
        out << "    recipientUsername is not set\n";
    }

    if (value.recipientUserId.isSet()) {
        out << "    recipientUserId = "
            << value.recipientUserId.ref() << "\n";
    }
    else {
        out << "    recipientUserId is not set\n";
    }

    if (value.serviceAssigned.isSet()) {
        out << "    serviceAssigned = "
            << value.serviceAssigned.ref() << "\n";
    }
    else {
        out << "    serviceAssigned is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeCanMoveToContainerRestrictions(ThriftBinaryBufferWriter & w, const CanMoveToContainerRestrictions & s) {
    w.writeStructBegin(QStringLiteral("CanMoveToContainerRestrictions"));
    if (s.canMoveToContainer.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("canMoveToContainer"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(static_cast<qint32>(s.canMoveToContainer.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readCanMoveToContainerRestrictions(ThriftBinaryBufferReader & r, CanMoveToContainerRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                CanMoveToContainerStatus v;
                readEnumCanMoveToContainerStatus(r, v);
                s.canMoveToContainer = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const CanMoveToContainerRestrictions & value)
{
    out << "CanMoveToContainerRestrictions: {\n";

    if (value.canMoveToContainer.isSet()) {
        out << "    canMoveToContainer = "
            << value.canMoveToContainer.ref() << "\n";
    }
    else {
        out << "    canMoveToContainer is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const CanMoveToContainerRestrictions & value)
{
    out << "CanMoveToContainerRestrictions: {\n";

    if (value.canMoveToContainer.isSet()) {
        out << "    canMoveToContainer = "
            << value.canMoveToContainer.ref() << "\n";
    }
    else {
        out << "    canMoveToContainer is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookRestrictions(ThriftBinaryBufferWriter & w, const NotebookRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NotebookRestrictions"));
    if (s.noReadNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noReadNotes"),
            ThriftFieldType::T_BOOL,
            1);
        w.writeBool(s.noReadNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noCreateNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noCreateNotes"),
            ThriftFieldType::T_BOOL,
            2);
        w.writeBool(s.noCreateNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noUpdateNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noUpdateNotes"),
            ThriftFieldType::T_BOOL,
            3);
        w.writeBool(s.noUpdateNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noExpungeNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noExpungeNotes"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.noExpungeNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noShareNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noShareNotes"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.noShareNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noEmailNotes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noEmailNotes"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.noEmailNotes.ref());
        w.writeFieldEnd();
    }
    if (s.noSendMessageToRecipients.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSendMessageToRecipients"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.noSendMessageToRecipients.ref());
        w.writeFieldEnd();
    }
    if (s.noUpdateNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noUpdateNotebook"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.noUpdateNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.noExpungeNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noExpungeNotebook"),
            ThriftFieldType::T_BOOL,
            9);
        w.writeBool(s.noExpungeNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.noSetDefaultNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetDefaultNotebook"),
            ThriftFieldType::T_BOOL,
            10);
        w.writeBool(s.noSetDefaultNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.noSetNotebookStack.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetNotebookStack"),
            ThriftFieldType::T_BOOL,
            11);
        w.writeBool(s.noSetNotebookStack.ref());
        w.writeFieldEnd();
    }
    if (s.noPublishToPublic.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noPublishToPublic"),
            ThriftFieldType::T_BOOL,
            12);
        w.writeBool(s.noPublishToPublic.ref());
        w.writeFieldEnd();
    }
    if (s.noPublishToBusinessLibrary.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noPublishToBusinessLibrary"),
            ThriftFieldType::T_BOOL,
            13);
        w.writeBool(s.noPublishToBusinessLibrary.ref());
        w.writeFieldEnd();
    }
    if (s.noCreateTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noCreateTags"),
            ThriftFieldType::T_BOOL,
            14);
        w.writeBool(s.noCreateTags.ref());
        w.writeFieldEnd();
    }
    if (s.noUpdateTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noUpdateTags"),
            ThriftFieldType::T_BOOL,
            15);
        w.writeBool(s.noUpdateTags.ref());
        w.writeFieldEnd();
    }
    if (s.noExpungeTags.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noExpungeTags"),
            ThriftFieldType::T_BOOL,
            16);
        w.writeBool(s.noExpungeTags.ref());
        w.writeFieldEnd();
    }
    if (s.noSetParentTag.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetParentTag"),
            ThriftFieldType::T_BOOL,
            17);
        w.writeBool(s.noSetParentTag.ref());
        w.writeFieldEnd();
    }
    if (s.noCreateSharedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noCreateSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            18);
        w.writeBool(s.noCreateSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.updateWhichSharedNotebookRestrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            19);
        w.writeI32(static_cast<qint32>(s.updateWhichSharedNotebookRestrictions.ref()));
        w.writeFieldEnd();
    }
    if (s.expungeWhichSharedNotebookRestrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("expungeWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            20);
        w.writeI32(static_cast<qint32>(s.expungeWhichSharedNotebookRestrictions.ref()));
        w.writeFieldEnd();
    }
    if (s.noShareNotesWithBusiness.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noShareNotesWithBusiness"),
            ThriftFieldType::T_BOOL,
            21);
        w.writeBool(s.noShareNotesWithBusiness.ref());
        w.writeFieldEnd();
    }
    if (s.noRenameNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noRenameNotebook"),
            ThriftFieldType::T_BOOL,
            22);
        w.writeBool(s.noRenameNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.noSetInMyList.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetInMyList"),
            ThriftFieldType::T_BOOL,
            23);
        w.writeBool(s.noSetInMyList.ref());
        w.writeFieldEnd();
    }
    if (s.noChangeContact.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noChangeContact"),
            ThriftFieldType::T_BOOL,
            24);
        w.writeBool(s.noChangeContact.ref());
        w.writeFieldEnd();
    }
    if (s.canMoveToContainerRestrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("canMoveToContainerRestrictions"),
            ThriftFieldType::T_STRUCT,
            26);
        writeCanMoveToContainerRestrictions(w, s.canMoveToContainerRestrictions.ref());
        w.writeFieldEnd();
    }
    if (s.noSetReminderNotifyEmail.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            27);
        w.writeBool(s.noSetReminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if (s.noSetReminderNotifyInApp.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            28);
        w.writeBool(s.noSetReminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    if (s.noSetRecipientSettingsStack.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noSetRecipientSettingsStack"),
            ThriftFieldType::T_BOOL,
            29);
        w.writeBool(s.noSetRecipientSettingsStack.ref());
        w.writeFieldEnd();
    }
    if (s.noCanMoveNote.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noCanMoveNote"),
            ThriftFieldType::T_BOOL,
            30);
        w.writeBool(s.noCanMoveNote.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookRestrictions(ThriftBinaryBufferReader & r, NotebookRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noReadNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShareNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noEmailNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSendMessageToRecipients = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetDefaultNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetNotebookStack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noPublishToPublic = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noPublishToBusinessLibrary = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetParentTag = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(r, v);
                s.updateWhichSharedNotebookRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(r, v);
                s.expungeWhichSharedNotebookRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShareNotesWithBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noRenameNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetInMyList = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noChangeContact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                CanMoveToContainerRestrictions v;
                readCanMoveToContainerRestrictions(r, v);
                s.canMoveToContainerRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetRecipientSettingsStack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCanMoveNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotebookRestrictions & value)
{
    out << "NotebookRestrictions: {\n";

    if (value.noReadNotes.isSet()) {
        out << "    noReadNotes = "
            << value.noReadNotes.ref() << "\n";
    }
    else {
        out << "    noReadNotes is not set\n";
    }

    if (value.noCreateNotes.isSet()) {
        out << "    noCreateNotes = "
            << value.noCreateNotes.ref() << "\n";
    }
    else {
        out << "    noCreateNotes is not set\n";
    }

    if (value.noUpdateNotes.isSet()) {
        out << "    noUpdateNotes = "
            << value.noUpdateNotes.ref() << "\n";
    }
    else {
        out << "    noUpdateNotes is not set\n";
    }

    if (value.noExpungeNotes.isSet()) {
        out << "    noExpungeNotes = "
            << value.noExpungeNotes.ref() << "\n";
    }
    else {
        out << "    noExpungeNotes is not set\n";
    }

    if (value.noShareNotes.isSet()) {
        out << "    noShareNotes = "
            << value.noShareNotes.ref() << "\n";
    }
    else {
        out << "    noShareNotes is not set\n";
    }

    if (value.noEmailNotes.isSet()) {
        out << "    noEmailNotes = "
            << value.noEmailNotes.ref() << "\n";
    }
    else {
        out << "    noEmailNotes is not set\n";
    }

    if (value.noSendMessageToRecipients.isSet()) {
        out << "    noSendMessageToRecipients = "
            << value.noSendMessageToRecipients.ref() << "\n";
    }
    else {
        out << "    noSendMessageToRecipients is not set\n";
    }

    if (value.noUpdateNotebook.isSet()) {
        out << "    noUpdateNotebook = "
            << value.noUpdateNotebook.ref() << "\n";
    }
    else {
        out << "    noUpdateNotebook is not set\n";
    }

    if (value.noExpungeNotebook.isSet()) {
        out << "    noExpungeNotebook = "
            << value.noExpungeNotebook.ref() << "\n";
    }
    else {
        out << "    noExpungeNotebook is not set\n";
    }

    if (value.noSetDefaultNotebook.isSet()) {
        out << "    noSetDefaultNotebook = "
            << value.noSetDefaultNotebook.ref() << "\n";
    }
    else {
        out << "    noSetDefaultNotebook is not set\n";
    }

    if (value.noSetNotebookStack.isSet()) {
        out << "    noSetNotebookStack = "
            << value.noSetNotebookStack.ref() << "\n";
    }
    else {
        out << "    noSetNotebookStack is not set\n";
    }

    if (value.noPublishToPublic.isSet()) {
        out << "    noPublishToPublic = "
            << value.noPublishToPublic.ref() << "\n";
    }
    else {
        out << "    noPublishToPublic is not set\n";
    }

    if (value.noPublishToBusinessLibrary.isSet()) {
        out << "    noPublishToBusinessLibrary = "
            << value.noPublishToBusinessLibrary.ref() << "\n";
    }
    else {
        out << "    noPublishToBusinessLibrary is not set\n";
    }

    if (value.noCreateTags.isSet()) {
        out << "    noCreateTags = "
            << value.noCreateTags.ref() << "\n";
    }
    else {
        out << "    noCreateTags is not set\n";
    }

    if (value.noUpdateTags.isSet()) {
        out << "    noUpdateTags = "
            << value.noUpdateTags.ref() << "\n";
    }
    else {
        out << "    noUpdateTags is not set\n";
    }

    if (value.noExpungeTags.isSet()) {
        out << "    noExpungeTags = "
            << value.noExpungeTags.ref() << "\n";
    }
    else {
        out << "    noExpungeTags is not set\n";
    }

    if (value.noSetParentTag.isSet()) {
        out << "    noSetParentTag = "
            << value.noSetParentTag.ref() << "\n";
    }
    else {
        out << "    noSetParentTag is not set\n";
    }

    if (value.noCreateSharedNotebooks.isSet()) {
        out << "    noCreateSharedNotebooks = "
            << value.noCreateSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    noCreateSharedNotebooks is not set\n";
    }

    if (value.updateWhichSharedNotebookRestrictions.isSet()) {
        out << "    updateWhichSharedNotebookRestrictions = "
            << value.updateWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        out << "    updateWhichSharedNotebookRestrictions is not set\n";
    }

    if (value.expungeWhichSharedNotebookRestrictions.isSet()) {
        out << "    expungeWhichSharedNotebookRestrictions = "
            << value.expungeWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        out << "    expungeWhichSharedNotebookRestrictions is not set\n";
    }

    if (value.noShareNotesWithBusiness.isSet()) {
        out << "    noShareNotesWithBusiness = "
            << value.noShareNotesWithBusiness.ref() << "\n";
    }
    else {
        out << "    noShareNotesWithBusiness is not set\n";
    }

    if (value.noRenameNotebook.isSet()) {
        out << "    noRenameNotebook = "
            << value.noRenameNotebook.ref() << "\n";
    }
    else {
        out << "    noRenameNotebook is not set\n";
    }

    if (value.noSetInMyList.isSet()) {
        out << "    noSetInMyList = "
            << value.noSetInMyList.ref() << "\n";
    }
    else {
        out << "    noSetInMyList is not set\n";
    }

    if (value.noChangeContact.isSet()) {
        out << "    noChangeContact = "
            << value.noChangeContact.ref() << "\n";
    }
    else {
        out << "    noChangeContact is not set\n";
    }

    if (value.canMoveToContainerRestrictions.isSet()) {
        out << "    canMoveToContainerRestrictions = "
            << value.canMoveToContainerRestrictions.ref() << "\n";
    }
    else {
        out << "    canMoveToContainerRestrictions is not set\n";
    }

    if (value.noSetReminderNotifyEmail.isSet()) {
        out << "    noSetReminderNotifyEmail = "
            << value.noSetReminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    noSetReminderNotifyEmail is not set\n";
    }

    if (value.noSetReminderNotifyInApp.isSet()) {
        out << "    noSetReminderNotifyInApp = "
            << value.noSetReminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    noSetReminderNotifyInApp is not set\n";
    }

    if (value.noSetRecipientSettingsStack.isSet()) {
        out << "    noSetRecipientSettingsStack = "
            << value.noSetRecipientSettingsStack.ref() << "\n";
    }
    else {
        out << "    noSetRecipientSettingsStack is not set\n";
    }

    if (value.noCanMoveNote.isSet()) {
        out << "    noCanMoveNote = "
            << value.noCanMoveNote.ref() << "\n";
    }
    else {
        out << "    noCanMoveNote is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotebookRestrictions & value)
{
    out << "NotebookRestrictions: {\n";

    if (value.noReadNotes.isSet()) {
        out << "    noReadNotes = "
            << value.noReadNotes.ref() << "\n";
    }
    else {
        out << "    noReadNotes is not set\n";
    }

    if (value.noCreateNotes.isSet()) {
        out << "    noCreateNotes = "
            << value.noCreateNotes.ref() << "\n";
    }
    else {
        out << "    noCreateNotes is not set\n";
    }

    if (value.noUpdateNotes.isSet()) {
        out << "    noUpdateNotes = "
            << value.noUpdateNotes.ref() << "\n";
    }
    else {
        out << "    noUpdateNotes is not set\n";
    }

    if (value.noExpungeNotes.isSet()) {
        out << "    noExpungeNotes = "
            << value.noExpungeNotes.ref() << "\n";
    }
    else {
        out << "    noExpungeNotes is not set\n";
    }

    if (value.noShareNotes.isSet()) {
        out << "    noShareNotes = "
            << value.noShareNotes.ref() << "\n";
    }
    else {
        out << "    noShareNotes is not set\n";
    }

    if (value.noEmailNotes.isSet()) {
        out << "    noEmailNotes = "
            << value.noEmailNotes.ref() << "\n";
    }
    else {
        out << "    noEmailNotes is not set\n";
    }

    if (value.noSendMessageToRecipients.isSet()) {
        out << "    noSendMessageToRecipients = "
            << value.noSendMessageToRecipients.ref() << "\n";
    }
    else {
        out << "    noSendMessageToRecipients is not set\n";
    }

    if (value.noUpdateNotebook.isSet()) {
        out << "    noUpdateNotebook = "
            << value.noUpdateNotebook.ref() << "\n";
    }
    else {
        out << "    noUpdateNotebook is not set\n";
    }

    if (value.noExpungeNotebook.isSet()) {
        out << "    noExpungeNotebook = "
            << value.noExpungeNotebook.ref() << "\n";
    }
    else {
        out << "    noExpungeNotebook is not set\n";
    }

    if (value.noSetDefaultNotebook.isSet()) {
        out << "    noSetDefaultNotebook = "
            << value.noSetDefaultNotebook.ref() << "\n";
    }
    else {
        out << "    noSetDefaultNotebook is not set\n";
    }

    if (value.noSetNotebookStack.isSet()) {
        out << "    noSetNotebookStack = "
            << value.noSetNotebookStack.ref() << "\n";
    }
    else {
        out << "    noSetNotebookStack is not set\n";
    }

    if (value.noPublishToPublic.isSet()) {
        out << "    noPublishToPublic = "
            << value.noPublishToPublic.ref() << "\n";
    }
    else {
        out << "    noPublishToPublic is not set\n";
    }

    if (value.noPublishToBusinessLibrary.isSet()) {
        out << "    noPublishToBusinessLibrary = "
            << value.noPublishToBusinessLibrary.ref() << "\n";
    }
    else {
        out << "    noPublishToBusinessLibrary is not set\n";
    }

    if (value.noCreateTags.isSet()) {
        out << "    noCreateTags = "
            << value.noCreateTags.ref() << "\n";
    }
    else {
        out << "    noCreateTags is not set\n";
    }

    if (value.noUpdateTags.isSet()) {
        out << "    noUpdateTags = "
            << value.noUpdateTags.ref() << "\n";
    }
    else {
        out << "    noUpdateTags is not set\n";
    }

    if (value.noExpungeTags.isSet()) {
        out << "    noExpungeTags = "
            << value.noExpungeTags.ref() << "\n";
    }
    else {
        out << "    noExpungeTags is not set\n";
    }

    if (value.noSetParentTag.isSet()) {
        out << "    noSetParentTag = "
            << value.noSetParentTag.ref() << "\n";
    }
    else {
        out << "    noSetParentTag is not set\n";
    }

    if (value.noCreateSharedNotebooks.isSet()) {
        out << "    noCreateSharedNotebooks = "
            << value.noCreateSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    noCreateSharedNotebooks is not set\n";
    }

    if (value.updateWhichSharedNotebookRestrictions.isSet()) {
        out << "    updateWhichSharedNotebookRestrictions = "
            << value.updateWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        out << "    updateWhichSharedNotebookRestrictions is not set\n";
    }

    if (value.expungeWhichSharedNotebookRestrictions.isSet()) {
        out << "    expungeWhichSharedNotebookRestrictions = "
            << value.expungeWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        out << "    expungeWhichSharedNotebookRestrictions is not set\n";
    }

    if (value.noShareNotesWithBusiness.isSet()) {
        out << "    noShareNotesWithBusiness = "
            << value.noShareNotesWithBusiness.ref() << "\n";
    }
    else {
        out << "    noShareNotesWithBusiness is not set\n";
    }

    if (value.noRenameNotebook.isSet()) {
        out << "    noRenameNotebook = "
            << value.noRenameNotebook.ref() << "\n";
    }
    else {
        out << "    noRenameNotebook is not set\n";
    }

    if (value.noSetInMyList.isSet()) {
        out << "    noSetInMyList = "
            << value.noSetInMyList.ref() << "\n";
    }
    else {
        out << "    noSetInMyList is not set\n";
    }

    if (value.noChangeContact.isSet()) {
        out << "    noChangeContact = "
            << value.noChangeContact.ref() << "\n";
    }
    else {
        out << "    noChangeContact is not set\n";
    }

    if (value.canMoveToContainerRestrictions.isSet()) {
        out << "    canMoveToContainerRestrictions = "
            << value.canMoveToContainerRestrictions.ref() << "\n";
    }
    else {
        out << "    canMoveToContainerRestrictions is not set\n";
    }

    if (value.noSetReminderNotifyEmail.isSet()) {
        out << "    noSetReminderNotifyEmail = "
            << value.noSetReminderNotifyEmail.ref() << "\n";
    }
    else {
        out << "    noSetReminderNotifyEmail is not set\n";
    }

    if (value.noSetReminderNotifyInApp.isSet()) {
        out << "    noSetReminderNotifyInApp = "
            << value.noSetReminderNotifyInApp.ref() << "\n";
    }
    else {
        out << "    noSetReminderNotifyInApp is not set\n";
    }

    if (value.noSetRecipientSettingsStack.isSet()) {
        out << "    noSetRecipientSettingsStack = "
            << value.noSetRecipientSettingsStack.ref() << "\n";
    }
    else {
        out << "    noSetRecipientSettingsStack is not set\n";
    }

    if (value.noCanMoveNote.isSet()) {
        out << "    noCanMoveNote = "
            << value.noCanMoveNote.ref() << "\n";
    }
    else {
        out << "    noCanMoveNote is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebook(ThriftBinaryBufferWriter & w, const Notebook & s) {
    w.writeStructBegin(QStringLiteral("Notebook"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.defaultNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("defaultNotebook"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.defaultNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.serviceCreated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if (s.serviceUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.publishing.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("publishing"),
            ThriftFieldType::T_STRUCT,
            10);
        writePublishing(w, s.publishing.ref());
        w.writeFieldEnd();
    }
    if (s.published.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("published"),
            ThriftFieldType::T_BOOL,
            11);
        w.writeBool(s.published.ref());
        w.writeFieldEnd();
    }
    if (s.stack.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            12);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if (s.sharedNotebookIds.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharedNotebookIds"),
            ThriftFieldType::T_LIST,
            13);
        w.writeListBegin(ThriftFieldType::T_I64, s.sharedNotebookIds.ref().length());
        for(const auto & value: qAsConst(s.sharedNotebookIds.ref())) {
            w.writeI64(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.sharedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharedNotebooks"),
            ThriftFieldType::T_LIST,
            14);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.sharedNotebooks.ref())) {
            writeSharedNotebook(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.businessNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessNotebook"),
            ThriftFieldType::T_STRUCT,
            15);
        writeBusinessNotebook(w, s.businessNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.contact.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            16);
        writeUser(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if (s.restrictions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);
        writeNotebookRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if (s.recipientSettings.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            18);
        writeNotebookRecipientSettings(w, s.recipientSettings.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebook(ThriftBinaryBufferReader & r, Notebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.defaultNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Publishing v;
                readPublishing(r, v);
                s.publishing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.published = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<qint64> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I64) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Notebook.sharedNotebookIds)"));
                for(qint32 i = 0; i < size; i++) {
                    qint64 elem;
                    r.readI64(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotebookIds = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Notebook.sharedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessNotebook v;
                readBusinessNotebook(r, v);
                s.businessNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRestrictions v;
                readNotebookRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(r, v);
                s.recipientSettings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const Notebook & value)
{
    out << "Notebook: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.defaultNotebook.isSet()) {
        out << "    defaultNotebook = "
            << value.defaultNotebook.ref() << "\n";
    }
    else {
        out << "    defaultNotebook is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.publishing.isSet()) {
        out << "    publishing = "
            << value.publishing.ref() << "\n";
    }
    else {
        out << "    publishing is not set\n";
    }

    if (value.published.isSet()) {
        out << "    published = "
            << value.published.ref() << "\n";
    }
    else {
        out << "    published is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.sharedNotebookIds.isSet()) {
        out << "    sharedNotebookIds = "
            << "QList<qint64> {";
        for(const auto & v: value.sharedNotebookIds.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotebookIds is not set\n";
    }

    if (value.sharedNotebooks.isSet()) {
        out << "    sharedNotebooks = "
            << "QList<SharedNotebook> {";
        for(const auto & v: value.sharedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotebooks is not set\n";
    }

    if (value.businessNotebook.isSet()) {
        out << "    businessNotebook = "
            << value.businessNotebook.ref() << "\n";
    }
    else {
        out << "    businessNotebook is not set\n";
    }

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.recipientSettings.isSet()) {
        out << "    recipientSettings = "
            << value.recipientSettings.ref() << "\n";
    }
    else {
        out << "    recipientSettings is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const Notebook & value)
{
    out << "Notebook: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.defaultNotebook.isSet()) {
        out << "    defaultNotebook = "
            << value.defaultNotebook.ref() << "\n";
    }
    else {
        out << "    defaultNotebook is not set\n";
    }

    if (value.serviceCreated.isSet()) {
        out << "    serviceCreated = "
            << value.serviceCreated.ref() << "\n";
    }
    else {
        out << "    serviceCreated is not set\n";
    }

    if (value.serviceUpdated.isSet()) {
        out << "    serviceUpdated = "
            << value.serviceUpdated.ref() << "\n";
    }
    else {
        out << "    serviceUpdated is not set\n";
    }

    if (value.publishing.isSet()) {
        out << "    publishing = "
            << value.publishing.ref() << "\n";
    }
    else {
        out << "    publishing is not set\n";
    }

    if (value.published.isSet()) {
        out << "    published = "
            << value.published.ref() << "\n";
    }
    else {
        out << "    published is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.sharedNotebookIds.isSet()) {
        out << "    sharedNotebookIds = "
            << "QList<qint64> {";
        for(const auto & v: value.sharedNotebookIds.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotebookIds is not set\n";
    }

    if (value.sharedNotebooks.isSet()) {
        out << "    sharedNotebooks = "
            << "QList<SharedNotebook> {";
        for(const auto & v: value.sharedNotebooks.ref()) {
            out << v;
        }
    }
    else {
        out << "    sharedNotebooks is not set\n";
    }

    if (value.businessNotebook.isSet()) {
        out << "    businessNotebook = "
            << value.businessNotebook.ref() << "\n";
    }
    else {
        out << "    businessNotebook is not set\n";
    }

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.restrictions.isSet()) {
        out << "    restrictions = "
            << value.restrictions.ref() << "\n";
    }
    else {
        out << "    restrictions is not set\n";
    }

    if (value.recipientSettings.isSet()) {
        out << "    recipientSettings = "
            << value.recipientSettings.ref() << "\n";
    }
    else {
        out << "    recipientSettings is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeLinkedNotebook(ThriftBinaryBufferWriter & w, const LinkedNotebook & s) {
    w.writeStructBegin(QStringLiteral("LinkedNotebook"));
    if (s.shareName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("shareName"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.shareName.ref());
        w.writeFieldEnd();
    }
    if (s.username.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if (s.shardId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.shardId.ref());
        w.writeFieldEnd();
    }
    if (s.sharedNotebookGlobalId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sharedNotebookGlobalId"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.sharedNotebookGlobalId.ref());
        w.writeFieldEnd();
    }
    if (s.uri.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.uri.ref());
        w.writeFieldEnd();
    }
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            7);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            8);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if (s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            10);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if (s.stack.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            11);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if (s.businessId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            12);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readLinkedNotebook(ThriftBinaryBufferReader & r, LinkedNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shareName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shardId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sharedNotebookGlobalId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.uri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const LinkedNotebook & value)
{
    out << "LinkedNotebook: {\n";

    if (value.shareName.isSet()) {
        out << "    shareName = "
            << value.shareName.ref() << "\n";
    }
    else {
        out << "    shareName is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.shardId.isSet()) {
        out << "    shardId = "
            << value.shardId.ref() << "\n";
    }
    else {
        out << "    shardId is not set\n";
    }

    if (value.sharedNotebookGlobalId.isSet()) {
        out << "    sharedNotebookGlobalId = "
            << value.sharedNotebookGlobalId.ref() << "\n";
    }
    else {
        out << "    sharedNotebookGlobalId is not set\n";
    }

    if (value.uri.isSet()) {
        out << "    uri = "
            << value.uri.ref() << "\n";
    }
    else {
        out << "    uri is not set\n";
    }

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const LinkedNotebook & value)
{
    out << "LinkedNotebook: {\n";

    if (value.shareName.isSet()) {
        out << "    shareName = "
            << value.shareName.ref() << "\n";
    }
    else {
        out << "    shareName is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.shardId.isSet()) {
        out << "    shardId = "
            << value.shardId.ref() << "\n";
    }
    else {
        out << "    shardId is not set\n";
    }

    if (value.sharedNotebookGlobalId.isSet()) {
        out << "    sharedNotebookGlobalId = "
            << value.sharedNotebookGlobalId.ref() << "\n";
    }
    else {
        out << "    sharedNotebookGlobalId is not set\n";
    }

    if (value.uri.isSet()) {
        out << "    uri = "
            << value.uri.ref() << "\n";
    }
    else {
        out << "    uri is not set\n";
    }

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.updateSequenceNum.isSet()) {
        out << "    updateSequenceNum = "
            << value.updateSequenceNum.ref() << "\n";
    }
    else {
        out << "    updateSequenceNum is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.stack.isSet()) {
        out << "    stack = "
            << value.stack.ref() << "\n";
    }
    else {
        out << "    stack is not set\n";
    }

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookDescriptor(ThriftBinaryBufferWriter & w, const NotebookDescriptor & s) {
    w.writeStructBegin(QStringLiteral("NotebookDescriptor"));
    if (s.guid.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if (s.notebookDisplayName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("notebookDisplayName"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.notebookDisplayName.ref());
        w.writeFieldEnd();
    }
    if (s.contactName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contactName"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.contactName.ref());
        w.writeFieldEnd();
    }
    if (s.hasSharedNotebook.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("hasSharedNotebook"),
            ThriftFieldType::T_BOOL,
            4);
        w.writeBool(s.hasSharedNotebook.ref());
        w.writeFieldEnd();
    }
    if (s.joinedUserCount.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("joinedUserCount"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.joinedUserCount.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookDescriptor(ThriftBinaryBufferReader & r, NotebookDescriptor & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookDisplayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contactName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.hasSharedNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.joinedUserCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NotebookDescriptor & value)
{
    out << "NotebookDescriptor: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.notebookDisplayName.isSet()) {
        out << "    notebookDisplayName = "
            << value.notebookDisplayName.ref() << "\n";
    }
    else {
        out << "    notebookDisplayName is not set\n";
    }

    if (value.contactName.isSet()) {
        out << "    contactName = "
            << value.contactName.ref() << "\n";
    }
    else {
        out << "    contactName is not set\n";
    }

    if (value.hasSharedNotebook.isSet()) {
        out << "    hasSharedNotebook = "
            << value.hasSharedNotebook.ref() << "\n";
    }
    else {
        out << "    hasSharedNotebook is not set\n";
    }

    if (value.joinedUserCount.isSet()) {
        out << "    joinedUserCount = "
            << value.joinedUserCount.ref() << "\n";
    }
    else {
        out << "    joinedUserCount is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NotebookDescriptor & value)
{
    out << "NotebookDescriptor: {\n";

    if (value.guid.isSet()) {
        out << "    guid = "
            << value.guid.ref() << "\n";
    }
    else {
        out << "    guid is not set\n";
    }

    if (value.notebookDisplayName.isSet()) {
        out << "    notebookDisplayName = "
            << value.notebookDisplayName.ref() << "\n";
    }
    else {
        out << "    notebookDisplayName is not set\n";
    }

    if (value.contactName.isSet()) {
        out << "    contactName = "
            << value.contactName.ref() << "\n";
    }
    else {
        out << "    contactName is not set\n";
    }

    if (value.hasSharedNotebook.isSet()) {
        out << "    hasSharedNotebook = "
            << value.hasSharedNotebook.ref() << "\n";
    }
    else {
        out << "    hasSharedNotebook is not set\n";
    }

    if (value.joinedUserCount.isSet()) {
        out << "    joinedUserCount = "
            << value.joinedUserCount.ref() << "\n";
    }
    else {
        out << "    joinedUserCount is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUserProfile(ThriftBinaryBufferWriter & w, const UserProfile & s) {
    w.writeStructBegin(QStringLiteral("UserProfile"));
    if (s.id.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.id.ref());
        w.writeFieldEnd();
    }
    if (s.name.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if (s.email.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if (s.username.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if (s.attributes.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            5);
        writeBusinessUserAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if (s.joined.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("joined"),
            ThriftFieldType::T_I64,
            6);
        w.writeI64(s.joined.ref());
        w.writeFieldEnd();
    }
    if (s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if (s.photoUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            8);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if (s.role.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            9);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if (s.status.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            10);
        w.writeI32(static_cast<qint32>(s.status.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserProfile(ThriftBinaryBufferReader & r, UserProfile & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserAttributes v;
                readBusinessUserAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.joined = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserStatus v;
                readEnumBusinessUserStatus(r, v);
                s.status = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UserProfile & value)
{
    out << "UserProfile: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.joined.isSet()) {
        out << "    joined = "
            << value.joined.ref() << "\n";
    }
    else {
        out << "    joined is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.status.isSet()) {
        out << "    status = "
            << value.status.ref() << "\n";
    }
    else {
        out << "    status is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UserProfile & value)
{
    out << "UserProfile: {\n";

    if (value.id.isSet()) {
        out << "    id = "
            << value.id.ref() << "\n";
    }
    else {
        out << "    id is not set\n";
    }

    if (value.name.isSet()) {
        out << "    name = "
            << value.name.ref() << "\n";
    }
    else {
        out << "    name is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.attributes.isSet()) {
        out << "    attributes = "
            << value.attributes.ref() << "\n";
    }
    else {
        out << "    attributes is not set\n";
    }

    if (value.joined.isSet()) {
        out << "    joined = "
            << value.joined.ref() << "\n";
    }
    else {
        out << "    joined is not set\n";
    }

    if (value.photoLastUpdated.isSet()) {
        out << "    photoLastUpdated = "
            << value.photoLastUpdated.ref() << "\n";
    }
    else {
        out << "    photoLastUpdated is not set\n";
    }

    if (value.photoUrl.isSet()) {
        out << "    photoUrl = "
            << value.photoUrl.ref() << "\n";
    }
    else {
        out << "    photoUrl is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.status.isSet()) {
        out << "    status = "
            << value.status.ref() << "\n";
    }
    else {
        out << "    status is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedContentImage(ThriftBinaryBufferWriter & w, const RelatedContentImage & s) {
    w.writeStructBegin(QStringLiteral("RelatedContentImage"));
    if (s.url.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.url.ref());
        w.writeFieldEnd();
    }
    if (s.width.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I32,
            2);
        w.writeI32(s.width.ref());
        w.writeFieldEnd();
    }
    if (s.height.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(s.height.ref());
        w.writeFieldEnd();
    }
    if (s.pixelRatio.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("pixelRatio"),
            ThriftFieldType::T_DOUBLE,
            4);
        w.writeDouble(s.pixelRatio.ref());
        w.writeFieldEnd();
    }
    if (s.fileSize.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("fileSize"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.fileSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedContentImage(ThriftBinaryBufferReader & r, RelatedContentImage & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.url = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.width = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.height = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.pixelRatio = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.fileSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedContentImage & value)
{
    out << "RelatedContentImage: {\n";

    if (value.url.isSet()) {
        out << "    url = "
            << value.url.ref() << "\n";
    }
    else {
        out << "    url is not set\n";
    }

    if (value.width.isSet()) {
        out << "    width = "
            << value.width.ref() << "\n";
    }
    else {
        out << "    width is not set\n";
    }

    if (value.height.isSet()) {
        out << "    height = "
            << value.height.ref() << "\n";
    }
    else {
        out << "    height is not set\n";
    }

    if (value.pixelRatio.isSet()) {
        out << "    pixelRatio = "
            << value.pixelRatio.ref() << "\n";
    }
    else {
        out << "    pixelRatio is not set\n";
    }

    if (value.fileSize.isSet()) {
        out << "    fileSize = "
            << value.fileSize.ref() << "\n";
    }
    else {
        out << "    fileSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedContentImage & value)
{
    out << "RelatedContentImage: {\n";

    if (value.url.isSet()) {
        out << "    url = "
            << value.url.ref() << "\n";
    }
    else {
        out << "    url is not set\n";
    }

    if (value.width.isSet()) {
        out << "    width = "
            << value.width.ref() << "\n";
    }
    else {
        out << "    width is not set\n";
    }

    if (value.height.isSet()) {
        out << "    height = "
            << value.height.ref() << "\n";
    }
    else {
        out << "    height is not set\n";
    }

    if (value.pixelRatio.isSet()) {
        out << "    pixelRatio = "
            << value.pixelRatio.ref() << "\n";
    }
    else {
        out << "    pixelRatio is not set\n";
    }

    if (value.fileSize.isSet()) {
        out << "    fileSize = "
            << value.fileSize.ref() << "\n";
    }
    else {
        out << "    fileSize is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedContent(ThriftBinaryBufferWriter & w, const RelatedContent & s) {
    w.writeStructBegin(QStringLiteral("RelatedContent"));
    if (s.contentId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentId"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.contentId.ref());
        w.writeFieldEnd();
    }
    if (s.title.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if (s.url.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.url.ref());
        w.writeFieldEnd();
    }
    if (s.sourceId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceId"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.sourceId.ref());
        w.writeFieldEnd();
    }
    if (s.sourceUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceUrl"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.sourceUrl.ref());
        w.writeFieldEnd();
    }
    if (s.sourceFaviconUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceFaviconUrl"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.sourceFaviconUrl.ref());
        w.writeFieldEnd();
    }
    if (s.sourceName.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("sourceName"),
            ThriftFieldType::T_STRING,
            7);
        w.writeString(s.sourceName.ref());
        w.writeFieldEnd();
    }
    if (s.date.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("date"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.date.ref());
        w.writeFieldEnd();
    }
    if (s.teaser.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("teaser"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.teaser.ref());
        w.writeFieldEnd();
    }
    if (s.thumbnails.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("thumbnails"),
            ThriftFieldType::T_LIST,
            10);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.thumbnails.ref().length());
        for(const auto & value: qAsConst(s.thumbnails.ref())) {
            writeRelatedContentImage(w, value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if (s.contentType.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contentType"),
            ThriftFieldType::T_I32,
            11);
        w.writeI32(static_cast<qint32>(s.contentType.ref()));
        w.writeFieldEnd();
    }
    if (s.accessType.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("accessType"),
            ThriftFieldType::T_I32,
            12);
        w.writeI32(static_cast<qint32>(s.accessType.ref()));
        w.writeFieldEnd();
    }
    if (s.visibleUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("visibleUrl"),
            ThriftFieldType::T_STRING,
            13);
        w.writeString(s.visibleUrl.ref());
        w.writeFieldEnd();
    }
    if (s.clipUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("clipUrl"),
            ThriftFieldType::T_STRING,
            14);
        w.writeString(s.clipUrl.ref());
        w.writeFieldEnd();
    }
    if (s.contact.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            15);
        writeContact(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if (s.authors.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("authors"),
            ThriftFieldType::T_LIST,
            16);
        w.writeListBegin(ThriftFieldType::T_STRING, s.authors.ref().length());
        for(const auto & value: qAsConst(s.authors.ref())) {
            w.writeString(value);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedContent(ThriftBinaryBufferReader & r, RelatedContent & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contentId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.url = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceFaviconUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.date = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.teaser = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContentImage> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedContent.thumbnails)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentImage elem;
                    readRelatedContentImage(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.thumbnails = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentType v;
                readEnumRelatedContentType(r, v);
                s.contentType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentAccess v;
                readEnumRelatedContentAccess(r, v);
                s.accessType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.visibleUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.clipUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedContent.authors)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.authors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedContent & value)
{
    out << "RelatedContent: {\n";

    if (value.contentId.isSet()) {
        out << "    contentId = "
            << value.contentId.ref() << "\n";
    }
    else {
        out << "    contentId is not set\n";
    }

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.url.isSet()) {
        out << "    url = "
            << value.url.ref() << "\n";
    }
    else {
        out << "    url is not set\n";
    }

    if (value.sourceId.isSet()) {
        out << "    sourceId = "
            << value.sourceId.ref() << "\n";
    }
    else {
        out << "    sourceId is not set\n";
    }

    if (value.sourceUrl.isSet()) {
        out << "    sourceUrl = "
            << value.sourceUrl.ref() << "\n";
    }
    else {
        out << "    sourceUrl is not set\n";
    }

    if (value.sourceFaviconUrl.isSet()) {
        out << "    sourceFaviconUrl = "
            << value.sourceFaviconUrl.ref() << "\n";
    }
    else {
        out << "    sourceFaviconUrl is not set\n";
    }

    if (value.sourceName.isSet()) {
        out << "    sourceName = "
            << value.sourceName.ref() << "\n";
    }
    else {
        out << "    sourceName is not set\n";
    }

    if (value.date.isSet()) {
        out << "    date = "
            << value.date.ref() << "\n";
    }
    else {
        out << "    date is not set\n";
    }

    if (value.teaser.isSet()) {
        out << "    teaser = "
            << value.teaser.ref() << "\n";
    }
    else {
        out << "    teaser is not set\n";
    }

    if (value.thumbnails.isSet()) {
        out << "    thumbnails = "
            << "QList<RelatedContentImage> {";
        for(const auto & v: value.thumbnails.ref()) {
            out << v;
        }
    }
    else {
        out << "    thumbnails is not set\n";
    }

    if (value.contentType.isSet()) {
        out << "    contentType = "
            << value.contentType.ref() << "\n";
    }
    else {
        out << "    contentType is not set\n";
    }

    if (value.accessType.isSet()) {
        out << "    accessType = "
            << value.accessType.ref() << "\n";
    }
    else {
        out << "    accessType is not set\n";
    }

    if (value.visibleUrl.isSet()) {
        out << "    visibleUrl = "
            << value.visibleUrl.ref() << "\n";
    }
    else {
        out << "    visibleUrl is not set\n";
    }

    if (value.clipUrl.isSet()) {
        out << "    clipUrl = "
            << value.clipUrl.ref() << "\n";
    }
    else {
        out << "    clipUrl is not set\n";
    }

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.authors.isSet()) {
        out << "    authors = "
            << "QList<QString> {";
        for(const auto & v: value.authors.ref()) {
            out << v;
        }
    }
    else {
        out << "    authors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedContent & value)
{
    out << "RelatedContent: {\n";

    if (value.contentId.isSet()) {
        out << "    contentId = "
            << value.contentId.ref() << "\n";
    }
    else {
        out << "    contentId is not set\n";
    }

    if (value.title.isSet()) {
        out << "    title = "
            << value.title.ref() << "\n";
    }
    else {
        out << "    title is not set\n";
    }

    if (value.url.isSet()) {
        out << "    url = "
            << value.url.ref() << "\n";
    }
    else {
        out << "    url is not set\n";
    }

    if (value.sourceId.isSet()) {
        out << "    sourceId = "
            << value.sourceId.ref() << "\n";
    }
    else {
        out << "    sourceId is not set\n";
    }

    if (value.sourceUrl.isSet()) {
        out << "    sourceUrl = "
            << value.sourceUrl.ref() << "\n";
    }
    else {
        out << "    sourceUrl is not set\n";
    }

    if (value.sourceFaviconUrl.isSet()) {
        out << "    sourceFaviconUrl = "
            << value.sourceFaviconUrl.ref() << "\n";
    }
    else {
        out << "    sourceFaviconUrl is not set\n";
    }

    if (value.sourceName.isSet()) {
        out << "    sourceName = "
            << value.sourceName.ref() << "\n";
    }
    else {
        out << "    sourceName is not set\n";
    }

    if (value.date.isSet()) {
        out << "    date = "
            << value.date.ref() << "\n";
    }
    else {
        out << "    date is not set\n";
    }

    if (value.teaser.isSet()) {
        out << "    teaser = "
            << value.teaser.ref() << "\n";
    }
    else {
        out << "    teaser is not set\n";
    }

    if (value.thumbnails.isSet()) {
        out << "    thumbnails = "
            << "QList<RelatedContentImage> {";
        for(const auto & v: value.thumbnails.ref()) {
            out << v;
        }
    }
    else {
        out << "    thumbnails is not set\n";
    }

    if (value.contentType.isSet()) {
        out << "    contentType = "
            << value.contentType.ref() << "\n";
    }
    else {
        out << "    contentType is not set\n";
    }

    if (value.accessType.isSet()) {
        out << "    accessType = "
            << value.accessType.ref() << "\n";
    }
    else {
        out << "    accessType is not set\n";
    }

    if (value.visibleUrl.isSet()) {
        out << "    visibleUrl = "
            << value.visibleUrl.ref() << "\n";
    }
    else {
        out << "    visibleUrl is not set\n";
    }

    if (value.clipUrl.isSet()) {
        out << "    clipUrl = "
            << value.clipUrl.ref() << "\n";
    }
    else {
        out << "    clipUrl is not set\n";
    }

    if (value.contact.isSet()) {
        out << "    contact = "
            << value.contact.ref() << "\n";
    }
    else {
        out << "    contact is not set\n";
    }

    if (value.authors.isSet()) {
        out << "    authors = "
            << "QList<QString> {";
        for(const auto & v: value.authors.ref()) {
            out << v;
        }
    }
    else {
        out << "    authors is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessInvitation(ThriftBinaryBufferWriter & w, const BusinessInvitation & s) {
    w.writeStructBegin(QStringLiteral("BusinessInvitation"));
    if (s.businessId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if (s.email.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if (s.role.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if (s.status.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            4);
        w.writeI32(static_cast<qint32>(s.status.ref()));
        w.writeFieldEnd();
    }
    if (s.requesterId.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("requesterId"),
            ThriftFieldType::T_I32,
            5);
        w.writeI32(s.requesterId.ref());
        w.writeFieldEnd();
    }
    if (s.fromWorkChat.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("fromWorkChat"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.fromWorkChat.ref());
        w.writeFieldEnd();
    }
    if (s.created.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            7);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if (s.mostRecentReminder.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("mostRecentReminder"),
            ThriftFieldType::T_I64,
            8);
        w.writeI64(s.mostRecentReminder.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessInvitation(ThriftBinaryBufferReader & r, BusinessInvitation & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessInvitationStatus v;
                readEnumBusinessInvitationStatus(r, v);
                s.status = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.requesterId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.fromWorkChat = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.mostRecentReminder = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessInvitation & value)
{
    out << "BusinessInvitation: {\n";

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.status.isSet()) {
        out << "    status = "
            << value.status.ref() << "\n";
    }
    else {
        out << "    status is not set\n";
    }

    if (value.requesterId.isSet()) {
        out << "    requesterId = "
            << value.requesterId.ref() << "\n";
    }
    else {
        out << "    requesterId is not set\n";
    }

    if (value.fromWorkChat.isSet()) {
        out << "    fromWorkChat = "
            << value.fromWorkChat.ref() << "\n";
    }
    else {
        out << "    fromWorkChat is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.mostRecentReminder.isSet()) {
        out << "    mostRecentReminder = "
            << value.mostRecentReminder.ref() << "\n";
    }
    else {
        out << "    mostRecentReminder is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessInvitation & value)
{
    out << "BusinessInvitation: {\n";

    if (value.businessId.isSet()) {
        out << "    businessId = "
            << value.businessId.ref() << "\n";
    }
    else {
        out << "    businessId is not set\n";
    }

    if (value.email.isSet()) {
        out << "    email = "
            << value.email.ref() << "\n";
    }
    else {
        out << "    email is not set\n";
    }

    if (value.role.isSet()) {
        out << "    role = "
            << value.role.ref() << "\n";
    }
    else {
        out << "    role is not set\n";
    }

    if (value.status.isSet()) {
        out << "    status = "
            << value.status.ref() << "\n";
    }
    else {
        out << "    status is not set\n";
    }

    if (value.requesterId.isSet()) {
        out << "    requesterId = "
            << value.requesterId.ref() << "\n";
    }
    else {
        out << "    requesterId is not set\n";
    }

    if (value.fromWorkChat.isSet()) {
        out << "    fromWorkChat = "
            << value.fromWorkChat.ref() << "\n";
    }
    else {
        out << "    fromWorkChat is not set\n";
    }

    if (value.created.isSet()) {
        out << "    created = "
            << value.created.ref() << "\n";
    }
    else {
        out << "    created is not set\n";
    }

    if (value.mostRecentReminder.isSet()) {
        out << "    mostRecentReminder = "
            << value.mostRecentReminder.ref() << "\n";
    }
    else {
        out << "    mostRecentReminder is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUserIdentity(ThriftBinaryBufferWriter & w, const UserIdentity & s) {
    w.writeStructBegin(QStringLiteral("UserIdentity"));
    if (s.type.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            1);
        w.writeI32(static_cast<qint32>(s.type.ref()));
        w.writeFieldEnd();
    }
    if (s.stringIdentifier.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("stringIdentifier"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.stringIdentifier.ref());
        w.writeFieldEnd();
    }
    if (s.longIdentifier.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("longIdentifier"),
            ThriftFieldType::T_I64,
            3);
        w.writeI64(s.longIdentifier.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserIdentity(ThriftBinaryBufferReader & r, UserIdentity & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserIdentityType v;
                readEnumUserIdentityType(r, v);
                s.type = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stringIdentifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.longIdentifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UserIdentity & value)
{
    out << "UserIdentity: {\n";

    if (value.type.isSet()) {
        out << "    type = "
            << value.type.ref() << "\n";
    }
    else {
        out << "    type is not set\n";
    }

    if (value.stringIdentifier.isSet()) {
        out << "    stringIdentifier = "
            << value.stringIdentifier.ref() << "\n";
    }
    else {
        out << "    stringIdentifier is not set\n";
    }

    if (value.longIdentifier.isSet()) {
        out << "    longIdentifier = "
            << value.longIdentifier.ref() << "\n";
    }
    else {
        out << "    longIdentifier is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UserIdentity & value)
{
    out << "UserIdentity: {\n";

    if (value.type.isSet()) {
        out << "    type = "
            << value.type.ref() << "\n";
    }
    else {
        out << "    type is not set\n";
    }

    if (value.stringIdentifier.isSet()) {
        out << "    stringIdentifier = "
            << value.stringIdentifier.ref() << "\n";
    }
    else {
        out << "    stringIdentifier is not set\n";
    }

    if (value.longIdentifier.isSet()) {
        out << "    longIdentifier = "
            << value.longIdentifier.ref() << "\n";
    }
    else {
        out << "    longIdentifier is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writePublicUserInfo(ThriftBinaryBufferWriter & w, const PublicUserInfo & s) {
    w.writeStructBegin(QStringLiteral("PublicUserInfo"));
    w.writeFieldBegin(
        QStringLiteral("userId"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(s.userId);
    w.writeFieldEnd();
    if (s.serviceLevel.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            7);
        w.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        w.writeFieldEnd();
    }
    if (s.username.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if (s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readPublicUserInfo(ThriftBinaryBufferReader & r, PublicUserInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool userId_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                userId_isset = true;
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(r, v);
                s.serviceLevel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!userId_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("PublicUserInfo.userId has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const PublicUserInfo & value)
{
    out << "PublicUserInfo: {\n";
    out << "    userId = "
        << "UserID" << "\n";

    if (value.serviceLevel.isSet()) {
        out << "    serviceLevel = "
            << value.serviceLevel.ref() << "\n";
    }
    else {
        out << "    serviceLevel is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const PublicUserInfo & value)
{
    out << "PublicUserInfo: {\n";
    out << "    userId = "
        << "UserID" << "\n";

    if (value.serviceLevel.isSet()) {
        out << "    serviceLevel = "
            << value.serviceLevel.ref() << "\n";
    }
    else {
        out << "    serviceLevel is not set\n";
    }

    if (value.username.isSet()) {
        out << "    username = "
            << value.username.ref() << "\n";
    }
    else {
        out << "    username is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeUserUrls(ThriftBinaryBufferWriter & w, const UserUrls & s) {
    w.writeStructBegin(QStringLiteral("UserUrls"));
    if (s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if (s.userStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userStoreUrl"),
            ThriftFieldType::T_STRING,
            3);
        w.writeString(s.userStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.utilityUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("utilityUrl"),
            ThriftFieldType::T_STRING,
            4);
        w.writeString(s.utilityUrl.ref());
        w.writeFieldEnd();
    }
    if (s.messageStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("messageStoreUrl"),
            ThriftFieldType::T_STRING,
            5);
        w.writeString(s.messageStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.userWebSocketUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("userWebSocketUrl"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.userWebSocketUrl.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserUrls(ThriftBinaryBufferReader & r, UserUrls & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.userStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.utilityUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.messageStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.userWebSocketUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UserUrls & value)
{
    out << "UserUrls: {\n";

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.userStoreUrl.isSet()) {
        out << "    userStoreUrl = "
            << value.userStoreUrl.ref() << "\n";
    }
    else {
        out << "    userStoreUrl is not set\n";
    }

    if (value.utilityUrl.isSet()) {
        out << "    utilityUrl = "
            << value.utilityUrl.ref() << "\n";
    }
    else {
        out << "    utilityUrl is not set\n";
    }

    if (value.messageStoreUrl.isSet()) {
        out << "    messageStoreUrl = "
            << value.messageStoreUrl.ref() << "\n";
    }
    else {
        out << "    messageStoreUrl is not set\n";
    }

    if (value.userWebSocketUrl.isSet()) {
        out << "    userWebSocketUrl = "
            << value.userWebSocketUrl.ref() << "\n";
    }
    else {
        out << "    userWebSocketUrl is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UserUrls & value)
{
    out << "UserUrls: {\n";

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.userStoreUrl.isSet()) {
        out << "    userStoreUrl = "
            << value.userStoreUrl.ref() << "\n";
    }
    else {
        out << "    userStoreUrl is not set\n";
    }

    if (value.utilityUrl.isSet()) {
        out << "    utilityUrl = "
            << value.utilityUrl.ref() << "\n";
    }
    else {
        out << "    utilityUrl is not set\n";
    }

    if (value.messageStoreUrl.isSet()) {
        out << "    messageStoreUrl = "
            << value.messageStoreUrl.ref() << "\n";
    }
    else {
        out << "    messageStoreUrl is not set\n";
    }

    if (value.userWebSocketUrl.isSet()) {
        out << "    userWebSocketUrl = "
            << value.userWebSocketUrl.ref() << "\n";
    }
    else {
        out << "    userWebSocketUrl is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeAuthenticationResult(ThriftBinaryBufferWriter & w, const AuthenticationResult & s) {
    w.writeStructBegin(QStringLiteral("AuthenticationResult"));
    w.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        2);
    w.writeString(s.authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("expiration"),
        ThriftFieldType::T_I64,
        3);
    w.writeI64(s.expiration);
    w.writeFieldEnd();
    if (s.user.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("user"),
            ThriftFieldType::T_STRUCT,
            4);
        writeUser(w, s.user.ref());
        w.writeFieldEnd();
    }
    if (s.publicUserInfo.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("publicUserInfo"),
            ThriftFieldType::T_STRUCT,
            5);
        writePublicUserInfo(w, s.publicUserInfo.ref());
        w.writeFieldEnd();
    }
    if (s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            6);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if (s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            7);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if (s.secondFactorRequired.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("secondFactorRequired"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.secondFactorRequired.ref());
        w.writeFieldEnd();
    }
    if (s.secondFactorDeliveryHint.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("secondFactorDeliveryHint"),
            ThriftFieldType::T_STRING,
            9);
        w.writeString(s.secondFactorDeliveryHint.ref());
        w.writeFieldEnd();
    }
    if (s.urls.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("urls"),
            ThriftFieldType::T_STRUCT,
            10);
        writeUserUrls(w, s.urls.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAuthenticationResult(ThriftBinaryBufferReader & r, AuthenticationResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool authenticationToken_isset = false;
    bool expiration_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                authenticationToken_isset = true;
                QString v;
                r.readString(v);
                s.authenticationToken = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                expiration_isset = true;
                qint64 v;
                r.readI64(v);
                s.expiration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(r, v);
                s.user = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                PublicUserInfo v;
                readPublicUserInfo(r, v);
                s.publicUserInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.secondFactorRequired = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.secondFactorDeliveryHint = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserUrls v;
                readUserUrls(r, v);
                s.urls = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.currentTime has no value"));
    if(!authenticationToken_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.authenticationToken has no value"));
    if(!expiration_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.expiration has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const AuthenticationResult & value)
{
    out << "AuthenticationResult: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";
    out << "    authenticationToken = "
        << "QString" << "\n";
    out << "    expiration = "
        << "Timestamp" << "\n";

    if (value.user.isSet()) {
        out << "    user = "
            << value.user.ref() << "\n";
    }
    else {
        out << "    user is not set\n";
    }

    if (value.publicUserInfo.isSet()) {
        out << "    publicUserInfo = "
            << value.publicUserInfo.ref() << "\n";
    }
    else {
        out << "    publicUserInfo is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.secondFactorRequired.isSet()) {
        out << "    secondFactorRequired = "
            << value.secondFactorRequired.ref() << "\n";
    }
    else {
        out << "    secondFactorRequired is not set\n";
    }

    if (value.secondFactorDeliveryHint.isSet()) {
        out << "    secondFactorDeliveryHint = "
            << value.secondFactorDeliveryHint.ref() << "\n";
    }
    else {
        out << "    secondFactorDeliveryHint is not set\n";
    }

    if (value.urls.isSet()) {
        out << "    urls = "
            << value.urls.ref() << "\n";
    }
    else {
        out << "    urls is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const AuthenticationResult & value)
{
    out << "AuthenticationResult: {\n";
    out << "    currentTime = "
        << "Timestamp" << "\n";
    out << "    authenticationToken = "
        << "QString" << "\n";
    out << "    expiration = "
        << "Timestamp" << "\n";

    if (value.user.isSet()) {
        out << "    user = "
            << value.user.ref() << "\n";
    }
    else {
        out << "    user is not set\n";
    }

    if (value.publicUserInfo.isSet()) {
        out << "    publicUserInfo = "
            << value.publicUserInfo.ref() << "\n";
    }
    else {
        out << "    publicUserInfo is not set\n";
    }

    if (value.noteStoreUrl.isSet()) {
        out << "    noteStoreUrl = "
            << value.noteStoreUrl.ref() << "\n";
    }
    else {
        out << "    noteStoreUrl is not set\n";
    }

    if (value.webApiUrlPrefix.isSet()) {
        out << "    webApiUrlPrefix = "
            << value.webApiUrlPrefix.ref() << "\n";
    }
    else {
        out << "    webApiUrlPrefix is not set\n";
    }

    if (value.secondFactorRequired.isSet()) {
        out << "    secondFactorRequired = "
            << value.secondFactorRequired.ref() << "\n";
    }
    else {
        out << "    secondFactorRequired is not set\n";
    }

    if (value.secondFactorDeliveryHint.isSet()) {
        out << "    secondFactorDeliveryHint = "
            << value.secondFactorDeliveryHint.ref() << "\n";
    }
    else {
        out << "    secondFactorDeliveryHint is not set\n";
    }

    if (value.urls.isSet()) {
        out << "    urls = "
            << value.urls.ref() << "\n";
    }
    else {
        out << "    urls is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapSettings(ThriftBinaryBufferWriter & w, const BootstrapSettings & s) {
    w.writeStructBegin(QStringLiteral("BootstrapSettings"));
    w.writeFieldBegin(
        QStringLiteral("serviceHost"),
        ThriftFieldType::T_STRING,
        1);
    w.writeString(s.serviceHost);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("marketingUrl"),
        ThriftFieldType::T_STRING,
        2);
    w.writeString(s.marketingUrl);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("supportUrl"),
        ThriftFieldType::T_STRING,
        3);
    w.writeString(s.supportUrl);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("accountEmailDomain"),
        ThriftFieldType::T_STRING,
        4);
    w.writeString(s.accountEmailDomain);
    w.writeFieldEnd();
    if (s.enableFacebookSharing.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableFacebookSharing"),
            ThriftFieldType::T_BOOL,
            5);
        w.writeBool(s.enableFacebookSharing.ref());
        w.writeFieldEnd();
    }
    if (s.enableGiftSubscriptions.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableGiftSubscriptions"),
            ThriftFieldType::T_BOOL,
            6);
        w.writeBool(s.enableGiftSubscriptions.ref());
        w.writeFieldEnd();
    }
    if (s.enableSupportTickets.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableSupportTickets"),
            ThriftFieldType::T_BOOL,
            7);
        w.writeBool(s.enableSupportTickets.ref());
        w.writeFieldEnd();
    }
    if (s.enableSharedNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);
        w.writeBool(s.enableSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.enableSingleNoteSharing.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableSingleNoteSharing"),
            ThriftFieldType::T_BOOL,
            9);
        w.writeBool(s.enableSingleNoteSharing.ref());
        w.writeFieldEnd();
    }
    if (s.enableSponsoredAccounts.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableSponsoredAccounts"),
            ThriftFieldType::T_BOOL,
            10);
        w.writeBool(s.enableSponsoredAccounts.ref());
        w.writeFieldEnd();
    }
    if (s.enableTwitterSharing.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableTwitterSharing"),
            ThriftFieldType::T_BOOL,
            11);
        w.writeBool(s.enableTwitterSharing.ref());
        w.writeFieldEnd();
    }
    if (s.enableLinkedInSharing.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableLinkedInSharing"),
            ThriftFieldType::T_BOOL,
            12);
        w.writeBool(s.enableLinkedInSharing.ref());
        w.writeFieldEnd();
    }
    if (s.enablePublicNotebooks.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enablePublicNotebooks"),
            ThriftFieldType::T_BOOL,
            13);
        w.writeBool(s.enablePublicNotebooks.ref());
        w.writeFieldEnd();
    }
    if (s.enableGoogle.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("enableGoogle"),
            ThriftFieldType::T_BOOL,
            16);
        w.writeBool(s.enableGoogle.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapSettings(ThriftBinaryBufferReader & r, BootstrapSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool serviceHost_isset = false;
    bool marketingUrl_isset = false;
    bool supportUrl_isset = false;
    bool accountEmailDomain_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                serviceHost_isset = true;
                QString v;
                r.readString(v);
                s.serviceHost = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                marketingUrl_isset = true;
                QString v;
                r.readString(v);
                s.marketingUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                supportUrl_isset = true;
                QString v;
                r.readString(v);
                s.supportUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                accountEmailDomain_isset = true;
                QString v;
                r.readString(v);
                s.accountEmailDomain = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableFacebookSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableGiftSubscriptions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSupportTickets = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSingleNoteSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSponsoredAccounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableTwitterSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableLinkedInSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enablePublicNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableGoogle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!serviceHost_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.serviceHost has no value"));
    if(!marketingUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.marketingUrl has no value"));
    if(!supportUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.supportUrl has no value"));
    if(!accountEmailDomain_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.accountEmailDomain has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BootstrapSettings & value)
{
    out << "BootstrapSettings: {\n";
    out << "    serviceHost = "
        << "QString" << "\n";
    out << "    marketingUrl = "
        << "QString" << "\n";
    out << "    supportUrl = "
        << "QString" << "\n";
    out << "    accountEmailDomain = "
        << "QString" << "\n";

    if (value.enableFacebookSharing.isSet()) {
        out << "    enableFacebookSharing = "
            << value.enableFacebookSharing.ref() << "\n";
    }
    else {
        out << "    enableFacebookSharing is not set\n";
    }

    if (value.enableGiftSubscriptions.isSet()) {
        out << "    enableGiftSubscriptions = "
            << value.enableGiftSubscriptions.ref() << "\n";
    }
    else {
        out << "    enableGiftSubscriptions is not set\n";
    }

    if (value.enableSupportTickets.isSet()) {
        out << "    enableSupportTickets = "
            << value.enableSupportTickets.ref() << "\n";
    }
    else {
        out << "    enableSupportTickets is not set\n";
    }

    if (value.enableSharedNotebooks.isSet()) {
        out << "    enableSharedNotebooks = "
            << value.enableSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    enableSharedNotebooks is not set\n";
    }

    if (value.enableSingleNoteSharing.isSet()) {
        out << "    enableSingleNoteSharing = "
            << value.enableSingleNoteSharing.ref() << "\n";
    }
    else {
        out << "    enableSingleNoteSharing is not set\n";
    }

    if (value.enableSponsoredAccounts.isSet()) {
        out << "    enableSponsoredAccounts = "
            << value.enableSponsoredAccounts.ref() << "\n";
    }
    else {
        out << "    enableSponsoredAccounts is not set\n";
    }

    if (value.enableTwitterSharing.isSet()) {
        out << "    enableTwitterSharing = "
            << value.enableTwitterSharing.ref() << "\n";
    }
    else {
        out << "    enableTwitterSharing is not set\n";
    }

    if (value.enableLinkedInSharing.isSet()) {
        out << "    enableLinkedInSharing = "
            << value.enableLinkedInSharing.ref() << "\n";
    }
    else {
        out << "    enableLinkedInSharing is not set\n";
    }

    if (value.enablePublicNotebooks.isSet()) {
        out << "    enablePublicNotebooks = "
            << value.enablePublicNotebooks.ref() << "\n";
    }
    else {
        out << "    enablePublicNotebooks is not set\n";
    }

    if (value.enableGoogle.isSet()) {
        out << "    enableGoogle = "
            << value.enableGoogle.ref() << "\n";
    }
    else {
        out << "    enableGoogle is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BootstrapSettings & value)
{
    out << "BootstrapSettings: {\n";
    out << "    serviceHost = "
        << "QString" << "\n";
    out << "    marketingUrl = "
        << "QString" << "\n";
    out << "    supportUrl = "
        << "QString" << "\n";
    out << "    accountEmailDomain = "
        << "QString" << "\n";

    if (value.enableFacebookSharing.isSet()) {
        out << "    enableFacebookSharing = "
            << value.enableFacebookSharing.ref() << "\n";
    }
    else {
        out << "    enableFacebookSharing is not set\n";
    }

    if (value.enableGiftSubscriptions.isSet()) {
        out << "    enableGiftSubscriptions = "
            << value.enableGiftSubscriptions.ref() << "\n";
    }
    else {
        out << "    enableGiftSubscriptions is not set\n";
    }

    if (value.enableSupportTickets.isSet()) {
        out << "    enableSupportTickets = "
            << value.enableSupportTickets.ref() << "\n";
    }
    else {
        out << "    enableSupportTickets is not set\n";
    }

    if (value.enableSharedNotebooks.isSet()) {
        out << "    enableSharedNotebooks = "
            << value.enableSharedNotebooks.ref() << "\n";
    }
    else {
        out << "    enableSharedNotebooks is not set\n";
    }

    if (value.enableSingleNoteSharing.isSet()) {
        out << "    enableSingleNoteSharing = "
            << value.enableSingleNoteSharing.ref() << "\n";
    }
    else {
        out << "    enableSingleNoteSharing is not set\n";
    }

    if (value.enableSponsoredAccounts.isSet()) {
        out << "    enableSponsoredAccounts = "
            << value.enableSponsoredAccounts.ref() << "\n";
    }
    else {
        out << "    enableSponsoredAccounts is not set\n";
    }

    if (value.enableTwitterSharing.isSet()) {
        out << "    enableTwitterSharing = "
            << value.enableTwitterSharing.ref() << "\n";
    }
    else {
        out << "    enableTwitterSharing is not set\n";
    }

    if (value.enableLinkedInSharing.isSet()) {
        out << "    enableLinkedInSharing = "
            << value.enableLinkedInSharing.ref() << "\n";
    }
    else {
        out << "    enableLinkedInSharing is not set\n";
    }

    if (value.enablePublicNotebooks.isSet()) {
        out << "    enablePublicNotebooks = "
            << value.enablePublicNotebooks.ref() << "\n";
    }
    else {
        out << "    enablePublicNotebooks is not set\n";
    }

    if (value.enableGoogle.isSet()) {
        out << "    enableGoogle = "
            << value.enableGoogle.ref() << "\n";
    }
    else {
        out << "    enableGoogle is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapProfile(ThriftBinaryBufferWriter & w, const BootstrapProfile & s) {
    w.writeStructBegin(QStringLiteral("BootstrapProfile"));
    w.writeFieldBegin(
        QStringLiteral("name"),
        ThriftFieldType::T_STRING,
        1);
    w.writeString(s.name);
    w.writeFieldEnd();
    w.writeFieldBegin(
        QStringLiteral("settings"),
        ThriftFieldType::T_STRUCT,
        2);
    writeBootstrapSettings(w, s.settings);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapProfile(ThriftBinaryBufferReader & r, BootstrapProfile & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool name_isset = false;
    bool settings_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                name_isset = true;
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                settings_isset = true;
                BootstrapSettings v;
                readBootstrapSettings(r, v);
                s.settings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!name_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.name has no value"));
    if(!settings_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.settings has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BootstrapProfile & value)
{
    out << "BootstrapProfile: {\n";
    out << "    name = "
        << "QString" << "\n";
    out << "    settings = "
        << "BootstrapSettings" << "\n";
    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BootstrapProfile & value)
{
    out << "BootstrapProfile: {\n";
    out << "    name = "
        << "QString" << "\n";
    out << "    settings = "
        << "BootstrapSettings" << "\n";
    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapInfo(ThriftBinaryBufferWriter & w, const BootstrapInfo & s) {
    w.writeStructBegin(QStringLiteral("BootstrapInfo"));
    w.writeFieldBegin(
        QStringLiteral("profiles"),
        ThriftFieldType::T_LIST,
        1);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.profiles.length());
    for(const auto & value: qAsConst(s.profiles)) {
        writeBootstrapProfile(w, value);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapInfo(ThriftBinaryBufferReader & r, BootstrapInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool profiles_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                profiles_isset = true;
                QList<BootstrapProfile> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (BootstrapInfo.profiles)"));
                for(qint32 i = 0; i < size; i++) {
                    BootstrapProfile elem;
                    readBootstrapProfile(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.profiles = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!profiles_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapInfo.profiles has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BootstrapInfo & value)
{
    out << "BootstrapInfo: {\n";
    out << "    profiles = "
        << "QList<BootstrapProfile>" << "\n";
    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BootstrapInfo & value)
{
    out << "BootstrapInfo: {\n";
    out << "    profiles = "
        << "QList<BootstrapProfile>" << "\n";
    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

EDAMUserException::EDAMUserException() {}
EDAMUserException::~EDAMUserException() throw() {}
EDAMUserException::EDAMUserException(const EDAMUserException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   parameter = other.parameter;
}
void writeEDAMUserException(ThriftBinaryBufferWriter & w, const EDAMUserException & s) {
    w.writeStructBegin(QStringLiteral("EDAMUserException"));
    w.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(static_cast<qint32>(s.errorCode));
    w.writeFieldEnd();
    if (s.parameter.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.parameter.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMUserException(ThriftBinaryBufferReader & r, EDAMUserException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(r, v);
                s.errorCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.parameter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMUserException.errorCode has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMUserException & value)
{
    out << "EDAMUserException: {\n";
    out << "    errorCode = "
        << "EDAMErrorCode" << "\n";

    if (value.parameter.isSet()) {
        out << "    parameter = "
            << value.parameter.ref() << "\n";
    }
    else {
        out << "    parameter is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMUserException & value)
{
    out << "EDAMUserException: {\n";
    out << "    errorCode = "
        << "EDAMErrorCode" << "\n";

    if (value.parameter.isSet()) {
        out << "    parameter = "
            << value.parameter.ref() << "\n";
    }
    else {
        out << "    parameter is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

EDAMSystemException::EDAMSystemException() {}
EDAMSystemException::~EDAMSystemException() throw() {}
EDAMSystemException::EDAMSystemException(const EDAMSystemException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   message = other.message;
   rateLimitDuration = other.rateLimitDuration;
}
void writeEDAMSystemException(ThriftBinaryBufferWriter & w, const EDAMSystemException & s) {
    w.writeStructBegin(QStringLiteral("EDAMSystemException"));
    w.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);
    w.writeI32(static_cast<qint32>(s.errorCode));
    w.writeFieldEnd();
    if (s.message.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.message.ref());
        w.writeFieldEnd();
    }
    if (s.rateLimitDuration.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("rateLimitDuration"),
            ThriftFieldType::T_I32,
            3);
        w.writeI32(s.rateLimitDuration.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMSystemException(ThriftBinaryBufferReader & r, EDAMSystemException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(r, v);
                s.errorCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.message = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.rateLimitDuration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMSystemException.errorCode has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMSystemException & value)
{
    out << "EDAMSystemException: {\n";
    out << "    errorCode = "
        << "EDAMErrorCode" << "\n";

    if (value.message.isSet()) {
        out << "    message = "
            << value.message.ref() << "\n";
    }
    else {
        out << "    message is not set\n";
    }

    if (value.rateLimitDuration.isSet()) {
        out << "    rateLimitDuration = "
            << value.rateLimitDuration.ref() << "\n";
    }
    else {
        out << "    rateLimitDuration is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMSystemException & value)
{
    out << "EDAMSystemException: {\n";
    out << "    errorCode = "
        << "EDAMErrorCode" << "\n";

    if (value.message.isSet()) {
        out << "    message = "
            << value.message.ref() << "\n";
    }
    else {
        out << "    message is not set\n";
    }

    if (value.rateLimitDuration.isSet()) {
        out << "    rateLimitDuration = "
            << value.rateLimitDuration.ref() << "\n";
    }
    else {
        out << "    rateLimitDuration is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

EDAMNotFoundException::EDAMNotFoundException() {}
EDAMNotFoundException::~EDAMNotFoundException() throw() {}
EDAMNotFoundException::EDAMNotFoundException(const EDAMNotFoundException& other) : EvernoteException(other)
{
   identifier = other.identifier;
   key = other.key;
}
void writeEDAMNotFoundException(ThriftBinaryBufferWriter & w, const EDAMNotFoundException & s) {
    w.writeStructBegin(QStringLiteral("EDAMNotFoundException"));
    if (s.identifier.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("identifier"),
            ThriftFieldType::T_STRING,
            1);
        w.writeString(s.identifier.ref());
        w.writeFieldEnd();
    }
    if (s.key.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("key"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.key.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMNotFoundException(ThriftBinaryBufferReader & r, EDAMNotFoundException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.identifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.key = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMNotFoundException & value)
{
    out << "EDAMNotFoundException: {\n";

    if (value.identifier.isSet()) {
        out << "    identifier = "
            << value.identifier.ref() << "\n";
    }
    else {
        out << "    identifier is not set\n";
    }

    if (value.key.isSet()) {
        out << "    key = "
            << value.key.ref() << "\n";
    }
    else {
        out << "    key is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMNotFoundException & value)
{
    out << "EDAMNotFoundException: {\n";

    if (value.identifier.isSet()) {
        out << "    identifier = "
            << value.identifier.ref() << "\n";
    }
    else {
        out << "    identifier is not set\n";
    }

    if (value.key.isSet()) {
        out << "    key = "
            << value.key.ref() << "\n";
    }
    else {
        out << "    key is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

EDAMInvalidContactsException::EDAMInvalidContactsException() {}
EDAMInvalidContactsException::~EDAMInvalidContactsException() throw() {}
EDAMInvalidContactsException::EDAMInvalidContactsException(const EDAMInvalidContactsException& other) : EvernoteException(other)
{
   contacts = other.contacts;
   parameter = other.parameter;
   reasons = other.reasons;
}
void writeEDAMInvalidContactsException(ThriftBinaryBufferWriter & w, const EDAMInvalidContactsException & s) {
    w.writeStructBegin(QStringLiteral("EDAMInvalidContactsException"));
    w.writeFieldBegin(
        QStringLiteral("contacts"),
        ThriftFieldType::T_LIST,
        1);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.contacts.length());
    for(const auto & value: qAsConst(s.contacts)) {
        writeContact(w, value);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if (s.parameter.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);
        w.writeString(s.parameter.ref());
        w.writeFieldEnd();
    }
    if (s.reasons.isSet()) {
        w.writeFieldBegin(
            QStringLiteral("reasons"),
            ThriftFieldType::T_LIST,
            3);
        w.writeListBegin(ThriftFieldType::T_I32, s.reasons.ref().length());
        for(const auto & value: qAsConst(s.reasons.ref())) {
            w.writeI32(static_cast<qint32>(value));
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMInvalidContactsException(ThriftBinaryBufferReader & r, EDAMInvalidContactsException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool contacts_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                contacts_isset = true;
                QList<Contact> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (EDAMInvalidContactsException.contacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.contacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.parameter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<EDAMInvalidContactReason> v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (EDAMInvalidContactsException.reasons)"));
                for(qint32 i = 0; i < size; i++) {
                    EDAMInvalidContactReason elem;
                    readEnumEDAMInvalidContactReason(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.reasons = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!contacts_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMInvalidContactsException.contacts has no value"));
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMInvalidContactsException & value)
{
    out << "EDAMInvalidContactsException: {\n";
    out << "    contacts = "
        << "QList<Contact>" << "\n";

    if (value.parameter.isSet()) {
        out << "    parameter = "
            << value.parameter.ref() << "\n";
    }
    else {
        out << "    parameter is not set\n";
    }

    if (value.reasons.isSet()) {
        out << "    reasons = "
            << "QList<EDAMInvalidContactReason> {";
        for(const auto & v: value.reasons.ref()) {
            out << v;
        }
    }
    else {
        out << "    reasons is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMInvalidContactsException & value)
{
    out << "EDAMInvalidContactsException: {\n";
    out << "    contacts = "
        << "QList<Contact>" << "\n";

    if (value.parameter.isSet()) {
        out << "    parameter = "
            << value.parameter.ref() << "\n";
    }
    else {
        out << "    parameter is not set\n";
    }

    if (value.reasons.isSet()) {
        out << "    reasons = "
            << "QList<EDAMInvalidContactReason> {";
        for(const auto & v: value.reasons.ref()) {
            out << v;
        }
    }
    else {
        out << "    reasons is not set\n";
    }

    out << "}\n";
    return out;
}

////////////////////////////////////////////////////////////////////////////////


/** @endcond */



} // namespace qevercloud
