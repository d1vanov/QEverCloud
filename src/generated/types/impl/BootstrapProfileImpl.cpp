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

#include "BootstrapProfileImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

void BootstrapProfile::Impl::print(QTextStream & strm) const
{
    strm << "BootstrapProfile: {\n";
    strm << "    name = "
        << m_name << "\n";
    strm << "    settings = "
        << m_settings << "\n";
    strm << "}\n";
}

} // namespace qevercloud
