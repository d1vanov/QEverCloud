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

#include <qevercloud/serialization/json/BootstrapProfile.h>

#include <qevercloud/serialization/json/BootstrapSettings.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const BootstrapProfile & value)
{
    QJsonObject object;

    object[QStringLiteral("name")] = value.name();
    object[QStringLiteral("settings")] = serializeToJson(value.settings());
    return object;
}

bool deserializeFromJson(const QJsonObject & object, BootstrapProfile & value)
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

    if (object.contains(QStringLiteral("settings"))) {
        const auto v = object[QStringLiteral("settings")];
        if (v.isObject()) {
            auto o = v.toObject();
            BootstrapSettings f;
            if (deserializeFromJson(o, f)) {
                value.setSettings(std::move(f));
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
