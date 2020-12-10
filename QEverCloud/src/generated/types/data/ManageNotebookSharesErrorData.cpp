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

#include "ManageNotebookSharesErrorData.h"

#include <QTextStream>

namespace qevercloud {

bool ManageNotebookSharesError::ManageNotebookSharesErrorData::operator==(
    const ManageNotebookSharesErrorData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_userIdentity == other.m_userIdentity &&
        m_userException == other.m_userException &&
        m_notFoundException == other.m_notFoundException;
}

bool ManageNotebookSharesError::ManageNotebookSharesErrorData::operator!=(
    const ManageNotebookSharesErrorData & other) const noexcept
{
    return !(*this == other);
}

void ManageNotebookSharesError::ManageNotebookSharesErrorData::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesError: {\n";

    if (m_userIdentity) {
        strm << "    userIdentity = "
            << *m_userIdentity << "\n";
    }
    else {
        strm << "    userIdentity is not set\n";
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
