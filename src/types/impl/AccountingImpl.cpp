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

#include "AccountingImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void Accounting::Impl::print(QTextStream & strm) const
{
    strm << "Accounting: {\n";

    if (m_uploadLimitEnd) {
        strm << "    uploadLimitEnd = "
            << *m_uploadLimitEnd << "\n";
    }
    else {
        strm << "    uploadLimitEnd is not set\n";
    }

    if (m_uploadLimitNextMonth) {
        strm << "    uploadLimitNextMonth = "
            << *m_uploadLimitNextMonth << "\n";
    }
    else {
        strm << "    uploadLimitNextMonth is not set\n";
    }

    if (m_premiumServiceStatus) {
        strm << "    premiumServiceStatus = "
            << *m_premiumServiceStatus << "\n";
    }
    else {
        strm << "    premiumServiceStatus is not set\n";
    }

    if (m_premiumOrderNumber) {
        strm << "    premiumOrderNumber = "
            << *m_premiumOrderNumber << "\n";
    }
    else {
        strm << "    premiumOrderNumber is not set\n";
    }

    if (m_premiumCommerceService) {
        strm << "    premiumCommerceService = "
            << *m_premiumCommerceService << "\n";
    }
    else {
        strm << "    premiumCommerceService is not set\n";
    }

    if (m_premiumServiceStart) {
        strm << "    premiumServiceStart = "
            << *m_premiumServiceStart << "\n";
    }
    else {
        strm << "    premiumServiceStart is not set\n";
    }

    if (m_premiumServiceSKU) {
        strm << "    premiumServiceSKU = "
            << *m_premiumServiceSKU << "\n";
    }
    else {
        strm << "    premiumServiceSKU is not set\n";
    }

    if (m_lastSuccessfulCharge) {
        strm << "    lastSuccessfulCharge = "
            << *m_lastSuccessfulCharge << "\n";
    }
    else {
        strm << "    lastSuccessfulCharge is not set\n";
    }

    if (m_lastFailedCharge) {
        strm << "    lastFailedCharge = "
            << *m_lastFailedCharge << "\n";
    }
    else {
        strm << "    lastFailedCharge is not set\n";
    }

    if (m_lastFailedChargeReason) {
        strm << "    lastFailedChargeReason = "
            << *m_lastFailedChargeReason << "\n";
    }
    else {
        strm << "    lastFailedChargeReason is not set\n";
    }

    if (m_nextPaymentDue) {
        strm << "    nextPaymentDue = "
            << *m_nextPaymentDue << "\n";
    }
    else {
        strm << "    nextPaymentDue is not set\n";
    }

    if (m_premiumLockUntil) {
        strm << "    premiumLockUntil = "
            << *m_premiumLockUntil << "\n";
    }
    else {
        strm << "    premiumLockUntil is not set\n";
    }

    if (m_updated) {
        strm << "    updated = "
            << *m_updated << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (m_premiumSubscriptionNumber) {
        strm << "    premiumSubscriptionNumber = "
            << *m_premiumSubscriptionNumber << "\n";
    }
    else {
        strm << "    premiumSubscriptionNumber is not set\n";
    }

    if (m_lastRequestedCharge) {
        strm << "    lastRequestedCharge = "
            << *m_lastRequestedCharge << "\n";
    }
    else {
        strm << "    lastRequestedCharge is not set\n";
    }

    if (m_currency) {
        strm << "    currency = "
            << *m_currency << "\n";
    }
    else {
        strm << "    currency is not set\n";
    }

    if (m_unitPrice) {
        strm << "    unitPrice = "
            << *m_unitPrice << "\n";
    }
    else {
        strm << "    unitPrice is not set\n";
    }

    if (m_businessId) {
        strm << "    businessId = "
            << *m_businessId << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (m_businessName) {
        strm << "    businessName = "
            << *m_businessName << "\n";
    }
    else {
        strm << "    businessName is not set\n";
    }

    if (m_businessRole) {
        strm << "    businessRole = "
            << *m_businessRole << "\n";
    }
    else {
        strm << "    businessRole is not set\n";
    }

    if (m_unitDiscount) {
        strm << "    unitDiscount = "
            << *m_unitDiscount << "\n";
    }
    else {
        strm << "    unitDiscount is not set\n";
    }

    if (m_nextChargeDate) {
        strm << "    nextChargeDate = "
            << *m_nextChargeDate << "\n";
    }
    else {
        strm << "    nextChargeDate is not set\n";
    }

    if (m_availablePoints) {
        strm << "    availablePoints = "
            << *m_availablePoints << "\n";
    }
    else {
        strm << "    availablePoints is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
