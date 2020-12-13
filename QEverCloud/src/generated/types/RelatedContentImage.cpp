/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/types/RelatedContentImage.h>

#include "impl/RelatedContentImageImpl.h"

namespace qevercloud {

RelatedContentImage::RelatedContentImage() :
    d(new RelatedContentImage::Impl)
 {}

RelatedContentImage::RelatedContentImage(const RelatedContentImage & other) :
    d(other.d)
{}

RelatedContentImage::RelatedContentImage(RelatedContentImage && other) noexcept :
    d(std::move(other.d))
{}

RelatedContentImage::~RelatedContentImage() noexcept {}

RelatedContentImage & RelatedContentImage::operator=(const RelatedContentImage & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

RelatedContentImage & RelatedContentImage::operator=(RelatedContentImage && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & RelatedContentImage::url() const noexcept
{
    return d->m_url;
}

void RelatedContentImage::setUrl(std::optional<QString> url)
{
    d->m_url = url;
}

const std::optional<qint32> & RelatedContentImage::width() const noexcept
{
    return d->m_width;
}

std::optional<qint32> & RelatedContentImage::mutableWidth()
{
    return d->m_width;
}

void RelatedContentImage::setWidth(std::optional<qint32> width)
{
    d->m_width = width;
}

const std::optional<qint32> & RelatedContentImage::height() const noexcept
{
    return d->m_height;
}

std::optional<qint32> & RelatedContentImage::mutableHeight()
{
    return d->m_height;
}

void RelatedContentImage::setHeight(std::optional<qint32> height)
{
    d->m_height = height;
}

const std::optional<double> & RelatedContentImage::pixelRatio() const noexcept
{
    return d->m_pixelRatio;
}

std::optional<double> & RelatedContentImage::mutablePixelRatio()
{
    return d->m_pixelRatio;
}

void RelatedContentImage::setPixelRatio(std::optional<double> pixelRatio)
{
    d->m_pixelRatio = pixelRatio;
}

const std::optional<qint32> & RelatedContentImage::fileSize() const noexcept
{
    return d->m_fileSize;
}

std::optional<qint32> & RelatedContentImage::mutableFileSize()
{
    return d->m_fileSize;
}

void RelatedContentImage::setFileSize(std::optional<qint32> fileSize)
{
    d->m_fileSize = fileSize;
}

void RelatedContentImage::print(QTextStream & strm) const
{
    d->print(strm);
}

bool RelatedContentImage::operator==(const RelatedContentImage & other) const noexcept
{
    return *d == *other.d;
}

bool RelatedContentImage::operator!=(const RelatedContentImage & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
