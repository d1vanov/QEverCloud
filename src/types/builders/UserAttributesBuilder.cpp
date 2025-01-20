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

#include <qevercloud/types/builders/UserAttributesBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserAttributesBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_defaultLocationName;
    std::optional<double> m_defaultLatitude;
    std::optional<double> m_defaultLongitude;
    std::optional<bool> m_preactivation;
    std::optional<QStringList> m_viewedPromotions;
    std::optional<QString> m_incomingEmailAddress;
    std::optional<QStringList> m_recentMailedAddresses;
    std::optional<QString> m_comments;
    std::optional<Timestamp> m_dateAgreedToTermsOfService;
    std::optional<qint32> m_maxReferrals;
    std::optional<qint32> m_referralCount;
    std::optional<QString> m_refererCode;
    std::optional<Timestamp> m_sentEmailDate;
    std::optional<qint32> m_sentEmailCount;
    std::optional<qint32> m_dailyEmailLimit;
    std::optional<Timestamp> m_emailOptOutDate;
    std::optional<Timestamp> m_partnerEmailOptInDate;
    std::optional<QString> m_preferredLanguage;
    std::optional<QString> m_preferredCountry;
    std::optional<bool> m_clipFullPage;
    std::optional<QString> m_twitterUserName;
    std::optional<QString> m_twitterId;
    std::optional<QString> m_groupName;
    std::optional<QString> m_recognitionLanguage;
    std::optional<QString> m_referralProof;
    std::optional<bool> m_educationalDiscount;
    std::optional<QString> m_businessAddress;
    std::optional<bool> m_hideSponsorBilling;
    std::optional<bool> m_useEmailAutoFiling;
    std::optional<ReminderEmailConfig> m_reminderEmailConfig;
    std::optional<Timestamp> m_emailAddressLastConfirmed;
    std::optional<Timestamp> m_passwordUpdated;
    std::optional<bool> m_salesforcePushEnabled;
    std::optional<bool> m_shouldLogClientEvent;
    std::optional<bool> m_optOutMachineLearning;
};

UserAttributesBuilder::UserAttributesBuilder() :
    d(new UserAttributesBuilder::Impl)
{}

