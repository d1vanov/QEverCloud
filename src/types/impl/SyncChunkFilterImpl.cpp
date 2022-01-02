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

#include "SyncChunkFilterImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void SyncChunkFilter::Impl::print(QTextStream & strm) const
{
    strm << "SyncChunkFilter: {\n";

    if (m_includeNotes) {
        strm << "    includeNotes = "
            << *m_includeNotes << "\n";
    }
    else {
        strm << "    includeNotes is not set\n";
    }

    if (m_includeNoteResources) {
        strm << "    includeNoteResources = "
            << *m_includeNoteResources << "\n";
    }
    else {
        strm << "    includeNoteResources is not set\n";
    }

    if (m_includeNoteAttributes) {
        strm << "    includeNoteAttributes = "
            << *m_includeNoteAttributes << "\n";
    }
    else {
        strm << "    includeNoteAttributes is not set\n";
    }

    if (m_includeNotebooks) {
        strm << "    includeNotebooks = "
            << *m_includeNotebooks << "\n";
    }
    else {
        strm << "    includeNotebooks is not set\n";
    }

    if (m_includeTags) {
        strm << "    includeTags = "
            << *m_includeTags << "\n";
    }
    else {
        strm << "    includeTags is not set\n";
    }

    if (m_includeSearches) {
        strm << "    includeSearches = "
            << *m_includeSearches << "\n";
    }
    else {
        strm << "    includeSearches is not set\n";
    }

    if (m_includeResources) {
        strm << "    includeResources = "
            << *m_includeResources << "\n";
    }
    else {
        strm << "    includeResources is not set\n";
    }

    if (m_includeLinkedNotebooks) {
        strm << "    includeLinkedNotebooks = "
            << *m_includeLinkedNotebooks << "\n";
    }
    else {
        strm << "    includeLinkedNotebooks is not set\n";
    }

    if (m_includeExpunged) {
        strm << "    includeExpunged = "
            << *m_includeExpunged << "\n";
    }
    else {
        strm << "    includeExpunged is not set\n";
    }

    if (m_includeNoteApplicationDataFullMap) {
        strm << "    includeNoteApplicationDataFullMap = "
            << *m_includeNoteApplicationDataFullMap << "\n";
    }
    else {
        strm << "    includeNoteApplicationDataFullMap is not set\n";
    }

    if (m_includeResourceApplicationDataFullMap) {
        strm << "    includeResourceApplicationDataFullMap = "
            << *m_includeResourceApplicationDataFullMap << "\n";
    }
    else {
        strm << "    includeResourceApplicationDataFullMap is not set\n";
    }

    if (m_includeNoteResourceApplicationDataFullMap) {
        strm << "    includeNoteResourceApplicationDataFullMap = "
            << *m_includeNoteResourceApplicationDataFullMap << "\n";
    }
    else {
        strm << "    includeNoteResourceApplicationDataFullMap is not set\n";
    }

    if (m_includeSharedNotes) {
        strm << "    includeSharedNotes = "
            << *m_includeSharedNotes << "\n";
    }
    else {
        strm << "    includeSharedNotes is not set\n";
    }

    if (m_omitSharedNotebooks) {
        strm << "    omitSharedNotebooks = "
            << *m_omitSharedNotebooks << "\n";
    }
    else {
        strm << "    omitSharedNotebooks is not set\n";
    }

    if (m_requireNoteContentClass) {
        strm << "    requireNoteContentClass = "
            << *m_requireNoteContentClass << "\n";
    }
    else {
        strm << "    requireNoteContentClass is not set\n";
    }

    if (m_notebookGuids) {
        strm << "    notebookGuids = "
            << "QSet<QString> {";
        for(const auto & v: *m_notebookGuids) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebookGuids is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
