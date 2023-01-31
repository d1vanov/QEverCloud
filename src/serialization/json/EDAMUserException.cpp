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

#include <qevercloud/serialization/json/EDAMUserException.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<EDAMErrorCode> safeCastEDAMErrorCodeToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(EDAMErrorCode::UNKNOWN):
        return EDAMErrorCode::UNKNOWN;
    case static_cast<qint64>(EDAMErrorCode::BAD_DATA_FORMAT):
        return EDAMErrorCode::BAD_DATA_FORMAT;
    case static_cast<qint64>(EDAMErrorCode::PERMISSION_DENIED):
        return EDAMErrorCode::PERMISSION_DENIED;
    case static_cast<qint64>(EDAMErrorCode::INTERNAL_ERROR):
        return EDAMErrorCode::INTERNAL_ERROR;
    case static_cast<qint64>(EDAMErrorCode::DATA_REQUIRED):
        return EDAMErrorCode::DATA_REQUIRED;
    case static_cast<qint64>(EDAMErrorCode::LIMIT_REACHED):
        return EDAMErrorCode::LIMIT_REACHED;
    case static_cast<qint64>(EDAMErrorCode::QUOTA_REACHED):
        return EDAMErrorCode::QUOTA_REACHED;
    case static_cast<qint64>(EDAMErrorCode::INVALID_AUTH):
        return EDAMErrorCode::INVALID_AUTH;
    case static_cast<qint64>(EDAMErrorCode::AUTH_EXPIRED):
        return EDAMErrorCode::AUTH_EXPIRED;
    case static_cast<qint64>(EDAMErrorCode::DATA_CONFLICT):
        return EDAMErrorCode::DATA_CONFLICT;
    case static_cast<qint64>(EDAMErrorCode::ENML_VALIDATION):
        return EDAMErrorCode::ENML_VALIDATION;
    case static_cast<qint64>(EDAMErrorCode::SHARD_UNAVAILABLE):
        return EDAMErrorCode::SHARD_UNAVAILABLE;
    case static_cast<qint64>(EDAMErrorCode::LEN_TOO_SHORT):
        return EDAMErrorCode::LEN_TOO_SHORT;
    case static_cast<qint64>(EDAMErrorCode::LEN_TOO_LONG):
        return EDAMErrorCode::LEN_TOO_LONG;
    case static_cast<qint64>(EDAMErrorCode::TOO_FEW):
        return EDAMErrorCode::TOO_FEW;
    case static_cast<qint64>(EDAMErrorCode::TOO_MANY):
        return EDAMErrorCode::TOO_MANY;
    case static_cast<qint64>(EDAMErrorCode::UNSUPPORTED_OPERATION):
        return EDAMErrorCode::UNSUPPORTED_OPERATION;
    case static_cast<qint64>(EDAMErrorCode::TAKEN_DOWN):
        return EDAMErrorCode::TAKEN_DOWN;
    case static_cast<qint64>(EDAMErrorCode::RATE_LIMIT_REACHED):
        return EDAMErrorCode::RATE_LIMIT_REACHED;
    case static_cast<qint64>(EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED):
        return EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    case static_cast<qint64>(EDAMErrorCode::DEVICE_LIMIT_REACHED):
        return EDAMErrorCode::DEVICE_LIMIT_REACHED;
    case static_cast<qint64>(EDAMErrorCode::OPENID_ALREADY_TAKEN):
        return EDAMErrorCode::OPENID_ALREADY_TAKEN;
    case static_cast<qint64>(EDAMErrorCode::INVALID_OPENID_TOKEN):
        return EDAMErrorCode::INVALID_OPENID_TOKEN;
    case static_cast<qint64>(EDAMErrorCode::USER_NOT_ASSOCIATED):
        return EDAMErrorCode::USER_NOT_ASSOCIATED;
    case static_cast<qint64>(EDAMErrorCode::USER_NOT_REGISTERED):
        return EDAMErrorCode::USER_NOT_REGISTERED;
    case static_cast<qint64>(EDAMErrorCode::USER_ALREADY_ASSOCIATED):
        return EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    case static_cast<qint64>(EDAMErrorCode::ACCOUNT_CLEAR):
        return EDAMErrorCode::ACCOUNT_CLEAR;
    case static_cast<qint64>(EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED):
        return EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const EDAMUserException & value)
{
    QJsonObject object;

    object[QStringLiteral("errorCode")] = QString::number(static_cast<qint64>(value.errorCode()));
    if (value.parameter()) {
        object[QStringLiteral("parameter")] = *value.parameter();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, EDAMUserException & value)
{
    if (object.contains(QStringLiteral("errorCode"))) {
        const auto v = object[QStringLiteral("errorCode")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastEDAMErrorCodeToEnum(i);
            if (e) {
                value.setErrorCode(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("parameter"))) {
        const auto v = object[QStringLiteral("parameter")];
        if (v.isString()) {
            auto s = v.toString();
            value.setParameter(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
