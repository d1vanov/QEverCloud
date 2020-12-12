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

#include "ShareRelationshipRestrictionsImpl.h"

#include <QTextStream>

namespace qevercloud {

bool ShareRelationshipRestrictions::Impl::operator==(
    const ShareRelationshipRestrictions::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_noSetReadOnly == other.m_noSetReadOnly &&
        m_noSetReadPlusActivity == other.m_noSetReadPlusActivity &&
        m_noSetModify == other.m_noSetModify &&
        m_noSetFullAccess == other.m_noSetFullAccess;
}

bool ShareRelationshipRestrictions::Impl::operator!=(
    const ShareRelationshipRestrictions::Impl & other) const noexcept
{
    return !(*this == other);
}

void ShareRelationshipRestrictions::Impl::print(QTextStream & strm) const
{
    strm << "ShareRelationshipRestrictions: {\n";

    if (m_noSetReadOnly) {
        strm << "    noSetReadOnly = "
            << *m_noSetReadOnly << "\n";
    }
    else {
        strm << "    noSetReadOnly is not set\n";
    }

    if (m_noSetReadPlusActivity) {
        strm << "    noSetReadPlusActivity = "
            << *m_noSetReadPlusActivity << "\n";
    }
    else {
        strm << "    noSetReadPlusActivity is not set\n";
    }

    if (m_noSetModify) {
        strm << "    noSetModify = "
            << *m_noSetModify << "\n";
    }
    else {
        strm << "    noSetModify is not set\n";
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
