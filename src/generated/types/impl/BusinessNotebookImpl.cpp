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

#include "BusinessNotebookImpl.h"

#include <QTextStream>

namespace qevercloud {

bool BusinessNotebook::Impl::operator==(
    const BusinessNotebook::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_notebookDescription == other.m_notebookDescription &&
        m_privilege == other.m_privilege &&
        m_recommended == other.m_recommended;
}

bool BusinessNotebook::Impl::operator!=(
    const BusinessNotebook::Impl & other) const noexcept
{
    return !(*this == other);
}

void BusinessNotebook::Impl::print(QTextStream & strm) const
{
    strm << "BusinessNotebook: {\n";

    if (m_notebookDescription) {
        strm << "    notebookDescription = "
            << *m_notebookDescription << "\n";
    }
    else {
        strm << "    notebookDescription is not set\n";
    }

    if (m_privilege) {
        strm << "    privilege = "
            << *m_privilege << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (m_recommended) {
        strm << "    recommended = "
            << *m_recommended << "\n";
    }
    else {
        strm << "    recommended is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
