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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESBUILDER
#define QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessUserAttributes.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT BusinessUserAttributesBuilder
{
public:
    BusinessUserAttributesBuilder();

    BusinessUserAttributesBuilder(BusinessUserAttributesBuilder && other) noexcept;

    ~BusinessUserAttributesBuilder() noexcept;

    BusinessUserAttributesBuilder & operator=(BusinessUserAttributesBuilder && other) noexcept;

    BusinessUserAttributesBuilder & setTitle(std::optional<QString> title);
    BusinessUserAttributesBuilder & setLocation(std::optional<QString> location);
    BusinessUserAttributesBuilder & setDepartment(std::optional<QString> department);
    BusinessUserAttributesBuilder & setMobilePhone(std::optional<QString> mobilePhone);
    BusinessUserAttributesBuilder & setLinkedInProfileUrl(std::optional<QString> linkedInProfileUrl);
    BusinessUserAttributesBuilder & setWorkPhone(std::optional<QString> workPhone);
    BusinessUserAttributesBuilder & setCompanyStartDate(std::optional<Timestamp> companyStartDate);

    [[nodiscard]] BusinessUserAttributes build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESBUILDER
