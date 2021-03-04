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

#ifndef QEVERCLOUD_GENERATED_NOTELISTIMPL_H
#define QEVERCLOUD_GENERATED_NOTELISTIMPL_H

#include <qevercloud/generated/types/NoteList.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteList::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteList::Impl & other) = default;
    Impl(NoteList::Impl && other) noexcept = default;

    NoteList::Impl & operator=(const NoteList::Impl & other) = delete;
    NoteList::Impl & operator=(NoteList::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_NOTELISTIMPL_H
