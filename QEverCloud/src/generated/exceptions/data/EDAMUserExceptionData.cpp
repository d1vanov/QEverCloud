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

#include "EDAMUserExceptionData.h"

#include <QTextStream>

namespace qevercloud {

bool EDAMUserException::EDAMUserExceptionData::operator==(
    const EDAMUserExceptionData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_errorCode == other.m_errorCode &&
        m_parameter == other.m_parameter;
}

bool EDAMUserException::EDAMUserExceptionData::operator!=(
    const EDAMUserExceptionData & other) const noexcept
{
    return !(*this == other);
}

void EDAMUserException::EDAMUserExceptionData::print(QTextStream & strm) const
{
    strm << "EDAMUserException: {\n";
    strm << "    errorCode = "
        << m_errorCode << "\n";

    if (m_parameter) {
        strm << "    parameter = "
            << *m_parameter << "\n";
    }
    else {
        strm << "    parameter is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
