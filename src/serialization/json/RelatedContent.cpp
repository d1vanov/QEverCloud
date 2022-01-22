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

#include <qevercloud/serialization/json/RelatedContent.h>

#include <qevercloud/serialization/json/Contact.h>
#include <qevercloud/serialization/json/RelatedContentImage.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<RelatedContentType> safeCastRelatedContentTypeToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(RelatedContentType::NEWS_ARTICLE):
        return RelatedContentType::NEWS_ARTICLE;
    case static_cast<qint64>(RelatedContentType::PROFILE_PERSON):
        return RelatedContentType::PROFILE_PERSON;
    case static_cast<qint64>(RelatedContentType::PROFILE_ORGANIZATION):
        return RelatedContentType::PROFILE_ORGANIZATION;
    case static_cast<qint64>(RelatedContentType::REFERENCE_MATERIAL):
        return RelatedContentType::REFERENCE_MATERIAL;
    default:
        return std::nullopt;
    }
}

[[nodiscard]] std::optional<RelatedContentAccess> safeCastRelatedContentAccessToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(RelatedContentAccess::NOT_ACCESSIBLE):
        return RelatedContentAccess::NOT_ACCESSIBLE;
    case static_cast<qint64>(RelatedContentAccess::DIRECT_LINK_ACCESS_OK):
        return RelatedContentAccess::DIRECT_LINK_ACCESS_OK;
    case static_cast<qint64>(RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED):
        return RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED;
    case static_cast<qint64>(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW):
        return RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const RelatedContent & value)
{
    QJsonObject object;

    if (value.contentId()) {
        object[QStringLiteral("contentId")] = *value.contentId();
    }

    if (value.title()) {
        object[QStringLiteral("title")] = *value.title();
    }

    if (value.url()) {
        object[QStringLiteral("url")] = *value.url();
    }

    if (value.sourceId()) {
        object[QStringLiteral("sourceId")] = *value.sourceId();
    }

    if (value.sourceUrl()) {
        object[QStringLiteral("sourceUrl")] = *value.sourceUrl();
    }

    if (value.sourceFaviconUrl()) {
        object[QStringLiteral("sourceFaviconUrl")] = *value.sourceFaviconUrl();
    }

    if (value.sourceName()) {
        object[QStringLiteral("sourceName")] = *value.sourceName();
    }

    if (value.date()) {
        object[QStringLiteral("date")] = *value.date();
    }

    if (value.teaser()) {
        object[QStringLiteral("teaser")] = *value.teaser();
    }

    if (value.thumbnails())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.thumbnails()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("thumbnails")] = array;
    }

    if (value.contentType()) {
        object[QStringLiteral("contentType")] = QString::number(static_cast<qint64>(*value.contentType()));
    }

    if (value.accessType()) {
        object[QStringLiteral("accessType")] = QString::number(static_cast<qint64>(*value.accessType()));
    }

    if (value.visibleUrl()) {
        object[QStringLiteral("visibleUrl")] = *value.visibleUrl();
    }

    if (value.clipUrl()) {
        object[QStringLiteral("clipUrl")] = *value.clipUrl();
    }

    if (value.contact()) {
        object[QStringLiteral("contact")] = serializeToJson(*value.contact());
    }

    if (value.authors())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.authors()))
        {
            array << v;
        }

        object[QStringLiteral("authors")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, RelatedContent & value)
{
    if (object.contains(QStringLiteral("contentId"))) {
        const auto v = object[QStringLiteral("contentId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContentId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("title"))) {
        const auto v = object[QStringLiteral("title")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTitle(std::move(s));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("sourceId"))) {
        const auto v = object[QStringLiteral("sourceId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sourceUrl"))) {
        const auto v = object[QStringLiteral("sourceUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sourceFaviconUrl"))) {
        const auto v = object[QStringLiteral("sourceFaviconUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceFaviconUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sourceName"))) {
        const auto v = object[QStringLiteral("sourceName")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSourceName(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("date"))) {
        const auto v = object[QStringLiteral("date")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setDate(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("teaser"))) {
        const auto v = object[QStringLiteral("teaser")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTeaser(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("thumbnails"))) {
        const auto v = object[QStringLiteral("thumbnails")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<RelatedContentImage> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    RelatedContentImage f;
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
            value.setThumbnails(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contentType"))) {
        const auto v = object[QStringLiteral("contentType")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastRelatedContentTypeToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setContentType(*e);
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (object.contains(QStringLiteral("accessType"))) {
        const auto v = object[QStringLiteral("accessType")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                const auto e = safeCastRelatedContentAccessToEnum(static_cast<qint64>(d));
                if (e) {
                    value.setAccessType(*e);
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (object.contains(QStringLiteral("visibleUrl"))) {
        const auto v = object[QStringLiteral("visibleUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setVisibleUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("clipUrl"))) {
        const auto v = object[QStringLiteral("clipUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setClipUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contact"))) {
        const auto v = object[QStringLiteral("contact")];
        if (v.isObject()) {
            auto o = v.toObject();
            Contact f;
            if (deserializeFromJson(o, f)) {
                value.setContact(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("authors"))) {
        const auto v = object[QStringLiteral("authors")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setAuthors(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
