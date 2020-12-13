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

#ifndef QEVERCLOUD_GENERATED_USERATTRIBUTESIMPL_H
#define QEVERCLOUD_GENERATED_USERATTRIBUTESIMPL_H

#include <qevercloud/generated/types/UserAttributes.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserAttributes::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const UserAttributes::Impl & other) = default;
    Impl(UserAttributes::Impl && other) noexcept = default;

    UserAttributes::Impl & operator=(const UserAttributes::Impl & other) = delete;
    UserAttributes::Impl & operator=(UserAttributes::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const UserAttributes::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserAttributes::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERATTRIBUTESIMPL_H
