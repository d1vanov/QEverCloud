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

#include "RelatedResultImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void RelatedResult::Impl::print(QTextStream & strm) const
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