UserAttributesBuilder::UserAttributesBuilder(UserAttributesBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UserAttributesBuilder::~UserAttributesBuilder() noexcept = default;

UserAttributesBuilder & UserAttributesBuilder::operator=(UserAttributesBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setDefaultLocationName(std::optional<QString> defaultLocationName)
{
    d->m_defaultLocationName = std::move(defaultLocationName);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setDefaultLatitude(std::optional<double> defaultLatitude)
{
    d->m_defaultLatitude = std::move(defaultLatitude);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setDefaultLongitude(std::optional<double> defaultLongitude)
{
    d->m_defaultLongitude = std::move(defaultLongitude);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setPreactivation(std::optional<bool> preactivation)
{
    d->m_preactivation = std::move(preactivation);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setViewedPromotions(std::optional<QStringList> viewedPromotions)
{
    d->m_viewedPromotions = std::move(viewedPromotions);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setIncomingEmailAddress(std::optional<QString> incomingEmailAddress)
{
    d->m_incomingEmailAddress = std::move(incomingEmailAddress);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setRecentMailedAddresses(std::optional<QStringList> recentMailedAddresses)
{
    d->m_recentMailedAddresses = std::move(recentMailedAddresses);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setComments(std::optional<QString> comments)
{
    d->m_comments = std::move(comments);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setDateAgreedToTermsOfService(std::optional<Timestamp> dateAgreedToTermsOfService)
{
    d->m_dateAgreedToTermsOfService = std::move(dateAgreedToTermsOfService);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setMaxReferrals(std::optional<qint32> maxReferrals)
{
    d->m_maxReferrals = std::move(maxReferrals);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setReferralCount(std::optional<qint32> referralCount)
{
    d->m_referralCount = std::move(referralCount);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setRefererCode(std::optional<QString> refererCode)
{
    d->m_refererCode = std::move(refererCode);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setSentEmailDate(std::optional<Timestamp> sentEmailDate)
{
    d->m_sentEmailDate = std::move(sentEmailDate);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setSentEmailCount(std::optional<qint32> sentEmailCount)
{
    d->m_sentEmailCount = std::move(sentEmailCount);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setDailyEmailLimit(std::optional<qint32> dailyEmailLimit)
{
    d->m_dailyEmailLimit = std::move(dailyEmailLimit);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setEmailOptOutDate(std::optional<Timestamp> emailOptOutDate)
{
    d->m_emailOptOutDate = std::move(emailOptOutDate);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setPartnerEmailOptInDate(std::optional<Timestamp> partnerEmailOptInDate)
{
    d->m_partnerEmailOptInDate = std::move(partnerEmailOptInDate);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setPreferredLanguage(std::optional<QString> preferredLanguage)
{
    d->m_preferredLanguage = std::move(preferredLanguage);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setPreferredCountry(std::optional<QString> preferredCountry)
{
    d->m_preferredCountry = std::move(preferredCountry);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setClipFullPage(std::optional<bool> clipFullPage)
{
    d->m_clipFullPage = std::move(clipFullPage);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setTwitterUserName(std::optional<QString> twitterUserName)
{
    d->m_twitterUserName = std::move(twitterUserName);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setTwitterId(std::optional<QString> twitterId)
{
    d->m_twitterId = std::move(twitterId);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setGroupName(std::optional<QString> groupName)
{
    d->m_groupName = std::move(groupName);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setRecognitionLanguage(std::optional<QString> recognitionLanguage)
{
    d->m_recognitionLanguage = std::move(recognitionLanguage);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setReferralProof(std::optional<QString> referralProof)
{
    d->m_referralProof = std::move(referralProof);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setEducationalDiscount(std::optional<bool> educationalDiscount)
{
    d->m_educationalDiscount = std::move(educationalDiscount);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setBusinessAddress(std::optional<QString> businessAddress)
{
    d->m_businessAddress = std::move(businessAddress);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setHideSponsorBilling(std::optional<bool> hideSponsorBilling)
{
    d->m_hideSponsorBilling = std::move(hideSponsorBilling);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setUseEmailAutoFiling(std::optional<bool> useEmailAutoFiling)
{
    d->m_useEmailAutoFiling = std::move(useEmailAutoFiling);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setReminderEmailConfig(std::optional<ReminderEmailConfig> reminderEmailConfig)
{
    d->m_reminderEmailConfig = std::move(reminderEmailConfig);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setEmailAddressLastConfirmed(std::optional<Timestamp> emailAddressLastConfirmed)
{
    d->m_emailAddressLastConfirmed = std::move(emailAddressLastConfirmed);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setPasswordUpdated(std::optional<Timestamp> passwordUpdated)
{
    d->m_passwordUpdated = std::move(passwordUpdated);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setSalesforcePushEnabled(std::optional<bool> salesforcePushEnabled)
{
    d->m_salesforcePushEnabled = std::move(salesforcePushEnabled);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setShouldLogClientEvent(std::optional<bool> shouldLogClientEvent)
{
    d->m_shouldLogClientEvent = std::move(shouldLogClientEvent);
    return *this;
}

UserAttributesBuilder & UserAttributesBuilder::setOptOutMachineLearning(std::optional<bool> optOutMachineLearning)
{
    d->m_optOutMachineLearning = std::move(optOutMachineLearning);
    return *this;
}

UserAttributes UserAttributesBuilder::build()
{
    UserAttributes result;

    result.setDefaultLocationName(std::move(d->m_defaultLocationName));
    result.setDefaultLatitude(std::move(d->m_defaultLatitude));
    result.setDefaultLongitude(std::move(d->m_defaultLongitude));
    result.setPreactivation(std::move(d->m_preactivation));
    result.setViewedPromotions(std::move(d->m_viewedPromotions));
    result.setIncomingEmailAddress(std::move(d->m_incomingEmailAddress));
    result.setRecentMailedAddresses(std::move(d->m_recentMailedAddresses));
    result.setComments(std::move(d->m_comments));
    result.setDateAgreedToTermsOfService(std::move(d->m_dateAgreedToTermsOfService));
    result.setMaxReferrals(std::move(d->m_maxReferrals));
    result.setReferralCount(std::move(d->m_referralCount));
    result.setRefererCode(std::move(d->m_refererCode));
    result.setSentEmailDate(std::move(d->m_sentEmailDate));
    result.setSentEmailCount(std::move(d->m_sentEmailCount));
    result.setDailyEmailLimit(std::move(d->m_dailyEmailLimit));
    result.setEmailOptOutDate(std::move(d->m_emailOptOutDate));
    result.setPartnerEmailOptInDate(std::move(d->m_partnerEmailOptInDate));
    result.setPreferredLanguage(std::move(d->m_preferredLanguage));
    result.setPreferredCountry(std::move(d->m_preferredCountry));
    result.setClipFullPage(std::move(d->m_clipFullPage));
    result.setTwitterUserName(std::move(d->m_twitterUserName));
    result.setTwitterId(std::move(d->m_twitterId));
    result.setGroupName(std::move(d->m_groupName));
    result.setRecognitionLanguage(std::move(d->m_recognitionLanguage));
    result.setReferralProof(std::move(d->m_referralProof));
    result.setEducationalDiscount(std::move(d->m_educationalDiscount));
    result.setBusinessAddress(std::move(d->m_businessAddress));
    result.setHideSponsorBilling(std::move(d->m_hideSponsorBilling));
    result.setUseEmailAutoFiling(std::move(d->m_useEmailAutoFiling));
    result.setReminderEmailConfig(std::move(d->m_reminderEmailConfig));
    result.setEmailAddressLastConfirmed(std::move(d->m_emailAddressLastConfirmed));
    result.setPasswordUpdated(std::move(d->m_passwordUpdated));
    result.setSalesforcePushEnabled(std::move(d->m_salesforcePushEnabled));
    result.setShouldLogClientEvent(std::move(d->m_shouldLogClientEvent));
    result.setOptOutMachineLearning(std::move(d->m_optOutMachineLearning));

    d->m_defaultLocationName = {};
    d->m_defaultLatitude = {};
    d->m_defaultLongitude = {};
    d->m_preactivation = {};
    d->m_viewedPromotions = {};
    d->m_incomingEmailAddress = {};
    d->m_recentMailedAddresses = {};
    d->m_comments = {};
    d->m_dateAgreedToTermsOfService = {};
    d->m_maxReferrals = {};
    d->m_referralCount = {};
    d->m_refererCode = {};
    d->m_sentEmailDate = {};
    d->m_sentEmailCount = {};
    d->m_dailyEmailLimit = {};
    d->m_emailOptOutDate = {};
    d->m_partnerEmailOptInDate = {};
    d->m_preferredLanguage = {};
    d->m_preferredCountry = {};
    d->m_clipFullPage = {};
    d->m_twitterUserName = {};
    d->m_twitterId = {};
    d->m_groupName = {};
    d->m_recognitionLanguage = {};
    d->m_referralProof = {};
    d->m_educationalDiscount = {};
    d->m_businessAddress = {};
    d->m_hideSponsorBilling = {};
    d->m_useEmailAutoFiling = {};
    d->m_reminderEmailConfig = {};
    d->m_emailAddressLastConfirmed = {};
    d->m_passwordUpdated = {};
    d->m_salesforcePushEnabled = {};
    d->m_shouldLogClientEvent = {};
    d->m_optOutMachineLearning = {};

    return result;
}

} // namespace qevercloud
