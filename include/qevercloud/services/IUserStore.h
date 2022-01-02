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

#ifndef QEVERCLOUD_GENERATED_IUSERSTORE
#define QEVERCLOUD_GENERATED_IUSERSTORE

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/DurableService.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/Types.h>
#include <QFuture>
#include <QObject>
#include <QVariant>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * Service:  UserStore
 * <p>
 * The UserStore service is primarily used by EDAM clients to establish
 * authentication via username and password over a trusted connection (e.g.
 * SSL).  A client's first call to this interface should be checkVersion() to
 * ensure that the client's software is up to date.
 * </p>
 * All calls which require an authenticationToken may throw an
 * EDAMUserException for the following reasons:
 *  <ul>
 *   <li> AUTH_EXPIRED "authenticationToken" - token has expired
 *   <li> BAD_DATA_FORMAT "authenticationToken" - token is malformed
 *   <li> DATA_REQUIRED "authenticationToken" - token is empty
 *   <li> INVALID_AUTH "authenticationToken" - token signature is invalid
 *   <li> PERMISSION_DENIED "authenticationToken" - token does not convey sufficient
 *     privileges
 * </ul>
 */
class QEVERCLOUD_EXPORT IUserStore: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(IUserStore)
protected:
    IUserStore(QObject * parent) :
        QObject(parent)
    {}

