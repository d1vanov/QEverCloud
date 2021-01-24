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

#ifndef QEVERCLOUD_GENERATED_USERATTRIBUTES_H
#define QEVERCLOUD_GENERATED_USERATTRIBUTES_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure holding the optional attributes that can be stored
 * on a User.  These are generally less critical than the core User fields.
 *
 **/
class QEVERCLOUD_EXPORT UserAttributes: public Printable
{
    Q_GADGET
public:
    UserAttributes();
    UserAttributes(const UserAttributes & other);
    UserAttributes(UserAttributes && other) noexcept;
    ~UserAttributes() noexcept override;

    UserAttributes & operator=(const UserAttributes & other);
    UserAttributes & operator=(UserAttributes && other) noexcept;

    /**
     * the location string that should be associated
     * with the user in order to determine where notes are taken if not otherwise
     * specified.<br/>
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & defaultLocationName() const noexcept;
    void setDefaultLocationName(std::optional<QString> defaultLocationName);

    /**
     * if set, this is the latitude that should be
     * assigned to any notes that have no other latitude information.
     */
    [[nodiscard]] const std::optional<double> & defaultLatitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableDefaultLatitude();
    void setDefaultLatitude(std::optional<double> defaultLatitude);

    /**
     * if set, this is the longitude that should be
     * assigned to any notes that have no other longitude information.
     */
    [[nodiscard]] const std::optional<double> & defaultLongitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableDefaultLongitude();
    void setDefaultLongitude(std::optional<double> defaultLongitude);

    /**
     * if set, the user account is not yet confirmed for
     * login. I.e. the account has been created, but we are still waiting for
     * the user to complete the activation step.
     */
    [[nodiscard]] const std::optional<bool> & preactivation() const noexcept;
    [[nodiscard]] std::optional<bool> & mutablePreactivation();
    void setPreactivation(std::optional<bool> preactivation);

    /**
     * a list of promotions the user has seen.
     * This list may occasionally be modified by the system when promotions are
     * no longer available.<br/>
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QStringList> & viewedPromotions() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableViewedPromotions();
    void setViewedPromotions(std::optional<QStringList> viewedPromotions);

    /**
     * if set, this is the email address that the
     * user may send email to in order to add an email note directly into the
     * account via the SMTP email gateway. This is the part of the email
     * address before the '@' symbol ... our domain is not included.
     * If this is not set, the user may not add notes via the gateway.<br/>
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & incomingEmailAddress() const noexcept;
    void setIncomingEmailAddress(std::optional<QString> incomingEmailAddress);

    /**
     * if set, this will contain a list of email
     * addresses that have recently been used as recipients
     * of outbound emails by the user. This can be used to pre-populate a
     * list of possible destinations when a user wishes to send a note via
     * email.<br/>
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX each<br/>
     * Max: EDAM_USER_RECENT_MAILED_ADDRESSES_MAX entries
     */
    [[nodiscard]] const std::optional<QStringList> & recentMailedAddresses() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableRecentMailedAddresses();
    void setRecentMailedAddresses(std::optional<QStringList> recentMailedAddresses);

    /**
     * Free-form text field that may hold general support
     * information, etc.<br/>
     * Length: EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
     */
    [[nodiscard]] const std::optional<QString> & comments() const noexcept;
    void setComments(std::optional<QString> comments);

    /**
     * The date/time when the user agreed to
     * the terms of service. This can be used as the effective "start date"
     * for the account.
     */
    [[nodiscard]] const std::optional<Timestamp> & dateAgreedToTermsOfService() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableDateAgreedToTermsOfService();
    void setDateAgreedToTermsOfService(std::optional<Timestamp> dateAgreedToTermsOfService);

    /**
     * The number of referrals that the user is permitted
     * to make.
     */
    [[nodiscard]] const std::optional<qint32> & maxReferrals() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableMaxReferrals();
    void setMaxReferrals(std::optional<qint32> maxReferrals);

    /**
     * The number of referrals sent from this account.
     */
    [[nodiscard]] const std::optional<qint32> & referralCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableReferralCount();
    void setReferralCount(std::optional<qint32> referralCount);

