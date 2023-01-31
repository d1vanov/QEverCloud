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

#include <qevercloud/serialization/json/EDAMNotFoundException.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const EDAMNotFoundException & value)
{
    QJsonObject object;

    if (value.identifier()) {
        object[QStringLiteral("identifier")] = *value.identifier();
    }

    if (value.key()) {
        object[QStringLiteral("key")] = *value.key();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, EDAMNotFoundException & value)
{
    if (object.contains(QStringLiteral("identifier"))) {
        const auto v = object[QStringLiteral("identifier")];
        if (v.isString()) {
            auto s = v.toString();
            value.setIdentifier(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("key"))) {
        const auto v = object[QStringLiteral("key")];
        if (v.isString()) {
            auto s = v.toString();
            value.setKey(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
