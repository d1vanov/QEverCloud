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

#include <qevercloud/generated/types/BusinessUserAttributes.h>

#include "impl/BusinessUserAttributesImpl.h"

namespace qevercloud {

BusinessUserAttributes::BusinessUserAttributes() :
    d(new BusinessUserAttributes::Impl)
 {}

BusinessUserAttributes::BusinessUserAttributes(const BusinessUserAttributes & other) :
    d(other.d)
{}

BusinessUserAttributes::BusinessUserAttributes(BusinessUserAttributes && other) noexcept :
    d(std::move(other.d))
{}

BusinessUserAttributes::~BusinessUserAttributes() noexcept {}

BusinessUserAttributes & BusinessUserAttributes::operator=(const BusinessUserAttributes & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BusinessUserAttributes & BusinessUserAttributes::operator=(BusinessUserAttributes && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & BusinessUserAttributes::title() const noexcept
{
    return d->m_title;
}

void BusinessUserAttributes::setTitle(std::optional<QString> title)
{
    d->m_title = title;
}

const std::optional<QString> & BusinessUserAttributes::location() const noexcept
{
    return d->m_location;
}

void BusinessUserAttributes::setLocation(std::optional<QString> location)
{
    d->m_location = location;
}

const std::optional<QString> & BusinessUserAttributes::department() const noexcept
{
    return d->m_department;
}

void BusinessUserAttributes::setDepartment(std::optional<QString> department)
{
    d->m_department = department;
}

const std::optional<QString> & BusinessUserAttributes::mobilePhone() const noexcept
{
    return d->m_mobilePhone;
}

void BusinessUserAttributes::setMobilePhone(std::optional<QString> mobilePhone)
{
    d->m_mobilePhone = mobilePhone;
}

const std::optional<QString> & BusinessUserAttributes::linkedInProfileUrl() const noexcept
{
    return d->m_linkedInProfileUrl;
}

void BusinessUserAttributes::setLinkedInProfileUrl(std::optional<QString> linkedInProfileUrl)
{
    d->m_linkedInProfileUrl = linkedInProfileUrl;
}

const std::optional<QString> & BusinessUserAttributes::workPhone() const noexcept
{
    return d->m_workPhone;
}

void BusinessUserAttributes::setWorkPhone(std::optional<QString> workPhone)
{
    d->m_workPhone = workPhone;
}

const std::optional<Timestamp> & BusinessUserAttributes::companyStartDate() const noexcept
{
    return d->m_companyStartDate;
}

std::optional<Timestamp> & BusinessUserAttributes::mutableCompanyStartDate()
{
    return d->m_companyStartDate;
}

void BusinessUserAttributes::setCompanyStartDate(std::optional<Timestamp> companyStartDate)
{
    d->m_companyStartDate = companyStartDate;
}

void BusinessUserAttributes::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const BusinessUserAttributes & lhs, const BusinessUserAttributes & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.title() == rhs.title() &&
        lhs.location() == rhs.location() &&
        lhs.department() == rhs.department() &&
        lhs.mobilePhone() == rhs.mobilePhone() &&
        lhs.linkedInProfileUrl() == rhs.linkedInProfileUrl() &&
        lhs.workPhone() == rhs.workPhone() &&
        lhs.companyStartDate() == rhs.companyStartDate();
}

bool operator!=(const BusinessUserAttributes & lhs, const BusinessUserAttributes & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
