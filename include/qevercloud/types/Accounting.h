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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTING
#define QEVERCLOUD_GENERATED_ACCOUNTING

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This represents the bookkeeping information for the user's subscription.
 *
 **/
class QEVERCLOUD_EXPORT Accounting: public Printable
{
    Q_GADGET
public:
    Accounting();
    Accounting(const Accounting & other);
    Accounting(Accounting && other) noexcept;
    ~Accounting() noexcept override;

    Accounting & operator=(const Accounting & other);
    Accounting & operator=(Accounting && other) noexcept;

    /**
     * The date and time when the current upload limit
     * expires. At this time, the monthly upload count reverts to 0 and a new
     * limit is imposed. This date and time is exclusive, so this is effectively
     * the start of the new month.
     */
    [[nodiscard]] const std::optional<Timestamp> & uploadLimitEnd() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUploadLimitEnd();
    void setUploadLimitEnd(std::optional<Timestamp> uploadLimitEnd);

    /**
     * When uploadLimitEnd is reached, the service
     * will change uploadLimit to uploadLimitNextMonth. If a premium account is
     * canceled, this mechanism will reset the quota appropriately.
     */
    [[nodiscard]] const std::optional<qint64> & uploadLimitNextMonth() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableUploadLimitNextMonth();
    void setUploadLimitNextMonth(std::optional<qint64> uploadLimitNextMonth);

    /**
     * Indicates the phases of a premium account
     * during the billing process.
     */
    [[nodiscard]] const std::optional<PremiumOrderStatus> & premiumServiceStatus() const noexcept;
    [[nodiscard]] std::optional<PremiumOrderStatus> & mutablePremiumServiceStatus();
    void setPremiumServiceStatus(std::optional<PremiumOrderStatus> premiumServiceStatus);

    /**
     * The order number used by the commerce system to
     * process recurring payments
     */
    [[nodiscard]] const std::optional<QString> & premiumOrderNumber() const noexcept;
    void setPremiumOrderNumber(std::optional<QString> premiumOrderNumber);

    /**
     * The commerce system used (paypal, Google
     * checkout, etc)
     */
    [[nodiscard]] const std::optional<QString> & premiumCommerceService() const noexcept;
    void setPremiumCommerceService(std::optional<QString> premiumCommerceService);

    /**
     * The start date when this premium promotion
     * began (this number will get overwritten if a premium service is canceled
     * and then re-activated).
     */
    [[nodiscard]] const std::optional<Timestamp> & premiumServiceStart() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePremiumServiceStart();
    void setPremiumServiceStart(std::optional<Timestamp> premiumServiceStart);

    /**
     * The code associated with the purchase eg. monthly
     * or annual purchase. Clients should interpret this value and localize it.
     */
    [[nodiscard]] const std::optional<QString> & premiumServiceSKU() const noexcept;
    void setPremiumServiceSKU(std::optional<QString> premiumServiceSKU);

    /**
     * Date the last time the user was charged.
     * Null if never charged.
     */
    [[nodiscard]] const std::optional<Timestamp> & lastSuccessfulCharge() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableLastSuccessfulCharge();
    void setLastSuccessfulCharge(std::optional<Timestamp> lastSuccessfulCharge);

    /**
     * Date the last time a charge was attempted and
     * failed.
     */
    [[nodiscard]] const std::optional<Timestamp> & lastFailedCharge() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableLastFailedCharge();
    void setLastFailedCharge(std::optional<Timestamp> lastFailedCharge);

    /**
     * Reason provided for the charge failure
     */
    [[nodiscard]] const std::optional<QString> & lastFailedChargeReason() const noexcept;
    void setLastFailedChargeReason(std::optional<QString> lastFailedChargeReason);

    /**
     * The end of the billing cycle. This could be in the
     * past if there are failed charges.
     */
    [[nodiscard]] const std::optional<Timestamp> & nextPaymentDue() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableNextPaymentDue();
    void setNextPaymentDue(std::optional<Timestamp> nextPaymentDue);

    /**
     * An internal variable to manage locking operations
     * on the commerce variables.
     */
    [[nodiscard]] const std::optional<Timestamp> & premiumLockUntil() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePremiumLockUntil();
    void setPremiumLockUntil(std::optional<Timestamp> premiumLockUntil);

    /**
     * The date any modification where made to this record.
     */
    [[nodiscard]] const std::optional<Timestamp> & updated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUpdated();
    void setUpdated(std::optional<Timestamp> updated);

    /**
     * The number number identifying the
     * recurring subscription used to make the recurring charges.
     */
    [[nodiscard]] const std::optional<QString> & premiumSubscriptionNumber() const noexcept;
    void setPremiumSubscriptionNumber(std::optional<QString> premiumSubscriptionNumber);

    /**
     * Date charge last attempted
     */
    [[nodiscard]] const std::optional<Timestamp> & lastRequestedCharge() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableLastRequestedCharge();
    void setLastRequestedCharge(std::optional<Timestamp> lastRequestedCharge);

