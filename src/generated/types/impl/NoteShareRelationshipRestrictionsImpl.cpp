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

#include "NoteShareRelationshipRestrictionsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteShareRelationshipRestrictions::Impl::operator==(
    const NoteShareRelationshipRestrictions::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_noSetReadNote == other.m_noSetReadNote &&
        m_noSetModifyNote == other.m_noSetModifyNote &&
        m_noSetFullAccess == other.m_noSetFullAccess;
}

bool NoteShareRelationshipRestrictions::Impl::operator!=(
    const NoteShareRelationshipRestrictions::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteShareRelationshipRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "NoteShareRelationshipRestrictions: {\n";

    if (m_noSetReadNote) {
        strm << "    noSetReadNote = "
            << *m_noSetReadNote << "\n";
    }
    else {
        strm << "    noSetReadNote is not set\n";
    }

    if (m_noSetModifyNote) {
        strm << "    noSetModifyNote = "
            << *m_noSetModifyNote << "\n";
    }
    else {
        strm << "    noSetModifyNote is not set\n";
    }

    if (m_noSetFullAccess) {
        strm << "    noSetFullAccess = "
            << *m_noSetFullAccess << "\n";
    }
    else {
        strm << "    noSetFullAccess is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
