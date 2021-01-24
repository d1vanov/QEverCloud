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

#include <qevercloud/generated/types/Publishing.h>

#include "impl/PublishingImpl.h"

namespace qevercloud {

Publishing::Publishing() :
    d(new Publishing::Impl)
 {}

Publishing::Publishing(const Publishing & other) :
    d(other.d)
{}

Publishing::Publishing(Publishing && other) noexcept :
    d(std::move(other.d))
{}

Publishing::~Publishing() noexcept {}

Publishing & Publishing::operator=(const Publishing & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Publishing & Publishing::operator=(Publishing && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & Publishing::uri() const noexcept
{
    return d->m_uri;
}

void Publishing::setUri(std::optional<QString> uri)
{
    d->m_uri = uri;
}

const std::optional<NoteSortOrder> & Publishing::order() const noexcept
{
    return d->m_order;
}

std::optional<NoteSortOrder> & Publishing::mutableOrder()
{
    return d->m_order;
}

void Publishing::setOrder(std::optional<NoteSortOrder> order)
{
    d->m_order = order;
}

const std::optional<bool> & Publishing::ascending() const noexcept
{
    return d->m_ascending;
}

std::optional<bool> & Publishing::mutableAscending()
{
    return d->m_ascending;
}

void Publishing::setAscending(std::optional<bool> ascending)
{
    d->m_ascending = ascending;
}

const std::optional<QString> & Publishing::publicDescription() const noexcept
{
    return d->m_publicDescription;
}

void Publishing::setPublicDescription(std::optional<QString> publicDescription)
{
    d->m_publicDescription = publicDescription;
}

void Publishing::print(QTextStream & strm) const
{
    d->print(strm);
}

bool Publishing::operator==(const Publishing & other) const noexcept
{
    return *d == *other.d;
}

bool Publishing::operator!=(const Publishing & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
