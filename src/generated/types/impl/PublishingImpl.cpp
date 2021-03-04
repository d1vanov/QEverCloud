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

#include "PublishingImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void Publishing::Impl::print(QTextStream & strm) const
{
    strm << "Publishing: {\n";

    if (m_uri) {
        strm << "    uri = "
            << *m_uri << "\n";
    }
    else {
        strm << "    uri is not set\n";
    }

    if (m_order) {
        strm << "    order = "
            << *m_order << "\n";
    }
    else {
        strm << "    order is not set\n";
    }

    if (m_ascending) {
        strm << "    ascending = "
            << *m_ascending << "\n";
    }
    else {
        strm << "    ascending is not set\n";
    }

    if (m_publicDescription) {
        strm << "    publicDescription = "
            << *m_publicDescription << "\n";
    }
    else {
        strm << "    publicDescription is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
