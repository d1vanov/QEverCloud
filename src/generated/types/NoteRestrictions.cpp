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

#include <qevercloud/generated/types/NoteRestrictions.h>

#include "impl/NoteRestrictionsImpl.h"

namespace qevercloud {

NoteRestrictions::NoteRestrictions() :
    d(new NoteRestrictions::Impl)
 {}

NoteRestrictions::NoteRestrictions(const NoteRestrictions & other) :
    d(other.d)
{}

NoteRestrictions::NoteRestrictions(NoteRestrictions && other) noexcept :
    d(std::move(other.d))
{}

NoteRestrictions::~NoteRestrictions() noexcept {}

NoteRestrictions & NoteRestrictions::operator=(const NoteRestrictions & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteRestrictions & NoteRestrictions::operator=(NoteRestrictions && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NoteRestrictions::noUpdateTitle() const noexcept
{
    return d->m_noUpdateTitle;
}

std::optional<bool> & NoteRestrictions::mutableNoUpdateTitle()
{
    return d->m_noUpdateTitle;
}

void NoteRestrictions::setNoUpdateTitle(std::optional<bool> noUpdateTitle)
{
    d->m_noUpdateTitle = noUpdateTitle;
}

const std::optional<bool> & NoteRestrictions::noUpdateContent() const noexcept
{
    return d->m_noUpdateContent;
}

std::optional<bool> & NoteRestrictions::mutableNoUpdateContent()
{
    return d->m_noUpdateContent;
}

void NoteRestrictions::setNoUpdateContent(std::optional<bool> noUpdateContent)
{
    d->m_noUpdateContent = noUpdateContent;
}

const std::optional<bool> & NoteRestrictions::noEmail() const noexcept
{
    return d->m_noEmail;
}

std::optional<bool> & NoteRestrictions::mutableNoEmail()
{
    return d->m_noEmail;
}

void NoteRestrictions::setNoEmail(std::optional<bool> noEmail)
{
    d->m_noEmail = noEmail;
}

const std::optional<bool> & NoteRestrictions::noShare() const noexcept
{
    return d->m_noShare;
}

std::optional<bool> & NoteRestrictions::mutableNoShare()
{
    return d->m_noShare;
}

void NoteRestrictions::setNoShare(std::optional<bool> noShare)
{
    d->m_noShare = noShare;
}

const std::optional<bool> & NoteRestrictions::noSharePublicly() const noexcept
{
    return d->m_noSharePublicly;
}

std::optional<bool> & NoteRestrictions::mutableNoSharePublicly()
{
    return d->m_noSharePublicly;
}

void NoteRestrictions::setNoSharePublicly(std::optional<bool> noSharePublicly)
{
    d->m_noSharePublicly = noSharePublicly;
}

void NoteRestrictions::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteRestrictions::operator==(const NoteRestrictions & other) const noexcept
{
    return *d == *other.d;
}

bool NoteRestrictions::operator!=(const NoteRestrictions & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud