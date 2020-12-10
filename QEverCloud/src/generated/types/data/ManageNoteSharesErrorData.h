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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORDATA_H

#include <generated/types/ManageNoteSharesError.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesError::ManageNoteSharesErrorData final:
    public QSharedData,
    public Printable
{
public:
    ManageNoteSharesErrorData() = default;
    ManageNoteSharesErrorData(const ManageNoteSharesErrorData & other) = default;
    ManageNoteSharesErrorData(ManageNoteSharesErrorData && other) noexcept = default;

    ManageNoteSharesErrorData & operator=(const ManageNoteSharesErrorData & other) = delete;
    ManageNoteSharesErrorData & operator=(ManageNoteSharesErrorData && other) = delete;

    ~ManageNoteSharesErrorData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNoteSharesErrorData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNoteSharesErrorData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<IdentityID> m_identityID;
    std::optional<UserID> m_userID;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORDATA_H
