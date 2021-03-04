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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORIMPL_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORIMPL_H

#include <qevercloud/generated/types/ManageNoteSharesError.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesError::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNoteSharesError::Impl & other) = default;
    Impl(ManageNoteSharesError::Impl && other) noexcept = default;

    ManageNoteSharesError::Impl & operator=(const ManageNoteSharesError::Impl & other) = delete;
    ManageNoteSharesError::Impl & operator=(ManageNoteSharesError::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<IdentityID> m_identityID;
    std::optional<UserID> m_userID;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORIMPL_H
