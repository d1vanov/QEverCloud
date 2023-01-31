/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/AccountingBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AccountingBuilder::Impl final:
    public QSharedData
{
public:
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

AccountingBuilder::AccountingBuilder() :
    d(new AccountingBuilder::Impl)
{}

AccountingBuilder::AccountingBuilder(AccountingBuilder && other) noexcept :
    d{std::move(other.d)}
{}

AccountingBuilder::~AccountingBuilder() noexcept = default;

AccountingBuilder & AccountingBuilder::operator=(AccountingBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

AccountingBuilder & AccountingBuilder::setUploadLimitEnd(std::optional<Timestamp> uploadLimitEnd)
{
    d->m_uploadLimitEnd = std::move(uploadLimitEnd);
    return *this;
}

AccountingBuilder & AccountingBuilder::setUploadLimitNextMonth(std::optional<qint64> uploadLimitNextMonth)
{
    d->m_uploadLimitNextMonth = std::move(uploadLimitNextMonth);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumServiceStatus(std::optional<PremiumOrderStatus> premiumServiceStatus)
{
    d->m_premiumServiceStatus = std::move(premiumServiceStatus);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumOrderNumber(std::optional<QString> premiumOrderNumber)
{
    d->m_premiumOrderNumber = std::move(premiumOrderNumber);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumCommerceService(std::optional<QString> premiumCommerceService)
{
    d->m_premiumCommerceService = std::move(premiumCommerceService);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumServiceStart(std::optional<Timestamp> premiumServiceStart)
{
    d->m_premiumServiceStart = std::move(premiumServiceStart);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumServiceSKU(std::optional<QString> premiumServiceSKU)
{
    d->m_premiumServiceSKU = std::move(premiumServiceSKU);
    return *this;
}

AccountingBuilder & AccountingBuilder::setLastSuccessfulCharge(std::optional<Timestamp> lastSuccessfulCharge)
{
    d->m_lastSuccessfulCharge = std::move(lastSuccessfulCharge);
    return *this;
}

AccountingBuilder & AccountingBuilder::setLastFailedCharge(std::optional<Timestamp> lastFailedCharge)
{
    d->m_lastFailedCharge = std::move(lastFailedCharge);
    return *this;
}

AccountingBuilder & AccountingBuilder::setLastFailedChargeReason(std::optional<QString> lastFailedChargeReason)
{
    d->m_lastFailedChargeReason = std::move(lastFailedChargeReason);
    return *this;
}

AccountingBuilder & AccountingBuilder::setNextPaymentDue(std::optional<Timestamp> nextPaymentDue)
{
    d->m_nextPaymentDue = std::move(nextPaymentDue);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumLockUntil(std::optional<Timestamp> premiumLockUntil)
{
    d->m_premiumLockUntil = std::move(premiumLockUntil);
    return *this;
}

AccountingBuilder & AccountingBuilder::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

AccountingBuilder & AccountingBuilder::setPremiumSubscriptionNumber(std::optional<QString> premiumSubscriptionNumber)
{
    d->m_premiumSubscriptionNumber = std::move(premiumSubscriptionNumber);
    return *this;
}

AccountingBuilder & AccountingBuilder::setLastRequestedCharge(std::optional<Timestamp> lastRequestedCharge)
{
    d->m_lastRequestedCharge = std::move(lastRequestedCharge);
    return *this;
}

AccountingBuilder & AccountingBuilder::setCurrency(std::optional<QString> currency)
{
    d->m_currency = std::move(currency);
    return *this;
}

AccountingBuilder & AccountingBuilder::setUnitPrice(std::optional<qint32> unitPrice)
{
    d->m_unitPrice = std::move(unitPrice);
    return *this;
}

AccountingBuilder & AccountingBuilder::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = std::move(businessId);
    return *this;
}

AccountingBuilder & AccountingBuilder::setBusinessName(std::optional<QString> businessName)
{
    d->m_businessName = std::move(businessName);
    return *this;
}

AccountingBuilder & AccountingBuilder::setBusinessRole(std::optional<BusinessUserRole> businessRole)
{
    d->m_businessRole = std::move(businessRole);
    return *this;
}

AccountingBuilder & AccountingBuilder::setUnitDiscount(std::optional<qint32> unitDiscount)
{
    d->m_unitDiscount = std::move(unitDiscount);
    return *this;
}

AccountingBuilder & AccountingBuilder::setNextChargeDate(std::optional<Timestamp> nextChargeDate)
{
    d->m_nextChargeDate = std::move(nextChargeDate);
    return *this;
}

AccountingBuilder & AccountingBuilder::setAvailablePoints(std::optional<qint32> availablePoints)
{
    d->m_availablePoints = std::move(availablePoints);
    return *this;
}

Accounting AccountingBuilder::build()
{
    Accounting result;

    result.setUploadLimitEnd(std::move(d->m_uploadLimitEnd));
    result.setUploadLimitNextMonth(std::move(d->m_uploadLimitNextMonth));
    result.setPremiumServiceStatus(std::move(d->m_premiumServiceStatus));
    result.setPremiumOrderNumber(std::move(d->m_premiumOrderNumber));
    result.setPremiumCommerceService(std::move(d->m_premiumCommerceService));
    result.setPremiumServiceStart(std::move(d->m_premiumServiceStart));
    result.setPremiumServiceSKU(std::move(d->m_premiumServiceSKU));
    result.setLastSuccessfulCharge(std::move(d->m_lastSuccessfulCharge));
    result.setLastFailedCharge(std::move(d->m_lastFailedCharge));
    result.setLastFailedChargeReason(std::move(d->m_lastFailedChargeReason));
    result.setNextPaymentDue(std::move(d->m_nextPaymentDue));
    result.setPremiumLockUntil(std::move(d->m_premiumLockUntil));
    result.setUpdated(std::move(d->m_updated));
    result.setPremiumSubscriptionNumber(std::move(d->m_premiumSubscriptionNumber));
    result.setLastRequestedCharge(std::move(d->m_lastRequestedCharge));
    result.setCurrency(std::move(d->m_currency));
    result.setUnitPrice(std::move(d->m_unitPrice));
    result.setBusinessId(std::move(d->m_businessId));
    result.setBusinessName(std::move(d->m_businessName));
    result.setBusinessRole(std::move(d->m_businessRole));
    result.setUnitDiscount(std::move(d->m_unitDiscount));
    result.setNextChargeDate(std::move(d->m_nextChargeDate));
    result.setAvailablePoints(std::move(d->m_availablePoints));

    d->m_uploadLimitEnd = {};
    d->m_uploadLimitNextMonth = {};
    d->m_premiumServiceStatus = {};
    d->m_premiumOrderNumber = {};
    d->m_premiumCommerceService = {};
    d->m_premiumServiceStart = {};
    d->m_premiumServiceSKU = {};
    d->m_lastSuccessfulCharge = {};
    d->m_lastFailedCharge = {};
    d->m_lastFailedChargeReason = {};
    d->m_nextPaymentDue = {};
    d->m_premiumLockUntil = {};
    d->m_updated = {};
    d->m_premiumSubscriptionNumber = {};
    d->m_lastRequestedCharge = {};
    d->m_currency = {};
    d->m_unitPrice = {};
    d->m_businessId = {};
    d->m_businessName = {};
    d->m_businessRole = {};
    d->m_unitDiscount = {};
    d->m_nextChargeDate = {};
    d->m_availablePoints = {};

    return result;
}

} // namespace qevercloud
