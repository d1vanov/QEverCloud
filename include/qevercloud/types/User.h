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

#ifndef QEVERCLOUD_GENERATED_USER
#define QEVERCLOUD_GENERATED_USER

#include <qevercloud/Export.h>

#include "AccountLimits.h"
#include "Accounting.h"
#include "BusinessUserInfo.h"
#include "UserAttributes.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * This represents the information about a single user account.
 **/
class QEVERCLOUD_EXPORT User: public Printable
{
    Q_GADGET
public:
    User();
    User(const User & other);
    User(User && other) noexcept;
    ~User() noexcept override;

    User & operator=(const User & other);
    User & operator=(User && other) noexcept;

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool favorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The unique numeric identifier for the account, which will not
     * change for the lifetime of the account.
     */
    [[nodiscard]] const std::optional<UserID> & id() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableId();
    void setId(std::optional<UserID> id);

    /**
     * The name that uniquely identifies a single user account. This name
     * may be presented by the user, along with their password, to log into
     * their account.
     * May only contain a-z, 0-9, or '-', and may not start or end with the '-'
     * Length: EDAM_USER_USERNAME_LEN_MIN - EDAM_USER_USERNAME_LEN_MAX
     * Regex: EDAM_USER_USERNAME_REGEX
     */
    [[nodiscard]] const std::optional<QString> & username() const noexcept;
    void setUsername(std::optional<QString> username);

    /**
     * The email address registered for the user. Must comply with
     * RFC 2821 and RFC 2822.<br/>
     * Third party applications that authenticate using OAuth do not have
     * access to this field.
     * Length: EDAM_EMAIL_LEN_MIN - EDAM_EMAIL_LEN_MAX
     * Regex: EDAM_EMAIL_REGEX
     */
    [[nodiscard]] const std::optional<QString> & email() const noexcept;
    void setEmail(std::optional<QString> email);

    /**
     * The printable name of the user, which may be a combination
     * of given and family names. This is used instead of separate "first"
     * and "last" names due to variations in international name format/order.
     * May not start or end with a whitespace character. May contain any
     * character but carriage return or newline (Unicode classes Zl and Zp).
     * Length: EDAM_USER_NAME_LEN_MIN - EDAM_USER_NAME_LEN_MAX
     * Regex: EDAM_USER_NAME_REGEX
     */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
     * The zone ID for the user's default location. If present,
     * this may be used to localize the display of any timestamp for which no
     * other timezone is available.
     * The format must be encoded as a standard zone ID such as
     * "America/Los_Angeles" or "GMT+08:00"
     * Length: EDAM_TIMEZONE_LEN_MIN - EDAM_TIMEZONE_LEN_MAX
     * Regex: EDAM_TIMEZONE_REGEX
     */
    [[nodiscard]] const std::optional<QString> & timezone() const noexcept;
    void setTimezone(std::optional<QString> timezone);

