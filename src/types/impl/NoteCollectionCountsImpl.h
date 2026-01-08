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

#ifndef QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSIMPL
#define QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSIMPL

#include <qevercloud/types/NoteCollectionCounts.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteCollectionCounts::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteCollectionCounts::Impl & other) = default;
    Impl(NoteCollectionCounts::Impl && other) noexcept = default;

    NoteCollectionCounts::Impl & operator=(const NoteCollectionCounts::Impl & other) = delete;
    NoteCollectionCounts::Impl & operator=(NoteCollectionCounts::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QMap<Guid, qint32>> m_notebookCounts;
    std::optional<QMap<Guid, qint32>> m_tagCounts;
    std::optional<qint32> m_trashCount;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSIMPL
