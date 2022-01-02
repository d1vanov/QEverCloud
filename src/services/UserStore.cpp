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

#include <qevercloud/services/IUserStore.h>
#include "../Impl.h"
#include "../Http.h"
#include "../Types_io.h"
#include <qevercloud/DurableService.h>
#include <qevercloud/utility/Log.h>
#include <algorithm>
#include <cmath>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN UserStore: public IUserStore
{
    Q_OBJECT
    Q_DISABLE_COPY(UserStore)
public:
    explicit UserStore(
            QString userStoreUrl = {},
            IRequestContextPtr ctx = {},
            QObject * parent = nullptr) :
        IUserStore(parent),
        m_url(std::move(userStoreUrl)),
        m_ctx(std::move(ctx))
    {
        if (!m_ctx) {
            m_ctx = newRequestContext();
        }
    }

    explicit UserStore(QObject * parent) :
        IUserStore(parent)
    {
        m_ctx = newRequestContext();
    }

    void setUserStoreUrl(QString userStoreUrl) override
    {
        m_url = std::move(userStoreUrl);
    }

    QString userStoreUrl() const override
    {
        return m_url;
    }

    bool checkVersion(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> checkVersionAsync(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) override;

    BootstrapInfo getBootstrapInfo(
        QString locale,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getBootstrapInfoAsync(
        QString locale,
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult authenticateLongSession(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> authenticateLongSessionAsync(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult completeTwoFactorAuthentication(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> completeTwoFactorAuthenticationAsync(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) override;

    void revokeLongSession(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> revokeLongSessionAsync(
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult authenticateToBusiness(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> authenticateToBusinessAsync(
        IRequestContextPtr ctx = {}) override;

    User getUser(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getUserAsync(
        IRequestContextPtr ctx = {}) override;

    PublicUserInfo getPublicUserInfo(
        QString username,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getPublicUserInfoAsync(
        QString username,
        IRequestContextPtr ctx = {}) override;

    UserUrls getUserUrls(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getUserUrlsAsync(
        IRequestContextPtr ctx = {}) override;

    void inviteToBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> inviteToBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    void removeFromBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> removeFromBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    void updateBusinessUserIdentifier(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> updateBusinessUserIdentifierAsync(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) override;

    QList<UserProfile> listBusinessUsers(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> listBusinessUsersAsync(
        IRequestContextPtr ctx = {}) override;

    QList<BusinessInvitation> listBusinessInvitations(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> listBusinessInvitationsAsync(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) override;

    AccountLimits getAccountLimits(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getAccountLimitsAsync(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) override;

private:
    QString m_url;
    IRequestContextPtr m_ctx;
};

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreCheckVersionPrepareParams(
    QString clientName,
    qint16 edamVersionMajor,
    qint16 edamVersionMinor)
{
    QEC_DEBUG("user_store", "UserStoreCheckVersionPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("checkVersion"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_checkVersion_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("clientName"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(clientName);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("edamVersionMajor"),
        ThriftFieldType::T_I16,
        2);

    writer.writeI16(edamVersionMajor);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("edamVersionMinor"),
        ThriftFieldType::T_I16,
        3);

    writer.writeI16(edamVersionMinor);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

bool UserStoreCheckVersionReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    bool result = bool();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("checkVersion")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                resultIsSet = true;
                bool v;
                reader.readBool(v);
                result = v;
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("checkVersion: missing result"));
    }

    return result;
}

QVariant UserStoreCheckVersionReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreCheckVersionReadReply(reply));
}

} // namespace

bool UserStore::checkVersion(
    QString clientName,
    qint16 edamVersionMajor,
    qint16 edamVersionMinor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::checkVersion: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    clientName = " << clientName << "\n"
        << "    edamVersionMajor = " << edamVersionMajor << "\n"
        << "    edamVersionMinor = " << edamVersionMinor);

    QByteArray params = UserStoreCheckVersionPrepareParams(
        clientName,
        edamVersionMajor,
        edamVersionMinor);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreCheckVersionReadReply(reply);
}

QFuture<QVariant> UserStore::checkVersionAsync(
    QString clientName,
    qint16 edamVersionMajor,
    qint16 edamVersionMinor,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::checkVersionAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    clientName = " << clientName << "\n"
        << "    edamVersionMajor = " << edamVersionMajor << "\n"
        << "    edamVersionMinor = " << edamVersionMinor);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreCheckVersionPrepareParams(
        clientName,
        edamVersionMajor,
        edamVersionMinor);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreCheckVersionReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreGetBootstrapInfoPrepareParams(
    QString locale)
{
    QEC_DEBUG("user_store", "UserStoreGetBootstrapInfoPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getBootstrapInfo"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_getBootstrapInfo_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("locale"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(locale);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

BootstrapInfo UserStoreGetBootstrapInfoReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    BootstrapInfo result = BootstrapInfo();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getBootstrapInfo")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                BootstrapInfo v;
                readBootstrapInfo(reader, v);
                result = v;
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getBootstrapInfo: missing result"));
    }

    return result;
}

QVariant UserStoreGetBootstrapInfoReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreGetBootstrapInfoReadReply(reply));
}

} // namespace

BootstrapInfo UserStore::getBootstrapInfo(
    QString locale,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::getBootstrapInfo: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    locale = " << locale);

    QByteArray params = UserStoreGetBootstrapInfoPrepareParams(
        locale);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreGetBootstrapInfoReadReply(reply);
}

QFuture<QVariant> UserStore::getBootstrapInfoAsync(
    QString locale,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::getBootstrapInfoAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    locale = " << locale);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreGetBootstrapInfoPrepareParams(
        locale);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreGetBootstrapInfoReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreAuthenticateLongSessionPrepareParams(
    QString username,
    QString password,
    QString consumerKey,
    QString consumerSecret,
    QString deviceIdentifier,
    QString deviceDescription,
    bool supportsTwoFactor)
{
    QEC_DEBUG("user_store", "UserStoreAuthenticateLongSessionPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("authenticateLongSession"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_authenticateLongSession_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("username"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(username);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("password"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(password);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("consumerKey"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(consumerKey);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("consumerSecret"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(consumerSecret);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("deviceIdentifier"),
        ThriftFieldType::T_STRING,
        5);

    writer.writeString(deviceIdentifier);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("deviceDescription"),
        ThriftFieldType::T_STRING,
        6);

    writer.writeString(deviceDescription);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("supportsTwoFactor"),
        ThriftFieldType::T_BOOL,
        7);

    writer.writeBool(supportsTwoFactor);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AuthenticationResult UserStoreAuthenticateLongSessionReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateLongSession")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("authenticateLongSession: missing result"));
    }

    return result;
}

QVariant UserStoreAuthenticateLongSessionReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreAuthenticateLongSessionReadReply(reply));
}

} // namespace

AuthenticationResult UserStore::authenticateLongSession(
    QString username,
    QString password,
    QString consumerKey,
    QString consumerSecret,
    QString deviceIdentifier,
    QString deviceDescription,
    bool supportsTwoFactor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::authenticateLongSession: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    username = " << username << "\n"
        << "    deviceIdentifier = " << deviceIdentifier << "\n"
        << "    deviceDescription = " << deviceDescription << "\n"
        << "    supportsTwoFactor = " << supportsTwoFactor);

    QByteArray params = UserStoreAuthenticateLongSessionPrepareParams(
        username,
        password,
        consumerKey,
        consumerSecret,
        deviceIdentifier,
        deviceDescription,
        supportsTwoFactor);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreAuthenticateLongSessionReadReply(reply);
}

QFuture<QVariant> UserStore::authenticateLongSessionAsync(
    QString username,
    QString password,
    QString consumerKey,
    QString consumerSecret,
    QString deviceIdentifier,
    QString deviceDescription,
    bool supportsTwoFactor,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::authenticateLongSessionAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    username = " << username << "\n"
        << "    deviceIdentifier = " << deviceIdentifier << "\n"
        << "    deviceDescription = " << deviceDescription << "\n"
        << "    supportsTwoFactor = " << supportsTwoFactor);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreAuthenticateLongSessionPrepareParams(
        username,
        password,
        consumerKey,
        consumerSecret,
        deviceIdentifier,
        deviceDescription,
        supportsTwoFactor);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreAuthenticateLongSessionReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreCompleteTwoFactorAuthenticationPrepareParams(
    QString authenticationToken,
    QString oneTimeCode,
    QString deviceIdentifier,
    QString deviceDescription)
{
    QEC_DEBUG("user_store", "UserStoreCompleteTwoFactorAuthenticationPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("completeTwoFactorAuthentication"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_completeTwoFactorAuthentication_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("oneTimeCode"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(oneTimeCode);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("deviceIdentifier"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(deviceIdentifier);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("deviceDescription"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(deviceDescription);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AuthenticationResult UserStoreCompleteTwoFactorAuthenticationReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("completeTwoFactorAuthentication")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("completeTwoFactorAuthentication: missing result"));
    }

    return result;
}

QVariant UserStoreCompleteTwoFactorAuthenticationReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreCompleteTwoFactorAuthenticationReadReply(reply));
}

} // namespace

AuthenticationResult UserStore::completeTwoFactorAuthentication(
    QString oneTimeCode,
    QString deviceIdentifier,
    QString deviceDescription,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::completeTwoFactorAuthentication: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    deviceIdentifier = " << deviceIdentifier << "\n"
        << "    deviceDescription = " << deviceDescription);

    QByteArray params = UserStoreCompleteTwoFactorAuthenticationPrepareParams(
        ctx->authenticationToken(),
        oneTimeCode,
        deviceIdentifier,
        deviceDescription);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreCompleteTwoFactorAuthenticationReadReply(reply);
}

