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

#include <generated/types/ManageNotebookSharesError.h>

#include "data/ManageNotebookSharesErrorData.h"

namespace qevercloud {

ManageNotebookSharesError::ManageNotebookSharesError() : d(new ManageNotebookSharesErrorData) {}

ManageNotebookSharesError::ManageNotebookSharesError(const ManageNotebookSharesError & other) : d(other.d) {}

ManageNotebookSharesError::ManageNotebookSharesError(ManageNotebookSharesError && other) noexcept : d(std::move(other.d))
{}

ManageNotebookSharesError::~ManageNotebookSharesError() noexcept {}

ManageNotebookSharesError & ManageNotebookSharesError::operator=(const ManageNotebookSharesError & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNotebookSharesError & ManageNotebookSharesError::operator=(ManageNotebookSharesError && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<UserIdentity> & ManageNotebookSharesError::userIdentity() const noexcept
{
    return d->m_userIdentity;
}

std::optional<UserIdentity> & ManageNotebookSharesError::mutableUserIdentity()
{
    return d->m_userIdentity;
}

void ManageNotebookSharesError::setUserIdentity(std::optional<UserIdentity> userIdentity)
{
    d->m_userIdentity = userIdentity;
}

const std::optional<EDAMUserException> & ManageNotebookSharesError::userException() const noexcept
{
    return d->m_userException;
}

std::optional<EDAMUserException> & ManageNotebookSharesError::mutableUserException()
{
    return d->m_userException;
}

void ManageNotebookSharesError::setUserException(std::optional<EDAMUserException> userException)
{
    d->m_userException = userException;
}

const std::optional<EDAMNotFoundException> & ManageNotebookSharesError::notFoundException() const noexcept
{
    return d->m_notFoundException;
}

std::optional<EDAMNotFoundException> & ManageNotebookSharesError::mutableNotFoundException()
{
    return d->m_notFoundException;
}

void ManageNotebookSharesError::setNotFoundException(std::optional<EDAMNotFoundException> notFoundException)
{
    d->m_notFoundException = notFoundException;
}

void ManageNotebookSharesError::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ManageNotebookSharesError::operator==(const ManageNotebookSharesError & other) const noexcept
{
    return *d == *other.d;
}

bool ManageNotebookSharesError::operator!=(const ManageNotebookSharesError & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
