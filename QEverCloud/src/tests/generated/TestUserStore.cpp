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

#include "TestUserStore.h"
#include "../../Impl.h"
#include "../Common.h"
#include <generated/Servers.h>
#include <generated/Services.h>
#include <QTcpServer>
#include <QtTest/QtTest>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

UserStoreTester::UserStoreTester(QObject * parent) :
    QObject(parent)
{}

////////////////////////////////////////////////////////////////////////////////

class UserStoreCheckVersionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        bool(
            QString,
            qint16,
            qint16,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreCheckVersionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void checkVersionRequestReady(
        bool value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCheckVersionRequestReceived(
        QString clientName,
        qint16 edamVersionMajor,
        qint16 edamVersionMinor,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                clientName,
                edamVersionMajor,
                edamVersionMinor,
                ctx);

            Q_EMIT checkVersionRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT checkVersionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetBootstrapInfoTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        BootstrapInfo(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetBootstrapInfoTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getBootstrapInfoRequestReady(
        BootstrapInfo value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetBootstrapInfoRequestReceived(
        QString locale,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                locale,
                ctx);

            Q_EMIT getBootstrapInfoRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getBootstrapInfoRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateLongSessionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            QString,
            QString,
            QString,
            QString,
            QString,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreAuthenticateLongSessionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateLongSessionRequestReady(
        AuthenticationResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onAuthenticateLongSessionRequestReceived(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                username,
                password,
                consumerKey,
                consumerSecret,
                deviceIdentifier,
                deviceDescription,
                supportsTwoFactor,
                ctx);

            Q_EMIT authenticateLongSessionRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateLongSessionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreCompleteTwoFactorAuthenticationTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreCompleteTwoFactorAuthenticationTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void completeTwoFactorAuthenticationRequestReady(
        AuthenticationResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCompleteTwoFactorAuthenticationRequestReceived(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                oneTimeCode,
                deviceIdentifier,
                deviceDescription,
                ctx);

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRevokeLongSessionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreRevokeLongSessionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void revokeLongSessionRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onRevokeLongSessionRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                ctx);

            Q_EMIT revokeLongSessionRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT revokeLongSessionRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateToBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreAuthenticateToBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateToBusinessRequestReady(
        AuthenticationResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onAuthenticateToBusinessRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT authenticateToBusinessRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateToBusinessRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        User(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetUserTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getUserRequestReady(
        User value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetUserRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getUserRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getUserRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetPublicUserInfoTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        PublicUserInfo(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetPublicUserInfoTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getPublicUserInfoRequestReady(
        PublicUserInfo value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetPublicUserInfoRequestReceived(
        QString username,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                username,
                ctx);

            Q_EMIT getPublicUserInfoRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getPublicUserInfoRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserUrlsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        UserUrls(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetUserUrlsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getUserUrlsRequestReady(
        UserUrls value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetUserUrlsRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getUserUrlsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getUserUrlsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreInviteToBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreInviteToBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void inviteToBusinessRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onInviteToBusinessRequestReceived(
        QString emailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                emailAddress,
                ctx);

            Q_EMIT inviteToBusinessRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT inviteToBusinessRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRemoveFromBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreRemoveFromBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void removeFromBusinessRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onRemoveFromBusinessRequestReceived(
        QString emailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                emailAddress,
                ctx);

            Q_EMIT removeFromBusinessRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT removeFromBusinessRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreUpdateBusinessUserIdentifierTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreUpdateBusinessUserIdentifierTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateBusinessUserIdentifierRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateBusinessUserIdentifierRequestReceived(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                oldEmailAddress,
                newEmailAddress,
                ctx);

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateBusinessUserIdentifierRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessUsersTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<UserProfile>(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreListBusinessUsersTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listBusinessUsersRequestReady(
        QList<UserProfile> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListBusinessUsersRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listBusinessUsersRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listBusinessUsersRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessInvitationsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<BusinessInvitation>(
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreListBusinessInvitationsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listBusinessInvitationsRequestReady(
        QList<BusinessInvitation> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListBusinessInvitationsRequestReceived(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                includeRequestedInvitations,
                ctx);

            Q_EMIT listBusinessInvitationsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listBusinessInvitationsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetAccountLimitsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AccountLimits(
            ServiceLevel,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetAccountLimitsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getAccountLimitsRequestReady(
        AccountLimits value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetAccountLimitsRequestReceived(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                serviceLevel,
                ctx);

            Q_EMIT getAccountLimitsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getAccountLimitsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteCheckVersion()
{
    QString clientName = tests::generateRandomString();
    qint16 edamVersionMajor = tests::generateRandomInt16();
    qint16 edamVersionMinor = tests::generateRandomInt16();
    IRequestContextPtr ctx = newRequestContext();

    bool response = tests::generateRandomBool();

    UserStoreCheckVersionTesterHelper helper(
        [&] (const QString & clientNameParam,
             qint16 edamVersionMajorParam,
             qint16 edamVersionMinorParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(clientName == clientNameParam);
            Q_ASSERT(edamVersionMajor == edamVersionMajorParam);
            Q_ASSERT(edamVersionMinor == edamVersionMinorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequest,
        &helper,
        &UserStoreCheckVersionTesterHelper::onCheckVersionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCheckVersionTesterHelper::checkVersionRequestReady,
        &server,
        &UserStoreServer::onCheckVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    bool res = userStore->checkVersion(
        clientName,
        edamVersionMajor,
        edamVersionMinor,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetBootstrapInfo()
{
    QString locale = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    BootstrapInfo response = tests::generateBootstrapInfo();

    UserStoreGetBootstrapInfoTesterHelper helper(
        [&] (const QString & localeParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(locale == localeParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequest,
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::onGetBootstrapInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::getBootstrapInfoRequestReady,
        &server,
        &UserStoreServer::onGetBootstrapInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    BootstrapInfo res = userStore->getBootstrapInfo(
        locale,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateLongSession()
{
    QString username = tests::generateRandomString();
    QString password = tests::generateRandomString();
    QString consumerKey = tests::generateRandomString();
    QString consumerSecret = tests::generateRandomString();
    QString deviceIdentifier = tests::generateRandomString();
    QString deviceDescription = tests::generateRandomString();
    bool supportsTwoFactor = tests::generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    AuthenticationResult response = tests::generateAuthenticationResult();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    AuthenticationResult res = userStore->authenticateLongSession(
        username,
        password,
        consumerKey,
        consumerSecret,
        deviceIdentifier,
        deviceDescription,
        supportsTwoFactor,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteCompleteTwoFactorAuthentication()
{
    QString oneTimeCode = tests::generateRandomString();
    QString deviceIdentifier = tests::generateRandomString();
    QString deviceDescription = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = tests::generateAuthenticationResult();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    AuthenticationResult res = userStore->completeTwoFactorAuthentication(
        oneTimeCode,
        deviceIdentifier,
        deviceDescription,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRevokeLongSession()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    userStore->revokeLongSession(
        ctx);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateToBusiness()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = tests::generateAuthenticationResult();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    AuthenticationResult res = userStore->authenticateToBusiness(
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUser()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    User response = tests::generateUser();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    User res = userStore->getUser(
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetPublicUserInfo()
{
    QString username = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    PublicUserInfo response = tests::generatePublicUserInfo();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(username == usernameParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    PublicUserInfo res = userStore->getPublicUserInfo(
        username,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUserUrls()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserUrls response = tests::generateUserUrls();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    UserUrls res = userStore->getUserUrls(
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteInviteToBusiness()
{
    QString emailAddress = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    userStore->inviteToBusiness(
        emailAddress,
        ctx);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRemoveFromBusiness()
{
    QString emailAddress = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    userStore->removeFromBusiness(
        emailAddress,
        ctx);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = tests::generateRandomString();
    QString newEmailAddress = tests::generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    userStore->updateBusinessUserIdentifier(
        oldEmailAddress,
        newEmailAddress,
        ctx);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessUsers()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<UserProfile> response;
    response << tests::generateUserProfile();
    response << tests::generateUserProfile();
    response << tests::generateUserProfile();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    QList<UserProfile> res = userStore->listBusinessUsers(
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessInvitations()
{
    bool includeRequestedInvitations = tests::generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<BusinessInvitation> response;
    response << tests::generateBusinessInvitation();
    response << tests::generateBusinessInvitation();
    response << tests::generateBusinessInvitation();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    QList<BusinessInvitation> res = userStore->listBusinessInvitations(
        includeRequestedInvitations,
        ctx);
    QVERIFY(res == response);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetAccountLimits()
{
    ServiceLevel serviceLevel = ServiceLevel::BASIC;
    IRequestContextPtr ctx = newRequestContext();

    AccountLimits response = tests::generateAccountLimits();

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam)
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = tests::readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!tests::writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto userStore = newUserStore(
        QStringLiteral("127.0.0.1"),
        port,
        QStringLiteral("http"));
    AccountLimits res = userStore->getAccountLimits(
        serviceLevel,
        ctx);
    QVERIFY(res == response);
}

} // namespace qevercloud

#include <TestUserStore.moc>
