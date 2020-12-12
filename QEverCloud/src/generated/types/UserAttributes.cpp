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

#include <generated/types/UserAttributes.h>

#include "impl/UserAttributesImpl.h"

namespace qevercloud {

UserAttributes::UserAttributes() : d(new UserAttributes::Impl) {}

UserAttributes::UserAttributes(const UserAttributes & other) : d(other.d) {}

UserAttributes::UserAttributes(UserAttributes && other) noexcept : d(std::move(other.d))
{}

UserAttributes::~UserAttributes() noexcept {}

UserAttributes & UserAttributes::operator=(const UserAttributes & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

UserAttributes & UserAttributes::operator=(UserAttributes && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & UserAttributes::defaultLocationName() const noexcept
{
    return d->m_defaultLocationName;
}

void UserAttributes::setDefaultLocationName(std::optional<QString> defaultLocationName)
{
    d->m_defaultLocationName = defaultLocationName;
}

const std::optional<double> & UserAttributes::defaultLatitude() const noexcept
{
    return d->m_defaultLatitude;
}

std::optional<double> & UserAttributes::mutableDefaultLatitude()
{
    return d->m_defaultLatitude;
}

void UserAttributes::setDefaultLatitude(std::optional<double> defaultLatitude)
{
    d->m_defaultLatitude = defaultLatitude;
}

const std::optional<double> & UserAttributes::defaultLongitude() const noexcept
{
    return d->m_defaultLongitude;
}

std::optional<double> & UserAttributes::mutableDefaultLongitude()
{
    return d->m_defaultLongitude;
}

void UserAttributes::setDefaultLongitude(std::optional<double> defaultLongitude)
{
    d->m_defaultLongitude = defaultLongitude;
}

const std::optional<bool> & UserAttributes::preactivation() const noexcept
{
    return d->m_preactivation;
}

std::optional<bool> & UserAttributes::mutablePreactivation()
{
    return d->m_preactivation;
}

void UserAttributes::setPreactivation(std::optional<bool> preactivation)
{
    d->m_preactivation = preactivation;
}

const std::optional<QStringList> & UserAttributes::viewedPromotions() const noexcept
{
    return d->m_viewedPromotions;
}

std::optional<QStringList> & UserAttributes::mutableViewedPromotions()
{
    return d->m_viewedPromotions;
}

void UserAttributes::setViewedPromotions(std::optional<QStringList> viewedPromotions)
{
    d->m_viewedPromotions = viewedPromotions;
}

const std::optional<QString> & UserAttributes::incomingEmailAddress() const noexcept
{
    return d->m_incomingEmailAddress;
}

void UserAttributes::setIncomingEmailAddress(std::optional<QString> incomingEmailAddress)
{
    d->m_incomingEmailAddress = incomingEmailAddress;
}

const std::optional<QStringList> & UserAttributes::recentMailedAddresses() const noexcept
{
    return d->m_recentMailedAddresses;
}

std::optional<QStringList> & UserAttributes::mutableRecentMailedAddresses()
{
    return d->m_recentMailedAddresses;
}

void UserAttributes::setRecentMailedAddresses(std::optional<QStringList> recentMailedAddresses)
{
    d->m_recentMailedAddresses = recentMailedAddresses;
}

const std::optional<QString> & UserAttributes::comments() const noexcept
{
    return d->m_comments;
}

void UserAttributes::setComments(std::optional<QString> comments)
{
    d->m_comments = comments;
}

const std::optional<Timestamp> & UserAttributes::dateAgreedToTermsOfService() const noexcept
{
    return d->m_dateAgreedToTermsOfService;
}

std::optional<Timestamp> & UserAttributes::mutableDateAgreedToTermsOfService()
{
    return d->m_dateAgreedToTermsOfService;
}

void UserAttributes::setDateAgreedToTermsOfService(std::optional<Timestamp> dateAgreedToTermsOfService)
{
    d->m_dateAgreedToTermsOfService = dateAgreedToTermsOfService;
}

const std::optional<qint32> & UserAttributes::maxReferrals() const noexcept
{
    return d->m_maxReferrals;
}

std::optional<qint32> & UserAttributes::mutableMaxReferrals()
{
    return d->m_maxReferrals;
}

void UserAttributes::setMaxReferrals(std::optional<qint32> maxReferrals)
{
    d->m_maxReferrals = maxReferrals;
}

const std::optional<qint32> & UserAttributes::referralCount() const noexcept
{
    return d->m_referralCount;
}

std::optional<qint32> & UserAttributes::mutableReferralCount()
{
    return d->m_referralCount;
}

void UserAttributes::setReferralCount(std::optional<qint32> referralCount)
{
    d->m_referralCount = referralCount;
}

const std::optional<QString> & UserAttributes::refererCode() const noexcept
{
    return d->m_refererCode;
}

void UserAttributes::setRefererCode(std::optional<QString> refererCode)
{
    d->m_refererCode = refererCode;
}

const std::optional<Timestamp> & UserAttributes::sentEmailDate() const noexcept
{
    return d->m_sentEmailDate;
}

std::optional<Timestamp> & UserAttributes::mutableSentEmailDate()
{
    return d->m_sentEmailDate;
}

void UserAttributes::setSentEmailDate(std::optional<Timestamp> sentEmailDate)
{
    d->m_sentEmailDate = sentEmailDate;
}

const std::optional<qint32> & UserAttributes::sentEmailCount() const noexcept
{
    return d->m_sentEmailCount;
}

std::optional<qint32> & UserAttributes::mutableSentEmailCount()
{
    return d->m_sentEmailCount;
}

void UserAttributes::setSentEmailCount(std::optional<qint32> sentEmailCount)
{
    d->m_sentEmailCount = sentEmailCount;
}

const std::optional<qint32> & UserAttributes::dailyEmailLimit() const noexcept
{
    return d->m_dailyEmailLimit;
}

std::optional<qint32> & UserAttributes::mutableDailyEmailLimit()
{
    return d->m_dailyEmailLimit;
}

void UserAttributes::setDailyEmailLimit(std::optional<qint32> dailyEmailLimit)
{
    d->m_dailyEmailLimit = dailyEmailLimit;
}

const std::optional<Timestamp> & UserAttributes::emailOptOutDate() const noexcept
{
    return d->m_emailOptOutDate;
}

std::optional<Timestamp> & UserAttributes::mutableEmailOptOutDate()
{
    return d->m_emailOptOutDate;
}

void UserAttributes::setEmailOptOutDate(std::optional<Timestamp> emailOptOutDate)
{
    d->m_emailOptOutDate = emailOptOutDate;
}

const std::optional<Timestamp> & UserAttributes::partnerEmailOptInDate() const noexcept
{
    return d->m_partnerEmailOptInDate;
}

std::optional<Timestamp> & UserAttributes::mutablePartnerEmailOptInDate()
{
    return d->m_partnerEmailOptInDate;
}

void UserAttributes::setPartnerEmailOptInDate(std::optional<Timestamp> partnerEmailOptInDate)
{
    d->m_partnerEmailOptInDate = partnerEmailOptInDate;
}

const std::optional<QString> & UserAttributes::preferredLanguage() const noexcept
{
    return d->m_preferredLanguage;
}

void UserAttributes::setPreferredLanguage(std::optional<QString> preferredLanguage)
{
    d->m_preferredLanguage = preferredLanguage;
}

const std::optional<QString> & UserAttributes::preferredCountry() const noexcept
{
    return d->m_preferredCountry;
}

void UserAttributes::setPreferredCountry(std::optional<QString> preferredCountry)
{
    d->m_preferredCountry = preferredCountry;
}

const std::optional<bool> & UserAttributes::clipFullPage() const noexcept
{
    return d->m_clipFullPage;
}

std::optional<bool> & UserAttributes::mutableClipFullPage()
{
    return d->m_clipFullPage;
}

void UserAttributes::setClipFullPage(std::optional<bool> clipFullPage)
{
    d->m_clipFullPage = clipFullPage;
}

const std::optional<QString> & UserAttributes::twitterUserName() const noexcept
{
    return d->m_twitterUserName;
}

void UserAttributes::setTwitterUserName(std::optional<QString> twitterUserName)
{
    d->m_twitterUserName = twitterUserName;
}

const std::optional<QString> & UserAttributes::twitterId() const noexcept
{
    return d->m_twitterId;
}

void UserAttributes::setTwitterId(std::optional<QString> twitterId)
{
    d->m_twitterId = twitterId;
}

const std::optional<QString> & UserAttributes::groupName() const noexcept
{
    return d->m_groupName;
}

void UserAttributes::setGroupName(std::optional<QString> groupName)
{
    d->m_groupName = groupName;
}

const std::optional<QString> & UserAttributes::recognitionLanguage() const noexcept
{
    return d->m_recognitionLanguage;
}

void UserAttributes::setRecognitionLanguage(std::optional<QString> recognitionLanguage)
{
    d->m_recognitionLanguage = recognitionLanguage;
}

const std::optional<QString> & UserAttributes::referralProof() const noexcept
{
    return d->m_referralProof;
}

void UserAttributes::setReferralProof(std::optional<QString> referralProof)
{
    d->m_referralProof = referralProof;
}

const std::optional<bool> & UserAttributes::educationalDiscount() const noexcept
{
    return d->m_educationalDiscount;
}

std::optional<bool> & UserAttributes::mutableEducationalDiscount()
{
    return d->m_educationalDiscount;
}

void UserAttributes::setEducationalDiscount(std::optional<bool> educationalDiscount)
{
    d->m_educationalDiscount = educationalDiscount;
}

const std::optional<QString> & UserAttributes::businessAddress() const noexcept
{
    return d->m_businessAddress;
}

void UserAttributes::setBusinessAddress(std::optional<QString> businessAddress)
{
    d->m_businessAddress = businessAddress;
}

const std::optional<bool> & UserAttributes::hideSponsorBilling() const noexcept
{
    return d->m_hideSponsorBilling;
}

std::optional<bool> & UserAttributes::mutableHideSponsorBilling()
{
    return d->m_hideSponsorBilling;
}

void UserAttributes::setHideSponsorBilling(std::optional<bool> hideSponsorBilling)
{
    d->m_hideSponsorBilling = hideSponsorBilling;
}

const std::optional<bool> & UserAttributes::useEmailAutoFiling() const noexcept
{
    return d->m_useEmailAutoFiling;
}

std::optional<bool> & UserAttributes::mutableUseEmailAutoFiling()
{
    return d->m_useEmailAutoFiling;
}

void UserAttributes::setUseEmailAutoFiling(std::optional<bool> useEmailAutoFiling)
{
    d->m_useEmailAutoFiling = useEmailAutoFiling;
}

const std::optional<ReminderEmailConfig> & UserAttributes::reminderEmailConfig() const noexcept
{
    return d->m_reminderEmailConfig;
}

std::optional<ReminderEmailConfig> & UserAttributes::mutableReminderEmailConfig()
{
    return d->m_reminderEmailConfig;
}

void UserAttributes::setReminderEmailConfig(std::optional<ReminderEmailConfig> reminderEmailConfig)
{
    d->m_reminderEmailConfig = reminderEmailConfig;
}

const std::optional<Timestamp> & UserAttributes::emailAddressLastConfirmed() const noexcept
{
    return d->m_emailAddressLastConfirmed;
}

std::optional<Timestamp> & UserAttributes::mutableEmailAddressLastConfirmed()
{
    return d->m_emailAddressLastConfirmed;
}

void UserAttributes::setEmailAddressLastConfirmed(std::optional<Timestamp> emailAddressLastConfirmed)
{
    d->m_emailAddressLastConfirmed = emailAddressLastConfirmed;
}

const std::optional<Timestamp> & UserAttributes::passwordUpdated() const noexcept
{
    return d->m_passwordUpdated;
}

std::optional<Timestamp> & UserAttributes::mutablePasswordUpdated()
{
    return d->m_passwordUpdated;
}

void UserAttributes::setPasswordUpdated(std::optional<Timestamp> passwordUpdated)
{
    d->m_passwordUpdated = passwordUpdated;
}

const std::optional<bool> & UserAttributes::salesforcePushEnabled() const noexcept
{
    return d->m_salesforcePushEnabled;
}

std::optional<bool> & UserAttributes::mutableSalesforcePushEnabled()
{
    return d->m_salesforcePushEnabled;
}

void UserAttributes::setSalesforcePushEnabled(std::optional<bool> salesforcePushEnabled)
{
    d->m_salesforcePushEnabled = salesforcePushEnabled;
}

const std::optional<bool> & UserAttributes::shouldLogClientEvent() const noexcept
{
    return d->m_shouldLogClientEvent;
}

std::optional<bool> & UserAttributes::mutableShouldLogClientEvent()
{
    return d->m_shouldLogClientEvent;
}

void UserAttributes::setShouldLogClientEvent(std::optional<bool> shouldLogClientEvent)
{
    d->m_shouldLogClientEvent = shouldLogClientEvent;
}

const std::optional<bool> & UserAttributes::optOutMachineLearning() const noexcept
{
    return d->m_optOutMachineLearning;
}

std::optional<bool> & UserAttributes::mutableOptOutMachineLearning()
{
    return d->m_optOutMachineLearning;
}

void UserAttributes::setOptOutMachineLearning(std::optional<bool> optOutMachineLearning)
{
    d->m_optOutMachineLearning = optOutMachineLearning;
}

void UserAttributes::print(QTextStream & strm) const
{
    d->print(strm);
}

bool UserAttributes::operator==(const UserAttributes & other) const noexcept
{
    return *d == *other.d;
}

bool UserAttributes::operator!=(const UserAttributes & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
