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

#include <qevercloud/types/builders/BusinessUserAttributesBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessUserAttributesBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_title;
    std::optional<QString> m_location;
    std::optional<QString> m_department;
    std::optional<QString> m_mobilePhone;
    std::optional<QString> m_linkedInProfileUrl;
    std::optional<QString> m_workPhone;
    std::optional<Timestamp> m_companyStartDate;
};

BusinessUserAttributesBuilder::BusinessUserAttributesBuilder() :
    d(new BusinessUserAttributesBuilder::Impl)
{}

BusinessUserAttributesBuilder::BusinessUserAttributesBuilder(BusinessUserAttributesBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BusinessUserAttributesBuilder::~BusinessUserAttributesBuilder() noexcept = default;

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::operator=(BusinessUserAttributesBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setTitle(std::optional<QString> title)
{
    d->m_title = std::move(title);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setLocation(std::optional<QString> location)
{
    d->m_location = std::move(location);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setDepartment(std::optional<QString> department)
{
    d->m_department = std::move(department);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setMobilePhone(std::optional<QString> mobilePhone)
{
    d->m_mobilePhone = std::move(mobilePhone);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setLinkedInProfileUrl(std::optional<QString> linkedInProfileUrl)
{
    d->m_linkedInProfileUrl = std::move(linkedInProfileUrl);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setWorkPhone(std::optional<QString> workPhone)
{
    d->m_workPhone = std::move(workPhone);
    return *this;
}

BusinessUserAttributesBuilder & BusinessUserAttributesBuilder::setCompanyStartDate(std::optional<Timestamp> companyStartDate)
{
    d->m_companyStartDate = std::move(companyStartDate);
    return *this;
}

BusinessUserAttributes BusinessUserAttributesBuilder::build()
{
    BusinessUserAttributes result;

    result.setTitle(std::move(d->m_title));
    result.setLocation(std::move(d->m_location));
    result.setDepartment(std::move(d->m_department));
    result.setMobilePhone(std::move(d->m_mobilePhone));
    result.setLinkedInProfileUrl(std::move(d->m_linkedInProfileUrl));
    result.setWorkPhone(std::move(d->m_workPhone));
    result.setCompanyStartDate(std::move(d->m_companyStartDate));

    d->m_title = {};
    d->m_location = {};
    d->m_department = {};
    d->m_mobilePhone = {};
    d->m_linkedInProfileUrl = {};
    d->m_workPhone = {};
    d->m_companyStartDate = {};

    return result;
}

} // namespace qevercloud
