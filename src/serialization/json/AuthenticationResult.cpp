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

#include <qevercloud/serialization/json/AuthenticationResult.h>

#include <qevercloud/serialization/json/PublicUserInfo.h>
#include <qevercloud/serialization/json/User.h>
#include <qevercloud/serialization/json/UserUrls.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const AuthenticationResult & value)
{
    QJsonObject object;

    object[QStringLiteral("currentTime")] = QString::number(value.currentTime());
    object[QStringLiteral("authenticationToken")] = value.authenticationToken();
    object[QStringLiteral("expiration")] = QString::number(value.expiration());
    if (value.user()) {
        object[QStringLiteral("user")] = serializeToJson(*value.user());
    }

    if (value.publicUserInfo()) {
        object[QStringLiteral("publicUserInfo")] = serializeToJson(*value.publicUserInfo());
    }

    if (value.noteStoreUrl()) {
        object[QStringLiteral("noteStoreUrl")] = *value.noteStoreUrl();
    }

    if (value.webApiUrlPrefix()) {
        object[QStringLiteral("webApiUrlPrefix")] = *value.webApiUrlPrefix();
    }

    if (value.secondFactorRequired()) {
        object[QStringLiteral("secondFactorRequired")] = *value.secondFactorRequired();
    }

    if (value.secondFactorDeliveryHint()) {
        object[QStringLiteral("secondFactorDeliveryHint")] = *value.secondFactorDeliveryHint();
    }

    if (value.urls()) {
        object[QStringLiteral("urls")] = serializeToJson(*value.urls());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, AuthenticationResult & value)
{
    if (object.contains(QStringLiteral("currentTime"))) {
        const auto v = object[QStringLiteral("currentTime")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setCurrentTime(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("authenticationToken"))) {
        const auto v = object[QStringLiteral("authenticationToken")];
        if (v.isString()) {
            auto s = v.toString();
            value.setAuthenticationToken(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("expiration"))) {
        const auto v = object[QStringLiteral("expiration")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setExpiration(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("user"))) {
        const auto v = object[QStringLiteral("user")];
        if (v.isObject()) {
            auto o = v.toObject();
            User f;
            if (deserializeFromJson(o, f)) {
                value.setUser(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("publicUserInfo"))) {
        const auto v = object[QStringLiteral("publicUserInfo")];
        if (v.isObject()) {
            auto o = v.toObject();
            PublicUserInfo f;
            if (deserializeFromJson(o, f)) {
                value.setPublicUserInfo(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("secondFactorRequired"))) {
        const auto v = object[QStringLiteral("secondFactorRequired")];
        if (v.isBool()) {
            value.setSecondFactorRequired(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("secondFactorDeliveryHint"))) {
        const auto v = object[QStringLiteral("secondFactorDeliveryHint")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSecondFactorDeliveryHint(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("urls"))) {
        const auto v = object[QStringLiteral("urls")];
        if (v.isObject()) {
            auto o = v.toObject();
            UserUrls f;
            if (deserializeFromJson(o, f)) {
                value.setUrls(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
