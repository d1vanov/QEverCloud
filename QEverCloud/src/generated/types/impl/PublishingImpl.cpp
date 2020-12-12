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

#include "PublishingData.h"

#include <QTextStream>

namespace qevercloud {

bool Publishing::Impl::operator==(
    const Publishing::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_uri == other.m_uri &&
        m_order == other.m_order &&
        m_ascending == other.m_ascending &&
        m_publicDescription == other.m_publicDescription;
}

bool Publishing::Impl::operator!=(
    const Publishing::Impl & other) const noexcept
{
    return !(*this == other);
}

void Publishing::Data::print(QTextStream & strm) const
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
