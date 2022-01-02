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

#include "LazyMapImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void LazyMap::Impl::print(QTextStream & strm) const
{
    strm << "LazyMap: {\n";

    if (m_keysOnly) {
        strm << "    keysOnly = "
            << "QSet<QString> {";
        for(const auto & v: *m_keysOnly) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    keysOnly is not set\n";
    }

    if (m_fullMap) {
        strm << "    fullMap = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(*m_fullMap)) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    fullMap is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
