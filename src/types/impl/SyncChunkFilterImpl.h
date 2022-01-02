/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SYNCCHUNKFILTERIMPL
#define QEVERCLOUD_GENERATED_SYNCCHUNKFILTERIMPL

#include <qevercloud/types/SyncChunkFilter.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SyncChunkFilter::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SyncChunkFilter::Impl & other) = default;
    Impl(SyncChunkFilter::Impl && other) noexcept = default;

    SyncChunkFilter::Impl & operator=(const SyncChunkFilter::Impl & other) = delete;
    SyncChunkFilter::Impl & operator=(SyncChunkFilter::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_includeNotes;
    std::optional<bool> m_includeNoteResources;
    std::optional<bool> m_includeNoteAttributes;
    std::optional<bool> m_includeNotebooks;
    std::optional<bool> m_includeTags;
    std::optional<bool> m_includeSearches;
    std::optional<bool> m_includeResources;
    std::optional<bool> m_includeLinkedNotebooks;
    std::optional<bool> m_includeExpunged;
    std::optional<bool> m_includeNoteApplicationDataFullMap;
    std::optional<bool> m_includeResourceApplicationDataFullMap;
    std::optional<bool> m_includeNoteResourceApplicationDataFullMap;
    std::optional<bool> m_includeSharedNotes;
    std::optional<bool> m_omitSharedNotebooks;
    std::optional<QString> m_requireNoteContentClass;
    std::optional<QSet<QString>> m_notebookGuids;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SYNCCHUNKFILTERIMPL
