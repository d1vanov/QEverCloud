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

#ifndef QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSDATA_H
#define QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSDATA_H

#include <generated/types/NoteCollectionCounts.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteCollectionCounts::NoteCollectionCountsData final:
    public QSharedData,
    public Printable
{
public:
    NoteCollectionCountsData() = default;
    NoteCollectionCountsData(const NoteCollectionCountsData & other) = default;
    NoteCollectionCountsData(NoteCollectionCountsData && other) noexcept = default;

    NoteCollectionCountsData & operator=(const NoteCollectionCountsData & other) = delete;
    NoteCollectionCountsData & operator=(NoteCollectionCountsData && other) = delete;

    ~NoteCollectionCountsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteCollectionCountsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteCollectionCountsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QMap<Guid, qint32>> m_notebookCounts;
    std::optional<QMap<Guid, qint32>> m_tagCounts;
    std::optional<qint32> m_trashCount;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTECOLLECTIONCOUNTSDATA_H
