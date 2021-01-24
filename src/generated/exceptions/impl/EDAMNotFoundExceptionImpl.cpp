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

#include "EDAMNotFoundExceptionImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool EDAMNotFoundException::Impl::operator==(
    const EDAMNotFoundException::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_identifier == other.m_identifier &&
        m_key == other.m_key;
}

bool EDAMNotFoundException::Impl::operator!=(
    const EDAMNotFoundException::Impl & other) const noexcept
{
    return !(*this == other);
}

void EDAMNotFoundException::Impl::print(QTextStream & strm) const
{
    strm << "EDAMNotFoundException: {\n";

    if (m_identifier) {
        strm << "    identifier = "
            << *m_identifier << "\n";
    }
    else {
        strm << "    identifier is not set\n";
    }

    if (m_key) {
        strm << "    key = "
            << *m_key << "\n";
    }
    else {
        strm << "    key is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
