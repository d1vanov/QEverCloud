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

#include <qevercloud/serialization/json/RelatedResultSpec.h>

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

} // namespace

QJsonObject serializeToJson(const RelatedResultSpec & value)
{
    QJsonObject object;

    if (value.maxNotes()) {
        object[QStringLiteral("maxNotes")] = *value.maxNotes();
    }

    if (value.maxNotebooks()) {
        object[QStringLiteral("maxNotebooks")] = *value.maxNotebooks();
    }

    if (value.maxTags()) {
        object[QStringLiteral("maxTags")] = *value.maxTags();
    }

    if (value.writableNotebooksOnly()) {
        object[QStringLiteral("writableNotebooksOnly")] = *value.writableNotebooksOnly();
    }

    if (value.includeContainingNotebooks()) {
        object[QStringLiteral("includeContainingNotebooks")] = *value.includeContainingNotebooks();
    }

    if (value.includeDebugInfo()) {
        object[QStringLiteral("includeDebugInfo")] = *value.includeDebugInfo();
    }

    if (value.maxExperts()) {
        object[QStringLiteral("maxExperts")] = *value.maxExperts();
    }

    if (value.maxRelatedContent()) {
        object[QStringLiteral("maxRelatedContent")] = *value.maxRelatedContent();
    }

    if (value.relatedContentTypes())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.relatedContentTypes()))
        {
            array << QString::number(static_cast<qint64>(v));
        }

        object[QStringLiteral("relatedContentTypes")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, RelatedResultSpec & value)
{
    if (object.contains(QStringLiteral("maxNotes"))) {
        const auto v = object[QStringLiteral("maxNotes")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxNotes(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("maxNotebooks"))) {
        const auto v = object[QStringLiteral("maxNotebooks")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxNotebooks(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("maxTags"))) {
        const auto v = object[QStringLiteral("maxTags")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxTags(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("writableNotebooksOnly"))) {
        const auto v = object[QStringLiteral("writableNotebooksOnly")];
        if (v.isBool()) {
            value.setWritableNotebooksOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeContainingNotebooks"))) {
        const auto v = object[QStringLiteral("includeContainingNotebooks")];
        if (v.isBool()) {
            value.setIncludeContainingNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeDebugInfo"))) {
        const auto v = object[QStringLiteral("includeDebugInfo")];
        if (v.isBool()) {
            value.setIncludeDebugInfo(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("maxExperts"))) {
        const auto v = object[QStringLiteral("maxExperts")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxExperts(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("maxRelatedContent"))) {
        const auto v = object[QStringLiteral("maxRelatedContent")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setMaxRelatedContent(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("relatedContentTypes"))) {
        const auto v = object[QStringLiteral("relatedContentTypes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QSet<RelatedContentType> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isDouble()) {
                    const auto d = item.toDouble();
                    if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                        (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
                    {
                        const auto e = safeCastRelatedContentTypeToEnum(static_cast<qint64>(d));
                        if (e) {
                            values.insert(*e);
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
            value.setRelatedContentTypes(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
