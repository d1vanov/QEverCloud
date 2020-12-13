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

#include "NotesMetadataResultSpecImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NotesMetadataResultSpec::Impl::operator==(
    const NotesMetadataResultSpec::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_includeTitle == other.m_includeTitle &&
        m_includeContentLength == other.m_includeContentLength &&
        m_includeCreated == other.m_includeCreated &&
        m_includeUpdated == other.m_includeUpdated &&
        m_includeDeleted == other.m_includeDeleted &&
        m_includeUpdateSequenceNum == other.m_includeUpdateSequenceNum &&
        m_includeNotebookGuid == other.m_includeNotebookGuid &&
        m_includeTagGuids == other.m_includeTagGuids &&
        m_includeAttributes == other.m_includeAttributes &&
        m_includeLargestResourceMime == other.m_includeLargestResourceMime &&
        m_includeLargestResourceSize == other.m_includeLargestResourceSize;
}

bool NotesMetadataResultSpec::Impl::operator!=(
    const NotesMetadataResultSpec::Impl & other) const noexcept
{
    return !(*this == other);
}

void NotesMetadataResultSpec::Impl::print(QTextStream & strm) const
{
    strm << "NotesMetadataResultSpec: {\n";

    if (m_includeTitle) {
        strm << "    includeTitle = "
            << *m_includeTitle << "\n";
    }
    else {
        strm << "    includeTitle is not set\n";
    }

    if (m_includeContentLength) {
        strm << "    includeContentLength = "
            << *m_includeContentLength << "\n";
    }
    else {
        strm << "    includeContentLength is not set\n";
    }

    if (m_includeCreated) {
        strm << "    includeCreated = "
            << *m_includeCreated << "\n";
    }
    else {
        strm << "    includeCreated is not set\n";
    }

    if (m_includeUpdated) {
        strm << "    includeUpdated = "
            << *m_includeUpdated << "\n";
    }
    else {
        strm << "    includeUpdated is not set\n";
    }

    if (m_includeDeleted) {
        strm << "    includeDeleted = "
            << *m_includeDeleted << "\n";
    }
    else {
        strm << "    includeDeleted is not set\n";
    }

    if (m_includeUpdateSequenceNum) {
        strm << "    includeUpdateSequenceNum = "
            << *m_includeUpdateSequenceNum << "\n";
    }
    else {
        strm << "    includeUpdateSequenceNum is not set\n";
    }

    if (m_includeNotebookGuid) {
        strm << "    includeNotebookGuid = "
            << *m_includeNotebookGuid << "\n";
    }
    else {
        strm << "    includeNotebookGuid is not set\n";
    }

    if (m_includeTagGuids) {
        strm << "    includeTagGuids = "
            << *m_includeTagGuids << "\n";
    }
    else {
        strm << "    includeTagGuids is not set\n";
    }

    if (m_includeAttributes) {
        strm << "    includeAttributes = "
            << *m_includeAttributes << "\n";
    }
    else {
        strm << "    includeAttributes is not set\n";
    }

    if (m_includeLargestResourceMime) {
        strm << "    includeLargestResourceMime = "
            << *m_includeLargestResourceMime << "\n";
    }
    else {
        strm << "    includeLargestResourceMime is not set\n";
    }

    if (m_includeLargestResourceSize) {
        strm << "    includeLargestResourceSize = "
            << *m_includeLargestResourceSize << "\n";
    }
    else {
        strm << "    includeLargestResourceSize is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
