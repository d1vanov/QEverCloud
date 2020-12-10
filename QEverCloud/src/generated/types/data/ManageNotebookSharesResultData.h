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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTDATA_H

#include <generated/types/ManageNotebookSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesResult::ManageNotebookSharesResultData final:
    public QSharedData,
    public Printable
{
public:
    ManageNotebookSharesResultData() = default;
    ManageNotebookSharesResultData(const ManageNotebookSharesResultData & other) = default;
    ManageNotebookSharesResultData(ManageNotebookSharesResultData && other) noexcept = default;

    ManageNotebookSharesResultData & operator=(const ManageNotebookSharesResultData & other) = delete;
    ManageNotebookSharesResultData & operator=(ManageNotebookSharesResultData && other) = delete;

    ~ManageNotebookSharesResultData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNotebookSharesResultData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesResultData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QList<ManageNotebookSharesError>> m_errors;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTDATA_H
