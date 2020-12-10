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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSDATA_H
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSDATA_H

#include <generated/types/NoteShareRelationshipRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteShareRelationshipRestrictions::NoteShareRelationshipRestrictionsData final:
    public QSharedData,
    public Printable
{
public:
    NoteShareRelationshipRestrictionsData() = default;
    NoteShareRelationshipRestrictionsData(const NoteShareRelationshipRestrictionsData & other) = default;
    NoteShareRelationshipRestrictionsData(NoteShareRelationshipRestrictionsData && other) noexcept = default;

    NoteShareRelationshipRestrictionsData & operator=(const NoteShareRelationshipRestrictionsData & other) = delete;
    NoteShareRelationshipRestrictionsData & operator=(NoteShareRelationshipRestrictionsData && other) = delete;

    ~NoteShareRelationshipRestrictionsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteShareRelationshipRestrictionsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteShareRelationshipRestrictionsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noSetReadNote;
    std::optional<bool> m_noSetModifyNote;
    std::optional<bool> m_noSetFullAccess;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSDATA_H