QFuture<QVariant> UserStore::completeTwoFactorAuthenticationAsync(
    QString oneTimeCode,
    QString deviceIdentifier,
    QString deviceDescription,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::completeTwoFactorAuthenticationAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    deviceIdentifier = " << deviceIdentifier << "\n"
        << "    deviceDescription = " << deviceDescription);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreCompleteTwoFactorAuthenticationPrepareParams(
        ctx->authenticationToken(),
        oneTimeCode,
        deviceIdentifier,
        deviceDescription);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreCompleteTwoFactorAuthenticationReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreRevokeLongSessionPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("user_store", "UserStoreRevokeLongSessionPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("revokeLongSession"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_revokeLongSession_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void UserStoreRevokeLongSessionReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("revokeLongSession")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

}

QVariant UserStoreRevokeLongSessionReadReplyAsync(QByteArray reply)
{
    UserStoreRevokeLongSessionReadReply(reply);
    return QVariant();
}

} // namespace

void UserStore::revokeLongSession(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::revokeLongSession: request id = "
        << ctx->requestId());

    QByteArray params = UserStoreRevokeLongSessionPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    UserStoreRevokeLongSessionReadReply(reply);
}

QFuture<QVariant> UserStore::revokeLongSessionAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::revokeLongSessionAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreRevokeLongSessionPrepareParams(
        ctx->authenticationToken());

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreRevokeLongSessionReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreAuthenticateToBusinessPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("user_store", "UserStoreAuthenticateToBusinessPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("authenticateToBusiness"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_authenticateToBusiness_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AuthenticationResult UserStoreAuthenticateToBusinessReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToBusiness")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("authenticateToBusiness: missing result"));
    }

    return result;
}

QVariant UserStoreAuthenticateToBusinessReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreAuthenticateToBusinessReadReply(reply));
}

} // namespace

AuthenticationResult UserStore::authenticateToBusiness(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::authenticateToBusiness: request id = "
        << ctx->requestId());

    QByteArray params = UserStoreAuthenticateToBusinessPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreAuthenticateToBusinessReadReply(reply);
}

QFuture<QVariant> UserStore::authenticateToBusinessAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::authenticateToBusinessAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreAuthenticateToBusinessPrepareParams(
        ctx->authenticationToken());

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreAuthenticateToBusinessReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreGetUserPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("user_store", "UserStoreGetUserPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getUser"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_getUser_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

User UserStoreGetUserReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    User result = User();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getUser")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                User v;
                readUser(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getUser: missing result"));
    }

    return result;
}

QVariant UserStoreGetUserReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreGetUserReadReply(reply));
}

} // namespace

User UserStore::getUser(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::getUser: request id = "
        << ctx->requestId());

    QByteArray params = UserStoreGetUserPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreGetUserReadReply(reply);
}

QFuture<QVariant> UserStore::getUserAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::getUserAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreGetUserPrepareParams(
        ctx->authenticationToken());

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreGetUserReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreGetPublicUserInfoPrepareParams(
    QString username)
{
    QEC_DEBUG("user_store", "UserStoreGetPublicUserInfoPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getPublicUserInfo"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_getPublicUserInfo_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("username"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(username);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

PublicUserInfo UserStoreGetPublicUserInfoReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    PublicUserInfo result = PublicUserInfo();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getPublicUserInfo")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                PublicUserInfo v;
                readPublicUserInfo(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getPublicUserInfo: missing result"));
    }

    return result;
}

QVariant UserStoreGetPublicUserInfoReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreGetPublicUserInfoReadReply(reply));
}

} // namespace

PublicUserInfo UserStore::getPublicUserInfo(
    QString username,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::getPublicUserInfo: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    username = " << username);

    QByteArray params = UserStoreGetPublicUserInfoPrepareParams(
        username);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreGetPublicUserInfoReadReply(reply);
}

QFuture<QVariant> UserStore::getPublicUserInfoAsync(
    QString username,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::getPublicUserInfoAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    username = " << username);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreGetPublicUserInfoPrepareParams(
        username);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreGetPublicUserInfoReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreGetUserUrlsPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("user_store", "UserStoreGetUserUrlsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getUserUrls"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_getUserUrls_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

UserUrls UserStoreGetUserUrlsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    UserUrls result = UserUrls();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getUserUrls")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                UserUrls v;
                readUserUrls(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getUserUrls: missing result"));
    }

    return result;
}

QVariant UserStoreGetUserUrlsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreGetUserUrlsReadReply(reply));
}

} // namespace

