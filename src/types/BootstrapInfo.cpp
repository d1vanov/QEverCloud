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

#include <qevercloud/types/BootstrapInfo.h>

#include "impl/BootstrapInfoImpl.h"

namespace qevercloud {

BootstrapInfo::BootstrapInfo() :
    d(new BootstrapInfo::Impl)
{}

BootstrapInfo::BootstrapInfo(const BootstrapInfo & other) :
    d(other.d)
{}

BootstrapInfo::BootstrapInfo(BootstrapInfo && other) noexcept :
    d(std::move(other.d))
{}

BootstrapInfo::~BootstrapInfo() noexcept {}

BootstrapInfo & BootstrapInfo::operator=(const BootstrapInfo & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BootstrapInfo & BootstrapInfo::operator=(BootstrapInfo && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QList<BootstrapProfile> & BootstrapInfo::profiles() const noexcept
{
    return d->m_profiles;
}

QList<BootstrapProfile> & BootstrapInfo::mutableProfiles()
{
    return d->m_profiles;
}

void BootstrapInfo::setProfiles(QList<BootstrapProfile> profiles)
{
    d->m_profiles = profiles;
}

void BootstrapInfo::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const BootstrapInfo & bootstrapInfo)
{
    strm << static_cast<const Printable&>(bootstrapInfo);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const BootstrapInfo & bootstrapInfo)
{
    dbg << static_cast<const Printable&>(bootstrapInfo);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const BootstrapInfo & bootstrapInfo)
{
    strm << static_cast<const Printable&>(bootstrapInfo);
    return strm;
}

bool operator==(const BootstrapInfo & lhs, const BootstrapInfo & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.profiles() == rhs.profiles();
}

bool operator!=(const BootstrapInfo & lhs, const BootstrapInfo & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
