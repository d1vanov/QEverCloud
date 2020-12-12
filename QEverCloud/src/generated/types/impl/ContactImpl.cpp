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

#include "ContactData.h"

#include <QTextStream>

namespace qevercloud {

bool Contact::Impl::operator==(
    const Contact::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_name == other.m_name &&
        m_id == other.m_id &&
        m_type == other.m_type &&
        m_photoUrl == other.m_photoUrl &&
        m_photoLastUpdated == other.m_photoLastUpdated &&
        m_messagingPermit == other.m_messagingPermit &&
        m_messagingPermitExpires == other.m_messagingPermitExpires;
}

bool Contact::Impl::operator!=(
    const Contact::Impl & other) const noexcept
{
    return !(*this == other);
}

void Contact::Data::print(QTextStream & strm) const
{
    strm << "Contact: {\n";

    if (m_name) {
        strm << "    name = "
            << *m_name << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (m_id) {
        strm << "    id = "
            << *m_id << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (m_type) {
        strm << "    type = "
            << *m_type << "\n";
    }
    else {
        strm << "    type is not set\n";
    }

    if (m_photoUrl) {
        strm << "    photoUrl = "
            << *m_photoUrl << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (m_photoLastUpdated) {
        strm << "    photoLastUpdated = "
            << *m_photoLastUpdated << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (m_messagingPermit) {
        strm << "    messagingPermit = "
            << *m_messagingPermit << "\n";
    }
    else {
        strm << "    messagingPermit is not set\n";
    }

    if (m_messagingPermitExpires) {
        strm << "    messagingPermitExpires = "
            << *m_messagingPermitExpires << "\n";
    }
    else {
        strm << "    messagingPermitExpires is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
