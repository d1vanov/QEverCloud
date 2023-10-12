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

#include <qevercloud/services/UserStoreServer.h>
#include "../Impl.h"
#include "../Thrift.h"
#include "../Types_io.h"
#include <qevercloud/RequestContextBuilder.h>
#include <qevercloud/exceptions/builders/EDAMSystemExceptionBuilder.h>
#include <qevercloud/utility/Log.h>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCheckVersionParams(
    ThriftBinaryBufferReader & reader,
    QString & clientName,
    qint16 & edamVersionMajor,
    qint16 & edamVersionMinor,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_checkVersion_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                clientName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMajor = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMinor = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetBootstrapInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & locale,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getBootstrapInfo_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                locale = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateLongSessionParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    QString & password,
    QString & consumerKey,
    QString & consumerSecret,
    QString & deviceIdentifier,
    QString & deviceDescription,
    bool & supportsTwoFactor,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_authenticateLongSession_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                password = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                consumerKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                consumerSecret = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 7)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                supportsTwoFactor = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCompleteTwoFactorAuthenticationParams(
    ThriftBinaryBufferReader & reader,
    QString & oneTimeCode,
    QString & deviceIdentifier,
    QString & deviceDescription,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_completeTwoFactorAuthentication_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                oneTimeCode = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceDescription = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRevokeLongSessionParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_revokeLongSession_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateToBusinessParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_authenticateToBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_getUser_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetPublicUserInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getPublicUserInfo_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                username = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserUrlsParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_getUserUrls_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreInviteToBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_inviteToBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                emailAddress = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRemoveFromBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_removeFromBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                emailAddress = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreUpdateBusinessUserIdentifierParams(
    ThriftBinaryBufferReader & reader,
    QString & oldEmailAddress,
    QString & newEmailAddress,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_updateBusinessUserIdentifier_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                oldEmailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                newEmailAddress = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessUsersParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_listBusinessUsers_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessInvitationsParams(
    ThriftBinaryBufferReader & reader,
    bool & includeRequestedInvitations,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_listBusinessInvitations_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                includeRequestedInvitations = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetAccountLimitsParams(
    ThriftBinaryBufferReader & reader,
    ServiceLevel & serviceLevel,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getAccountLimits_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                serviceLevel = v;
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
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

UserStoreServer::UserStoreServer(QObject * parent) :
    QObject(parent)
{}

void UserStoreServer::onRequest(QByteArray data, QUuid requestId)
{
    ThriftBinaryBufferReader reader(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);

    if (mtype != ThriftMessageType::T_CALL) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }

    if (fname == QStringLiteral("checkVersion"))
    {
        QString clientName;
        qint16 edamVersionMajor = 0;
        qint16 edamVersionMinor = 0;
        IRequestContextPtr ctx;

        parseUserStoreCheckVersionParams(
            reader,
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            requestId,
            ctx);

        Q_EMIT checkVersionRequest(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);
    }
    else if (fname == QStringLiteral("getBootstrapInfo"))
    {
        QString locale;
        IRequestContextPtr ctx;

        parseUserStoreGetBootstrapInfoParams(
            reader,
            locale,
            requestId,
            ctx);

        Q_EMIT getBootstrapInfoRequest(
            locale,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateLongSession"))
    {
        QString username;
        QString password;
        QString consumerKey;
        QString consumerSecret;
        QString deviceIdentifier;
        QString deviceDescription;
        bool supportsTwoFactor = false;
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateLongSessionParams(
            reader,
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            requestId,
            ctx);

        Q_EMIT authenticateLongSessionRequest(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
    }
    else if (fname == QStringLiteral("completeTwoFactorAuthentication"))
    {
        QString oneTimeCode;
        QString deviceIdentifier;
        QString deviceDescription;
        IRequestContextPtr ctx;

        parseUserStoreCompleteTwoFactorAuthenticationParams(
            reader,
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            requestId,
            ctx);

        Q_EMIT completeTwoFactorAuthenticationRequest(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
    }
    else if (fname == QStringLiteral("revokeLongSession"))
    {
        IRequestContextPtr ctx;

        parseUserStoreRevokeLongSessionParams(
            reader,
            requestId,
            ctx);

        Q_EMIT revokeLongSessionRequest(
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToBusiness"))
    {
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateToBusinessParams(
            reader,
            requestId,
            ctx);

        Q_EMIT authenticateToBusinessRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getUser"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserParams(
            reader,
            requestId,
            ctx);

        Q_EMIT getUserRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getPublicUserInfo"))
    {
        QString username;
        IRequestContextPtr ctx;

        parseUserStoreGetPublicUserInfoParams(
            reader,
            username,
            requestId,
            ctx);

        Q_EMIT getPublicUserInfoRequest(
            username,
            ctx);
    }
    else if (fname == QStringLiteral("getUserUrls"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserUrlsParams(
            reader,
            requestId,
            ctx);

        Q_EMIT getUserUrlsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("inviteToBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreInviteToBusinessParams(
            reader,
            emailAddress,
            requestId,
            ctx);

        Q_EMIT inviteToBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("removeFromBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreRemoveFromBusinessParams(
            reader,
            emailAddress,
            requestId,
            ctx);

        Q_EMIT removeFromBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("updateBusinessUserIdentifier"))
    {
        QString oldEmailAddress;
        QString newEmailAddress;
        IRequestContextPtr ctx;

        parseUserStoreUpdateBusinessUserIdentifierParams(
            reader,
            oldEmailAddress,
            newEmailAddress,
            requestId,
            ctx);

        Q_EMIT updateBusinessUserIdentifierRequest(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessUsers"))
    {
        IRequestContextPtr ctx;

        parseUserStoreListBusinessUsersParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listBusinessUsersRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessInvitations"))
    {
        bool includeRequestedInvitations = false;
        IRequestContextPtr ctx;

        parseUserStoreListBusinessInvitationsParams(
            reader,
            includeRequestedInvitations,
            requestId,
            ctx);

        Q_EMIT listBusinessInvitationsRequest(
            includeRequestedInvitations,
            ctx);
    }
    else if (fname == QStringLiteral("getAccountLimits"))
    {
        ServiceLevel serviceLevel;
        IRequestContextPtr ctx;

        parseUserStoreGetAccountLimitsParams(
            reader,
            serviceLevel,
            requestId,
            ctx);

        Q_EMIT getAccountLimitsRequest(
            serviceLevel,
            ctx);
    }
}

void UserStoreServer::onCheckVersionRequestReady(
    bool value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("checkVersion"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT checkVersionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("checkVersion"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("checkVersion"));

    writer.writeFieldBegin(
        QStringLiteral("checkVersion"),
        ThriftFieldType::T_BOOL,
        0);
    writer.writeBool(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT checkVersionRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onGetBootstrapInfoRequestReady(
    BootstrapInfo value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getBootstrapInfo"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getBootstrapInfoRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getBootstrapInfo"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getBootstrapInfo"));

    writer.writeFieldBegin(
        QStringLiteral("getBootstrapInfo"),
        ThriftFieldType::T_STRUCT,
        0);
    writeBootstrapInfo(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getBootstrapInfoRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onAuthenticateLongSessionRequestReady(
    AuthenticationResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateLongSession"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateLongSession"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateLongSession"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT authenticateLongSessionRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateLongSession"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateLongSessionRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady(
    AuthenticationResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("completeTwoFactorAuthentication"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("completeTwoFactorAuthentication"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("completeTwoFactorAuthentication"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT completeTwoFactorAuthenticationRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("completeTwoFactorAuthentication"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT completeTwoFactorAuthenticationRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onRevokeLongSessionRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("revokeLongSession"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("revokeLongSession"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("revokeLongSession"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT revokeLongSessionRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("revokeLongSession"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT revokeLongSessionRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onAuthenticateToBusinessRequestReady(
    AuthenticationResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToBusiness"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT authenticateToBusinessRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToBusiness"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToBusinessRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onGetUserRequestReady(
    User value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getUser"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getUser"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getUser"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getUserRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getUser"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUser(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getUserRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onGetPublicUserInfoRequestReady(
    PublicUserInfo value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getPublicUserInfo"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getPublicUserInfo"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getPublicUserInfo"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getPublicUserInfoRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getPublicUserInfo"),
        ThriftFieldType::T_STRUCT,
        0);
    writePublicUserInfo(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getPublicUserInfoRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onGetUserUrlsRequestReady(
    UserUrls value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getUserUrls"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getUserUrls"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getUserUrls"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getUserUrlsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getUserUrls"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUserUrls(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getUserUrlsRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onInviteToBusinessRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("inviteToBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("inviteToBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("inviteToBusiness"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT inviteToBusinessRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("inviteToBusiness"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT inviteToBusinessRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onRemoveFromBusinessRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("removeFromBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("removeFromBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("removeFromBusiness"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT removeFromBusinessRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("removeFromBusiness"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT removeFromBusinessRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onUpdateBusinessUserIdentifierRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateBusinessUserIdentifier"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateBusinessUserIdentifier"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateBusinessUserIdentifier"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateBusinessUserIdentifierRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateBusinessUserIdentifier"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateBusinessUserIdentifierRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onListBusinessUsersRequestReady(
    QList<UserProfile> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listBusinessUsers"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listBusinessUsers"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listBusinessUsers"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listBusinessUsersRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listBusinessUsers"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeUserProfile(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listBusinessUsersRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onListBusinessInvitationsRequestReady(
    QList<BusinessInvitation> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listBusinessInvitations"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listBusinessInvitations"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listBusinessInvitations"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listBusinessInvitationsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listBusinessInvitations"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeBusinessInvitation(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listBusinessInvitationsRequestReady(
        writer.buffer(), requestId);
}

void UserStoreServer::onGetAccountLimitsRequestReady(
    AccountLimits value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getAccountLimits"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getAccountLimitsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getAccountLimits"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getAccountLimits"));

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getAccountLimitsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            throw;
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            throw;
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getAccountLimits"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAccountLimits(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getAccountLimitsRequestReady(
        writer.buffer(), requestId);
}

} // namespace qevercloud
