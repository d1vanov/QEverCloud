/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/serialization/json/UserAttributes.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<ReminderEmailConfig> safeCastReminderEmailConfigToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(ReminderEmailConfig::DO_NOT_SEND):
        return ReminderEmailConfig::DO_NOT_SEND;
    case static_cast<qint64>(ReminderEmailConfig::SEND_DAILY_EMAIL):
        return ReminderEmailConfig::SEND_DAILY_EMAIL;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const UserAttributes & value)
{
    QJsonObject object;

    if (value.defaultLocationName()) {
        object[QStringLiteral("defaultLocationName")] = *value.defaultLocationName();
    }

    if (value.defaultLatitude()) {
        object[QStringLiteral("defaultLatitude")] = *value.defaultLatitude();
    }

    if (value.defaultLongitude()) {
        object[QStringLiteral("defaultLongitude")] = *value.defaultLongitude();
    }

    if (value.preactivation()) {
        object[QStringLiteral("preactivation")] = *value.preactivation();
    }

    if (value.viewedPromotions())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.viewedPromotions()))
        {
            array << v;
        }

        object[QStringLiteral("viewedPromotions")] = array;
    }

    if (value.incomingEmailAddress()) {
        object[QStringLiteral("incomingEmailAddress")] = *value.incomingEmailAddress();
    }

    if (value.recentMailedAddresses())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.recentMailedAddresses()))
        {
            array << v;
        }

        object[QStringLiteral("recentMailedAddresses")] = array;
    }

    if (value.comments()) {
        object[QStringLiteral("comments")] = *value.comments();
    }

    if (value.dateAgreedToTermsOfService()) {
        object[QStringLiteral("dateAgreedToTermsOfService")] = QString::number(*value.dateAgreedToTermsOfService());
    }

    if (value.maxReferrals()) {
        object[QStringLiteral("maxReferrals")] = *value.maxReferrals();
    }

    if (value.referralCount()) {
        object[QStringLiteral("referralCount")] = *value.referralCount();
    }

    if (value.refererCode()) {
        object[QStringLiteral("refererCode")] = *value.refererCode();
    }

    if (value.sentEmailDate()) {
        object[QStringLiteral("sentEmailDate")] = QString::number(*value.sentEmailDate());
    }

    if (value.sentEmailCount()) {
        object[QStringLiteral("sentEmailCount")] = *value.sentEmailCount();
    }

    if (value.dailyEmailLimit()) {
        object[QStringLiteral("dailyEmailLimit")] = *value.dailyEmailLimit();
    }

    if (value.emailOptOutDate()) {
        object[QStringLiteral("emailOptOutDate")] = QString::number(*value.emailOptOutDate());
    }

    if (value.partnerEmailOptInDate()) {
        object[QStringLiteral("partnerEmailOptInDate")] = QString::number(*value.partnerEmailOptInDate());
    }

    if (value.preferredLanguage()) {
        object[QStringLiteral("preferredLanguage")] = *value.preferredLanguage();
    }

    if (value.preferredCountry()) {
        object[QStringLiteral("preferredCountry")] = *value.preferredCountry();
    }

    if (value.clipFullPage()) {
        object[QStringLiteral("clipFullPage")] = *value.clipFullPage();
    }

    if (value.twitterUserName()) {
        object[QStringLiteral("twitterUserName")] = *value.twitterUserName();
    }

    if (value.twitterId()) {
        object[QStringLiteral("twitterId")] = *value.twitterId();
    }

    if (value.groupName()) {
        object[QStringLiteral("groupName")] = *value.groupName();
    }

    if (value.recognitionLanguage()) {
        object[QStringLiteral("recognitionLanguage")] = *value.recognitionLanguage();
    }

    if (value.referralProof()) {
        object[QStringLiteral("referralProof")] = *value.referralProof();
    }

    if (value.educationalDiscount()) {
        object[QStringLiteral("educationalDiscount")] = *value.educationalDiscount();
    }

    if (value.businessAddress()) {
        object[QStringLiteral("businessAddress")] = *value.businessAddress();
    }

    if (value.hideSponsorBilling()) {
        object[QStringLiteral("hideSponsorBilling")] = *value.hideSponsorBilling();
    }

    if (value.useEmailAutoFiling()) {
        object[QStringLiteral("useEmailAutoFiling")] = *value.useEmailAutoFiling();
    }

    if (value.reminderEmailConfig()) {
        object[QStringLiteral("reminderEmailConfig")] = QString::number(static_cast<qint64>(*value.reminderEmailConfig()));
    }

    if (value.emailAddressLastConfirmed()) {
        object[QStringLiteral("emailAddressLastConfirmed")] = QString::number(*value.emailAddressLastConfirmed());
    }

    if (value.passwordUpdated()) {
        object[QStringLiteral("passwordUpdated")] = QString::number(*value.passwordUpdated());
    }

    if (value.salesforcePushEnabled()) {
        object[QStringLiteral("salesforcePushEnabled")] = *value.salesforcePushEnabled();
    }

    if (value.shouldLogClientEvent()) {
        object[QStringLiteral("shouldLogClientEvent")] = *value.shouldLogClientEvent();
    }

    if (value.optOutMachineLearning()) {
        object[QStringLiteral("optOutMachineLearning")] = *value.optOutMachineLearning();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, UserAttributes & value)
{
    if (object.contains(QStringLiteral("defaultLocationName"))) {
        const auto v = object[QStringLiteral("defaultLocationName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setDefaultLocationName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("defaultLatitude"))) {
        const auto v = object[QStringLiteral("defaultLatitude")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setDefaultLatitude(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("defaultLongitude"))) {
        const auto v = object[QStringLiteral("defaultLongitude")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setDefaultLongitude(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("preactivation"))) {
        const auto v = object[QStringLiteral("preactivation")];
        if (v.isBool()) {
            value.setPreactivation(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("viewedPromotions"))) {
        const auto v = object[QStringLiteral("viewedPromotions")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setViewedPromotions(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("incomingEmailAddress"))) {
        const auto v = object[QStringLiteral("incomingEmailAddress")];
        if (v.isString()) {
            auto s = v.toString();
            value.setIncomingEmailAddress(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recentMailedAddresses"))) {
        const auto v = object[QStringLiteral("recentMailedAddresses")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setRecentMailedAddresses(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("comments"))) {
        const auto v = object[QStringLiteral("comments")];
        if (v.isString()) {
            auto s = v.toString();
            value.setComments(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("dateAgreedToTermsOfService"))) {
        const auto v = object[QStringLiteral("dateAgreedToTermsOfService")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setDateAgreedToTermsOfService(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("maxReferrals"))) {
        const auto v = object[QStringLiteral("maxReferrals")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxReferrals(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("referralCount"))) {
        const auto v = object[QStringLiteral("referralCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setReferralCount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("refererCode"))) {
        const auto v = object[QStringLiteral("refererCode")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRefererCode(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sentEmailDate"))) {
        const auto v = object[QStringLiteral("sentEmailDate")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setSentEmailDate(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sentEmailCount"))) {
        const auto v = object[QStringLiteral("sentEmailCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setSentEmailCount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("dailyEmailLimit"))) {
        const auto v = object[QStringLiteral("dailyEmailLimit")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setDailyEmailLimit(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("emailOptOutDate"))) {
        const auto v = object[QStringLiteral("emailOptOutDate")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setEmailOptOutDate(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("partnerEmailOptInDate"))) {
        const auto v = object[QStringLiteral("partnerEmailOptInDate")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setPartnerEmailOptInDate(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("preferredLanguage"))) {
        const auto v = object[QStringLiteral("preferredLanguage")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPreferredLanguage(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("preferredCountry"))) {
        const auto v = object[QStringLiteral("preferredCountry")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPreferredCountry(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("clipFullPage"))) {
        const auto v = object[QStringLiteral("clipFullPage")];
        if (v.isBool()) {
            value.setClipFullPage(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("twitterUserName"))) {
        const auto v = object[QStringLiteral("twitterUserName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTwitterUserName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("twitterId"))) {
        const auto v = object[QStringLiteral("twitterId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTwitterId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("groupName"))) {
        const auto v = object[QStringLiteral("groupName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setGroupName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recognitionLanguage"))) {
        const auto v = object[QStringLiteral("recognitionLanguage")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRecognitionLanguage(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("referralProof"))) {
        const auto v = object[QStringLiteral("referralProof")];
        if (v.isString()) {
            auto s = v.toString();
            value.setReferralProof(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("educationalDiscount"))) {
        const auto v = object[QStringLiteral("educationalDiscount")];
        if (v.isBool()) {
            value.setEducationalDiscount(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessAddress"))) {
        const auto v = object[QStringLiteral("businessAddress")];
        if (v.isString()) {
            auto s = v.toString();
            value.setBusinessAddress(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("hideSponsorBilling"))) {
        const auto v = object[QStringLiteral("hideSponsorBilling")];
        if (v.isBool()) {
            value.setHideSponsorBilling(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("useEmailAutoFiling"))) {
        const auto v = object[QStringLiteral("useEmailAutoFiling")];
        if (v.isBool()) {
            value.setUseEmailAutoFiling(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("reminderEmailConfig"))) {
        const auto v = object[QStringLiteral("reminderEmailConfig")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastReminderEmailConfigToEnum(i);
            if (e) {
                value.setReminderEmailConfig(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("emailAddressLastConfirmed"))) {
        const auto v = object[QStringLiteral("emailAddressLastConfirmed")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setEmailAddressLastConfirmed(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("passwordUpdated"))) {
        const auto v = object[QStringLiteral("passwordUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setPasswordUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("salesforcePushEnabled"))) {
        const auto v = object[QStringLiteral("salesforcePushEnabled")];
        if (v.isBool()) {
            value.setSalesforcePushEnabled(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("shouldLogClientEvent"))) {
        const auto v = object[QStringLiteral("shouldLogClientEvent")];
        if (v.isBool()) {
            value.setShouldLogClientEvent(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("optOutMachineLearning"))) {
        const auto v = object[QStringLiteral("optOutMachineLearning")];
        if (v.isBool()) {
            value.setOptOutMachineLearning(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
