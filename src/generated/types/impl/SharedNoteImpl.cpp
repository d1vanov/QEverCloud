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

#include "SharedNoteImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

SharedNote::Impl::Impl()
{
    m_localId = QUuid::createUuid().toString();
    // Remove curvy braces
    m_localId.remove(m_localId.size() - 1, 1);
    m_localId.remove(0, 1);
}

bool SharedNote::Impl::operator==(
    const SharedNote::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_localId == other.m_localId &&
        m_locallyModified == other.m_locallyModified &&
        m_localOnly == other.m_localOnly &&
        m_locallyFavorited == other.m_locallyFavorited &&
        m_noteGuid == other.m_noteGuid &&
        m_indexInNote == other.m_indexInNote &&
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
        strm << "    noteGuid = " << m_noteGuid.value_or(QStringLiteral("not set")) << "\n";
        strm << "    indexInNote = " << (m_indexInNote ? QString::number(*m_indexInNote) : QStringLiteral("<not set>")) << "\n";
        strm << "    localId = " << m_localId << "\n";
        strm << "    locallyModified = " << (m_locallyModified ? "true" : "false") << "\n";
        strm << "    localOnly = " << (m_localOnly ? "true" : "false") << "\n";
        strm << "    locallyFavorited = " << (m_locallyFavorited ? "true" : "false") << "\n";

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
