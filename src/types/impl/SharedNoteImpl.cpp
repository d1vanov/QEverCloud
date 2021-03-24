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

#include "../../Impl.h"

#include <QTextStream>
#include <QUuid>

namespace qevercloud {

SharedNote::Impl::Impl()
{
}

void SharedNote::Impl::print(QTextStream & strm) const
{
    strm << "SharedNote: {\n";
        strm << "    noteGuid = " << m_noteGuid.value_or(QStringLiteral("not set")) << "\n";
        strm << "\n";
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
