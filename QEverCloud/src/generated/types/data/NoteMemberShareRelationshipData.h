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

#ifndef QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPDATA_H
#define QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPDATA_H

#include <generated/types/NoteMemberShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteMemberShareRelationship::NoteMemberShareRelationshipData final:
    public QSharedData,
    public Printable
{
public:
    NoteMemberShareRelationshipData() = default;
    NoteMemberShareRelationshipData(const NoteMemberShareRelationshipData & other) = default;
    NoteMemberShareRelationshipData(NoteMemberShareRelationshipData && other) noexcept = default;

    NoteMemberShareRelationshipData & operator=(const NoteMemberShareRelationshipData & other) = delete;
    NoteMemberShareRelationshipData & operator=(NoteMemberShareRelationshipData && other) = delete;

    ~NoteMemberShareRelationshipData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteMemberShareRelationshipData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteMemberShareRelationshipData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<NoteShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPDATA_H
