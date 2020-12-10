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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORDATA_H

#include <generated/types/ManageNotebookSharesError.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesError::ManageNotebookSharesErrorData final:
    public QSharedData,
    public Printable
{
public:
    ManageNotebookSharesErrorData() = default;
    ManageNotebookSharesErrorData(const ManageNotebookSharesErrorData & other) = default;
    ManageNotebookSharesErrorData(ManageNotebookSharesErrorData && other) noexcept = default;

    ManageNotebookSharesErrorData & operator=(const ManageNotebookSharesErrorData & other) = delete;
    ManageNotebookSharesErrorData & operator=(ManageNotebookSharesErrorData && other) = delete;

    ~ManageNotebookSharesErrorData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNotebookSharesErrorData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesErrorData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserIdentity> m_userIdentity;
    std::optional<EDAMUserException> m_userException;
    std::optional<EDAMNotFoundException> m_notFoundException;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORDATA_H
