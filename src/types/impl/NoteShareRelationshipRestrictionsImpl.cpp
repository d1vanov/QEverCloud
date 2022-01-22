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

#include "NoteShareRelationshipRestrictionsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteShareRelationshipRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "NoteShareRelationshipRestrictions: {\n";

    if (m_noSetReadNote) {
        strm << "    noSetReadNote = "
            << (*m_noSetReadNote ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetReadNote is not set\n";
    }

    if (m_noSetModifyNote) {
        strm << "    noSetModifyNote = "
            << (*m_noSetModifyNote ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetModifyNote is not set\n";
    }

    if (m_noSetFullAccess) {
        strm << "    noSetFullAccess = "
            << (*m_noSetFullAccess ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetFullAccess is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
