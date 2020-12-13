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

#include "DataImpl.h"

#include <QTextStream>

namespace qevercloud {

bool Data::Impl::operator==(
    const Data::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_bodyHash == other.m_bodyHash &&
        m_size == other.m_size &&
        m_body == other.m_body;
}

bool Data::Impl::operator!=(
    const Data::Impl & other) const noexcept
{
    return !(*this == other);
}

void Data::Impl::print(QTextStream & strm) const
{
    strm << "Data: {\n";

    if (m_bodyHash) {
        strm << "    bodyHash = "
            << *m_bodyHash << "\n";
    }
    else {
        strm << "    bodyHash is not set\n";
    }

    if (m_size) {
        strm << "    size = "
            << *m_size << "\n";
    }
    else {
        strm << "    size is not set\n";
    }

    if (m_body) {
        strm << "    body = "
            << *m_body << "\n";
    }
    else {
        strm << "    body is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
