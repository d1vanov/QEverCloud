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

#include <qevercloud/serialization/json/BootstrapSettings.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const BootstrapSettings & value)
{
    QJsonObject object;

    object[QStringLiteral("serviceHost")] = value.serviceHost();
    object[QStringLiteral("marketingUrl")] = value.marketingUrl();
    object[QStringLiteral("supportUrl")] = value.supportUrl();
    object[QStringLiteral("accountEmailDomain")] = value.accountEmailDomain();
    if (value.enableFacebookSharing()) {
        object[QStringLiteral("enableFacebookSharing")] = *value.enableFacebookSharing();
    }

    if (value.enableGiftSubscriptions()) {
        object[QStringLiteral("enableGiftSubscriptions")] = *value.enableGiftSubscriptions();
    }

    if (value.enableSupportTickets()) {
        object[QStringLiteral("enableSupportTickets")] = *value.enableSupportTickets();
    }

    if (value.enableSharedNotebooks()) {
        object[QStringLiteral("enableSharedNotebooks")] = *value.enableSharedNotebooks();
    }

    if (value.enableSingleNoteSharing()) {
        object[QStringLiteral("enableSingleNoteSharing")] = *value.enableSingleNoteSharing();
    }

    if (value.enableSponsoredAccounts()) {
        object[QStringLiteral("enableSponsoredAccounts")] = *value.enableSponsoredAccounts();
    }

    if (value.enableTwitterSharing()) {
        object[QStringLiteral("enableTwitterSharing")] = *value.enableTwitterSharing();
    }

    if (value.enableLinkedInSharing()) {
        object[QStringLiteral("enableLinkedInSharing")] = *value.enableLinkedInSharing();
    }

    if (value.enablePublicNotebooks()) {
        object[QStringLiteral("enablePublicNotebooks")] = *value.enablePublicNotebooks();
    }

    if (value.enableGoogle()) {
        object[QStringLiteral("enableGoogle")] = *value.enableGoogle();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BootstrapSettings & value)
{
    if (object.contains(QStringLiteral("serviceHost"))) {
        const auto v = object[QStringLiteral("serviceHost")];
        if (v.isString()) {
            auto s = v.toString();
            value.setServiceHost(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("marketingUrl"))) {
        const auto v = object[QStringLiteral("marketingUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMarketingUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("supportUrl"))) {
        const auto v = object[QStringLiteral("supportUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSupportUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("accountEmailDomain"))) {
        const auto v = object[QStringLiteral("accountEmailDomain")];
        if (v.isString()) {
            auto s = v.toString();
            value.setAccountEmailDomain(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableFacebookSharing"))) {
        const auto v = object[QStringLiteral("enableFacebookSharing")];
        if (v.isBool()) {
            value.setEnableFacebookSharing(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableGiftSubscriptions"))) {
        const auto v = object[QStringLiteral("enableGiftSubscriptions")];
        if (v.isBool()) {
            value.setEnableGiftSubscriptions(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableSupportTickets"))) {
        const auto v = object[QStringLiteral("enableSupportTickets")];
        if (v.isBool()) {
            value.setEnableSupportTickets(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableSharedNotebooks"))) {
        const auto v = object[QStringLiteral("enableSharedNotebooks")];
        if (v.isBool()) {
            value.setEnableSharedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableSingleNoteSharing"))) {
        const auto v = object[QStringLiteral("enableSingleNoteSharing")];
        if (v.isBool()) {
            value.setEnableSingleNoteSharing(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableSponsoredAccounts"))) {
        const auto v = object[QStringLiteral("enableSponsoredAccounts")];
        if (v.isBool()) {
            value.setEnableSponsoredAccounts(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableTwitterSharing"))) {
        const auto v = object[QStringLiteral("enableTwitterSharing")];
        if (v.isBool()) {
            value.setEnableTwitterSharing(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableLinkedInSharing"))) {
        const auto v = object[QStringLiteral("enableLinkedInSharing")];
        if (v.isBool()) {
            value.setEnableLinkedInSharing(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enablePublicNotebooks"))) {
        const auto v = object[QStringLiteral("enablePublicNotebooks")];
        if (v.isBool()) {
            value.setEnablePublicNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("enableGoogle"))) {
        const auto v = object[QStringLiteral("enableGoogle")];
        if (v.isBool()) {
            value.setEnableGoogle(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
