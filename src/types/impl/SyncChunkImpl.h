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

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNKIMPL
#define QEVERCLOUD_GENERATED_SYNCCHUNKIMPL

#include <qevercloud/types/SyncChunk.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncChunk::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SyncChunk::Impl & other) = default;
    Impl(SyncChunk::Impl && other) noexcept = default;

    SyncChunk::Impl & operator=(const SyncChunk::Impl & other) = delete;
    SyncChunk::Impl & operator=(SyncChunk::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    Timestamp m_currentTime = 0;
    std::optional<qint32> m_chunkHighUSN;
    qint32 m_updateCount = 0;
    std::optional<QList<Note>> m_notes;
    std::optional<QList<Notebook>> m_notebooks;
    std::optional<QList<Tag>> m_tags;
    std::optional<QList<SavedSearch>> m_searches;
    std::optional<QList<Resource>> m_resources;
    std::optional<QList<Guid>> m_expungedNotes;
    std::optional<QList<Guid>> m_expungedNotebooks;
    std::optional<QList<Guid>> m_expungedTags;
    std::optional<QList<Guid>> m_expungedSearches;
    std::optional<QList<LinkedNotebook>> m_linkedNotebooks;
    std::optional<QList<Guid>> m_expungedLinkedNotebooks;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNKIMPL
