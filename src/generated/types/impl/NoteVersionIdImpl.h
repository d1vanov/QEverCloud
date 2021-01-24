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

#ifndef QEVERCLOUD_GENERATED_NOTEVERSIONIDIMPL_H
#define QEVERCLOUD_GENERATED_NOTEVERSIONIDIMPL_H

#include <qevercloud/generated/types/NoteVersionId.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteVersionId::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteVersionId::Impl & other) = default;
    Impl(NoteVersionId::Impl && other) noexcept = default;

    NoteVersionId::Impl & operator=(const NoteVersionId::Impl & other) = delete;
    NoteVersionId::Impl & operator=(NoteVersionId::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteVersionId::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteVersionId::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    qint32 m_updateSequenceNum = 0;
    Timestamp m_updated = 0;
    Timestamp m_saved = 0;
    QString m_title;
    std::optional<UserID> m_lastEditorId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEVERSIONIDIMPL_H
