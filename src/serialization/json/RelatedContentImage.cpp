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

#include <qevercloud/serialization/json/RelatedContentImage.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const RelatedContentImage & value)
{
    QJsonObject object;

    if (value.url()) {
        object[QStringLiteral("url")] = *value.url();
    }

    if (value.width()) {
        object[QStringLiteral("width")] = *value.width();
    }

    if (value.height()) {
        object[QStringLiteral("height")] = *value.height();
    }

    if (value.pixelRatio()) {
        object[QStringLiteral("pixelRatio")] = *value.pixelRatio();
    }

    if (value.fileSize()) {
        object[QStringLiteral("fileSize")] = *value.fileSize();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, RelatedContentImage & value)
{
    if (object.contains(QStringLiteral("url"))) {
        const auto v = object[QStringLiteral("url")];
        if (v.isString()) {
            auto s = v.toString();
            value.setUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("width"))) {
        const auto v = object[QStringLiteral("width")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setWidth(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("height"))) {
        const auto v = object[QStringLiteral("height")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setHeight(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("pixelRatio"))) {
        const auto v = object[QStringLiteral("pixelRatio")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            value.setPixelRatio(d);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("fileSize"))) {
        const auto v = object[QStringLiteral("fileSize")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setFileSize(static_cast<qint32>(d));
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
