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

#include "ShareRelationshipRestrictionsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void ShareRelationshipRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "ShareRelationshipRestrictions: {\n";

    if (m_noSetReadOnly) {
        strm << "    noSetReadOnly = "
            << (*m_noSetReadOnly ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetReadOnly is not set\n";
    }

    if (m_noSetReadPlusActivity) {
        strm << "    noSetReadPlusActivity = "
            << (*m_noSetReadPlusActivity ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetReadPlusActivity is not set\n";
    }

    if (m_noSetModify) {
        strm << "    noSetModify = "
            << (*m_noSetModify ? "true" : "false") << "\n";
    }
    else {
        strm << "    noSetModify is not set\n";
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
