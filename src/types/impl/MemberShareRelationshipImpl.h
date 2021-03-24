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

#ifndef QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPIMPL_H
#define QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPIMPL_H

#include <qevercloud/types/MemberShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN MemberShareRelationship::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const MemberShareRelationship::Impl & other) = default;
    Impl(MemberShareRelationship::Impl && other) noexcept = default;

    MemberShareRelationship::Impl & operator=(const MemberShareRelationship::Impl & other) = delete;
    MemberShareRelationship::Impl & operator=(MemberShareRelationship::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<ShareRelationshipPrivilegeLevel> m_bestPrivilege;
    std::optional<ShareRelationshipPrivilegeLevel> m_individualPrivilege;
    std::optional<ShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPIMPL_H
