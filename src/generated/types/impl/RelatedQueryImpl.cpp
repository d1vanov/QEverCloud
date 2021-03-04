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

#include "RelatedQueryImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void RelatedQuery::Impl::print(QTextStream & strm) const
{
    strm << "RelatedQuery: {\n";

    if (m_noteGuid) {
        strm << "    noteGuid = "
            << *m_noteGuid << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (m_plainText) {
        strm << "    plainText = "
            << *m_plainText << "\n";
    }
    else {
        strm << "    plainText is not set\n";
    }

    if (m_filter) {
        strm << "    filter = "
            << *m_filter << "\n";
    }
    else {
        strm << "    filter is not set\n";
    }

    if (m_referenceUri) {
        strm << "    referenceUri = "
            << *m_referenceUri << "\n";
    }
    else {
        strm << "    referenceUri is not set\n";
    }

    if (m_context) {
        strm << "    context = "
            << *m_context << "\n";
    }
    else {
        strm << "    context is not set\n";
    }

    if (m_cacheKey) {
        strm << "    cacheKey = "
            << *m_cacheKey << "\n";
    }
    else {
        strm << "    cacheKey is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
