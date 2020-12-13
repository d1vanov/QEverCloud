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

#include <generated/types/ShareRelationshipRestrictions.h>

#include "impl/ShareRelationshipRestrictionsImpl.h"

namespace qevercloud {

ShareRelationshipRestrictions::ShareRelationshipRestrictions() :
    d(new ShareRelationshipRestrictions::Impl)
 {}

ShareRelationshipRestrictions::ShareRelationshipRestrictions(const ShareRelationshipRestrictions & other) :
    d(other.d)
{}

ShareRelationshipRestrictions::ShareRelationshipRestrictions(ShareRelationshipRestrictions && other) noexcept :
    d(std::move(other.d))
{}

ShareRelationshipRestrictions::~ShareRelationshipRestrictions() noexcept {}

ShareRelationshipRestrictions & ShareRelationshipRestrictions::operator=(const ShareRelationshipRestrictions & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ShareRelationshipRestrictions & ShareRelationshipRestrictions::operator=(ShareRelationshipRestrictions && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & ShareRelationshipRestrictions::noSetReadOnly() const noexcept
{
    return d->m_noSetReadOnly;
}

std::optional<bool> & ShareRelationshipRestrictions::mutableNoSetReadOnly()
{
    return d->m_noSetReadOnly;
}

void ShareRelationshipRestrictions::setNoSetReadOnly(std::optional<bool> noSetReadOnly)
{
    d->m_noSetReadOnly = noSetReadOnly;
}

const std::optional<bool> & ShareRelationshipRestrictions::noSetReadPlusActivity() const noexcept
{
    return d->m_noSetReadPlusActivity;
}

std::optional<bool> & ShareRelationshipRestrictions::mutableNoSetReadPlusActivity()
{
    return d->m_noSetReadPlusActivity;
}

void ShareRelationshipRestrictions::setNoSetReadPlusActivity(std::optional<bool> noSetReadPlusActivity)
{
    d->m_noSetReadPlusActivity = noSetReadPlusActivity;
}

const std::optional<bool> & ShareRelationshipRestrictions::noSetModify() const noexcept
{
    return d->m_noSetModify;
}

std::optional<bool> & ShareRelationshipRestrictions::mutableNoSetModify()
{
    return d->m_noSetModify;
}

void ShareRelationshipRestrictions::setNoSetModify(std::optional<bool> noSetModify)
{
    d->m_noSetModify = noSetModify;
}

const std::optional<bool> & ShareRelationshipRestrictions::noSetFullAccess() const noexcept
{
    return d->m_noSetFullAccess;
}

std::optional<bool> & ShareRelationshipRestrictions::mutableNoSetFullAccess()
{
    return d->m_noSetFullAccess;
}

void ShareRelationshipRestrictions::setNoSetFullAccess(std::optional<bool> noSetFullAccess)
{
    d->m_noSetFullAccess = noSetFullAccess;
}

void ShareRelationshipRestrictions::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ShareRelationshipRestrictions::operator==(const ShareRelationshipRestrictions & other) const noexcept
{
    return *d == *other.d;
}

bool ShareRelationshipRestrictions::operator!=(const ShareRelationshipRestrictions & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
