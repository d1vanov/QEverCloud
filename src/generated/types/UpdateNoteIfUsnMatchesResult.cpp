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

#include <qevercloud/generated/types/UpdateNoteIfUsnMatchesResult.h>

#include "impl/UpdateNoteIfUsnMatchesResultImpl.h"

namespace qevercloud {

UpdateNoteIfUsnMatchesResult::UpdateNoteIfUsnMatchesResult() :
    d(new UpdateNoteIfUsnMatchesResult::Impl)
 {}

UpdateNoteIfUsnMatchesResult::UpdateNoteIfUsnMatchesResult(const UpdateNoteIfUsnMatchesResult & other) :
    d(other.d)
{}

UpdateNoteIfUsnMatchesResult::UpdateNoteIfUsnMatchesResult(UpdateNoteIfUsnMatchesResult && other) noexcept :
    d(std::move(other.d))
{}

UpdateNoteIfUsnMatchesResult::~UpdateNoteIfUsnMatchesResult() noexcept {}

UpdateNoteIfUsnMatchesResult & UpdateNoteIfUsnMatchesResult::operator=(const UpdateNoteIfUsnMatchesResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

UpdateNoteIfUsnMatchesResult & UpdateNoteIfUsnMatchesResult::operator=(UpdateNoteIfUsnMatchesResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<Note> & UpdateNoteIfUsnMatchesResult::note() const noexcept
{
    return d->m_note;
}

std::optional<Note> & UpdateNoteIfUsnMatchesResult::mutableNote()
{
    return d->m_note;
}

void UpdateNoteIfUsnMatchesResult::setNote(std::optional<Note> note)
{
    d->m_note = note;
}

const std::optional<bool> & UpdateNoteIfUsnMatchesResult::updated() const noexcept
{
    return d->m_updated;
}

std::optional<bool> & UpdateNoteIfUsnMatchesResult::mutableUpdated()
{
    return d->m_updated;
}

void UpdateNoteIfUsnMatchesResult::setUpdated(std::optional<bool> updated)
{
    d->m_updated = updated;
}

void UpdateNoteIfUsnMatchesResult::print(QTextStream & strm) const
{
    d->print(strm);
}

bool UpdateNoteIfUsnMatchesResult::operator==(const UpdateNoteIfUsnMatchesResult & other) const noexcept
{
    return *d == *other.d;
}

bool UpdateNoteIfUsnMatchesResult::operator!=(const UpdateNoteIfUsnMatchesResult & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
