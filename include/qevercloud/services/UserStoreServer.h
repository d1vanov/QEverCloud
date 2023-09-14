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

#ifndef QEVERCLOUD_GENERATED_USERSTORESERVER
#define QEVERCLOUD_GENERATED_USERSTORESERVER

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/IRequestContext.h>
#include <qevercloud/Types.h>
#include <QObject>
#include <exception>
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
        QByteArray data, QUuid requestId);

    void getBootstrapInfoRequestReady(
        QByteArray data, QUuid requestId);

    void authenticateLongSessionRequestReady(
        QByteArray data, QUuid requestId);

    void completeTwoFactorAuthenticationRequestReady(
        QByteArray data, QUuid requestId);

    void revokeLongSessionRequestReady(
        QByteArray data, QUuid requestId);

    void authenticateToBusinessRequestReady(
        QByteArray data, QUuid requestId);

    void getUserRequestReady(
        QByteArray data, QUuid requestId);

    void getPublicUserInfoRequestReady(
        QByteArray data, QUuid requestId);

    void getUserUrlsRequestReady(
        QByteArray data, QUuid requestId);

    void inviteToBusinessRequestReady(
        QByteArray data, QUuid requestId);

    void removeFromBusinessRequestReady(
        QByteArray data, QUuid requestId);

    void updateBusinessUserIdentifierRequestReady(
        QByteArray data, QUuid requestId);

    void listBusinessUsersRequestReady(
        QByteArray data, QUuid requestId);

    void listBusinessInvitationsRequestReady(
        QByteArray data, QUuid requestId);

    void getAccountLimitsRequestReady(
        QByteArray data, QUuid requestId);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data, QUuid requestId);

    // Slots for replies to requests
    void onCheckVersionRequestReady(
        bool value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetBootstrapInfoRequestReady(
        BootstrapInfo value,
        std::exception_ptr e,
        QUuid requestId);

    void onAuthenticateLongSessionRequestReady(
        AuthenticationResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onCompleteTwoFactorAuthenticationRequestReady(
        AuthenticationResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onRevokeLongSessionRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onAuthenticateToBusinessRequestReady(
        AuthenticationResult value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetUserRequestReady(
        User value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetPublicUserInfoRequestReady(
        PublicUserInfo value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetUserUrlsRequestReady(
        UserUrls value,
        std::exception_ptr e,
        QUuid requestId);

    void onInviteToBusinessRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onRemoveFromBusinessRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onUpdateBusinessUserIdentifierRequestReady(
        std::exception_ptr e,
        QUuid requestId);

    void onListBusinessUsersRequestReady(
        QList<UserProfile> value,
        std::exception_ptr e,
        QUuid requestId);

    void onListBusinessInvitationsRequestReady(
        QList<BusinessInvitation> value,
        std::exception_ptr e,
        QUuid requestId);

    void onGetAccountLimitsRequestReady(
        AccountLimits value,
        std::exception_ptr e,
        QUuid requestId);

};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERSTORESERVER
