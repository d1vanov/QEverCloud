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

#include <generated/types/BusinessNotebook.h>

#include "impl/BusinessNotebookImpl.h"

namespace qevercloud {

BusinessNotebook::BusinessNotebook() : d(new BusinessNotebook::Impl) {}

BusinessNotebook::BusinessNotebook(const BusinessNotebook & other) : d(other.d) {}

BusinessNotebook::BusinessNotebook(BusinessNotebook && other) noexcept : d(std::move(other.d))
{}

BusinessNotebook::~BusinessNotebook() noexcept {}

BusinessNotebook & BusinessNotebook::operator=(const BusinessNotebook & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BusinessNotebook & BusinessNotebook::operator=(BusinessNotebook && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & BusinessNotebook::notebookDescription() const noexcept
{
    return d->m_notebookDescription;
}

void BusinessNotebook::setNotebookDescription(std::optional<QString> notebookDescription)
{
    d->m_notebookDescription = notebookDescription;
}

const std::optional<SharedNotebookPrivilegeLevel> & BusinessNotebook::privilege() const noexcept
{
    return d->m_privilege;
}

std::optional<SharedNotebookPrivilegeLevel> & BusinessNotebook::mutablePrivilege()
{
    return d->m_privilege;
}

void BusinessNotebook::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = privilege;
}

const std::optional<bool> & BusinessNotebook::recommended() const noexcept
{
    return d->m_recommended;
}

std::optional<bool> & BusinessNotebook::mutableRecommended()
{
    return d->m_recommended;
}

void BusinessNotebook::setRecommended(std::optional<bool> recommended)
{
    d->m_recommended = recommended;
}

void BusinessNotebook::print(QTextStream & strm) const
{
    d->print(strm);
}

bool BusinessNotebook::operator==(const BusinessNotebook & other) const noexcept
{
    return *d == *other.d;
}

bool BusinessNotebook::operator!=(const BusinessNotebook & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
