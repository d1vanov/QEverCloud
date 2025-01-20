/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/UserIdentityBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserIdentityBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<UserIdentityType> m_type;
    std::optional<QString> m_stringIdentifier;
    std::optional<qint64> m_longIdentifier;
};

UserIdentityBuilder::UserIdentityBuilder() :
    d(new UserIdentityBuilder::Impl)
{}

UserIdentityBuilder::UserIdentityBuilder(UserIdentityBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UserIdentityBuilder::~UserIdentityBuilder() noexcept = default;

UserIdentityBuilder & UserIdentityBuilder::operator=(UserIdentityBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserIdentityBuilder & UserIdentityBuilder::setType(std::optional<UserIdentityType> type)
{
    d->m_type = std::move(type);
    return *this;
}

UserIdentityBuilder & UserIdentityBuilder::setStringIdentifier(std::optional<QString> stringIdentifier)
{
    d->m_stringIdentifier = std::move(stringIdentifier);
    return *this;
}

UserIdentityBuilder & UserIdentityBuilder::setLongIdentifier(std::optional<qint64> longIdentifier)
{
    d->m_longIdentifier = std::move(longIdentifier);
    return *this;
}

UserIdentity UserIdentityBuilder::build()
{
    UserIdentity result;

    result.setType(std::move(d->m_type));
    result.setStringIdentifier(std::move(d->m_stringIdentifier));
    result.setLongIdentifier(std::move(d->m_longIdentifier));

    d->m_type = {};
    d->m_stringIdentifier = {};
    d->m_longIdentifier = {};

    return result;
}

} // namespace qevercloud
