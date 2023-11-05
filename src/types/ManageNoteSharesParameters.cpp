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

#include <qevercloud/types/ManageNoteSharesParameters.h>

#include "impl/ManageNoteSharesParametersImpl.h"

namespace qevercloud {

ManageNoteSharesParameters::ManageNoteSharesParameters() :
    d(new ManageNoteSharesParameters::Impl)
{}

ManageNoteSharesParameters::ManageNoteSharesParameters(const ManageNoteSharesParameters & other) :
    d(other.d)
{}

ManageNoteSharesParameters::ManageNoteSharesParameters(ManageNoteSharesParameters && other) noexcept :
    d(std::move(other.d))
{}

ManageNoteSharesParameters::~ManageNoteSharesParameters() noexcept {}

ManageNoteSharesParameters & ManageNoteSharesParameters::operator=(const ManageNoteSharesParameters & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNoteSharesParameters & ManageNoteSharesParameters::operator=(ManageNoteSharesParameters && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & ManageNoteSharesParameters::noteGuid() const noexcept
{
    return d->m_noteGuid;
}

void ManageNoteSharesParameters::setNoteGuid(std::optional<QString> noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
}

const std::optional<QList<NoteMemberShareRelationship>> & ManageNoteSharesParameters::membershipsToUpdate() const noexcept
{
    return d->m_membershipsToUpdate;
}

std::optional<QList<NoteMemberShareRelationship>> & ManageNoteSharesParameters::mutableMembershipsToUpdate()
{
    return d->m_membershipsToUpdate;
}

void ManageNoteSharesParameters::setMembershipsToUpdate(std::optional<QList<NoteMemberShareRelationship>> membershipsToUpdate)
{
    d->m_membershipsToUpdate = std::move(membershipsToUpdate);
}

const std::optional<QList<NoteInvitationShareRelationship>> & ManageNoteSharesParameters::invitationsToUpdate() const noexcept
{
    return d->m_invitationsToUpdate;
}

std::optional<QList<NoteInvitationShareRelationship>> & ManageNoteSharesParameters::mutableInvitationsToUpdate()
{
    return d->m_invitationsToUpdate;
}

void ManageNoteSharesParameters::setInvitationsToUpdate(std::optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate)
{
    d->m_invitationsToUpdate = std::move(invitationsToUpdate);
}

const std::optional<QList<UserID>> & ManageNoteSharesParameters::membershipsToUnshare() const noexcept
{
    return d->m_membershipsToUnshare;
}

std::optional<QList<UserID>> & ManageNoteSharesParameters::mutableMembershipsToUnshare()
{
    return d->m_membershipsToUnshare;
}

void ManageNoteSharesParameters::setMembershipsToUnshare(std::optional<QList<UserID>> membershipsToUnshare)
{
    d->m_membershipsToUnshare = std::move(membershipsToUnshare);
}

const std::optional<QList<IdentityID>> & ManageNoteSharesParameters::invitationsToUnshare() const noexcept
{
    return d->m_invitationsToUnshare;
}

std::optional<QList<IdentityID>> & ManageNoteSharesParameters::mutableInvitationsToUnshare()
{
    return d->m_invitationsToUnshare;
}

void ManageNoteSharesParameters::setInvitationsToUnshare(std::optional<QList<IdentityID>> invitationsToUnshare)
{
    d->m_invitationsToUnshare = std::move(invitationsToUnshare);
}

void ManageNoteSharesParameters::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const ManageNoteSharesParameters & manageNoteSharesParameters)
{
    strm << static_cast<const Printable&>(manageNoteSharesParameters);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const ManageNoteSharesParameters & manageNoteSharesParameters)
{
    dbg << static_cast<const Printable&>(manageNoteSharesParameters);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const ManageNoteSharesParameters & manageNoteSharesParameters)
{
    strm << static_cast<const Printable&>(manageNoteSharesParameters);
    return strm;
}

bool operator==(const ManageNoteSharesParameters & lhs, const ManageNoteSharesParameters & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noteGuid() == rhs.noteGuid() &&
        lhs.membershipsToUpdate() == rhs.membershipsToUpdate() &&
        lhs.invitationsToUpdate() == rhs.invitationsToUpdate() &&
        lhs.membershipsToUnshare() == rhs.membershipsToUnshare() &&
        lhs.invitationsToUnshare() == rhs.invitationsToUnshare();
}

bool operator!=(const ManageNoteSharesParameters & lhs, const ManageNoteSharesParameters & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
