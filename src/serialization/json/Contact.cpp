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

#include <qevercloud/serialization/json/Contact.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<ContactType> safeCastContactTypeToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(ContactType::EVERNOTE):
        return ContactType::EVERNOTE;
    case static_cast<qint64>(ContactType::SMS):
        return ContactType::SMS;
    case static_cast<qint64>(ContactType::FACEBOOK):
        return ContactType::FACEBOOK;
    case static_cast<qint64>(ContactType::EMAIL):
        return ContactType::EMAIL;
    case static_cast<qint64>(ContactType::TWITTER):
        return ContactType::TWITTER;
    case static_cast<qint64>(ContactType::LINKEDIN):
        return ContactType::LINKEDIN;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const Contact & value)
{
    QJsonObject object;

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.id()) {
        object[QStringLiteral("id")] = *value.id();
    }

    if (value.type()) {
        object[QStringLiteral("type")] = QString::number(static_cast<qint64>(*value.type()));
    }

    if (value.photoUrl()) {
        object[QStringLiteral("photoUrl")] = *value.photoUrl();
    }

    if (value.photoLastUpdated()) {
        object[QStringLiteral("photoLastUpdated")] = QString::number(*value.photoLastUpdated());
    }

    if (value.messagingPermit()) {
        object[QStringLiteral("messagingPermit")] = QString::fromUtf8(value.messagingPermit()->toBase64());
    }

    if (value.messagingPermitExpires()) {
        object[QStringLiteral("messagingPermitExpires")] = QString::number(*value.messagingPermitExpires());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Contact & value)
{
    if (object.contains(QStringLiteral("name"))) {
        const auto v = object[QStringLiteral("name")];
        if (v.isString()) {
            auto s = v.toString();
            value.setName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("id"))) {
        const auto v = object[QStringLiteral("id")];
        if (v.isString()) {
            auto s = v.toString();
            value.setId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("type"))) {
        const auto v = object[QStringLiteral("type")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastContactTypeToEnum(i);
            if (e) {
                value.setType(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("photoUrl"))) {
        const auto v = object[QStringLiteral("photoUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPhotoUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("photoLastUpdated"))) {
        const auto v = object[QStringLiteral("photoLastUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setPhotoLastUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("messagingPermit"))) {
        const auto v = object[QStringLiteral("messagingPermit")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMessagingPermit(QByteArray::fromBase64(s.toUtf8()));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("messagingPermitExpires"))) {
        const auto v = object[QStringLiteral("messagingPermitExpires")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setMessagingPermitExpires(i);
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
