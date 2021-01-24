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

#include "ManageNotebookSharesResultImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool ManageNotebookSharesResult::Impl::operator==(
    const ManageNotebookSharesResult::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_errors == other.m_errors;
}

bool ManageNotebookSharesResult::Impl::operator!=(
    const ManageNotebookSharesResult::Impl & other) const noexcept
{
    return !(*this == other);
}

void ManageNotebookSharesResult::Impl::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesResult: {\n";

    if (m_errors) {
        strm << "    errors = "
            << "QList<ManageNotebookSharesError> {";
        for(const auto & v: *m_errors) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    errors is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