    /**
     * ISO 4217 currency code
     */
    [[nodiscard]] const std::optional<QString> & currency() const noexcept;
    void setCurrency(std::optional<QString> currency);

    /**
     * charge in the smallest unit of the currency (e.g. cents for USD)
     */
    [[nodiscard]] const std::optional<qint32> & unitPrice() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUnitPrice();
    void setUnitPrice(std::optional<qint32> unitPrice);

    /**
     * <i>DEPRECATED:</i>See BusinessUserInfo.
     */
    [[nodiscard]] const std::optional<qint32> & businessId() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableBusinessId();
    void setBusinessId(std::optional<qint32> businessId);

    /**
     * <i>DEPRECATED:</i>See BusinessUserInfo.
     */
    [[nodiscard]] const std::optional<QString> & businessName() const noexcept;
    void setBusinessName(std::optional<QString> businessName);

    /**
     * <i>DEPRECATED:</i>See BusinessUserInfo.
     */
    [[nodiscard]] const std::optional<BusinessUserRole> & businessRole() const noexcept;
    [[nodiscard]] std::optional<BusinessUserRole> & mutableBusinessRole();
    void setBusinessRole(std::optional<BusinessUserRole> businessRole);

    /**
     * discount per seat in negative amount and smallest unit of the currency (e.g.
     * cents for USD)
     */
    [[nodiscard]] const std::optional<qint32> & unitDiscount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUnitDiscount();
    void setUnitDiscount(std::optional<qint32> unitDiscount);

    /**
     * The next time the user will be charged, may or may not be the same as
     * nextPaymentDue
     */
    [[nodiscard]] const std::optional<Timestamp> & nextChargeDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableNextChargeDate();
    void setNextChargeDate(std::optional<Timestamp> nextChargeDate);

    [[nodiscard]] const std::optional<qint32> & availablePoints() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableAvailablePoints();
    void setAvailablePoints(std::optional<qint32> availablePoints);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<Timestamp> uploadLimitEnd READ uploadLimitEnd WRITE setUploadLimitEnd)
    Q_PROPERTY(std::optional<qint64> uploadLimitNextMonth READ uploadLimitNextMonth WRITE setUploadLimitNextMonth)
    Q_PROPERTY(std::optional<PremiumOrderStatus> premiumServiceStatus READ premiumServiceStatus WRITE setPremiumServiceStatus)
    Q_PROPERTY(std::optional<QString> premiumOrderNumber READ premiumOrderNumber WRITE setPremiumOrderNumber)
    Q_PROPERTY(std::optional<QString> premiumCommerceService READ premiumCommerceService WRITE setPremiumCommerceService)
    Q_PROPERTY(std::optional<Timestamp> premiumServiceStart READ premiumServiceStart WRITE setPremiumServiceStart)
    Q_PROPERTY(std::optional<QString> premiumServiceSKU READ premiumServiceSKU WRITE setPremiumServiceSKU)
    Q_PROPERTY(std::optional<Timestamp> lastSuccessfulCharge READ lastSuccessfulCharge WRITE setLastSuccessfulCharge)
    Q_PROPERTY(std::optional<Timestamp> lastFailedCharge READ lastFailedCharge WRITE setLastFailedCharge)
    Q_PROPERTY(std::optional<QString> lastFailedChargeReason READ lastFailedChargeReason WRITE setLastFailedChargeReason)
    Q_PROPERTY(std::optional<Timestamp> nextPaymentDue READ nextPaymentDue WRITE setNextPaymentDue)
    Q_PROPERTY(std::optional<Timestamp> premiumLockUntil READ premiumLockUntil WRITE setPremiumLockUntil)
    Q_PROPERTY(std::optional<Timestamp> updated READ updated WRITE setUpdated)
    Q_PROPERTY(std::optional<QString> premiumSubscriptionNumber READ premiumSubscriptionNumber WRITE setPremiumSubscriptionNumber)
    Q_PROPERTY(std::optional<Timestamp> lastRequestedCharge READ lastRequestedCharge WRITE setLastRequestedCharge)
    Q_PROPERTY(std::optional<QString> currency READ currency WRITE setCurrency)
    Q_PROPERTY(std::optional<qint32> unitPrice READ unitPrice WRITE setUnitPrice)
    Q_PROPERTY(std::optional<qint32> businessId READ businessId WRITE setBusinessId)
    Q_PROPERTY(std::optional<QString> businessName READ businessName WRITE setBusinessName)
    Q_PROPERTY(std::optional<BusinessUserRole> businessRole READ businessRole WRITE setBusinessRole)
    Q_PROPERTY(std::optional<qint32> unitDiscount READ unitDiscount WRITE setUnitDiscount)
    Q_PROPERTY(std::optional<Timestamp> nextChargeDate READ nextChargeDate WRITE setNextChargeDate)
    Q_PROPERTY(std::optional<qint32> availablePoints READ availablePoints WRITE setAvailablePoints)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const Accounting & lhs, const Accounting & rhs) noexcept;
[[nodiscard]] bool operator!=(const Accounting & lhs, const Accounting & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Accounting)

#endif // QEVERCLOUD_GENERATED_ACCOUNTING
