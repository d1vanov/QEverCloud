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
#include <generated/Servers.h>

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
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetBootstrapInfo()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateLongSession()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteCompleteTwoFactorAuthentication()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRevokeLongSession()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateToBusiness()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUser()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetPublicUserInfo()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUserUrls()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteInviteToBusiness()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRemoveFromBusiness()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteUpdateBusinessUserIdentifier()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessUsers()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessInvitations()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetAccountLimits()
{
    // TODO: implement
}

} // namespace qevercloud

#include <TestUserStore.moc>
