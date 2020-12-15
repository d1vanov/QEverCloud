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

#include "ManageNoteSharesErrorImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool ManageNoteSharesError::Impl::operator==(
    const ManageNoteSharesError::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_identityID == other.m_identityID &&
        m_userID == other.m_userID &&
        m_userException == other.m_userException &&
        m_notFoundException == other.m_notFoundException;
}

bool ManageNoteSharesError::Impl::operator!=(
    const ManageNoteSharesError::Impl & other) const noexcept
{
    return !(*this == other);
}

void ManageNoteSharesError::Impl::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesError: {\n";

    if (m_identityID) {
        strm << "    identityID = "
            << *m_identityID << "\n";
    }
    else {
        strm << "    identityID is not set\n";
    }

    if (m_userID) {
        strm << "    userID = "
            << *m_userID << "\n";
    }
    else {
        strm << "    userID is not set\n";
    }

    if (m_userException) {
        strm << "    userException = "
            << *m_userException << "\n";
    }
    else {
        strm << "    userException is not set\n";
    }

    if (m_notFoundException) {
        strm << "    notFoundException = "
            << *m_notFoundException << "\n";
    }
    else {
        strm << "    notFoundException is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud