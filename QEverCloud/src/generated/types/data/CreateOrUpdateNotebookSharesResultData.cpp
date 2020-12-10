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

#include "CreateOrUpdateNotebookSharesResultData.h"

#include <QTextStream>

namespace qevercloud {

bool CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResultData::operator==(
    const CreateOrUpdateNotebookSharesResultData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_updateSequenceNum == other.m_updateSequenceNum &&
        m_matchingShares == other.m_matchingShares;
}

bool CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResultData::operator!=(
    const CreateOrUpdateNotebookSharesResultData & other) const noexcept
{
    return !(*this == other);
}

void CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResultData::print(QTextStream & strm) const
{
    strm << "CreateOrUpdateNotebookSharesResult: {\n";

    if (m_updateSequenceNum) {
        strm << "    updateSequenceNum = "
            << *m_updateSequenceNum << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (m_matchingShares) {
        strm << "    matchingShares = "
            << "QList<SharedNotebook> {";
        for(const auto & v: *m_matchingShares) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    matchingShares is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
