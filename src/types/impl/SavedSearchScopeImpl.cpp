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

#include "SavedSearchScopeImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void SavedSearchScope::Impl::print(QTextStream & strm) const
{
    strm << "SavedSearchScope: {\n";

    if (m_includeAccount) {
        strm << "    includeAccount = "
            << *m_includeAccount << "\n";
    }
    else {
        strm << "    includeAccount is not set\n";
    }

    if (m_includePersonalLinkedNotebooks) {
        strm << "    includePersonalLinkedNotebooks = "
            << *m_includePersonalLinkedNotebooks << "\n";
    }
    else {
        strm << "    includePersonalLinkedNotebooks is not set\n";
    }

    if (m_includeBusinessLinkedNotebooks) {
        strm << "    includeBusinessLinkedNotebooks = "
            << *m_includeBusinessLinkedNotebooks << "\n";
    }
    else {
        strm << "    includeBusinessLinkedNotebooks is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
