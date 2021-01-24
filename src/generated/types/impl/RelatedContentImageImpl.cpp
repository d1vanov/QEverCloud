/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "RelatedContentImageImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool RelatedContentImage::Impl::operator==(
    const RelatedContentImage::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_url == other.m_url &&
        m_width == other.m_width &&
        m_height == other.m_height &&
        m_pixelRatio == other.m_pixelRatio &&
        m_fileSize == other.m_fileSize;
}

bool RelatedContentImage::Impl::operator!=(
    const RelatedContentImage::Impl & other) const noexcept
{
    return !(*this == other);
}

void RelatedContentImage::Impl::print(QTextStream & strm) const
{
    strm << "RelatedContentImage: {\n";

    if (m_url) {
        strm << "    url = "
            << *m_url << "\n";
    }
    else {
        strm << "    url is not set\n";
    }

    if (m_width) {
        strm << "    width = "
            << *m_width << "\n";
    }
    else {
        strm << "    width is not set\n";
    }

    if (m_height) {
        strm << "    height = "
            << *m_height << "\n";
    }
    else {
        strm << "    height is not set\n";
    }

    if (m_pixelRatio) {
        strm << "    pixelRatio = "
            << *m_pixelRatio << "\n";
    }
    else {
        strm << "    pixelRatio is not set\n";
    }

    if (m_fileSize) {
        strm << "    fileSize = "
            << *m_fileSize << "\n";
    }
    else {
        strm << "    fileSize is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
