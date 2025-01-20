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

#include <qevercloud/serialization/json/UserUrls.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const UserUrls & value)
{
    QJsonObject object;

    if (value.noteStoreUrl()) {
        object[QStringLiteral("noteStoreUrl")] = *value.noteStoreUrl();
    }

    if (value.webApiUrlPrefix()) {
        object[QStringLiteral("webApiUrlPrefix")] = *value.webApiUrlPrefix();
    }

    if (value.userStoreUrl()) {
        object[QStringLiteral("userStoreUrl")] = *value.userStoreUrl();
    }

    if (value.utilityUrl()) {
        object[QStringLiteral("utilityUrl")] = *value.utilityUrl();
    }

    if (value.messageStoreUrl()) {
        object[QStringLiteral("messageStoreUrl")] = *value.messageStoreUrl();
    }

    if (value.userWebSocketUrl()) {
        object[QStringLiteral("userWebSocketUrl")] = *value.userWebSocketUrl();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, UserUrls & value)
{
    if (object.contains(QStringLiteral("noteStoreUrl"))) {
        const auto v = object[QStringLiteral("noteStoreUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteStoreUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("webApiUrlPrefix"))) {
        const auto v = object[QStringLiteral("webApiUrlPrefix")];
        if (v.isString()) {
            auto s = v.toString();
            value.setWebApiUrlPrefix(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userStoreUrl"))) {
        const auto v = object[QStringLiteral("userStoreUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUserStoreUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("utilityUrl"))) {
        const auto v = object[QStringLiteral("utilityUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUtilityUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("messageStoreUrl"))) {
        const auto v = object[QStringLiteral("messageStoreUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMessageStoreUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userWebSocketUrl"))) {
        const auto v = object[QStringLiteral("userWebSocketUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUserWebSocketUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
