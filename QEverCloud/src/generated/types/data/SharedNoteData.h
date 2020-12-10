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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEDATA_H
#define QEVERCLOUD_GENERATED_SHAREDNOTEDATA_H

#include <generated/types/SharedNote.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNote::SharedNoteData final:
    public QSharedData,
    public Printable
{
public:
    SharedNoteData() = default;
    SharedNoteData(const SharedNoteData & other) = default;
    SharedNoteData(SharedNoteData && other) noexcept = default;

    SharedNoteData & operator=(const SharedNoteData & other) = delete;
    SharedNoteData & operator=(SharedNoteData && other) = delete;

    ~SharedNoteData() noexcept override = default;

    [[nodiscard]] bool operator==(const SharedNoteData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNoteData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserID> m_sharerUserID;
    std::optional<Identity> m_recipientIdentity;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<Timestamp> m_serviceAssigned;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEDATA_H
