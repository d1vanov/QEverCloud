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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTDATA_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTDATA_H

#include <generated/types/ManageNoteSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesResult::ManageNoteSharesResultData final:
    public QSharedData,
    public Printable
{
public:
    ManageNoteSharesResultData() = default;
    ManageNoteSharesResultData(const ManageNoteSharesResultData & other) = default;
    ManageNoteSharesResultData(ManageNoteSharesResultData && other) noexcept = default;

    ManageNoteSharesResultData & operator=(const ManageNoteSharesResultData & other) = delete;
    ManageNoteSharesResultData & operator=(ManageNoteSharesResultData && other) = delete;

    ~ManageNoteSharesResultData() noexcept override = default;

    [[nodiscard]] bool operator==(const ManageNoteSharesResultData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNoteSharesResultData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QList<ManageNoteSharesError>> m_errors;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTDATA_H
