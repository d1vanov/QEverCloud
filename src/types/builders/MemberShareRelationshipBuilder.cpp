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

#include <qevercloud/types/builders/MemberShareRelationshipBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN MemberShareRelationshipBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<ShareRelationshipPrivilegeLevel> m_bestPrivilege;
    std::optional<ShareRelationshipPrivilegeLevel> m_individualPrivilege;
    std::optional<ShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

MemberShareRelationshipBuilder::MemberShareRelationshipBuilder() :
    d(new MemberShareRelationshipBuilder::Impl)
{}

MemberShareRelationshipBuilder::MemberShareRelationshipBuilder(MemberShareRelationshipBuilder && other) noexcept :
    d{std::move(other.d)}
{}

MemberShareRelationshipBuilder::~MemberShareRelationshipBuilder() noexcept = default;

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::operator=(MemberShareRelationshipBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setDisplayName(std::optional<QString> displayName)
{
    d->m_displayName = std::move(displayName);
    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setRecipientUserId(std::optional<UserID> recipientUserId)
{
    d->m_recipientUserId = std::move(recipientUserId);
    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setBestPrivilege(std::optional<ShareRelationshipPrivilegeLevel> bestPrivilege)
{
    d->m_bestPrivilege = std::move(bestPrivilege);
    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setIndividualPrivilege(std::optional<ShareRelationshipPrivilegeLevel> individualPrivilege)
{
    d->m_individualPrivilege = std::move(individualPrivilege);
    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setRestrictions(std::optional<ShareRelationshipRestrictions> restrictions)
{
    d->m_restrictions = std::move(restrictions);
    return *this;
}

MemberShareRelationshipBuilder & MemberShareRelationshipBuilder::setSharerUserId(std::optional<UserID> sharerUserId)
{
    d->m_sharerUserId = std::move(sharerUserId);
    return *this;
}

MemberShareRelationship MemberShareRelationshipBuilder::build()
{
    MemberShareRelationship result;

    result.setDisplayName(std::move(d->m_displayName));
    result.setRecipientUserId(std::move(d->m_recipientUserId));
    result.setBestPrivilege(std::move(d->m_bestPrivilege));
    result.setIndividualPrivilege(std::move(d->m_individualPrivilege));
    result.setRestrictions(std::move(d->m_restrictions));
    result.setSharerUserId(std::move(d->m_sharerUserId));

    d->m_displayName = {};
    d->m_recipientUserId = {};
    d->m_bestPrivilege = {};
    d->m_individualPrivilege = {};
    d->m_restrictions = {};
    d->m_sharerUserId = {};

    return result;
}

} // namespace qevercloud