    /**
     * A code indicating where the user was sent from. AKA
     * promotion code
     */
    [[nodiscard]] const std::optional<QString> & refererCode() const noexcept;
    void setRefererCode(std::optional<QString> refererCode);

    /**
     * The most recent date when the user sent outbound
     * emails from the service. Used with sentEmailCount to limit the number
     * of emails that can be sent per day.
     */
    [[nodiscard]] const std::optional<Timestamp> & sentEmailDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableSentEmailDate();
    void setSentEmailDate(std::optional<Timestamp> sentEmailDate);

    /**
     * The number of emails that were sent from the user
     * via the service on sentEmailDate. Used to enforce a limit on the number
     * of emails per user per day to prevent spamming.
     */
    [[nodiscard]] const std::optional<qint32> & sentEmailCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableSentEmailCount();
    void setSentEmailCount(std::optional<qint32> sentEmailCount);

    /**
     * If set, this is the maximum number of emails that
     * may be sent in a given day from this account. If unset, the server will
     * use the configured default limit.
     */
    [[nodiscard]] const std::optional<qint32> & dailyEmailLimit() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableDailyEmailLimit();
    void setDailyEmailLimit(std::optional<qint32> dailyEmailLimit);

    /**
     * If set, this is the date when the user asked
     * to be excluded from offers and promotions sent by Evernote. If not set,
     * then the user currently agrees to receive these messages.
     */
    [[nodiscard]] const std::optional<Timestamp> & emailOptOutDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableEmailOptOutDate();
    void setEmailOptOutDate(std::optional<Timestamp> emailOptOutDate);

    /**
     * If set, this is the date when the user asked
     * to be included in offers and promotions sent by Evernote's partners.
     * If not sent, then the user currently does not agree to receive these
     * emails.
     */
    [[nodiscard]] const std::optional<Timestamp> & partnerEmailOptInDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePartnerEmailOptInDate();
    void setPartnerEmailOptInDate(std::optional<Timestamp> partnerEmailOptInDate);

    /**
     * a 2 character language codes based on:
     * http://ftp.ics.uci.edu/pub/ietf/http/related/iso639.txt used for
     * localization purposes to determine what language to use for the web
     * interface and for other direct communication (e.g. emails).
     */
    [[nodiscard]] const std::optional<QString> & preferredLanguage() const noexcept;
    void setPreferredLanguage(std::optional<QString> preferredLanguage);

    /**
     * Preferred country code based on ISO 3166-1-alpha-2 indicating the
     * users preferred country
     */
    [[nodiscard]] const std::optional<QString> & preferredCountry() const noexcept;
    void setPreferredCountry(std::optional<QString> preferredCountry);

    /**
     * Boolean flag set to true if the user wants to clip full pages by
     * default when they use the web clipper without a selection.
     */
    [[nodiscard]] const std::optional<bool> & clipFullPage() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableClipFullPage();
    void setClipFullPage(std::optional<bool> clipFullPage);

    /**
     * The username of the account of someone who has chosen to enable
     * Twittering into Evernote. This value is subject to change, since users
     * may change their Twitter user name.
     */
    [[nodiscard]] const std::optional<QString> & twitterUserName() const noexcept;
    void setTwitterUserName(std::optional<QString> twitterUserName);

    /**
     * The unique identifier of the user's Twitter account if that user
     * has chosen to enable Twittering into Evernote.
     */
    [[nodiscard]] const std::optional<QString> & twitterId() const noexcept;
    void setTwitterId(std::optional<QString> twitterId);

    /**
     * A name identifier used to identify a particular set of branding and
     * light customization.
     */
    [[nodiscard]] const std::optional<QString> & groupName() const noexcept;
    void setGroupName(std::optional<QString> groupName);

    /**
     * a 2 character language codes based on:
     * http://ftp.ics.uci.edu/pub/ietf/http/related/iso639.txt
     * If set, this is used to determine the language that should be used
     * when processing images and PDF files to find text.
     * If not set, then the 'preferredLanguage' will be used.
     */
    [[nodiscard]] const std::optional<QString> & recognitionLanguage() const noexcept;
    void setRecognitionLanguage(std::optional<QString> recognitionLanguage);

