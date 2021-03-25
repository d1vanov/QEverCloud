/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_USERSTORESERVER
#define QEVERCLOUD_GENERATED_USERSTORESERVER

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/Types.h>
#include <QObject>
#include <functional>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The UserStoreServer class represents
 * customizable server for UserStore requests.
 * It is primarily used for testing of QEverCloud
 */
class QEVERCLOUD_EXPORT UserStoreServer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UserStoreServer)
public:
    explicit UserStoreServer(QObject * parent = nullptr);

Q_SIGNALS:
    // Signals notifying listeners about incoming requests
    void checkVersionRequest(
        QString clientName,
        qint16 edamVersionMajor,
        qint16 edamVersionMinor,
        IRequestContextPtr ctx);

    void getBootstrapInfoRequest(
        QString locale,
        IRequestContextPtr ctx);

    void authenticateLongSessionRequest(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx);

    void completeTwoFactorAuthenticationRequest(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx);

    void revokeLongSessionRequest(
        IRequestContextPtr ctx);

    void authenticateToBusinessRequest(
        IRequestContextPtr ctx);

    void getUserRequest(
        IRequestContextPtr ctx);

    void getPublicUserInfoRequest(
        QString username,
        IRequestContextPtr ctx);

    void getUserUrlsRequest(
        IRequestContextPtr ctx);

    void inviteToBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void removeFromBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void updateBusinessUserIdentifierRequest(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx);

    void listBusinessUsersRequest(
        IRequestContextPtr ctx);

    void listBusinessInvitationsRequest(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx);

    void getAccountLimitsRequest(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx);

    // Signals used to send encoded response data
    void checkVersionRequestReady(
        QByteArray data);

    void getBootstrapInfoRequestReady(
        QByteArray data);

    void authenticateLongSessionRequestReady(
        QByteArray data);

    void completeTwoFactorAuthenticationRequestReady(
        QByteArray data);

    void revokeLongSessionRequestReady(
        QByteArray data);

    void authenticateToBusinessRequestReady(
        QByteArray data);

    void getUserRequestReady(
        QByteArray data);

    void getPublicUserInfoRequestReady(
        QByteArray data);

    void getUserUrlsRequestReady(
        QByteArray data);

    void inviteToBusinessRequestReady(
        QByteArray data);

    void removeFromBusinessRequestReady(
        QByteArray data);

    void updateBusinessUserIdentifierRequestReady(
        QByteArray data);

    void listBusinessUsersRequestReady(
        QByteArray data);

    void listBusinessInvitationsRequestReady(
        QByteArray data);

    void getAccountLimitsRequestReady(
        QByteArray data);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    // Slots for replies to requests
    void onCheckVersionRequestReady(
        bool value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetBootstrapInfoRequestReady(
        BootstrapInfo value,
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateLongSessionRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onCompleteTwoFactorAuthenticationRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onRevokeLongSessionRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateToBusinessRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetUserRequestReady(
        User value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetPublicUserInfoRequestReady(
        PublicUserInfo value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetUserUrlsRequestReady(
        UserUrls value,
        EverCloudExceptionDataPtr exceptionData);

    void onInviteToBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onRemoveFromBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateBusinessUserIdentifierRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onListBusinessUsersRequestReady(
        QList<UserProfile> value,
        EverCloudExceptionDataPtr exceptionData);

    void onListBusinessInvitationsRequestReady(
        QList<BusinessInvitation> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetAccountLimitsRequestReady(
        AccountLimits value,
        EverCloudExceptionDataPtr exceptionData);

};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERSTORESERVER
