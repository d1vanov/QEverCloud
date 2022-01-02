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

#include <qevercloud/types/builders/ManageNoteSharesErrorBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesErrorBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<IdentityID> m_identityID;
    std::optional<UserID> m_userID;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

ManageNoteSharesErrorBuilder::ManageNoteSharesErrorBuilder() :
    d(new ManageNoteSharesErrorBuilder::Impl)
{}

ManageNoteSharesErrorBuilder::ManageNoteSharesErrorBuilder(ManageNoteSharesErrorBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNoteSharesErrorBuilder::~ManageNoteSharesErrorBuilder() noexcept = default;

ManageNoteSharesErrorBuilder & ManageNoteSharesErrorBuilder::operator=(ManageNoteSharesErrorBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNoteSharesErrorBuilder & ManageNoteSharesErrorBuilder::setIdentityID(std::optional<IdentityID> identityID)
{
    d->m_identityID = std::move(identityID);
    return *this;
}

ManageNoteSharesErrorBuilder & ManageNoteSharesErrorBuilder::setUserID(std::optional<UserID> userID)
{
    d->m_userID = std::move(userID);
    return *this;
}

ManageNoteSharesErrorBuilder & ManageNoteSharesErrorBuilder::setUserException(std::optional<EDAMUserException> userException)
{
    d->m_userException = std::move(userException);
    return *this;
}

ManageNoteSharesErrorBuilder & ManageNoteSharesErrorBuilder::setNotFoundException(std::optional<EDAMNotFoundException> notFoundException)
{
    d->m_notFoundException = std::move(notFoundException);
    return *this;
}

ManageNoteSharesError ManageNoteSharesErrorBuilder::build()
{
    ManageNoteSharesError result;

    result.setIdentityID(std::move(d->m_identityID));
    result.setUserID(std::move(d->m_userID));
    result.setUserException(std::move(d->m_userException));
    result.setNotFoundException(std::move(d->m_notFoundException));

    d->m_identityID = {};
    d->m_userID = {};
    d->m_userException = {};
    d->m_notFoundException = {};

    return result;
}

} // namespace qevercloud
