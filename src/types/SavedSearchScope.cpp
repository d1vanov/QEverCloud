/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/SavedSearchScope.h>

#include "impl/SavedSearchScopeImpl.h"

namespace qevercloud {

SavedSearchScope::SavedSearchScope() :
    d(new SavedSearchScope::Impl)
{}

SavedSearchScope::SavedSearchScope(const SavedSearchScope & other) :
    d(other.d)
{}

SavedSearchScope::SavedSearchScope(SavedSearchScope && other) noexcept :
    d(std::move(other.d))
{}

SavedSearchScope::~SavedSearchScope() noexcept {}

SavedSearchScope & SavedSearchScope::operator=(const SavedSearchScope & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

SavedSearchScope & SavedSearchScope::operator=(SavedSearchScope && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & SavedSearchScope::includeAccount() const noexcept
{
    return d->m_includeAccount;
}

std::optional<bool> & SavedSearchScope::mutableIncludeAccount()
{
    return d->m_includeAccount;
}

void SavedSearchScope::setIncludeAccount(std::optional<bool> includeAccount)
{
    d->m_includeAccount = includeAccount;
}

const std::optional<bool> & SavedSearchScope::includePersonalLinkedNotebooks() const noexcept
{
    return d->m_includePersonalLinkedNotebooks;
}

std::optional<bool> & SavedSearchScope::mutableIncludePersonalLinkedNotebooks()
{
    return d->m_includePersonalLinkedNotebooks;
}

void SavedSearchScope::setIncludePersonalLinkedNotebooks(std::optional<bool> includePersonalLinkedNotebooks)
{
    d->m_includePersonalLinkedNotebooks = includePersonalLinkedNotebooks;
}

const std::optional<bool> & SavedSearchScope::includeBusinessLinkedNotebooks() const noexcept
{
    return d->m_includeBusinessLinkedNotebooks;
}

std::optional<bool> & SavedSearchScope::mutableIncludeBusinessLinkedNotebooks()
{
    return d->m_includeBusinessLinkedNotebooks;
}

void SavedSearchScope::setIncludeBusinessLinkedNotebooks(std::optional<bool> includeBusinessLinkedNotebooks)
{
    d->m_includeBusinessLinkedNotebooks = includeBusinessLinkedNotebooks;
}

void SavedSearchScope::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const SavedSearchScope & savedSearchScope)
{
    strm << static_cast<const Printable&>(savedSearchScope);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const SavedSearchScope & savedSearchScope)
{
    dbg << static_cast<const Printable&>(savedSearchScope);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const SavedSearchScope & savedSearchScope)
{
    strm << static_cast<const Printable&>(savedSearchScope);
    return strm;
}

bool operator==(const SavedSearchScope & lhs, const SavedSearchScope & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.includeAccount() == rhs.includeAccount() &&
        lhs.includePersonalLinkedNotebooks() == rhs.includePersonalLinkedNotebooks() &&
        lhs.includeBusinessLinkedNotebooks() == rhs.includeBusinessLinkedNotebooks();
}

bool operator!=(const SavedSearchScope & lhs, const SavedSearchScope & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
