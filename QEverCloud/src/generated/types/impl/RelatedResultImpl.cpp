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

#include "RelatedResultData.h"

#include <QTextStream>

namespace qevercloud {

bool RelatedResult::Impl::operator==(
    const RelatedResult::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_notes == other.m_notes &&
        m_notebooks == other.m_notebooks &&
        m_tags == other.m_tags &&
        m_containingNotebooks == other.m_containingNotebooks &&
        m_debugInfo == other.m_debugInfo &&
        m_experts == other.m_experts &&
        m_relatedContent == other.m_relatedContent &&
        m_cacheKey == other.m_cacheKey &&
        m_cacheExpires == other.m_cacheExpires;
}

bool RelatedResult::Impl::operator!=(
    const RelatedResult::Impl & other) const noexcept
{
    return !(*this == other);
}

void RelatedResult::Data::print(QTextStream & strm) const
{
    strm << "RelatedResult: {\n";

    if (m_notes) {
        strm << "    notes = "
            << "QList<Note> {";
        for(const auto & v: *m_notes) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notes is not set\n";
    }

    if (m_notebooks) {
        strm << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: *m_notebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebooks is not set\n";
    }

    if (m_tags) {
        strm << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: *m_tags) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tags is not set\n";
    }

    if (m_containingNotebooks) {
        strm << "    containingNotebooks = "
            << "QList<NotebookDescriptor> {";
        for(const auto & v: *m_containingNotebooks) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    containingNotebooks is not set\n";
    }

    if (m_debugInfo) {
        strm << "    debugInfo = "
            << *m_debugInfo << "\n";
    }
    else {
        strm << "    debugInfo is not set\n";
    }

    if (m_experts) {
        strm << "    experts = "
            << "QList<UserProfile> {";
        for(const auto & v: *m_experts) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    experts is not set\n";
    }

    if (m_relatedContent) {
        strm << "    relatedContent = "
            << "QList<RelatedContent> {";
        for(const auto & v: *m_relatedContent) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    relatedContent is not set\n";
    }

    if (m_cacheKey) {
        strm << "    cacheKey = "
            << *m_cacheKey << "\n";
    }
    else {
        strm << "    cacheKey is not set\n";
    }

    if (m_cacheExpires) {
        strm << "    cacheExpires = "
            << *m_cacheExpires << "\n";
    }
    else {
        strm << "    cacheExpires is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
