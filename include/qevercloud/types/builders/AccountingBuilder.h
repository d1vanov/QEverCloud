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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTINGBUILDER
#define QEVERCLOUD_GENERATED_ACCOUNTINGBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Accounting.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT AccountingBuilder
{
public:
    AccountingBuilder();

    AccountingBuilder(AccountingBuilder && other) noexcept;

    ~AccountingBuilder() noexcept;

    AccountingBuilder & operator=(AccountingBuilder && other) noexcept;

    AccountingBuilder & setUploadLimitEnd(std::optional<Timestamp> uploadLimitEnd);
    AccountingBuilder & setUploadLimitNextMonth(std::optional<qint64> uploadLimitNextMonth);
    AccountingBuilder & setPremiumServiceStatus(std::optional<PremiumOrderStatus> premiumServiceStatus);
    AccountingBuilder & setPremiumOrderNumber(std::optional<QString> premiumOrderNumber);
    AccountingBuilder & setPremiumCommerceService(std::optional<QString> premiumCommerceService);
    AccountingBuilder & setPremiumServiceStart(std::optional<Timestamp> premiumServiceStart);
    AccountingBuilder & setPremiumServiceSKU(std::optional<QString> premiumServiceSKU);
    AccountingBuilder & setLastSuccessfulCharge(std::optional<Timestamp> lastSuccessfulCharge);
    AccountingBuilder & setLastFailedCharge(std::optional<Timestamp> lastFailedCharge);
    AccountingBuilder & setLastFailedChargeReason(std::optional<QString> lastFailedChargeReason);
    AccountingBuilder & setNextPaymentDue(std::optional<Timestamp> nextPaymentDue);
    AccountingBuilder & setPremiumLockUntil(std::optional<Timestamp> premiumLockUntil);
    AccountingBuilder & setUpdated(std::optional<Timestamp> updated);
    AccountingBuilder & setPremiumSubscriptionNumber(std::optional<QString> premiumSubscriptionNumber);
    AccountingBuilder & setLastRequestedCharge(std::optional<Timestamp> lastRequestedCharge);
    AccountingBuilder & setCurrency(std::optional<QString> currency);
    AccountingBuilder & setUnitPrice(std::optional<qint32> unitPrice);
    AccountingBuilder & setBusinessId(std::optional<qint32> businessId);
    AccountingBuilder & setBusinessName(std::optional<QString> businessName);
    AccountingBuilder & setBusinessRole(std::optional<BusinessUserRole> businessRole);
    AccountingBuilder & setUnitDiscount(std::optional<qint32> unitDiscount);
    AccountingBuilder & setNextChargeDate(std::optional<Timestamp> nextChargeDate);
    AccountingBuilder & setAvailablePoints(std::optional<qint32> availablePoints);

    [[nodiscard]] Accounting build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_ACCOUNTINGBUILDER
