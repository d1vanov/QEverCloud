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

#ifndef QEVERCLOUD_GENERATED_AUTHENTICATIONRESULT_H
#define QEVERCLOUD_GENERATED_AUTHENTICATIONRESULT_H

#include <qevercloud/Export.h>

#include "PublicUserInfo.h"
#include "User.h"
#include "UserUrls.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * When an authentication (or re-authentication) is performed, this structure
 * provides the result to the client.
 **/
class QEVERCLOUD_EXPORT AuthenticationResult: public Printable
{
    Q_GADGET
public:
    AuthenticationResult();
    AuthenticationResult(const AuthenticationResult & other);
    AuthenticationResult(AuthenticationResult && other) noexcept;
    ~AuthenticationResult() noexcept override;

    AuthenticationResult & operator=(const AuthenticationResult & other);
    AuthenticationResult & operator=(AuthenticationResult && other) noexcept;

    /**
     * The server-side date and time when this result was
     * generated.
     */
    [[nodiscard]] Timestamp currentTime() const noexcept;
    void setCurrentTime(Timestamp currentTime);

    /**
     * Holds an opaque, ASCII-encoded token that can be
     * used by the client to perform actions on a NoteStore.
     */
    [[nodiscard]] const QString & authenticationToken() const noexcept;
    void setAuthenticationToken(QString authenticationToken);

    /**
     * Holds the server-side date and time when the
     * authentication token will expire.
     * This time can be compared to "currentTime" to produce an expiration
     * time that can be reconciled with the client's local clock.
     */
    [[nodiscard]] Timestamp expiration() const noexcept;
    void setExpiration(Timestamp expiration);

    /**
     * Holds the information about the account which was
     * authenticated if this was a full authentication. May be absent if this
     * particular authentication did not require user information.
     */
    [[nodiscard]] const std::optional<User> & user() const noexcept;
    [[nodiscard]] std::optional<User> & mutableUser();
    void setUser(std::optional<User> user);

    /**
     * If this authentication result was achieved without full permissions to
     * access the full User structure, this field may be set to give back
     * a more limited public set of data.
     */
    [[nodiscard]] const std::optional<PublicUserInfo> & publicUserInfo() const noexcept;
    [[nodiscard]] std::optional<PublicUserInfo> & mutablePublicUserInfo();
    void setPublicUserInfo(std::optional<PublicUserInfo> publicUserInfo);

    /**
     * DEPRECATED - Client applications should use urls.noteStoreUrl.
     */
    [[nodiscard]] const std::optional<QString> & noteStoreUrl() const noexcept;
    void setNoteStoreUrl(std::optional<QString> noteStoreUrl);

    /**
     * DEPRECATED - Client applications should use urls.webApiUrlPrefix.
     */
    [[nodiscard]] const std::optional<QString> & webApiUrlPrefix() const noexcept;
    void setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);

    /**
     * If set to true, this field indicates that the user has enabled two-factor
     * authentication and must enter their second factor in order to complete
     * authentication. In this case the value of authenticationResult will be
     * a short-lived authentication token that may only be used to make a
     * subsequent call to completeTwoFactorAuthentication.
     */
    [[nodiscard]] const std::optional<bool> & secondFactorRequired() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableSecondFactorRequired();
    void setSecondFactorRequired(std::optional<bool> secondFactorRequired);

    /**
     * When secondFactorRequired is set to true, this field may contain a string
     * describing the second factor delivery method that the user has configured.
     * This will typically be an obfuscated mobile device number, such as
     * "(xxx) xxx-x095". This string can be displayed to the user to remind them
     * how to obtain the required second factor.
     */
    [[nodiscard]] const std::optional<QString> & secondFactorDeliveryHint() const noexcept;
    void setSecondFactorDeliveryHint(std::optional<QString> secondFactorDeliveryHint);

    /**
     * This structure will contain all of the URLs that clients need to make requests to the
     * Evernote service on behalf of the authenticated User.
     */
    [[nodiscard]] const std::optional<UserUrls> & urls() const noexcept;
    [[nodiscard]] std::optional<UserUrls> & mutableUrls();
    void setUrls(std::optional<UserUrls> urls);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const AuthenticationResult & other) const noexcept;
    [[nodiscard]] bool operator!=(const AuthenticationResult & other) const noexcept;

    Q_PROPERTY(Timestamp currentTime READ currentTime WRITE setCurrentTime)
    Q_PROPERTY(QString authenticationToken READ authenticationToken WRITE setAuthenticationToken)
    Q_PROPERTY(Timestamp expiration READ expiration WRITE setExpiration)
    Q_PROPERTY(std::optional<User> user READ user WRITE setUser)
    Q_PROPERTY(std::optional<PublicUserInfo> publicUserInfo READ publicUserInfo WRITE setPublicUserInfo)
    Q_PROPERTY(std::optional<QString> noteStoreUrl READ noteStoreUrl WRITE setNoteStoreUrl)
    Q_PROPERTY(std::optional<QString> webApiUrlPrefix READ webApiUrlPrefix WRITE setWebApiUrlPrefix)
    Q_PROPERTY(std::optional<bool> secondFactorRequired READ secondFactorRequired WRITE setSecondFactorRequired)
    Q_PROPERTY(std::optional<QString> secondFactorDeliveryHint READ secondFactorDeliveryHint WRITE setSecondFactorDeliveryHint)
    Q_PROPERTY(std::optional<UserUrls> urls READ urls WRITE setUrls)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::AuthenticationResult)

#endif // QEVERCLOUD_GENERATED_AUTHENTICATIONRESULT_H
