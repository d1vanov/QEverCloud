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

#include "RelatedResultSpecImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void RelatedResultSpec::Impl::print(QTextStream & strm) const
{
    strm << "RelatedResultSpec: {\n";

    if (m_maxNotes) {
        strm << "    maxNotes = "
            << *m_maxNotes << "\n";
    }
    else {
        strm << "    maxNotes is not set\n";
    }

    if (m_maxNotebooks) {
        strm << "    maxNotebooks = "
            << *m_maxNotebooks << "\n";
    }
    else {
        strm << "    maxNotebooks is not set\n";
    }

    if (m_maxTags) {
        strm << "    maxTags = "
            << *m_maxTags << "\n";
    }
    else {
        strm << "    maxTags is not set\n";
    }

    if (m_writableNotebooksOnly) {
        strm << "    writableNotebooksOnly = "
            << (*m_writableNotebooksOnly ? "true" : "false") << "\n";
    }
    else {
        strm << "    writableNotebooksOnly is not set\n";
    }

    if (m_includeContainingNotebooks) {
        strm << "    includeContainingNotebooks = "
            << (*m_includeContainingNotebooks ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeContainingNotebooks is not set\n";
    }

    if (m_includeDebugInfo) {
        strm << "    includeDebugInfo = "
            << (*m_includeDebugInfo ? "true" : "false") << "\n";
    }
    else {
        strm << "    includeDebugInfo is not set\n";
    }

    if (m_maxExperts) {
        strm << "    maxExperts = "
            << *m_maxExperts << "\n";
    }
    else {
        strm << "    maxExperts is not set\n";
    }

    if (m_maxRelatedContent) {
        strm << "    maxRelatedContent = "
            << *m_maxRelatedContent << "\n";
    }
    else {
        strm << "    maxRelatedContent is not set\n";
    }

    if (m_relatedContentTypes) {
        strm << "    relatedContentTypes = "
            << "QSet<RelatedContentType> {";
        for(const auto & v: *m_relatedContentTypes) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    relatedContentTypes is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
