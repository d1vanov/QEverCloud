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

#include <qevercloud/serialization/json/BootstrapInfo.h>

#include <qevercloud/serialization/json/BootstrapProfile.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const BootstrapInfo & value)
{
    QJsonObject object;

    {
        QJsonArray array;
        for (const auto & v: std::as_const(value.profiles()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("profiles")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BootstrapInfo & value)
{
    if (object.contains(QStringLiteral("profiles"))) {
        const auto v = object[QStringLiteral("profiles")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<BootstrapProfile> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    BootstrapProfile f;
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
            value.setProfiles(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
