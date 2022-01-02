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

#include <qevercloud/types/builders/RelatedContentImageBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedContentImageBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_url;
    std::optional<qint32> m_width;
    std::optional<qint32> m_height;
    std::optional<double> m_pixelRatio;
    std::optional<qint32> m_fileSize;
};

RelatedContentImageBuilder::RelatedContentImageBuilder() :
    d(new RelatedContentImageBuilder::Impl)
{}

RelatedContentImageBuilder::RelatedContentImageBuilder(RelatedContentImageBuilder && other) noexcept :
    d{std::move(other.d)}
{}

RelatedContentImageBuilder::~RelatedContentImageBuilder() noexcept = default;

RelatedContentImageBuilder & RelatedContentImageBuilder::operator=(RelatedContentImageBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

RelatedContentImageBuilder & RelatedContentImageBuilder::setUrl(std::optional<QString> url)
{
    d->m_url = std::move(url);
    return *this;
}

RelatedContentImageBuilder & RelatedContentImageBuilder::setWidth(std::optional<qint32> width)
{
    d->m_width = std::move(width);
    return *this;
}

RelatedContentImageBuilder & RelatedContentImageBuilder::setHeight(std::optional<qint32> height)
{
    d->m_height = std::move(height);
    return *this;
}

RelatedContentImageBuilder & RelatedContentImageBuilder::setPixelRatio(std::optional<double> pixelRatio)
{
    d->m_pixelRatio = std::move(pixelRatio);
    return *this;
}

RelatedContentImageBuilder & RelatedContentImageBuilder::setFileSize(std::optional<qint32> fileSize)
{
    d->m_fileSize = std::move(fileSize);
    return *this;
}

RelatedContentImage RelatedContentImageBuilder::build()
{
    RelatedContentImage result;

    result.setUrl(std::move(d->m_url));
    result.setWidth(std::move(d->m_width));
    result.setHeight(std::move(d->m_height));
    result.setPixelRatio(std::move(d->m_pixelRatio));
    result.setFileSize(std::move(d->m_fileSize));

    d->m_url = {};
    d->m_width = {};
    d->m_height = {};
    d->m_pixelRatio = {};
    d->m_fileSize = {};

    return result;
}

} // namespace qevercloud
