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

#include "UpdateNoteIfUsnMatchesResultImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void UpdateNoteIfUsnMatchesResult::Impl::print(QTextStream & strm) const
{
    strm << "UpdateNoteIfUsnMatchesResult: {\n";

    if (m_note) {
        strm << "    note = "
            << *m_note << "\n";
    }
    else {
        strm << "    note is not set\n";
    }

    if (m_updated) {
        strm << "    updated = "
            << (*m_updated ? "true" : "false") << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
