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

#include "NoteLimitsImpl.h"

#include "../../../../src/Impl.h"

#include <QTextStream>

namespace qevercloud {

bool NoteLimits::Impl::operator==(
    const NoteLimits::Impl & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_noteResourceCountMax == other.m_noteResourceCountMax &&
        m_uploadLimit == other.m_uploadLimit &&
        m_resourceSizeMax == other.m_resourceSizeMax &&
        m_noteSizeMax == other.m_noteSizeMax &&
        m_uploaded == other.m_uploaded;
}

bool NoteLimits::Impl::operator!=(
    const NoteLimits::Impl & other) const noexcept
{
    return !(*this == other);
}

void NoteLimits::Impl::print(QTextStream & strm) const
{
    strm << "NoteLimits: {\n";

    if (m_noteResourceCountMax) {
        strm << "    noteResourceCountMax = "
            << *m_noteResourceCountMax << "\n";
    }
    else {
        strm << "    noteResourceCountMax is not set\n";
    }

    if (m_uploadLimit) {
        strm << "    uploadLimit = "
            << *m_uploadLimit << "\n";
    }
    else {
        strm << "    uploadLimit is not set\n";
    }

    if (m_resourceSizeMax) {
        strm << "    resourceSizeMax = "
            << *m_resourceSizeMax << "\n";
    }
    else {
        strm << "    resourceSizeMax is not set\n";
    }

    if (m_noteSizeMax) {
        strm << "    noteSizeMax = "
            << *m_noteSizeMax << "\n";
    }
    else {
        strm << "    noteSizeMax is not set\n";
    }

    if (m_uploaded) {
        strm << "    uploaded = "
            << *m_uploaded << "\n";
    }
    else {
        strm << "    uploaded is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
