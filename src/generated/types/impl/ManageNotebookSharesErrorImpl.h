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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORIMPL_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORIMPL_H

#include <qevercloud/generated/types/ManageNotebookSharesError.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesError::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNotebookSharesError::Impl & other) = default;
    Impl(ManageNotebookSharesError::Impl && other) noexcept = default;

    ManageNotebookSharesError::Impl & operator=(const ManageNotebookSharesError::Impl & other) = delete;
    ManageNotebookSharesError::Impl & operator=(ManageNotebookSharesError::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNotebookSharesError::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesError::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserIdentity> m_userIdentity;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORIMPL_H
