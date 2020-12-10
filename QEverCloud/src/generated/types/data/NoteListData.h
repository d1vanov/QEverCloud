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

#ifndef QEVERCLOUD_GENERATED_NOTELISTDATA_H
#define QEVERCLOUD_GENERATED_NOTELISTDATA_H

#include <generated/types/NoteList.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteList::NoteListData final:
    public QSharedData,
    public Printable
{
public:
    NoteListData() = default;
    NoteListData(const NoteListData & other) = default;
    NoteListData(NoteListData && other) noexcept = default;

    NoteListData & operator=(const NoteListData & other) = delete;
    NoteListData & operator=(NoteListData && other) = delete;

    ~NoteListData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteListData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteListData & other) const noexcept;

    void print(QTextStream & strm) const override;

    qint32 m_startIndex = 0;
    qint32 m_totalNotes = 0;
    QList<Note> m_notes;
    std::optional<QStringList> m_stoppedWords;
    std::optional<QStringList> m_searchedWords;
    std::optional<qint32> m_updateCount;
    std::optional<QByteArray> m_searchContextBytes;
    std::optional<QString> m_debugInfo;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTELISTDATA_H
