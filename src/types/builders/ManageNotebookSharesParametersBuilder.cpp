/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/ManageNotebookSharesParametersBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesParametersBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_notebookGuid;
    std::optional<QString> m_inviteMessage;
    std::optional<QList<MemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<InvitationShareRelationship>> m_invitationsToCreateOrUpdate;
    std::optional<QList<UserIdentity>> m_unshares;
};

ManageNotebookSharesParametersBuilder::ManageNotebookSharesParametersBuilder() :
    d(new ManageNotebookSharesParametersBuilder::Impl)
{}

ManageNotebookSharesParametersBuilder::ManageNotebookSharesParametersBuilder(ManageNotebookSharesParametersBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNotebookSharesParametersBuilder::~ManageNotebookSharesParametersBuilder() noexcept = default;

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::operator=(ManageNotebookSharesParametersBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = std::move(notebookGuid);
    return *this;
}

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::setInviteMessage(std::optional<QString> inviteMessage)
{
    d->m_inviteMessage = std::move(inviteMessage);
    return *this;
}

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::setMembershipsToUpdate(std::optional<QList<MemberShareRelationship>> membershipsToUpdate)
{
    d->m_membershipsToUpdate = std::move(membershipsToUpdate);
    return *this;
}

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::setInvitationsToCreateOrUpdate(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate)
{
    d->m_invitationsToCreateOrUpdate = std::move(invitationsToCreateOrUpdate);
    return *this;
}

ManageNotebookSharesParametersBuilder & ManageNotebookSharesParametersBuilder::setUnshares(std::optional<QList<UserIdentity>> unshares)
{
    d->m_unshares = std::move(unshares);
    return *this;
}

ManageNotebookSharesParameters ManageNotebookSharesParametersBuilder::build()
{
    ManageNotebookSharesParameters result;

    result.setNotebookGuid(std::move(d->m_notebookGuid));
    result.setInviteMessage(std::move(d->m_inviteMessage));
    result.setMembershipsToUpdate(std::move(d->m_membershipsToUpdate));
    result.setInvitationsToCreateOrUpdate(std::move(d->m_invitationsToCreateOrUpdate));
    result.setUnshares(std::move(d->m_unshares));

    d->m_notebookGuid = {};
    d->m_inviteMessage = {};
    d->m_membershipsToUpdate = {};
    d->m_invitationsToCreateOrUpdate = {};
    d->m_unshares = {};

    return result;
}

} // namespace qevercloud