    [[nodiscard]] const std::optional<PrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<PrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<PrivilegeLevel> privilege);

    /**
     * The level of service the user currently receives. This will always be populated
     * for users retrieved from the Evernote service.
     */
    [[nodiscard]] const std::optional<ServiceLevel> & serviceLevel() const noexcept;
    [[nodiscard]] std::optional<ServiceLevel> & mutableServiceLevel();
    void setServiceLevel(std::optional<ServiceLevel> serviceLevel);

    /**
     * The date and time when this user account was created in the
     * service.
     */
    [[nodiscard]] const std::optional<Timestamp> & created() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableCreated();
    void setCreated(std::optional<Timestamp> created);

    /**
     * The date and time when this user account was last modified
     * in the service.
     */
    [[nodiscard]] const std::optional<Timestamp> & updated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUpdated();
    void setUpdated(std::optional<Timestamp> updated);

    /**
     * If the account has been deleted from the system (e.g. as
     * the result of a legal request by the user), the date and time of the
     * deletion will be represented here. If not, this value will not be set.
     */
    [[nodiscard]] const std::optional<Timestamp> & deleted() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableDeleted();
    void setDeleted(std::optional<Timestamp> deleted);

    /**
     * If the user account is available for login and
     * synchronization, this flag will be set to true.
     */
    [[nodiscard]] const std::optional<bool> & active() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableActive();
    void setActive(std::optional<bool> active);

    /**
     * DEPRECATED - Client applications should have no need to use this field.
     */
    [[nodiscard]] const std::optional<QString> & shardId() const noexcept;
    void setShardId(std::optional<QString> shardId);

    /**
     * If present, this will contain a list of the attributes
     * for this user account.
     */
    [[nodiscard]] const std::optional<UserAttributes> & attributes() const noexcept;
    [[nodiscard]] std::optional<UserAttributes> & mutableAttributes();
    void setAttributes(std::optional<UserAttributes> attributes);

    /**
     * Bookkeeping information for the user's subscription.
     */
    [[nodiscard]] const std::optional<Accounting> & accounting() const noexcept;
    [[nodiscard]] std::optional<Accounting> & mutableAccounting();
    void setAccounting(std::optional<Accounting> accounting);

    /**
     * If present, this will contain a set of business information
     * relating to the user's business membership. If not present, the
     * user is not currently part of a business.
     */
    [[nodiscard]] const std::optional<BusinessUserInfo> & businessUserInfo() const noexcept;
    [[nodiscard]] std::optional<BusinessUserInfo> & mutableBusinessUserInfo();
    void setBusinessUserInfo(std::optional<BusinessUserInfo> businessUserInfo);

    /**
     * The URL of the photo that represents this User. This field is filled in by the
     * service and is read-only to clients. If <code>photoLastUpdated</code> is
     * not set, this url will point to a placeholder user photo generated by the
     * service.
     */
    [[nodiscard]] const std::optional<QString> & photoUrl() const noexcept;
    void setPhotoUrl(std::optional<QString> photoUrl);

    /**
     * The time at which the photo at 'photoUrl' was last updated by this User. This
     * field will be null if the User never set a profile photo. This field is filled in by
     * the service and is read-only to clients.
     */
    [[nodiscard]] const std::optional<Timestamp> & photoLastUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePhotoLastUpdated();
    void setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);

    /**
     * Account limits applicable for this user.
     */
    [[nodiscard]] const std::optional<AccountLimits> & accountLimits() const noexcept;
    [[nodiscard]] std::optional<AccountLimits> & mutableAccountLimits();
    void setAccountLimits(std::optional<AccountLimits> accountLimits);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const User & user);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const User & user);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const User & user);

    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<UserID> id READ id WRITE setId)
    Q_PROPERTY(std::optional<QString> username READ username WRITE setUsername)
    Q_PROPERTY(std::optional<QString> email READ email WRITE setEmail)
    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<QString> timezone READ timezone WRITE setTimezone)
    Q_PROPERTY(std::optional<PrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<ServiceLevel> serviceLevel READ serviceLevel WRITE setServiceLevel)
    Q_PROPERTY(std::optional<Timestamp> created READ created WRITE setCreated)
    Q_PROPERTY(std::optional<Timestamp> updated READ updated WRITE setUpdated)
    Q_PROPERTY(std::optional<Timestamp> deleted READ deleted WRITE setDeleted)
    Q_PROPERTY(std::optional<bool> active READ active WRITE setActive)
    Q_PROPERTY(std::optional<QString> shardId READ shardId WRITE setShardId)
    Q_PROPERTY(std::optional<UserAttributes> attributes READ attributes WRITE setAttributes)
    Q_PROPERTY(std::optional<Accounting> accounting READ accounting WRITE setAccounting)
    Q_PROPERTY(std::optional<BusinessUserInfo> businessUserInfo READ businessUserInfo WRITE setBusinessUserInfo)
    Q_PROPERTY(std::optional<QString> photoUrl READ photoUrl WRITE setPhotoUrl)
    Q_PROPERTY(std::optional<Timestamp> photoLastUpdated READ photoLastUpdated WRITE setPhotoLastUpdated)
    Q_PROPERTY(std::optional<AccountLimits> accountLimits READ accountLimits WRITE setAccountLimits)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const User & lhs, const User & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const User & lhs, const User & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::User)

#endif // QEVERCLOUD_GENERATED_USER
