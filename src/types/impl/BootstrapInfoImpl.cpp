/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "BootstrapInfoImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void BootstrapInfo::Impl::print(QTextStream & strm) const
{
    strm << "BootstrapInfo: {\n";
    strm << "    profiles = "
        << "QList<BootstrapProfile> {";
    for(const auto & v: m_profiles) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";
    strm << "}\n";
}

} // namespace qevercloud
