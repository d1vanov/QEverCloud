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

#include "NoteFilterImpl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteFilter::Impl::operator==(
    const NoteFilter::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_order == other.m_order &&
        m_ascending == other.m_ascending &&
        m_words == other.m_words &&
        m_notebookGuid == other.m_notebookGuid &&
        m_tagGuids == other.m_tagGuids &&
        m_timeZone == other.m_timeZone &&
        m_inactive == other.m_inactive &&
        m_emphasized == other.m_emphasized &&
        m_includeAllReadableNotebooks == other.m_includeAllReadableNotebooks &&
        m_includeAllReadableWorkspaces == other.m_includeAllReadableWorkspaces &&
        m_context == other.m_context &&
        m_rawWords == other.m_rawWords &&
        m_searchContextBytes == other.m_searchContextBytes;
}

bool NoteFilter::Impl::operator!=(
    const NoteFilter::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteFilter::Impl::print(QTextStream & strm) const
{
    strm << "NoteFilter: {\n";

    if (m_order) {
        strm << "    order = "
            << *m_order << "\n";
    }
    else {
        strm << "    order is not set\n";
    }

    if (m_ascending) {
        strm << "    ascending = "
            << *m_ascending << "\n";
    }
    else {
        strm << "    ascending is not set\n";
    }

    if (m_words) {
        strm << "    words = "
            << *m_words << "\n";
    }
    else {
        strm << "    words is not set\n";
    }

    if (m_notebookGuid) {
        strm << "    notebookGuid = "
            << *m_notebookGuid << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (m_tagGuids) {
        strm << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: *m_tagGuids) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagGuids is not set\n";
    }

    if (m_timeZone) {
        strm << "    timeZone = "
            << *m_timeZone << "\n";
    }
    else {
        strm << "    timeZone is not set\n";
    }

    if (m_inactive) {
        strm << "    inactive = "
            << *m_inactive << "\n";
    }
    else {
        strm << "    inactive is not set\n";
    }

    if (m_emphasized) {
        strm << "    emphasized = "
            << *m_emphasized << "\n";
    }
    else {
        strm << "    emphasized is not set\n";
    }

    if (m_includeAllReadableNotebooks) {
        strm << "    includeAllReadableNotebooks = "
            << *m_includeAllReadableNotebooks << "\n";
    }
    else {
        strm << "    includeAllReadableNotebooks is not set\n";
    }

    if (m_includeAllReadableWorkspaces) {
        strm << "    includeAllReadableWorkspaces = "
            << *m_includeAllReadableWorkspaces << "\n";
    }
    else {
        strm << "    includeAllReadableWorkspaces is not set\n";
    }

    if (m_context) {
        strm << "    context = "
            << *m_context << "\n";
    }
    else {
        strm << "    context is not set\n";
    }

    if (m_rawWords) {
        strm << "    rawWords = "
            << *m_rawWords << "\n";
    }
    else {
        strm << "    rawWords is not set\n";
    }

    if (m_searchContextBytes) {
        strm << "    searchContextBytes = "
            << *m_searchContextBytes << "\n";
    }
    else {
        strm << "    searchContextBytes is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
