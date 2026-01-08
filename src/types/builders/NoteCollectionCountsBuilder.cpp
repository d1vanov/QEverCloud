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

#include <qevercloud/types/builders/NoteCollectionCountsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteCollectionCountsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QMap<Guid, qint32>> m_notebookCounts;
    std::optional<QMap<Guid, qint32>> m_tagCounts;
    std::optional<qint32> m_trashCount;
};

NoteCollectionCountsBuilder::NoteCollectionCountsBuilder() :
    d(new NoteCollectionCountsBuilder::Impl)
{}

NoteCollectionCountsBuilder::NoteCollectionCountsBuilder(NoteCollectionCountsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteCollectionCountsBuilder::~NoteCollectionCountsBuilder() noexcept = default;

NoteCollectionCountsBuilder & NoteCollectionCountsBuilder::operator=(NoteCollectionCountsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteCollectionCountsBuilder & NoteCollectionCountsBuilder::setNotebookCounts(std::optional<QMap<Guid, qint32>> notebookCounts)
{
    d->m_notebookCounts = std::move(notebookCounts);
    return *this;
}

NoteCollectionCountsBuilder & NoteCollectionCountsBuilder::setTagCounts(std::optional<QMap<Guid, qint32>> tagCounts)
{
    d->m_tagCounts = std::move(tagCounts);
    return *this;
}

NoteCollectionCountsBuilder & NoteCollectionCountsBuilder::setTrashCount(std::optional<qint32> trashCount)
{
    d->m_trashCount = std::move(trashCount);
    return *this;
}

NoteCollectionCounts NoteCollectionCountsBuilder::build()
{
    NoteCollectionCounts result;

    result.setNotebookCounts(std::move(d->m_notebookCounts));
    result.setTagCounts(std::move(d->m_tagCounts));
    result.setTrashCount(std::move(d->m_trashCount));

    d->m_notebookCounts = {};
    d->m_tagCounts = {};
    d->m_trashCount = {};

    return result;
}

} // namespace qevercloud
