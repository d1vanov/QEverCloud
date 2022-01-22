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

#include <qevercloud/serialization/json/Accounting.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<PremiumOrderStatus> safeCastPremiumOrderStatusToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(PremiumOrderStatus::NONE):
        return PremiumOrderStatus::NONE;
    case static_cast<qint64>(PremiumOrderStatus::PENDING):
        return PremiumOrderStatus::PENDING;
    case static_cast<qint64>(PremiumOrderStatus::ACTIVE):
        return PremiumOrderStatus::ACTIVE;
    case static_cast<qint64>(PremiumOrderStatus::FAILED):
        return PremiumOrderStatus::FAILED;
    case static_cast<qint64>(PremiumOrderStatus::CANCELLATION_PENDING):
        return PremiumOrderStatus::CANCELLATION_PENDING;
    case static_cast<qint64>(PremiumOrderStatus::CANCELED):
        return PremiumOrderStatus::CANCELED;
    default:
        return std::nullopt;
    }
}

[[nodiscard]] std::optional<BusinessUserRole> safeCastBusinessUserRoleToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(BusinessUserRole::ADMIN):
        return BusinessUserRole::ADMIN;
    case static_cast<qint64>(BusinessUserRole::NORMAL):
        return BusinessUserRole::NORMAL;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const Accounting & value)
{
    QJsonObject object;

    if (value.uploadLimitEnd()) {
        object[QStringLiteral("uploadLimitEnd")] = *value.uploadLimitEnd();
    }

    if (value.uploadLimitNextMonth()) {
        object[QStringLiteral("uploadLimitNextMonth")] = *value.uploadLimitNextMonth();
    }

    if (value.premiumServiceStatus()) {
        object[QStringLiteral("premiumServiceStatus")] = QString::number(static_cast<qint64>(*value.premiumServiceStatus()));
    }

    if (value.premiumOrderNumber()) {
        object[QStringLiteral("premiumOrderNumber")] = *value.premiumOrderNumber();
    }

    if (value.premiumCommerceService()) {
        object[QStringLiteral("premiumCommerceService")] = *value.premiumCommerceService();
    }

    if (value.premiumServiceStart()) {
        object[QStringLiteral("premiumServiceStart")] = *value.premiumServiceStart();
    }

    if (value.premiumServiceSKU()) {
        object[QStringLiteral("premiumServiceSKU")] = *value.premiumServiceSKU();
    }

    if (value.lastSuccessfulCharge()) {
        object[QStringLiteral("lastSuccessfulCharge")] = *value.lastSuccessfulCharge();
    }

    if (value.lastFailedCharge()) {
        object[QStringLiteral("lastFailedCharge")] = *value.lastFailedCharge();
    }

    if (value.lastFailedChargeReason()) {
        object[QStringLiteral("lastFailedChargeReason")] = *value.lastFailedChargeReason();
    }

    if (value.nextPaymentDue()) {
        object[QStringLiteral("nextPaymentDue")] = *value.nextPaymentDue();
    }

    if (value.premiumLockUntil()) {
        object[QStringLiteral("premiumLockUntil")] = *value.premiumLockUntil();
    }

    if (value.updated()) {
        object[QStringLiteral("updated")] = *value.updated();
    }

    if (value.premiumSubscriptionNumber()) {
        object[QStringLiteral("premiumSubscriptionNumber")] = *value.premiumSubscriptionNumber();
    }

    if (value.lastRequestedCharge()) {
        object[QStringLiteral("lastRequestedCharge")] = *value.lastRequestedCharge();
    }

    if (value.currency()) {
        object[QStringLiteral("currency")] = *value.currency();
    }

    if (value.unitPrice()) {
        object[QStringLiteral("unitPrice")] = *value.unitPrice();
    }

    if (value.businessId()) {
        object[QStringLiteral("businessId")] = *value.businessId();
    }

    if (value.businessName()) {
        object[QStringLiteral("businessName")] = *value.businessName();
    }

    if (value.businessRole()) {
        object[QStringLiteral("businessRole")] = QString::number(static_cast<qint64>(*value.businessRole()));
    }

    if (value.unitDiscount()) {
        object[QStringLiteral("unitDiscount")] = *value.unitDiscount();
    }

    if (value.nextChargeDate()) {
        object[QStringLiteral("nextChargeDate")] = *value.nextChargeDate();
    }

    if (value.availablePoints()) {
        object[QStringLiteral("availablePoints")] = *value.availablePoints();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Accounting & value)
{
    if (object.contains(QStringLiteral("uploadLimitEnd"))) {
        const auto v = object[QStringLiteral("uploadLimitEnd")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setUploadLimitEnd(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("uploadLimitNextMonth"))) {
        const auto v = object[QStringLiteral("uploadLimitNextMonth")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setUploadLimitNextMonth(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumServiceStatus"))) {
        const auto v = object[QStringLiteral("premiumServiceStatus")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastPremiumOrderStatusToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setPremiumServiceStatus(*e);
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (object.contains(QStringLiteral("premiumOrderNumber"))) {
        const auto v = object[QStringLiteral("premiumOrderNumber")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPremiumOrderNumber(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumCommerceService"))) {
        const auto v = object[QStringLiteral("premiumCommerceService")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPremiumCommerceService(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumServiceStart"))) {
        const auto v = object[QStringLiteral("premiumServiceStart")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setPremiumServiceStart(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumServiceSKU"))) {
        const auto v = object[QStringLiteral("premiumServiceSKU")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPremiumServiceSKU(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("lastSuccessfulCharge"))) {
        const auto v = object[QStringLiteral("lastSuccessfulCharge")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setLastSuccessfulCharge(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("lastFailedCharge"))) {
        const auto v = object[QStringLiteral("lastFailedCharge")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setLastFailedCharge(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("lastFailedChargeReason"))) {
        const auto v = object[QStringLiteral("lastFailedChargeReason")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLastFailedChargeReason(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("nextPaymentDue"))) {
        const auto v = object[QStringLiteral("nextPaymentDue")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setNextPaymentDue(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumLockUntil"))) {
        const auto v = object[QStringLiteral("premiumLockUntil")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setPremiumLockUntil(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updated"))) {
        const auto v = object[QStringLiteral("updated")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setUpdated(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("premiumSubscriptionNumber"))) {
        const auto v = object[QStringLiteral("premiumSubscriptionNumber")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPremiumSubscriptionNumber(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("lastRequestedCharge"))) {
        const auto v = object[QStringLiteral("lastRequestedCharge")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setLastRequestedCharge(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("currency"))) {
        const auto v = object[QStringLiteral("currency")];
        if (v.isString()) {
            auto s = v.toString();
            value.setCurrency(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("unitPrice"))) {
        const auto v = object[QStringLiteral("unitPrice")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUnitPrice(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessId"))) {
        const auto v = object[QStringLiteral("businessId")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setBusinessId(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessName"))) {
        const auto v = object[QStringLiteral("businessName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setBusinessName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessRole"))) {
        const auto v = object[QStringLiteral("businessRole")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastBusinessUserRoleToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setBusinessRole(*e);
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (object.contains(QStringLiteral("unitDiscount"))) {
        const auto v = object[QStringLiteral("unitDiscount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUnitDiscount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("nextChargeDate"))) {
        const auto v = object[QStringLiteral("nextChargeDate")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setNextChargeDate(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("availablePoints"))) {
        const auto v = object[QStringLiteral("availablePoints")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setAvailablePoints(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
