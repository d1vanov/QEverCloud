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

#include "BusinessUserAttributesImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void BusinessUserAttributes::Impl::print(QTextStream & strm) const
{
    strm << "BusinessUserAttributes: {\n";

    if (m_title) {
        strm << "    title = "
            << *m_title << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (m_location) {
        strm << "    location = "
            << *m_location << "\n";
    }
    else {
        strm << "    location is not set\n";
    }

    if (m_department) {
        strm << "    department = "
            << *m_department << "\n";
    }
    else {
        strm << "    department is not set\n";
    }

    if (m_mobilePhone) {
        strm << "    mobilePhone = "
            << *m_mobilePhone << "\n";
    }
    else {
        strm << "    mobilePhone is not set\n";
    }

    if (m_linkedInProfileUrl) {
        strm << "    linkedInProfileUrl = "
            << *m_linkedInProfileUrl << "\n";
    }
    else {
        strm << "    linkedInProfileUrl is not set\n";
    }

    if (m_workPhone) {
        strm << "    workPhone = "
            << *m_workPhone << "\n";
    }
    else {
        strm << "    workPhone is not set\n";
    }

    if (m_companyStartDate) {
        strm << "    companyStartDate = "
            << *m_companyStartDate << "\n";
    }
    else {
        strm << "    companyStartDate is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
