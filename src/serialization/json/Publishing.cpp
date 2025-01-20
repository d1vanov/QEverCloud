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

#include <qevercloud/serialization/json/Publishing.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<NoteSortOrder> safeCastNoteSortOrderToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(NoteSortOrder::CREATED):
        return NoteSortOrder::CREATED;
    case static_cast<qint64>(NoteSortOrder::UPDATED):
        return NoteSortOrder::UPDATED;
    case static_cast<qint64>(NoteSortOrder::RELEVANCE):
        return NoteSortOrder::RELEVANCE;
    case static_cast<qint64>(NoteSortOrder::UPDATE_SEQUENCE_NUMBER):
        return NoteSortOrder::UPDATE_SEQUENCE_NUMBER;
    case static_cast<qint64>(NoteSortOrder::TITLE):
        return NoteSortOrder::TITLE;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const Publishing & value)
{
    QJsonObject object;

    if (value.uri()) {
        object[QStringLiteral("uri")] = *value.uri();
    }

    if (value.order()) {
        object[QStringLiteral("order")] = QString::number(static_cast<qint64>(*value.order()));
    }

    if (value.ascending()) {
        object[QStringLiteral("ascending")] = *value.ascending();
    }

    if (value.publicDescription()) {
        object[QStringLiteral("publicDescription")] = *value.publicDescription();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Publishing & value)
{
    if (object.contains(QStringLiteral("uri"))) {
        const auto v = object[QStringLiteral("uri")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUri(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("order"))) {
        const auto v = object[QStringLiteral("order")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastNoteSortOrderToEnum(i);
            if (e) {
                value.setOrder(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("ascending"))) {
        const auto v = object[QStringLiteral("ascending")];
        if (v.isBool()) {
            value.setAscending(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("publicDescription"))) {
        const auto v = object[QStringLiteral("publicDescription")];
        if (v.isString()) {
            auto s = v.toString();
            value.setPublicDescription(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
