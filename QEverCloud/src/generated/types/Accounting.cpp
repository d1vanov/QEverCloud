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

#include <generated/types/Accounting.h>

#include "impl/AccountingImpl.h"

namespace qevercloud {

Accounting::Accounting() : d(new Accounting::Impl) {}

Accounting::Accounting(const Accounting & other) : d(other.d) {}

Accounting::Accounting(Accounting && other) noexcept : d(std::move(other.d))
{}

Accounting::~Accounting() noexcept {}

Accounting & Accounting::operator=(const Accounting & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Accounting & Accounting::operator=(Accounting && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<Timestamp> & Accounting::uploadLimitEnd() const noexcept
{
    return d->m_uploadLimitEnd;
}

std::optional<Timestamp> & Accounting::mutableUploadLimitEnd()
{
    return d->m_uploadLimitEnd;
}

void Accounting::setUploadLimitEnd(std::optional<Timestamp> uploadLimitEnd)
{
    d->m_uploadLimitEnd = uploadLimitEnd;
}

const std::optional<qint64> & Accounting::uploadLimitNextMonth() const noexcept
{
    return d->m_uploadLimitNextMonth;
}

std::optional<qint64> & Accounting::mutableUploadLimitNextMonth()
{
    return d->m_uploadLimitNextMonth;
}

void Accounting::setUploadLimitNextMonth(std::optional<qint64> uploadLimitNextMonth)
{
    d->m_uploadLimitNextMonth = uploadLimitNextMonth;
}

const std::optional<PremiumOrderStatus> & Accounting::premiumServiceStatus() const noexcept
{
    return d->m_premiumServiceStatus;
}

std::optional<PremiumOrderStatus> & Accounting::mutablePremiumServiceStatus()
{
    return d->m_premiumServiceStatus;
}

void Accounting::setPremiumServiceStatus(std::optional<PremiumOrderStatus> premiumServiceStatus)
{
    d->m_premiumServiceStatus = premiumServiceStatus;
}

const std::optional<QString> & Accounting::premiumOrderNumber() const noexcept
{
    return d->m_premiumOrderNumber;
}

void Accounting::setPremiumOrderNumber(std::optional<QString> premiumOrderNumber)
{
    d->m_premiumOrderNumber = premiumOrderNumber;
}

const std::optional<QString> & Accounting::premiumCommerceService() const noexcept
{
    return d->m_premiumCommerceService;
}

void Accounting::setPremiumCommerceService(std::optional<QString> premiumCommerceService)
{
    d->m_premiumCommerceService = premiumCommerceService;
}

const std::optional<Timestamp> & Accounting::premiumServiceStart() const noexcept
{
    return d->m_premiumServiceStart;
}

std::optional<Timestamp> & Accounting::mutablePremiumServiceStart()
{
    return d->m_premiumServiceStart;
}

void Accounting::setPremiumServiceStart(std::optional<Timestamp> premiumServiceStart)
{
    d->m_premiumServiceStart = premiumServiceStart;
}

const std::optional<QString> & Accounting::premiumServiceSKU() const noexcept
{
    return d->m_premiumServiceSKU;
}

void Accounting::setPremiumServiceSKU(std::optional<QString> premiumServiceSKU)
{
    d->m_premiumServiceSKU = premiumServiceSKU;
}

const std::optional<Timestamp> & Accounting::lastSuccessfulCharge() const noexcept
{
    return d->m_lastSuccessfulCharge;
}

std::optional<Timestamp> & Accounting::mutableLastSuccessfulCharge()
{
    return d->m_lastSuccessfulCharge;
}

void Accounting::setLastSuccessfulCharge(std::optional<Timestamp> lastSuccessfulCharge)
{
    d->m_lastSuccessfulCharge = lastSuccessfulCharge;
}

const std::optional<Timestamp> & Accounting::lastFailedCharge() const noexcept
{
    return d->m_lastFailedCharge;
}

std::optional<Timestamp> & Accounting::mutableLastFailedCharge()
{
    return d->m_lastFailedCharge;
}

void Accounting::setLastFailedCharge(std::optional<Timestamp> lastFailedCharge)
{
    d->m_lastFailedCharge = lastFailedCharge;
}

const std::optional<QString> & Accounting::lastFailedChargeReason() const noexcept
{
    return d->m_lastFailedChargeReason;
}

void Accounting::setLastFailedChargeReason(std::optional<QString> lastFailedChargeReason)
{
    d->m_lastFailedChargeReason = lastFailedChargeReason;
}

const std::optional<Timestamp> & Accounting::nextPaymentDue() const noexcept
{
    return d->m_nextPaymentDue;
}

std::optional<Timestamp> & Accounting::mutableNextPaymentDue()
{
    return d->m_nextPaymentDue;
}

void Accounting::setNextPaymentDue(std::optional<Timestamp> nextPaymentDue)
{
    d->m_nextPaymentDue = nextPaymentDue;
}

const std::optional<Timestamp> & Accounting::premiumLockUntil() const noexcept
{
    return d->m_premiumLockUntil;
}

std::optional<Timestamp> & Accounting::mutablePremiumLockUntil()
{
    return d->m_premiumLockUntil;
}

void Accounting::setPremiumLockUntil(std::optional<Timestamp> premiumLockUntil)
{
    d->m_premiumLockUntil = premiumLockUntil;
}

const std::optional<Timestamp> & Accounting::updated() const noexcept
{
    return d->m_updated;
}

std::optional<Timestamp> & Accounting::mutableUpdated()
{
    return d->m_updated;
}

void Accounting::setUpdated(std::optional<Timestamp> updated)
{
    d->m_updated = updated;
}

const std::optional<QString> & Accounting::premiumSubscriptionNumber() const noexcept
{
    return d->m_premiumSubscriptionNumber;
}

void Accounting::setPremiumSubscriptionNumber(std::optional<QString> premiumSubscriptionNumber)
{
    d->m_premiumSubscriptionNumber = premiumSubscriptionNumber;
}

const std::optional<Timestamp> & Accounting::lastRequestedCharge() const noexcept
{
    return d->m_lastRequestedCharge;
}

std::optional<Timestamp> & Accounting::mutableLastRequestedCharge()
{
    return d->m_lastRequestedCharge;
}

void Accounting::setLastRequestedCharge(std::optional<Timestamp> lastRequestedCharge)
{
    d->m_lastRequestedCharge = lastRequestedCharge;
}

const std::optional<QString> & Accounting::currency() const noexcept
{
    return d->m_currency;
}

void Accounting::setCurrency(std::optional<QString> currency)
{
    d->m_currency = currency;
}

const std::optional<qint32> & Accounting::unitPrice() const noexcept
{
    return d->m_unitPrice;
}

std::optional<qint32> & Accounting::mutableUnitPrice()
{
    return d->m_unitPrice;
}

void Accounting::setUnitPrice(std::optional<qint32> unitPrice)
{
    d->m_unitPrice = unitPrice;
}

const std::optional<qint32> & Accounting::businessId() const noexcept
{
    return d->m_businessId;
}

std::optional<qint32> & Accounting::mutableBusinessId()
{
    return d->m_businessId;
}

void Accounting::setBusinessId(std::optional<qint32> businessId)
{
    d->m_businessId = businessId;
}

const std::optional<QString> & Accounting::businessName() const noexcept
{
    return d->m_businessName;
}

void Accounting::setBusinessName(std::optional<QString> businessName)
{
    d->m_businessName = businessName;
}

const std::optional<BusinessUserRole> & Accounting::businessRole() const noexcept
{
    return d->m_businessRole;
}

std::optional<BusinessUserRole> & Accounting::mutableBusinessRole()
{
    return d->m_businessRole;
}

void Accounting::setBusinessRole(std::optional<BusinessUserRole> businessRole)
{
    d->m_businessRole = businessRole;
}

const std::optional<qint32> & Accounting::unitDiscount() const noexcept
{
    return d->m_unitDiscount;
}

std::optional<qint32> & Accounting::mutableUnitDiscount()
{
    return d->m_unitDiscount;
}

void Accounting::setUnitDiscount(std::optional<qint32> unitDiscount)
{
    d->m_unitDiscount = unitDiscount;
}

const std::optional<Timestamp> & Accounting::nextChargeDate() const noexcept
{
    return d->m_nextChargeDate;
}

std::optional<Timestamp> & Accounting::mutableNextChargeDate()
{
    return d->m_nextChargeDate;
}

void Accounting::setNextChargeDate(std::optional<Timestamp> nextChargeDate)
{
    d->m_nextChargeDate = nextChargeDate;
}

const std::optional<qint32> & Accounting::availablePoints() const noexcept
{
    return d->m_availablePoints;
}

std::optional<qint32> & Accounting::mutableAvailablePoints()
{
    return d->m_availablePoints;
}

void Accounting::setAvailablePoints(std::optional<qint32> availablePoints)
{
    d->m_availablePoints = availablePoints;
}

void Accounting::print(QTextStream & strm) const
{
    d->print(strm);
}

bool Accounting::operator==(const Accounting & other) const noexcept
{
    return *d == *other.d;
}

bool Accounting::operator!=(const Accounting & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
