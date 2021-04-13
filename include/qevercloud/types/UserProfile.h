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

#ifndef QEVERCLOUD_GENERATED_USERPROFILE
#define QEVERCLOUD_GENERATED_USERPROFILE

#include <qevercloud/Export.h>

#include "BusinessUserAttributes.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure represents profile information for a user in a business.
 *
 * */
class QEVERCLOUD_EXPORT UserProfile: public Printable
{
    Q_GADGET
public:
    UserProfile();
    UserProfile(const UserProfile & other);
    UserProfile(UserProfile && other) noexcept;
    ~UserProfile() noexcept override;

    UserProfile & operator=(const UserProfile & other);
    UserProfile & operator=(UserProfile && other) noexcept;

    /**
     * The numeric identifier that uniquely identifies a user.
     */
    [[nodiscard]] const std::optional<UserID> & id() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableId();
    void setId(std::optional<UserID> id);

    /**
     * The full name of the user.
     */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
     * The user's business email address. If the user has not registered their business
     * email address, this field will be empty.
     */
    [[nodiscard]] const std::optional<QString> & email() const noexcept;
    void setEmail(std::optional<QString> email);

    /**
     * The user's Evernote username.
     */
    [[nodiscard]] const std::optional<QString> & username() const noexcept;
    void setUsername(std::optional<QString> username);

    /**
     * The user's business specific attributes.
     */
    [[nodiscard]] const std::optional<BusinessUserAttributes> & attributes() const noexcept;
    [[nodiscard]] std::optional<BusinessUserAttributes> & mutableAttributes();
    void setAttributes(std::optional<BusinessUserAttributes> attributes);

    /**
     * The time when the user joined the business
     */
    [[nodiscard]] const std::optional<Timestamp> & joined() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableJoined();
    void setJoined(std::optional<Timestamp> joined);

    /**
     * The time when the user's profile photo was most recently updated
     */
    [[nodiscard]] const std::optional<Timestamp> & photoLastUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePhotoLastUpdated();
    void setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);

    /**
     * A URL identifying a copy of the user's current profile photo
     */
    [[nodiscard]] const std::optional<QString> & photoUrl() const noexcept;
    void setPhotoUrl(std::optional<QString> photoUrl);

    /**
     * The BusinessUserRole for the user
     */
    [[nodiscard]] const std::optional<BusinessUserRole> & role() const noexcept;
    [[nodiscard]] std::optional<BusinessUserRole> & mutableRole();
    void setRole(std::optional<BusinessUserRole> role);

    /**
     * The BusinessUserStatus for the user
     */
    [[nodiscard]] const std::optional<BusinessUserStatus> & status() const noexcept;
    [[nodiscard]] std::optional<BusinessUserStatus> & mutableStatus();
    void setStatus(std::optional<BusinessUserStatus> status);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<UserID> id READ id WRITE setId)
    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<QString> email READ email WRITE setEmail)
    Q_PROPERTY(std::optional<QString> username READ username WRITE setUsername)
    Q_PROPERTY(std::optional<BusinessUserAttributes> attributes READ attributes WRITE setAttributes)
    Q_PROPERTY(std::optional<Timestamp> joined READ joined WRITE setJoined)
    Q_PROPERTY(std::optional<Timestamp> photoLastUpdated READ photoLastUpdated WRITE setPhotoLastUpdated)
    Q_PROPERTY(std::optional<QString> photoUrl READ photoUrl WRITE setPhotoUrl)
    Q_PROPERTY(std::optional<BusinessUserRole> role READ role WRITE setRole)
    Q_PROPERTY(std::optional<BusinessUserStatus> status READ status WRITE setStatus)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const UserProfile & lhs, const UserProfile & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const UserProfile & lhs, const UserProfile & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::UserProfile)

#endif // QEVERCLOUD_GENERATED_USERPROFILE
