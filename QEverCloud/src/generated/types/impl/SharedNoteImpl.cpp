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

#include "SharedNoteImpl.h"

#include <QTextStream>

namespace qevercloud {

bool SharedNote::Impl::operator==(
    const SharedNote::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_sharerUserID == other.m_sharerUserID &&
        m_recipientIdentity == other.m_recipientIdentity &&
        m_privilege == other.m_privilege &&
        m_serviceCreated == other.m_serviceCreated &&
        m_serviceUpdated == other.m_serviceUpdated &&
        m_serviceAssigned == other.m_serviceAssigned;
}

bool SharedNote::Impl::operator!=(
    const SharedNote::Impl & other) const noexcept
{
    return !(*this == other);
}

void SharedNote::Impl::print(QTextStream & strm) const
{
    strm << "SharedNote: {\n";

    if (m_sharerUserID) {
        strm << "    sharerUserID = "
            << *m_sharerUserID << "\n";
    }
    else {
        strm << "    sharerUserID is not set\n";
    }

    if (m_recipientIdentity) {
        strm << "    recipientIdentity = "
            << *m_recipientIdentity << "\n";
    }
    else {
        strm << "    recipientIdentity is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (m_serviceCreated) {
        strm << "    serviceCreated = "
            << *m_serviceCreated << "\n";
    }
    else {
        strm << "    serviceCreated is not set\n";
    }

    if (m_serviceUpdated) {
        strm << "    serviceUpdated = "
            << *m_serviceUpdated << "\n";
    }
    else {
        strm << "    serviceUpdated is not set\n";
    }

    if (m_serviceAssigned) {
        strm << "    serviceAssigned = "
            << *m_serviceAssigned << "\n";
    }
    else {
        strm << "    serviceAssigned is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
