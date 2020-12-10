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

#ifndef QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTDATA_H
#define QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTDATA_H

#include <generated/types/UpdateNoteIfUsnMatchesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UpdateNoteIfUsnMatchesResult::UpdateNoteIfUsnMatchesResultData final:
    public QSharedData,
    public Printable
{
public:
    UpdateNoteIfUsnMatchesResultData() = default;
    UpdateNoteIfUsnMatchesResultData(const UpdateNoteIfUsnMatchesResultData & other) = default;
    UpdateNoteIfUsnMatchesResultData(UpdateNoteIfUsnMatchesResultData && other) noexcept = default;

    UpdateNoteIfUsnMatchesResultData & operator=(const UpdateNoteIfUsnMatchesResultData & other) = delete;
    UpdateNoteIfUsnMatchesResultData & operator=(UpdateNoteIfUsnMatchesResultData && other) = delete;

    ~UpdateNoteIfUsnMatchesResultData() noexcept override = default;

    [[nodiscard]] bool operator==(const UpdateNoteIfUsnMatchesResultData & other) const noexcept;
    [[nodiscard]] bool operator!=(const UpdateNoteIfUsnMatchesResultData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<Note> m_note;
    std::optional<bool> m_updated;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTDATA_H