    [[nodiscard]] const std::optional<QString> & referralProof() const noexcept;
    void setReferralProof(std::optional<QString> referralProof);

    [[nodiscard]] const std::optional<bool> & educationalDiscount() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEducationalDiscount();
    void setEducationalDiscount(std::optional<bool> educationalDiscount);

    /**
     * A string recording the business address of a Sponsored Account user who has requested invoicing.
     */
    [[nodiscard]] const std::optional<QString> & businessAddress() const noexcept;
    void setBusinessAddress(std::optional<QString> businessAddress);

    /**
     * A flag indicating whether to hide the billing information on a sponsored
     * account owner's settings page
     */
    [[nodiscard]] const std::optional<bool> & hideSponsorBilling() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableHideSponsorBilling();
    void setHideSponsorBilling(std::optional<bool> hideSponsorBilling);

    /**
     * A flag indicating whether the user chooses to allow Evernote to automatically
     * file and tag emailed notes
     */
    [[nodiscard]] const std::optional<bool> & useEmailAutoFiling() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableUseEmailAutoFiling();
    void setUseEmailAutoFiling(std::optional<bool> useEmailAutoFiling);

    /**
     * Configuration state for whether or not the user wishes to receive
     * reminder e-mail. This setting applies to both the reminder e-mail sent
     * for personal reminder notes and for the reminder e-mail sent for reminder
     * notes in the user's business notebooks that the user has configured for
     * e-mail notifications.
     */
    [[nodiscard]] const std::optional<ReminderEmailConfig> & reminderEmailConfig() const noexcept;
    [[nodiscard]] std::optional<ReminderEmailConfig> & mutableReminderEmailConfig();
    void setReminderEmailConfig(std::optional<ReminderEmailConfig> reminderEmailConfig);

    /**
     * If set, this contains the time at which the user last confirmed that the
     * configured email address for this account is correct and up-to-date. If this is
     * unset that indicates that the user's email address is unverified.
     */
    [[nodiscard]] const std::optional<Timestamp> & emailAddressLastConfirmed() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableEmailAddressLastConfirmed();
    void setEmailAddressLastConfirmed(std::optional<Timestamp> emailAddressLastConfirmed);

    /**
     * If set, this contains the time at which the user's password last changed. This
     * will be unset for users created before the addition of this field who have not
     * changed their passwords since the addition of this field.
     */
    [[nodiscard]] const std::optional<Timestamp> & passwordUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutablePasswordUpdated();
    void setPasswordUpdated(std::optional<Timestamp> passwordUpdated);

    [[nodiscard]] const std::optional<bool> & salesforcePushEnabled() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableSalesforcePushEnabled();
    void setSalesforcePushEnabled(std::optional<bool> salesforcePushEnabled);

    /**
     * If set to True, the server will record LogRequest send from clients of this
     * user as ClientEventLog.
     */
    [[nodiscard]] const std::optional<bool> & shouldLogClientEvent() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableShouldLogClientEvent();
    void setShouldLogClientEvent(std::optional<bool> shouldLogClientEvent);

