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
    void CheckVersionRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetBootstrapInfoRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void AuthenticateLongSessionRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CompleteTwoFactorAuthenticationRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void RevokeLongSessionRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onRevokeLongSessionRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                ctx);
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void AuthenticateToBusinessRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetUserRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetPublicUserInfoRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetUserUrlsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void InviteToBusinessRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void RemoveFromBusinessRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateBusinessUserIdentifierRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListBusinessUsersRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListBusinessInvitationsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetAccountLimitsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
