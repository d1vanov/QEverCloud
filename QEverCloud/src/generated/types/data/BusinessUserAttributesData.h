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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESDATA_H
#define QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESDATA_H

#include <generated/types/BusinessUserAttributes.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessUserAttributes::BusinessUserAttributesData final:
    public QSharedData,
    public Printable
{
public:
    BusinessUserAttributesData() = default;
    BusinessUserAttributesData(const BusinessUserAttributesData & other) = default;
    BusinessUserAttributesData(BusinessUserAttributesData && other) noexcept = default;

    BusinessUserAttributesData & operator=(const BusinessUserAttributesData & other) = delete;
    BusinessUserAttributesData & operator=(BusinessUserAttributesData && other) = delete;

    ~BusinessUserAttributesData() noexcept override = default;

    [[nodiscard]] bool operator==(const BusinessUserAttributesData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessUserAttributesData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_title;
    std::optional<QString> m_location;
    std::optional<QString> m_department;
    std::optional<QString> m_mobilePhone;
    std::optional<QString> m_linkedInProfileUrl;
    std::optional<QString> m_workPhone;
    std::optional<Timestamp> m_companyStartDate;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESDATA_H
