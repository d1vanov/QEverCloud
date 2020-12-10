/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPDATA_H
#define QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPDATA_H

#include <generated/types/MemberShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN MemberShareRelationship::MemberShareRelationshipData final:
    public QSharedData,
    public Printable
{
public:
    MemberShareRelationshipData() = default;
    MemberShareRelationshipData(const MemberShareRelationshipData & other) = default;
    MemberShareRelationshipData(MemberShareRelationshipData && other) noexcept = default;

    MemberShareRelationshipData & operator=(const MemberShareRelationshipData & other) = delete;
    MemberShareRelationshipData & operator=(MemberShareRelationshipData && other) = delete;

    ~MemberShareRelationshipData() noexcept override = default;

    [[nodiscard]] bool operator==(const MemberShareRelationshipData & other) const noexcept;
    [[nodiscard]] bool operator!=(const MemberShareRelationshipData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<ShareRelationshipPrivilegeLevel> m_bestPrivilege;
    std::optional<ShareRelationshipPrivilegeLevel> m_individualPrivilege;
    std::optional<ShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIPDATA_H
