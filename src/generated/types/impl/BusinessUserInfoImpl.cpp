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

#include "BusinessUserInfoImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool BusinessUserInfo::Impl::operator==(
    const BusinessUserInfo::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_businessId == other.m_businessId &&
        m_businessName == other.m_businessName &&
        m_role == other.m_role &&
        m_email == other.m_email &&
        m_updated == other.m_updated;
}

bool BusinessUserInfo::Impl::operator!=(
    const BusinessUserInfo::Impl & other) const noexcept
{
    return !(*this == other);
}

void BusinessUserInfo::Impl::print(QTextStream & strm) const
{
    strm << "BusinessUserInfo: {\n";

    if (m_businessId) {
        strm << "    businessId = "
            << *m_businessId << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (m_businessName) {
        strm << "    businessName = "
            << *m_businessName << "\n";
    }
    else {
        strm << "    businessName is not set\n";
    }

    if (m_role) {
        strm << "    role = "
            << *m_role << "\n";
    }
    else {
        strm << "    role is not set\n";
    }

    if (m_email) {
        strm << "    email = "
            << *m_email << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (m_updated) {
        strm << "    updated = "
            << *m_updated << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud