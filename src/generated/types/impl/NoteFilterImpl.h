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

#ifndef QEVERCLOUD_GENERATED_NOTEFILTERIMPL_H
#define QEVERCLOUD_GENERATED_NOTEFILTERIMPL_H

#include <qevercloud/generated/types/NoteFilter.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteFilter::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteFilter::Impl & other) = default;
    Impl(NoteFilter::Impl && other) noexcept = default;

    NoteFilter::Impl & operator=(const NoteFilter::Impl & other) = delete;
    NoteFilter::Impl & operator=(NoteFilter::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteFilter::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteFilter::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_order;
    std::optional<bool> m_ascending;
    std::optional<QString> m_words;
    std::optional<Guid> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<QString> m_timeZone;
    std::optional<bool> m_inactive;
    std::optional<QString> m_emphasized;
    std::optional<bool> m_includeAllReadableNotebooks;
    std::optional<bool> m_includeAllReadableWorkspaces;
    std::optional<QString> m_context;
    std::optional<QString> m_rawWords;
    std::optional<QByteArray> m_searchContextBytes;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEFILTERIMPL_H
