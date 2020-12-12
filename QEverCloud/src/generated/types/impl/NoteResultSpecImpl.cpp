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

#include "NoteResultSpecImpl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteResultSpec::Impl::operator==(
    const NoteResultSpec::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_includeContent == other.m_includeContent &&
        m_includeResourcesData == other.m_includeResourcesData &&
        m_includeResourcesRecognition == other.m_includeResourcesRecognition &&
        m_includeResourcesAlternateData == other.m_includeResourcesAlternateData &&
        m_includeSharedNotes == other.m_includeSharedNotes &&
        m_includeNoteAppDataValues == other.m_includeNoteAppDataValues &&
        m_includeResourceAppDataValues == other.m_includeResourceAppDataValues &&
        m_includeAccountLimits == other.m_includeAccountLimits;
}

bool NoteResultSpec::Impl::operator!=(
    const NoteResultSpec::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteResultSpec::Impl::print(QTextStream & strm) const
{
    strm << "NoteResultSpec: {\n";

    if (m_includeContent) {
        strm << "    includeContent = "
            << *m_includeContent << "\n";
    }
    else {
        strm << "    includeContent is not set\n";
    }

    if (m_includeResourcesData) {
        strm << "    includeResourcesData = "
            << *m_includeResourcesData << "\n";
    }
    else {
        strm << "    includeResourcesData is not set\n";
    }

    if (m_includeResourcesRecognition) {
        strm << "    includeResourcesRecognition = "
            << *m_includeResourcesRecognition << "\n";
    }
    else {
        strm << "    includeResourcesRecognition is not set\n";
    }

    if (m_includeResourcesAlternateData) {
        strm << "    includeResourcesAlternateData = "
            << *m_includeResourcesAlternateData << "\n";
    }
    else {
        strm << "    includeResourcesAlternateData is not set\n";
    }

    if (m_includeSharedNotes) {
        strm << "    includeSharedNotes = "
            << *m_includeSharedNotes << "\n";
    }
    else {
        strm << "    includeSharedNotes is not set\n";
    }

    if (m_includeNoteAppDataValues) {
        strm << "    includeNoteAppDataValues = "
            << *m_includeNoteAppDataValues << "\n";
    }
    else {
        strm << "    includeNoteAppDataValues is not set\n";
    }

    if (m_includeResourceAppDataValues) {
        strm << "    includeResourceAppDataValues = "
            << *m_includeResourceAppDataValues << "\n";
    }
    else {
        strm << "    includeResourceAppDataValues is not set\n";
    }

    if (m_includeAccountLimits) {
        strm << "    includeAccountLimits = "
            << *m_includeAccountLimits << "\n";
    }
    else {
        strm << "    includeAccountLimits is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
