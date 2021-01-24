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

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool BusinessUserAttributes::Impl::operator==(
    const BusinessUserAttributes::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_title == other.m_title &&
        m_location == other.m_location &&
        m_department == other.m_department &&
        m_mobilePhone == other.m_mobilePhone &&
        m_linkedInProfileUrl == other.m_linkedInProfileUrl &&
        m_workPhone == other.m_workPhone &&
        m_companyStartDate == other.m_companyStartDate;
}

bool BusinessUserAttributes::Impl::operator!=(
    const BusinessUserAttributes::Impl & other) const noexcept
{
    return !(*this == other);
}

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
