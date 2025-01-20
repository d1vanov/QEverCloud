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

#ifndef QEVERCLOUD_GENERATED_USERATTRIBUTESBUILDER
#define QEVERCLOUD_GENERATED_USERATTRIBUTESBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserAttributes.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UserAttributesBuilder
{
public:
    UserAttributesBuilder();

    UserAttributesBuilder(UserAttributesBuilder && other) noexcept;

    ~UserAttributesBuilder() noexcept;

    UserAttributesBuilder & operator=(UserAttributesBuilder && other) noexcept;

    UserAttributesBuilder & setDefaultLocationName(std::optional<QString> defaultLocationName);
    UserAttributesBuilder & setDefaultLatitude(std::optional<double> defaultLatitude);
    UserAttributesBuilder & setDefaultLongitude(std::optional<double> defaultLongitude);
    UserAttributesBuilder & setPreactivation(std::optional<bool> preactivation);
    UserAttributesBuilder & setViewedPromotions(std::optional<QStringList> viewedPromotions);
    UserAttributesBuilder & setIncomingEmailAddress(std::optional<QString> incomingEmailAddress);
    UserAttributesBuilder & setRecentMailedAddresses(std::optional<QStringList> recentMailedAddresses);
    UserAttributesBuilder & setComments(std::optional<QString> comments);
    UserAttributesBuilder & setDateAgreedToTermsOfService(std::optional<Timestamp> dateAgreedToTermsOfService);
    UserAttributesBuilder & setMaxReferrals(std::optional<qint32> maxReferrals);
    UserAttributesBuilder & setReferralCount(std::optional<qint32> referralCount);
    UserAttributesBuilder & setRefererCode(std::optional<QString> refererCode);
    UserAttributesBuilder & setSentEmailDate(std::optional<Timestamp> sentEmailDate);
    UserAttributesBuilder & setSentEmailCount(std::optional<qint32> sentEmailCount);
    UserAttributesBuilder & setDailyEmailLimit(std::optional<qint32> dailyEmailLimit);
    UserAttributesBuilder & setEmailOptOutDate(std::optional<Timestamp> emailOptOutDate);
    UserAttributesBuilder & setPartnerEmailOptInDate(std::optional<Timestamp> partnerEmailOptInDate);
    UserAttributesBuilder & setPreferredLanguage(std::optional<QString> preferredLanguage);
    UserAttributesBuilder & setPreferredCountry(std::optional<QString> preferredCountry);
    UserAttributesBuilder & setClipFullPage(std::optional<bool> clipFullPage);
    UserAttributesBuilder & setTwitterUserName(std::optional<QString> twitterUserName);
    UserAttributesBuilder & setTwitterId(std::optional<QString> twitterId);
    UserAttributesBuilder & setGroupName(std::optional<QString> groupName);
    UserAttributesBuilder & setRecognitionLanguage(std::optional<QString> recognitionLanguage);
    UserAttributesBuilder & setReferralProof(std::optional<QString> referralProof);
    UserAttributesBuilder & setEducationalDiscount(std::optional<bool> educationalDiscount);
    UserAttributesBuilder & setBusinessAddress(std::optional<QString> businessAddress);
    UserAttributesBuilder & setHideSponsorBilling(std::optional<bool> hideSponsorBilling);
    UserAttributesBuilder & setUseEmailAutoFiling(std::optional<bool> useEmailAutoFiling);
    UserAttributesBuilder & setReminderEmailConfig(std::optional<ReminderEmailConfig> reminderEmailConfig);
    UserAttributesBuilder & setEmailAddressLastConfirmed(std::optional<Timestamp> emailAddressLastConfirmed);
    UserAttributesBuilder & setPasswordUpdated(std::optional<Timestamp> passwordUpdated);
    UserAttributesBuilder & setSalesforcePushEnabled(std::optional<bool> salesforcePushEnabled);
    UserAttributesBuilder & setShouldLogClientEvent(std::optional<bool> shouldLogClientEvent);
    UserAttributesBuilder & setOptOutMachineLearning(std::optional<bool> optOutMachineLearning);

    [[nodiscard]] UserAttributes build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERATTRIBUTESBUILDER
