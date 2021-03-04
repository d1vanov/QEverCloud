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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTIMPL_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTIMPL_H

#include <qevercloud/generated/types/ManageNotebookSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNotebookSharesResult::Impl & other) = default;
    Impl(ManageNotebookSharesResult::Impl && other) noexcept = default;

    ManageNotebookSharesResult::Impl & operator=(const ManageNotebookSharesResult::Impl & other) = delete;
    ManageNotebookSharesResult::Impl & operator=(ManageNotebookSharesResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QList<ManageNotebookSharesError>> m_errors;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTIMPL_H
