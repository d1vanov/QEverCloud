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

#include <qevercloud/types/CanMoveToContainerRestrictions.h>

#include "impl/CanMoveToContainerRestrictionsImpl.h"

namespace qevercloud {

CanMoveToContainerRestrictions::CanMoveToContainerRestrictions() :
    d(new CanMoveToContainerRestrictions::Impl)
 {}

CanMoveToContainerRestrictions::CanMoveToContainerRestrictions(const CanMoveToContainerRestrictions & other) :
    d(other.d)
{}

CanMoveToContainerRestrictions::CanMoveToContainerRestrictions(CanMoveToContainerRestrictions && other) noexcept :
    d(std::move(other.d))
{}

CanMoveToContainerRestrictions::~CanMoveToContainerRestrictions() noexcept {}

CanMoveToContainerRestrictions & CanMoveToContainerRestrictions::operator=(const CanMoveToContainerRestrictions & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

CanMoveToContainerRestrictions & CanMoveToContainerRestrictions::operator=(CanMoveToContainerRestrictions && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<CanMoveToContainerStatus> & CanMoveToContainerRestrictions::canMoveToContainer() const noexcept
{
    return d->m_canMoveToContainer;
}

std::optional<CanMoveToContainerStatus> & CanMoveToContainerRestrictions::mutableCanMoveToContainer()
{
    return d->m_canMoveToContainer;
}

void CanMoveToContainerRestrictions::setCanMoveToContainer(std::optional<CanMoveToContainerStatus> canMoveToContainer)
{
    d->m_canMoveToContainer = canMoveToContainer;
}

void CanMoveToContainerRestrictions::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.canMoveToContainer() == rhs.canMoveToContainer();
}

bool operator!=(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
