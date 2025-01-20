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

#include <qevercloud/serialization/json/EDAMInvalidContactsException.h>

#include <qevercloud/serialization/json/Contact.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<EDAMInvalidContactReason> safeCastEDAMInvalidContactReasonToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(EDAMInvalidContactReason::BAD_ADDRESS):
        return EDAMInvalidContactReason::BAD_ADDRESS;
    case static_cast<qint64>(EDAMInvalidContactReason::DUPLICATE_CONTACT):
        return EDAMInvalidContactReason::DUPLICATE_CONTACT;
    case static_cast<qint64>(EDAMInvalidContactReason::NO_CONNECTION):
        return EDAMInvalidContactReason::NO_CONNECTION;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const EDAMInvalidContactsException & value)
{
    QJsonObject object;

    {
        QJsonArray array;
        for (const auto & v: std::as_const(value.contacts()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("contacts")] = array;
    }

    if (value.parameter()) {
        object[QStringLiteral("parameter")] = *value.parameter();
    }

    if (value.reasons())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.reasons()))
        {
            array << QString::number(static_cast<qint64>(v));
        }

        object[QStringLiteral("reasons")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, EDAMInvalidContactsException & value)
{
    if (object.contains(QStringLiteral("contacts"))) {
        const auto v = object[QStringLiteral("contacts")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Contact> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Contact f;
                    if (deserializeFromJson(o, f)) {
                        values.push_back(std::move(f));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setContacts(std::move(values));
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

    if (object.contains(QStringLiteral("reasons"))) {
        const auto v = object[QStringLiteral("reasons")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<EDAMInvalidContactReason> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    const auto s = item.toString();
                    bool conversionResult = false;
                    qint64 i = s.toLongLong(&conversionResult);
                    if (!conversionResult) {
                        return false;
                    }

                    const auto e = safeCastEDAMInvalidContactReasonToEnum(i);
                    if (e) {
                        values.push_back(*e);
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setReasons(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
