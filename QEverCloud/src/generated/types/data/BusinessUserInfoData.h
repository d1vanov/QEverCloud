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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERINFODATA_H
#define QEVERCLOUD_GENERATED_BUSINESSUSERINFODATA_H

#include <generated/types/BusinessUserInfo.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessUserInfo::BusinessUserInfoData final:
    public QSharedData,
    public Printable
{
public:
    BusinessUserInfoData() = default;
    BusinessUserInfoData(const BusinessUserInfoData & other) = default;
    BusinessUserInfoData(BusinessUserInfoData && other) noexcept = default;

    BusinessUserInfoData & operator=(const BusinessUserInfoData & other) = delete;
    BusinessUserInfoData & operator=(BusinessUserInfoData && other) = delete;

    ~BusinessUserInfoData() noexcept override = default;

    [[nodiscard]] bool operator==(const BusinessUserInfoData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessUserInfoData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_businessId;
    std::optional<QString> m_businessName;
    std::optional<BusinessUserRole> m_role;
    std::optional<QString> m_email;
    std::optional<Timestamp> m_updated;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERINFODATA_H
