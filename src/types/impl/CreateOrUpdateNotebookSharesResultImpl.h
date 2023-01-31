/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTIMPL
#define QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTIMPL

#include <qevercloud/types/CreateOrUpdateNotebookSharesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CreateOrUpdateNotebookSharesResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const CreateOrUpdateNotebookSharesResult::Impl & other) = default;
    Impl(CreateOrUpdateNotebookSharesResult::Impl && other) noexcept = default;

    CreateOrUpdateNotebookSharesResult::Impl & operator=(const CreateOrUpdateNotebookSharesResult::Impl & other) = delete;
    CreateOrUpdateNotebookSharesResult::Impl & operator=(CreateOrUpdateNotebookSharesResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_updateSequenceNum;
    std::optional<QList<SharedNotebook>> m_matchingShares;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTIMPL
