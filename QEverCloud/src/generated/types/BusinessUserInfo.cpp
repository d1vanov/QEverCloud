/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/types/BusinessUserInfo.h>

#include "impl/BusinessUserInfoImpl.h"

namespace qevercloud {

BusinessUserInfo::BusinessUserInfo() :
    d(new BusinessUserInfo::Impl)
 {}

BusinessUserInfo::BusinessUserInfo(const BusinessUserInfo & other) :
    d(other.d)
{}

BusinessUserInfo::BusinessUserInfo(BusinessUserInfo && other) noexcept :
    d(std::move(other.d))
{}

BusinessUserInfo::~BusinessUserInfo() noexcept {}

BusinessUserInfo & BusinessUserInfo::operator=(const BusinessUserInfo & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BusinessUserInfo & BusinessUserInfo::operator=(BusinessUserInfo && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & BusinessUserInfo::businessId() const noexcept
{
    return d->m_businessId;
}

std::optional<qint32> & BusinessUserInfo::mutableBusinessId()
{
    return d->m_businessId;
}

void BusinessUserInfo::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = businessId;
}

const std::optional<QString> & BusinessUserInfo::businessName() const noexcept
{
    return d->m_businessName;
}

void BusinessUserInfo::setBusinessName(std::optional<QString> businessName)
{
    d->m_businessName = businessName;
}

const std::optional<BusinessUserRole> & BusinessUserInfo::role() const noexcept
{
    return d->m_role;
}

std::optional<BusinessUserRole> & BusinessUserInfo::mutableRole()
{
    return d->m_role;
}

void BusinessUserInfo::setRole(std::optional<BusinessUserRole> role)
{
    d->m_role = role;
}

const std::optional<QString> & BusinessUserInfo::email() const noexcept
{
    return d->m_email;
}

void BusinessUserInfo::setEmail(std::optional<QString> email)
{
    d->m_email = email;
}

const std::optional<Timestamp> & BusinessUserInfo::updated() const noexcept
{
    return d->m_updated;
}

std::optional<Timestamp> & BusinessUserInfo::mutableUpdated()
{
    return d->m_updated;
}

void BusinessUserInfo::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = updated;
}

void BusinessUserInfo::print(QTextStream & strm) const
{
    d->print(strm);
}

bool BusinessUserInfo::operator==(const BusinessUserInfo & other) const noexcept
{
    return *d == *other.d;
}

bool BusinessUserInfo::operator!=(const BusinessUserInfo & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
