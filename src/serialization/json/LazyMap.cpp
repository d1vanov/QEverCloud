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

#include <qevercloud/serialization/json/LazyMap.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const LazyMap & value)
{
    QJsonObject object;

    if (value.keysOnly())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.keysOnly()))
        {
            array << v;
        }

        object[QStringLiteral("keysOnly")] = array;
    }

    if (value.fullMap())
    {
        QJsonObject subobject;
        for (auto it: toRange(std::as_const(*value.fullMap())))
        {
            subobject[it.key()] = it.value();
        }
        object[QStringLiteral("fullMap")] = subobject;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, LazyMap & value)
{
    if (object.contains(QStringLiteral("keysOnly"))) {
        const auto v = object[QStringLiteral("keysOnly")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QSet<QString> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.insert(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setKeysOnly(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("fullMap"))) {
        auto v = object[QStringLiteral("fullMap")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QMap<QString, QString> map;
            for (auto it: toRange(std::as_const(o))) {
                if (it.value().isString()) {
                    auto s = it.value().toString();
                    map[it.key()] = std::move(s);
                }
                else {
                    return false;
                }
            }
            value.setFullMap(std::move(map));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
