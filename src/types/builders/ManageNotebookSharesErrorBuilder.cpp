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

#include <qevercloud/types/builders/ManageNotebookSharesErrorBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesErrorBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<UserIdentity> m_userIdentity;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

ManageNotebookSharesErrorBuilder::ManageNotebookSharesErrorBuilder() :
    d(new ManageNotebookSharesErrorBuilder::Impl)
{}

ManageNotebookSharesErrorBuilder::ManageNotebookSharesErrorBuilder(ManageNotebookSharesErrorBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNotebookSharesErrorBuilder::~ManageNotebookSharesErrorBuilder() noexcept = default;

ManageNotebookSharesErrorBuilder & ManageNotebookSharesErrorBuilder::operator=(ManageNotebookSharesErrorBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNotebookSharesErrorBuilder & ManageNotebookSharesErrorBuilder::setUserIdentity(std::optional<UserIdentity> userIdentity)
{
    d->m_userIdentity = std::move(userIdentity);
    return *this;
}

ManageNotebookSharesErrorBuilder & ManageNotebookSharesErrorBuilder::setUserException(std::optional<EDAMUserException> userException)
{
    d->m_userException = std::move(userException);
    return *this;
}

ManageNotebookSharesErrorBuilder & ManageNotebookSharesErrorBuilder::setNotFoundException(std::optional<EDAMNotFoundException> notFoundException)
{
    d->m_notFoundException = std::move(notFoundException);
    return *this;
}

ManageNotebookSharesError ManageNotebookSharesErrorBuilder::build()
{
    ManageNotebookSharesError result;

    result.setUserIdentity(std::move(d->m_userIdentity));
    result.setUserException(std::move(d->m_userException));
    result.setNotFoundException(std::move(d->m_notFoundException));

    d->m_userIdentity = {};
    d->m_userException = {};
    d->m_notFoundException = {};

    return result;
}

} // namespace qevercloud
