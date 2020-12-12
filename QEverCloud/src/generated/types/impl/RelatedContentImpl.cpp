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

#include "RelatedContentData.h"

#include <QTextStream>

namespace qevercloud {

bool RelatedContent::Impl::operator==(
    const RelatedContent::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_contentId == other.m_contentId &&
        m_title == other.m_title &&
        m_url == other.m_url &&
        m_sourceId == other.m_sourceId &&
        m_sourceUrl == other.m_sourceUrl &&
        m_sourceFaviconUrl == other.m_sourceFaviconUrl &&
        m_sourceName == other.m_sourceName &&
        m_date == other.m_date &&
        m_teaser == other.m_teaser &&
        m_thumbnails == other.m_thumbnails &&
        m_contentType == other.m_contentType &&
        m_accessType == other.m_accessType &&
        m_visibleUrl == other.m_visibleUrl &&
        m_clipUrl == other.m_clipUrl &&
        m_contact == other.m_contact &&
        m_authors == other.m_authors;
}

bool RelatedContent::Impl::operator!=(
    const RelatedContent::Impl & other) const noexcept
{
    return !(*this == other);
}

void RelatedContent::Data::print(QTextStream & strm) const
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
