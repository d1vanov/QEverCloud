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

#include <qevercloud/generated/types/BootstrapInfo.h>

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

bool BootstrapInfo::operator==(const BootstrapInfo & other) const noexcept
{
    return *d == *other.d;
}

bool BootstrapInfo::operator!=(const BootstrapInfo & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
