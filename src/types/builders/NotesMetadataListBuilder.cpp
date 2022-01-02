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

#include <qevercloud/types/builders/NotesMetadataListBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotesMetadataListBuilder::Impl final:
    public QSharedData
{
public:
    qint32 m_startIndex = 0;
    qint32 m_totalNotes = 0;
    QList<NoteMetadata> m_notes;
    std::optional<QStringList> m_stoppedWords;
    std::optional<QStringList> m_searchedWords;
    std::optional<qint32> m_updateCount;
    std::optional<QByteArray> m_searchContextBytes;
    std::optional<QString> m_debugInfo;
};

NotesMetadataListBuilder::NotesMetadataListBuilder() :
    d(new NotesMetadataListBuilder::Impl)
{}

NotesMetadataListBuilder::NotesMetadataListBuilder(NotesMetadataListBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NotesMetadataListBuilder::~NotesMetadataListBuilder() noexcept = default;

NotesMetadataListBuilder & NotesMetadataListBuilder::operator=(NotesMetadataListBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setStartIndex(qint32 startIndex)
{
    d->m_startIndex = startIndex;
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setTotalNotes(qint32 totalNotes)
{
    d->m_totalNotes = totalNotes;
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setNotes(QList<NoteMetadata> notes)
{
    d->m_notes = std::move(notes);
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setStoppedWords(std::optional<QStringList> stoppedWords)
{
    d->m_stoppedWords = std::move(stoppedWords);
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setSearchedWords(std::optional<QStringList> searchedWords)
{
    d->m_searchedWords = std::move(searchedWords);
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setUpdateCount(std::optional<qint32> updateCount)
{
    d->m_updateCount = std::move(updateCount);
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setSearchContextBytes(std::optional<QByteArray> searchContextBytes)
{
    d->m_searchContextBytes = std::move(searchContextBytes);
    return *this;
}

NotesMetadataListBuilder & NotesMetadataListBuilder::setDebugInfo(std::optional<QString> debugInfo)
{
    d->m_debugInfo = std::move(debugInfo);
    return *this;
}

NotesMetadataList NotesMetadataListBuilder::build()
{
    NotesMetadataList result;

    result.setStartIndex(d->m_startIndex);
    result.setTotalNotes(d->m_totalNotes);
    result.setNotes(std::move(d->m_notes));
    result.setStoppedWords(std::move(d->m_stoppedWords));
    result.setSearchedWords(std::move(d->m_searchedWords));
    result.setUpdateCount(std::move(d->m_updateCount));
    result.setSearchContextBytes(std::move(d->m_searchContextBytes));
    result.setDebugInfo(std::move(d->m_debugInfo));

    d->m_startIndex = 0;
    d->m_totalNotes = 0;
    d->m_notes = {};
    d->m_stoppedWords = {};
    d->m_searchedWords = {};
    d->m_updateCount = {};
    d->m_searchContextBytes = {};
    d->m_debugInfo = {};

    return result;
}

} // namespace qevercloud