    /**
     * If set to True, no Machine Learning nor human review will be done to this
     * user's note contents.
     */
    [[nodiscard]] const std::optional<bool> & optOutMachineLearning() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableOptOutMachineLearning();
    void setOptOutMachineLearning(std::optional<bool> optOutMachineLearning);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const UserAttributes & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserAttributes & other) const noexcept;

    Q_PROPERTY(std::optional<QString> defaultLocationName READ defaultLocationName WRITE setDefaultLocationName)
    Q_PROPERTY(std::optional<double> defaultLatitude READ defaultLatitude WRITE setDefaultLatitude)
    Q_PROPERTY(std::optional<double> defaultLongitude READ defaultLongitude WRITE setDefaultLongitude)
    Q_PROPERTY(std::optional<bool> preactivation READ preactivation WRITE setPreactivation)
    Q_PROPERTY(std::optional<QStringList> viewedPromotions READ viewedPromotions WRITE setViewedPromotions)
    Q_PROPERTY(std::optional<QString> incomingEmailAddress READ incomingEmailAddress WRITE setIncomingEmailAddress)
    Q_PROPERTY(std::optional<QStringList> recentMailedAddresses READ recentMailedAddresses WRITE setRecentMailedAddresses)
    Q_PROPERTY(std::optional<QString> comments READ comments WRITE setComments)
    Q_PROPERTY(std::optional<Timestamp> dateAgreedToTermsOfService READ dateAgreedToTermsOfService WRITE setDateAgreedToTermsOfService)
    Q_PROPERTY(std::optional<qint32> maxReferrals READ maxReferrals WRITE setMaxReferrals)
    Q_PROPERTY(std::optional<qint32> referralCount READ referralCount WRITE setReferralCount)
    Q_PROPERTY(std::optional<QString> refererCode READ refererCode WRITE setRefererCode)
    Q_PROPERTY(std::optional<Timestamp> sentEmailDate READ sentEmailDate WRITE setSentEmailDate)
    Q_PROPERTY(std::optional<qint32> sentEmailCount READ sentEmailCount WRITE setSentEmailCount)
    Q_PROPERTY(std::optional<qint32> dailyEmailLimit READ dailyEmailLimit WRITE setDailyEmailLimit)
    Q_PROPERTY(std::optional<Timestamp> emailOptOutDate READ emailOptOutDate WRITE setEmailOptOutDate)
    Q_PROPERTY(std::optional<Timestamp> partnerEmailOptInDate READ partnerEmailOptInDate WRITE setPartnerEmailOptInDate)
    Q_PROPERTY(std::optional<QString> preferredLanguage READ preferredLanguage WRITE setPreferredLanguage)
    Q_PROPERTY(std::optional<QString> preferredCountry READ preferredCountry WRITE setPreferredCountry)
    Q_PROPERTY(std::optional<bool> clipFullPage READ clipFullPage WRITE setClipFullPage)
    Q_PROPERTY(std::optional<QString> twitterUserName READ twitterUserName WRITE setTwitterUserName)
    Q_PROPERTY(std::optional<QString> twitterId READ twitterId WRITE setTwitterId)
    Q_PROPERTY(std::optional<QString> groupName READ groupName WRITE setGroupName)
    Q_PROPERTY(std::optional<QString> recognitionLanguage READ recognitionLanguage WRITE setRecognitionLanguage)
    Q_PROPERTY(std::optional<QString> referralProof READ referralProof WRITE setReferralProof)
    Q_PROPERTY(std::optional<bool> educationalDiscount READ educationalDiscount WRITE setEducationalDiscount)
    Q_PROPERTY(std::optional<QString> businessAddress READ businessAddress WRITE setBusinessAddress)
    Q_PROPERTY(std::optional<bool> hideSponsorBilling READ hideSponsorBilling WRITE setHideSponsorBilling)
    Q_PROPERTY(std::optional<bool> useEmailAutoFiling READ useEmailAutoFiling WRITE setUseEmailAutoFiling)
    Q_PROPERTY(std::optional<ReminderEmailConfig> reminderEmailConfig READ reminderEmailConfig WRITE setReminderEmailConfig)
    Q_PROPERTY(std::optional<Timestamp> emailAddressLastConfirmed READ emailAddressLastConfirmed WRITE setEmailAddressLastConfirmed)
    Q_PROPERTY(std::optional<Timestamp> passwordUpdated READ passwordUpdated WRITE setPasswordUpdated)
    Q_PROPERTY(std::optional<bool> salesforcePushEnabled READ salesforcePushEnabled WRITE setSalesforcePushEnabled)
    Q_PROPERTY(std::optional<bool> shouldLogClientEvent READ shouldLogClientEvent WRITE setShouldLogClientEvent)
    Q_PROPERTY(std::optional<bool> optOutMachineLearning READ optOutMachineLearning WRITE setOptOutMachineLearning)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::UserAttributes)

#endif // QEVERCLOUD_GENERATED_USERATTRIBUTES_H
