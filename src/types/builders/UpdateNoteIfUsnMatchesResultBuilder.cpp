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

#include <qevercloud/types/builders/UpdateNoteIfUsnMatchesResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UpdateNoteIfUsnMatchesResultBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<Note> m_note;
    std::optional<bool> m_updated;
};

UpdateNoteIfUsnMatchesResultBuilder::UpdateNoteIfUsnMatchesResultBuilder() :
    d(new UpdateNoteIfUsnMatchesResultBuilder::Impl)
{}

UpdateNoteIfUsnMatchesResultBuilder::UpdateNoteIfUsnMatchesResultBuilder(UpdateNoteIfUsnMatchesResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

UpdateNoteIfUsnMatchesResultBuilder::~UpdateNoteIfUsnMatchesResultBuilder() noexcept = default;

UpdateNoteIfUsnMatchesResultBuilder & UpdateNoteIfUsnMatchesResultBuilder::operator=(UpdateNoteIfUsnMatchesResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

UpdateNoteIfUsnMatchesResultBuilder & UpdateNoteIfUsnMatchesResultBuilder::setNote(std::optional<Note> note)
{
    d->m_note = std::move(note);
    return *this;
}

UpdateNoteIfUsnMatchesResultBuilder & UpdateNoteIfUsnMatchesResultBuilder::setUpdated(std::optional<bool> updated)
{
    d->m_updated = std::move(updated);
    return *this;
}

UpdateNoteIfUsnMatchesResult UpdateNoteIfUsnMatchesResultBuilder::build()
{
    UpdateNoteIfUsnMatchesResult result;

    result.setNote(std::move(d->m_note));
    result.setUpdated(std::move(d->m_updated));

    d->m_note = {};
    d->m_updated = {};

    return result;
}

} // namespace qevercloud
