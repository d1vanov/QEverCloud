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

#include <qevercloud/types/UpdateNoteIfUsnMatchesResult.h>

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
    d->m_note = std::move(note);
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

QTextStream & operator<<(QTextStream & strm, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult)
{
    strm << static_cast<const Printable&>(updateNoteIfUsnMatchesResult);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult)
{
    dbg << static_cast<const Printable&>(updateNoteIfUsnMatchesResult);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const UpdateNoteIfUsnMatchesResult & updateNoteIfUsnMatchesResult)
{
    strm << static_cast<const Printable&>(updateNoteIfUsnMatchesResult);
    return strm;
}

bool operator==(const UpdateNoteIfUsnMatchesResult & lhs, const UpdateNoteIfUsnMatchesResult & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.note() == rhs.note() &&
        lhs.updated() == rhs.updated();
}

bool operator!=(const UpdateNoteIfUsnMatchesResult & lhs, const UpdateNoteIfUsnMatchesResult & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
