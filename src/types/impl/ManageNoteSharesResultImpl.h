/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTIMPL
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTIMPL

#include <qevercloud/types/ManageNoteSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ManageNoteSharesResult::Impl & other) = default;
    Impl(ManageNoteSharesResult::Impl && other) noexcept = default;

    ManageNoteSharesResult::Impl & operator=(const ManageNoteSharesResult::Impl & other) = delete;
    ManageNoteSharesResult::Impl & operator=(ManageNoteSharesResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QList<ManageNoteSharesError>> m_errors;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTIMPL
