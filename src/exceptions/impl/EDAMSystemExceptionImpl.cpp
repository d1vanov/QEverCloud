/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "EDAMSystemExceptionImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void EDAMSystemException::Impl::print(QTextStream & strm) const
{
    strm << "EDAMSystemException: {\n";
    strm << "    errorCode = "
        << m_errorCode << "\n";

    if (m_message) {
        strm << "    message = "
            << *m_message << "\n";
    }
    else {
        strm << "    message is not set\n";
    }

    if (m_rateLimitDuration) {
        strm << "    rateLimitDuration = "
            << *m_rateLimitDuration << "\n";
    }
    else {
        strm << "    rateLimitDuration is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
