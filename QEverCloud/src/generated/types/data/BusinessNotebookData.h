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

#ifndef QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKDATA_H
#define QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKDATA_H

#include <generated/types/BusinessNotebook.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessNotebook::BusinessNotebookData final:
    public QSharedData,
    public Printable
{
public:
    BusinessNotebookData() = default;
    BusinessNotebookData(const BusinessNotebookData & other) = default;
    BusinessNotebookData(BusinessNotebookData && other) noexcept = default;

    BusinessNotebookData & operator=(const BusinessNotebookData & other) = delete;
    BusinessNotebookData & operator=(BusinessNotebookData && other) = delete;

    ~BusinessNotebookData() noexcept override = default;

    [[nodiscard]] bool operator==(const BusinessNotebookData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessNotebookData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_notebookDescription;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
    std::optional<bool> m_recommended;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKDATA_H
