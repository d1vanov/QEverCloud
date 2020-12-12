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

#include "ManageNoteSharesResultData.h"

#include <QTextStream>

namespace qevercloud {

bool ManageNoteSharesResult::Impl::operator==(
    const ManageNoteSharesResult::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_errors == other.m_errors;
}

bool ManageNoteSharesResult::Impl::operator!=(
    const ManageNoteSharesResult::Impl & other) const noexcept
{
    return !(*this == other);
}

void ManageNoteSharesResult::Data::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesResult: {\n";

    if (m_errors) {
        strm << "    errors = "
            << "QList<ManageNoteSharesError> {";
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
