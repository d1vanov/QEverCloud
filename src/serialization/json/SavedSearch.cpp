/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/serialization/json/SavedSearch.h>

#include <qevercloud/serialization/json/SavedSearchScope.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<QueryFormat> safeCastQueryFormatToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(QueryFormat::USER):
        return QueryFormat::USER;
    case static_cast<qint64>(QueryFormat::SEXP):
        return QueryFormat::SEXP;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const SavedSearch & value)
{
    QJsonObject object;

    object[QStringLiteral("localId")] = value.localId();
    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.query()) {
        object[QStringLiteral("query")] = *value.query();
    }

    if (value.format()) {
        object[QStringLiteral("format")] = QString::number(static_cast<qint64>(*value.format()));
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.scope()) {
        object[QStringLiteral("scope")] = serializeToJson(*value.scope());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SavedSearch & value)
{
    if (object.contains(QStringLiteral("localId"))) {
        const auto v = object[QStringLiteral("localId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLocalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyModified"))) {
        const auto v = object[QStringLiteral("isLocallyModified")];
        if (v.isBool()) {
            value.setLocallyModified(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocalOnly"))) {
        const auto v = object[QStringLiteral("isLocalOnly")];
        if (v.isBool()) {
            value.setLocalOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyFavorited"))) {
        const auto v = object[QStringLiteral("isLocallyFavorited")];
        if (v.isBool()) {
            value.setLocallyFavorited(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("localData"))) {
        auto v = object[QStringLiteral("localData")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QHash<QString, QVariant> map;
            for (auto it: toRange(qAsConst(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("guid"))) {
        const auto v = object[QStringLiteral("guid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setGuid(std::move(s));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("query"))) {
        const auto v = object[QStringLiteral("query")];
        if (v.isString()) {
            auto s = v.toString();
            value.setQuery(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("format"))) {
        const auto v = object[QStringLiteral("format")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastQueryFormatToEnum(i);
            if (e) {
                value.setFormat(*e);
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updateSequenceNum"))) {
        const auto v = object[QStringLiteral("updateSequenceNum")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUpdateSequenceNum(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("scope"))) {
        const auto v = object[QStringLiteral("scope")];
        if (v.isObject()) {
            auto o = v.toObject();
            SavedSearchScope f;
            if (deserializeFromJson(o, f)) {
                value.setScope(std::move(f));
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