UserUrls UserStore::getUserUrls(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::getUserUrls: request id = "
        << ctx->requestId());

    QByteArray params = UserStoreGetUserUrlsPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreGetUserUrlsReadReply(reply);
}

QFuture<QVariant> UserStore::getUserUrlsAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::getUserUrlsAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreGetUserUrlsPrepareParams(
        ctx->authenticationToken());

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreGetUserUrlsReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreInviteToBusinessPrepareParams(
    QString authenticationToken,
    QString emailAddress)
{
    QEC_DEBUG("user_store", "UserStoreInviteToBusinessPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("inviteToBusiness"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_inviteToBusiness_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("emailAddress"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(emailAddress);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void UserStoreInviteToBusinessReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("inviteToBusiness")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

}

QVariant UserStoreInviteToBusinessReadReplyAsync(QByteArray reply)
{
    UserStoreInviteToBusinessReadReply(reply);
    return QVariant();
}

} // namespace

void UserStore::inviteToBusiness(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::inviteToBusiness: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    emailAddress = " << emailAddress);

    QByteArray params = UserStoreInviteToBusinessPrepareParams(
        ctx->authenticationToken(),
        emailAddress);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    UserStoreInviteToBusinessReadReply(reply);
}

QFuture<QVariant> UserStore::inviteToBusinessAsync(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::inviteToBusinessAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    emailAddress = " << emailAddress);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreInviteToBusinessPrepareParams(
        ctx->authenticationToken(),
        emailAddress);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreInviteToBusinessReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreRemoveFromBusinessPrepareParams(
    QString authenticationToken,
    QString emailAddress)
{
    QEC_DEBUG("user_store", "UserStoreRemoveFromBusinessPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("removeFromBusiness"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_removeFromBusiness_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("emailAddress"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(emailAddress);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void UserStoreRemoveFromBusinessReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("removeFromBusiness")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
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

}

QVariant UserStoreRemoveFromBusinessReadReplyAsync(QByteArray reply)
{
    UserStoreRemoveFromBusinessReadReply(reply);
    return QVariant();
}

} // namespace

void UserStore::removeFromBusiness(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::removeFromBusiness: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    emailAddress = " << emailAddress);

    QByteArray params = UserStoreRemoveFromBusinessPrepareParams(
        ctx->authenticationToken(),
        emailAddress);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    UserStoreRemoveFromBusinessReadReply(reply);
}

QFuture<QVariant> UserStore::removeFromBusinessAsync(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::removeFromBusinessAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    emailAddress = " << emailAddress);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreRemoveFromBusinessPrepareParams(
        ctx->authenticationToken(),
        emailAddress);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreRemoveFromBusinessReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreUpdateBusinessUserIdentifierPrepareParams(
    QString authenticationToken,
    QString oldEmailAddress,
    QString newEmailAddress)
{
    QEC_DEBUG("user_store", "UserStoreUpdateBusinessUserIdentifierPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("updateBusinessUserIdentifier"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_updateBusinessUserIdentifier_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("oldEmailAddress"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(oldEmailAddress);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("newEmailAddress"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(newEmailAddress);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

void UserStoreUpdateBusinessUserIdentifierReadReply(QByteArray reply)
{
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateBusinessUserIdentifier")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(reader, e);
                throw e;
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

}

QVariant UserStoreUpdateBusinessUserIdentifierReadReplyAsync(QByteArray reply)
{
    UserStoreUpdateBusinessUserIdentifierReadReply(reply);
    return QVariant();
}

} // namespace

void UserStore::updateBusinessUserIdentifier(
    QString oldEmailAddress,
    QString newEmailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::updateBusinessUserIdentifier: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    oldEmailAddress = " << oldEmailAddress << "\n"
        << "    newEmailAddress = " << newEmailAddress);

    QByteArray params = UserStoreUpdateBusinessUserIdentifierPrepareParams(
        ctx->authenticationToken(),
        oldEmailAddress,
        newEmailAddress);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    UserStoreUpdateBusinessUserIdentifierReadReply(reply);
}

QFuture<QVariant> UserStore::updateBusinessUserIdentifierAsync(
    QString oldEmailAddress,
    QString newEmailAddress,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::updateBusinessUserIdentifierAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    oldEmailAddress = " << oldEmailAddress << "\n"
        << "    newEmailAddress = " << newEmailAddress);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreUpdateBusinessUserIdentifierPrepareParams(
        ctx->authenticationToken(),
        oldEmailAddress,
        newEmailAddress);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreUpdateBusinessUserIdentifierReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreListBusinessUsersPrepareParams(
    QString authenticationToken)
{
    QEC_DEBUG("user_store", "UserStoreListBusinessUsersPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listBusinessUsers"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_listBusinessUsers_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<UserProfile> UserStoreListBusinessUsersReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<UserProfile> result = QList<UserProfile>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listBusinessUsers")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<UserProfile> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listBusinessUsers.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listBusinessUsers: missing result"));
    }

    return result;
}

QVariant UserStoreListBusinessUsersReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreListBusinessUsersReadReply(reply));
}

} // namespace

QList<UserProfile> UserStore::listBusinessUsers(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::listBusinessUsers: request id = "
        << ctx->requestId());

    QByteArray params = UserStoreListBusinessUsersPrepareParams(
        ctx->authenticationToken());

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreListBusinessUsersReadReply(reply);
}

QFuture<QVariant> UserStore::listBusinessUsersAsync(
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::listBusinessUsersAsync");

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreListBusinessUsersPrepareParams(
        ctx->authenticationToken());

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreListBusinessUsersReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreListBusinessInvitationsPrepareParams(
    QString authenticationToken,
    bool includeRequestedInvitations)
{
    QEC_DEBUG("user_store", "UserStoreListBusinessInvitationsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("listBusinessInvitations"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_listBusinessInvitations_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("includeRequestedInvitations"),
        ThriftFieldType::T_BOOL,
        2);

    writer.writeBool(includeRequestedInvitations);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

QList<BusinessInvitation> UserStoreListBusinessInvitationsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList<BusinessInvitation> result = QList<BusinessInvitation>();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listBusinessInvitations")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList<BusinessInvitation> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (listBusinessInvitations.result)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    BusinessInvitation elem;
                    readBusinessInvitation(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(reader, e);
                throwEDAMSystemException(e);
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("listBusinessInvitations: missing result"));
    }

    return result;
}

QVariant UserStoreListBusinessInvitationsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreListBusinessInvitationsReadReply(reply));
}

} // namespace

QList<BusinessInvitation> UserStore::listBusinessInvitations(
    bool includeRequestedInvitations,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::listBusinessInvitations: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    includeRequestedInvitations = " << includeRequestedInvitations);

    QByteArray params = UserStoreListBusinessInvitationsPrepareParams(
        ctx->authenticationToken(),
        includeRequestedInvitations);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreListBusinessInvitationsReadReply(reply);
}

QFuture<QVariant> UserStore::listBusinessInvitationsAsync(
    bool includeRequestedInvitations,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::listBusinessInvitationsAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    includeRequestedInvitations = " << includeRequestedInvitations);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreListBusinessInvitationsPrepareParams(
        ctx->authenticationToken(),
        includeRequestedInvitations);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreListBusinessInvitationsReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

