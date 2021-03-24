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

#include <qevercloud/types/ManageNoteSharesError.h>

#include "impl/ManageNoteSharesErrorImpl.h"

namespace qevercloud {

ManageNoteSharesError::ManageNoteSharesError() :
    d(new ManageNoteSharesError::Impl)
 {}

ManageNoteSharesError::ManageNoteSharesError(const ManageNoteSharesError & other) :
    d(other.d)
{}

ManageNoteSharesError::ManageNoteSharesError(ManageNoteSharesError && other) noexcept :
    d(std::move(other.d))
{}

ManageNoteSharesError::~ManageNoteSharesError() noexcept {}

ManageNoteSharesError & ManageNoteSharesError::operator=(const ManageNoteSharesError & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNoteSharesError & ManageNoteSharesError::operator=(ManageNoteSharesError && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<IdentityID> & ManageNoteSharesError::identityID() const noexcept
{
    return d->m_identityID;
}

std::optional<IdentityID> & ManageNoteSharesError::mutableIdentityID()
{
    return d->m_identityID;
}

void ManageNoteSharesError::setIdentityID(std::optional<IdentityID> identityID)
{
    d->m_identityID = identityID;
}

const std::optional<UserID> & ManageNoteSharesError::userID() const noexcept
{
    return d->m_userID;
}

std::optional<UserID> & ManageNoteSharesError::mutableUserID()
{
    return d->m_userID;
}

void ManageNoteSharesError::setUserID(std::optional<UserID> userID)
{
    d->m_userID = userID;
}

const std::optional<EDAMUserException> & ManageNoteSharesError::userException() const noexcept
{
    return d->m_userException;
}

std::optional<EDAMUserException> & ManageNoteSharesError::mutableUserException()
{
    return d->m_userException;
}

void ManageNoteSharesError::setUserException(std::optional<EDAMUserException> userException)
{
    d->m_userException = userException;
}

const std::optional<EDAMNotFoundException> & ManageNoteSharesError::notFoundException() const noexcept
{
    return d->m_notFoundException;
}

std::optional<EDAMNotFoundException> & ManageNoteSharesError::mutableNotFoundException()
{
    return d->m_notFoundException;
}

void ManageNoteSharesError::setNotFoundException(std::optional<EDAMNotFoundException> notFoundException)
{
    d->m_notFoundException = notFoundException;
}

void ManageNoteSharesError::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const ManageNoteSharesError & lhs, const ManageNoteSharesError & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.identityID() == rhs.identityID() &&
        lhs.userID() == rhs.userID() &&
        lhs.userException() == rhs.userException() &&
        lhs.notFoundException() == rhs.notFoundException();
}

bool operator!=(const ManageNoteSharesError & lhs, const ManageNoteSharesError & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
