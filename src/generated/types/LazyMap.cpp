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

#include <qevercloud/generated/types/LazyMap.h>

#include "impl/LazyMapImpl.h"

namespace qevercloud {

LazyMap::LazyMap() :
    d(new LazyMap::Impl)
 {}

LazyMap::LazyMap(const LazyMap & other) :
    d(other.d)
{}

LazyMap::LazyMap(LazyMap && other) noexcept :
    d(std::move(other.d))
{}

LazyMap::~LazyMap() noexcept {}

LazyMap & LazyMap::operator=(const LazyMap & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

LazyMap & LazyMap::operator=(LazyMap && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QSet<QString>> & LazyMap::keysOnly() const noexcept
{
    return d->m_keysOnly;
}

std::optional<QSet<QString>> & LazyMap::mutableKeysOnly()
{
    return d->m_keysOnly;
}

void LazyMap::setKeysOnly(std::optional<QSet<QString>> keysOnly)
{
    d->m_keysOnly = keysOnly;
}

const std::optional<QMap<QString, QString>> & LazyMap::fullMap() const noexcept
{
    return d->m_fullMap;
}

std::optional<QMap<QString, QString>> & LazyMap::mutableFullMap()
{
    return d->m_fullMap;
}

void LazyMap::setFullMap(std::optional<QMap<QString, QString>> fullMap)
{
    d->m_fullMap = fullMap;
}

void LazyMap::print(QTextStream & strm) const
{
    d->print(strm);
}

bool LazyMap::operator==(const LazyMap & other) const noexcept
{
    return *d == *other.d;
}

bool LazyMap::operator!=(const LazyMap & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
