/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "ManageNoteSharesResultImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void ManageNoteSharesResult::Impl::print(QTextStream & strm) const
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
