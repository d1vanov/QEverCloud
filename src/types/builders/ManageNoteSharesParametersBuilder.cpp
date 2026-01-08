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

#include <qevercloud/types/builders/ManageNoteSharesParametersBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesParametersBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_noteGuid;
    std::optional<QList<NoteMemberShareRelationship>> m_membershipsToUpdate;
    std::optional<QList<NoteInvitationShareRelationship>> m_invitationsToUpdate;
    std::optional<QList<UserID>> m_membershipsToUnshare;
    std::optional<QList<IdentityID>> m_invitationsToUnshare;
};

ManageNoteSharesParametersBuilder::ManageNoteSharesParametersBuilder() :
    d(new ManageNoteSharesParametersBuilder::Impl)
{}

ManageNoteSharesParametersBuilder::ManageNoteSharesParametersBuilder(ManageNoteSharesParametersBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNoteSharesParametersBuilder::~ManageNoteSharesParametersBuilder() noexcept = default;

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::operator=(ManageNoteSharesParametersBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::setNoteGuid(std::optional<QString> noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
    return *this;
}

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::setMembershipsToUpdate(std::optional<QList<NoteMemberShareRelationship>> membershipsToUpdate)
{
    d->m_membershipsToUpdate = std::move(membershipsToUpdate);
    return *this;
}

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::setInvitationsToUpdate(std::optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate)
{
    d->m_invitationsToUpdate = std::move(invitationsToUpdate);
    return *this;
}

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::setMembershipsToUnshare(std::optional<QList<UserID>> membershipsToUnshare)
{
    d->m_membershipsToUnshare = std::move(membershipsToUnshare);
    return *this;
}

ManageNoteSharesParametersBuilder & ManageNoteSharesParametersBuilder::setInvitationsToUnshare(std::optional<QList<IdentityID>> invitationsToUnshare)
{
    d->m_invitationsToUnshare = std::move(invitationsToUnshare);
    return *this;
}

ManageNoteSharesParameters ManageNoteSharesParametersBuilder::build()
{
    ManageNoteSharesParameters result;

    result.setNoteGuid(std::move(d->m_noteGuid));
    result.setMembershipsToUpdate(std::move(d->m_membershipsToUpdate));
    result.setInvitationsToUpdate(std::move(d->m_invitationsToUpdate));
    result.setMembershipsToUnshare(std::move(d->m_membershipsToUnshare));
    result.setInvitationsToUnshare(std::move(d->m_invitationsToUnshare));

    d->m_noteGuid = {};
    d->m_membershipsToUpdate = {};
    d->m_invitationsToUpdate = {};
    d->m_membershipsToUnshare = {};
    d->m_invitationsToUnshare = {};

    return result;
}

} // namespace qevercloud
