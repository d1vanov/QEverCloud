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

#include "BootstrapInfoData.h"

#include <QTextStream>

namespace qevercloud {

bool BootstrapInfo::BootstrapInfoData::operator==(
    const BootstrapInfoData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_profiles == other.m_profiles;
}

bool BootstrapInfo::BootstrapInfoData::operator!=(
    const BootstrapInfoData & other) const noexcept
{
    return !(*this == other);
}

void BootstrapInfo::BootstrapInfoData::print(QTextStream & strm) const
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