public:
    virtual QString userStoreUrl() const = 0;
    virtual void setUserStoreUrl(QString url) = 0;

    /**
       * This should be the first call made by a client to the EDAM service.  It
       * tells the service what protocol version is used by the client.  The
       * service will then return true if the client is capable of talking to
       * the service, and false if the client's protocol version is incompatible
       * with the service, so the client must upgrade.  If a client receives a
       * false value, it should report the incompatibility to the user and not
       * continue with any more EDAM requests (UserStore or NoteStore).
       *
       * @param clientName
       *   This string provides some information about the client for
       *   tracking/logging on the service.  It should provide information about
       *   the client's software and platform. The structure should be:
       *   application/version; platform/version; [ device/version ]
       *   E.g. "Evernote Windows/3.0.1; Windows/XP SP3".
       *
       * @param edamVersionMajor
       *   This should be the major protocol version that was compiled by the
       *   client.  This should be the current value of the EDAM_VERSION_MAJOR
       *   constant for the client.
       *
       * @param edamVersionMinor
       *   This should be the major protocol version that was compiled by the
       *   client.  This should be the current value of the EDAM_VERSION_MINOR
       *   constant for the client.
       */
    virtual bool checkVersion(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link checkVersion @endlink */
    virtual QFuture<QVariant> checkVersionAsync(
        QString clientName,
        qint16 edamVersionMajor = EDAM_VERSION_MAJOR,
        qint16 edamVersionMinor = EDAM_VERSION_MINOR,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This provides bootstrap information to the client. Various bootstrap
       * profiles and settings may be used by the client to configure itself.
       *
       * @param locale
       *   The client's current locale, expressed in language[_country]
       *   format. E.g., "en_US". See ISO-639 and ISO-3166 for valid
       *   language and country codes.
       *
       * @return
       *   The bootstrap information suitable for this client.
       */
    virtual BootstrapInfo getBootstrapInfo(
        QString locale,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getBootstrapInfo @endlink */
    virtual QFuture<QVariant> getBootstrapInfoAsync(
        QString locale,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This is used to check a username and password in order to create a
       * long-lived authentication token that can be used for further actions.
       *
       * This function is not available to most third party applications,
       * which typically authenticate using OAuth as
       * described at
       * <a href="http://dev.evernote.com/documentation/cloud/">dev.evernote.com</a>.
       * If you believe that your application requires permission to authenticate
       * using username and password instead of OAuth, please contact Evernote
       * developer support by visiting
       * <a href="http://dev.evernote.com">dev.evernote.com</a>.
       *
       * @param username
       *   The username or registered email address of the account to
       *   authenticate against.
       *
       * @param password
       *   The plaintext password to check against the account.  Since
       *   this is not protected by the EDAM protocol, this information must be
       *   provided over a protected transport (i.e. SSL).
       *
       * @param consumerKey
       *   The "consumer key" portion of the API key issued to the client application
       *   by Evernote.
       *
       * @param consumerSecret
       *   The "consumer secret" portion of the API key issued to the client application
       *   by Evernote.
       *
       * @param deviceIdentifier
       *   An optional string that uniquely identifies the device from which the
       *   authentication is being performed. This string allows the service to return the
       *   same authentication token when a given application requests authentication
       *   repeatedly from the same device. This may happen when the user logs out of an
       *   application and then logs back in, or when the application is uninstalled
       *   and later reinstalled. If no reliable device identifier can be created,
       *   this value should be omitted. If set, the device identifier must be between
       *   1 and EDAM_DEVICE_ID_LEN_MAX characters long and must match the regular expression
       *   EDAM_DEVICE_ID_REGEX.
       *
       * @param deviceDescription
       *   A description of the device from which the authentication is being performed.
       *   This field is displayed to the user in a list of authorized applications to
       *   allow them to distinguish between multiple tokens issued to the same client
       *   application on different devices. For example, the Evernote iOS client on
       *   a user's iPhone and iPad might pass the iOS device names "Bob's iPhone" and
       *   "Bob's iPad". The device description must be between 1 and
       *   EDAM_DEVICE_DESCRIPTION_LEN_MAX characters long and must match the regular
       *   expression EDAM_DEVICE_DESCRIPTION_REGEX.
       *
       * @param supportsTwoFactor
       *   Whether the calling application supports two-factor authentication. If this
       *   parameter is false, this method will fail with the error code INVALID_AUTH and the
       *   parameter "password" when called for a user who has enabled two-factor
       *   authentication.
       *
       * @return
       *   <p>The result of the authentication. The level of detail provided in the returned
       *   AuthenticationResult.User structure depends on the access level granted by
       *   calling application's API key.</p>
       *   <p>If the user has two-factor authentication enabled,
       *   AuthenticationResult.secondFactorRequired will be set and
       *   AuthenticationResult.authenticationToken will contain a short-lived token
       *   that may only be used to complete the two-factor authentication process by calling
       *   UserStore.completeTwoFactorAuthentication.</p>
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "username" - username is empty
       *   <li> DATA_REQUIRED "password" - password is empty
       *   <li> DATA_REQUIRED "consumerKey" - consumerKey is empty
       *   <li> DATA_REQUIRED "consumerSecret" - consumerSecret is empty
       *   <li> DATA_REQUIRED "deviceDescription" - deviceDescription is empty
       *   <li> BAD_DATA_FORMAT "deviceDescription" - deviceDescription is not valid.
       *   <li> BAD_DATA_FORMAT "deviceIdentifier" - deviceIdentifier is not valid.
       *   <li> INVALID_AUTH "username" - username not found
       *   <li> INVALID_AUTH "password" - password did not match
       *   <li> INVALID_AUTH "consumerKey" - consumerKey is not authorized
       *   <li> INVALID_AUTH "consumerSecret" - consumerSecret is incorrect
       *   <li> INVALID_AUTH "businessOnly" - the user is a business-only account
       *   <li> PERMISSION_DENIED "User.active" - user account is closed
       *   <li> PERMISSION_DENIED "User.tooManyFailuresTryAgainLater" - user has
       *     failed authentication too often
       *   <li> AUTH_EXPIRED "password" - user password is expired
       * </ul>
       */
    virtual AuthenticationResult authenticateLongSession(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link authenticateLongSession @endlink */
    virtual QFuture<QVariant> authenticateLongSessionAsync(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Complete the authentication process when a second factor is required. This
       * call is made after a successful call to authenticate or authenticateLongSession
       * when the authenticating user has enabled two-factor authentication.
       *
       * @param authenticationToken An authentication token returned by a previous
       *   call to UserStore.authenticate or UserStore.authenticateLongSession that
       *   could not be completed in a single call because a second factor was required.
       *
       * @param oneTimeCode The one time code entered by the user. This value is delivered
       *   out-of-band, typically via SMS or an authenticator application.
       *
       * @param deviceIdentifier See the corresponding parameter in authenticateLongSession.
       *
       * @param deviceDescription See the corresponding parameter in authenticateLongSession.
       *
       * @return
       *   The result of the authentication. The level of detail provided in the returned
       *   AuthenticationResult.User structure depends on the access level granted by the
       *   calling application's API key. If the initial authentication call was made to
       *   authenticateLongSession, the AuthenticationResult will contain a long-lived
       *   authentication token.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "authenticationToken" - authenticationToken is empty
       *   <li> DATA_REQUIRED "oneTimeCode" - oneTimeCode is empty
       *   <li> BAD_DATA_FORMAT "deviceIdentifier" - deviceIdentifier is not valid
       *   <li> BAD_DATA_FORMAT "authenticationToken" - authenticationToken is not well formed
       *   <li> INVALID_AUTH "oneTimeCode" - oneTimeCode did not match
       *   <li> AUTH_EXPIRED "authenticationToken" - authenticationToken has expired
       *   <li> PERMISSION_DENIED "authenticationToken" - authenticationToken is not valid
       *   <li> PERMISSION_DENIED "User.active" - user account is closed
       *   <li> PERMISSION_DENIED "User.tooManyFailuresTryAgainLater" - user has
       *     failed authentication too often
       *   <li> DATA_CONFLICT "User.twoFactorAuthentication" - The user has not enabled
       *      two-factor authentication.</li>
       * </ul>
       */
    virtual AuthenticationResult completeTwoFactorAuthentication(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link completeTwoFactorAuthentication @endlink */
    virtual QFuture<QVariant> completeTwoFactorAuthenticationAsync(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Revoke an existing long lived authentication token. This can be used to
       * revoke OAuth tokens or tokens created by calling authenticateLongSession,
       * and allows a user to effectively log out of Evernote from the perspective
       * of the application that holds the token. The authentication token that is
       * passed is immediately revoked and may not be used to call any authenticated
       * EDAM function.
       *
       * @param authenticationToken the authentication token to revoke.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "authenticationToken" - no authentication token provided
       *   <li> BAD_DATA_FORMAT "authenticationToken" - the authentication token is not well formed
       *   <li> INVALID_AUTH "authenticationToken" - the authentication token is invalid
       *   <li> AUTH_EXPIRED "authenticationToken" - the authentication token is expired or
       *     is already revoked.
       * </ul>
       */
    virtual void revokeLongSession(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link revokeLongSession @endlink */
    virtual QFuture<QVariant> revokeLongSessionAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This is used to take an existing authentication token that grants access
       * to an individual user account (returned from 'authenticate',
       * 'authenticateLongSession' or an OAuth authorization) and obtain an additional
       * authentication token that may be used to access business notebooks if the user
       * is a member of an Evernote Business account.
       *
       * The resulting authentication token may be used to make NoteStore API calls
       * against the business using the NoteStore URL returned in the result.
       *
       * @param authenticationToken
       *   The authentication token for the user. This may not be a shared authentication
       *   token (returned by NoteStore.authenticateToSharedNotebook or
       *   NoteStore.authenticateToSharedNote) or a business authentication token.
       *
       * @return
       *   The result of the authentication, with the token granting access to the
       *   business in the result's 'authenticationToken' field. The URL that must
       *   be used to access the business account NoteStore will be returned in the
       *   result's 'noteStoreUrl' field.  The 'User' field will
       *   not be set in the result.
       *
       * @throws EDAMUserException <ul>
       *   <li> PERMISSION_DENIED "authenticationToken" - the provided authentication token
       *        is a shared or business authentication token. </li>
       *   <li> PERMISSION_DENIED "Business" - the user identified by the provided
       *        authentication token is not currently a member of a business. </li>
       *   <li> PERMISSION_DENIED "Business.status" - the business that the user is a
       *        member of is not currently in an active status. </li>
       *   <li> BUSINESS_SECURITY_LOGIN_REQUIRED "sso" - the user must complete single
       *        sign-on before authenticating to the business.
       * </ul>
       */
    virtual AuthenticationResult authenticateToBusiness(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link authenticateToBusiness @endlink */
    virtual QFuture<QVariant> authenticateToBusinessAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the User corresponding to the provided authentication token,
       * or throws an exception if this token is not valid.
       * The level of detail provided in the returned User structure depends on
       * the access level granted by the token, so a web service client may receive
       * fewer fields than an integrated desktop client.
       */
    virtual User getUser(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getUser @endlink */
    virtual QFuture<QVariant> getUserAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the UserStore about the publicly available location information for
       * a particular username.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "username" - username is empty
       * </ul>
       */
    virtual PublicUserInfo getPublicUserInfo(
        QString username,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getPublicUserInfo @endlink */
    virtual QFuture<QVariant> getPublicUserInfoAsync(
        QString username,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * <p>Returns the URLs that should be used when sending requests to the service on
       * behalf of the account represented by the provided authenticationToken.</p>
       *
       * <p>This method isn't needed by most clients, who can retrieve the correct set of
       * UserUrls from the AuthenticationResult returned from
       * UserStore#authenticateLongSession(). This method is typically only needed to look up
       * the correct URLs for an existing long-lived authentication token.</p>
       */
    virtual UserUrls getUserUrls(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getUserUrls @endlink */
    virtual QFuture<QVariant> getUserUrlsAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Invite a user to join an Evernote Business account.
       *
       * Behavior will depend on the auth token. <ol>
       *   <li>
       *     auth token with privileges to manage Evernote Business membership.
       *       "External Provisioning" - The user will receive an email inviting
       *       them to join the business. They do not need to have an existing Evernote
       *       account. If the user has already been invited, a new invitation email
       *       will be sent.
       *   </li>
       *   <li>
       *     business auth token issued to an admin user. Only for first-party clients:
       *       "Approve Invitation" - If there has been a request to invite the email,
       *       approve it. Invited user will receive email with a link to join business.
       *       "Invite User" - If no invitation for the email exists, create an approved
       *       invitation for the email. An email will be sent to the emailAddress with
       *       a link to join the caller's business.
       *   </li>
       *   </li>
       *     business auth token:
       *       "Request Invitation" - If no invitation exists, create a request to
       *       invite the user to the business. These requests do not count towards a
       *       business' max active user limit.
       *   </li>
       * </ol>
       *
       * @param authenticationToken
       *   the authentication token with sufficient privileges to manage Evernote Business
       *   membership or a business auth token.
       *
       * @param emailAddress
       *   the email address of the user to invite to join the Evernote Business account.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "email" - if no email address was provided </li>
       *   <li> BAD_DATA_FORMAT "email" - if the email address is not well formed </li>
       *   <li> DATA_CONFLICT "BusinessUser.email" - if there is already a user in the business
       *     whose business email address matches the specified email address. </li>
       *   <li> LIMIT_REACHED "Business.maxActiveUsers" - if the business has reached its
       *     user limit. </li>
       * </ul>
       */
    virtual void inviteToBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link inviteToBusiness @endlink */
    virtual QFuture<QVariant> inviteToBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Remove a user from an Evernote Business account. Once removed, the user will no
       * longer be able to access content within the Evernote Business account.
       *
       * <p>The email address of the user to remove from the business must match the email
       * address used to invite a user to join the business via UserStore.inviteToBusiness.
       * This function will only remove users who were invited by external provisioning</p>
       *
       * @param authenticationToken
       *   An authentication token with sufficient privileges to manage Evernote Business
       *   membership.
       *
       * @param emailAddress
       *   The email address of the user to remove from the Evernote Business account.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "email" - if no email address was provided </li>
       *   <li> BAD_DATA_FORMAT "email" - The email address is not well formed </li>
       * </ul>
       * @throws EDAMNotFoundException <ul>
       *   <li> "email" - If there is no user with the specified email address in the
       *     business or that user was not invited via external provisioning. </li>
       * </ul>
       */
    virtual void removeFromBusiness(
        QString emailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link removeFromBusiness @endlink */
    virtual QFuture<QVariant> removeFromBusinessAsync(
        QString emailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Update the email address used to uniquely identify an Evernote Business user.
       *
       * This will update the identifier for a user who was previously invited using
       * inviteToBusiness, ensuring that caller and the Evernote service maintain an
       * agreed-upon identifier for a specific user.
       *
       * For example, the following sequence of calls would invite a user to join
       * a business, update their email address, and then remove the user
       * from the business using the updated email address.
       *
       * inviteToBusiness("foo@bar.com")
       * updateBusinessUserIdentifier("foo@bar.com", "baz@bar.com")
       * removeFromBusiness("baz@bar.com")
       *
       * @param authenticationToken
       *   An authentication token with sufficient privileges to manage Evernote Business
       *   membership.
       *
       * @param oldEmailAddress
       *   The existing email address used to uniquely identify the user.
       *
       * @param newEmailAddress
       *   The new email address used to uniquely identify the user.
       *
       * @throws EDAMUserException <ul>
       *   <li>DATA_REQUIRED "oldEmailAddress" - No old email address was provided</li>
       *   <li>DATA_REQUIRED "newEmailAddress" - No new email address was provided</li>
       *   <li>BAD_DATA_FORMAT "oldEmailAddress" - The old email address is not well formed</li>
       *   <li>BAD_DATA_FORMAT "newEmailAddress" - The new email address is not well formed</li>
       *   <li>DATA_CONFLICT "oldEmailAddress" - The old and new email addresses were the same</li>
       *   <li>DATA_CONFLICT "newEmailAddress" - There is already an invitation or registered user with
       *     the provided new email address.</li>
       *   <li>DATA_CONFLICT "invitation.externallyProvisioned" - The user identified by
       *     oldEmailAddress was not added via UserStore.inviteToBusiness and therefore cannot be
       *     updated.</li>
       * </ul>
       * @throws EDAMNotFoundException <ul>
       *   <li>"oldEmailAddress" - If there is no user or invitation with the specified oldEmailAddress
       *     in the business.</li>
       * </ul>
       */
    virtual void updateBusinessUserIdentifier(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateBusinessUserIdentifier @endlink */
    virtual QFuture<QVariant> updateBusinessUserIdentifierAsync(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of active business users in a given business.
       *
       * Clients are required to cache this information and re-fetch no more than once per day
       * or when they encountered a user ID or username that was not known to them.
       *
       * To avoid excessive look ups, clients should also track user IDs and usernames that belong
       * to users who are not in the business, since they will not be included in the result.
       *
       * I.e., when a client encounters a previously unknown user ID as a note's creator, it may query
       * listBusinessUsers to find information about this user. If the user is not in the resulting
       * list, the client should track that fact and not re-query the service the next time that it sees
       * this user on a note.
       *
       * @param authenticationToken
       *   A business authentication token returned by authenticateToBusiness or with sufficient
       *   privileges to manage Evernote Business membership.
       */
    virtual QList<UserProfile> listBusinessUsers(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listBusinessUsers @endlink */
    virtual QFuture<QVariant> listBusinessUsersAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of outstanding invitations to join an Evernote Business account.
       *
       * Only outstanding invitations are returned by this function. Users who have accepted an
       * invitation and joined a business are listed using listBusinessUsers.
       *
       * @param authenticationToken
       *   An authentication token with sufficient privileges to manage Evernote Business membership.
       *
       * @param includeRequestedInvitations
       *   If true, invitations with a status of BusinessInvitationStatus.REQUESTED will be included
       *   in the returned list. If false, only invitations with a status of
       *   BusinessInvitationStatus.APPROVED will be included.
       */
    virtual QList<BusinessInvitation> listBusinessInvitations(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listBusinessInvitations @endlink */
    virtual QFuture<QVariant> listBusinessInvitationsAsync(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Retrieve the standard account limits for a given service level. This should only be
       * called when necessary, e.g. to determine if a higher level is available should the
       * user upgrade, and should be cached for long periods (e.g. 30 days) as the values are
       * not expected to fluctuate frequently.
       *
       * @throws EDAMUserException <ul>
       *   <li>DATA_REQUIRED "serviceLevel" - serviceLevel is null</li>
       * </ul>
       */
    virtual AccountLimits getAccountLimits(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getAccountLimits @endlink */
    virtual QFuture<QVariant> getAccountLimitsAsync(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx = {}) = 0;

};

using IUserStorePtr = std::shared_ptr<IUserStore>;

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT IUserStore * newUserStore(
    QString userStoreUrl = {},
    IRequestContextPtr ctx = {},
    QObject * parent = nullptr,
    IRetryPolicyPtr retryPolicy = {});

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_IUSERSTORE
