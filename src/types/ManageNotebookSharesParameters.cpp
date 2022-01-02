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

#include <qevercloud/types/ManageNotebookSharesParameters.h>

#include "impl/ManageNotebookSharesParametersImpl.h"

namespace qevercloud {

ManageNotebookSharesParameters::ManageNotebookSharesParameters() :
    d(new ManageNotebookSharesParameters::Impl)
{}

ManageNotebookSharesParameters::ManageNotebookSharesParameters(const ManageNotebookSharesParameters & other) :
    d(other.d)
{}

ManageNotebookSharesParameters::ManageNotebookSharesParameters(ManageNotebookSharesParameters && other) noexcept :
    d(std::move(other.d))
{}

ManageNotebookSharesParameters::~ManageNotebookSharesParameters() noexcept {}

ManageNotebookSharesParameters & ManageNotebookSharesParameters::operator=(const ManageNotebookSharesParameters & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNotebookSharesParameters & ManageNotebookSharesParameters::operator=(ManageNotebookSharesParameters && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & ManageNotebookSharesParameters::notebookGuid() const noexcept
{
    return d->m_notebookGuid;
}

void ManageNotebookSharesParameters::setNotebookGuid(std::optional<QString> notebookGuid)
{
    d->m_notebookGuid = notebookGuid;
}

const std::optional<QString> & ManageNotebookSharesParameters::inviteMessage() const noexcept
{
    return d->m_inviteMessage;
}

void ManageNotebookSharesParameters::setInviteMessage(std::optional<QString> inviteMessage)
{
    d->m_inviteMessage = inviteMessage;
}

const std::optional<QList<MemberShareRelationship>> & ManageNotebookSharesParameters::membershipsToUpdate() const noexcept
{
    return d->m_membershipsToUpdate;
}

std::optional<QList<MemberShareRelationship>> & ManageNotebookSharesParameters::mutableMembershipsToUpdate()
{
    return d->m_membershipsToUpdate;
}

void ManageNotebookSharesParameters::setMembershipsToUpdate(std::optional<QList<MemberShareRelationship>> membershipsToUpdate)
{
    d->m_membershipsToUpdate = membershipsToUpdate;
}

const std::optional<QList<InvitationShareRelationship>> & ManageNotebookSharesParameters::invitationsToCreateOrUpdate() const noexcept
{
    return d->m_invitationsToCreateOrUpdate;
}

std::optional<QList<InvitationShareRelationship>> & ManageNotebookSharesParameters::mutableInvitationsToCreateOrUpdate()
{
    return d->m_invitationsToCreateOrUpdate;
}

void ManageNotebookSharesParameters::setInvitationsToCreateOrUpdate(std::optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate)
{
    d->m_invitationsToCreateOrUpdate = invitationsToCreateOrUpdate;
}

const std::optional<QList<UserIdentity>> & ManageNotebookSharesParameters::unshares() const noexcept
{
    return d->m_unshares;
}

std::optional<QList<UserIdentity>> & ManageNotebookSharesParameters::mutableUnshares()
{
    return d->m_unshares;
}

void ManageNotebookSharesParameters::setUnshares(std::optional<QList<UserIdentity>> unshares)
{
    d->m_unshares = unshares;
}

void ManageNotebookSharesParameters::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const ManageNotebookSharesParameters & manageNotebookSharesParameters)
{
    strm << static_cast<const Printable&>(manageNotebookSharesParameters);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const ManageNotebookSharesParameters & manageNotebookSharesParameters)
{
    dbg << static_cast<const Printable&>(manageNotebookSharesParameters);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const ManageNotebookSharesParameters & manageNotebookSharesParameters)
{
    strm << static_cast<const Printable&>(manageNotebookSharesParameters);
    return strm;
}

bool operator==(const ManageNotebookSharesParameters & lhs, const ManageNotebookSharesParameters & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.notebookGuid() == rhs.notebookGuid() &&
        lhs.inviteMessage() == rhs.inviteMessage() &&
        lhs.membershipsToUpdate() == rhs.membershipsToUpdate() &&
        lhs.invitationsToCreateOrUpdate() == rhs.invitationsToCreateOrUpdate() &&
        lhs.unshares() == rhs.unshares();
}

bool operator!=(const ManageNotebookSharesParameters & lhs, const ManageNotebookSharesParameters & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
