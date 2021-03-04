/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "NoteRestrictionsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "NoteRestrictions: {\n";

    if (m_noUpdateTitle) {
        strm << "    noUpdateTitle = "
            << *m_noUpdateTitle << "\n";
    }
    else {
        strm << "    noUpdateTitle is not set\n";
    }

    if (m_noUpdateContent) {
        strm << "    noUpdateContent = "
            << *m_noUpdateContent << "\n";
    }
    else {
        strm << "    noUpdateContent is not set\n";
    }

    if (m_noEmail) {
        strm << "    noEmail = "
            << *m_noEmail << "\n";
    }
    else {
        strm << "    noEmail is not set\n";
    }

    if (m_noShare) {
        strm << "    noShare = "
            << *m_noShare << "\n";
    }
    else {
        strm << "    noShare is not set\n";
    }

    if (m_noSharePublicly) {
        strm << "    noSharePublicly = "
            << *m_noSharePublicly << "\n";
    }
    else {
        strm << "    noSharePublicly is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
