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

#include "NoteCollectionCountsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void NoteCollectionCounts::Impl::print(QTextStream & strm) const
{
    strm << "NoteCollectionCounts: {\n";

    if (m_notebookCounts) {
        strm << "    notebookCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(*m_notebookCounts)) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebookCounts is not set\n";
    }

    if (m_tagCounts) {
        strm << "    tagCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(*m_tagCounts)) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagCounts is not set\n";
    }

    if (m_trashCount) {
        strm << "    trashCount = "
            << *m_trashCount << "\n";
    }
    else {
        strm << "    trashCount is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
