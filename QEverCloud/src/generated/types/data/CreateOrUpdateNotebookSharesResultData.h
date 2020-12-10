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

#ifndef QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTDATA_H
#define QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTDATA_H

#include <generated/types/CreateOrUpdateNotebookSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResultData final:
    public QSharedData,
    public Printable
{
public:
    CreateOrUpdateNotebookSharesResultData() = default;
    CreateOrUpdateNotebookSharesResultData(const CreateOrUpdateNotebookSharesResultData & other) = default;
    CreateOrUpdateNotebookSharesResultData(CreateOrUpdateNotebookSharesResultData && other) noexcept = default;

    CreateOrUpdateNotebookSharesResultData & operator=(const CreateOrUpdateNotebookSharesResultData & other) = delete;
    CreateOrUpdateNotebookSharesResultData & operator=(CreateOrUpdateNotebookSharesResultData && other) = delete;

    ~CreateOrUpdateNotebookSharesResultData() noexcept override = default;

    [[nodiscard]] bool operator==(const CreateOrUpdateNotebookSharesResultData & other) const noexcept;
    [[nodiscard]] bool operator!=(const CreateOrUpdateNotebookSharesResultData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_updateSequenceNum;
    std::optional<QList<SharedNotebook>> m_matchingShares;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTDATA_H
