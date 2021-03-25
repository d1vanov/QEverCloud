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

#ifndef QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTIMPL
#define QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTIMPL

#include <qevercloud/types/UpdateNoteIfUsnMatchesResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UpdateNoteIfUsnMatchesResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const UpdateNoteIfUsnMatchesResult::Impl & other) = default;
    Impl(UpdateNoteIfUsnMatchesResult::Impl && other) noexcept = default;

    UpdateNoteIfUsnMatchesResult::Impl & operator=(const UpdateNoteIfUsnMatchesResult::Impl & other) = delete;
    UpdateNoteIfUsnMatchesResult::Impl & operator=(UpdateNoteIfUsnMatchesResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<Note> m_note;
    std::optional<bool> m_updated;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTIMPL
