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

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEBUILDER
#define QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/RelatedContentImage.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT RelatedContentImageBuilder
{
public:
    RelatedContentImageBuilder();

    RelatedContentImageBuilder(RelatedContentImageBuilder && other) noexcept;

    ~RelatedContentImageBuilder() noexcept;

    RelatedContentImageBuilder & operator=(RelatedContentImageBuilder && other) noexcept;

    RelatedContentImageBuilder & setUrl(std::optional<QString> url);
    RelatedContentImageBuilder & setWidth(std::optional<qint32> width);
    RelatedContentImageBuilder & setHeight(std::optional<qint32> height);
    RelatedContentImageBuilder & setPixelRatio(std::optional<double> pixelRatio);
    RelatedContentImageBuilder & setFileSize(std::optional<qint32> fileSize);

    [[nodiscard]] RelatedContentImage build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEBUILDER
