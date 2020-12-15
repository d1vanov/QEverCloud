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

#include "UpdateNoteIfUsnMatchesResultImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool UpdateNoteIfUsnMatchesResult::Impl::operator==(
    const UpdateNoteIfUsnMatchesResult::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_note == other.m_note &&
        m_updated == other.m_updated;
}

bool UpdateNoteIfUsnMatchesResult::Impl::operator!=(
    const UpdateNoteIfUsnMatchesResult::Impl & other) const noexcept
{
    return !(*this == other);
}

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
            << *m_updated << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud