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

#include "SyncChunkFilterImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool SyncChunkFilter::Impl::operator==(
    const SyncChunkFilter::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_includeNotes == other.m_includeNotes &&
        m_includeNoteResources == other.m_includeNoteResources &&
        m_includeNoteAttributes == other.m_includeNoteAttributes &&
        m_includeNotebooks == other.m_includeNotebooks &&
        m_includeTags == other.m_includeTags &&
        m_includeSearches == other.m_includeSearches &&
        m_includeResources == other.m_includeResources &&
        m_includeLinkedNotebooks == other.m_includeLinkedNotebooks &&
        m_includeExpunged == other.m_includeExpunged &&
        m_includeNoteApplicationDataFullMap == other.m_includeNoteApplicationDataFullMap &&
        m_includeResourceApplicationDataFullMap == other.m_includeResourceApplicationDataFullMap &&
        m_includeNoteResourceApplicationDataFullMap == other.m_includeNoteResourceApplicationDataFullMap &&
        m_includeSharedNotes == other.m_includeSharedNotes &&
        m_omitSharedNotebooks == other.m_omitSharedNotebooks &&
        m_requireNoteContentClass == other.m_requireNoteContentClass &&
        m_notebookGuids == other.m_notebookGuids;
}

bool SyncChunkFilter::Impl::operator!=(
    const SyncChunkFilter::Impl & other) const noexcept
{
    return !(*this == other);
}

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
