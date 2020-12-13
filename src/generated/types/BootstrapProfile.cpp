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

#include <qevercloud/generated/types/BootstrapProfile.h>

#include "impl/BootstrapProfileImpl.h"

namespace qevercloud {

BootstrapProfile::BootstrapProfile() :
    d(new BootstrapProfile::Impl)
 {}

BootstrapProfile::BootstrapProfile(const BootstrapProfile & other) :
    d(other.d)
{}

BootstrapProfile::BootstrapProfile(BootstrapProfile && other) noexcept :
    d(std::move(other.d))
{}

BootstrapProfile::~BootstrapProfile() noexcept {}

BootstrapProfile & BootstrapProfile::operator=(const BootstrapProfile & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BootstrapProfile & BootstrapProfile::operator=(BootstrapProfile && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QString & BootstrapProfile::name() const noexcept
{
    return d->m_name;
}

void BootstrapProfile::setName(QString name)
{
    d->m_name = name;
}

const BootstrapSettings & BootstrapProfile::settings() const noexcept
{
    return d->m_settings;
}

BootstrapSettings & BootstrapProfile::mutableSettings()
{
    return d->m_settings;
}

void BootstrapProfile::setSettings(BootstrapSettings settings)
{
    d->m_settings = settings;
}

void BootstrapProfile::print(QTextStream & strm) const
{
    d->print(strm);
}

bool BootstrapProfile::operator==(const BootstrapProfile & other) const noexcept
{
    return *d == *other.d;
}

bool BootstrapProfile::operator!=(const BootstrapProfile & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