namespace {

QByteArray UserStoreGetAccountLimitsPrepareParams(
    ServiceLevel serviceLevel)
{
    QEC_DEBUG("user_store", "UserStoreGetAccountLimitsPrepareParams");

    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    writer.writeMessageBegin(
        QStringLiteral("getAccountLimits"),
        ThriftMessageType::T_CALL,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("UserStore_getAccountLimits_pargs"));
    writer.writeFieldBegin(
        QStringLiteral("serviceLevel"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(static_cast<qint32>(serviceLevel));
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
    writer.writeMessageEnd();
    return writer.buffer();
}

AccountLimits UserStoreGetAccountLimitsReadReply(QByteArray reply)
{
    bool resultIsSet = false;
    AccountLimits result = AccountLimits();
    ThriftBinaryBufferReader reader(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
        ThriftException e = readThriftException(reader);
        reader.readMessageEnd();
        throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getAccountLimits")) != 0) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 0)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AccountLimits v;
                readAccountLimits(reader, v);
                result = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(reader, e);
                throw e;
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

    if (!resultIsSet) {
        throw ThriftException(
            ThriftException::Type::MISSING_RESULT,
            QStringLiteral("getAccountLimits: missing result"));
    }

    return result;
}

QVariant UserStoreGetAccountLimitsReadReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStoreGetAccountLimitsReadReply(reply));
}

} // namespace

AccountLimits UserStore::getAccountLimits(
    ServiceLevel serviceLevel,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QEC_DEBUG("user_store", "UserStore::getAccountLimits: request id = "
        << ctx->requestId());
    QEC_TRACE("user_store", "Parameters:\n"
        << "    serviceLevel = " << serviceLevel);

    QByteArray params = UserStoreGetAccountLimitsPrepareParams(
        serviceLevel);

    QByteArray reply = askEvernote(
        m_url,
        params,
        ctx->requestTimeout(),
        ctx->cookies());

    QEC_DEBUG("user_store", "received reply for request with id = "
        << ctx->requestId());
    return UserStoreGetAccountLimitsReadReply(reply);
}

QFuture<QVariant> UserStore::getAccountLimitsAsync(
    ServiceLevel serviceLevel,
    IRequestContextPtr ctx)
{
    QEC_DEBUG("user_store", "UserStore::getAccountLimitsAsync");
    QEC_TRACE("user_store", "Parameters:\n"
        << "    serviceLevel = " << serviceLevel);

    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    QByteArray params = UserStoreGetAccountLimitsPrepareParams(
        serviceLevel);

    return sendRequest(
        m_url,
        params,
        ctx,
        UserStoreGetAccountLimitsReadReplyAsync);
}

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN DurableUserStore: public IUserStore
{
    Q_OBJECT
    Q_DISABLE_COPY(DurableUserStore)
public:
    explicit DurableUserStore(
            IUserStorePtr service,
            IRequestContextPtr ctx = {},
            IRetryPolicyPtr retryPolicy = newRetryPolicy(),
            QObject * parent = nullptr) :
        IUserStore(parent),
        m_service(std::move(service)),
        m_durableService(newDurableService(retryPolicy, ctx)),
        m_ctx(std::move(ctx))
    {
        if (!m_ctx) {
            m_ctx = newRequestContext();
        }

        m_service->setParent(this);
    }

    ~DurableUserStore()
    {
        // Don't interfere with std::shared_ptr's lifetime tracking
        m_service->setParent(nullptr);
    }

    void setUserStoreUrl(QString userStoreUrl) override
    {
        m_service->setUserStoreUrl(userStoreUrl);
    }

    QString userStoreUrl() const override
    {
        return m_service->userStoreUrl();
    }

    bool checkVersion(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> checkVersionAsync(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) override;

    BootstrapInfo getBootstrapInfo(
        QString locale,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getBootstrapInfoAsync(
        QString locale,
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult authenticateLongSession(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> authenticateLongSessionAsync(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult completeTwoFactorAuthentication(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> completeTwoFactorAuthenticationAsync(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) override;

    void revokeLongSession(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> revokeLongSessionAsync(
        IRequestContextPtr ctx = {}) override;

    AuthenticationResult authenticateToBusiness(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> authenticateToBusinessAsync(
        IRequestContextPtr ctx = {}) override;

    User getUser(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getUserAsync(
        IRequestContextPtr ctx = {}) override;

    PublicUserInfo getPublicUserInfo(
        QString username,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getPublicUserInfoAsync(
        QString username,
        IRequestContextPtr ctx = {}) override;

    UserUrls getUserUrls(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getUserUrlsAsync(
        IRequestContextPtr ctx = {}) override;

    void inviteToBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> inviteToBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    void removeFromBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> removeFromBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) override;

    void updateBusinessUserIdentifier(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> updateBusinessUserIdentifierAsync(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) override;

    QList<UserProfile> listBusinessUsers(
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> listBusinessUsersAsync(
        IRequestContextPtr ctx = {}) override;

    QList<BusinessInvitation> listBusinessInvitations(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> listBusinessInvitationsAsync(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) override;

    AccountLimits getAccountLimits(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) override;

    QFuture<QVariant> getAccountLimitsAsync(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) override;

private:
    IUserStorePtr m_service;
    IDurableServicePtr m_durableService;
    IRequestContextPtr m_ctx;
};

bool DurableUserStore::checkVersion(
    QString clientName,
    qint16 edamVersionMajor,
    qint16 edamVersionMinor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->checkVersion(
                clientName,
                edamVersionMajor,
                edamVersionMinor,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "clientName = " << clientName << "\n";
        strm << "edamVersionMajor = " << edamVersionMajor << "\n";
        strm << "edamVersionMinor = " << edamVersionMinor << "\n";
    }

    IDurableService::SyncRequest request(
        "checkVersion",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.toBool();
}

QFuture<QVariant> DurableUserStore::checkVersionAsync(
    QString clientName,
    qint16 edamVersionMajor,
    qint16 edamVersionMinor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->checkVersionAsync(
                clientName,
                edamVersionMajor,
                edamVersionMinor,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "clientName = " << clientName << "\n";
        strm << "edamVersionMajor = " << edamVersionMajor << "\n";
        strm << "edamVersionMinor = " << edamVersionMinor << "\n";
    }

    IDurableService::AsyncRequest request(
        "checkVersion",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

BootstrapInfo DurableUserStore::getBootstrapInfo(
    QString locale,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getBootstrapInfo(
                locale,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "locale = " << locale << "\n";
    }

    IDurableService::SyncRequest request(
        "getBootstrapInfo",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<BootstrapInfo>();
}

QFuture<QVariant> DurableUserStore::getBootstrapInfoAsync(
    QString locale,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->getBootstrapInfoAsync(
                locale,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "locale = " << locale << "\n";
    }

    IDurableService::AsyncRequest request(
        "getBootstrapInfo",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

AuthenticationResult DurableUserStore::authenticateLongSession(
    QString username,
    QString password,
    QString consumerKey,
    QString consumerSecret,
    QString deviceIdentifier,
    QString deviceDescription,
    bool supportsTwoFactor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->authenticateLongSession(
                username,
                password,
                consumerKey,
                consumerSecret,
                deviceIdentifier,
                deviceDescription,
                supportsTwoFactor,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "username = " << username << "\n";
        strm << "deviceIdentifier = " << deviceIdentifier << "\n";
        strm << "deviceDescription = " << deviceDescription << "\n";
        strm << "supportsTwoFactor = " << supportsTwoFactor << "\n";
    }

    IDurableService::SyncRequest request(
        "authenticateLongSession",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AuthenticationResult>();
}

QFuture<QVariant> DurableUserStore::authenticateLongSessionAsync(
    QString username,
    QString password,
    QString consumerKey,
    QString consumerSecret,
    QString deviceIdentifier,
    QString deviceDescription,
    bool supportsTwoFactor,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->authenticateLongSessionAsync(
                username,
                password,
                consumerKey,
                consumerSecret,
                deviceIdentifier,
                deviceDescription,
                supportsTwoFactor,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "username = " << username << "\n";
        strm << "deviceIdentifier = " << deviceIdentifier << "\n";
        strm << "deviceDescription = " << deviceDescription << "\n";
        strm << "supportsTwoFactor = " << supportsTwoFactor << "\n";
    }

    IDurableService::AsyncRequest request(
        "authenticateLongSession",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

AuthenticationResult DurableUserStore::completeTwoFactorAuthentication(
    QString oneTimeCode,
    QString deviceIdentifier,
    QString deviceDescription,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->completeTwoFactorAuthentication(
                oneTimeCode,
                deviceIdentifier,
                deviceDescription,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "deviceIdentifier = " << deviceIdentifier << "\n";
        strm << "deviceDescription = " << deviceDescription << "\n";
    }

    IDurableService::SyncRequest request(
        "completeTwoFactorAuthentication",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AuthenticationResult>();
}

QFuture<QVariant> DurableUserStore::completeTwoFactorAuthenticationAsync(
    QString oneTimeCode,
    QString deviceIdentifier,
    QString deviceDescription,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->completeTwoFactorAuthenticationAsync(
                oneTimeCode,
                deviceIdentifier,
                deviceDescription,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "deviceIdentifier = " << deviceIdentifier << "\n";
        strm << "deviceDescription = " << deviceDescription << "\n";
    }

    IDurableService::AsyncRequest request(
        "completeTwoFactorAuthentication",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

void DurableUserStore::revokeLongSession(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->revokeLongSession(
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    IDurableService::SyncRequest request(
        "revokeLongSession",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<QVariant> DurableUserStore::revokeLongSessionAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->revokeLongSessionAsync(
                ctx);
        });

    IDurableService::AsyncRequest request(
        "revokeLongSession",
        {},
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

AuthenticationResult DurableUserStore::authenticateToBusiness(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->authenticateToBusiness(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "authenticateToBusiness",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AuthenticationResult>();
}

QFuture<QVariant> DurableUserStore::authenticateToBusinessAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->authenticateToBusinessAsync(
                ctx);
        });

    IDurableService::AsyncRequest request(
        "authenticateToBusiness",
        {},
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

User DurableUserStore::getUser(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getUser(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "getUser",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<User>();
}

QFuture<QVariant> DurableUserStore::getUserAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->getUserAsync(
                ctx);
        });

    IDurableService::AsyncRequest request(
        "getUser",
        {},
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

PublicUserInfo DurableUserStore::getPublicUserInfo(
    QString username,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getPublicUserInfo(
                username,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "username = " << username << "\n";
    }

    IDurableService::SyncRequest request(
        "getPublicUserInfo",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<PublicUserInfo>();
}

QFuture<QVariant> DurableUserStore::getPublicUserInfoAsync(
    QString username,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->getPublicUserInfoAsync(
                username,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "username = " << username << "\n";
    }

    IDurableService::AsyncRequest request(
        "getPublicUserInfo",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

UserUrls DurableUserStore::getUserUrls(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getUserUrls(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "getUserUrls",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<UserUrls>();
}

QFuture<QVariant> DurableUserStore::getUserUrlsAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->getUserUrlsAsync(
                ctx);
        });

    IDurableService::AsyncRequest request(
        "getUserUrls",
        {},
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

void DurableUserStore::inviteToBusiness(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->inviteToBusiness(
                emailAddress,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "emailAddress = " << emailAddress << "\n";
    }

    IDurableService::SyncRequest request(
        "inviteToBusiness",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<QVariant> DurableUserStore::inviteToBusinessAsync(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->inviteToBusinessAsync(
                emailAddress,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "emailAddress = " << emailAddress << "\n";
    }

    IDurableService::AsyncRequest request(
        "inviteToBusiness",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

void DurableUserStore::removeFromBusiness(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->removeFromBusiness(
                emailAddress,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "emailAddress = " << emailAddress << "\n";
    }

    IDurableService::SyncRequest request(
        "removeFromBusiness",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<QVariant> DurableUserStore::removeFromBusinessAsync(
    QString emailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->removeFromBusinessAsync(
                emailAddress,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "emailAddress = " << emailAddress << "\n";
    }

    IDurableService::AsyncRequest request(
        "removeFromBusiness",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

void DurableUserStore::updateBusinessUserIdentifier(
    QString oldEmailAddress,
    QString newEmailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            m_service->updateBusinessUserIdentifier(
                oldEmailAddress,
                newEmailAddress,
                ctx);
            return IDurableService::SyncResult(QVariant(), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "oldEmailAddress = " << oldEmailAddress << "\n";
        strm << "newEmailAddress = " << newEmailAddress << "\n";
    }

    IDurableService::SyncRequest request(
        "updateBusinessUserIdentifier",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return;
}

QFuture<QVariant> DurableUserStore::updateBusinessUserIdentifierAsync(
    QString oldEmailAddress,
    QString newEmailAddress,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->updateBusinessUserIdentifierAsync(
                oldEmailAddress,
                newEmailAddress,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "oldEmailAddress = " << oldEmailAddress << "\n";
        strm << "newEmailAddress = " << newEmailAddress << "\n";
    }

    IDurableService::AsyncRequest request(
        "updateBusinessUserIdentifier",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

QList<UserProfile> DurableUserStore::listBusinessUsers(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listBusinessUsers(
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    IDurableService::SyncRequest request(
        "listBusinessUsers",
        {},
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<UserProfile>>();
}

QFuture<QVariant> DurableUserStore::listBusinessUsersAsync(
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->listBusinessUsersAsync(
                ctx);
        });

    IDurableService::AsyncRequest request(
        "listBusinessUsers",
        {},
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

QList<BusinessInvitation> DurableUserStore::listBusinessInvitations(
    bool includeRequestedInvitations,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->listBusinessInvitations(
                includeRequestedInvitations,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "includeRequestedInvitations = " << includeRequestedInvitations << "\n";
    }

    IDurableService::SyncRequest request(
        "listBusinessInvitations",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<QList<BusinessInvitation>>();
}

QFuture<QVariant> DurableUserStore::listBusinessInvitationsAsync(
    bool includeRequestedInvitations,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->listBusinessInvitationsAsync(
                includeRequestedInvitations,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "includeRequestedInvitations = " << includeRequestedInvitations << "\n";
    }

    IDurableService::AsyncRequest request(
        "listBusinessInvitations",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

AccountLimits DurableUserStore::getAccountLimits(
    ServiceLevel serviceLevel,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::SyncServiceCall(
        [&] (IRequestContextPtr ctx)
        {
            auto res = m_service->getAccountLimits(
                serviceLevel,
                ctx);
            return IDurableService::SyncResult(QVariant::fromValue(res), {});
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "serviceLevel = " << serviceLevel << "\n";
    }

    IDurableService::SyncRequest request(
        "getAccountLimits",
        requestDescription,
        std::move(call));

    auto result = m_durableService->executeSyncRequest(
        std::move(request), ctx);

    if (result.second) {
        std::rethrow_exception(result.second);
    }

    return result.first.value<AccountLimits>();
}

QFuture<QVariant> DurableUserStore::getAccountLimitsAsync(
    ServiceLevel serviceLevel,
    IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx.reset(m_ctx->clone());
    }

    auto call = IDurableService::AsyncServiceCall(
        [=, service=m_service] (IRequestContextPtr ctx)
        {
            return service->getAccountLimitsAsync(
                serviceLevel,
                ctx);
        });

    QString requestDescription;
    QTextStream strm(&requestDescription);
    if (logger()->shouldLog(LogLevel::Trace, "durable_service")) {
        strm << "serviceLevel = " << serviceLevel << "\n";
    }

    IDurableService::AsyncRequest request(
        "getAccountLimits",
        requestDescription,
        std::move(call));

    return m_durableService->executeAsyncRequest(
        std::move(request), ctx);

}

////////////////////////////////////////////////////////////////////////////////

IUserStore * newUserStore(
    QString userStoreUrl,
    IRequestContextPtr ctx,
    QObject * parent,
    IRetryPolicyPtr retryPolicy)
{
    if (ctx && ctx->maxRequestRetryCount() == 0)
    {
        return new UserStore(std::move(userStoreUrl), ctx);
    }
    else
    {
        if (!retryPolicy) {
            retryPolicy = newRetryPolicy();
        }

        return new DurableUserStore(
            std::make_shared<UserStore>(std::move(userStoreUrl), ctx),
            ctx,
            retryPolicy,
            parent);
    }
}

} // namespace qevercloud

#include <UserStore.moc>
