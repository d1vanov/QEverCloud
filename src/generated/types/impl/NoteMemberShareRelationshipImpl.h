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

#ifndef QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPIMPL_H
#define QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPIMPL_H

#include <qevercloud/generated/types/NoteMemberShareRelationship.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteMemberShareRelationship::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteMemberShareRelationship::Impl & other) = default;
    Impl(NoteMemberShareRelationship::Impl && other) noexcept = default;

    NoteMemberShareRelationship::Impl & operator=(const NoteMemberShareRelationship::Impl & other) = delete;
    NoteMemberShareRelationship::Impl & operator=(NoteMemberShareRelationship::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteMemberShareRelationship::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteMemberShareRelationship::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_displayName;
    std::optional<UserID> m_recipientUserId;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<NoteShareRelationshipRestrictions> m_restrictions;
    std::optional<UserID> m_sharerUserId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMEMBERSHARERELATIONSHIPIMPL_H
