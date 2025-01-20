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

#include <qevercloud/types/NoteVersionId.h>

#include "impl/NoteVersionIdImpl.h"

namespace qevercloud {

NoteVersionId::NoteVersionId() :
    d(new NoteVersionId::Impl)
{}

NoteVersionId::NoteVersionId(const NoteVersionId & other) :
    d(other.d)
{}

NoteVersionId::NoteVersionId(NoteVersionId && other) noexcept :
    d(std::move(other.d))
{}

NoteVersionId::~NoteVersionId() noexcept {}

NoteVersionId & NoteVersionId::operator=(const NoteVersionId & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteVersionId & NoteVersionId::operator=(NoteVersionId && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

qint32 NoteVersionId::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

void NoteVersionId::setUpdateSequenceNum(qint32 updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

Timestamp NoteVersionId::updated() const noexcept
{
    return d->m_updated;
}

void NoteVersionId::setUpdated(Timestamp updated)
{
    d->m_updated = updated;
}

Timestamp NoteVersionId::saved() const noexcept
{
    return d->m_saved;
}

void NoteVersionId::setSaved(Timestamp saved)
{
    d->m_saved = saved;
}

const QString & NoteVersionId::title() const noexcept
{
    return d->m_title;
}

void NoteVersionId::setTitle(QString title)
{
    d->m_title = std::move(title);
}

const std::optional<UserID> & NoteVersionId::lastEditorId() const noexcept
{
    return d->m_lastEditorId;
}

std::optional<UserID> & NoteVersionId::mutableLastEditorId()
{
    return d->m_lastEditorId;
}

void NoteVersionId::setLastEditorId(std::optional<UserID> lastEditorId)
{
    d->m_lastEditorId = lastEditorId;
}

void NoteVersionId::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const NoteVersionId & noteVersionId)
{
    strm << static_cast<const Printable&>(noteVersionId);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NoteVersionId & noteVersionId)
{
    dbg << static_cast<const Printable&>(noteVersionId);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NoteVersionId & noteVersionId)
{
    strm << static_cast<const Printable&>(noteVersionId);
    return strm;
}

bool operator==(const NoteVersionId & lhs, const NoteVersionId & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.updated() == rhs.updated() &&
        lhs.saved() == rhs.saved() &&
        lhs.title() == rhs.title() &&
        lhs.lastEditorId() == rhs.lastEditorId();
}

bool operator!=(const NoteVersionId & lhs, const NoteVersionId & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
