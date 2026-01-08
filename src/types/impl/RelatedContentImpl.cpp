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

#include "RelatedContentImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void RelatedContent::Impl::print(QTextStream & strm) const
{
    strm << "RelatedContent: {\n";

    if (m_contentId) {
        strm << "    contentId = "
            << *m_contentId << "\n";
    }
    else {
        strm << "    contentId is not set\n";
    }

    if (m_title) {
        strm << "    title = "
            << *m_title << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (m_url) {
        strm << "    url = "
            << *m_url << "\n";
    }
    else {
        strm << "    url is not set\n";
    }

    if (m_sourceId) {
        strm << "    sourceId = "
            << *m_sourceId << "\n";
    }
    else {
        strm << "    sourceId is not set\n";
    }

    if (m_sourceUrl) {
        strm << "    sourceUrl = "
            << *m_sourceUrl << "\n";
    }
    else {
        strm << "    sourceUrl is not set\n";
    }

    if (m_sourceFaviconUrl) {
        strm << "    sourceFaviconUrl = "
            << *m_sourceFaviconUrl << "\n";
    }
    else {
        strm << "    sourceFaviconUrl is not set\n";
    }

    if (m_sourceName) {
        strm << "    sourceName = "
            << *m_sourceName << "\n";
    }
    else {
        strm << "    sourceName is not set\n";
    }

    if (m_date) {
        strm << "    date = "
            << *m_date << "\n";
    }
    else {
        strm << "    date is not set\n";
    }

    if (m_teaser) {
        strm << "    teaser = "
            << *m_teaser << "\n";
    }
    else {
        strm << "    teaser is not set\n";
    }

    if (m_thumbnails) {
        strm << "    thumbnails = "
            << "QList<RelatedContentImage> {";
        for(const auto & v: *m_thumbnails) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    thumbnails is not set\n";
    }

    if (m_contentType) {
        strm << "    contentType = "
            << *m_contentType << "\n";
    }
    else {
        strm << "    contentType is not set\n";
    }

    if (m_accessType) {
        strm << "    accessType = "
            << *m_accessType << "\n";
    }
    else {
        strm << "    accessType is not set\n";
    }

    if (m_visibleUrl) {
        strm << "    visibleUrl = "
            << *m_visibleUrl << "\n";
    }
    else {
        strm << "    visibleUrl is not set\n";
    }

    if (m_clipUrl) {
        strm << "    clipUrl = "
            << *m_clipUrl << "\n";
    }
    else {
        strm << "    clipUrl is not set\n";
    }

    if (m_contact) {
        strm << "    contact = "
            << *m_contact << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (m_authors) {
        strm << "    authors = "
            << "QList<QString> {";
        for(const auto & v: *m_authors) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    authors is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
