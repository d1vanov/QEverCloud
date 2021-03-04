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

#include <qevercloud/generated/types/ManageNotebookSharesError.h>

#include "impl/ManageNotebookSharesErrorImpl.h"

namespace qevercloud {

ManageNotebookSharesError::ManageNotebookSharesError() :
    d(new ManageNotebookSharesError::Impl)
 {}

ManageNotebookSharesError::ManageNotebookSharesError(const ManageNotebookSharesError & other) :
    d(other.d)
{}

ManageNotebookSharesError::ManageNotebookSharesError(ManageNotebookSharesError && other) noexcept :
    d(std::move(other.d))
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

bool operator==(const ManageNotebookSharesError & lhs, const ManageNotebookSharesError & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.userIdentity() == rhs.userIdentity() &&
        lhs.userException() == rhs.userException() &&
        lhs.notFoundException() == rhs.notFoundException();
}

bool operator!=(const ManageNotebookSharesError & lhs, const ManageNotebookSharesError & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
