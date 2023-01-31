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

#include <qevercloud/types/builders/UserProfileBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserProfileBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<UserID> m_id;
    std::optional<QString> m_name;
    std::optional<QString> m_email;
    std::optional<QString> m_username;
    std::optional<BusinessUserAttributes> m_attributes;
    std::optional<Timestamp> m_joined;
    std::optional<Timestamp> m_photoLastUpdated;
    std::optional<QString> m_photoUrl;
    std::optional<BusinessUserRole> m_role;
    std::optional<BusinessUserStatus> m_status;
};

UserProfileBuilder::UserProfileBuilder() :
    d(new UserProfileBuilder::Impl)
{}

UserProfileBuilder::UserProfileBuilder(UserProfileBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UserProfileBuilder::~UserProfileBuilder() noexcept = default;

UserProfileBuilder & UserProfileBuilder::operator=(UserProfileBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserProfileBuilder & UserProfileBuilder::setId(std::optional<UserID> id)
{
    d->m_id = std::move(id);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setUsername(std::optional<QString> username)
{
    d->m_username = std::move(username);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setAttributes(std::optional<BusinessUserAttributes> attributes)
{
    d->m_attributes = std::move(attributes);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setJoined(std::optional<Timestamp> joined)
{
    d->m_joined = std::move(joined);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = std::move(photoLastUpdated);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = std::move(photoUrl);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = std::move(role);
    return *this;
}

UserProfileBuilder & UserProfileBuilder::setStatus(std::optional<BusinessUserStatus> status)
{
    d->m_status = std::move(status);
    return *this;
}

UserProfile UserProfileBuilder::build()
{
    UserProfile result;

    result.setId(std::move(d->m_id));
    result.setName(std::move(d->m_name));
    result.setEmail(std::move(d->m_email));
    result.setUsername(std::move(d->m_username));
    result.setAttributes(std::move(d->m_attributes));
    result.setJoined(std::move(d->m_joined));
    result.setPhotoLastUpdated(std::move(d->m_photoLastUpdated));
    result.setPhotoUrl(std::move(d->m_photoUrl));
    result.setRole(std::move(d->m_role));
    result.setStatus(std::move(d->m_status));

    d->m_id = {};
    d->m_name = {};
    d->m_email = {};
    d->m_username = {};
    d->m_attributes = {};
    d->m_joined = {};
    d->m_photoLastUpdated = {};
    d->m_photoUrl = {};
    d->m_role = {};
    d->m_status = {};

    return result;
}

} // namespace qevercloud
