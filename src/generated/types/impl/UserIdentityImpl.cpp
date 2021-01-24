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

#include "UserIdentityImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool UserIdentity::Impl::operator==(
    const UserIdentity::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_type == other.m_type &&
        m_stringIdentifier == other.m_stringIdentifier &&
        m_longIdentifier == other.m_longIdentifier;
}

bool UserIdentity::Impl::operator!=(
    const UserIdentity::Impl & other) const noexcept
{
    return !(*this == other);
}

void UserIdentity::Impl::print(QTextStream & strm) const
{
    strm << "UserIdentity: {\n";

    if (m_type) {
        strm << "    type = "
            << *m_type << "\n";
    }
    else {
        strm << "    type is not set\n";
    }

    if (m_stringIdentifier) {
        strm << "    stringIdentifier = "
            << *m_stringIdentifier << "\n";
    }
    else {
        strm << "    stringIdentifier is not set\n";
    }

    if (m_longIdentifier) {
        strm << "    longIdentifier = "
            << *m_longIdentifier << "\n";
    }
    else {
        strm << "    longIdentifier is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
