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

#ifndef QEVERCLOUD_GENERATED_NOTEVERSIONIDDATA_H
#define QEVERCLOUD_GENERATED_NOTEVERSIONIDDATA_H

#include <generated/types/NoteVersionId.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteVersionId::NoteVersionIdData final:
    public QSharedData,
    public Printable
{
public:
    NoteVersionIdData() = default;
    NoteVersionIdData(const NoteVersionIdData & other) = default;
    NoteVersionIdData(NoteVersionIdData && other) noexcept = default;

    NoteVersionIdData & operator=(const NoteVersionIdData & other) = delete;
    NoteVersionIdData & operator=(NoteVersionIdData && other) = delete;

    ~NoteVersionIdData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteVersionIdData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteVersionIdData & other) const noexcept;

    void print(QTextStream & strm) const override;

    qint32 m_updateSequenceNum = 0;
    Timestamp m_updated = 0;
    Timestamp m_saved = 0;
    QString m_title;
    std::optional<UserID> m_lastEditorId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEVERSIONIDDATA_H
