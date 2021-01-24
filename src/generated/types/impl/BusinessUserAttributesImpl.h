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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESIMPL_H
#define QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESIMPL_H

#include <qevercloud/generated/types/BusinessUserAttributes.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessUserAttributes::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const BusinessUserAttributes::Impl & other) = default;
    Impl(BusinessUserAttributes::Impl && other) noexcept = default;

    BusinessUserAttributes::Impl & operator=(const BusinessUserAttributes::Impl & other) = delete;
    BusinessUserAttributes::Impl & operator=(BusinessUserAttributes::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const BusinessUserAttributes::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessUserAttributes::Impl & other) const noexcept;

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

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTESIMPL_H
