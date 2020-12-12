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

#include "EDAMSystemExceptionData.h"

#include <QTextStream>

namespace qevercloud {

bool EDAMSystemException::Impl::operator==(
    const EDAMSystemException::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_errorCode == other.m_errorCode &&
        m_message == other.m_message &&
        m_rateLimitDuration == other.m_rateLimitDuration;
}

bool EDAMSystemException::Impl::operator!=(
    const EDAMSystemException::Impl & other) const noexcept
{
    return !(*this == other);
}

void EDAMSystemException::Data::print(QTextStream & strm) const
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
