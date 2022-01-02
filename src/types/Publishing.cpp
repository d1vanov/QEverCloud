/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/Publishing.h>

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

QTextStream & operator<<(QTextStream & strm, const Publishing & publishing)
{
    strm << static_cast<const Printable&>(publishing);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Publishing & publishing)
{
    dbg << static_cast<const Printable&>(publishing);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Publishing & publishing)
{
    strm << static_cast<const Printable&>(publishing);
    return strm;
}

bool operator==(const Publishing & lhs, const Publishing & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.uri() == rhs.uri() &&
        lhs.order() == rhs.order() &&
        lhs.ascending() == rhs.ascending() &&
        lhs.publicDescription() == rhs.publicDescription();
}

bool operator!=(const Publishing & lhs, const Publishing & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
