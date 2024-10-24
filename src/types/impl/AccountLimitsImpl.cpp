/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "AccountLimitsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void AccountLimits::Impl::print(QTextStream & strm) const
{
    strm << "AccountLimits: {\n";

    if (m_userMailLimitDaily) {
        strm << "    userMailLimitDaily = "
            << *m_userMailLimitDaily << "\n";
    }
    else {
        strm << "    userMailLimitDaily is not set\n";
    }

    if (m_noteSizeMax) {
        strm << "    noteSizeMax = "
            << *m_noteSizeMax << "\n";
    }
    else {
        strm << "    noteSizeMax is not set\n";
    }

    if (m_resourceSizeMax) {
        strm << "    resourceSizeMax = "
            << *m_resourceSizeMax << "\n";
    }
    else {
        strm << "    resourceSizeMax is not set\n";
    }

    if (m_userLinkedNotebookMax) {
        strm << "    userLinkedNotebookMax = "
            << *m_userLinkedNotebookMax << "\n";
    }
    else {
        strm << "    userLinkedNotebookMax is not set\n";
    }

    if (m_uploadLimit) {
        strm << "    uploadLimit = "
            << *m_uploadLimit << "\n";
    }
    else {
        strm << "    uploadLimit is not set\n";
    }

    if (m_userNoteCountMax) {
        strm << "    userNoteCountMax = "
            << *m_userNoteCountMax << "\n";
    }
    else {
        strm << "    userNoteCountMax is not set\n";
    }

    if (m_userNotebookCountMax) {
        strm << "    userNotebookCountMax = "
            << *m_userNotebookCountMax << "\n";
    }
    else {
        strm << "    userNotebookCountMax is not set\n";
    }

    if (m_userTagCountMax) {
        strm << "    userTagCountMax = "
            << *m_userTagCountMax << "\n";
    }
    else {
        strm << "    userTagCountMax is not set\n";
    }

    if (m_noteTagCountMax) {
        strm << "    noteTagCountMax = "
            << *m_noteTagCountMax << "\n";
    }
    else {
        strm << "    noteTagCountMax is not set\n";
    }

    if (m_userSavedSearchesMax) {
        strm << "    userSavedSearchesMax = "
            << *m_userSavedSearchesMax << "\n";
    }
    else {
        strm << "    userSavedSearchesMax is not set\n";
    }

    if (m_noteResourceCountMax) {
        strm << "    noteResourceCountMax = "
            << *m_noteResourceCountMax << "\n";
    }
    else {
        strm << "    noteResourceCountMax is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud