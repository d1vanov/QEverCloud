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

#include <qevercloud/serialization/json/Data.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const Data & value)
{
    QJsonObject object;

    if (value.bodyHash()) {
        object[QStringLiteral("bodyHash")] = QString::fromUtf8(value.bodyHash()->toBase64());
    }

    if (value.size()) {
        object[QStringLiteral("size")] = *value.size();
    }

    if (value.body()) {
        object[QStringLiteral("body")] = QString::fromUtf8(value.body()->toBase64());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Data & value)
{
    if (object.contains(QStringLiteral("bodyHash"))) {
        const auto v = object[QStringLiteral("bodyHash")];
        if (v.isString()) {
            auto s = v.toString();
            value.setBodyHash(QByteArray::fromBase64(s.toUtf8()));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("size"))) {
        const auto v = object[QStringLiteral("size")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setSize(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("body"))) {
        const auto v = object[QStringLiteral("body")];
        if (v.isString()) {
            auto s = v.toString();
            value.setBody(QByteArray::fromBase64(s.toUtf8()));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
