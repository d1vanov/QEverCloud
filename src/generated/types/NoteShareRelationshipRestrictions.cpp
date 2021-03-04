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

#include <qevercloud/generated/types/NoteShareRelationshipRestrictions.h>

#include "impl/NoteShareRelationshipRestrictionsImpl.h"

namespace qevercloud {

NoteShareRelationshipRestrictions::NoteShareRelationshipRestrictions() :
    d(new NoteShareRelationshipRestrictions::Impl)
 {}

NoteShareRelationshipRestrictions::NoteShareRelationshipRestrictions(const NoteShareRelationshipRestrictions & other) :
    d(other.d)
{}

NoteShareRelationshipRestrictions::NoteShareRelationshipRestrictions(NoteShareRelationshipRestrictions && other) noexcept :
    d(std::move(other.d))
{}

NoteShareRelationshipRestrictions::~NoteShareRelationshipRestrictions() noexcept {}

NoteShareRelationshipRestrictions & NoteShareRelationshipRestrictions::operator=(const NoteShareRelationshipRestrictions & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteShareRelationshipRestrictions & NoteShareRelationshipRestrictions::operator=(NoteShareRelationshipRestrictions && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NoteShareRelationshipRestrictions::noSetReadNote() const noexcept
{
    return d->m_noSetReadNote;
}

std::optional<bool> & NoteShareRelationshipRestrictions::mutableNoSetReadNote()
{
    return d->m_noSetReadNote;
}

void NoteShareRelationshipRestrictions::setNoSetReadNote(std::optional<bool> noSetReadNote)
{
    d->m_noSetReadNote = noSetReadNote;
}

const std::optional<bool> & NoteShareRelationshipRestrictions::noSetModifyNote() const noexcept
{
    return d->m_noSetModifyNote;
}

std::optional<bool> & NoteShareRelationshipRestrictions::mutableNoSetModifyNote()
{
    return d->m_noSetModifyNote;
}

void NoteShareRelationshipRestrictions::setNoSetModifyNote(std::optional<bool> noSetModifyNote)
{
    d->m_noSetModifyNote = noSetModifyNote;
}

const std::optional<bool> & NoteShareRelationshipRestrictions::noSetFullAccess() const noexcept
{
    return d->m_noSetFullAccess;
}

std::optional<bool> & NoteShareRelationshipRestrictions::mutableNoSetFullAccess()
{
    return d->m_noSetFullAccess;
}

void NoteShareRelationshipRestrictions::setNoSetFullAccess(std::optional<bool> noSetFullAccess)
{
    d->m_noSetFullAccess = noSetFullAccess;
}

void NoteShareRelationshipRestrictions::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const NoteShareRelationshipRestrictions & lhs, const NoteShareRelationshipRestrictions & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noSetReadNote() == rhs.noSetReadNote() &&
        lhs.noSetModifyNote() == rhs.noSetModifyNote() &&
        lhs.noSetFullAccess() == rhs.noSetFullAccess();
}

bool operator!=(const NoteShareRelationshipRestrictions & lhs, const NoteShareRelationshipRestrictions & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
