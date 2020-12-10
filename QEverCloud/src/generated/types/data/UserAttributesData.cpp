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

#include "UserAttributesData.h"

#include <QTextStream>

namespace qevercloud {

bool UserAttributes::UserAttributesData::operator==(
    const UserAttributesData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_defaultLocationName == other.m_defaultLocationName &&
        m_defaultLatitude == other.m_defaultLatitude &&
        m_defaultLongitude == other.m_defaultLongitude &&
        m_preactivation == other.m_preactivation &&
        m_viewedPromotions == other.m_viewedPromotions &&
        m_incomingEmailAddress == other.m_incomingEmailAddress &&
        m_recentMailedAddresses == other.m_recentMailedAddresses &&
        m_comments == other.m_comments &&
        m_dateAgreedToTermsOfService == other.m_dateAgreedToTermsOfService &&
        m_maxReferrals == other.m_maxReferrals &&
        m_referralCount == other.m_referralCount &&
        m_refererCode == other.m_refererCode &&
        m_sentEmailDate == other.m_sentEmailDate &&
        m_sentEmailCount == other.m_sentEmailCount &&
        m_dailyEmailLimit == other.m_dailyEmailLimit &&
        m_emailOptOutDate == other.m_emailOptOutDate &&
        m_partnerEmailOptInDate == other.m_partnerEmailOptInDate &&
        m_preferredLanguage == other.m_preferredLanguage &&
        m_preferredCountry == other.m_preferredCountry &&
        m_clipFullPage == other.m_clipFullPage &&
        m_twitterUserName == other.m_twitterUserName &&
        m_twitterId == other.m_twitterId &&
        m_groupName == other.m_groupName &&
        m_recognitionLanguage == other.m_recognitionLanguage &&
        m_referralProof == other.m_referralProof &&
        m_educationalDiscount == other.m_educationalDiscount &&
        m_businessAddress == other.m_businessAddress &&
        m_hideSponsorBilling == other.m_hideSponsorBilling &&
        m_useEmailAutoFiling == other.m_useEmailAutoFiling &&
        m_reminderEmailConfig == other.m_reminderEmailConfig &&
        m_emailAddressLastConfirmed == other.m_emailAddressLastConfirmed &&
        m_passwordUpdated == other.m_passwordUpdated &&
        m_salesforcePushEnabled == other.m_salesforcePushEnabled &&
        m_shouldLogClientEvent == other.m_shouldLogClientEvent &&
        m_optOutMachineLearning == other.m_optOutMachineLearning;
}

bool UserAttributes::UserAttributesData::operator!=(
    const UserAttributesData & other) const noexcept
{
    return !(*this == other);
}

void UserAttributes::UserAttributesData::print(QTextStream & strm) const
{
    strm << "UserAttributes: {\n";

    if (m_defaultLocationName) {
        strm << "    defaultLocationName = "
            << *m_defaultLocationName << "\n";
    }
    else {
        strm << "    defaultLocationName is not set\n";
    }

    if (m_defaultLatitude) {
        strm << "    defaultLatitude = "
            << *m_defaultLatitude << "\n";
    }
    else {
        strm << "    defaultLatitude is not set\n";
    }

    if (m_defaultLongitude) {
        strm << "    defaultLongitude = "
            << *m_defaultLongitude << "\n";
    }
    else {
        strm << "    defaultLongitude is not set\n";
    }

    if (m_preactivation) {
        strm << "    preactivation = "
            << *m_preactivation << "\n";
    }
    else {
        strm << "    preactivation is not set\n";
    }

    if (m_viewedPromotions) {
        strm << "    viewedPromotions = "
            << "QList<QString> {";
        for(const auto & v: *m_viewedPromotions) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    viewedPromotions is not set\n";
    }

    if (m_incomingEmailAddress) {
        strm << "    incomingEmailAddress = "
            << *m_incomingEmailAddress << "\n";
    }
    else {
        strm << "    incomingEmailAddress is not set\n";
    }

    if (m_recentMailedAddresses) {
        strm << "    recentMailedAddresses = "
            << "QList<QString> {";
        for(const auto & v: *m_recentMailedAddresses) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    recentMailedAddresses is not set\n";
    }

    if (m_comments) {
        strm << "    comments = "
            << *m_comments << "\n";
    }
    else {
        strm << "    comments is not set\n";
    }

    if (m_dateAgreedToTermsOfService) {
        strm << "    dateAgreedToTermsOfService = "
            << *m_dateAgreedToTermsOfService << "\n";
    }
    else {
        strm << "    dateAgreedToTermsOfService is not set\n";
    }

    if (m_maxReferrals) {
        strm << "    maxReferrals = "
            << *m_maxReferrals << "\n";
    }
    else {
        strm << "    maxReferrals is not set\n";
    }

    if (m_referralCount) {
        strm << "    referralCount = "
            << *m_referralCount << "\n";
    }
    else {
        strm << "    referralCount is not set\n";
    }

    if (m_refererCode) {
        strm << "    refererCode = "
            << *m_refererCode << "\n";
    }
    else {
        strm << "    refererCode is not set\n";
    }

    if (m_sentEmailDate) {
        strm << "    sentEmailDate = "
            << *m_sentEmailDate << "\n";
    }
    else {
        strm << "    sentEmailDate is not set\n";
    }

    if (m_sentEmailCount) {
        strm << "    sentEmailCount = "
            << *m_sentEmailCount << "\n";
    }
    else {
        strm << "    sentEmailCount is not set\n";
    }

    if (m_dailyEmailLimit) {
        strm << "    dailyEmailLimit = "
            << *m_dailyEmailLimit << "\n";
    }
    else {
        strm << "    dailyEmailLimit is not set\n";
    }

    if (m_emailOptOutDate) {
        strm << "    emailOptOutDate = "
            << *m_emailOptOutDate << "\n";
    }
    else {
        strm << "    emailOptOutDate is not set\n";
    }

    if (m_partnerEmailOptInDate) {
        strm << "    partnerEmailOptInDate = "
            << *m_partnerEmailOptInDate << "\n";
    }
    else {
        strm << "    partnerEmailOptInDate is not set\n";
    }

    if (m_preferredLanguage) {
        strm << "    preferredLanguage = "
            << *m_preferredLanguage << "\n";
    }
    else {
        strm << "    preferredLanguage is not set\n";
    }

    if (m_preferredCountry) {
        strm << "    preferredCountry = "
            << *m_preferredCountry << "\n";
    }
    else {
        strm << "    preferredCountry is not set\n";
    }

    if (m_clipFullPage) {
        strm << "    clipFullPage = "
            << *m_clipFullPage << "\n";
    }
    else {
        strm << "    clipFullPage is not set\n";
    }

    if (m_twitterUserName) {
        strm << "    twitterUserName = "
            << *m_twitterUserName << "\n";
    }
    else {
        strm << "    twitterUserName is not set\n";
    }

    if (m_twitterId) {
        strm << "    twitterId = "
            << *m_twitterId << "\n";
    }
    else {
        strm << "    twitterId is not set\n";
    }

    if (m_groupName) {
        strm << "    groupName = "
            << *m_groupName << "\n";
    }
    else {
        strm << "    groupName is not set\n";
    }

    if (m_recognitionLanguage) {
        strm << "    recognitionLanguage = "
            << *m_recognitionLanguage << "\n";
    }
    else {
        strm << "    recognitionLanguage is not set\n";
    }

    if (m_referralProof) {
        strm << "    referralProof = "
            << *m_referralProof << "\n";
    }
    else {
        strm << "    referralProof is not set\n";
    }

    if (m_educationalDiscount) {
        strm << "    educationalDiscount = "
            << *m_educationalDiscount << "\n";
    }
    else {
        strm << "    educationalDiscount is not set\n";
    }

    if (m_businessAddress) {
        strm << "    businessAddress = "
            << *m_businessAddress << "\n";
    }
    else {
        strm << "    businessAddress is not set\n";
    }

    if (m_hideSponsorBilling) {
        strm << "    hideSponsorBilling = "
            << *m_hideSponsorBilling << "\n";
    }
    else {
        strm << "    hideSponsorBilling is not set\n";
    }

    if (m_useEmailAutoFiling) {
        strm << "    useEmailAutoFiling = "
            << *m_useEmailAutoFiling << "\n";
    }
    else {
        strm << "    useEmailAutoFiling is not set\n";
    }

    if (m_reminderEmailConfig) {
        strm << "    reminderEmailConfig = "
            << *m_reminderEmailConfig << "\n";
    }
    else {
        strm << "    reminderEmailConfig is not set\n";
    }

    if (m_emailAddressLastConfirmed) {
        strm << "    emailAddressLastConfirmed = "
            << *m_emailAddressLastConfirmed << "\n";
    }
    else {
        strm << "    emailAddressLastConfirmed is not set\n";
    }

    if (m_passwordUpdated) {
        strm << "    passwordUpdated = "
            << *m_passwordUpdated << "\n";
    }
    else {
        strm << "    passwordUpdated is not set\n";
    }

    if (m_salesforcePushEnabled) {
        strm << "    salesforcePushEnabled = "
            << *m_salesforcePushEnabled << "\n";
    }
    else {
        strm << "    salesforcePushEnabled is not set\n";
    }

    if (m_shouldLogClientEvent) {
        strm << "    shouldLogClientEvent = "
            << *m_shouldLogClientEvent << "\n";
    }
    else {
        strm << "    shouldLogClientEvent is not set\n";
    }

    if (m_optOutMachineLearning) {
        strm << "    optOutMachineLearning = "
            << *m_optOutMachineLearning << "\n";
    }
    else {
        strm << "    optOutMachineLearning is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
