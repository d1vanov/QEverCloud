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

#include <qevercloud/types/builders/BusinessUserInfoBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessUserInfoBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_businessId;
    std::optional<QString> m_businessName;
    std::optional<BusinessUserRole> m_role;
    std::optional<QString> m_email;
    std::optional<Timestamp> m_updated;
};

BusinessUserInfoBuilder::BusinessUserInfoBuilder() :
    d(new BusinessUserInfoBuilder::Impl)
{}

BusinessUserInfoBuilder::BusinessUserInfoBuilder(BusinessUserInfoBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BusinessUserInfoBuilder::~BusinessUserInfoBuilder() noexcept = default;

BusinessUserInfoBuilder & BusinessUserInfoBuilder::operator=(BusinessUserInfoBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BusinessUserInfoBuilder & BusinessUserInfoBuilder::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = std::move(businessId);
    return *this;
}

BusinessUserInfoBuilder & BusinessUserInfoBuilder::setBusinessName(std::optional<QString> businessName)
{
    d->m_businessName = std::move(businessName);
    return *this;
}

BusinessUserInfoBuilder & BusinessUserInfoBuilder::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = std::move(role);
    return *this;
}

BusinessUserInfoBuilder & BusinessUserInfoBuilder::setEmail(std::optional<QString> email)
{
    d->m_email = std::move(email);
    return *this;
}

BusinessUserInfoBuilder & BusinessUserInfoBuilder::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

BusinessUserInfo BusinessUserInfoBuilder::build()
{
    BusinessUserInfo result;

    result.setBusinessId(std::move(d->m_businessId));
    result.setBusinessName(std::move(d->m_businessName));
    result.setRole(std::move(d->m_role));
    result.setEmail(std::move(d->m_email));
    result.setUpdated(std::move(d->m_updated));

    d->m_businessId = {};
    d->m_businessName = {};
    d->m_role = {};
    d->m_email = {};
    d->m_updated = {};

    return result;
}

} // namespace qevercloud
