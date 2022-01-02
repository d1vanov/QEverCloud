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

#include "RelatedContentImageImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

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
