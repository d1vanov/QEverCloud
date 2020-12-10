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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTINGDATA_H
#define QEVERCLOUD_GENERATED_ACCOUNTINGDATA_H

#include <generated/types/Accounting.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Accounting::AccountingData final:
    public QSharedData,
    public Printable
{
public:
    AccountingData() = default;
    AccountingData(const AccountingData & other) = default;
    AccountingData(AccountingData && other) noexcept = default;

    AccountingData & operator=(const AccountingData & other) = delete;
    AccountingData & operator=(AccountingData && other) = delete;

    ~AccountingData() noexcept override = default;

    [[nodiscard]] bool operator==(const AccountingData & other) const noexcept;
    [[nodiscard]] bool operator!=(const AccountingData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<Timestamp> m_uploadLimitEnd;
    std::optional<qint64> m_uploadLimitNextMonth;
    std::optional<PremiumOrderStatus> m_premiumServiceStatus;
    std::optional<QString> m_premiumOrderNumber;
    std::optional<QString> m_premiumCommerceService;
    std::optional<Timestamp> m_premiumServiceStart;
    std::optional<QString> m_premiumServiceSKU;
    std::optional<Timestamp> m_lastSuccessfulCharge;
    std::optional<Timestamp> m_lastFailedCharge;
    std::optional<QString> m_lastFailedChargeReason;
    std::optional<Timestamp> m_nextPaymentDue;
    std::optional<Timestamp> m_premiumLockUntil;
    std::optional<Timestamp> m_updated;
    std::optional<QString> m_premiumSubscriptionNumber;
    std::optional<Timestamp> m_lastRequestedCharge;
    std::optional<QString> m_currency;
    std::optional<qint32> m_unitPrice;
    std::optional<qint32> m_businessId;
    std::optional<QString> m_businessName;
    std::optional<BusinessUserRole> m_businessRole;
    std::optional<qint32> m_unitDiscount;
    std::optional<Timestamp> m_nextChargeDate;
    std::optional<qint32> m_availablePoints;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_ACCOUNTINGDATA_H
